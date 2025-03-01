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

void enqueue(node *&queue, int x) {
    node *newNode = makenode(x);
    if (queue == nullptr) {
        queue = newNode;
        return;
    }
    node *temp = queue;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dequeue(node *&queue) {
    if (queue == nullptr) return;
    node *temp = queue;
    queue = queue->next;
    delete temp;
}

int main() {
    node *queue = nullptr;
    int n;
    cin >> n;
    while (n--) {
        string request;
        cin >> request;
        if (request == "enqueue") {
            int x;
            cin >> x;
            enqueue(queue, x);
        } else {
            dequeue(queue);
        }
    }

    duyet(queue);
    return 0;
}
