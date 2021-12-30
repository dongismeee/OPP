#include <iostream>
using namespace std;
class PS{
	private: 
		 float tuso;
		 float mauso;
	public:
		PS(){
			this->tuso =0;
			this->mauso =1;
		};
		PS(float tuso, float mauso){
			this->tuso = tuso;
			this->mauso =mauso;
		};
		void nhap(){
			cout<<"\nNhap tu so: ";
			cin>>tuso;
			cout<<"\nNhap mau so: ";
			cin>>mauso;
			while(mauso==0){
				cout<<"\nNhap lai mau so: ";
				cin>>mauso;
			}
		};
		void xuat(){
			cout<<"Phan so co dang: "<<tuso<<"/"<<mauso;
		};
		bool operator > (PS &p){
		PS ps1;
 		if(ps1.tuso * this->mauso > this->mauso* ps1.mauso ){
		 	return ps1 > p;
		 }
	 
	} 		 
};

template <typename T>
T min(T *a,int n){
	T min = a[0];
	for(int i=0;i<n;i++){
		if(min > a[i])
		min = a[i];
	} 
	return min;
} 
int main(){
	PS * a;
	int n;
	cout<<"\nNhap so phan so muon nhap n=: ";
	cin>>n;
	a = new PS[n];
	for(int i=0;i<n;i++){
		cout<<"\nPhan so thu nhat: ";
		a[i].nhap();	
	};
	for(int i=0;i<n;i++){
		cout<<"\nPhan so thu: "<<i+1;
		a[i].xuat();
	};
	cout<<"\nPhan so nho nhat trong nay la: ";
	min(a,n).xuat();
	return 0;
}