#include<iostream>
#include<iomanip>
using namespace std;
class GV{
	private:
		char ht[30];
		int tuoi;
		char bc[15];
		char cn[15];
		float bl;
	public:
		GV();
		void nhap();
		void in();
		float tinhtl();	
};
GV::GV(){
	ht[30]=' ';
	bc[15]=' ';
	cn[15]=' ';
	tuoi=0;
	bl=0;
}
void GV::nhap(){
	fflush(stdin);
	cout<<"\n--Nhap ho ten cua giao vien:";
	cin.getline(ht,30);
	cout<<"\n--Nhap vao tuoi:";
	cin>>tuoi;
	fflush(stdin);
	cout<<"\n--Nhap vao bang cap:";
	cin.getline(bc,15);
	cout<<"\n--Nhap vao chuyen nganh:";
	cin.getline(cn,15);
	cout<<"\n--Nhap vao bac luong:";
	cin>>bl;
}
void GV::in(){
	cout<<setw(15)<<"HO TEN"<<setw(15)<<"TUOI"<<setw(15)<<"BANGCAP"<<setw(15)<<"CHUYENNGANH"<<setw(15)<<"BAC LUONG"<<setw(19)<<"TIEN LUONG"<<endl;
	cout<<setw(15)<<ht<<setw(15)<<tuoi<<setw(15)<<bc<<setw(15)<<cn<<setw(10)<<bl<<setw(15)<<tinhtl()<<endl;
}
float GV::tinhtl(){
	return bl*1490;
}
int main(){
	GV gv1;
	gv1.nhap();
	cout<<"Thong tin cua giao vien nhap la:"<<endl;
    gv1.in();
	return 0;
}