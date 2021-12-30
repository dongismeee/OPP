#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class quay {
	private: 
		int sothutu;
		int dientich;
	protected:
		double doanhthu;
		virtual double tinhThueDoanhThu() =0;
		virtual double tinhTienDichVu(){
			return 0;
		}
		double tinhtienThueQuay(){
			return 40000000 * dientich;
		}	
	public:
		virtual double tinhtienPhaiDong(){
			return tinhTienDichVu() + tinhtienThueQuay() + tinhThueDoanhThu();
		}
		virtual void nhap(){
			cout<<"\nNhap so thu tu : ";
			cin>>sothutu;
			cout<<"\nNhap dien tich: ";
			cin>>dientich;
			cout<<"\nNhap doanh thu: ";
			cin>>doanhthu; 
		}
		virtual void xuat(){
			cout<<"\nSo thu tu: "<<sothutu;
			cout<<"\nDien tich: "<<dientich;
			cout<<"\nDoanh thu: "<<doanhthu;
		}	
		virtual int check() =0;
		int getDt(){
			return dientich;
		}
};
class quayquanao:public quay
{
	protected: 
		double tinhThueDoanhThu(){
			return doanhthu * 0.1;
		};
		double tinhtienPhaiDong()
		{
			return tinhThueDoanhThu() + tinhtienThueQuay();
		};
		void nhap(){
			cout<<"\n\t Quay quan ao";
			quay::nhap();
		}
		void xuat(){
			quay::xuat();
			cout<<"\nTien thue Doanh Thu: "<<quayquanao::tinhThueDoanhThu();
			cout<<"\nTien phai dong: "<<quayquanao::tinhtienPhaiDong();
		}
		int check(){
			return 1;
		}
};
class quaythucpham:public quay {
	private: 
		 int tienDichVu;
	protected:
		double tinhThueDoanhThu(){
			return doanhthu * 0.05;
		};
		double tinhTienDichVu(){
			return tienDichVu;
		};
		double tinhtienPhaiDong(){
			return tinhThueDoanhThu() + tinhTienDichVu() + tinhtienThueQuay();
		};
		void nhap(){
			quay::nhap();
			cout<<"\nNhap tien dich vu: ";
			cin>>tienDichVu;
		}
		void xuat(){
			quay::xuat();
			cout<<"\nTien dich vu: "<<tienDichVu;
			cout<<"\nTien thue doanh thu: "<<quaythucpham::tinhThueDoanhThu();
			cout<<"\nTien phai dong: "<<quaythucpham::tinhtienPhaiDong();
		}
		int check(){
			return 2;
		}	 
};
class quaytrangsuc:public quay
{
	protected:
		double tinhThueDoanhThu(){
			if(doanhthu	 < 100000000){
				return doanhthu * 0.2;
			}
			else if(doanhthu >= 100000000){
				return doanhthu * 0.3;
			}
		};
		double tinhtienPhaiDong(){
			return tinhThueDoanhThu() + tinhtienThueQuay();
		};
		void nhap(){
			quay::nhap();
		};
		void xuat(){
			quay::xuat();
			cout<<"\nTien thue doanh thu: "<<quaytrangsuc::tinhThueDoanhThu();
			cout<<"\nTien phai dong: "<<quaytrangsuc::tinhtienPhaiDong();
		};
		int check(){
			return 3;
		}
};
class sieuthi {
	private:
		vector <quay*> dsQuay;
	public:	
		void Nhap(){
			quay *q;
			int LuaChon;
	
			do
			{
				system("cls");
				cout<<"\n\t\t\t*******QUAY*********";
				cout<<"\n\t\t\t1.Quay quan ao.";
				cout<<"\n\t\t\t2.Quay thuc pham.";
				cout<<"\n\t\t\t3.Quay trang suc.";
				cout<<"\n\t\t\t99.Thoat!";
				cout<<"\n\t\t\t Lua chon!";
				cin>>LuaChon;
				switch(LuaChon)
					{
						case 1:
						{
							q = new quayquanao;
							q->nhap();
							dsQuay.push_back(q);
							cout<<"\nDa Nhap Xong!";
							system("pause>pls");
						}
						break;
						case 2:
						{
							q =new quaythucpham;
							q->nhap();
							dsQuay.push_back(q);
							cout<<"\nDa Nhap Xong!";
							system("pause>pls");
						}
						break;
						case 3:
						{
							q =new quaytrangsuc;
							q->nhap();
							dsQuay.push_back(q);
							cout<<"\nDa Nhap Xong!";
							system("pause>pls");
						}
						break;
				default :
						break;
				}
			}
			while(LuaChon !=99);
		};
		void Xuat(){
			cout<<"\n\t\t\tDanh Sach Quay Trong Sieu Thi";
			for(int i=0;i< dsQuay.size();i++)
			{
			dsQuay[i]->xuat();
			}
		};
		double tinhTongsoTien(){
			 double tong = 0;
			for(int i =0;i < dsQuay.size();i++){
				tong += dsQuay[i]->tinhtienPhaiDong();
			}
			return tong;
		};
		int ThongkeSL(){
			
		};
};
int main(){
	sieuthi a;
	int n;
		cout<<"\nNhap so luong sap: ";
		cin>>n;
		a.Nhap();
		cout<<"\n\t\tThong tin cac quay hang"<<endl;
		a.Xuat();
		cout<<endl;
		cout<<"\n\tTong so tien phai dong cua cac quay la: ";
		cout<<setprecision(10);
		cout<<a.tinhTongsoTien();
		cout<<endl;
		cout<<"\n\t Thong ke so luong cac quay hang";
		a.ThongkeSL();
		cout<<endl;
		return 0;
}