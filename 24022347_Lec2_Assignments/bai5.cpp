#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};
typedef struct node node;

node *makenode(int x) {
    node *newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void duyet(node* queue) {
    while (queue != nullptr) {
        cout << queue->data << " ";
        queue = queue->next;
    }
    cout << endl;
}

void push(node *&top, int x) {
    node *newNode = makenode(x); 
    if (top == nullptr) {
        top = newNode;
        return;
    }
    node *temp = top;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void pop(node *&top) {
    if (top == nullptr) return;
    if (top->next == nullptr) { 
        delete top;
        top = nullptr;
        return;
    }
    node *temp = top;

    while (temp->next->next != nullptr) { 
        temp = temp->next;
    }

    delete temp->next; 
    temp->next = nullptr; 
}

int main() {
    node *top = nullptr;
    int n;
    cin >> n;
    while (n--) {
        string request;
        cin >> request;
        if (request == "push"){
            int x;
            cin >> x;
            push(top, x);
        }
        else{
            pop(top);
        }
    }
    duyet(top);
    return 0;
}