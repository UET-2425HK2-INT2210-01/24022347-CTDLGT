#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm thêm phần tử mới vào cây BST
Node* insertNode(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

// Duyệt cây theo thứ tự trung thứ (Inorder): trái -> gốc -> phải
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Tìm node nhỏ nhất bên phải (kế thừa trong khi xóa node có 2 con)
Node* getRightMin(Node* node) {
    Node* temp = node->right;
    while (temp && temp->left)
        temp = temp->left;
    return temp;
}

// Hàm xóa một phần tử khỏi cây
Node* removeNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = removeNode(root->left, key);
    else if (key > root->data)
        root->right = removeNode(root->right, key);
    else {
        // Trường hợp node chỉ có 1 con hoặc không có con
        if (!root->left) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (!root->right) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        // Trường hợp có 2 con
        Node* successor = getRightMin(root);
        root->data = successor->data;
        root->right = removeNode(root->right, successor->data);
    }

    return root;
}

int main() {
    int n;
    cin >> n;

    Node* tree = nullptr;
    while (n--) {
        int val;
        cin >> val;
        tree = insertNode(tree, val);
    }

    printInorder(tree);
    cout << endl;

    int m;
    cin >> m;
    while (m--) {
        int val;
        cin >> val;
        tree = removeNode(tree, val);
    }

    printInorder
