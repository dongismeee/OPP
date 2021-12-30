#include <iostream.h>
#include <string.h>
#include <math.h>
using namespace std;
class hanghoa 
{
	protected:
		string ma;
		string tenhang;
		float dongia;
	public:
		string getma(){
			return ma;
		}
		string gettenhang(){
			return tenhang;
		}
		hanghoa(){
			ma=" ";
			tenhang="";
			dongia=0;
		};
		~hanghoa(){};
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ma hang: ";
			getline(cin,ma);
			cout<<"\nNhap ten hang: ";
			getline(cin, tenhang);
			cout<<"\nNhap don gia: ";
			cin>>dongia;
		};
		void xuat(){
			cout<<"\nMa hang: "<<ma;
			cout<<"\nTen hang: "<<tenhang;
			cout<<"\nDon gia: "<<dongia;
		};
		void swap(hanghoa &x , hanghoa &y){
			hanghoa tg;
			tg=x ;
			x=y;
			y=tg;
		} 
};
class maytinh:public hanghoa
{
	protected:
		int tocdo;
		int soluong;
	public:
		int gettd(){
			return tocdo;
		}
		maytinh(){
			tocdo=0;
			soluong=0;
		};
		~maytinh(){};
		friend istream& operator >>(istream &is ,maytinh & mt){
			fflush(stdin);
			mt.hanghoa::nhap();
			cout<<"\nNhap toc do: ";
			is>>mt.tocdo;
			cout<<"\nNhap so luong: ";
			is>>mt.soluong;
			return is;	
		};
		friend ostream& operator <<(ostream & os ,maytinh mt){
			mt.hanghoa::xuat();
			cout<<"\nToc do: ";    os<<mt.tocdo;
			cout<<"\nSo luong: "; os<<mt.soluong;
			cout<<"\nTien: ";     os<<mt.tien();
			return os;		
		};	
		float tien(){
			return (soluong * dongia);
		};
};
class maytinhxachtay:public maytinh
{
	private:
		float trongluong;
	public:
		maytinhxachtay(){
			trongluong=0;
		};
		~maytinhxachtay(){};
		float tienbt(){
			return ( 0.05 * this->dongia);
		};
		friend istream& operator >>(istream & is, maytinhxachtay & mtxt){
			is>>(maytinh&)mtxt;
			fflush(stdin);
			cout<<"\nNhap trong luong: ";
			is>>mtxt.trongluong;
			return is;
		};
		friend ostream& operator <<(ostream & os, maytinhxachtay mtxt){
			os<<(maytinh)mtxt;
			cout<<"\nTrong luong: ";os<<mtxt.trongluong;
			cout<<"\nTien bao tri: ";os<<mtxt.tienbt();
		};	
};
void menu(){
	maytinhxachtay * a;
	int n,i;
	a = new maytinhxachtay[n];
	string tk , tk_th , hang , xoa_m;
	int x;
	do
	{
		system("cls");
		cout<<"\n\t\t\t============MENU==============";
		cout<<"\n\t\t\t1.Nhap va hien thi ds may tinh xach tay";
		cout<<"\n\t\t\t2.Tim kiem mt theo ma nhap tu ban phim";
		cout<<"\n\t\t\t3.Liet ke may tinh xach tay theo ten";
		cout<<"\n\t\t\t4.tinh tong phi bao tri cua mt";
		cout<<"\n\t\t\t5.Tim mt co tocdo nho nhat";
		cout<<"\n\t\t\t6.Sua thong tin  mot mt";
		cout<<"\n\t\t\t7.Xoa mot mt theo ma cho truoc";
		cout<<"\n\t\t\t8.Chen them mot mt vao vi tri k nhap tu ban phim";
		cout<<"\n\t\t\t9.Sap xep ds theo chieu tang dan cua ma";
		cout<<"\n\t\t\t10.Thoat!";
		cout<<"\n\t\t\t==Hay nhap su lua chon cua ban: ";
		cin>>x;
		switch(x)
		{
			case 1:
			{
				system("cls");
				cout<<"\nNhap so may tinh muon dien tt: ";
				cin>>n;
				for(i=0;i<n;i++){
					cout<<"\nSTT: "<<i+1;
					cin>>a[i];
				}
				cout<<"\n\t\t\t==Ds sau khi nhap+==";
				for(i=0;i<n;i++){
					cout<<"\n\tThong tin may so "<<i+1;
					cout<<a[i];
				}
				system("pause");
			}
			break;
			case 2:
			{
				system("cls");
				fflush(stdin);
				cout<<"\nNhap ma may tinh can tim kiem";
				cin>>tk;
				for(i=0;i<n;i++){
					if(a[i].getma() == tk){
						cout<<a[i]; 
					}
				}
				system("pause");
			}
			break;
			case 3:
			{
				system("cls");
				cout<<"\nNhap ten hang may can tim: ";
				cin>>tk_th;
				cout<<"\nDanh sach may tinh co ten la: "<<tk_th;
				for(i=0;i<n;i++){
					if(a[i].gettenhang() == tk_th){
						cout<<a[i];
					}
				}
				system("pause");
			}
			break;
			case 4:
			{
				
				system("cls");
				for(i=0;i<n;i++){
					cout<<"\nTien bao tri cua may so tinh: "<<i+1<<" Hang "<<a[i].gettenhang()<<" so tien "<<a[i].tien();
					cout<<endl;
				}
				system("pause");
			}
			break;
			case 5:
			{
				system("cls");
				cout<<"\nThong tin may tinh co toc do nho nhat";
				float mintd;
				int cs = 0;
				mintd = a[0].gettd();
				for(i = 1; i <= n; i++){
					if(mintd > a[i].gettd()){
						mintd = a[i].gettd();
						cs = i;
					}
				}
			 	cout<<a[cs];
			 	system("pause");
			}
			break;
			case 6:
			{
				system("cls");
				cout<<"\n\t1.Sua thong tin";
				cout<<"\n\t2.Hien thi ds sau khi sua";
				cout<<"\n\t3.Thoat!";
				cout<<"\n\t Hay chon gia dung! ";
				int(chon);
				cin>>chon; 
				 	switch(chon)
					{
						case 1:
						{
							system("cls");
							maytinhxachtay suamt;
							int pos;
							bool kt;
							kt = false;
							for(int i=0;i<n;i++){
								if(a[i].getma() == hang ){
									pos=i;
									kt =true;
									for(i = pos ;i < n-1 ;i++){
										a[i]=a[i+1];
									}
									n--;
									cout<<"\nThong tin ban update ";
									cin>>suamt;
								 	for(i = n; i > pos; i--){
	 									a[i]=a[i-1];
	 								}
	 								a[pos]=suamt;
	 								n++;
								}
								if(!kt){
									cout<<"\nMa khong co trong danh sach!"<<endl;
								}
								system("pause>pls");
							}
						}
						break;
						case 2:
							{
								system("cls");
								cout<<"\nThong tin sua khi sua:";
								for(i=0;i<n;i++){
									cout<<a[i];
								}
								system("pause>pls");
							}
							break;
						default: 
								break;	
					}
					while(chon!=3);
					system("pause");
			}
			break;
			case 7:
			{
				system("cls");
					cout<<"\n\t1.Sua thong tin";
					cout<<"\n\t2.Hien thi ds sau khi sua";
					cout<<"\n\t3.Thoat!";
					cout<<"\n\t Hay chon gia dung! ";
					int(chon);
					cin>>chon; 
						switch(chon)
						{
							case 1:
							{
								system("cls");
								cout<<"\nNhap ma hang muon xoa! ";
								cin>>xoa_m;
								bool kt;
								kt =false;
								maytinhxachtay xoamt;
								int pos;
								for(i=0;i<n;i++){
									if(a[i].getma()== xoa_m ){
										pos=i;
										kt = true;
										for(i = pos ;i < n-1 ; i++){
											a[i]=a[i+1];
										}
										n--;
									}
								}
								if(!kt){
									cout<<"\n==Khong co ma trong ds!";
								}
								system("pause>pls");
							}
							break;
						    case 2:
							{
								system("cls");
								cout<<"\nDanh sach sau khi xoa! ";
								for(i=0;i<n;i++){
									cout<<"\nSTT: "<<i+1;
									cout<<a[i];
								}
								system("pause>pls");
							}
							break;
						default:
								break;		
						}
						while(chon!=3);
						system("pause");	
			}
			
			break;
			case 8:
			{
				system("cls");
				int pos;
				maytinhxachtay chen_mt;
				cout<<"\nNhap vi tri k muon chen: ";
				fflush(stdin);
				cin>>pos;
				cout<<"\nNhap thong tin cua vi tri k :";
				cin>>chen_mt;
					for(i=n ;i>=pos ;i--){
						a[i]=a[i-1];
					}
					a[pos] = chen_mt;
					n++;
				system("pause");	
			}
			break;
			case 9:
			{
				system("cls");
				cout<<"\n\tDanh sach sau khi sap xep";
				for(i=0;i<n-1;i++){
					for(int j=i-1;j<n;j++){
						if(a[i].getma() > a[j].getma()){
							swap(a[i],a[j]);
						}
					}
				}
				for(int i = 0; i < n; i++){
					cout<<"\nSTT: "<<i+1;
					cout<<a[i];
				}
				system("pause");	
			}
			break;
		default:
			break;	
		}
	}
	while(x!=10);
}
int main(){
	menu();
	return 0;
}