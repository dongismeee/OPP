#include<iostream>
using namespace std;
class Docgia{
	protected: 
		char ma[20];
		char hoten[30];
		int thanghl;
	public:
		Docgia()
		{
			ma[20]=' ';
			hoten[30]=' ';
			thanghl=0;
		};
		~Docgia(){
		};
		virtual void nhap()
		{
		fflush(stdin);	
		cout<<"\nNhap ma the: ";
		cin.getline(ma,20);
		cout<<"\nNhap ho va ten: ";
		cin.getline(hoten,30);
		fflush(stdin);
		cout<<"\nNhap so thang hieu luc: ";
		cin>>thanghl;
		};
		virtual void xuat()
		{
		cout<<"\nMa the: "<<ma;
		cout<<"\nHoten: "<<hoten;
		cout<<"\nThang hieu luc: "<<thanghl;	
		};
		virtual float tinhtien() =0;
		virtual int Tim() = 0;
};
class DGtre:public Docgia {
	protected: 
		int ns;
	public:
		DGtre(){
			ns=0;
		};
		~DGtre(){
		};
		void nhap(){
			Docgia::nhap();
			fflush(stdin);
			cout<<"\nNhap nam sinh: ";
			cin>>ns;
		};
		void xuat(){
			Docgia::xuat();
			cout<<"\nNam sinh: "<<ns;
		};
		float tinhtien(){
			return thanghl * 20000;
		};
		int Tim(){
			if(thanghl < 10)
				return 1;
				return 0;
		};	
};
class DGlon:public Docgia {
	protected: 
		char nghe[30];
	public:
		DGlon(){
			nghe[30]=' ';
		};
		~DGlon(){
		};
		 void nhap()
		{
		Docgia::nhap();
		fflush(stdin);
		cout<<"\nNhap nghe nghiep: ";
		cin.getline(nghe, 30);	
		};
		 void xuat()
		{
			Docgia::xuat();
		cout<<"\nNghe nghiep: "<<nghe;	
		};
		float tinhtien(){
			return thanghl * 30000;
		};
		int Tim(){
			if(strcmp(nghe, "Giang Vien")==0)
			 return 1;
			 return 2;
		};	
};
int main()
{ 		
		Docgia *d[30];
				int chon, n, k=0, i, s=0;
				while(1)
				{
				cout<<"\n\t\tNhap su lua chon!";
				cout<<"\n\t\tDocgiatre - Docgialon - Dung (1,2,3): ";
				cin>>chon;
				if(chon==3) 	break;
				if(chon==1){
					d[k]= new DGtre();
				};
				if(chon==2){
					d[k]= new DGlon();
				};	
				d[k]->nhap();
				s = s + d[k]->tinhtien();
				k++;
				k=n;
				cout<<"\n\t\tTong tien lam the:"<<s;
				};
				cout<<"\nDanh sach doc gia can tim: ";
				for(i=0;i<k;i++){
					if(d[i]->Tim() == 1){
						d[i]->xuat();	
						}	
					}		
			return 0;
}