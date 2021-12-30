#include <iostream.h>
#include <iomanip.h>
#include <string>

class maytinh 
{
	private:
	  char mahang[30];
	  char tenhang[30];
	  float dongia;
   	  float	ram;
	  float trongluong;
	public:
	  maytinh();
	  maytinh(char *mathang, char *tenhang, float dongia ,float ram ,float trongluong)
	  {
  		strcmp(this->mahang,mathang);
  		strcmp(this->tenhang,tenhang);
  		this->dongia = dongia;
  		this->ram = ram;
  		this->trongluong = trongluong;
  	  };
	  ~maytinh()
	  	{
  		
  		};
	  friend istream& operator >>(istream & is ,maytinh &);
	  friend ostream& operator <<(ostream & os ,maytinh);
	  float tienvanchuyen()
	  {
		if(this->trongluong > 2){
			return 100000;	
		}
		else if(this->trongluong > 1){
			return 50000;
		}
		else{
			return 30000;
		}		   	
  		};
	  float getram()
	  	{
  		return ram;
  		};
	  char *gettenhang()
	  	{
  		return tenhang;
  		};		  		  
};
maytinh::maytinh(){
		this->mahang[30]=' ';
		this->tenhang[30]=' ';
		this->dongia=0;
		this->ram=0;
		this->trongluong=0;
}
istream& operator >>(istream & is ,maytinh & mt)
{
	fflush(stdin);
	cout<<"\nNhap ma hang:";
	is.getline(mt.mahang,30);
	cout<<"\nNhap ten hang mt: ";
	is.getline(mt.tenhang,30); 
	fflush(stdin);
	cout<<"\nNhap don gia: ";
	is>>mt.dongia;
	cout<<"\nNhap dung luong RAM: ";
	is>>mt.ram;
	cout<<"\nNhap trong luong may: ";
	is>>mt.trongluong;
	return is;
};
ostream& operator <<(ostream & os , maytinh mt)
{
	os<<"mahang"<<setw(15)<<"tenhang"<<setw(15)<<"dongia"<<setw(15)<<"RAM"<<setw(15)<<"trongluong"<<setw(20)<<"tien van chuyen"<<endl;
	os<<mt.mahang<<setw(15)<<mt.tenhang<<setw(15)<<mt.dongia<<setw(18)<<mt.ram<<setw(15)<<mt.trongluong<<setw(15)<<mt.tienvanchuyen()<<"VND"<<endl;
	return os;
};
int main()
{	

	maytinh *mt; 
	int n;
	cout<<"\nNhap so may tinh: ";
	cin>>n;
	mt = new maytinh[n];
	for(int i=0;i<n ;i++)
	{
		cout<<"\nThong tin may thu "<<i+1<<endl;
		cin>>mt[i];
		cout<<"\n_________________________________________"<<endl;
	}
	
    
    bool kt1;
    kt1=false;
    int chiso;
    for(int i=0;i<n;i++)
	{
		cout<<"\nDanh sach mt co RAM 16GB la: "<<endl;	
		if(mt[i].getram()>=16 )
		{
			kt1=true;
			chiso =i;
			cout<<mt[i];
		}
	}
	if(!kt1)
	        cout<<"\nKhong co may tinh duoi 16GB ram!"<<endl;
	//tim kiem hang sony        
	maytinh sony;
	cout<<"\nNhap vao may tinh muon tim:";
	cin>>sony.gettenhang();
	bool kt;
	kt = false;
	for(int i= 0;i<n;i++)
	{
		if(strcmp(sony.gettenhang(),mt[i].gettenhang())==0)
		{
			   
			    for(int k= 0;k<n;k++){
				mt[k]=mt[k+1];
				kt =true;
				n--;	
			}
			
			for(int i=0;i<n;i++)
			{
		    cout<<mt[i];
			cout<<endl;	
			}	
		}
	}
	if(!kt){
		cout<<"\nKhong co hang sony trong danh sach:"<<endl;
		cout<<"\nChen them 1 may tinh co hang sony: "<<endl;
		cin>>sony;
		for(int i=n-1;i>0;i--){
			mt[i]=mt[i-1];	
		}
		n++;
		mt[0]=sony;
		
	cout<<"\nDanh sach sau khi chen:"<<endl;
	for(int i=0;i<n-1;i++){
		cout<<mt[i];
		cout<<endl;
	}
	}		
	cout<<endl;
	return 0;
}
