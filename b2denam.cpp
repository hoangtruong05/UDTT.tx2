#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXS = 1000;
int n,s;

struct canruou{
	char nhanhieu[20];
	int dungtich;
	int giatri;
};

canruou can[MAXN];
int dp[MAXN][MAXS];
int trace[MAXN][MAXS];
int choosen[MAXN];

void input(){
	cout<<"Nhap so luong can ruou: ";cin>>n;
	cout<<"Nhap dung tich lon nhat: ";cin>>s;
	
	cout<<"===Nhap thong tin can ruou===\n";
	for(int i=0;i<n;i++){
		cout<<"Can ruou thu "<<i+1<<endl;
		cout<<"Nhap nhan hieu: ";fflush(stdin);gets(can[i].nhanhieu);
		cout<<"Nhap dung tich: ";cin>>can[i].dungtich;
		cout<<"Nhap gia tri: ";cin>>can[i].giatri;
	}
}

void quyhoachdong(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			dp[i][j]=0;
			trace[i][j]=0;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			dp[i][j]=dp[i-1][j];
			trace[i][j] = 0;
			if(j>=can[i-1].dungtich){
				int value=dp[i-1][j-can[i-1].dungtich]+can[i-1].giatri;
				if(value > dp[i][j]){
					dp[i][j]=value;
					trace[i][j] = 1;
				}
			}
		}
	}
}

int traceCan(){
	int i=n;
	int j=s;
	int k=0;
	while(i>0){
		if(trace[i][j]==1){
			choosen[k]=i-1;
			k++;
			j-=can[i-1].dungtich;
		}
		i--;
	}
	for(int x=0;x<k/2;x++){
		int tg=choosen[x];
		choosen[x]=choosen[k-x-1];
		choosen[k-x-1] = tg;
	}
	return k;
}

void output(){
	cout<<"Tong gia tri toi da: "<<dp[n][s]<<endl;
	int dem=traceCan();
	cout<<"So can duoc chon : "<<dem<<endl;
	cout<<"===Danh sach ===\n";
	for(int i=0;i<dem;i++){
		int idx=choosen[i];
		cout<<"Nhan hieu"<<can[idx].nhanhieu
			<<"( Dung tich: "<<can[idx].dungtich
			<<", Gia tri: "<<can[idx].giatri<<" )\n";
	}
}

int main(){
	input();
	quyhoachdong();
	output();
	return 0;
}
