#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
class dieuhoa
{
	private:
		char mahang[30];
		char tenhang[20];
		char nuocnk[20];
		float dongia;
		float congsuat;
	public:
		dieuhoa(char* mahang=" ", char* tenhang=" ", char* nuocnk=" ", float dongia=0 ,float congsuat=0)
		{
			strcmp(this->mahang,mahang);
			strcmp(this->tenhang,tenhang);
			strcmp(this->nuocnk,nuocnk);
			this->dongia=dongia;
			this->congsuat=congsuat;
		};	
		~dieuhoa(){};
		friend istream& operator >>(istream & is, dieuhoa & dh);
		friend ostream& operator <<(ostream & os, dieuhoa dh);
		friend bool operator < (dieuhoa dh1 , dieuhoa dh2)
			{
			bool status = false ;
				if(dh1.dongia < dh2.dongia)
					{
					status = true;
					cout<<"\nDieu hoa 1 dat hon dieu hoa 2";
					}
			return status;
			};
		float tien()
		{
			if(congsuat <= 18000)
			{
				return (dongia * (0.2 * this->dongia) + (0.1 * this->dongia));
			}
			else if(this->congsuat > 18000)
			{
				return (this->dongia * (0.4 * this->dongia) + (0.1 * this->dongia));
			}
		};
		char* getnuocnk()
		{
			return nuocnk; 
		}
		char* gettenhang()
		{
			return tenhang;
		} 
		
};
istream& operator >>(istream & is, dieuhoa & dh)
{
	fflush(stdin);
	cout<<"\nNhap ma hang: ";
	is.getline(dh.mahang,30);
	cout<<"\nNhap ten hang: ";
	is.getline(dh.tenhang,20);
	cout<<"\nNhap nuoc nhap khau: ";
	is.getline(dh.nuocnk,20);
	cout<<"\nNhap don gia: ";
	is>>dh.dongia;
	cout<<"\nNhap cong suat: ";
	is>>dh.congsuat;
	return is;
};
ostream& operator <<(ostream & os, dieuhoa dh)
{
    os<<dh.mahang<<setw(15)<<dh.tenhang<<setw(15)<<dh.nuocnk<<setw(15)<<dh.dongia<<setw(15)<<dh.congsuat<<setw(15)<<dh.tien()<<endl;
    return os;
};
void doicho(dieuhoa &X, dieuhoa &Y)
{
	dieuhoa TG;
	TG =X;
	X = Y;
	Y = TG;
}
int menu()
{
	
    int c;
    system("cls");
    cout<<endl<<endl<<"                      CHUONG TRINH QUAN LY DIEU HOA"<<endl;
    cout<<"          *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
    cout<<"          ||      0 : Nhap danh sach.                             ||"<<endl;
    cout<<"          ||      1 : Hien thi toan bo danh sach sau khi sap xep. ||"<<endl;
    cout<<"          ||      2 : In thong tin doi tuong co tien tt (>1000).  ||"<<endl;
    cout<<"          ||      3 : Tim hang panasonic. Neu chua co chen doi    ||"<<endl;
    cout<<"          ||          tuong do vao danh sach tai vi tri k nhap tu ||"<<endl;
    cout<<"          ||          ban phim. Sau do xuat ds sau khi chen       ||"<<endl;
    cout<<"          ||      4 : Tim trong ds dieu hoa nhap khau tu Thai lan ||"<<endl;
    cout<<"          ||          Neu co xoa khoi ds va in ds sau khi xoa     ||"<<endl;
    cout<<"          ||      99 : Thoat.                                     ||"<<endl;
    cout<<"          *-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-*"<<endl<<endl;
    cout<<"Nhap su lua chon cua ban:";cin>>c;
    return c;
};
int main()
{       system("color 90");
		dieuhoa *dh;
		int n;
		cout<<"\nNhap so dieu hoa can dien: ";
		cin>>n;
		dh = new dieuhoa[n];		
	int chon;
	do 
	{
		chon=menu();
		switch(chon)
		{
		case 99 : return 99;
			case 0:
			{    
				system("cls");
				for(int i=0;i<n;i++)
					{
					cout<<"\nThong tin dieu hoa thu "<<i+1<<endl;
					cin>>dh[i];
					cout<<endl;
					}
	   		}
		 			break;	
			case 1:
			{
				system("cls");
				for(int i=0;i<n;i++)
					{
							for(int j=i+1;j<n;j++)
							{
								if(strcmp(dh[i].getnuocnk(),dh[j].getnuocnk())>0)
								{
									doicho(dh[i],dh[j]);
								}
							}
					}
					cout<<"\nDanh sach sau khi sap xep "<<endl;
					cout<<"Mahang"<<setw(15)<<"Tenhang"<<setw(15)<<"Nuoc_nk"<<setw(15)<<"Dongia"<<setw(15)<<"Congsuat"<<setw(15)<<"Tien"<<endl;
					for(int i=0;i<n;i++)
					{
						cout<<dh[i];
					}
					system("pause");
			}
					break; 
			case 2:
			{
				bool kt;
				kt = false;
				cout<<"\nThong tin dieu gia co gia hon 1000$"<<endl;
				for(int i=0;i<n;i++)
				{
					if(dh[i].tien() > 1000)
					{
						kt = true;
						cout<<dh[i];
						cout<<endl;
					}
				}
				if(!kt)
				{
					cout<<"\nDanh sach khong co dieu hoa 1000$"<<endl;
				}
				system("pause");
			}
				break;
			case 3:
			{
			   dieuhoa tkdh;
			   int pos;
			   cout<<"\nNhap ten hang dieu hoa muon tim: ";
			   cin>>tkdh.gettenhang();
			   bool kt1;
			   kt1 = false;
			   for(int i=0;i<n;i++)
			   {
   				if(strcmp(tkdh.gettenhang(), dh[i].gettenhang())==0)
      				{
				   	 cout<<"\nThong tin co trong ds !"<<endl;
				   	 kt1 = true;
				   	}   	
	     	   }
	    	   if(!kt1)
				{
				 	cout<<"\nThong tin dh khong co trong danh sach !";
					cout<<"\nVi tri can bo sung: "<<endl;
					cin>>pos;
					cout<<"\nThong tin can bo sung: "<<endl;
					cin>>tkdh;
					for(int i = n; i >= pos; i--){
      				dh[i] = dh[i-1];
 			 		}
  					dh[pos] = tkdh;
		    		++n;
					cout<<"\nDanh sach sau khi bo sung la: "<<endl;
					for(int i=0;i<n;i++)
					{
						cout<<dh[i];
						cout<<endl;
					}
				}
				system("pause");		    	
			}		
					break;
			case 4:
			{
				system("cls");
				bool kt2;
				kt2 = false;
				for(int i=0;i<n;i++)
				{
					if(strcmp(dh[i].getnuocnk(),"thailan")==0)
					{
						for(int k=0;k<n;k++)
						{
							n--;
							dh[k]=dh[k+1];
							kt2 = true;
						}
						cout<<"\nDanh sach sau khi xoa!"<<endl;
						for(int i=0;i<n;i++)
						{
							cout<<dh[i];
							cout<<endl;
						}
						
					}
				}
				if(!kt2)
				{
					cout<<"\nTrong danh sach khong co dieu hoa nhap khau tu Thai Lan !"<<endl;
				}
				system("pause");
			}
			         break;
		default:
		 		break;				
		}
	}
	while(chon!=99);
	return 0;
	cout<<endl;
}
	