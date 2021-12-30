#include <iostream.h>
#include <string.h>
class Nguoi
{
private:
  char hoten[30];
  int ns;
public:
Nguoi()
{
	strcpy(hoten,"");	
	ns=0;
}
Nguoi( char h[],int a)
{
		strcpy(hoten,h);	
		ns=a;
}
friend istream & operator >>(istream &is, Nguoi &p)
  { 
  	fflush(stdin); 
	cout<<"\n\t Nhap Ho ten: "; is.getline(p.hoten,30);
	fflush(stdin);
	cout<<"\n\t Nhap nam sinh: "; is>>p.ns;
 	return is;
  }
 void Xuat() 
  {
    cout<<"\n\tHo ten: "<<hoten;
    cout<<"\n\tNam sinh:  "<<ns;
  }
};

class SV  
{
private: 	
		char hk[30];
		float dtb;		
public:	
SV() 
 {
 }
SV(char hk1[], float d) 
 { 	
     	strcpy( hk, hk1);
	    dtb= d;		
 }
friend istream & operator >>(istream &is, SV &p)
  { 
  	fflush(stdin);
	cout<<"\n\t Nhap hanh kiem: "; is.getline(p.hk,30);
	cout<<"\n\t Nhap diem tb: "; is>>p.dtb;
	return is;
  }
friend ostream & operator << (ostream & os, SV p)
{
	  cout<<"\n\tHanh Kiem: "; os<<p.hk;
      cout<<"\n\tDiem TB: ";  os<<p.dtb;
      return os;
}
char *GetHk()  
{
	return hk;	
}
float GetDtb() 
{
	return dtb;
 }		
};

class SVTC : public Nguoi, public SV
{
private: 	
	float hp;	
public:
SVTC() 
   {
   }		

SVTC(char ht1[], int n1,char hk1[], float diem, 
float hp1): Nguoi(ht1, n1),SV(hk1, diem)
{
			hp=hp1;
}	
float hocbong()
  {
	if(strcmpi(GetHk(),"A")==0 && GetDtb()>=9.0) 	
				return 5;
	else
	if((strcmpi(GetHk(),"A")==0 && GetDtb()>=8.0)
	|| (strcmpi(GetHk(),"B")==0 && GetDtb()>=8.0)) 
				return 3;
	else
	if((strcmpi(GetHk(),"A")==0 && GetDtb()>=7.0)
	|| (strcmpi(GetHk(),"B")==0 && GetDtb()>=7.0)) 
			      return 2;
    
				 return 0;		
  }		 

friend istream & operator >>(istream &is, SVTC &p)
		{ 
		    is>>(Nguoi&) p;   // goi lai toan tu >>  
		    is>>(SV&) p;
		    fflush(stdin); 
 			cout<<"\n\tHoc Phi: "; is>>p.hp;
		}
friend ostream & operator <<(ostream &os, SVTC p)
		{ 
		    p.Nguoi::Xuat();
     		os<<(SV&) p;
			os<<"\n\tHoc Phi: "<<p.hp;
			if(p.hocbong()!=0)
			os<<"\n\tHoc bong: "<<p.hocbong() <<" TRIEU"<<endl;
			return os;
		}
};

main()
{
SVTC sv[30];
cout<<"\n\tNhap Danh Sach Sinh Vien";
for( int i=0;i<2;i++)
	{ 
		cout<<"\n Nhap Sinh Vien Thu : "<<i+1<<endl;
		cin>>sv[i];  
	}
cout<<"\n danh sach SVTC da nhap "<<endl;
	for( int i=0;i<2;i++) 
    {	
		cout<<sv[i];  
	}
cout<<"\n\n Sinh vien duoc hoc bong"<<endl; 	
	for( int i=0;i<2;i++)
	if(sv[i].hocbong()!=0)
		cout<<sv[i];
for( int i=0;i<1;i++)
	for( int j=i+1; j<2;j++)
	if(sv[i].GetDtb()>sv[j].GetDtb())	
       {
		   	SVTC tg= sv[i];
				sv[i]= sv[j];
				sv[j]=tg;
	   }
	cout<<"\n danh sach SVTC da sap xep "<<endl;
	for( int i=0;i<2;i++)
		cout<<sv[i];
} 