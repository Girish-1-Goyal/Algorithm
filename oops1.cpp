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

class Car{
private:
    string company;
    string modal;
    int year;
public:

    Car(){}

    Car(string company, string modal, int year){
        this->company = company;
        this->modal = modal;
        this->year = year;
    }

    Car(Car &obj){
        this->company = obj.company;
        this->modal = obj.modal;
        this->year = obj.year;
    }
    
    void setCompany(string company){
        this->company = company;
    }
    void setModal(string modal){
        this->modal = modal;
    }
    void setYear(int year){
        this->year = year;
    }
    string getCompany(){
        return company;
    }
    string getModal(){
        return modal;
    }
    int getYear(){
        return year;
    }
    void getInfo(){
        cout << "Company" << company;
        cout << "modal" << modal;
        cout << "year" << year;
    }
    
};

void solve(){
    Car C2("Toyota", "Pro", 2011);
    C2.getInfo();
    Car C1;
    C1.setCompany("Toyota");
    C1.setModal("Pro");
    C1.setYear(2011);

    cout << C1.getCompany() << "\n";
    cout << C1.getModal() << "\n";
    cout << C1.getYear() << "\n";

    Car C3(C2);
    C3.getInfo();
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
