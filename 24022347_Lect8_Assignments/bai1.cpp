#include <iostream>
#include <vector>
using namespace std;

// Hàm sắp xếp nhanh sử dụng phương pháp Hoare partition
void quickSort(vector<int> &arr, int left, int right) {
    int l = left, r = right;
    int midVal = arr[(left + right) / 2]; // Chọn pivot là phần tử giữa

    // Phân đoạn mảng thành hai phần theo pivot
    while (l <= r) {
        while (arr[l] < midVal) ++l;
        while (arr[r] > midVal) --r;

        if (l <= r) {
            swap(arr[l], arr[r]);
            ++l;
            --r;
        }
    }

    // Gọi đệ quy để tiếp tục sắp xếp hai nửa còn lại
    if (left < r) quickSort(arr, left, r);
    if (l < right) quickSort(arr, l, right);
}

int main() {
    int size; 
    cin >> size;
    vector<int> numbers(size); // Khởi tạo mảng vector chứa phần tử cần sắp xếp

    // Nhập dữ liệu đầu vào
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    // Gọi hàm sắp xếp nhanh
    quickSort(numbers, 0, size - 1);

    // Xuất kết quả sau khi sắp xếp
    for (int val : numbers) {
        cout << val << " ";
    }

    return 0;
}
