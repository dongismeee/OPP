#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
class ntn{
	private:
	 	int ngay;
	 	int thang;
	 	int nam;
	 public:
	 	friend istream& operator >>(istream & is, ntn & y){
	     cout<<"\nngay: ";
		 is>>y.ngay;	
		 cout<<"\nthang: ";
		 is>>y.thang;	
		 cout<<"\nnam: ";
		 is>>y.nam;
		 return is;
	 	};
	  	friend ostream& operator <<(ostream & os, ntn y){
	  		cout<<"\nNgay: "<<y.ngay;
	  		cout<<"\nthang: "<<y.thang;
	  		cout<<"\nNam: "<<y.nam;
	  		return os;
	  	};	
};
class nguoi{
	private: 
		string hoten;
		ntn ngaysinh;
		int tuoi;
	public:
		public:
		 friend istream& operator >>(istream & is, nguoi & x){
 			cout<<"\nHo ten: ";
 			getline(is, x.hoten);
 			cout<<"\nNhap ngay sinh: ";
			cin>>x.ngaysinh;
			cout<<"\nNhap tuoi: ";
			is>>x.tuoi;
			return is;	
	  		};	
	  	friend ostream& operator <<(ostream & os, nguoi x){
	  		cout<<"\nHo ten: "<<x.hoten;
	  		cout<<"\nNgay sinh: "<<x.ngaysinh;
	  		cout<<"\nTuoi: "<<x.tuoi;
	  		return os;
	  	};	
	  	void WriteFileMode(char* file_name)
		{
 		 if (file_name != NULL)
 		 {
   		 fstream data_file;
   	     data_file.open(file_name, ios::out);
   		 data_file <<hoten;
   		 data_file.close();
  		}
}

};
int main(){
	nguoi n1;
	cin>>n1;
	cout<<n1;
	n1.WriteFileMode("demo.txt");
	return 0;
}