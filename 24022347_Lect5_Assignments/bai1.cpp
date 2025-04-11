#include <iostream>

using namespace std;

const int NODES_SIZE = 1000;

struct treeNode {
    int data;
    treeNode* firstChild;  // con cả
    treeNode* nextSibling;  // em của con cả

    treeNode(int value): data(value), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
    public: 
    // Khai báo
    treeNode* root; // khởi tạo cây bằng node root;
    treeNode* nodeList[NODES_SIZE];  // Mảng lưu các node
    bool isChild[NODES_SIZE];  // mảng quản lý node con, dùng để tìm các node root

    Tree(): root(nullptr) {
        for (int i = 0; i < NODES_SIZE; i++) {
            nodeList[i] = nullptr;
            isChild[i] = false;
        }
    }

    // hàm thiết lập nút gốc
    void setRoot(treeNode* rootNode) {
        root = rootNode;
    }
    
    // hàm lấy nút gốc
    treeNode* getRoot() {
        return root;
    }

    // Hàm updateroot 
    void updateRoot() {
        for (int i = 0; i < NODES_SIZE; i++) {
            if (nodeList[i] != nullptr && !isChild[i]) {
                root = nodeList[i];
                return;
            }
        }
    }

    // Thêm con vào node hiện tại 
    void addChild(int parent, int child) {
        // Kiểm tra xem 1 node đã tồn tại trong nodelist chưa
        if (!nodeList[parent]) nodeList[parent] = new treeNode(parent);
        if (!nodeList[child]) nodeList[child] = new treeNode(child);

        // Lấy node từ trong nodeList
        treeNode* parentNode = nodeList[parent];
        treeNode* childNode = nodeList[child];

        // nếu con cả là nullptr thì childNode được gán là con cả
        if (parentNode->firstChild == nullptr) {
            parentNode->firstChild == childNode;
        }

        // nếu con cả trong gia đình tồn tại thì thêm anh em vào 
        else {
            // duyệt danh sách các con để add newNode vào cuối
            treeNode* temp = parentNode->firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = childNode; // thêm vào đuôi
        }
        isChild[child] = true;
        updateRoot();
    }

    // hàm tính chiều cao của cây
    int findHeight(treeNode* node) {
        // đk dừng
        if (node == nullptr) {
            return 0;
        }

        int maxHeight = 0; // biến đếm chiều cao của cây

        // duyệt danh sách các con của parent
        treeNode* child = node->firstChild;
        while (child != nullptr) {
            int Height = findHeight(child); // gọi hàm đệ quy 

            // Nếu chiều cao của cây con hiện tại lớn hơn chiều cao lớn nhất đã tìm thấy 
            // -> cập nhật lại chiều cao lớn nhất
            if (Height > maxHeight) maxHeight = Height;
            child = child->nextSibling;
        }
        return maxHeight + 1;
    }

    int getHeight() {
        return findHeight(root) - 1;
    }

    // hàm duyệt theo thứ tự tiền tự 
    // Gốc->Trái->Phải
    void PreorderTraversal(treeNode* node) {
        // đk dừng: nếu node là nullptr (cây rỗng hoặc duyệt hết cây con), thoát
        if (!node) return;

        // xử lý node hiện tại trước (N - Node)
        cout << node->data << " ";

        // duyệt qua danh sách các con của node hiện tại (L - Left) 
        treeNode* child = node->firstChild;
        while (child) {
            PreorderTraversal(child); // gọi đệ quy để duyệt từng cây con
            child = child->nextSibling; // chuyển sang em tiếp theo (R - left)
        }
    }

    // hàm gọi duyệt theo Preorder
    void getPreorder() {
        PreorderTraversal(root);
        cout << endl;
    }

    // hàm duyệt theo thứ tự hậu tự
    // trái->phải->gốc
    void PostorderTraversal(treeNode* node) {
        // đk dừng: nếu node là nullptr, thoát
        if (!node) {
            return;
        }

        // duyệt danh sách cây con trước(L - left) 
        treeNode* child = node->firstChild;
        while (child) {
            PostorderTraversal(child);
            child = child->nextSibling; // chuyển sang em tiếp theo (R - right) 
        }

        // xử lý node hiện tại(N - Node)
        cout << node->data << " ";
    }

    // hàm gọi duyệt cây theo Postorder từ gốc
    void getPostorder() {
        PostorderTraversal(root);
        cout << endl;
    }

    bool checkBinaryTree(treeNode* node) {
        if (node == nullptr) return true; // cây là cây chị phân

        treeNode* child = node->firstChild;
        int childCount = 0;
        
        while (child != nullptr) {
            childCount++; // đếm số lượng node hiện tại 

            // nhiều hơn 2 con thì kh phải cây nhị phân

            if (childCount > 2) return false;

            // kiểm tra đệ quy các anh chị em và con của child
            if (checkBinaryTree(child) == false) return false;
            child = child->nextSibling;
        }
        return true;
    }

    bool isBinaryTree() {
        return checkBinaryTree(root);
    }

    // hàm duyệt theo thứ tự trung tự
    // trái -> gốc -> phải
    void InorderTraversal(treeNode* node) {
        // đk dừng: nếu node là nullptr, thoát
        if(!node) {
            return;
        }

        // đi thẳng đến con cả lá đầu tiên - bên trái
        if (node->firstChild != nullptr) {
            InorderTraversal(node->firstChild);
        }

        // xử lý node hiện tại - gốc
        cout << node->data << " ";

        // duyệt đếnn node nextSibling tiếp theo - bên phải
        if (node->firstChild != nullptr && node->firstChild->nextSibling != nullptr) {
            InorderTraversal(node->firstChild->nextSibling);
        }
    }

    void getInorder() {
        if (isBinaryTree() == true) {
            InorderTraversal(root);
            cout << endl;
        } else {
            cout << "không phải cây nhị phân" << endl;
            return;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Tree viethung;
    treeNode* nodeList[n] = {nullptr}; // mảng lưu các node
    bool isChild[n] = {false};

    // đọc input và xây dựng cây
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        viethung.addChild(a, b);
    }

    cout << viethung.getHeight() << endl;

    viethung.getPreorder();
    viethung.getPostorder();
    viethung.getInorder();
    return 0;
}