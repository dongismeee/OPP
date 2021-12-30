#include <iostream>
#include <string>
using namespace std;
class mydate{
	protected:
		int d, m, y;
	public:
	int gety(){
		return y;
	}
		mydate()
		{
			d=0; y=0; m=0;
		};
		mydate( int d, int m, int y){
			this->d=d;
			this->m=m;
			this->y=y;
		};
		~mydate(){};
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ngay: ";
			do{
				cin>>d;
			}while( d < 1 || d > 31);
			cout<<"\nNhap thang: ";
			do{
				cin>>m;
			}while( d < 1 || d > 12);
			cout<<"\nNhap nam: ";
			do{
				cin>>y;
			}while( d < 1900 || d > 2021);
		};
		void xuat(){
			cout<<"\nNgay sinh:"<<d<<" / "<<m<<" / "<<y;
		};	
};
class nguoi:public mydate
{
	private: 
		string name;
		string address;
		string phone;
	public:
		nguoi(){
			name=" ";
			address=" ";
			phone=" ";
		};
		nguoi(string name, string address, string phone){
			this->name=name;
			this->address=address;
			this->phone=phone;
		};
		~nguoi(){};
		void nhap(){
			mydate::nhap();
			fflush(stdin);
			cout<<"\nNhap ten: ";
			cin>>name;
			cout<<"\nNhap dia chi: ";
			cin>>address;
			cout<<"\nNhap so dien thoai: ";
			cin>>phone;
		};
		void xuat(){
			mydate::xuat();
			cout<<"\nName: "<<name;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone: "<<phone;
		};		
};
int main()
{
	nguoi *a;
	int n, i;
	cout<<"\nNhap so nguoi muon dien thong tin: ";
	cin>>n;
	a= new nguoi[n];
	for(i=0;i<n;i++){
		cout<<"\nNhap thong tin nguoi thu "<<i+1;
		a[i].nhap();
		cout<<"____________________________";
	}
	cout<<"\nDanh sach thong tin ve nguoi"<<endl;
	for(i=0;i<n;i++){
		a[i].xuat();
	}
	//sap xep ds theo chieu giam dan cua nam sinh
	for(i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].gety() < a[j].gety()){
				nguoi tg;
				tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
	}
	cout<<"\nDanh sach sau khi sap xep"<<endl;
	for(i=0;i<n;i++){
		a[i].xuat();
	}
	cout<<endl;
	return 0;
}