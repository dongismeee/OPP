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
 			if(ps1.tuso * this->mauso > this->tuso* ps1.mauso )
			 	{
		 		return ps1 > p;
		 		}
		};
		bool operator < (PS &p){
			PS ps1;
			if(ps1.tuso * this->mauso < this->tuso * ps1.mauso)
			{
				return ps1 < p;
			}
		};
		bool operator == (PS &p){
			PS ps1;
			if(this->tuso *ps1.mauso == ps1.tuso * this->mauso){
				return ps1 == p;
			}
		}
		PS operator + (PS &p){
		    PS t;
			t.tuso = (this->tuso * p.mauso) + (p.tuso * this->mauso);
			t.mauso =(this->mauso * p.mauso);
			return t;
		};
				 
};
template<class T>
T min(T *a,int n){
	T min = a[0];
	for(int i=0;i<n;i++){
		if(min > a[i])
		  min = a[i];
	} 
	return min;
}
template<class T>
T max(T * a, int n){
	T max = a[0];
	for(int i=0;i<n;i++){
		if (max < a[i])
			max =a[i];
	}
	 return max;
}
template <class T>
T tong(T * a,int n){
	T tong = a[0];
	for(int i=0;i<n;i++){
		tong = tong + a[i];
	}
	return tong;
}
template <class T>
T swap(T * a, int n){
	T t;
	for( int i;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] >a[j])
			 	t=a[i];
			 	a[i]= a[j];
			 	a[j]= t;
		}
	}
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
template <class T>
T tim(T * a, int n, T &t){
	bool kt ;
	kt = false;
	for(int i=0;i<n;i++){
		if(a[i] == t){
			kt =true;
			cout<<"\nDa tim thay!";
		}
	}
	if(!kt)
	{
		cout<<"\nKhong tim thay!";
	}
}
template <class T>
T demkhac(T * a, int n, T &t){
	int dem = 0;
	for(int i=0;i<n;i++){
		if(a[i] == t){
			dem ++;
		}
	}
	cout<< n-dem;
}
template <class T>
T them( T *a, int n, int pos, T &t){
	for(int i= n-1;i>pos;i--){
		a[i]=a[i-1];
	}
	n++;
	a[pos]=t;
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
template<class T>
T xoa( T *a, int n, int pos){
	for(int i= pos;i < n-1;i++){
		a[i]=a[i+1];
	}
	n--;
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
int main(){
	PS * a;
	int n; 
	cout<<"\nNhap so luong phan so n=: ";
	cin>>n;
	a = new PS[n];
	for(int i=0;i<n;i++){
		cout<<"nPhan so thu: "<<i+1;
		a[i].nhap();
	}
	for(int i=0;i<n;i++){
		cout<<"\nPhan so thu: "<<i+1;
		a[i].xuat();
	}
	cout<<endl;
	cout<<"\nPhan so co gia tri lon nhat: ";
	max(a,n).xuat();
	cout<<"\nPhan so co gia tri nho nhat: ";
	min(a,n).xuat();
	cout<<"\nTong cac phan so la: ";
	tong(a,n).xuat();
	cout<<"\nDanh sach sap xep cac phan so theo chieu tang dan: ";
	swap(a,n);
	cout<<"\n_____________________________________________________"<<endl;
	
	PS x;
	cout<<"\nDem phan tu khac mot gia tri cho truoc";
	cout<<"\nNhap PS can";
	x.nhap();
	cout<<"\nSo phan tu khac PS da nhap la: "; demkhac(a,n,x);
	
	PS y;
	cout<<"\nTim phan tu khac mot gia tri cho truoc";
	cout<<"\nNhap PS can = "; 
	y.nhap();
	cout<<"\nPhan tu giong PS da nhap o vi tri thu: "; tim(a,n,y);
	
	int k;
	cout<<"\nXoa phan tu tu vi tri k cho truoc";
	cout<<"\nNhap vi tri k = ";
	cin>>k;
	cout<<"\nDanh sach sau khi xoa: ";
	xoa(a,n,k);
	
	int c;
	PS z;
	cout<<"\n________Them phan tu tu vi tri k cho truoc";
	cout<<"\nNhap vi tri k = ";
	cin>>c;
	cout<<"\nNhap PS can them: ";
	z.nhap();
	cout<<"\nDanh sach sau khi them: ";
	them(a,n,c,z);
	
	return 0;
}

