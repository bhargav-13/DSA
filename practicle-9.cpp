#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp  = head ;
    while(temp != NULL) {
        cout << temp -> data << " -> " << flush;
        temp  = temp -> next;
    }
    cout << " NULL ]" << endl;
}

void insertAtHead(Node* &tail, Node* &head, int d) {

    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(tail,head, 11);
    insertAtTail(tail,head, 13);
    insertAtTail(tail,head, 8); 
    insertAtHead(tail,head, 25);

    print(head);

    return 0;
}



