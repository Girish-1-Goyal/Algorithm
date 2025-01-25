/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

template < class c > struct rge {
    c b, e;
};
template < class c > rge<c> range(c i, c j){
    return rge<c>{i, j};
}
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return * this;
    }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return * this << range(begin(i), end(i)); 
    }
    template < class c, class b > debug & operator << (pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
};  
#define imie(...) " [" << #__VA_ARGS__ " : " << (__VA_ARGS__) << "]"

vector<int> sieve_list(int n){
    // initialise the boolean array and mark all the index as true initially
    vector<bool> isprime(n + 1, true);
    // mark 0 and 1 as false because the 0 and 1 are not prime numbers
    isprime[0] = isprime[1] = false;
    // run a loop from 2 to sqrt(n)
    for(int i = 2; i * i <= n; ++i){
        // check if it is true or not
        if(isprime[i] == true){
            // go to its multiple and mark all them false
            for(int j = i * i; j <= n; j += i){
                isprime[j] = false;
            }
        }
    }
    // prime vector to store all the prime numbers;
    vector<int> prime;
    for(i = 2; i <= n; ++i){
        // check in the isprime array that if the element is true then it is the prime number and then push it into the prime array
        if(isprime[i] == true){
            prime.push_back(i);
        }
    }
    return prime;
}


void solve(){
    //Code Here....
}

void init_code(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    init_code();
    solve();
    return 0;
}
