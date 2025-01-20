/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

//node of the linked list
class Node{
public:
    int data;
    Node* next;
public:
    Node(int data1, Node* next){
        data = data1;
        next = next1;
    }
};

// convert array to linked list
Node* convert2arr(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); ++i){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    } 
    return head;
}

// length of the linked list
int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

//search in the linked list
int searchLL(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->next == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// delete from the linked list from head of the linked list
Node* removeHead(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// delete the tail of the linked list
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next == NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// delete the kth element from the linked list
Node* kthElement(Node* head, int k){
    if(head == NULL){
        return head;
    }
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// delete the value of the linked list or the data or the linked list
Node* removeValue(Node* head, int val){
     if(head == NULL){
        return head;
    }
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// inserting at the head of the linked list
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

// inserting at the tail of the linked list
Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// inserting at the given kth element
Node* insertKth(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k == 1){
        return new Node(val, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == (k - 1)){
            Node* x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insert before the value val
Node* insertBeforeKth(Node* head, int element, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        return new Node(val, head);
    }
    Node* temp = head;
    while(temp != NULL){
        if(temp->next->data == val){
            Node* x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void solve(){
    vector<int> arr = {2, 3, 4, 6};
    Node* y = new Node(arr[0], nullptr);
    Node* head = convert2arr(arr);
    cout << head->data << " ";
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << y->data << " " << y->next;
    cout << lengthofLL(head);
    cout << searchLL(head, val);
    head = removeHead(head);
    cout << head << " ";
    head = removeTail(head);
    cout << head << " ";
    head = kthElement(head, k);
    cout << head << " ";
    head = removeValue(head, val);
    cout << head << " ";
    head = insertHead(head, val);
    cout << head << " ";
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
