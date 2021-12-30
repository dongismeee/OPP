#include<iostream.h>
#include<cstring>
using namespace std; 

class TS{
	private:
	char ht[30];
	float dToan, dVan;
	public:
	void nhap();
	void in();
	char *getHt(){
		return ht;
	}
};
void TS :: nhap(){
	fflush(stdin);
	cout<<"\nNhap vao ho ten: ";cin.getline(ht,30);
	cout<<"\nNhap vao diem toan: ";cin>>dToan;
	cout<<"\nNhap vao diem van: ";cin>>dVan;
}
void TS :: in(){
	cout<<"\nHo ten: "<<ht;
	cout<<"\nDiem toan: "<<dToan;
	cout<<"\nDiem van: "<<dVan;
}
void swap(TS &x , TS &y){
	TS tg;
	tg=x ;
	x=y;
	y=tg;
	
} 
int main(){
	TS *ts;
	int n;
	cout<<"\nNhap vao so thi sinh n= ";cin>>n;
	ts = new TS[n]; 
	for(int i=0; i<n ; i++){
		cout<<"\n\n--Thi sinh thu "<<i+1;
		ts[i].nhap();
	}
	cout<<"\n--------------In thong tin thi sinh--------------";
	for(int i=0; i<n ; i++){
		cout<<"\n\n--Thi sinh thu "<<i+1;
		ts[i].in();
	}
	//Tim kiem thi sinh
	cout<<"\n--------------Tim kiem thi sinh--------------";
	char TK[30];
	cout<<"\nNhap ho ten thi sinh can tim kiem:";
	fflush(stdin);
	cin.getline(TK,30);
	
	bool KT = false;
	for(int i = 0 ; i< n; i++){
		if(strcmp(TK, ts[i].getHt())==0){
		cout<<"\nTen thi sinh can tim la:  ";
		ts[i].in();
		KT = true; 
	}
	if(!KT){
		cout<<"\n!!Khong tim thay thi sinh nay trong danh sach!!";
		break;
	}
	}
	//Neu tim thay thi xoa khoi danh sach
	for(int i = 0 ; i< n; i++){
		if(strcmp(TK, ts[i].getHt())==0){
		for(int k = i; k< n;k++ ){
			n--;
			ts[k] = ts[k+1]; 
		}
	}
	}
	cout<<"\n--------------Danh sach thi sinh sau khi xoa --------------";
	for(int i= 0 ; i<n;i++){
		ts[i].in();
	}
	
	cout<<"\n--------------Danh sach thi sinh sau khi sap xep --------------";
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(ts[i].getHt(),ts[j].getHt())> 0){
				swap(ts[i],ts[j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		ts[i].in();
	}
	cout<<endl;
}