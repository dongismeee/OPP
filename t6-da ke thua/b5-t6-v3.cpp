#include <iostream> 
#include<string>
using namespace std;
class internet{
	protected:
		char hoten[20];
		char diachi[30];
	public:
		virtual void nhap(){
			fflush(stdin);
			cout<<"\nNhap ho ten:";
			cin.getline(hoten , 20);
			cout<<"\nNhap dia chi:";
			cin.getline(diachi , 30);
		};
		virtual void xuat(){
			cout<<"\nHo ten: "<<hoten;
			cout<<"\nDia chi: "<<diachi;
		};
		virtual float tientb() =0;
		virtual int maloaihinh() =0;
		friend float tongchung();
	friend float tongtungloai();
	
};
class dialup:public internet {
	private:
		int thoigianthue;
		int hinhthucthue;
	public:
		void nhap(){
			internet::nhap();
			fflush(stdin);
			cout<<"\nHinh thuc thue (chon)";
			cout<<"\n1.Thue thang  2.Thue dl dulieu: ";
			cin>>hinhthucthue;
			cout<<"\nThoi gian thue: ";
			cin>>thoigianthue;
		};
		void xuat(){
			internet::xuat();
			if(hinhthucthue ==1 ){
				cout<<"\nHinh thuc thue: ";
				cout<<"Thue thang:";
			}
			if(hinhthucthue ==2 ){
				cout<<"\nHinh thuc thue: ";
				cout<<"Thue dung luong dl:";
			}
			cout<<"\nThoi gian thue: "<<thoigianthue;
		};
		float tientb(){
			if(hinhthucthue == 1)
				return 300*thoigianthue;
			else if(hinhthucthue == 2)
				return 30*thoigianthue;	
		};
		int maloaihinh(){
			return 1;
		};
};
class adsl:public internet {
	private:
		int thoigianthue;
		int hinhthucthue;
	public:
		void nhap(){
			internet::nhap();
			fflush(stdin);
			cout<<"\nHinh thuc thue (chon)";
			cout<<"\n1.Thue thang  2.Thue dl dulieu: ";
			cin>>hinhthucthue;
			cout<<"\nThoi gian thue: ";
			cin>>thoigianthue;
		};
		void xuat(){
			internet::xuat();
			if(hinhthucthue ==1 ){
				cout<<"\nHinh thuc thue: ";
				cout<<"Thue thang:";
			}
			if(hinhthucthue ==2 ){
				cout<<"\nHinh thuc thue: ";
				cout<<"Thue dung luong dl:";
			}
			cout<<"\nThoi gian thue: "<<thoigianthue;
		};
		float tientb(){
			if(hinhthucthue == 1)
				return 500*thoigianthue;
			else if(hinhthucthue == 2)
				return 50*thoigianthue;	
		};
		int maloaihinh(){
			return 2;
		}
			
};
class t1:public internet {
	private:
		int thoigianthue;
	public:
		void nhap(){
			internet::nhap();
			fflush(stdin);
			cout<<"\nThoi gian thue: ";
			cin>>thoigianthue;
		};
		void xuat(){
			internet::xuat();
			cout<<"\nThoi gian thue: "<<thoigianthue;
		};
		float tientb(){
				return 20*thoigianthue;
		};
		int maloaihinh(){
			return 3;
		}			
};
void tongchung( internet * a[], int n){
	float tongc;
	tongc = 0;
	for(int i=0;i<n;i++){
		tongc += a[i]->tientb();
	}
	cout<<"\nTong 3 loai hinh cho thue: "<<tongc<<endl;
};

void tongtungloai(internet * s[], int n){
	float d=0 , a=0 , t=0;
	for(int i=0;i<n;i++){
		if( s[i]->maloaihinh() ==1){
			d += s[i]->tientb();
		}
	}
	for(int i=0;i<n;i++){
		if( s[i]->maloaihinh() ==2){
			a += s[i]->tientb();
		}
	}
	for(int i=0;i<n;i++){
		if( s[i]->maloaihinh() ==3){
			t += s[i]->tientb();
		}
	}
	cout<<"\nTong tien Dialup: "<<d;
	cout<<"\nTong tien ADSL: "<<a;
	cout<<"\nTong tien T1: "<<t;
};
int main()
{
	internet *s[100];
	int n;
	cout<<"\nNhap so luong thue bao: ";
	cin>>n;
	int i = 0;
	for (int i = 0; i<n;i++)
	{
		cout<<"\t\t1.Nhap thue bao Dial UP"<<endl;
		cout<<"\t\t2.Nhap thue bao ADSL"<<endl;
		cout<<"\t\t3.Nhap thue bao T1"<<endl;
		cout<<"\t\t4.EXIT"<<endl;
		int c;
		cout<<"\n => Moi nhap lua chon: ";
		cin>>c;
		if(c==1)
		{
			s[i] = new dialup();
		}
		else if (c==2)
		{
			s[i] = new adsl();
		}
		else if (c==3)
		{
			s[i] = new t1();
		}
		
		s[i]->nhap();
		cout<<endl;
	}
	cout<<"\n\t\t___Danh sach thue bao"<<endl;
	for(int i=0; i<n;i++)
	{
		s[i]->xuat(); 
		cout<<endl;
	}
	cout<<"\nTong tien cuoc cua tung loai mang: ";
	tongtungloai(s,n);

	cout<<"\nTong tien cuoc thu duoc cua tat ca thue bao: ";
	tongchung(s,n);
	cout<<endl;
	return 0;
}
	