/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

// find the middle of the linked list if the list of even or of the length odd
//Time complexity = O(n + n/2) = ~O(n);

class Node{
public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* middleList(Node* head){

    // if the list is empty or list has only 1 element
    // then return the head of the list
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    int cnt = 0;

    //count the no of nodes in the linked list
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    // calculate the middle position of the middle node
    int mid = cnt / 2 + 1;
    temp = head;
    
    // traverse the middle node by moving temp to the middle position
    while(temp != NULL){
        mid = mid - 1;

        // check if the middle position is reached
        if(mid == 0){
            
            // break out the loop to return the temp
            break;
        }

        //move temp ahead
        temp = temp->next;
    }

    // return the middle node
    return temp;
}

Node* middleList(Node* head){

    // two pointers slow and fast at the head of the linked list
    Node* slow = head;
    Node* fast = head;

    //traverse the linked list until the fast reaches the null and the fast->next reaches the null
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
