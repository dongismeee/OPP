#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class congnhan{
	private:
		string ht;
		int tuoi;
		string qq;
		float bl;
	public:
		congnhan();
		void nhap();
		void in();
		float tinhluong();	
};
congnhan::congnhan(){
		ht="";
		qq="";
		tuoi=0;
		bl=0;
}
void congnhan::nhap(){
	fflush(stdin);
	cout<<"\nnhap ten nhan vien:";
	getline(cin,ht);
	cout<<"\nnhap tuoi cua minh:";
	cin>>tuoi;
	fflush(stdin);
	cout<<"\nnhap que quan cua minh:";
	getline(cin,qq);
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
