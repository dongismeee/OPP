#include <iostream>
#include <string>
using namespace std;
class anpham
{
	protected:
		string ten;
		float giathanh;
	public:
		string getten(){
			return ten;
		}
		anpham()
		{
			ten="";
			giathanh=0;
		}
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ten: ";
			cin>>ten;
			cout<<"\nNhap gia thanh: ";
			cin>>giathanh;
		}		
		void xuat(){
			cout<<"\nTen: "<<ten<<endl;
			cout<<"\nGia thanh: "<<giathanh<<endl;
		}
};
class sach:public anpham
{
	protected:
		int sotrang;
	public:
		int getst(){
			return sotrang;
		}
		sach(){
			sotrang=0;
		}	
		void nhap(){
			anpham::nhap();
			fflush(stdin);
			cout<<"\nNhap so trang: ";
			cin>>sotrang;
        };
        void xuat(){
        		anpham::xuat();
	        	cout<<"\nSo trang: "<<sotrang;
        };
};
class diacd:public anpham
{
	private:
		int sophut;
	public:
		diacd(){
			sophut=0;
		}
		void nhap()
		{
		anpham::nhap();	
		cout<<"\nNhap so phut: ";
		cin>>sophut;
		};
		void xuat(){
		anpham::xuat();
		cout<<"\nSophut: "<<sophut<<endl;	
		}	
};
int menu()
{
	int i,n;
	int m;
	int chon;
	do{
		system("cls");
		cout<<"\n\t 1.Nhap thong tin ve sach"<<endl;
		cout<<"\n\t 2.Nhap thong ve dia cd"<<endl;
		cout<<"\n\t 3.thoat"<<endl;
		cout<<"\n\t Nhap su lua chon cua ban";
		cin>>chon;
			switch(chon)
		 	{
	 			case 1:
	 				{
				 		system("cls");
					 	sach a[50];
				 		cout<<"\nNhap so sach muon dien thong tin";
				 		cin>>n;
				 		for(i=0;i<n;i++)
				 		{
		 					cout<<"\nThong tin sach thu "<<i+1;
		 					a[i].nhap();
		 				}
		 				cout<<"\nDanh sach so sach co so trang lon hon 500"<<endl;
		 				for(i=0;i<n;i++)
		 				{
				 			if(a[i].getst()>500){
			 					a[i].xuat();
			 				}
				 		}
				 		system("pause");
				 	}
				 		break;
				 	case 2:
					 {
 						system("cls");
 						diacd A[50];
 						cout<<"\nNhap so dia cd muon dien thong tin";
 						cin>>m;
 						for(i=0;i<n;i++){
						 	cout<<"\nNhap thong tin dia cd thu "<<i+1;
						 	A[i].xuat();
					    }
			    		string tend;
					    cout<<"\nNhap ten dia cd muon tim:";
					    cin>>tend;
					    bool kt = false;
					    for(i=0;i<n;i++)
					    {
    						if(A[i].getten() == tend)
    						{
						    	A[i].xuat();
						    	kt =true;
						    }
    					}
    					system("pause");
		    	     }
					  	break;
				default:
						break;  	
	 		}		
	  } while(chon!=3);
}
int main()
{
	menu();
	system("pause");
	return 0;
}
