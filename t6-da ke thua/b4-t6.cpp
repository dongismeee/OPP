#include <iostream>
#include <math.h>
using namespace std;
class shape{
	public:
		virtual void nhap() =0;
		virtual void xuat() =0;

};//end shape
class bachieu:public shape{
	public:
		virtual float thetich() = 0;
		friend void menubc();
};
class hinhcau:public bachieu{
	private:
		float R;
	public:
		hinhcau(){
			R=0;
		};
		void nhap(){
			bachieu::nhap();
			fflush(stdin);
			cout<<"\nNhap ban kinh hinh tron: ";
			cin>>R;
		};
		void xuat(){
			bachieu::xuat();
			cout<<"\nBan kinh: "<<R;
			cout<<"\nThe tich hinh cau: "<<thetich();
		};
		float thetich(){
			return (3/4)*3.14*R*R*R;
		};	
};
class lapphuong:public bachieu{
	private:
	 float a, b, h;
	 public:
	 	lapphuong(){
	 		a=0;
	 		b=0;
	 		h=0;
	 	};
	 	void nhap(){
	 		bachieu::nhap();
			cout<<"\nNhap chieu rong lp: ";
			cin>>a;
			cout<<"\nNhap chieu dai lp: ";
			cin>>b;
			cout<<"\nNhap chieu cao lp: ";
			cin>>h;
		};
		void xuat(){
			bachieu::xuat();
			cout<<"\nChieu rong: "<<a;
			cout<<"\nChieu dai; "<<b;
			cout<<"\nChieu cao: "<<h;
			cout<<"\nThe tich hinh hcn: "<<thetich();
		};
		float thetich(){
			return a*b*h;
		};
};
class Haichieu:public shape {
	public:
		virtual float chuvi()= 0;
		virtual float dientich() = 0;
		friend void menuhc();
};
class Round:public Haichieu {
	private:
		float r;
	public:
		Round(){
			r=0;
		};
		void nhap(){
			Haichieu::nhap();
			fflush(stdin);
			cout<<"\nNhap ban kinh hinh tron: ";
			cin>>r;
		};
		void xuat(){
			Haichieu::xuat();
			cout<<"\nBan kinh: "<<r;
			cout<<"\nChu vi hinh tron: "<<chuvi();
			cout<<"\nDien tich hinh tron: "<<dientich();
		};
		float chuvi(){
			return 2*3.14*r;
		};
		float dientich(){
			return 3.14*r*r;	
		};			
};
class rec:public Haichieu {
	private:
		float a;
		float b;
	public:
		rec(){
			a=0;
			b=0;
		};
		void nhap(){
			Haichieu::nhap();
			cout<<"\nNhap chieu rong hcn: ";
			cin>>a;
			cout<<"\nNhap chieu dai hcn: ";
			cin>>b;
		};
		void xuat(){
			Haichieu::xuat();
			cout<<"\nChieu rong: "<<a;
			cout<<"\nChieu dai; "<<b;
			cout<<"\nChu vi hinh hcn: "<<chuvi();
			cout<<"\nDien tich hinh hcn: "<<dientich();
		};
		float chuvi(){
			return 2*(a+b);
		};
		float dientich(){
			return a*b;	
		};			
};
class tri:public Haichieu {
	private:
		float x, y, z;
	public:
		tri(){
			x=0;
			y=0;
			z=0;
		};
		void nhap(){
			Haichieu::nhap();
			cout<<"\nNhap canh thu 1 cua tam giac: ";
			cin>>x;
			cout<<"\nNhap canh thu 2 cua tam giac: ";
			cin>>y;
			cout<<"\nNhap canh thu 3 cua tam giac: ";
			cin>>z;
		};
		void xuat(){
			Haichieu::xuat();
			cout<<"\nCanh thu 1: "<<x;
			cout<<"\nCanh thu 2: "<<y;
			cout<<"\nCanh thu 3: "<<z;
			cout<<"\nChu vi hinh tam giac: "<<chuvi();
			cout<<"\nDien tich hinh tam giac: "<<dientich();
		};
		float chuvi(){
			return x+y+z;
		};
		float ncv(){
			return chuvi()/2;
		};
		float dientich(){
			return sqrt((ncv())*(ncv()*x)*(ncv()*y)*(ncv()*z));	
		};			
};
void menuhc(Haichieu *a[],int n){
	int chon, i;
	do
	{
		system("cls");
		cout<<"\n\t\t-------Haichieu---------";
		cout<<"\n\t\t1.Nhap.";
		cout<<"\n\t\t2.Xuat.";
		cout<<"\n\t\t3.Tong chu vi.";
		cout<<"\n\t\t4.Tong dien tich.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon;
			switch(chon)
			{
				case 1:
				{
					system("cls");
					cout<<"\nSo hinh hai chieu: ";
					cin>>n;
					for(i=0;i<n;i++)
					{
					cout<<"\nSTT "<<i+1;
					a[i]->nhap();
					}
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");
					cout<<"\n-------danh sach hinh 2 chieu------";
					for(i=0;i<n;i++)
					{
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
					}
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");
					float sum1=0;
					for(int i=0;i<n;i++){
					sum1 += a[i]->chuvi();
					};
					cout<<"\nTong chu vi cua cac hinh la: "<<sum1<<endl;
					system("pause");
				}
				break;
				case 4:
				{
					system("cls");
					float sum2=0;
					for(int i=0;i<n;i++){
					sum2 += a[i]->dientich();
					}
					cout<<"\nTong dien tich cac hinh la: "<<sum2<<endl;
					system("pause");
				}
				break;
			default:
				break;	
			}
	}while(chon!=99);
};
void menubc(bachieu *a[],int n){
	int chon, i;
	do
	{
		system("cls");
		cout<<"\n\t\t-------Bachieu---------";
		cout<<"\n\t\t1.Nhap.";
		cout<<"\n\t\t2.Xuat.";
		cout<<"\n\t\t3.Tong the tich.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon;
			switch(chon)
			{
				case 1:
				{
					system("cls");
					cout<<"\nSo hinh ba chieu: ";
					cin>>n;
					cin.ignore();
					for(i=0;i<n;i++)
					{
					cout<<"\nSTT "<<i+1;
					a[i]->nhap();
					}
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");
					cout<<"\n-------danh sach hinh 3 chieu------";
					for(i=0;i<n;i++)
					{
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
					}
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");
					float sum3=0;
					for(int i=0;i<n;i++){
						sum3 += a[i]->thetich();
						}
					cout<<"\nTong the tich cac hinh la: "<<sum3<<endl;
					system("pause");
				}
				break;
			default:
				break;	
			}
	}while(chon!=99);
}
int main(){
	Haichieu *a[100];
	bachieu *b[100];
	int i, chon1;
	do{
		system("cls");
		cout<<"\n\t\t-------MENU---------";
		cout<<"\n\t\t1.HAI CHIEU.";
		cout<<"\n\t\t2.BA CHIEU.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon1;
			switch(chon1)
			{
				case 1:
				{
					system("cls");
					menuhc(a,100);
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");
					menubc(b,100);
					system("pause");
				}
				break;
			default:
				break;	
			}
	}while(chon1!=99);
	cout<<endl;
	return 0;
} 
