#include <iostream>
using namespace std;
class nguoi{
	protected: 
 		char hoten[30];
 	public:
 		nguoi(){
		 	hoten[30]=' ';
		 };
		~nguoi(){
		};
		virtual void nhap(){
			fflush(stdin);
			cout<<"\nNhap ho va ten: ";
			cin.getline(hoten,30);
		};
		virtual void xuat(){
			cout<<"\nHo ten: "<<hoten;
		};
		virtual int thuong()= 0;
};
class sinhvien:public nguoi {
	protected: 
		float diem;
	public:
		sinhvien(){
			diem = 0;
		};
		~sinhvien(){
		};
		void nhap(){
			nguoi::nhap();
			fflush(stdin);
			cout<<"\nNhap diem: ";
			cin>>diem;
		};
		void xuat(){
			nguoi::xuat();
			cout<<"\nDiem: "<<diem;
		};
		int thuong(){
			if(diem > 8)
				return 1;	
				return 0;
		};
};
class giangvien:public nguoi {
	protected:
		int sobd;
	public:
		giangvien(){
			sobd=0;
		};
		~giangvien(){
		};
		void nhap(){
			nguoi::nhap();
			fflush(stdin);
			cout<<"\nNhap so bai bao: ";
			cin>>sobd;
		};
		void xuat(){
			nguoi::xuat();
			cout<<"\nSo bai bao: "<<sobd;
		};
		int thuong(){
			if(sobd >5 )
				return 1;
				return 0;
		};	
};
int main(){
	nguoi *d[100];
	int chon , k=0, i;
	while(1){
		cout<<"\n\tNhap su lua chon";
		cout<<"\n\tGiangvien(1)-Sinhvien(2)-Thoat(3)";
		cin>>chon;
		cin.get();
		if(chon==1)		d[k] = new giangvien();
		if(chon==2)		d[k] = new sinhvien();
		if(chon==3) 	break;	
		d[k]->nhap();
		k++;
	};
	cout<<"\nDanh sach nhung nguoi duoc thuong "<<endl;
	for(i=0;i<k;i++){
		if(d[i]->thuong()== 1)
			d[i]->xuat();
	};
	return 0;	
}