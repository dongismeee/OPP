#include <iostream>
#include <vector>
using namespace std;
class Basic {
	protected:
		int thoiGianGoi;
		int donGiaGoi;
		int luuluong;
		int donGiaInternet;
	public:
		virtual int cuocDienThoai(){
			return thoiGianGoi * donGiaGoi;
		};
		virtual int cuocInternet(){
			return luuluong * donGiaInternet;
		};
		virtual void nhap(){
			cout<<"\nNhap thoi gian goi: ";
			cin>>thoiGianGoi;
			cout<<"\nNhap luu luong su dung: ";
			cin>>luuluong;
		};
		virtual void xuat(){
			cout<<"\n\t  Ten goi cuoc: Basic";
		};
		int cuocTong(){
				return 1.1 * (cuocDienThoai() + cuocInternet());
		};
		void suDung(int _thoiGianGoi, int _luuluong){
			thoiGianGoi += _thoiGianGoi;
			luuluong += _luuluong;
		};
		Basic(){
			thoiGianGoi=0;
			donGiaGoi=1000;
			donGiaInternet=200;
			luuluong=0;
		};
		virtual ~Basic(){
			
		};
};
class KhachHang {
		char hoten[30];
		char cmnd[20];
		char diachi[40];
		Basic *goiCuoc;
	public:
		KhachHang(){
		};
		~KhachHang(){
			delete goiCuoc;
		};
		void nhap(){
			cin.ignore(1);
			cout<<"\nNhap ho ten: ";
			cin.getline(hoten, 30);
			cout<<"\nNhap dia chi: ";
			cin.getline(diachi, 40);
			cout<<"\nNhap can cuoc cong dan: ";
			cin.getline(cmnd, 20);
			int c;
			cout << " - Nhap thong tin goi cuoc:\nChon loai goi cuoc (0: Basic, 1: DataFree, 2:DataFix): ";
			cin >> c;
			if (c == 0)
			goiCuoc = new Basic;
			else if (c == 1)
			goiCuoc = new DataFree;
			else
			goiCuoc = new DataFix;
			goiCuoc->nhap();
		};
		void xuat(){
			cout<<"\nHo ten: "<<hoten;
			cout<<"\nDia Chi: "<<diachi;
			cout<<"\nCan cuoc cong dan: "<<cmnd;
			goiCuoc->xuat();
		};
		int tinhCuocCuoithang(){
			return goiCuoc->cuocTong();
		};
		void suDung(int thoiGianGoi, int luuluong) {
	  		goiCuoc->suDung(thoiGianGoi, luuluong);
     	}
};
class DataFix: public Basic {
	public:
			int cuocDienThoai(){
				return ( Basic::cuocDienThoai() * 0.9 );
			}
			int cuocInternet(){
				return 1000000;
			};
			void xuat(){
				cout<<"\n\t Ten goi cuoc: DataFix";
			};
			int cuocTong(){
				return 1.1 * (cuocDienThoai() + cuocInternet());
		};
			~DataFix(){
			};
};
class DataFree:public Basic {
	protected:
		int cuocThueBao;
		int NguongMp;
	public:
		DataFree(){
			cuocThueBao=0;
			NguongMp=0;
		};
		int cuocInternet(){
			if(luuluong < NguongMp )
				return cuocThueBao;
			else
				return cuocThueBao +  (luuluong - NguongMp)*200;
		};
		void nhap(){
			Basic::nhap();
			cout<<"\nNhap cuoc thue bao: ";
			cin>>cuocThueBao;
			cout<<"\nNhap nguong luu luong mien phi: ";
			cin>>NguongMp;
		};
		int cuocTong(){
				return 1.1 * (Basic::cuocDienThoai() + cuocInternet());
		};
		void xuat(){
			cout<<"\n\t Ten goi cuoc: DataFree";
		};
		~DataFree(){
		};
};


class DanhSachHopDong {
	private:
		vector <KhachHang*> dsKhachHang;
	public:
		DanhSachHopDong(){	
		};
		~DanhSachHopDong(){
			for (int i = 0; i < dsKhachHang.size(); i++)
				delete dsKhachHang[i];
		};
		void dangKy(){
			int n;
			long int tong=0;
			cout << "Nhap so luong khach hang: ";
			cin >> n;
			dsKhachHang.resize(n);
			for (int i = 0; i < n; i++) {
			cout << "Nhap thong tin khach hang thu " << i + 1 << ":\n";
			dsKhachHang[i] = new KhachHang;
			dsKhachHang[i]->nhap();
			}
		};
		void thongBaoTienCuoc() {
			cout<<"\n \tTHONG BAO CUOC CUOI THANG"<<endl;
			cout << "So luong hop dong: " << dsKhachHang.size() << endl;
			for (int i = 0; i < dsKhachHang.size(); i++) {
			cout << "- Thong tin hop dong thu " << i + 1 << ":\n";
			dsKhachHang[i]->xuat();
			cout << endl;
			cout << "\t Tien cuoc cuoi thang: " << dsKhachHang[i]->tinhCuocCuoithang() <<endl;
			}
		};
}; 
int main(){
	DanhSachHopDong a;
		a.dangKy();
		cout<<endl;
		a.thongBaoTienCuoc();
		return 0;
}