#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;
class QD
{
	private:
		string ma, hsx;
		float dg, sl;
	public:
			QD(string maquatdien = "", string hangsx = "", float dongia = 0, float soluong = 0)
		{
			this->ma = maquatdien;
			this->hsx = hangsx;
			this->dg = dongia;
			this->sl = soluong;
		}
		~QD(){}
		
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ma quat dien: ";
			getline(cin, this->ma);
			cout<<"\nNhap ten hang san xuat: ";
			getline(cin, this->hsx);
			fflush(stdin);
			cout<<"\nNhap don gia: ";
			cin>>this->dg;
			cout<<"\nNhap so luong: ";
			cin>>this->sl;
		}
		void in(){
			cout<<setw(10)<<this->ma<<setw(10)<<this->hsx<<setw(10)<<this->dg<<setw(10)<<this->sl<<endl;
		}
		friend istream& operator >>(istream &is, QD &qt);
		friend ostream& operator <<(ostream &os, QD qt);
		bool operator < (QD qd1){
			bool result;
			if(this->dg < qd1.dg){
				result = true;
			}
			return result;
		}
		float thanhtien(){
			return (this->dg*this->sl) + (this->dg*this->sl)*0.1;
		}
		string getH(){
			return this->hsx;
		}
		string getM(){
			return this->ma;
		}
};
istream& operator >>(istream &is, QD &qt){
	
			fflush(stdin);
			cout<<"\nNhap ma quat dien: ";
			getline(is, qt.ma);
			cout<<"\nNhap ten hang san xuat: ";
			getline(is, qt.hsx);
			fflush(stdin);
			cout<<"\nNhap don gia: ";
			is>>qt.dg;
			cout<<"\nNhap so luong: ";
			is>>qt.sl;
			return is;
}
ostream& operator <<(ostream &os, QD qt){
	os<<setw(10)<<qt.ma<<setw(10)<<qt.hsx<<setw(10)<<qt.dg<<setw(10)<<qt.sl<<endl;
	return os;
}
void nhapds(QD *&a, int &n){
		for(int i=0; i<n; i++){
		cout<<"\nNhap quat dien thu "<<i+1<<endl;
		cin>>a[i];
	}
}
void xuatds(QD *&a, int n){
	for(int i=0; i<n; i++){
		cout<<"\nIn quat dien thu "<<i+1<<endl;
		cout<<a[i];
	}
}
void sxhang(QD *&a, int &n){
	cout<<"\n---------->Danh sach sap xep giam dan theo ten hang.<----------";
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(a[i].getH() < a[j].getH()){
				QD tg;
				tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
	}
	
	xuatds(a,n);
	
}
void tien(QD *&a, int n){
	// in ra tien nho hon 200 USD
	cout<<"\n---------->Thanh tien lon hon 200USD<----------"<<endl;
	for(int i = 0; i<n; i++){
		if(a[i].thanhtien() < 200){
			cout<<a[i]<<endl;
		}
	}
}
void searchM(QD *&a, int n){
	// tim kiem ma
	string str = "quatd 12345";
	int index = 0;
	bool KT = false;
	for(int i = 0; i< n; i++){
		if(a[i].getM() == str){
			KT = true;
			for(i=n; i>=0; i--){
				a[i]=a[i+1];
				}
				n--;
			}
		}
		if(!KT){
			cout<<"\n---------> danh sach khong co ma quatd 12345";
		}
}
void chen(QD *&a, int &n){
		//tim kiem hang, chen
		string strH = "senko";
		int index2 = 0;
		bool KT2 = false;
		for(int i = 0; i< n; i++){
			if(a[i].getM() == strH){
				KT2 = true;
				index2 = i;
				}
		}
		if(!KT2){
			cout<<"\n--------->Hang senko khong co trong danh sach.<----------"<<endl;
			cout<<"\nMoi nhap thong tin hang senko: "<<endl;
			int k;
			cout<<"\nNhap vi tri can chen: ";
			cin>>k;
			n++; 
			for(int i = n-1; i>=k ; i--) 
			{
				a[i] = a[i - 1];
			}
			cin>>a[k];
			
			cout << "\n---------> Danh sach hang sony khi them <----------";
			for(int i = 0;  i<n;i++) 
			{
				cout << a[i] << endl; 
			}
		}
}
void menu(QD *&a, int &n){
	
		
		cout<<"\n 1. xuat danh sach .";
		cout<<"\n 2. quat co so tien nho hon 200USD .";
		cout<<"\n 3. Tim quat dien co ma quatd 12345 .";
		cout<<"\n 4.  Tim quat dien co hang san xuat SENKO, Chen doi tuong .";
		cout<<"\n 5. sap xep quat theo ten hang san xuat";
	while(true){
		int key;
		cout<<"\nNhap lua chon: ";
		cin>>key;
		if(key == 1){
			xuatds(a,n);
		}else if(key == 2){
			tien(a, n);
		}else if(key == 3){
			searchM(a, n);
		}else if(key == 4){
			chen(a, n);
		}else if(key == 5){
			sxhang(a, n);
		}
	}
}

int main(){
	int n;
	cout<<"\nNhap so luong Quat Dien: ";
	cin>>n;
	QD *a;
	a = new QD[n+1];
	nhapds(a, n);
	menu(a,n);
return 0;
}
