#include<iostream>
#include<string.h>

using namespace std;
class QLtaichinh{
	public:
	 	virtual void nhap() =0;
	 	virtual void xuat() =0;
	 	virtual float luong() =0;
	 	virtual float tienBH() =0;
	 	virtual float tienMH() =0;
	 	virtual string getTen() =0;
	 	friend void menuNV();
	 	friend void menuBH();
	 	friend void menuNL();
	 	friend void menuTC();
};
class NhanVien:public QLtaichinh	{
	protected:
		char tenNV[30];
		int tuoi;
		char diachi[30];
		char vitriCV[30];
		float timelv;
		int sdt;
		
	public:
		NhanVien(){
			this->tenNV[30]=' ';
			this->diachi[30]=' ';
			this->vitriCV[30]=' ';
			this->tuoi=0;
			this->timelv=0;
			this->sdt=0;
		}
		NhanVien(char *tenNV, char *diachi, char *vitriCV, int tuoi, float timelv,int sdt){
			this->tenNV[30]=tenNV[30];
			this->diachi[30]=diachi[30];
			this->vitriCV[30]=vitriCV[30];
			this->tuoi=tuoi;
			this->timelv=timelv;
			this->sdt=sdt;
		}
		~NhanVien(){
			
		}
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap vao ten Nhan vien: ";
			cin.getline(tenNV,30);
			cout<<"\nNhap vao ma vi tri cong viec: ";
			cin.getline(vitriCV,30);
			cout<<"\nNhap vao tuoi Nhan vien: ";
			cin>>tuoi;
			fflush(stdin);
			cout<<"\nNhap vao dia chi Nhan vien: ";
			cin.getline(diachi,30);
			cout<<"\nNhap vao so dien thoai Khach hang: ";
			cin>>sdt;
			cout<<"\nNhap vao thoi gian da lam viec trong thang: ";
			cin>>timelv;
		}
		void xuat(){
			cout<<"\nTen Nhan vien: "<<tenNV;
			cout<<"\nVi tri cong viec: "<<vitriCV;
			cout<<"\nTuoi Nhan vien: "<<tuoi;
			cout<<"\nDia chi Nhan vien: "<<diachi;
			cout<<"\nSo dien thoai Khach hang: "<<sdt;
			cout<<"\nThoi gian da lam viec trong thang: "<<timelv;
		}
		float luong(){
			return 2000 * timelv;
		}
		float tienMH(){
			return 0;
		}
		float tienBH(){
			return 0;
		}
		string getTen(){
			return tenNV;
		}
};
class KhachHang	{
	protected:
		char maPhieu[30];
		char tenKH[30];
		int tuoi;
		int sdt;
	public:
		KhachHang(){
			this->maPhieu[30]=' ';
			this->tenKH[30]=' ';
			this->tuoi=0;
			this->sdt=0;
		}
		KhachHang(char *tenKH,int tuoi, char *maPhieu,int sdt){
			this->maPhieu[30]=maPhieu[30];
			this->tenKH[30]=tenKH[30];
			this->tuoi=tuoi;
			this->sdt=sdt;
		}
		~KhachHang(){
			
		}
		 void nhap(){
			fflush(stdin);
			cout<<"\nNhap vao ten Khach hang: ";
			cin.getline(tenKH,30);
			cout<<"\nNhap vao tuoi Khach hang: ";
			cin>>tuoi;
			fflush(stdin);
			cout<<"\nNhap vao ma phieu an: ";
			cin.getline(maPhieu,30);
			cout<<"\nNhap vao so dien thoai Khach hang: ";
			cin>>sdt;
		}
		void xuat(){
			cout<<"\nTen Khach hang: "<<tenKH;
			cout<<"\nTuoi: "<<tuoi;
			cout<<"\nMa phieu an: "<<maPhieu;
			cout<<"\nSDT: "<<sdt;
		}
		friend void menuNL();
		string getTen(){
			return maPhieu;
		}	
};
class QlBanHang:public QLtaichinh, public KhachHang{
	protected:
		char tenMonAn[30];
		double suatan;
		int soluong;
	public:
		QlBanHang(){
			this->tenMonAn[30]=' ';
			this->suatan=0;
			this->soluong=0;
		}
		QlBanHang(char *tenKH,int tuoi, char *maPhieu,int sdt,char *tenMonAn, double dongia, float	sosuat):KhachHang(tenKH,tuoi,maPhieu,sdt){
			this->tenMonAn[30]=tenMonAn[30];
			this->suatan=suatan;
			this->soluong=soluong;
		}
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap vao ten Mon an: ";
			cin.getline(tenMonAn,30);
			cout<<"\nNhap vao don gia suat an(25k - 30k - 50k): ";
			cin>>suatan;
			cout<<"\nNhap so luong suat an: ";
			cin>>soluong;
		}
		void xuat(){
			KhachHang::xuat();
			cout<<"\nNhap vao ten Mon an: "<<tenMonAn;
			cout<<"\nNhap vao don gia suat an: "<<suatan;
			cout<<"\nNhap vao so luong suat an: "<<soluong;
		}
		float tienBH(){
			return soluong * suatan;	
		}
		float luong(){
			return 0;
		}
		float tienMH(){
			return 0;
		}
		string getTen(){
			return 0;
		}
};
class NguyenLieu:public	QLtaichinh	{
	protected:
		char maNL[30];
		char tenNL[30];
		int ngay;
		int thang;
		int nam;
		float soluong;
		double gianhap;
	public:
		NguyenLieu	(){
			this->maNL[30]=' ';
			this->tenNL[30]=' ';
			this->ngay=0;
			this->thang=0;
			this->nam=0;
			this->soluong=0;
			this->gianhap=0;
		}
		NguyenLieu	(char *maNL, char *tenNL,int ngay, int thang, int nam, float soluong, double gianhap){
			this->maNL[30]=maNL[30];
			this->tenNL[30]=tenNL[30];
			this->ngay=ngay;
			this->thang=thang;
			this->nam=nam;
			this->soluong=soluong;
			this->gianhap=gianhap;
		}
		~NguyenLieu	(){
			
		}
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap vao ten Nguyen lieu: ";
			cin.getline(tenNL,30);
			cout<<"\nNhap vao ma Nguyen lieu: ";
			cin.getline(maNL,30);
			cout<<"\nNhap vao ngay nhap Nguyen lieu: ";
			cin>>ngay;cout<<"/";cin>>thang;cout<<"/";
			cin>>nam;
			cout<<"\nNhap vao so luong nguyen lieu: ";
			cin>>soluong;
			cout<<"\nNhap vao don gia nhap nguyen lieu: ";
			cin>>gianhap;
		}
		void xuat(){
			cout<<"\nTen Nguyen lieu: "<<tenNL;
			cout<<"\nMa Nguyen lieu: "<<maNL;
			cout<<"\nNgay nhap Nguyen lieu: "<<ngay<<"/"<<thang<<"/"<<nam;
			cout<<"\nSo luong nguyen lieu: "<<soluong;
			cout<<"\nDon gia nhap nguyen lieu: "<<gianhap;
		}
		float tienMH(){
			return soluong* gianhap;
		}
		float luong(){
			return 0;
		}
		float tienBH(){
			return 0;
		}
		string getTen(){
			return tenNL;
		}
};
void menuKH(KhachHang * a[], int n){
	int chon1, i;
	char tenkh[30];
	int pos;
	do
	{
		system("cls");
		cout<<"\n\t\t\t-----KH-----";
		cout<<"\n\t\t1.Nhap thong tin.";
		cout<<"\n\t\t2.Xuat thong tin.";
		cout<<"\n\t\t3.Sua thong tin.";
		cout<<"\n\t\t4.Them thong tin.";
		cout<<"\n\t\t5.Xoa thong tin.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon1;
		switch(chon1)
		{
			case 1:
			{
				system("cls");
			  	cout<<"\nNhap so luong khach hang: ";
			  	cin>>n;
	 	 		for(i=0;i<n;i++)
			  	{
					cout<<"\nSTT "<<i+1;
  					a[i]->nhap();
  				}
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
			  	cout<<"\n\t\t-----Danh sach khach hang------";
				for(i=0;i<n;i++){
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
				} 
				system("pause>pls");
			}
			break;
			case 3: {
				system("cls");
				cin.ignore(); 
				cout<<"\n-------Nhap ten Khach hang can sua: ";cin.getline(tenkh, 30);
				for(int i=0;i<n;i++){
					if(a[i]->getTen()==tenkh){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    --n;
					    
					    a[pos]->nhap();
 
					    ++n;		    
					}
				}
				system("pause>pls");
			}break;
			case 4:
			{
				system("cls");
			  	cout<<"\n-------Nhap thong tin Khach hang can them."<<endl;
					a[n]->nhap();
					n++;
				system("pause>pls");
			}
			break;
			case 5:
			{
				system("cls");
				char *tenKH;
				int pos;
				cout<<"\n-------Nhap ten Khach hang can xoa: ";cin>>tenKH;
				for(int i=0;i<n;i++){
					if(a[i]->getTen()==tenKH){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    n--;		    
					}
				}
				system("pause>pls");
			}
			break;
		default:
			break;	
		}
	}while(chon1!=99);	
}
void menuNV(QLtaichinh * a[], int n){
	int chon2, i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t-----NV-----";
		cout<<"\n\t\t1.Nhap thong tin.";
		cout<<"\n\t\t2.Xuat thong tin.";
		cout<<"\n\t\t3.Sua thong tin.";
		cout<<"\n\t\t4.Them thong tin.";
		cout<<"\n\t\t5.Xoa thong tin.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon2;
		switch(chon2)
		{
			case 1:
			{
				system("cls");
			  	cout<<"\nNhap so luong nhan vien: ";
			  	cin>>n;
	 	 		for(i=0;i<n;i++)
			  	{
					cout<<"\nSTT "<<i+1;
  					a[i]->nhap();
  				}
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
			  	cout<<"\n\t\t-----Danh sach nhan vien------";
				for(i=0;i<n;i++){
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
				} 
				system("pause>pls");
			}
			break;
			case 3: {
				system("cls");
				char *tenNL;
				int pos;
				cout<<"\n-------Nhap ten Nguyen lieu can sua: ";cin>>tenNL;
				for(int i=0;i<n;i++){
					if(a[i]->getTen()==tenNL){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    --n;
					    
					    a[pos]->nhap();
 
					    ++n;		    
					}
				}
				system("pause");
			}break;
			case 4:
			{
				system("cls");
			  	cout<<"\n-------Nhap thong tin Nguyen lieu can them."<<endl;
					a[n]->nhap();
					n++;
				system("pause>pls");
			}
			break;
			case 5:
			{
				system("cls");
				cin.ignore(); 
				char *tenNL;
				int pos;
				cout<<"\n-------Nhap ten Nguyen lieu can xoa: ";cin>>tenNL;
				for(int i=0;i<n;i++){
					if(a[i]->getTen()==tenNL){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    n--;		    
					}
				}
				system("pause>pls");
			}
			break;
		default:
			break;	
		}
	}while(chon2!=99);	
}
void menuBH	(QLtaichinh * a[], int n){
	int chon3, i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t-----BH-----";
		cout<<"\n\t\t1.Nhap thong tin.";
		cout<<"\n\t\t2.Xuat thong tin.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon3;
		switch(chon3)
		{
			case 1:
			{
				system("cls");
			  	cout<<"\nNhap so luong suat an ban duoc: ";
			  	cin>>n;
	 	 		for(i=0;i<n;i++)
			  	{
					cout<<"\nSTT "<<i+1;
  					a[i]->nhap();
  				}
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
			  	cout<<"\n\t\t-----Danh sach suat an da ban------";
				for(i=0;i<n;i++){
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
				} 
				system("pause>pls");
			}
			break;
		default:
			break;	
		}
	}while(chon3!=99);	
}
void menuNL	(QLtaichinh * a[], int n){
	int chon4, i;
	char suaNL[30];
	char xoaNL[30];
	int pos; 
	do
	{
		system("cls");
		cout<<"\n\t\t\t-----NV-----";
		cout<<"\n\t\t1.Nhap thong tin.";
		cout<<"\n\t\t2.Xuat thong tin.";
		cout<<"\n\t\t3.Sua thong tin.";
		cout<<"\n\t\t4.Them thong tin.";
		cout<<"\n\t\t5.Xoa thong tin.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon4;
		switch(chon4)
		{
			case 1:
			{
				system("cls");
			  	cout<<"\nNhap so luong nguyen lieu can nhap: ";
			  	cin>>n;
	 	 		for(i=0;i<n;i++)
			  	{
					cout<<"\nSTT "<<i+1;
  					a[i]->nhap();
  				}
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
			  	cout<<"\n\t\t-----Danh sach nguyen lieu------";
				for(i=0;i<n;i++){
					cout<<"\nSTT "<<i+1;
					a[i]->xuat();
				} 
				system("pause>pls");
			}
			break;
			case 3: {
				system("cls");
				cout<<"\n-------Nhap ten Nguyen lieu can sua: ";cin.getline(suaNL, 30);
				for(int i=0;i<n;i++){
					if(a[i]->getTen()==suaNL){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    --n;
					    
					    a[pos]->nhap();
 
					    ++n;		    
					}
				}
				system("pause>pls");
			}break;
			case 4:
			{
				system("cls");
			  	cout<<"\n-------Nhap thong tin Nguyen lieu can them."<<endl;
					a[n]->nhap();
					n++;
				system("pause>pls");
			}
			break;
			case 5:
			{
				system("cls");
				cin.ignore(); 
				cout<<"\n-------Nhap ten Nguyen lieu can xo: ";
				cin.getline(xoaNL, 30);
				for(int i=0;i<n;i++){
					if(a[i]->getTen() == xoaNL){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    n--;		    
					}
				}
				system("pause");
			}
			break;
		default:
			break;	
		}
	}while(chon4!=99);	
}
void menuTC(QLtaichinh * a[], int n){
	int chon5, i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t-----TC-----";
		cout<<"\n\t\t1.Tong doanh thu ban hang.";
		cout<<"\n\t\t2.Tong chi phi mua nguyen lieu.";
		cout<<"\n\t\t3.Tong chi phi tra luong nhan vien.";
		cout<<"\n\t\t4.Can bang thu chi.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon: ";
		cin>>chon5;
		switch(chon5)
		{
			case 1:
			{
				system("cls");
			  	float tongbh;
			  	tongbh =0;
			  	for(i=0;i<n;i++){
	  				tongbh += a[i]->tienBH();
	  			}
	  			cout<<"\nTong so tien ban hang duoc la: "<<tongbh;
				system("pause>pls");
			}
			break;
			case 2:
			{
				system("cls");
			  	float tongmh;
			  	tongmh =0;
			  	for(i=0;i<n;i++){
	  				tongmh += a[i]->tienMH();
	  			}
	  			cout<<"\nTong so tien mua hang duoc la: "<<tongmh;
				system("pause>pls");
			}
			break;
			case 3:
			{
				system("cls");
			  	float tongl;
			  	tongl =0;
			  	for(i=0;i<n;i++){
	  				tongl += a[i]->luong();
	  			}
	  			cout<<"\nTong so tien luong nv la: "<<tongl;
				system("pause>pls");
			}
			break;
			case 4:
			{
				system("cls");
			  	float cb;
			  	cb =0;
			  	for(i=0;i<n;i++){
	  				cb += (a[i]->tienBH() - a[i]->tienMH() - a[i]->luong());
	  			}
	  			if(cb > 0){
			  		cout<<"\nViec kinh doanh dang LAI.";
			  	}
			  	else {
	  				cout<<"\nViec kinh doanh dang LO.";
	  			}
 	  			cout<<"\nTong so tien can bang tai chinh: "<<cb;
				system("pause>pls");
			}
			break;
		default:
			break;	
		}
	}while(chon5!=99);	
}
int main(){
	QLtaichinh *a[100];
	KhachHang * b[100];
	int chon, i, chon5;
	do{
		system("cls");
		cout<<"\n\t\t\t-----MENU-----";
		cout<<"\n\t\t1.Quan ly khach hang.";
		cout<<"\n\t\t2.Quan ly nhan vien.";
		cout<<"\n\t\t3.Quan ly ban hang.";
		cout<<"\n\t\t4.Quan ly nguyen lieu.";
		cout<<"\n\t\t5.Quan ly tai chinh."; 
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLUA CHON: "; cin>>chon;
		switch(chon)
		{
			case 1:
			{
			  system("cls");
			  for(i=0;i<100;i++)
			  	{
				  	b[i] = new KhachHang();
  				}
				menuKH(b,100);
				system("pause");	
			}
			break;
			case 2:
			{
				system("cls");
	 	 		for(i=0;i<100;i++)
		  		{
  					a[i] = new NhanVien();
  				}
				menuNV(a,100);
				system("pause");
			}
			break;
			case 3:
			{
				system("cls");
	 	 		for(i=0;i<100;i++)
		  		{
  					a[i] = new QlBanHang();
  				}
				menuBH(a,100);
				system("pause");
			}
			break;
			case 4:
			{
				system("cls");
	 	 		for(i=0;i<100;i++)
		  		{
  					a[i] = new NguyenLieu();
  				}
				menuNL(a,100);
				system("pause");
			}
			break;
			case 5:
			{
				system("cls");
				menuTC(a,100);
				system("pause");
			}
			break;
		default:
			break;	
		}
	}while(chon!=99);
	return 0;
}