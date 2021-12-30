#include<iostream>
using namespace std;
class Mathang{
	protected:
		string ten_mat_hang;
		int sl_kho;
	public:
		virtual void nhap(){
			fflush(stdin);
			cout<<"\nNhap ten mat hang: ";
			getline(cin, ten_mat_hang);
			cout<<"\nNhap so luong trong kho: ";
			cin>>sl_kho;
		};
		virtual void xuat(){
			cout<<"\nTen Mat Hang : "<<ten_mat_hang;
			cout<<"\nSo Luong Trong Kho: "<<sl_kho;
		};
		virtual void NhapKho() =0;
		virtual void XuatKho() =0;
		friend void menuhang_nk();
		friend void menuhang_dl();
		string gettenmh(){
			return ten_mat_hang;
		}
		int getsl(){
			return sl_kho;
		}	
};
class hang_nk:public Mathang{
	private:
		float tinhthue;
	public:
		void nhap(){
			Mathang::nhap();
			fflush(stdin);
			cout<<"\nNhap tien thue: ";
			cin>>tinhthue;
		};
		void xuat(){
			Mathang::xuat();
			cout<<"Tien Thue: "<<tinhthue;
		};
		float tang_giam_thue(){
		};	
		 void NhapKho(){};
		 void XuatKho(){};
};
class hang_dl:public Mathang{
	private:
		float hoahong;
	public:
		void nhapkho(){
			Mathang::nhap();
			fflush(stdin);
			cout<<"\nNhap tien hoa hong: ";
			cin>>hoahong;
		};
		void xuat(){
			Mathang::xuat();
			cout<<"\nTien hoa hong: "<<hoahong;
		};
		float tang_giam_hoahong(){
		};	
		 void NhapKho(){};
		 void XuatKho(){};
};
void menuhang_nk(Mathang * a[], int n){
	int chon1, i;
	int sl;
	string tk;
	do
	{
		system("cls");
		cout<<"\n\t\t-------HangNhapKhau---------";
		cout<<"\n\t\t1.Nhap hang vao kho.";
		cout<<"\n\t\t2.Xuat hang khoi kho.";
		cout<<"\n\t\t3.So luong hang ton kho.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon1;
			switch(chon1)
			{
				case 1: 
					{
						system("cls");
						cout<<"\n\t\t\t-----HANGNHAPKHAU------";
						cout<<"\nSo hang can nhap kho: ";
						cin>>n;
						for(i=0;i<n;i++){
							cout<<"\nSTT "<<i+1;
							a[i]->nhap();
						}
						cout<<"\nDanh sach hang da nhap.";
						for(i=0;i<n;i++){
							cout<<"\nThong tin mat hang thu: "<<i+1;
							a[i]->xuat();
						}
						system("pause");
					}
					break;
					case 2: 
					{
						system("cls");
						cout<<"\nNhap ten mat hang can xuat: ";
						getline(cin, tk);
						cout<<"\nNhap so luong can xuat: ";
						cin>>sl;
						bool kt = false;
						for(i=0;i<n;i++){
							if(a[i]->gettenmh() ==tk && a[i]->getsl()	>= sl){
								kt= true;
							}
						}
						if(!kt){
							cout<<"\nMat hang ban khong co trong kho or sl khong du!";
						}
						system("pause");
					}
					break;
					case 3: 
					{
						system("cls");
						float tong1;
						tong1 = 0;
						cout<<"\nNhap ten mat hang can kt : ";
						getline(cin, tk);
						for(int i=0;i<n;i++)
						{
							if(a[i]->gettenmh() == tk){
								tong1 += a[i]->getsl() - sl;
							}
						}
						cout<<"\nSo luong mat hang "<<tk<<"la: "<<tong1;
						system("pause");
					}
					break;
				default:
					break;		
			}
	}while(chon1!=99);
};
void menuhang_dl(Mathang * a[], int k){
	int chon1, i;
	int sl;
	string tk;
	do
	{
		system("cls");
		cout<<"\n\t\t-------HangDaiLy---------";
		cout<<"\n\t\t1.Nhap hang vao kho.";
		cout<<"\n\t\t2.Xuat hang khoi kho.";
		cout<<"\n\t\t3.So luong hang ton kho.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon1;
			switch(chon1)
			{
				case 1: 
					{
						system("cls");
						cout<<"\n\t\t\t-----HANGDAILY------";
						cout<<"\nSo hang can nhap kho: ";
						cin>>k;
						for(i=0;i<k;i++){
							cout<<"\nSTT "<<i+1;
							a[i]->nhap();
						}
						cout<<"\nDanh sach hang da nhap.";
						for(i=0;i<k;i++){
							cout<<"\nThong tin mat hang thu: "<<i+1;
							a[i]->xuat();
						}
						system("pause");
					}
					break;
					case 2: 
					{
						system("cls");
						cout<<"\nNhap ten mat hang can xuat: ";
						getline(cin, tk);
						cout<<"\nNhap so luong can xuat: ";
						cin>>sl;
						bool kt = false;
						for(i=0;i<k;i++){
							if(a[i]->gettenmh() ==tk && a[i]->getsl() >= sl){
								kt= true;
							}
						}
						if(!kt){
							cout<<"\nMat hang ban khong co trong kho or sl khong du!";
						}
						system("pause");
					}
					break;
					case 3: 
					{
						system("cls");
						float tong2;
						tong2 = 0;
						cout<<"\nNhap ten mat hang can kt : ";
						getline(cin, tk);
						for(i=0;i<k;i++)
						{
							if(a[i]->gettenmh() == tk){
								tong2 += a[i]->getsl() - sl;
							}
						}
						cout<<"\nSo luong mat hang "<<tk<<"la: "<<tong2;
						system("pause");
					}
					break;
				default:
					break;		
			}
	}while(chon1!=99);
};
int main(){
	Mathang *a[100];
	int chon , i;
	do{
		system("cls");
		cout<<"\n\t\t\t-----MENU------";
		cout<<"\n\t\t1.Nhap hang vao kho.";
		cout<<"\n\t\t2.Xuat hang khoi kho.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon;
			switch(chon)
				{
					case 1: 
					{
						system("cls");
						for(i=0;i<100;i++){
							a[i]= new hang_nk();
						}
						menuhang_nk(a,100);
						system("pause");
					}
					break;
					case 2: 
					{
						system("cls");
						for(i=0;i<100;i++){
							a[i]= new hang_dl();
						}
						menuhang_dl(a,100);
						system("pause");
					}
					break;
				default:
					break;	
				}
	}while(chon!=99);
	
	return 0;
}