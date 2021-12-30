#include<iostream>
#include<string>
using namespace std;
class nguoi{
	protected:
		string name;
		string address;
		float phone;
	public:
		nguoi(){
			name="";
			address="";
			phone=0;
		};
		nguoi(string name, string address, float phone){
			this->name=name;
			this->address=address;
			this->phone=phone;
		};	
};
class officer:public nguoi {
	protected:
		int salary;
	public:
		officer(){
			salary=0;
		};
		officer(string name, string address, float phone, int salary): nguoi(name, address, phone){
			this->salary=salary;
		};
		bool operator !=( float a ){
			return salary != a ;
		};
		string getadd(){
			return address;
		}
};
class manager:public officer {
	private:
		float extra;
	public:
		manager(){
			extra=0;
		};
		manager(string name, string address	, float phone, int salary, float extra) : officer(name,address,phone,salary)
		{
			this->extra=extra;
		};
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ten: ";
			getline(cin ,name);
			cout<<"\nNhap dia chi: ";
			getline(cin ,address);
			cout<<"\nNhap so dien thoai: ";
			cin>>phone;
			cout<<"\nNhap luong: ";
			cin>>salary;
			cout<<"\nNhap Extra: ";
			cin>>extra;
		};
		void xuat(){
			cout<<"\nName: "<<name;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone: "<<phone;
			cout<<"\nSalary: "<<salary;
			cout<<"\nExtra: "<<extra;
		};
		bool Kt()
			{
			if( getadd(), "Ha Noi" == 0)
			return 1;
			return 0;
			}
		
};
int main()
{
	manager *m;
	int n,i;
	m = new manager[n];
	cout<<"\n--Nhap vao so manager n= ";cin>>n;
	for(i=0;i<n;i++){
		cout<<"\n-In thong tin manager "<<i+1<<endl;
		m[i].nhap();
	}
	for(i=0;i<n;i++){
		cout<<"\n-Nhap thong tin manager "<<i+1<<endl;
		m[i].xuat();
	}
	
	cout<<"\n Danh sach doi tuong can tim"<<"\n";
	for(int i=0;i<n;i++)
	 { 
		if( m[i].getadd() == "HaNoi" && m[i] != 10000000)
			{
			m[i].xuat();
	     	}
	 } 
	 return 0;
}