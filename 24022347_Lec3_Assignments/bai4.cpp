#include <iostream>
 
using namespace std;

struct node{
    int data;
    node *next;
};


void print(node *&queue) {
    node *temp = queue;
    while (temp->next != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
} // O(n)

node *makenode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
} // O(1)

void enqueue(node *&queue, int x) {
    node *newNode = makenode(x);
    if (queue = nullptr) queue = newNode; return; 
    node *temp = queue;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
} // O(n)

void dequeue(node *&queue) {
    if (queue == nullptr) return;
    node *temp = queue;
    queue = queue->next;
    delete temp;
} // O(1)

int main() {
    node* head = nullptr;
        int n;
        cin >> n;
        string operat;
        int x;
        for(int i = 1; i <= n; i++){
            cin >> operat;
            if(operat == "enqueue"){
                cin >> x;
                enqueue(head, x);
            }
            if(operat == "dequeue"){
                dequeue(head);
            }
        }
        print(head);
        return 0;
    }