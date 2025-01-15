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

class Triangle{
private:
    double len1;
    double len2;
    double len3;
public:

    Triangle(){} //non parameterised constructor
    
    Triangle(double len1, double len2, double len3){ //parameterised constructor
        this->len1 = len1;
        this->len2 = len2;
        this->len3 = len3;
    }

    Triangle(Triangle &obj){ // copy constructor
        this->len1 = obj.len1;
        this->len2 = obj.len2;
        this->len3 = obj.len3;
    }
    
    void setValues(double len1, double len2, double len3){
        this->len1 = len1;
        this->len2 = len2;
        this->len3 = len3;
    }      
    void checkTriangle(){
        if(len1 == len2 && len2 == len3 && len3 == len1){
            cout << "Triangle is equilateral Triangle" << "\n";   
        }
        else if(len1 != len2 && len2 != len3 && len3 != len1){
            cout << "Triangle is Scalan Triangle" << "\n";
        }
        else{
            cout << "Triangle is isosceles Triangle" << "\n";
        }
    }
};

void solve(){
    Triangle T1;
    T1.setValues(43, 43, 43);
    T1.checkTriangle();

    Triangle T2(23, 23, 45.1);
    T2.checkTriangle();

    Triangle T3(T2);
    T3.checkTriangle();
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
