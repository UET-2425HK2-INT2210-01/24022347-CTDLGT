#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

// Hàm DFS để thực hiện sắp xếp topo (từ dưới lên)
void dfsTopo(const vector<vector<int>> &ke, vector<bool> &daTham, int u, stack<int> &thuTu) {
    daTham[u] = true;
    for (int v : ke[u]) {
        if (!daTham[v]) dfsTopo(ke, daTham, v, thuTu);
    }
    thuTu.push(u); // Sau khi duyệt hết các đỉnh kề, đưa đỉnh hiện tại vào kết quả
}

// Hàm chính để sắp xếp topo
void sapXepTopo(const vector<vector<int>> &ke, int soDinh, stack<int> &ketQua) {
    vector<bool> daTham(soDinh + 1, false);
    for (int i = 1; i <= soDinh; ++i) {
        if (!daTham[i]) dfsTopo(ke, daTham, i, ketQua);
    }
}

int main() {
    ifstream fileIn("jobs.txt");
    ofstream fileOut("jobs.out");

    int dinh, canh;
    fileIn >> dinh >> canh;

    vector<vector<int>> danhSachKe(dinh + 1);
    for (int i = 0; i < canh; ++i) {
        int u, v;
        fileIn >> u >> v;
        danhSachKe[u].push_back(v);
    }

    stack<int> ketQuaTopo;
    sapXepTopo(danhSachKe, dinh, ketQuaTopo);

    while (!ketQuaTopo.empty()) {
        fileOut << ketQuaTopo.top() << ' ';
        ketQuaTopo.pop();
    }

    return 0;
}
