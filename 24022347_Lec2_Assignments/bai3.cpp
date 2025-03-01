#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node *creNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void duyet(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int sz(Node* head) {
    int cnt = 0;
    while (head != nullptr) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void themdau2(Node *&head, int x) {
    Node *newNode = creNode(x);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void themcuoi2(Node *&head, int x) {
    Node *newNode = creNode(x);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int count_triplets(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return 0; 
    }

    int count = 0;
    Node* temp = head->next;

    while (temp->next != nullptr) { 
        if (temp->prev->data + temp->data + temp->next->data == 0) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}


void clearList(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head = nullptr;
    int n;
    cin >> n;
    
    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    themdau2(head, a[0]);
    for (int i = 1; i < n; i++) {
        themcuoi2(head, a[i]);
    }
 
    cout << count_triplets(head) << endl;

    delete[] a;
    clearList(head); 

    return 0;
}
