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

class Person{
private:
    string name;
    int age;
    string country;
public:
	//methods to set name and get name in the class and the properties are the private and without constructor
    void setName(string name){
        this->name = name;
    }

    void setAge(int age){
        this->age = age;
    }
    void setCountry(string country){
        this->country = country;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getCountry(){
        return country;
    }
    
      
};


void solve(){
    Person P1;
    P1.setName("Girish Kumar Goyal");
    P1.setAge(24);
    P1.setCountry("India");

    cout << P1.getName() << "\n";
    cout << P1.getAge() << "\n";
    cout << P1.getCountry() << "\n";
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
