#include <bits/stdc++.h>

using namespace std;

/*
Pointers in c++ =>

special variables that store the address of the other variables.

*/
void solve(){
    int a = 10;
    int *ptr = &a;
    int **ptr2 = &ptr;
    /*
    Both will print the same value because in ptr we are storing the address
    of a and in the second cout we are directly print the address of a
    */

    cout << ptr << "\n";
    cout << &a << "\n";

    //this will print the value of the ptr pointer which is different from the above 2
    cout << &ptr << "\n";

    //here ptr2 will store the address the ptr;
    cout << ptr2 << "\n";

    // dereferencing operator to extract the value of the address it will print 10;
    cout << *(&a) << "\n";
    cout << *(ptr) << "\n";

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
            