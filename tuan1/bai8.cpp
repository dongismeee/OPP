#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
struct NGAY{
	int ngay,thang,nam;
};
class KH{
	private:
 		char ht[30], cmt[10], k[50];
		NGAY ns;	
	public:
		//khoi tao khong tham so
		KH(){
			strcpy(ht," ");
			strcpy(cmt," ");
			strcpy(k," ");
			ns.ngay=0;
			ns.thang=0;
			ns.nam=0;
			}
		//khoi tao co tham so 	
	 	KH(char *hoten,int ng,int th,int n,char *scmt,char *hokhau)
			{
			strcpy(ht,hoten);
			ns.ngay =ng;
			ns.thang =th;
			ns.nam =n;
			strcpy(cmt,scmt);
			strcpy(k,hokhau);
			}
			~KH(){};
			void nhap();
			void in();
};
void KH::nhap(){
	cout<<"\nNhap ho ten khach hang:";
	cin.getline(ht,30);
	fflush(stdin);
	cout<<"\nNhap ngay sinh(ngaythangnam):";
	cout<<"\nNgay sinh:";cin>>ns.ngay;
	cout<<"Thang sinh:";cin>>ns.thang;
	cout<<"Nam sinh:";cin>>ns.nam;
	fflush(stdin);
	cout<<"\nNhap so chung minh nhan dan:";
	cin.getline(cmt,10);
	fflush(stdin);
	cout<<"\nNhap ho khau cua minh:";
	cin.getline(k,50);
}
void KH::in(){
	cout<<"Ho va ten"<<setw(15)<<"Ngay sinh"<<setw(20)<<"Chung minh thu"<<setw(15)<<"Ho khau"<<endl;
	cout<<ht<<setw(5)<<ns.ngay<<"/"<<ns.thang<<"/"<<ns.nam<<setw(15)<<cmt<<setw(20)<<k<<endl;
}
int main(){
	KH kh1;
	cout<<"\n------------Nhap thong tin cua khach hang----------";
	fflush(stdin);
	kh1.nhap();
	cout<<"\n-------------Thong tin cua khach hang--------------"<<endl;
	kh1.in();
	return 0;
}

