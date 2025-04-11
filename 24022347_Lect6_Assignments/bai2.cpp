#include <iostream>
#include <vector>
using namespace std;

class MyMinHeap {
private:
    vector<int> a;

    // Trả về chỉ số cha của node tại i
    int getParent(int i) { return (i - 1) / 2; }

    // Trả về chỉ số con trái/phải
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }

    // Đẩy phần tử lên nếu nó bé hơn cha
    void siftUp(int i) {
        while (i > 0 && a[i] < a[getParent(i)]) {
            swap(a[i], a[getParent(i)]);
            i = getParent(i);
        }
    }

    // Đẩy phần tử xuống nếu nó lớn hơn con
    void siftDown(int i) {
        int minIdx = i;
        int l = getLeft(i), r = getRight(i);

        if (l < a.size() && a[l] < a[minIdx]) minIdx = l;
        if (r < a.size() && a[r] < a[minIdx]) minIdx = r;

        if (minIdx != i) {
            swap(a[i], a[minIdx]);
            siftDown(minIdx);
        }
    }

public:
    void push(int val) {
        a.push_back(val);
        siftUp(a.size() - 1);
    }

    void remove(int val) {
        int idx = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == val) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return;

        a[idx] = a.back();
        a.pop_back();

        if (!a.empty() && idx < a.size()) {
            if (idx > 0 && a[idx] < a[getParent(idx)])
                siftUp(idx);
            else
                siftDown(idx);
        }
    }

    void show() {
        for (int x : a) cout << x << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Số phần tử cần thêm vào heap: ";
    cin >> n;

    MyMinHeap heap;

    while (n--) {
        int val;
        cin >> val;
        heap.push(val);
    }

    cout << "Cây heap sau khi chèn: ";
    heap.show();

    cout << "Số phần tử cần xóa: ";
    cin >> n;

    while (n--) {
        int val;
        cin >> val;
        heap.remove(val);
    }

    cout << "Heap sau khi xóa: ";
    heap.show();

    return 0;
}
