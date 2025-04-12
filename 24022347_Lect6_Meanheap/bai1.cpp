#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;
    int maxSize;
    int size;

    // Trả về chỉ số node cha
    int parent(int i) { return (i - 1) / 2; }

    // Trả về chỉ số con trái
    int left(int i) { return 2 * i + 1; }

    // Trả về chỉ số con phải
    int right(int i) { return 2 * i + 2; }

    // Hoán đổi 2 phần tử
    void swapNode(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Đẩy phần tử lên đúng vị trí trong heap
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swapNode(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Đẩy phần tử xuống đúng vị trí sau khi xóa
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swapNode(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor: khởi tạo heap với dung lượng
    MinHeap(int cap) {
        heap = new int[cap];
        maxSize = cap;
        size = 0;
    }

    // Kiểm tra heap có đầy không
    bool isFull() {
        return size == maxSize;
    }

    // Kiểm tra heap có rỗng không
    bool isEmpty() {
        return size == 0;
    }

    // Thêm phần tử vào heap
    void insert(int val) {
        if (isFull()) {
            cout << "Heap đã đầy!\n";
            return;
        }
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    // Xóa phần tử bất kỳ trong heap
    void removeElement(int val) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (heap[i] == val) {
                found = true;
                heap[i] = heap[size - 1];
                size--;
                heapifyDown(i);
                break;
            }
        }
        if (!found) cout << "Không tìm thấy phần tử cần xóa!\n";
    }

    // Xây heap từ mảng - O(nlogn)
    void buildHeap(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insert(arr[i]);
        }
    }

    // In nội dung heap
    void print() {
        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Duyệt NLR
    void preorderTraversal(int i = 0) {
        if (i >= size) return;
        cout << heap[i] << " ";
        preorderTraversal(left(i));
        preorderTraversal(right(i));
    }

    // Duyệt LNR
    void inorderTraversal(int i = 0) {
        if (i >= size) return;
        inorderTraversal(left(i));
        cout << heap[i] << " ";
        inorderTraversal(right(i));
    }

    // Duyệt LRN
    void postorderTraversal(int i = 0) {
        if (i >= size) return;
        postorderTraversal(left(i));
        postorderTraversal(right(i));
        cout << heap[i] << " ";
    }
};

int main() {
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinHeap heap(n + 10);
    heap.buildHeap(arr, n);
    heap.print();

    cout << "Preorder: ";
    heap.preorderTraversal();
    cout << endl;

    cout << "Inorder: ";
    heap.inorderTraversal();
    cout << endl;

    cout << "Postorder: ";
    heap.postorderTraversal();
    cout << endl;

    heap.insert(14);
    heap.insert(0);
    heap.insert(35);
    heap.print();

    heap.removeElement(6);
    heap.removeElement(13);
    heap.removeElement(35);
    heap.print();

    return 0;
}
