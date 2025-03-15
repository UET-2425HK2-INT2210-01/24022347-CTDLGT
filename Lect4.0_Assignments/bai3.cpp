#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char x){
        data = x;
        next = nullptr;
    }
};

class Stack{
private:
    Node* head;
public:
    Stack(){
        head = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void push(char x){
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }
    char Top(){
        return head->data;
    }
    void pop(){
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

bool valid(string s) {
    if (s.length() % 2 == 1)
        return false;
    Stack stack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '('){
            stack.push(s[i]);
        }
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')'){
            if (i == 0) return false;
            else
                if (stack.Top() == '[' && s[i] == ']' || stack.Top() == '{' && s[i] == '}' || stack.Top() == '(' && s[i] == ')')
                    stack.pop();
                else return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    string s; cin >> s;
    if (valid(s))
        cout << "Valid";
    else 
        cout << "Invalid";

    return 0;
}