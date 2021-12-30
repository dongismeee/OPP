#include<iostream>

using namespace std;

class Person{
	protected: 
		char name[30];
		char address[40];
		long int phone;
	public:
		Person(){
			
		}
		Person(char *name,char *address,long int dt){
			strcpy(name,name);
			strcpy(address,address);
			this->phone=phone;
	 	} 
	 	
	 	char * GetAdd(){
			 return address;
	 	}
};

class Officer: public Person{
	protected:
		float salary;
	public:
		Officer(){
			
		}
		Officer(char *name,char *address,long int phone,float salary): Person(name,address,phone){
			this->salary=salary;			
		}
};

class Manager:public Officer{
	private:
		float extra;
	public:
		Manager ()
		{
			
		}
		
		Manager(char *name,char *address,long int phone,float salary,float extra) : Officer(name,address,phone,salary){
			this->extra=extra;
		}
		
		void nhap(){
			cout<<"\n=============================\n";
			fflush(stdin);
			cout<<"\nName: ";gets(name);
			cout<<"\nAddress: ";gets(address);
			cout<<"\nPhone: ";cin>>phone;
			cout<<"\nSalary: ";cin>>salary;
			cout<<"\nExtra: ";cin>>extra;cout<<endl;
		}
		
		void xuat(){
			cout<<"\n=============================\n";
			cout<<"\nName: "<<name;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone: "<<phone;
			cout<<"\nSalary: "<<salary;
			cout<<"\nExtra: "<<extra<<endl;
		}
		bool operator !=( float a ){
			return salary != a ;
		}
};

int main(){
	int n,i;
	Manager *m = new Manager[n];
	do{
		cout<<"\n--Nhap vao so manager n= ";cin>>n;
	}
	while(n<0);
	
	for(i=0;i<n;i++){
		cout<<"\n-In thong tin manager "<<i+1<<endl;
		m[i].nhap();
	}
	for(i=0;i<n;i++){
		cout<<"\n-Nhap thong tin manager "<<i+1<<endl;
		m[i].xuat();
	}
	
	cout<<"\n Danh sach doi tuong can tim"<<"\n";
	for(int i=0;i<n;i++) { 
		if( (strcmpi(m[i].GetAdd(), "Ha Noi") == 0) && m[i]!= 10000000)
			m[i].xuat();
	}
}