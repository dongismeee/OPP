#include <iostream> 
#include <vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class internet{
	public:
		virtual void nhap(){
			fflush(stdin);
			cout<<"\nNhap ho ten khach hang: ";
			cin.getline(hoten, 30);
		};
		virtual void xuat(){
			cout<<"\nHoten khach hang: "<<hoten;
			cout<<"\nTien thue bao: "<<tientb()<<" VND"<<endl;
		};
		virtual float tientb() =0;
		friend float Tientungloai();
	protected:
		char hoten[30];	
};
class dialup:public internet {
	private:
		int thoigianthue;
		int hinhthucthue;
	public:
		void nhap(){
			internet::nhap();
			fflush(stdin);
			cout<<"\n\t\t---Hinh thuc thue---(chon)";
			cout<<"\n1.Thue thang  2.Thue dl dulieu : ";
			cin>>hinhthucthue;
			cout<<"\nThoi gian thue: ";
			cin>>thoigianthue;
		};
		void xuat(){
			internet::xuat();
			cout<<"\nHinh thuc thue: "<<hinhthucthue;
			cout<<"\nThoi gian thue: "<<thoigianthue;
		};
		float tientb(){
			if(hinhthucthue == 1)
				return 30000*thoigianthue;
			else if(hinhthucthue == 2)
				return 30*thoigianthue;	
		};
};
class adsl:public internet {
	private:
		int thoigianthue;
		int hinhthucthue;
	public:
		void nhap(){
			internet::nhap();
			fflush(stdin);
			cout<<"\nHinh thuc thue--->chon";
			cout<<"\n1.Thue thang  2.Thue dl dulieu : ";
			cin>>hinhthucthue;
			cout<<"\nThoi gian thue: ";
			cin>>thoigianthue;
		};
		void xuat(){
			internet::xuat();
			cout<<"\nHinh thuc thue: "<<hinhthucthue;
			cout<<"\nThoi gian thue: "<<thoigianthue;
		};
		float tientb(){
			if(hinhthucthue == 1)
				return 50000*thoigianthue;
			else if(hinhthucthue == 2)
				return 50*thoigianthue;	
		};
			
		
};
class t1:public internet {
	private:
		int thoigianthue;
	public:
		void nhap(){
			internet::nhap();
			fflush(stdin);
			cout<<"\nThoi gian thue: ";
			cin>>thoigianthue;
		};
		void xuat(){
			internet::xuat();
			cout<<"\nThoi gian thue: "<<thoigianthue;
		};
		float tientb(){
				return 2000000*thoigianthue;
		};	
		
};
class quanly {
	public:
		internet * kh[30];
		int n;
		void nhapds();
		void xuatds();
		float tongphi();
};
void quanly::nhapds()		
			{	
			int luachon, i=0;
			float s=0;
			do{
				system("cls");
				cout<<"\n\t\t\t*******INTERNET*********";
				cout<<"\n\t\t\t1.DIAl UP.";
				cout<<"\n\t\t\t2.ADSL.";
				cout<<"\n\t\t\t3.T1.";
				cout<<"\n\t\t\t4.Thoat.";
				cout<<"\n\t\t\t Lua chon!: ";
				cin>>luachon;
				switch(luachon)
				{
					case 1:
					{
						kh[i]= new dialup();
						kh[i]->nhap();
						s += kh[i]->tientb();
						i++;
						n=i;
						cout<<"\nTong tien thue bao cua dialup: "<<s;
						system("pause>pls");	
					}
					break;
					case 2:
					{
						kh[i]= new adsl();
						kh[i]->nhap();
						s += kh[i]->tientb();
						i++;
						n=i;
						cout<<"\nTong tien thue bao cua adsl: "<<s;
						system("pause>pls");
					}
					break;
					case 3:
					{
						kh[i]= new t1();
						kh[i]->nhap();
						s += kh[i]->tientb();
						i++;
						n=i;
						cout<<"\nTong tien thue bao cua t1: "<<s;
						system("pause>pls");
					}
					break;
				default:
					break;	
				}
			}while(luachon!=4);
		}; //void nhap;
void quanly::xuatds()
{
			cout<<"\n\t\t\t****Danh Sach Khach hang thue*********";
			for(int i=0;i<n;i++)
			{
			kh[i]->xuat();
			cout<<"\n***********************************";
			}
};
float quanly::tongphi(){
			float tong;
			tong =0 ;
			for(int i =0;i<n;i++){
				tong += kh[i]->tientb();
			};
			return tong;
		};		
int menu(quanly	 ql){
	int chon;
	do{
				system("cls");
				cout<<"\n\t\t\t*******Quan ly*********";
				cout<<"\n\t\t\t1.Nhap danh sach.";
				cout<<"\n\t\t\t2.Xuat danh Sach.";
				cout<<"\n\t\t\t3.Tong tien thue."; 
				cout<<"\n\t\t\t4.Thoat.";
				cout<<"\n\t\t\t Lua chon!: ";
				cin>>chon;
				switch(chon)
				{
					case 1:
					{
						ql.nhapds();
						system("pause>pls");
					}
					break;
					case 2:
					{
						system("cls");
						ql.xuatds();
						system("pause>pls");
					}
					break;
					case 3:
					{
						system("cls");
						cout<<"\n\tTong tien thu duoc: ";
						cout<<"\nTong: "<<ql.tongphi();
						system("pause>pls");
					}
					break;
				default:
					break;	
				}					//end switch
	}while(chon!=4);				//end do
};  	//end menu
int main()
{
	quanly ql;
	menu(ql);
	system("pause");
	return 0;
}					