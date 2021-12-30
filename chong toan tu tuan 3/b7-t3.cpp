#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class OTO
{
	private:
	char mahang[30];
	char tenhang[30];
	float dongia;
	float dlxilanh;
	float trongluong;
	public:
	  OTO();
	  OTO( char *mathang, char *tenhang ,float dongia ,float dlxilanh ,float trongluong) 
		{
			strcmp(this->mahang,mahang);
			strcmp(this->tenhang,tenhang);
			this->dongia =dongia;
			this->dlxilanh =dlxilanh;
			this->trongluong=trongluong; 
		};
		~OTO(){};
		friend istream& operator >>(istream & is, OTO & oto);
		friend ostream& operator <<(ostream & os, OTO oto );
		
		float tienvanchuyen()
		{
			if(trongluong>2)
			{
				return 100000;
			}
			else if(trongluong>1)
			{
				return 50000;
			}
			else
			{
				return 30000;
			}
		};
	 
friend bool operator ==(OTO xilanh , float x )
		{	
			if (xilanh.dlxilanh ==x ) 
			{
				return true;
			}
			else
			 	return false;
			cout<<"\nDung luong xi lanh khong bang !"<<endl;
		} 
		float getdlxilanh()
		{
			return dlxilanh;
		}
		char *gettenhang()
		{
			return tenhang; 
		}	
};
OTO::OTO()
{
	this->mahang[30]=' ';
	this->tenhang[30]=' ';
	this->dongia=0;
	this->dlxilanh=0;
	this->trongluong=0;
};
istream& operator >>(istream & is ,OTO & oto)
{
	fflush(stdin);
	cout<<"\nNhap ma mat hang: ";
	cin.getline(oto.mahang,30);
	cout<<"\nNhap ten hang: ";
	cin.getline(oto.tenhang,30);
	cout<<"\nNhap don gia: ";
	cin>>oto.dongia;
	cout<<"\nNhap dung tich xi lanh: ";
	cin>>oto.dlxilanh;
	cout<<"\nNhap trong luong xe: ";
	cin>>oto.trongluong;
	return is;
};
ostream& operator <<(ostream & os , OTO oto)
{
	os<<"mahang"<<setw(15)<<"tenhang"<<setw(15)<<"dongia"<<setw(15)<<"xilanh"<<setw(15)<<"trongLuong"<<setw(20)<<"tien van chuyen"<<endl;
	os<<oto.mahang<<setw(15)<<oto.tenhang<<setw(15)<<oto.dongia<<setw(15)<<oto.dlxilanh<<setw(15)<<oto.trongluong<<setw(15)<<oto.tienvanchuyen()<<endl;
	return os;
};
int main()
{
	OTO *oto;
	int n;
	cout<<"\nNhap so oto: ";
	cin>>n;
	oto = new OTO[n];
		for(int i=0;i<n;i++)
		{
			cout<<"\nNhap thong tin xe oto thu "<<i+1<<endl;
			cin>>oto[i];
			cout<<"\n_______________________***____________________"<<endl;
		}
		//xuat danh sach xe oto co dungtich xi lanh 2.5
		bool kt;
		kt = false;
		cout<<"\nDanh sach oto co dungtich xi lanh 2.5 la:"<<endl;
		for(int i=0;i<n;i++)
		{   
				if(oto[i].getdlxilanh()== 2.5)
				{
				kt =true;
				cout<<oto[i];
				}
		}
			if(!kt){
				cout<<"\n______danh sach khong co xi lanh 2.5________"<<endl;
			} 
		
		OTO tkoto;
		cout<<"\nNhap ten hang oto muon tim: ";
		cin>>tkoto.gettenhang();
		
		bool kt1 ;
		kt1 =false;
		for(int i=0;i<n;i++)
		{
			if(strcmp(tkoto.gettenhang(),oto[i].gettenhang())==0)
			{
				for(int k=0;k<n;k++)
				{
					n--;
					oto[k]=oto[k+1];
					kt1 =true;	
				}
				cout<<"\nDanh sach sau khi xoa!!!"<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<oto[i];
					cout<<endl;
				}	
			}
		} 
		if(!kt1)
		{
			cout<<"\nTen hang  vua nhap khong co trong ds"<<endl;
			cout<<"\nThong tin xe nhap them la"<<endl;
			cin>>tkoto;
			for(int i=n-1;i>0;i--)
		 	{
	 			oto[i]=oto[i-1];
	 		}
	 		n++;
	 		oto[0]=tkoto;
	 		cout<<"\nDanh sach sau khi chen: "<<endl;
	 		for(int i=0;i<=n-1;i++)
	 		{
		 		cout<<oto[i];
		 		cout<<endl;
		 	}
		}
		cout<<endl;
		return 0;
}
