#include <iostream.h> 
#include <iomanip.h>
#include <string>

class benhnhan
{
	protected:
		string hoten;
		string quequan;
		int namsinh;
	public:
		int getns()
		{
			return namsinh;
		};
		void nhap()
		{
			fflush(stdin);
			cout<<"\nNhap ho ten: ";
			getline(cin,hoten);
			cout<<"\nNhap que quan: ";
			getline(cin,quequan);
			cout<<"\nNhap nam sinh: ";
			cin>>namsinh;
		};
		void xuat()
		{
			cout<<"\nHo ten: "<<hoten;
			cout<<"\nQue quan: "<<quequan;
			cout<<"\nNam sinh: "<<namsinh;
		};	
};
class benhan:public benhnhan
{
	protected:
		string tenba;
		float tienvp;
	public:
		float gettienvp()
		{
			return tienvp;
		};
		void nhap()
		{
			benhnhan::nhap();
			fflush(stdin);
			cout<<"\nNhap ten benh an: ";
			getline(cin,tenba);
			cout<<"\nNhap tien vien phi: ";
			cin>>tienvp;
		};
		void xuat()
		{
			benhnhan::xuat();
			cout<<"\nTen benh an: "<<tenba;
			cout<<"\nTien vien phi: "<<tienvp;
			cout<<"\nTuoi: "<<tuoi();
			cout<<endl;
		}
		float tuoi()
		{
			time_t baygio = time(0);
			tm *ltm = localtime(&baygio);
			return ( 1900 +ltm->tm_year - namsinh);
		};		
};
int main()
{
	benhan a[50];
	int i,n;
	cout<<"\nNhap so benh an n= ";
	cin>>n;
	//nhap thong benh an
	for(i=0;i<n;i++)
	{
		cout<<"\n-Thong tin benh nhan thu: "<<i+1;
		a[i].nhap();
	}
	//xuat thong tin
	for(i=0;i<n;i++)
	{
		cout<<"\n-Benh nhan thu "<<i+1<<endl;
		a[i].xuat();
	}
	//sap xep danh sanh giam dan theo nam sinh
	cout<<"__________________________________________"<<endl;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(a[i].tuoi() < a[j].tuoi()){
				benhan tg;
				tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
	}
	cout<<"\nDanh sach benh nha sau khi sap xep"<<endl;
	for(i=0;i<n;i++){
		a[i].xuat();
	}
		
	//danh sach benh nhan tren 50 tuoi
	
	cout<<"\n__________________________________________";
	cout<<"\nDanh sach benh nhan tren 50";
	bool kt =false;
	for(i=0;i<n;i++)
	{
		if(a[i].tuoi()>50)
			a[i].xuat();
			kt =true;
	}
	if(!kt)
	{
		cout<<"\nDanh sach ko co ai tren 50 tuoi!"<<endl;
	}
	//hien thi thong tin benh nha nco tien vien phi cao nhat
	cout<<"\n__________________________________________";
	cout<<"\nthong tin nguoi co vien phi cao nhat";
	float maxt;
	int chiso = 0;
	maxt = a[0].gettienvp();
		for(int i = 1; i <= n; i++)
		{
			if( maxt < a[i].gettienvp())
			{
				maxt = a[i].gettienvp();
				chiso = i;
			}
		}
			a[chiso].xuat();
	
	cout<<endl;	
	return 0;		
}