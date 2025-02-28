#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* next;
};

class LinkedList{
    public:
    Node* head;

    LinkedList () {
        head = nullptr;
    }

    void print() {
        Node* temp = head;
        while(temp != nullptr){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    void insert(int p,int x){
        Node* newNode = new Node{x, nullptr};

        if (p == 0 || head == nullptr){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for(int i = 0; i < p - 1 && temp->next != nullptr; i++){
            temp = temp->next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;

        // B0: ktra p
        // B1: Khởi tạo node mới từ giá trị x
        // B2: check ll null? head = newNode 
        // B3: chen vao p
        // B4: Len++
    }

    void del(int p) {
        if(head == nullptr){
            return;
        }
        if(p == 0){
            Node* temp = head;
            head = head-> next;
            delete temp;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < p - 1 && temp->next != nullptr; i++){
            temp = temp->next;
        }
        if(temp->next == nullptr) return;

        Node* nodeToDelete = temp -> next;
        temp -> next = (temp -> next) -> next;
        delete nodeToDelete;
        // B1: ktra p va ll
        // B2: Xoa tai
        // B3: Len--
    }
};

    int main() {
        int n;
        cin >> n;
        LinkedList ll;
        while (n--){
            string request;
            cin >> request;
            if(request == "insert"){
                int p, x;
                cin >> p >> x;
                ll.insert(p, x);
        } else if(request == "del"){
            int p;
            cin >> p;
            ll.del(p);
        }
    }
        ll.print();
        return 0;
    }
