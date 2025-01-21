/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    // data stored in the node
    int data;

    //pointer to the next node in the list

    Node* next;

    // constructor with both the data and the next as a parameter
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    // constructor with only data as a parameter and set next to the nullptr
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

};

// bruteforce approach to detect a cycle in the linked list
// time complexity = O(n * 2log(n));
// space complexity = O(n)

bool detectLoop(node* head){
    Node* temp = head;

    unordered_map<Node*, int> nodeMap;
    while(temp != nullptr){
        // if node is already in the map there is a loop
        if(nodeMap.find(temp) != nodeMap.end()){
            return true;
        }
        // store the current node in the map
        nodeMap[temp] = 1;

        //move to the next node
        temp = temp->next;
    }
    return false;
}
// this is the optimised code for the detect loop in the linked list;
// Time complexity = O(n) because the no of nodes in the linked list;

bool detectCycle(Node* head){

    // initialise 2 pointers slow and fast to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // traverse the linked list with slow and fast pointers 
    while(fast != nullptr && fast->next != nullptr){
        // move slow pointer to the 1 step ahead
        slow = slow->next;

        // move fast pointer to the 2 step ahead
        fast = fast->next->next;
        if(slow == fast){
            // detect the cycle in the linked list
            return true;
        }
    }
    // there is no cycle in the linked list
    return false;
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
