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

bool check_power4(int &n){
    if(n == 0){
        return false;
    }
    bool powerof2 = !(n & (n - 1));
    bool mask = !(n & 0xAAAAAAAA);
    return powerof2 && mask;
    //or we can simply return the following without doing above calculation
    return !(n & (n - 1)) && (n % 3 == 1);
}

bool check_power8(int &n){
    if(n == 0){
        return false;
    }
    bool powerof2 = !(n & (n - 1));
    bool mask = !(n & 0xB6DB6DB6);
    return powerof2 && mask;
    //or we can simply return the following without doing above calculation
    return !(n & (n - 1)) && (n % 7 == 1);
}

bool check_power8(int &n){
    if(n == 0){
        return false;
    }
    bool powerof2 = !(n & (n - 1));
    bool mask = !(n & 0xEEEEEEEE);
    return powerof2 && mask;
    //or we can simply return the following without doing above calculation
    return !(n & (n - 1)) && (n % 15 == 1);
}

void solve(){
    int n;
    cin >> n;
    //modify the if statement according to the questions for 8 and 16
    if(check_power4(n)){
        cout << "No is power of 4" << "\n";
    }
    else{
        cout << "NO is not power of 4" << "\n";
    }

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
