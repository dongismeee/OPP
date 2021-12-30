#include <iostream>
#include <string>
using namespace std;
class mathang
{
	protected:
		string mahang;
		string tenhang;
		float dongia;
	public:
		mathang()
		{
			mahang=" ";
			tenhang=" ";
			dongia=0;	
		};
		mathang( string mahang, string tenhang, float dongia )
		{
			this->mahang=mahang;
			this->tenhang=tenhang;
			this->dongia=dongia;
		}
		~mathang(){};
		friend iostream& operator >>(istream & is, mathang & );
};
class banhkeo:public mathang
{
	private: 
 		string noisx;
 	public:
 		string gettenhang()
 		{
		 	return tenhang;
		 }
	 	banhkeo()
		{
			noisx =" ";
		};
		banhkeo( string mahang ,string tenhang, float dongia ,string noisx) : mathang(mahang,tenhang,dongia)
		{
			this->mahang=mahang;
			this->tenhang=tenhang;
			this->dongia=dongia;
			this->noisx=noisx;	
		}
		~banhkeo(){};
		float chietkhau()
		{
			return (dongia* 0.1);
		};
		friend istream& operator >>(istream & is, banhkeo & bk)
		{
			fflush(stdin);
			cout<<"\nNhap ten ma hang: ";
			getline(is, bk.mahang);
			cout<<"\nNhap ten hang: ";
			getline(is, bk.tenhang);
			cout<<"\nNhap don gia: ";
			is>>bk.dongia;
			fflush(stdin);
			cout<<"\nNhap noi san xuat: ";
			getline(is, bk.noisx);
			return is;
		}
		friend ostream& operator <<(ostream &os, banhkeo bk)
		{
			cout<<"\nMa hang: ";		os<<bk.mahang;
			cout<<"\nTen hang: "; 		os<<bk.tenhang;
			cout<<"\nDon gia: "; 		os<<bk.dongia;
			cout<<"\nNoi san xuat: ";	os<<bk.noisx;
			cout<<"\nTien chieu khau: ";os<<bk.chietkhau();
			return os;
		} 	
};
int main()
{
	banhkeo a[50];
	int i,n ;
	cout<<"\nNhap so luong banh keo n= ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nThong tin ve loai keo thu "<<i+1;
		cin>>a[i];
	}
	//hien thi mat hang co ma khac mo1
	bool kt;
	kt = false;
	string tk ="MO1";
	for(i=0;i<n;i++)
	{
		if(a[i].gettenhang() == tk)
		{
			kt =true;
		}
	}
	if(!kt){
		cout<<"\ndanh sach banh keo khong co ma MO1"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<a[i];
		}	
	}
	cout<<endl;
	return 0;
}