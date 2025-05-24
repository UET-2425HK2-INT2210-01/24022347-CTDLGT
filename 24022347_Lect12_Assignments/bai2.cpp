#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Cấu trúc cạnh trong đồ thị
struct Canh {
    int dau, cuoi, trongSo;
    Canh(int u, int v, int w) {
        dau = u;
        cuoi = v;
        trongSo = w;
    }
};

// So sánh cạnh theo trọng số tăng dần
bool soSanhCanh(const Canh &a, const Canh &b) {
    return a.trongSo < b.trongSo;
}

// Lớp tập hợp rời - Disjoint Set Union (DSU)
class TapRoiRac {
private:
    vector<int> cha, bac;

public:
    TapRoiRac(int kichThuoc) {
        cha.resize(kichThuoc + 1);
        bac.resize(kichThuoc + 1, 0);
        for (int i = 1; i <= kichThuoc; ++i) cha[i] = i;
    }

    int timGoc(int x) {
        if (cha[x] != x) cha[x] = timGoc(cha[x]);
        return cha[x];
    }

    bool cungTap(int x, int y) {
        return timGoc(x) == timGoc(y);
    }

    void hopTap(int x, int y) {
        int gocX = timGoc(x);
        int gocY = timGoc(y);
        if (bac[gocX] > bac[gocY]) cha[gocY] = gocX;
        else if (bac[gocX] < bac[gocY]) cha[gocX] = gocY;
        else {
            cha[gocY] = gocX;
            bac[gocX]++;
        }
    }
};

// Thuật toán Kruskal - tìm cây khung nhỏ nhất
int cayKhungNhoNhat(vector<Canh> &danhSachCanh, int soDinh) {
    sort(danhSachCanh.begin(), danhSachCanh.end(), soSanhCanh);
    vector<Canh> chonCanh;
    TapRoiRac ds(soDinh);
    int tongChiPhi = 0, soCanhDaChon = 0;

    for (Canh c : danhSachCanh) {
        if (!ds.cungTap(c.dau, c.cuoi)) {
            ds.hopTap(c.dau, c.cuoi);
            tongChiPhi += c.trongSo;
            chonCanh.push_back(c);
            soCanhDaChon++;
        }
        if (soCanhDaChon == soDinh - 1) break;
    }

    if (soCanhDaChon != soDinh - 1) return -1;

    danhSachCanh = chonCanh;
    return tongChiPhi;
}

int main() {
    ifstream fileVao("connection.txt");
    ofstream fileRa("connection.out");

    int dinh, canh;
    fileVao >> dinh >> canh;

    vector<Canh> dsCanh;
    for (int i = 0; i < canh; ++i) {
        int x, y, w;
        fileVao >> x >> y >> w;
        dsCanh.emplace_back(x, y, w);
    }

    int ketQua = cayKhungNhoNhat(dsCanh, dinh);
    fileRa << ketQua << '\n';

    for (const Canh &c : dsCanh) {
        fileRa << c.dau << " " << c.cuoi << " " << c.trongSo << '\n';
    }

    return 0;
}
