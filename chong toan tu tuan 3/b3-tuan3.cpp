#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class giaovien
{
	private:
	 char ht[30];
	 int tuoi;
	 char bc[15];
	 char cn[20];
	 float bl;
	public:
	  giaovien();
	  friend istream& operator >>(istream & is ,giaovien & );
	  friend ostream& operator <<(ostream & os , giaovien );
	  float tinhluong();
	  float getbl();
	  char *getht()
	  	{
  		return ht;
  		}; 
};
istream& operator>>(istream &is,giaovien &gv)
{
	fflush(stdin);
	cout<<"\nnhap ho ten: ";
	is.getline(gv.ht,30);
	cout<<"\nNhap tuoi : ";
	is>>gv.tuoi;
	fflush(stdin);
	cout<<"\nbang cap: ";
	is.getline(gv.bc,15);
	fflush(stdin);
	cout<<"\nchuyen nganh: ";
	is.getline(gv.cn,20);
	cout<<"\nNhap bac luong: ";
	is>>gv.bl;
	return is;
}
ostream& operator<<(ostream &os ,giaovien gv)
{
	os<<"hoten"<<setw(15)<<"tuoi"<<setw(15)<<"bangcap"<<setw(15)<<"chuyennganh"<<setw(15)<<"bacluong"<<setw(15)<<"luong"<<endl;
	os<<gv.ht<<setw(15)<<gv.tuoi<<setw(15)<<gv.bc<<setw(15)<<gv.cn<<setw(15)<<gv.bl<<setw(15)<<gv.tinhluong()<<endl;
	return os;	
}
giaovien::giaovien()
 {
 	ht[30]=' ';
 	tuoi=0;
 	bc[15]=' ';
 	cn[20]=' ';
 	bl=0;
 } 
float giaovien::getbl()
{
	return bl;
}
float giaovien::tinhluong()
{
	return (bl*610);
}
int main()
{
	giaovien *GV;
	int n;
	GV = new giaovien[n];
	cout<<"\nNhap so giao vien: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nThong tin giao vien thu "<<i+1<<endl;
		cin>>GV[i];
		cout<<"\n__________________________________"<<endl;
	}
	for(int i=0;i<n;i++)
	{
		if(GV[i].tinhluong()<2000)
		{
			cout<<"\n\nGiao vien luong nho hon 2000: "<<endl;
			cout<<GV[i];
			cout<<"\n__________________________________"<<endl;
		}
	}	
			cout<<"\nKhong co giao vien luong nho hon 2000"<<endl;
			cout<<"\n__________________________________"<<endl;
	giaovien gvtk;
	cout<<"\nNhap giao vien can tim:";
	cin>>gvtk.getht();
	bool kt;
	kt = false;
	int chiso;
	for(int i=0;i<n;i++)
	{
		if(strcmp(GV[i].getht(),gvtk.getht())==0){
		 	kt= true;
		 	chiso =i;
		}
	}
	if(kt)
	{
		cout<<"\nGiao vien nay co trong danh sach va co luong la: "<<GV[chiso].tinhluong()<<endl;
	}
	else
	{
		cout<<"\nGiao vien nay khong co trong danh sach,nhap de them vao ds :"<<endl;
		n++;
		GV[n-1]=gvtk;
	}
	cout<<endl;
	return 0;
	
}

