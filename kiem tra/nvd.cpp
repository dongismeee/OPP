#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class quatdien 
{
	private:
		char mahang[30];
		char tenhang[20];
		float dongia;
		float soluong;
	public:
		quatdien(char* mahang=" ", char* tenhang=" ", float dongia=0 ,float soluong=0)
		{
			strcmp(this->mahang,mahang);
			strcmp(this->tenhang,tenhang);
			this->dongia=dongia;
			this->soluong=soluong;
		};	
		~quatdien(){};
		friend istream& operator >>(istream & is, quatdien & qd);
		friend ostream& operator <<(ostream & os, quatdien qd);
		friend bool operator < (quatdien qd1 , quatdien qd2)
			{
			bool status = false ;
				if(qd1.dongia < qd2.dongia)
					{
					status = true;
					cout<<"\nQuat dien 1 dat hon quat dien 2";
					}
			return status;
			};
		float tien()
		{
			return ((dongia *soluong) + 0.1);
		};
		char* gettenhang()
		{
			return tenhang;
		}
		char* getmahang()
		{
			return mahang;
		} 		
};
istream& operator >>(istream & is, quatdien & qd)
{
	fflush(stdin);
	cout<<"\nNhap ma hang: ";
	is.getline(qd.mahang,30);
	cout<<"\nNhap ten hang: ";
	is.getline(qd.tenhang,20);
	cout<<"\nNhap don gia: ";
	is>>qd.dongia;
	cout<<"\nNhap so luong: ";
	is>>qd.soluong;
	return is;
};
ostream& operator <<(ostream & os, quatdien qd)
{
    os<<qd.mahang<<setw(15)<<qd.tenhang<<setw(15)<<qd.dongia<<setw(15)<<qd.soluong<<setw(15)<<qd.tien()<<endl;
    return os;
};
void doicho(quatdien &X, quatdien &Y)
{
	quatdien TG;
	TG =X;
	X = Y;
	Y = TG;
};
int menu()
{
    int c;
    system("cls");
    cout<<endl<<endl<<"                      CHUONG TRINH QUAN LY DIEU HOA"<<endl;
    cout<<"          *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
    cout<<"          ||      0 : Nhap danh sach.                             ||"<<endl;
    cout<<"          ||      1 : Hien thi toan bo danh sach sau khi sap xep. ||"<<endl;
    cout<<"          ||      2 : In thong tin doi tuong co tien tt nho 200.  ||"<<endl;
    cout<<"          ||      3 : Tim ds co ma hang QUATD 12345. Neu co xoa   ||"<<endl;
    cout<<"          ||          doi tuong do va xuat ds sau khi xoa         ||"<<endl;
    cout<<"          ||      4 : Tim trong ds co hang quat dien SENKO khong  ||"<<endl;
    cout<<"          ||          .Neu chua co chen doi tuong nay vao danh    ||"<<endl;
    cout<<"          ||          sach tai vi tri k nhap ban phim             ||"<<endl;
    cout<<"          ||      5 : In danh sach sau khi xoa                    ||"<<endl;
    cout<<"          ||      99 : Thoat.                                     ||"<<endl;
    cout<<"          *-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-*"<<endl<<endl;
    cout<<"Nhap su lua chon cua ban:";cin>>c;
    return c;
};
int main()
{
		quatdien *qd;
		int n;
		cout<<"\nNhap so quat dien can dien: ";
		cin>>n;
		qd = new quatdien[n];		
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
					cout<<"\nThong tin quat dien thu "<<i+1<<endl;
					cin>>qd[i];
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
								if(strcmp(qd[i].gettenhang(),qd[j].gettenhang())>0)
								{
									doicho(qd[i],qd[j]);
								}
							}
					}
					cout<<"\nDanh sach sau khi sap xep "<<endl;
					cout<<"Mahang"<<setw(15)<<"Tenhang"<<setw(15)<<"Dongia"<<setw(15)<<"Soluong"<<setw(15)<<"Tien"<<"VND"<<endl;
					for(int i=0;i<n;i++)
					{
						cout<<qd[i];
					}
					system("pause");
			}
					break; 
			case 2:
			{
				bool kt;
				kt = false;
				cout<<"\nThong tin quat dien co gia nho hon 200VND"<<endl;
				for(int i=0;i<n;i++)
				{
					if(qd[i].tien() > 1000)
					{
						kt = true;
						cout<<qd[i];
						cout<<endl;
					}
				}
				if(!kt)
				{
					cout<<"\nDanh sach khong co quat dien nao gia nho hon 200"<<endl;
				}
				system("pause");
			}
				break;
			case 3:
			{	
    
			   quatdien tkqd;
			   cout<<"\nNhap ma hang quat dien muon tim: ";
			   cin>>tkqd.getmahang();
			   bool kt1;
			   kt1 = false;
			   for(int i=0;i<n;i++)
			   {
						if(strcmp(tkqd.getmahang(),qd[i].getmahang())==0)
						{
							for(int k=0;k<n;k++)
							{
								n--;
								qd[k]=qd[k+1];
								kt1 =true;	
       						}
							cout<<"\nDanh sach sau khi xoa!!!"<<endl;
							for(int i=0;i<n;i++)
							{
							cout<<qd[i];
							cout<<endl;
							}	
						}
				}
				if(!kt1)
				{
					cout<<"\nMa hang ban tim kiem khong co trong ds ! "<<endl;
				} 
			   
				system("pause");		    	
			}		
					break;
			case 4:
			{   
				system("cls"); 
				quatdien qdtk;
				int pos;
				cout<<"\nNhap ten hang muon tim: ";
				cin>>qdtk.gettenhang();
				bool kt2;
				kt2 = false;
				for(int i=0;i<n;i++)
				{
					if(strcmp(qd[i].gettenhang(),qdtk.gettenhang())==0)
					{
						cout<<"\nThong tin nay co trong ds!"<<endl;
						kt2 = true;
					}
				}
				if(!kt2)
				{
					cout<<"\nTrong danh sach khong co hang SENKO !"<<endl;
					cout<<"\nVi tri can bo sung: "<<endl;
					cin>>pos;
					cout<<"\nThong tin can bo sung: "<<endl;
					cin>>qdtk;
					  	for(int i = n; i >= pos; i--)
						{
      						qd[i] = qd[i-1];
 			 			}
  							qd[pos] = qdtk;
		    				++n;
				}
				system("pause");
			}
			         break;
			case 5:
			{
				cout<<"\nDanh sach sau khi chen"<<endl;
				cout<<"Mahang"<<setw(15)<<"Tenhang"<<setw(15)<<"Dongia"<<setw(15)<<"Soluong"<<setw(15)<<"Tien"<<"VND"<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<qd[i];
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
	