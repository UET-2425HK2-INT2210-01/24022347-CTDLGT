#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX_COST = 1e7; // Hằng số đại diện cho vô cực

// Cấu trúc lưu thông tin cạnh: từ u đến v với trọng số w
struct Canh {
    int u, v, w;
    Canh(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

// Giải thuật Bellman-Ford
void timDuongDiNganNhat(int dinh, int batDau, vector<Canh> &dsCanh, vector<int> &kc, vector<int> &truyVet) {
    kc[batDau] = 0;
    for (int i = 1; i < dinh; ++i) {
        for (const auto &canh : dsCanh) {
            int u = canh.u, v = canh.v, w = canh.w;
            if (kc[u] < MAX_COST && kc[v] > kc[u] + w) {
                kc[v] = kc[u] + w;
                truyVet[v] = u;
            }
        }
    }
}

// Hàm truy vết đường đi từ S đến đỉnh đích
vector<int> truyVetDuongDi(const vector<int> &truyVet, int S, int dich) {
    if (S != dich && truyVet[dich] == -1) return {};
    vector<int> duong;
    for (int v = dich; v != -1; v = truyVet[v]) {
        duong.push_back(v);
    }
    reverse(duong.begin(), duong.end());
    return duong;
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<Canh> danhSachCanh;
    for (int i = 0; i < m; ++i) {
        int x, y, trongSo;
        fin >> x >> y >> trongSo;
        danhSachCanh.emplace_back(x, y, trongSo);
    }

    // Bài toán 1: Tìm đường đi ngắn nhất từ s đến e
    vector<int> khoangCach(n + 1, MAX_COST);
    vector<int> truyVet(n + 1, -1);
    timDuongDiNganNhat(n, s, danhSachCanh, khoangCach, truyVet);

    vector<int> duongDi = truyVetDuongDi(truyVet, s, e);
    fout << khoangCach[e] << '\n';
    for (int v : duongDi) fout << v << ' ';
    fout << '\n';

    // Bài toán 2: Tìm đường đi ngắn nhất từ mọi đỉnh đến các đỉnh còn lại
    for (int i = 1; i <= n; ++i) {
        vector<int> kc(n + 1, MAX_COST);
        vector<int> tv(n + 1, -1);
        timDuongDiNganNhat(n, i, danhSachCanh, kc, tv);
        for (int j = 1; j <= n; ++j) fout << kc[j] << ' ';
        fout << '\n';
    }

    return 0;
}
