#include <iostream>
using namespace std;
template <class T>
void nhap( T a[], int n){
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
};
template <class T>
void xuat(T a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i];
		cout<<"\t";
	}
};
template<typename T>
T tong(T * a, int soPhanTu){
	T tong = 0;
	for(int i=0;i < soPhanTu;i++){
		tong += a[i];
	}
	return tong;
}
int main(){
	int a[30] ,n;
	cout<<"\nNhap so phan tu n= ";
	cin>>n;
	nhap(a,n);
	xuat(a,n);
	cout<<"\nTong cua cac phan tu trong mang: "<<tong(a,n)<<endl;
	
	float b[20];
	nhap(b,n);
	xuat(b,n);
	cout<<"\nTong cua cac phan tu trong mang: "<<tong(b,n)<<endl;
	return 0;
}