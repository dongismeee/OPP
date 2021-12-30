#include <iostream>

using namespace std;
class pet{
	protected:
		int tuoi;
		int can;
	public:
		pet(){
			this->tuoi=0;
			this->can=0;
		};
		pet(int tuoi, float cannang){
			tuoi=tuoi;
			cannang=cannang;
		}
		~pet(){
		};
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap so tuoi: ";
			cin>>tuoi;
			cout<<"\nNhap can nang: ";
			cin>>can;
		};
		void xuat(){
			cout<<"\nTuoi: "<<tuoi;
			cout<<"\nCan Nang: "<<can;
		};
		int getcan(){
			return can;
		};
		int gettuoi(){
			return tuoi;
		};		
};
class DOG : public pet{
	private: 
		char maumat[30];
		char sothich[50];
	public:
		DOG(){
			this->maumat[30]=' ';
			this->sothich[50]=' ';
		}
		DOG(int tuoi, float cannang,char *maumat, char *sothich) : pet(tuoi,can){
			strcpy(this->maumat,maumat);
			strcpy(this->sothich,sothich);
		}
		friend istream& operator >> (istream& is, DOG& d){
			d.pet::nhap();
			fflush(stdin);
			cout<<"\nNhap vao mau mat: ";is.getline(d.maumat,30);
			cout<<"\nNhap vao so thich: ";is.getline(d.sothich,50);
			return is;
		}
		friend ostream& operator << (ostream& os, DOG& d){
			d.pet::xuat();
			os<<"\nMau mat: "<<d.maumat;
			os<<"\nSo thich: "<<d.sothich;
			return os;	
		}
		
};
int main(){
	int n, i;
	DOG * a;
	a = new DOG[n];
	cout<<"\nNhap so dog: ";
	cin>>n;
	cout<<endl;
	cout<<"\n\tDanh sach nhap";
	for(i=0;i<n;i++){
		cout<<"\nNhap thong tin dog thu "<<i+1;
		cin>>a[i];
	};
	cout<<"\n\tDanh sach Dog sau khi nhap";
	for(i=0;i<n;i++){
		cout<<"\n\tThong tin Dog thu "<<i+1;
		cout<<a[i];
	};
	cout<<endl;
	int j;
	cout<<"\n-------Danh sach DOG theo chieu tang dan cua can nang-------";
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(a[j].getcan() > a[i].getcan()){
				DOG tg=a[i]; 
				a[i]=a[j];
				a[j]=tg;
			}	
		}
	}
	for(i=0;i<n;i++){
		cout<<"\nIn thong tin DOG thu "<<i+1<<endl;
		cout<<a[i];
	}
	
	cout<<endl;
	cout<<"\n-------Danh sach DOG co tuoi tu 2 den 5-------";
	for(i=0;i<n;i++){
		if(a[i].gettuoi()<=5 && a[i].gettuoi()>=2){
			cout<<"\nIn thong tin DOG thu "<<i+1<<endl;
			cout<<a[i];
		}	
	}
	cout<<"\nTong can nang cua cac con DOG = ";
	float x = a[0].getcan();
	x = 0;
	for(i=0;i<n;i++){
		x += a[i].getcan();	
	}
	cout<<x;
	cout<<endl;
}
	
