#include<iostream.h>
#include<iomanip.h>
using namespace std;

class NGUOI{
	private:
		char ht[30],nghe[50],qt[30];
		int t;
		
	public:
		void NGUOI :: nhap(){
		fflush(stdin);
		cout<<"\nNhap vao ho ten: ";cin.getline(ht,30);
		cout<<"\nNhap vao nghe: ";cin.getline(nghe,30);
		cout<<"\nNhap vao quoc tich: ";cin.getline(qt,30);
		cout<<"\nNhap vao tuoi: ";cin>>t; 
		
	}
	
	void NGUOI :: xuat(){
		cout<<"\nHo ten: "<<ht; 
		cout<<"\nNghe nghiep: "<<nghe;
		cout<<"\nQuoc tich: "<<qt; 
		cout<<"\nTuoi: "<<t; 
	}
	
	char *getnghe(){
		return nghe;
	}
	char *getht(){
		return ht;
	}
	int gett(){
			return t;
		};		
};
void doicho(NGUOI &X,NGUOI &Y){
		NGUOI TG;
		TG=X;
		X=Y;
		Y=TG;
	}
			
int main(){
	NGUOI *A;
	NGUOI ldn;
	int i,j,n;
	cout<<"-Nhap so nguoi: ";cin>>n;
	A=new NGUOI[n];
	cout<<"-Danh sach nguoi: ";
	for(i=0;i<n;i++){
		cout<<endl;
		cout<<"-Nhap thong tin nguoi thu "<<i+1<<endl;
		A[i].nhap();
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(A[i].getht(),A[j].getht())>0){
				doicho(A[i],A[j]);
			}
		}
	}
	cout<<"\n__________________________________________"<<endl;
	cout<<"\n- Danh sach nguoi sau khi sap xep la: "<<endl;
	for(i=0;i<n;i++){
		A[i].xuat();
	}
	cout<<"\n__________________END______________________"<<endl;
	cout<<endl;
	
bool kt1=false;
	for(i=0;i<n;i++){
		if(strcmp("bac si",A[i].getnghe())==0){
			cout<<"-Thong tin ve nguoi la bac si la:";
			A[i].xuat();
			cout<<"\n__________________END______________________"<<endl;
			kt1=true;
		}
	}
	if(!kt1){
		cout<<"-Khong co nguoi lam bac si trong danh sach!"<<endl;
		cout<<"\n__________________END______________________"<<endl; 
	}
	//kiem tra nguoi co quoc tich campuchia
	bool kt2=false;
	for(i=0;i<n;i++){
		if(strcmp("Campuchia",A[i].getht())==0){
			n--;
			for(int k=0;k<n;k++)
			A[k]=A[k+1];
			kt2=true;
			for(i=0;i<n;i++)
	      	{
		   		A[i].xuat();
		   		cout<<endl;
	      	}
		}
	}
	if(!kt2){
		cout<<"\n-Khong co nguoi thuoc quoc tich campuchia trong danh sach"<<endl;
		cout<<"\n__________________END______________________"<<endl;
	}
	bool kt3=false;
	for(i=0;i<n;i++)
		{
	    	if(strcmp("Le Dai Nghia",A[i].getht())==0)
				{
				kt3=true;	
				}
		}
            if(!kt3){
				cout<<"\n-Khong co ai ten Le Dai Nghia"<<endl;
				cout<<"\n-Nhap ho ten nguoi can chen"<<endl;
				ldn.nhap();
	   		for(int i=0 ;i<n;i++)
			{
				A[n]=ldn;
			}
            }
			cout<<"\------------Danh sach sau khi chen -----------------";
	       	for(i=0;i<=n;i++){
			A[i].xuat();
	}
 	//in nguoi cao tuoi va thap tuoi nhat 
        float Maxt;
    	int chiso = 0;
		Maxt = A[0].gett();
		for(int i = 1;i<=n;i++)
			{
					if(Maxt < A[i].gett())
					{  
						Maxt = A[i].gett();
						chiso = i;
					}
			}   
				cout<<"\n__________________END______________________"<<endl;
			    cout<<"-Nguoi cao tuoi nhat:"<<endl;
				A[chiso].xuat();	
				cout<<"\n__________________END______________________"<<endl;
		//in thong tin nguoi thao tuoi nhat nhom
	float Mint;
		int chisoduoi = 0 ;
		Mint =A[0].gett();
		for(int i=1;i<=n;i++)
		{
			if(Mint > A[i].gett())
			{
				Mint=A[i].gett();
				chisoduoi = i;	
			}
		}
		        
				cout<<"\n__________________END______________________"<<endl;
				cout<<"-Nguoi thap tuoi nhat la"<<endl;
				A[chisoduoi].xuat();
				cout<<"\n__________________END______________________"<<endl;				
	cout<<endl; 
	return 0;
} 