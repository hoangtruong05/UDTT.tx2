#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
const int MAX = 100;
struct CanRuou {
    string nhanHieu;
    int dungTich; 
    int giaTri;   
};

// Ham so sanh theo gia tri tang dan (cho tham lam)
bool cmpGia(CanRuou a, CanRuou b) {
    return a.giaTri < b.giaTri;
}

void thuatToanA(CanRuou ds[], int n, int m) {
    // Sap xsp tang dan theo gia tri
    sort(ds, ds + n, cmpGia);

    int tongTien = 0, dem = 0;

    cout << "\n Voi so tien m = " << m << " VND mua duoc nhieu nhat: \n";
    for (int i = 0; i < n; i++) {
        if (tongTien + ds[i].giaTri <= m) {
            tongTien += ds[i].giaTri;
            cout << "- " << ds[i].nhanHieu << " | " << ds[i].giaTri << " VND\n";
            dem++;
        }
    }
    cout << "==> Tong so can mua: " << dem << ", Tong tien da dung: " << tongTien << " VND\n";
}

// Câu 2: 
void thuatToanB(CanRuou ds[], int n, int S) {
    int dp[MAX][MAX] = {0};
    // Lap bang phuong an
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= S; j++) {
            if (ds[i-1].dungTich > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - ds[i-1].dungTich] + ds[i-1].giaTri);
            }
        }
    }

 cout << "\n===  (Dung tich S = " << S << "L) ===\n";
    cout << "Tong gia tri lon nhat: " << dp[n][S] << " VND\n";
    // Truy vet đe tim danh sach ruou đa chon
    cout << "Danh sach ruou duoc chon:\n";
    int i = n, j = S;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            cout << "- " << ds[i-1].nhanHieu << " | " << ds[i-1].dungTich << "L | " << ds[i-1].giaTri << " VND\n";
            j -= ds[i-1].dungTich;
        }
        i--;
    }
}

int main() {
    int n = 8;
    CanRuou danhSach[MAX] = {
        {"Vang Phap", 2, 1200000},
        {"Chivas", 5, 900000},
        {"Vodka", 3, 500000},
        {"Sake", 1, 400000},
        {"Whisky", 4, 1000000},
        {"Nep Moi", 2, 300000},
        {"Hennessy", 10, 2000000},
        {"Soju", 1, 150000}
    };
    int m = 2000000;
    int S = 100;     

    thuatToanA(danhSach, n, m);
    thuatToanB(danhSach, n, S);

    return 0;
}
