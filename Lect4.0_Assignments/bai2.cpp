#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    int p;
    Node* next;
    Node* prev;
    Node(int data, int p) {
        this->data = data;
        this->p = p;
        next = nullptr;
        prev = nullptr;
    }
};

class piorityQueue{
private:
    Node* head;
    Node* tail;
public:
    piorityQueue(){
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void enqueue(int x, int p){
        Node* newNode = new Node(x, p);
        if (isEmpty()){
            head = tail = newNode;
        }
        else{
            Node* temp = head;
            while (temp != nullptr && temp->p < p){
                temp = temp->next;
            }
            if (temp == nullptr){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else if (temp->prev == nullptr) {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }
    void Dequeue(){
        if (isEmpty()){
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }
    void Print(){
        Node* temp = head;
        while (temp != nullptr){
            cout << "(" << temp->data << ", " << temp->p << "); ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    piorityQueue q;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string require; cin >> require;
        if (require == "enqueue") {
            int x, p;
            cin >> x >> p;
            q.enqueue(x, p);
        }
        else if (require == "dequeue")
            q.Dequeue();
    }
    q.Print();

    return 0;
}