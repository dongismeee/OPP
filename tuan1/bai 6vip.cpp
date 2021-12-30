#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class congnhan{
	private:
		char ht[50];
		int tuoi;
		char qq[50];
		float bl;
	public:
		congnhan();
		void nhap();
		void in();
		float tinhluong();	
};
congnhan::congnhan(){
		ht[50]=' ';
		qq[50]=' ';
		tuoi=0;
		bl=0;
}
void congnhan::nhap(){
	fflush(stdin);
	cout<<"\nnhap ten nhan vien:";
	cin.getline(ht,50);
	cout<<"\nnhap tuoi cua minh:";
	cin>>tuoi;
	fflush(stdin);
	cout<<"\nnhap que quan cua minh:";
	cin.getline(qq,50);
	cout<<"\nnhap bac luong:";
	cin>>bl;
	
}
void congnhan::in(){
	cout<<"\nHo ten:"<<ht;
	cout<<"\nTuoi:"<<tuoi;
	cout<<"\nQue quan:"<<qq;
	cout<<"\nBac luong:"<<bl;
	tinhluong();
	cout<<"\nluong:"<<tinhluong();
}
float congnhan::tinhluong(){
	return bl*3125;
	   
}
int main(){
	congnhan  cn1 ,cn2;
	cn1.nhap();
	cn2.nhap(); 
	cn1.in();
	cn2.in(); 
}
