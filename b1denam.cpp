#include<bits/stdc++.h>

using namespace std;

struct canruou{
	char nhanhieu[20];
	int dungtich;
	int giatri;
};

void input(canruou can[], int n){
	cout<<"===Nhap danh sach can ruou===\n";
	for(int i=0;i<n;i++){
		cout<<"Can ruou thu "<<i+1<<endl;
		cout<<"Nhap nhan hieu: ";fflush(stdin);gets(can[i].nhanhieu);
		cout<<"Nhap dung tich (lit): ";cin>>can[i].dungtich;
		cout<<"Nhap gia tri (VND): ";cin>>can[i].giatri;
	}
}

void sapxep(canruou can[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(can[i].giatri>can[j].giatri){
				swap(can[i],can[j]);
			}
		}
	}
}

int choncan(canruou can[],int n, int m,canruou selected[],int &tongtien){
	tongtien =0;
	int tongcanchon = 0;
	for(int i=0;i<n;i++){
		if(tongtien + can[i].giatri<=m){
			selected[tongcanchon] = can[i];
			tongtien+= can[i].giatri;
			tongcanchon++;
		}else break;
	}
	return tongcanchon;
}

void inkq(canruou selected[],int tongcanchon,int tongtien, int m){
	cout<<"So tien co "<<m<<endl;
	if(tongcanchon ==0){
		cout<<"Khong the mua can nao\n";
	}else{
		cout<<"===Danh sach can ruou co the mua===\n";
		cout<<left<<setw(20)<<"Nhan hieu"
			<<left<<setw(15)<<"Dung tich"
			<<left<<setw(15)<<"Gia tri"<<endl;
		for(int i=0;i<tongcanchon;i++){
			cout<<left<<setw(20)<<selected[i].nhanhieu
				<<left<<setw(15)<<selected[i].dungtich
				<<left<<setw(15)<<selected[i].giatri<<endl;
		}
	}
	cout<<"So can nhieu nhat co the mua"<<tongcanchon<<endl;
	cout<<"So tien sd"<<tongtien<<endl;
}

int main(){
	int n,m;
	int tongtien =0;
	do{
		cout<<"Nhap so luong can ruou: ";cin>>n;
	}while(n<=0 || n>6);
	m=100;
	
	canruou can[20];
	canruou selected[20];
	input(can,n);
	sapxep(can,n);
	int tongcanchon = choncan(can,n,m,selected,tongtien);
	inkq(selected,tongcanchon,tongtien,m);
	return 0;
}
