#include<iostream>
#include<math.h>
using namespace std;
class phanso
{
	private:
		int t;
		int m;
	public:
		phanso(){
			this->t=0;
			this->m=1;
		};
		~phanso(){};
		void nhap()
		{
			cout<<"\nNhap tu so :";
			cin>>t;
			do{
				cout<<"\nNhap mau so:";
				cin>>m;
				if(m==0)
				cout<<"\nban da nhap sai so!!! :)";
				}while(m==0);
		};
		void in(){
			cout<<t<<"/"<<m<<endl;
		};
		phanso rutgonps(){
			int a,b;
			phanso ps;
				 ps.t=this->t;
				 ps.m=this->m;
				 
				 a=abs(ps.t);
				 b=abs(ps.m);
				 
				 if(a*b==0) return 1;
				 while(a!=b){
            		if(a>b) {a=a-b;}
        	       	else{b=b-a;}
    				}
    				ps.t=t/a;
    				ps.m=m/a;
    
    	return ps; 
		};
		phanso tong(phanso p){
			phanso tong;
				tong.t=(this->t*p.m) + (p.t * this->m);
				tong.m= this->m*p.m;
				return tong;
		};
		phanso tich(phanso p){
			phanso tich;
				tich.t=(this->t*p.t);
				tich.m=(this->m*p.m);
				return tich;
			};
		
};
int main(){
	phanso *P;
	int n;
	cout<<"\nNhap vao so doi tuong n= ";cin>>n;
	P = new phanso[n];
	phanso RG;
	
	cout<<"--------------Nhap cac phan so-------------- "<<endl;
	for(int i=0;i<n;i++){
		cout<<"\nNhap phan so thu "<<i+1<<": "<<endl;	
		P[i].nhap();
	}
	cout<<"--------------Hien thi cac phan so-------------- "<<endl;
	for(int i=0;i<n;i++){
		cout<<"\nPhan so thu "<<i+1<<": "<<endl;
		RG=P[i].rutgonps();
		RG.in();
	}
	//Tinh tong cac PS
	phanso KQ;
	KQ = P[0];
	for(int i = 1 ; i<n ; i++){
		KQ = KQ.tong(P[i]);	
	}	
	cout<<"\nTong cac phan so la:";
	KQ = KQ.rutgonps();
	KQ.in();
	
	//Tinh tich cac PS
	phanso KQ1;
	KQ1 = P[0];
	for(int i = 1 ; i<n ; i++){		
		KQ1= KQ1.tich(P[i]);	
	}
	cout<<"\nTich cac phan so la:";
	KQ1 = KQ1.rutgonps();
	KQ1.in();
	cout<<endl;
}