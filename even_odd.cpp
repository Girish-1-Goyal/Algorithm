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

//There are 4 methods to check wether a no is even or odd and we are doing there methods in different 4 functions

void check_even_odd1(int &n){
    if(n % 2 == 0){
        cout << "The no is even" << "\n";
    }
    else{
        cout << "The no is odd" << "\n";
    }
}

void check_even_odd2(int &n){
    //multiply and divide the no by 2 if the result is same then the no is even otherwise the no is odd
    int res = (n / 2) * 2;
    if(res == n){
        cout << "No is even" << "\n";
    }
    else{
        cout << "No is odd" << "\n";
    }
}

void check_even_odd3(int &n){
    if(n & 1){
        cout << "The no is odd" << "\n";
    }
    else{
        cout << "No is even" << "\n";
    }
}

void check_even_odd4(int &n){
    int res = ((n >> 1) << 1);
    if(n == res){
        cout << "No is even" << "\n";
    }
    else{
        cout << "No is odd" << "\n";
    }
}

void solve(){
    int n;
    cin >> n;
    check_even_odd1;
    check_even_odd2;
    check_even_odd3;
    check_even_odd4;

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
