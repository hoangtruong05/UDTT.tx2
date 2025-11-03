#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;   // slg dthoai toi da
const int MAXS = 1000; // Kích thuoc tui toi da

int n, S;

struct Phone {
    char brand[30];  
    int size;        
    int price;       
};

Phone phones[MAXN];       // Mang luu cac dthoai
int dp[MAXN][MAXS];       // Bang qhd
int trace[MAXN][MAXS];    // Truy vet
int chosen[MAXN];         // Mang luu dthoai dc chon

void input() {
    cout << "Nhap so luong dien thoai (5 <= n <= 10): ";
    cin >> n;
    cout << "Nhap kich thuoc tui (inch): ";
    cin >> S;

    cout << "\nNhap thong tin cac dien thoai:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Dien thoai " << i << ":\n";
        cout << "  Nhan hieu: "; fflush(stdin); gets(phones[i].brand);
        cout << "  Kich thuoc man hinh (inch): ";
        cin >> phones[i].size;
        cout << "  Gia ban: ";
        cin >> phones[i].price;
    }
}

// Thu?t toán quy ho?ch d?ng
void knapsack() {
    // Khoi tao dp và trace
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= S; j++) {
            dp[i][j] = 0;
            trace[i][j] = 0;
        }

    // Duyet tung dthoai
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= S; j++) {
            // TH1: Không chon dthoai i
            dp[i][j] = dp[i - 1][j];
            trace[i][j] = 0;

            // TH2: neu chon dthoai i
            if (j >= phones[i].size) {
                int value = dp[i - 1][j - phones[i].size] + phones[i].price;
                if (value > dp[i][j]) {
                    dp[i][j] = value;
                    trace[i][j] = 1; // Ðánh d?u ch?n
                }
            }
        }
    }
}

// Truy vet de tim dthoai dc chon
int tracePhones() {
    int i = n, j = S, k = 0;

    while (i > 0) {
        if (trace[i][j] == 1) {
            chosen[k] = i;
            k++;
            j -= phones[i].size;
        }
        i--;
    }

    // Ðao nguoc dsach chon cho dung thu tu
    for (int x = 0; x < k / 2; x++) {
        int temp = chosen[x];
        chosen[x] = chosen[k - x - 1];
        chosen[k - x - 1] = temp;
    }

    return k; // Tra ve slg dthoai dc chon
}

// Xu?t k?t qu?
void output() {
    cout << "\nTong gia tri lon nhat co the dat duoc: " << dp[n][S] << endl;

    int count = tracePhones();
    cout << "So dien thoai duoc chon: " << count << endl;
    cout << "Danh sach cac dien thoai duoc chon:\n";
    for (int i = 0; i < count; i++) {
        int idx = chosen[i];
        cout << "  - " << phones[idx].brand
             << " (Gia: " << phones[idx].price
             << ", Kich thuoc: " << phones[idx].size << " inch)" << endl;
    }
}

// Hàm main
int main() {
    input();
    knapsack();
    output();
    return 0;
}

