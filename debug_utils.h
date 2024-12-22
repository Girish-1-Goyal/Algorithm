#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <iostream>
#include <utility>
#include <type_traits>
#include <iterator>

using namespace std;

template <class c>
struct rge {
    c b, e;
};

template <class c>
rge<c> range(c i, c j) {
    return rge<c>{i, j};
}

template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);

template <class c>
char dud(...);

struct debug {
    ~debug() { cerr << endl; }
    template <class c>
    typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return *this;
    }
    template <class c>
    typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return *this << range(begin(i), end(i));
    }
    template <class c, class b>
    debug& operator<<(pair<b, c> d) {
        return *this << "(" << d.first << ", " << d.second << ")";
    }
    template <class c>
    debug& operator<<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return *this << "]";
    }
};

#define imie(...) " [" << #__VA_ARGS__ " : " << (__VA_ARGS__) << "]"

#endif // DEBUG_UTILS_H
