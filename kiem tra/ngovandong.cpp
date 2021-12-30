#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class trungtam{
	public:
		virtual void nhap() =0;
 		virtual void xuat() =0;
		virtual int tienhocphi() =0;	
};
class ddtinhoc:public trungtam
{
	private: 
		int sobuoi;
		int dongia;
		int tiendichvu;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap so buoi hoc: ";
			cin>>sobuoi;
			cout<<"\nNhap don gia: ";
			cin>> dongia;
			cout<<"\nNhap tien dich vu: ";
			cin>>tiendichvu;
		};
		void xuat(){
			cout<<"\nSo buoi hoc: "<<sobuoi;
			cout<<"\nDon gia: "<<dongia;
			cout<<"\nTien dich vu: "<<tiendichvu;
			cout<<"\nTien phai dong: "<<tienhocphi();
		
		};
		int tienhocphi(){
			if(sobuoi > 10 )
			return ((10*dongia) + tiendichvu) + (((sobuoi-10)*dongia) + tiendichvu);
			else if(sobuoi < 10)
			return sobuoi * dongia + tiendichvu;
		};
};
class ngoaingu:public trungtam{
	private: 
		int sogio;
		int dongia;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap so gio hoc : ";
			cin>>sogio;
			cout<<"\nNhap don gia: ";
			cin>>dongia;
		};
		void xuat(){
			cout<<"\nSo gio hoc: "<<sogio;
	
			cout<<"\nDon gia: "<<dongia;
			cout<<"\nTien phai dong: "<<tienhocphi();
		};
		int tienhocphi(){
			if( sogio > 50)
			return (sogio*50) + ((sogio-50)*dongia)*0.15;
			else if(sogio < 50)
			return sogio*dongia;
		};	
};
class khachhang 
{
	protected:
		char mahoadon[20];
		char makhachhang[20];
		char tenkhachhanh[30];
		trungtam * dichvu;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ma hoa don: ";
			cin.getline(mahoadon, 20);
			cout<<"\nNhap ma khach hang: ";
			cin.getline(makhachhang, 20);
			cout<<"\nNhap ho ten khanh hang: ";
			cin.getline(tenkhachhanh, 30);
			int c;
			cout << " - Nhap thong tin goi dich vu: \nChon loai goi cuoc (1: Tinhoc, 2:Ngoaingu): ";
			cin >> c;
			if (c == 1)
			dichvu = new ddtinhoc;
			else if (c == 2)
			dichvu = new ngoaingu;
			dichvu->nhap();
		};
		void xuat(){
			cout<<"\nNhap ma hoa don: "<<mahoadon;
			cout<<"\nNhap ma khach hang: "<<makhachhang;
			cout<<"\nNhap ten khach hang: "<<tenkhachhanh;
			dichvu->xuat();
		};
		int tienphaidong(){
			return dichvu->tienhocphi();
		};		
};
class DanhSachHopDong {
	private:
		vector <khachhang*> dsKhachHang;
	public:
		void hoadon(){
			khachhang * kh;
			kh = new khachhang();
			kh->nhap();
			dsKhachHang.push_back(kh);
		};
		void inhoadon() {
			cout<<"\nDanh sach hoa don";
			for(int i=0;i<dsKhachHang.size();i++)
			{
				dsKhachHang[i]->xuat();
			}
		};
		void tinhtongtien(){
			unsigned int S=0;
			for(int i=0;i<dsKhachHang.size();i++)
			{
				S=S+ dsKhachHang[i]->tienphaidong();
			} 
			cout<<"\nTong Tien Trung Tam nhan duoc :"<<S;
		};
		void loctiendicvu(){
			for(int i=0;i<dsKhachHang.size();i++)
			{
				if(dsKhachHang[i]->tienphaidong() > 5000000){
					dsKhachHang[i]->xuat();
				};
			} 
			
		}		
}; 
int menu(DanhSachHopDong &a){
	int chon, i;
		do{
			system("cls");
			cout<<"\n\t\t\t----Menu----";
			cout<<"\n\t\t1.Nhap hoa don cua khach hang.";
			cout<<"\n\t\t2.In hoa don khach hang.";
			cout<<"\n\t\t3.Tien ma trung tam nhan duoc.";
			cout<<"\n\t\t4.Loc ra tien dich tren 5 trieu.";
			cout<<"\n\t\t99.Thoat!";
			cout<<"\n\t\tLua chon: ";
			cin>>chon;
			switch(chon){
				case 1:
				{
					system("cls");
					a.hoadon();
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");
					a.inhoadon();
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");
					a.tinhtongtien();
					system("pause");
				}
				break;
				case 4:
				{
					system("cls");
					a.loctiendicvu();
					system("pause");
				}
				break;
				
			}
			
		}while(chon!=99);
		return 0;
}
int main()
{
	DanhSachHopDong a;
	menu(a);
	system("pause");
	return 0;
}