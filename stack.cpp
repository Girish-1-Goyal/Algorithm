/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

// implement a stack using array(dynamic)

class Stack{
private:
    vector<int> stck;
public:
    /*
    the important operations of the stack are
    1. push(int val)
    2. pop
    3. top
    4. isEmpty()
    5. size
    6. display the elements

    we are using const in the functions because we want to ensure that the function does not modify the object state
    it is a promise that the function will not change any member variables of the class.
    
    */


    // pushing an element into the stack
    void push(int val){
        stck.push_back(val);
    }

    // pop an element from the stack
    void pop(){
        if(!isEmpty()){
            stck.pop_back();
        }
        else{
            cout << "stack is empty can not pop the value" << "\n";
        }
    }

    // top of the stack
    int top() const{
        if(!isEmpty()){
            return stck.back();
        }
        else{
            throw runtime_error("stack is empty there is no top element");
        }
    }

    // check wether the stack is empty or not
    bool isEmpty() const{
        return stck.empty();
    }

    // return the size of the stack
    size_t size() const{
        return stck.size();
    }

    // display all the elements of the stack
    void display() const{
        if(isEmpty()){
            cout << "The stack is empty" << "\n";
            return;
        }
        else{
            for(auto it = stck.rbegin(); it != stck.rend(); ++it){
                cout << *it << " ";
            }
        }
        cout << "\n";
    }
};

void solve(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.display(); 

    cout << "Stack size: " << stack.size() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
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
