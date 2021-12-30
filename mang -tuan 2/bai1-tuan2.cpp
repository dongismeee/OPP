#include<iostream>
using namespace std;
class HCN
{
		private:
	  		float d,r;
 		public:
 			void nhap()
			 	{
		 		cout<<"nhap chieu dai: "; cin>>this->d;
		 		cout<<"nhap chieu rong: "; cin>>this->r;	
		 		}
			void inThongtin()
				{
				cout<<"("<<d<<","<<r<<")"<<endl;
				}
			float tinhchuvi()
				{
				return 2*(d+r);
				}
			float tinhdientich()
				{
					return (d*r);
				}
	
};
int main(){
		HCN *H;
		int n,i;
		fflush(stdin);
			cout<<"\nNhap so doi tuong n= ";
			cin>>n;
			H= new HCN[n];
		cout<<"\nNhap thong tin hinh chu nhat:"<<endl;
			for(i=0;i<n;i++)
	 			H[i].nhap();
	 	cout<<"\nIn thong tin hinh chu nhat:"<<endl;
		 	for(i=0;i<n;i++)
			 	H[i].inThongtin();
		//tim chu vi lon nhat cua hinh chu nhat	 		
 		float Maxcv;
		int chisocv;
			Maxcv = H[0].tinhchuvi();
			chisocv = 0;
		for(i=1;i<n;i++)
			if(Maxcv < H[i].tinhchuvi())
			{
				Maxcv = H[i].tinhchuvi();
				chisocv = i;
			}
		cout<<"\n\nHinh ch nhat co chu vi lon nhat la: ";
				H[chisocv].inThongtin();
		cout<<" co chu vi la "<<Maxcv<<endl;
		
//tim dien tich nho nhat cua hinh chu nhat
		float Mindt;
		int chisodt;
			Mindt = H[0].tinhdientich();
			chisodt = 0;
			for(i=1;i<n;i++)
				if(Mindt > H[i].tinhdientich())
					{
					Mindt = H[i].tinhdientich();
					chisodt = i;
					}
		cout<<"\n\nHinh ch nhat co dien tich nho nhat la: ";
			H[chisodt].inThongtin();
		cout<<" co dien tich la "<<Mindt<<endl;
	 	
		cout<<endl;
		return 0;	
}