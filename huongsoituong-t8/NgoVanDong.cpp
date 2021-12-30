#include <iostream>
#include <string>
using namespace std;
class khachsan{
	public:
		  virtual void nhap()=0;
 		 virtual void xuat()=0;
		 virtual int tientong()=0;
};
class giatla:public khachsan
{
	private: 
		int sokg;
		int dongia;
		int tiendichvu;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap so kg quan ao: ";
			cin>>sokg;
			cout<<"\nNhap don gia: ";
			cin>> dongia;
			cout<<"\nNhap tien dich vu: ";
			cin>>tiendichvu;
		};
		void xuat(){
			cout<<"\nSo kg: "<<sokg;
			cout<<"\nDon gia: "<<dongia;
			cout<<"\nTien dich vu: "<<tiendichvu;
			cout<<"\nTong tien: "<<tientong();
		};
		int tientong(){
			if(sokg> 5 )
			return (sokg * dongia +tiendichvu) * 0.05;
			else if(sokg < 5)
			return sokg * dongia + tiendichvu;
		};
};
class thuexe:public khachsan{
	private: 
		int sogio;
		int dongia;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap so gio thue xe: ";
			cin>>sogio;
			cout<<"\nNhap don gia: ";
			cin>>dongia;
		};
		void xuat(){
			cout<<"\nSo gio: "<<sogio;
			cout<<"\nDon gia: "<<dongia;
			cout<<"\nTong tien: "<<tientong();
		};
		int tientong(){
			if( sogio > 10)
			return (sogio * dongia) * 0.1;
			else if(sogio < 10)
			return sogio*dongia;
		};	
};
class khachhang 
{
	private: 
		char mahoadon[20];
		char makhachhang[20];
		char tenkhachhanh[30];
		khachsan * dichvu;
		
	public:
		int c;
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ma hoa don: ";
			cin.getline(mahoadon, 20);
			cout<<"\nNhap ma khach hang: ";
			cin.getline(makhachhang, 20);
			cout<<"\nNhap ho ten khanh hang: ";
			cin.getline(tenkhachhanh, 30);
			cout << " - Nhap thong tin goi dich vu: \nChon loai goi cuoc (1: Tinhoc, 2:Ngoaingu): ";
			cin >> c;
			if (c == 1)
			dichvu = new giatla;
			else if (c == 2)
			dichvu = new thuexe;
			dichvu->nhap();
		};
		void xuat(){
			cout<<"\nNhap ma hoa don: "<<mahoadon;
			cout<<"\nNhap ma khach hang: "<<makhachhang;
			cout<<"\nNhap ten khach hang: "<<tenkhachhanh;
            dichvu->xuat();
		};
		int tienphaidong(){
			return dichvu->tientong();
		}		
};
int main()
{
	khachhang * a;
	int n;
	a = new khachhang[n];
	cout<<"\nNhap so hoa don";
	cin>>n;
    int chon ,i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t----Menu----";
			cout<<"\n\t\t1.Nhap hoa don cua khach hang.";
			cout<<"\n\t\t2.In hoa don khach hang.";
			cout<<"\n\t\t3.Tien ma trung tam nhan duoc.";
			cout<<"\n\t\t4.Loc ra tien dich tren 10 trieu.";
			cout<<"\n\t\t99.Thoat!";
			cout<<"\n\t\tLua chon: ";
			cin>>chon;
		switch(chon)
		{
		 	case 1:
	 		{
 				system("cls");
 				cout<<"\n\t\tNhap hoa don cua khach hang."<<endl;
 				for(i=0;i<n;i++){
				 	a[i].nhap();
				 }
 				system("pause");
 			}
			 break;
			 	case 2:
 			{
 				system("cls");
 				cout<<"\n\t\tXuat hoa don cua khach hang."<<endl;
 				for(i=0;i++;i<n){
 					cout<<"\nSTT: "<<i+1;
				 	a[i].xuat();
				 }
 				system("pause");
 			}
			 break;
			 	case 3:
	 		{
 				system("cls");
 				cout<<"\n\t\tTong tien nhan duoc cua khach san."<<endl;
 				int tong = 0;
 				for(i=0;i++;i<n){
 					tong = tong + a[i].tienphaidong();
				 }
			    cout<<"\nTong so tien ma khach san thu dc: "<<tong<<endl;
 				system("pause");
 			}
			 break;	
			 	case 4:
	 		{
 				system("cls");
 				cout<<"\n\t\tKhach hang co tien giat la tren 10 trieu ."<<endl;
 				for(i=0;i++;i<n){
 					if(a[i].c == 1 && a[i].tienphaidong() > 10000000)
 					a[i].xuat();
				 }
 				system("pause");
 			}
			 break;	
			 default:
			break;		
		}
		
	}while(chon!=99);
}
