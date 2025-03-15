#include <iostream>
#include <string>

using namespace std;

struct node{
    int data;
    node *next;
};

typedef struct node node;

node *makenode(int x) {
    node * newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void append(node *&head, int x) {
    node *newNode = makenode(x);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

string search(node *&head, int x) {
    node *temp = head;
    int dem = 1;
    while (temp->data != x) {
        temp = temp->next;
        dem++;
    }
    if (dem == 1 && head->data == x) {
        return "NO";
    }
    return to_string(dem);
}

node* reverse(node *&head) {
    if (head == nullptr) return head;
    node *prev = nullptr;
    node *current = head;
    node *next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void print(node *&head) {
    node *temp = head;
    while (temp->next != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    node *head = nullptr;
    int n;
    cin >> n;
    string require;
    while (n--) {
        cin >> require;
        int x;
        cin >> x;
        if (require == "append"){
            append(head, x);
        } else if (require == "search") {
            search(head, x);
        } else {
            reverse(head);
        }
    }
    return 0;
}