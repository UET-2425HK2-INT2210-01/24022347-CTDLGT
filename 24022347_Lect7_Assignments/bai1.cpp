#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm merge để hợp nhất hai phần mảng đã được sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int p1 = left;        // con trỏ bắt đầu của mảng trái
    int p2 = mid + 1;     // con trỏ bắt đầu của mảng phải
    vector<int> merged;   // mảng tạm để lưu kết quả hợp nhất

    // So sánh và đưa phần tử nhỏ hơn vào mảng merged
    while (p1 <= mid && p2 <= right) {
        if (arr[p1] < arr[p2]) {
            merged.push_back(arr[p1++]);
        } else {
            merged.push_back(arr[p2++]);
        }
    }

    // Thêm phần tử còn lại của mảng bên trái nếu còn
    while (p1 <= mid) {
        merged.push_back(arr[p1++]);
    }

    // Thêm phần tử còn lại của mảng bên phải nếu còn
    while (p2 <= right) {
        merged.push_back(arr[p2++]);
    }

    // Ghi lại vào mảng gốc theo đúng vị trí
    for (int i = 0; i < merged.size(); ++i) {
        arr[left + i] = merged[i];
    }
}

// Hàm đệ quy merge sort để chia mảng và sắp xếp
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // Điều kiện dừng

    int mid = left + (right - left) / 2; // Tránh tràn số
    mergeSort(arr, left, mid);           // Sắp xếp nửa đầu
    mergeSort(arr, mid + 1, right);      // Sắp xếp nửa sau
    merge(arr, left, mid, right);        // Hợp nhất hai nửa
}

int main() {
    ifstream input("numbers.txt");   // Mở file input
    ofstream output("numbers.sorted"); // Mở file output
    vector<int> data;
    int number;

    // Đọc dữ liệu từ file và đưa vào vector
    while (input >> number) {
        data.push_back(number);
    }

    // Gọi merge sort để sắp xếp
    mergeSort(data, 0, data.size() - 1);

    // Ghi kết quả ra file
    for (int value : data) {
        output << value << " ";
    }

    return 0;
}
