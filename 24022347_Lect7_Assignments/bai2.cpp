#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    
    // Mở file input để đọc ma trận
    ifstream input("matrix.txt");
    input >> m >> n;

    // Khởi tạo ma trận m dòng, n cột
    vector<vector<int>> matrix(m, vector<int>(n));
    
    // Đọc dữ liệu từ file vào ma trận
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> matrix[i][j];
        }
    }
    input.close();

    // Các biến lưu thông tin hình chữ nhật có tổng lớn nhất
    int maxSum = matrix[0][0]; // Khởi tạo với phần tử đầu tiên
    int topRow = 0, leftCol = 0, bottomRow = 0, rightCol = 0;

    // Duyệt brute-force tất cả các hình chữ nhật con có thể
    for (int row1 = 0; row1 < m; ++row1) {
        for (int col1 = 0; col1 < n; ++col1) {
            for (int row2 = row1; row2 < m; ++row2) {
                for (int col2 = col1; col2 < n; ++col2) {
                    int sum = 0;
                    // Tính tổng các phần tử trong hình chữ nhật (row1,col1) -> (row2,col2)
                    for (int i = row1; i <= row2; ++i) {
                        for (int j = col1; j <= col2; ++j) {
                            sum += matrix[i][j];
                        }
                    }
                    // Cập nhật nếu tổng lớn hơn
                    if (sum > maxSum) {
                        maxSum = sum;
                        topRow = row1;
                        leftCol = col1;
                        bottomRow = row2;
                        rightCol = col2;
                    }
                }
            }
        }
    }

    // Chuyển chỉ số về hệ quy chiếu bắt đầu từ 1 (do đề yêu cầu)
    topRow++;
    leftCol++;
    bottomRow++;
    rightCol++;

    // Ghi kết quả vào file output
    ofstream output("matrix.out");
    output << topRow << " " << leftCol << " "
           << bottomRow << " " << rightCol << " "
           << maxSum;

    return 0;
}
