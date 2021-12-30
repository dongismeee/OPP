#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 
class quanly {
	public:
		virtual void nhap()=0;
		virtual void xuat()=0;
		virtual char *getcm()=0;
		virtual int getcc() =0;
		virtual char *getvt() =0;
		virtual int getns() =0;
		virtual int getngay() =0;
		virtual int getthang() =0;
		virtual int getnam() =0;
		friend void menuct();
		friend void menutd();
		friend void menudb();
};
class cauthu:public quanly{
	private:
		char cm[10];
		char hoten[20];
		char quoctich[20];
		int namsinh ;
		int chieucao;
		int cannang;
		char vitri[30];
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap so chung minh: ";
			cin.getline(cm, 10);
			cout<<"\nNhap ho ten: ";
			cin.getline(hoten, 20);
			cout<<"\nNhap quoc tich: ";
			cin.getline(quoctich, 20);
			cout<<"\nNhap vi tri thi dau: ";
			cin.getline(vitri, 30);
			cout<<"\nNhap nam sinh: ";
			cin>>namsinh;
			cout<<"\nNhap chieu cao: ";
			cin>>chieucao;
			cout<<"\nNhap can nang: ";
			cin>>cannang;
		};
		void xuat(){
			cout<<setw(10)<<cm<<setw(15)<<hoten<<setw(15)<<quoctich<<setw(15)<<namsinh<<setw(15)<<chieucao<<setw(15)<<cannang<<setw(15)<<vitri<<endl;
		};
		int getns(){
			return namsinh;
		};
		int getcc(){
			return chieucao;
		};;
		char *getvt(){
			return vitri;
		};
		char *getcm(){
			return cm;
		};
		int getngay(){
			return 0;
		};
		int getthang(){
			return 0;
		};
		int getnam(){
			return 0;
		};	
};
class doibong:public quanly{
	private:
		char tendoi[30];
		char diaphuong[30];
		char huanlv[30];
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap vao ten doi bong: ";cin.getline(tendoi,30);
			cout<<"\nNhap vao dia phuong: ";cin.getline(diaphuong,30);
			cout<<"\nNhap vao huan luyen vien: ";cin.getline(huanlv,30);
		};
		void xuat(){
			 cout<<setw(10)<<tendoi<<setw(20)<<diaphuong<<setw(20)<<huanlv<<endl;
		};
		int getns(){
			return 0;
		};
		int getcc(){
			return 0;
		};
		char *getvt(){
			return 0;
		};
		char *getcm(){
			return 0;
		};
		int getngay(){
			return 0;
		};
		int getthang(){
			return 0;
		};
		int getnam(){
			return 0;
		};		
};
class trandau:public quanly{
	private:
		int ngay, thang, nam;
		char santhidau[30];
		char tendoiH[20];
		char tendoiA[20];
		int tysoH;
		int tysoA;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\n\tNhap ngay thi dau ";
			cout<<"\nNgay: ";cin>>ngay;
			cout<<"\nThang: ";cin>>thang;
			cout<<"\nNam: ";cin>>nam;
			cout<<"\nNhap san thi dau: ";
			fflush(stdin);
			cin.getline(santhidau, 30);
			cout<<"\nNhap ten doi bong H: ";
			cin.getline(tendoiH, 20);
			cout<<"\nNhap ty so tran dau(A-B): ";
			cout<<"\nTy so A: ";
			cin>>tysoH;
			cout<<"\nTy so B: ";
			cin>>tysoA;
		};
		void xuat(){
			cout<<setw(10)<<ngay<<"/"<<thang<<"/"<<nam<<setw(25)
			<<santhidau<<setw(25)<<tendoiH<<setw(25)<<tendoiA<<setw(25)<<tysoH<<"-"<<tysoA<<endl;
		};
		int getngay(){
			return ngay;
		};
		int getthang(){
			return thang;
		};
		int getnam(){
			return nam;
		};
		int getns(){
			return 0;
		};
		int getcc(){
			return 0;
		};
		char *getvt(){
			return 0;
		};
		char *getcm(){
			return 0;
		};
};
void menuct(quanly *a[],int n){
	int chon, i;
	char tkcm[10];
	char tkvt[30];
	int pos;
	do{
		system("cls");
		cout<<"\n\t\t\t-----------QUAN LY CAU THU-----------";
		cout<<"\n\t\t1.Nhap danh sach cau thu.";
		cout<<"\n\t\t2.Xuat danh sach cau thu.";
		cout<<"\n\t\t3.Them thong tin cau thu.";
		cout<<"\n\t\t4.Sua thong tin cau thu.";
		cout<<"\n\t\t5.Xoa thong tin cau thu.";
		cout<<"\n\t\t6.Danh sach cau thu theo nam sinh.";
		cout<<"\n\t\t7.Danh sach cau thu theo vi tri thi dau.";
		cout<<"\n\t\t8.Cau thu cao nhat giai.";
		cout<<"\n\t\t9.Cau thu thap nhat giai.";
		cout<<"\n\t\t10.Cau thu tre nhat giai.";
		cout<<"\n\t\t99.GET OUT."<<endl;
		cout<<"\n\t\tChon: ";
		cin>>chon;
		switch(chon){
			case 1: {
				system("cls");
				cout<<"\n\t\t----------INPUT-----------"<<endl;
				cout<<"\nNhap so luong Cau Thu: ";cin>>n;
				for(i=0;i<n;i++){
					cout<<"\nCau thu thu: "<<i+1;
					a[i]->nhap();
				}
				cout<<"\n\t\t---------FINISH----------";
				system("pause>pls");
			}break;
			case 2: 
				{
				system("cls");
				cout<<"\n\t\t----------OUTPUT-----------"<<endl;
				cout<<setw(10)<<"CM"<<setw(15)<<"HOTEN"<<setw(15)<<"QUOCTICH"<<setw(15)<<"NAMSINH"<<setw(15)<<"CHIEUCAO"<<
				setw(15)<<"CANNANG"<<setw(15)<<"VITRI"<<endl;
				for(i=0;i<n;i++){
					a[i]->xuat();
				}
				cout<<"\n\t\t---------FINISH----------";
				system("pause");
			}break;
			case 3: {
				system("cls");
					cout<<"\nThong tin Cau Thu them."<<endl;
					a[n]->nhap();
					n++;
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
			}break;
			case 4: {
				system("cls");
				cin.ignore();
				cout<<"\nCau thu can sua thong tin (CM): ";
				cin.getline(tkcm,10);
				for(i=0;i<n;i++){
					if(strcmp(a[i]->getcm(),tkcm)==0){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    --n;
					    a[pos]->nhap();
					    ++n;		    
					}
				}
				cout<<"\n\t\t---------FINISH----------";
				system("pause>pls");
			}break;
			case 5: {
				system("cls");
				cin.ignore();
				cout<<"\nNhap cau thu can xoa (CM): ";
				cin.getline(tkcm,10);
				for(i=0;i<n;i++){
					if(strcmp(a[i]->getcm(),tkcm)==0){
						pos=i;
						for(int i = pos; i < n - 1; i++){
      						a[i] = a[i+1];
		    			} 
					    --n;		    
					}
				}
				cout<<"\n\t\t---------FINISH----------";
				system("pause>pls");
			}break;
			case 6: {
				system("cls");
				cout<<"\n\t\tDanh sach Cau Thu theo nam sinh";
				int ns;
				cout<<"\nNhap nam sinh cua cau thu: ";
				cin>>ns;
				cout<<endl;
				cout<<setw(10)<<"CM"<<setw(15)<<"HOTEN"<<setw(15)<<"QUOCTICH"<<setw(15)<<"NAMSINH"<<setw(15)<<"CHIEUCAO"<<
				setw(15)<<"CANNANG"<<setw(15)<<"VITRI"<<endl;
				for(i=0;i<n;i++){
					if(a[i]->getns()==ns){
						a[i]->xuat();	
					}
				}
				cout<<"\n\t\t---------FINISH----------";
				system("pause>pls");
			}break;
			case 7: {
				system("cls");
				cin.ignore();
				cout<<"\n\t\tDanh sach cau thu theo Vi tri thi dau.";
				cout<<"\nNhap vi tri thi dau: ";
				cin.getline(tkvt, 30);
				cout<<endl;
				cout<<setw(10)<<"CM"<<setw(15)<<"HOTEN"<<setw(15)<<"QUOCTICH"<<setw(15)<<"NAMSINH"<<setw(15)<<"CHIEUCAO"<<
				setw(15)<<"CANNANG"<<setw(15)<<"VITRI"<<endl;
				for(i=0;i<n;i++){
					if(strcmp(a[i]->getvt(),tkvt)==0){
						a[i]->xuat();	
					}
				}
				cout<<"\n\t\t---------FINISH----------";
				system("pause>pls");
			}break;
			case 8:{
				system("cls");
				float maxcc;
				int cs =0;
				maxcc = a[0]->getcc();
				for(i=0;i<n;i++){
					if(maxcc < a[i]->getcc()){
						maxcc = a[i]->getcc();
						i=cs;
					}
					cout<<"\nCau thu cao nhat giai dau: "<<endl;
					cout<<setw(10)<<"CM"<<setw(15)<<"HOTEN"<<setw(15)<<"QUOCTICH"<<setw(15)<<"NAMSINH"<<setw(15)<<"CHIEUCAO"<<
					setw(15)<<"CANNANG"<<setw(15)<<"VITRI"<<endl;
					a[cs]->xuat();
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
			}break;
			case 9:{
				system("cls");
				float mincc;
				int cs =0;
				mincc = a[0]->getcc();
				for(i=0;i<n;i++)
					{
					if(mincc > a[i]->getcc())
						{
						mincc = a[i]->getcc();
						i=cs;
						}
					}
					cout<<"\nCau thu thap nhat giai dau: "<<endl;
					cout<<setw(10)<<"CM"<<setw(15)<<"HOTEN"<<setw(15)<<"QUOCTICH"<<setw(15)<<"NAMSINH"<<setw(15)<<"CHIEUCAO"<<
					setw(15)<<"CANNANG"<<setw(15)<<"VITRI"<<endl;
					a[cs]->xuat();
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
			}break;
			case 10:
				{
				system("cls");
				float mintuoi;
				int cs =0;
				mintuoi = a[0]->getns();
				for(i=0;i<n;i++)
					{
					if(mintuoi > a[i]->getns())
						{
						a[i]->getns();
						i=cs;
						}
					}
					cout<<"\nCau thu nho tuoi nhat giai dau: "<<endl;
					cout<<setw(10)<<"CM"<<setw(15)<<"HOTEN"<<setw(15)<<"QUOCTICH"<<setw(15)<<"NAMSINH"<<setw(15)<<"CHIEUCAO"<<
					setw(15)<<"CANNANG"<<setw(15)<<"VITRI"<<endl;
					a[cs]->xuat();
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}break;
		default:
			break;
		}
	}while(chon!=99);
};
void menudb(quanly * a[], int n){
	int chon2, i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t-------QUANLYDOIBONG-------";
		cout<<"\n\t\t1.Nhap thong tin doi bong.";
		cout<<"\n\t\t2.Hien thi thong doi bong.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\\tLua chon: ";
		cin>>chon2;
			switch(chon2)
			{
				case 1:
				{
					system("cls");
					cout<<"\n\t\t-------INPUT-------"<<endl;
					cout<<"\nNhap so luong doi bong: ";
					cin>>n;
					for(i=0;i<n;i++){
						cout<<"\nDoi bong thu: "<<i+1;
						a[i]->nhap();
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
					
				}
				break;
				case 2:
				{
					system("cls");
					cout<<"\n\t\t---------OUTPUT--------"<<endl;
					cout<<setw(10)<<"TENDOI"<<setw(20)<<"DIAPHUONG"<<setw(20)<<"HLV"<<endl;
					for(i=0;i<n;i++){
						a[i]->xuat();
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
				break;
			default:
				break;	
			}
	}while(chon2!=99);
}
void menutd(quanly * a[], int n){
	int chon2, i;
		do
		{
			system("cls");
			cout<<"\n\t\t\t----QUANLYTRANDAU----";
			cout<<"\n\t\t1.Nhap thong tin cac tran dau.";
			cout<<"\n\t\t2.Hien thi thong cac tran dau.";
			cout<<"\n\t\t3.Ket qua tran dau theo ngay.";
			cout<<"\n\t\t4.Ket qua tran dau theo thang.";
			cout<<"\n\t\t5.Ket qua tran dau cua ca giai.";
			cout<<"\n\t\t99.Thoat!";
			cout<<"\n\t\tLua chon: ";
			cin>>chon2;
			switch(chon2)
			{
				case 1:
				{
					system("cls");
					cout<<"\n\t\t-------INPUT-------"<<endl;
					cout<<"\nNhap so luong tran dau: ";
					cin>>n;
					for(i=0;i<n;i++){
						cout<<"\nTran dau thu "<<i+1;
						a[i]->nhap();
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
				break;
				case 2:
				{
					system("cls");
					cout<<"\n\t\t---------OUTPUT-----------"<<endl;
					cout<<setw(10)<<"NGAY-THANG-NAM"<<setw(25)<<"SANTHIDAU"<<setw(25)
					<<"DOI-H"<<setw(25)<<"DOI-A"<<setw(25)<<"TYSOTRANDAU"<<endl;
					for(i=0;i<n;i++){
						a[i]->xuat();
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
				break;
				case 3:
				{
					system("cls");
					cin.ignore();
					int Ngay, Thang, Nam;
					cout<<"\n\t\tKet qua tran dau theo ngay. ";
					cout<<"\nNhap ngay muon tra ket qua: ";
					cin>>Ngay;cout<<"/";
					cin>>Thang;cout<<"/";
					cin>>Nam;
					cout<<endl;
					cout<<setw(10)<<"NGAY-THANG-NAM"<<setw(25)<<"SANTHIDAU"<<setw(25)
					<<"DOI-H"<<setw(25)<<"DOI-A"<<setw(25)<<"TYSOTRANDAU"<<endl;
					for(i=0;i<n;i++){
						if(a[i]->getngay()== Ngay && a[i]->getthang() == Thang && a[i]->getnam() == Nam){
							a[i]->xuat();
						}
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
				break;
				case 4:
				{
					system("cls");
					cin.ignore();
					int Thang, Nam;
					cout<<"\n\t\t\tKet qua tran dau theo thang. ";
					cout<<"\nNhap ngay muon tra ket qua: ";
					cin>>Thang;cout<<"/";
					cin>>Nam;
					cout<<endl;
					cout<<setw(10)<<"NGAY-THANG-NAM"<<setw(25)<<"SANTHIDAU"<<setw(25)
					<<"DOI-H"<<setw(25)<<"DOI-A"<<setw(25)<<"TYSOTRANDAU"<<endl;
					for(i=0;i<n;i++){
						if(a[i]->getthang() == Thang && a[i]->getnam() == Nam){
							a[i]->xuat();
						}
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
				break;
				case 5:
				{
					system("cls");
					cout<<"\nKet qua cua ca giai dau."<<endl;
					cout<<setw(10)<<"NGAY-THANG-NAM"<<setw(25)<<"SANTHIDAU"<<setw(25)
					<<"DOI-H"<<setw(25)<<"DOI-A"<<setw(25)<<"TYSOTRANDAU"<<endl;
					for(i=0;i<n;i++){
						a[i]->xuat();
					}
					cout<<"\n\t\t---------FINISH----------";
					system("pause>pls");
				}
				break;
			default:
				break;	
			}
		}while(chon2!=99);
};
int main(){
	quanly * a[200];
	int luachon, i;
	do
	{
		system("cls");
		cout<<"\n\t\t\t--------MENUQUANLY----------";
		cout<<"\n\t\t1.Quan ly cau thu.";
		cout<<"\n\t\t2.Quan ly doi bong.";
		cout<<"\n\t\t3.Quan ly tran dau.";
		cout<<"\n\t\t99.Thoat!";
		cout<<"\n\t\tLua chon cua ban: ";
		cin>>luachon;
		switch(luachon)
			{
				case 1:
				{
					system("cls");
					for(i=0;i<200;i++){
						a[i]= new cauthu();
					}
					menuct(a,200);
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");
					for(i=0;i<200;i++){
						a[i]= new doibong();
					}
					menudb(a,200);
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");
					for(i=0;i<200;i++){
						a[i]= new trandau();
					}
					menutd(a,200);
					system("pause");
				}
				break;
			default:
				break;	
			}
	}while(luachon!=99);
	return 0;
}
