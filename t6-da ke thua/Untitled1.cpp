#include <iostream>
using namespace std;
class ql {
	protected: 
		int masochuyen;
		char hotentx[30];
		int soxe;
	public: 
		virtual void nhap(){
			fflush(stdin);
			cout<<"\nNhap thong tin ma so chuyen xe: ";
			cin>>masochuyen;
			fflush(stdin);
			cout<<"\nNhap ho ten tai xe: ";
			cin.getline(hotentx, 30);
			cout<<"\nNhap so xe: ";
			cin>>soxe;
		};
		virtual void xuat(){
			cout<<"\nMa so chuyen: "<<masochuyen;
			cout<<"\nHo ten tai xe: "<<hotentx;
			cout<<"\nSo xe: "<<soxe;
		};
		friend void menunt();
		friend void menungt();
		virtual float tongdoanhthu() =0;
		virtual int ma() =0;	
};
class cxnoithanh:public ql {
	private: 
		int sotuyen;
		int sokm;
		float doanhthu;
	public: 
		void nhap(){
			ql::nhap();
			cout<<"\nNhap so tuyen: ";
			cin>>sotuyen;
			cout<<"\nNhap so km di duoc: ";
			cin>>sokm;
			cout<<"\nNhap doanh thu: ";
			cin>>doanhthu;
		};
		void xuat(){
			ql::xuat();
			cout<<"\nSo tuyen: "<<sotuyen;
			cout<<"\nSo km: "<<sokm;
			cout<<"\nDoanh thu: "<<doanhthu;
		};
		float tongdoanhthu(){
			return doanhthu;
		};	
		int ma(){
			return 1;
		};
};
class cxngoaithanh:public ql{
	private: 
		char noiden[20];
		int songaydi;
		float doanhthu2;
	public:
		void nhap(){
			ql::nhap();
			fflush(stdin);
			cout<<"\nNhap noi den: ";
			cin.getline(noiden, 20);
			cout<<"\nNhap so ngay da di: ";
			cin>>songaydi;
			cout<<"\nNhap doanh thu: ";
			cin>>doanhthu2;
		};
		void xuat(){
			ql::xuat();
			cout<<"\nNoi den: "<<noiden;
			cout<<"\nSo ngay da di: "<<songaydi;
			cout<<"\nDoanh thu: "<<doanhthu2;
		};
		float tongdoanhthu(){
			return doanhthu2;
		};
		int ma(){
			return 2;
		};
};
void menunt(ql * a[], int n){
	int chon, i;
	do{
		system("cls");
		cout<<"\n\t\tchuyen xe noi thanh";
		cout<<"\n1.Nhap thong tin.";
		cout<<"\n2.xuat thong tin.";
		cout<<"\n3.tong doanh thu.";
		cout<<"\n99. thoat!";
		cout<<"\nNhap su lua chon: ";
		cin>>chon;
		switch(chon){
			case 1:
			{
				system("cls");
				cout<<"\nNhap so chuyen xe: ";
				cin>>n;
				for(i=0;i<n;i++){
					cout<<"\nSTT : "<<i+1;
					a[i]->nhap();
				}
				system("pause");
			}
			break;
			case 2:
			{
				system("cls");
				for(i=0;i<n;i++){
					cout<<"\n chuyen xe thu : "<<i+1;
					a[i]->xuat();
				}
				system("pause");
			}
			break;
			case 3:
			{
				system("cls");
				float t =0;
				for(i=0;i<n;i++){
					if(a[i]->ma() ==1 ){
					 	t = t + a[i]->tongdoanhthu();
					}
				}
				cout<<"\nTong doanh thu xe noi thanh: "<<t;
				system("pause");
			}
			break;
		default:
		 		break;	
		}
	}while(chon!=99);
};
void menungt(ql * a[], int n){
	int chon, i;
	do{
		system("cls");
		cout<<"\n\t\tchuyen xe ngoai thanh";
		cout<<"\n1.Nhap thong tin.";
		cout<<"\n2.xuat thong tin.";
		cout<<"\n3.tong doanh thu.";
		cout<<"\n99. thoat!";
		cout<<"\nNhap su lua chon: ";
		cin>>chon;
		switch(chon){
			case 1:
			{
				system("cls");
				cout<<"\nNhap so chuyen xe: ";
				cin>>n;
				for(i=0;i<n;i++){
					cout<<"\nSTT : "<<i+1;
					a[i]->nhap();
				}
				system("pause");
			}
			break;
			case 2: 
			{
				system("cls");
				for(i=0;i<n;i++){
					cout<<"\n chuyen xe thu : "<<i+1;
					a[i]->xuat();
				}
				system("pause");
			}
			break;
			case 3:
			{
				system("cls");
				float t =0;
				for(i=0;i<n;i++){
					if(a[i]->ma() == 2 ){
					 	t = t + a[i]->tongdoanhthu();
					}
				}
				cout<<"\nTong doanh thu xe ngoai thanh: "<<t;
				system("pause");
			}
			break;
		default:
		 		break;	
		}
	}while(chon!=99);
};
int main(){
	ql * d[100];
	int chon ,i ;
	do{
		cout<<"\n\t\tMenu";
		cout<<"\n1.chuyen xe noi thanh.";
		cout<<"\n2.chuyen xe ngoai thanh.";
		cout<<"\n3.thoat!";
		cout<<"\nLua chon: ";
		cin>>chon;
		switch(chon){
			case 1:
			{
				system("cls");
				for(i=0;i<100;i++){
					d[i] = new cxnoithanh();
				}
				menunt(d,100);
				system("pause");
			}
			break;
			case 2:
			{
				system("cls");
				for(i=0;i<100;i++){
					d[i]= new cxngoaithanh();
				}
				menungt(d,100);
				system("pause");
			}
			break;
		default:
			break;	
		}
	}
	while(chon!=99);
	return 0;
}