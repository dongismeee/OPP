#include <iostream>
using namespace std;
class quanlyxe {
	protected:
		char masoxe[10];
		char hotentx[20];
		char soxe[10];
	public:	
		virtual void nhap(){
			fflush(stdin);
			cout<<"\nNhap ma so chuyen xe: ";
			cin.getline(masoxe, 10);
			cout<<"\nNhap ten tai xe: ";
			cin.getline(hotentx, 20);
			cout<<"\nNhap so xe: ";
			cin.getline(soxe, 10);
		};
		virtual void xuat(){
			cout<<"\nMa so chuyen xe: "<<masoxe;
			cout<<"\nHo ten tai xe: "<<hotentx;
			cout<<"\nSo xe: "<<soxe;
		}
		virtual float Doanhthu() =0;
		virtual int MA() =0;
		friend void menunt();
		friend void menungt();
};
class cx_noithanh:public quanlyxe{
		private: 
			int sotuyen;
			int sokmdi;
			float doanhthu1;
		public:
			void nhap(){
				quanlyxe::nhap();
				fflush(stdin);
				cout<<"\nNhap so  tuyen: ";
				cin>>sotuyen;
				cout<<"\nNhap so km ddi duoc: ";
				cin>>sokmdi;
				cout<<"\nNhap doanh thu: ";
				cin>>doanhthu1;
			}
			void xuat(){
				quanlyxe::xuat();
				cout<<"\nSo tuyen: "<<sotuyen;
				cout<<"\nSo km di duoc: "<<sokmdi;
				cout<<"\nDoanh thu: "<<doanhthu1;
			};
			int MA(){
				return 1;
			}
			float Doanhthu(){
				return doanhthu1;
			}			
};
class cx_ngoaithanh:public quanlyxe{
		private:
			char noiden[30];
			int songaydi;
			float doanhthu2;
		public:
			void nhap(){
				quanlyxe::nhap();
				fflush(stdin);
				cout<<"\nNhap noi di den: ";
				cin.getline(noiden, 30);
				cout<<"\nNhap so ngay di duoc: ";
				cin>>songaydi;
				cout<<"\nNhap doanh thu: ";
				cin>>doanhthu2;
			}
			void xuat(){
				quanlyxe::xuat();
				cout<<"\nNoi den: "<<noiden;
				cout<<"\nSo ngay di duoc: "<<songaydi;
				cout<<"\nDoanh thu: "<<doanhthu2;
			}
			float Doanhthu(){
				return doanhthu2;
			}
			int MA(){
				return 2;
			}	
};
void menunt(quanlyxe *a[], int n){
	int chon1;
	int i;
	do
	{
		system("cls");
		cout<<"\nQUAN LY XE NOI THANH";
		cout<<"\n1.Nhap.";
		cout<<"\n2.Xuat.";
		cout<<"\n3.Tien";
		cout<<"\n99.thoat";
		cout<<"\nChon: "; cin>>chon1;
		switch(chon1)
		{
			case 1: 
			{
				system("cls");
			  	cout<<"\nNhap so luong chuyen xe: ";
			  	cin>>n;
	 	 		for(i=0;i<n;i++)
			  	{
					cout<<"\nSTT "<<i+1;
  					a[i]->nhap();
  				}
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
				cout<<"\n\t\t-----Danh sach chuyen xe------";
				for(i=0;i<n;i++){
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
				} 
				system("pause>pls");
			}
			break;
			case 3: 
			{
				system("cls");
				float tong1;
				tong1 = 0;
				for(int i=0;i<n;i++)
					{
					if(a[i]->MA() == 1)
						{
								tong1 += a[i]->Doanhthu();
						}
					}
				cout<<"\nTong doanh thu cua xe noi thanh: "<<tong1;
				system("pause>pls");
			}
			break;
			default: 
				break;
		}
	}while(chon1!=99);
};
void menungt(quanlyxe * a[], int n)
{
	int chon2;
	int i;
	do
	{
		system("cls");
		cout<<"\nQUAN LY XE NGOAI THANH";
		cout<<"\n1.Nhap.";
		cout<<"\n2.Xuat.";
		cout<<"\n3.Tien";
		cout<<"\n99.thoat";
		cout<<"\nChon: "; cin>>chon2;
		switch(chon2)
		{
			case 1: 
			{
				system("cls");
			  	cout<<"\nNhap so luong chuyen xe: ";
			  	cin>>n;
	 	 		for(i=0;i<n;i++)
			  	{
					cout<<"\nSTT "<<i+1;
  					a[i]->nhap();
  				}
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
				cout<<"\n\t\t-----Danh sach chuyen xe------";
				for(i=0;i<n;i++){
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
				} 
				system("pause>pls");
			}
			break;
			case 3: 
			{
				system("cls");
				float tong2;
				tong2 = 0;
				for(int i=0;i<n;i++)
					{
					if(a[i]->MA() == 2)
						{
								tong2 += a[i]->Doanhthu();
						}
					}
				cout<<"\nTong doanh thu cua xe ngoai thanh: "<<tong2;
				system("pause>pls");
			}
			break;
			default: 
				break;
		}
	}while(chon2!=99);
};
int main(){
	quanlyxe *a[100];
	int chon, i;
	do{
		system("cls");
		cout<<"\n\t\t\t-----MENU-----";
		cout<<"\n\t\t1.Xe noi thanh.";
		cout<<"\n\t\t2.Xe ngoai thanh.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLUA CHON: "; cin>>chon;
		switch(chon)
		{
			case 1:
			{
			  system("cls");
			  for(i=0;i<100;i++)
			  	{
				  	a[i] = new cx_noithanh();
  				}
				menunt(a,100);
				system("pause");	
			}
			break;
			case 2:
			{
				system("cls");
	 	 		for(i=0;i<100;i++)
		  		{
  					a[i] = new cx_ngoaithanh();
  				}
				menungt(a,100);
				system("pause");
			}
			break;
			
		default:
			break;	
		}
	}while(chon!=99);
	return 0;
}