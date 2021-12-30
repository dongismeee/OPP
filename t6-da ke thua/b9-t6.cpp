#include<iostream>
#include<string>
using namespace std;
class quanly
{
	public:
		int ngay;
		int thang;
		int nam;
		virtual void nhap(){
			cout<<"\nNhap vao ngay GD (ngay/ thang/ nam): ";
		 	cin>>ngay;cin>>thang;cin>>nam;
		};
		virtual void xuat(){
			cout<<"\nNgay: "<<ngay;
			cout<<"\nThang: "<<thang;
			cout<<"\nNam: "<<nam;
		};
		virtual float thanhtien() =0;
		friend void menugd_dat();
		friend void menugd_nha();
		friend void timgd();
};
class gd_dat:public quanly{
	protected:
		char magd[10];
		float dongia;
		char loaidat[2];
		float dientich;
	public:
	 	void nhap(){
	 		quanly::nhap();
	 		fflush(stdin);
	 		cout<<"\nNhap ma gia dich: ";
	 		cin.getline(magd, 10);
 		
	 		cout<<"\nNhap don gia: ";
	 		cin>>dongia;
	 		cout<<"\nNhap loai dat(A-B-C): ";
	 		cin.getline(loaidat, 2);
	 		cout<<"\nNhap dien tich: ";
	 		cin>>dientich;
	 	};
		void xuat(){
			quanly::xuat();
			cout<<"\nMa gia dich: "<<magd;
			
			cout<<"\nDon gia: "<<dongia;
			cout<<"\nLoai dat: "<<loaidat;
			cout<<"\nDien tich: "<<dientich;
			cout<<"\nThanh tien: "<<thanhtien();
		};
		float thanhtien(){
			if(strcmp(loaidat,"B")==0 || strcmp(loaidat,"C")==0){
				return dientich * dongia;
			}
			if(strcmp(loaidat,"A")==0){
				return dientich * dongia * 1.5;
			}
		}
			
};
class gd_nha:public quanly
{
	private:
		char magd[10];
		int Ngay;
		int Thang;
		int Nam;
		float dongia;
		char loainha[15];
		char diachi[30];
		float dientich;
	public:	
		void nhap(){
			quanly::nhap();
	 		fflush(stdin);
	 		cout<<"\nNhap ma gia dich: ";
	 		cin.getline(magd, 10);
	 		cout<<"\nNhap don gia: ";
	 		cin>>dongia;
	 		cout<<"\nNhap loai nha(Cap cap- Thuong): ";
	 		cin.getline(loainha, 15);
	 		cout<<"\nNhap vao dia chi: ";
	 		cin.getline(diachi, 30);
	 		cout<<"\nNhap dien tich: ";
	 		cin>>dientich;
	 	};
		void xuat(){
			quanly::xuat();
			cout<<"\nMa gia dich: "<<magd;
			
			cout<<"\nDon gia: "<<dongia;
			cout<<"\nLoai nha: "<<loainha;
			cout<<"\nDia chi: "<<diachi;
			cout<<"\nDien tich: "<<dientich;
			cout<<"\nThanh tien: "<<thanhtien();
		};
		float thanhtien(){
			if(strcmp(loainha,"Thuong")==0){
				return dientich * dongia;
			}
			else{
				return dientich * dongia * 0.9;
			}
		}	
		
};
void menugd_dat(quanly * a[], int n){
	int chon1, i;
		do
		{
			system("cls");
			cout<<"\n\t\t\t-----GIAODICHDAT------";
			cout<<"\n\t\t1.Nhap thong tin.";
			cout<<"\n\t\t2.Xuat thong tin Giao dich.";
			cout<<"\n\t\t3..Tong so tien giao dich.";
			cout<<"\n\t\t4.Trung binh so tien cua moi giao dich.";
			cout<<"\n\t\t99.Thoat!";
			cout<<"\n\t\tLua chon: ";
			cin>>chon1;
			switch(chon1)
				{
					case 1: 
					{
						system("cls");
						cout<<"\nNhap so giao dich: ";
						cin>>n;
						for(i=0;i<n;i++){
							cout<<"\nThong tin gd thu: "<<i+1;
							a[i]->nhap();
						}
						system("pause");
					}
					break;
					case 2: 
					{
						system("cls");
						cout<<"\nDanh sach giao dich.";
						for(i-0;i<n;i++){
							cout<<"\nSTT "<<i+1;
							a[i]->xuat();
						}
						system("pause");
					}
					break;
					case 3:
					{
						system("cls");
						float tong;
						tong=0;
						for(i=0;i<n;i++){
							tong += a[i]->thanhtien();
						}
						cout<<"\nTong so tien giao dich: "<<tong;
						system("pause");
					}
					break;
					case 4:
					{
						system("cls");
						float tong2, tb;
						tong2=0;
						tb=0;
						for(i=0;i<n;i++){
							tong2 += a[i]->thanhtien();
						}
						tb =tong2/i;
						cout<<"\nTong so tien trung binh cua moi giao dich: "<<tb;
						system("pause");
					}
					break;
				default:
					break;	
				}
		}while(chon1!=99);
};
void menugd_nha(quanly *a[], int n){
	int chon2, i;
	do
		{
			system("cls");
			cout<<"\n\t\t\t-----GIAODICHNHA------";
			cout<<"\n\t\t1.Nhap thong tin.";
			cout<<"\n\t\t2.Xuat thong tin Giao dich.";
			cout<<"\n\t\t3..Tong so tien giao dich.";
			cout<<"\n\t\t99.Thoat!";
			cout<<"\n\t\tLua chon: ";
			cin>>chon2;
			switch(chon2)
				{
					case 1: 
					{
						system("cls");
						cout<<"\nNhap so giao dich: ";
						cin>>n;
						for(i=0;i<n;i++){
							cout<<"\nThong tin gd thu: "<<i+1;
							a[i]->nhap();
						}
						system("pause");
					}
					break;
					case 2: 
					{
						system("cls");
						cout<<"\nDanh sach giao dich.";
						for(i-0;i<n;i++){
							cout<<"\nSTT "<<i+1;
							a[i]->xuat();
						}
						system("pause");
					}
					break;
					case 3:
					{
						system("cls");
						float tong;
						tong=0;
						for(i=0;i<n;i++){
							tong += a[i]->thanhtien();
						}
						cout<<"\nTong so tien giao dich: "<<tong;
						system("pause");
					}
					break;
				default:
					break;	
				}
		}while(chon2!=99);
}
void timgd(quanly *a[],int n){
	for(int i=0;i<n;i++){
		if(a[i]->thang =9 && a[i]->nam == 2013 )
		a[i]->xuat();
	}
}
int main(){
	quanly * a[100];
	int chon, i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t-----MENU------";
		cout<<"\n\t\t1.Giao dich dat.";
		cout<<"\n\t\t2.Giao dich nha.";
		cout<<"\n\t\t3.Tim giao dich thang 9 nam 2013.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon;
			switch(chon)
				{
					case 1: 
					{
						system("cls");
						for(i=0;i<100;i++){
							a[i]= new gd_dat();
						}
						menugd_dat(a,100);
						system("pause");
					}
					break;
					case 2: 
					{
						system("cls");
						for(i=0;i<100;i++){
							a[i]= new gd_nha();
						}
						menugd_nha(a,100);
						system("pause");
					}
					break;
					case 3:
					{
						system("cls");
						cout<<"\nGiao dich thang 9 nam 2013: ";
						timgd(a,100);
						system("pause");
					}
					break;
				default:
					break;	
				}
	}while(chon!=99);
	return 0;
}
