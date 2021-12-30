#include<iostream.h>
#include<iomanip.h>
#include<math.h>
#include<string.h>
using namespace std;
struct SV
{
	int sobd;
	char ht[30];
	float t,l,h,td;
};
class SVien
{
	private:
	SV *sv;
	int sosv;
	public:
	void nhap();
	void in();
	void intrungtuyen();
	void inthukhoa();

	SVien()
	{
		sv=NULL;;
		sosv=0;
	}
	SVien(int n)
	{
		sv = new SV[n+1];
		sosv=n;
	}
	~SVien()
	{
		if (sosv)
		{
			sosv=0;
			sv=NULL;
		}
	}
};
	
void SVien::nhap()
{
	if(sosv)
		for(int i =0; i<sosv;i++)
		{
			cout<<"Sinh vien "<<i+1<<":";
			cout<<"\nSo bao danh: ";
			cin>>sv[i].sobd;
			cin.ignore();
			cout<<"\nHo ten: ";
			cin.get(sv[i].ht,30);
			cout<<"\nDiem toan, ly, hoa: "<<endl;
			cin>>sv[i].t>>sv[i].l>>sv[i].h;
			sv[i].td=sv[i].t+sv[i].l+sv[i].h;
	}
}
void SVien::in()
{
	if(sosv)
	{
		cout<<"HOTEN"<<setw(15)<<"SOBAODANH"<<setw(15)<<"TONG DIEM"<<endl;
		for(int i = 0; i<sosv;i++)
        cout<<sv[i].ht<<setw(15)<<sv[i].sobd<<setw(15)<<sv[i].td<<endl;
		cout<<"--------------------*_*_*_*_*-----------------"<<endl;
	}
}
void SVien::intrungtuyen()
{
	    cout<<"HOTEN"<<setw(15)<<"SOBAODANH"<<setw(15)<<"TONG DIEM"<<endl;
	for(int i = 0; i<sosv;i++)
	{
		if(sv[i].td>=20)
		cout<<sv[i].ht<<setw(15)<<sv[i].sobd<<setw(15)<<sv[i].td<<endl;
	}
}
void SVien::inthukhoa()
{
	float Maxtd;
	Maxtd = sv[0].td;
	int chiso = 0;
	cout<<"HOTEN"<<setw(15)<<"SOBAODANH"<<setw(15)<<"TONG DIEM"<<endl;
	for(int i = 1; i<sosv;i++)
		if(Maxtd<sv[i].td)
		{ 
			Maxtd = sv[i].td;
			chiso = i;
		}
	cout<<sv[chiso].ht<<setw(15)<<sv[chiso].sobd<<setw(15)<<sv[chiso].td<<endl;
}
int main()
{
	SVien *S ;
	int n;
	cout<<"Nhap so sinh vien n: ";
	cin>>n;
	S= new SVien(n);
	S->nhap();
    cout<<"------Danh sach sinh vien da nhap-------"<<endl;
	S->in();
	cout<<"---Danh sach sinh vien trung tuyen la---"<<endl;
	S->intrungtuyen();
	cout<<"------------------*_*_*_*_*-----------------"<<endl;
	cout<<"Thong tin sinh vien do thu khoa là: "<<endl;
	S->inthukhoa();
	cout<<"------------------*_*_*_*_*-----------------"<<endl;
	delete S;
	cout<<endl;
	return 0;
}