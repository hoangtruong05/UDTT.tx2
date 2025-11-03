#include <bits/stdc++.h>

using namespace std;

struct Fan{
	char ten[10];
	char mausac[10];
	float gia;
};

void nhapthongtinfan(Fan fans[], int n){
	cout<<"---Nhap thong tin quat---\n";
	for(int i=0;i<n;++i){
		cout<<"Quat "<<i+1<<endl;
		cout<<"Hang san xuat : ";fflush(stdin);gets(fans[i].ten);
		cout<<"Mau sac : ";fflush(stdin);gets(fans[i].mausac);
		cout<<"Gia ban : ";cin>>fans[i].gia;	
	}
}

void sapxep(Fan fans[], int n){
	for(int i=0;i<n-1;++i){
		for(int j=i+1;j<n;++j){
			if(fans[i].gia>fans[j].gia){
				swap(fans[i],fans[j]);
			}
		}
	}
}

int chonquat(Fan fans[], int n, int p, Fan selected[], int &tongtien){
//	fans[]: mang quat dc luu sx tang dan
//	selected[]: mang luu cac quat dc chon
	
	
	tongtien = 0;
	int tongquatchon = 0;
	
	for(int i=0;i<n;++i){
		if(tongtien + fans[i].gia <= p){
			selected[tongquatchon] = fans[i];   //luu quat i vao mang selected o vtri tonguatchon
			tongtien += fans[i].gia;
			tongquatchon++;
 		} else break;
	} return tongquatchon;
}

void intieude(){
	cout<<left<<setw(20)<<"Ten hang sx "
		<<left<<setw(15)<<"Mau sau"
		<<left<<setw(20)<<"Gia ban"<<endl;
}

void inkq(Fan selected[], int tongquatchon, int tongtien, int p){
	cout<<"===DANH SACH QUAT==="<<endl;
	
	cout << "So tien ban co: " << p << " VND\n";
    if (totalFans == 0) {
        cout << "Khong the mua duoc chiec quat nao.\n";
    } else {
		intieude();
		for(int i=0;i<tongquatchon;++i){
			cout<<left<<setw(20)<<selected[i].ten
				<<left<<setw(15)<<selected[i].mausac
				<<left<<setw(20)<<selected[i].gia<<endl;
		}
	}
	cout<<"So quat co the mua : "<<tongquatchon<<endl;
	cout<<"So tien da su dung : "<<tongtien<<endl;
}

int main() {
	int n,p;
	do{
		cout<<"Nhap so tien ban co(0<p<1200000) : ";
		cin>>p;
		if(p<=0 || p>=1200000) cout<<"Vui long nhap lai\n";
	}while(p<=0 || p>=1200000);
	
	do{
		cout<<"Nhap so luong quat(5<n<12) : "; 
		cin>>n;
		if(n<=5 || n>=12) cout<<"Vui long nhap lai\n";
	}while(n<=5 || n>=12);
	
	
	Fan fans[12];
	Fan selected[12];
	
	nhapthongtinfan(fans,n);
	
	sapxep(fans,n);
	
	int tongtien=0;
	int tongquatchon = chonquat(fans,n,p,selected,tongtien);
	
	inkq(selected,tongquatchon,tongtien,p);
	
	return 0;
}
