#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class lop 
{
	private:
		string tenmonhoc;
		int sotiet;
	public:
		lop()
		{
			tenmonhoc=" ";
			sotiet=0;
		};
		lop(string tenmonhoc, int sotiet){
			this->tenmonhoc=tenmonhoc;
			this->sotiet=sotiet;
		} 
		~lop(){
		};
		void nhap(){
			fflush(stdin);
			cout<<"\n\tNhap ten mon hoc: ";
			getline(cin , tenmonhoc);
			cout<<"\n\tNhap so tiet hoc: ";
			cin>>sotiet;
		};
		void display(ostream & os){
			os<<"\n\tMon hoc: "<<tenmonhoc;
			os<<"\n\tSo tiet: "<<sotiet;
		};	
};
class nguoi
{
	private:
		string hoten;
		int namsinh;
	public:
		nguoi(){
			hoten="";
			namsinh=0;
		};
		nguoi(string hoten, int namsinh){
			this->hoten=hoten;
			this->namsinh=namsinh;
		};
		~nguoi(){
		};
		void nhap(){
			fflush(stdin);
			cout<<"\n\tNhap ho ten: ";
			getline(cin, hoten);
			cout<<"\n\tNhap nam sinh: ";
			cin>>namsinh;	
		};
		void display(ostream & os){
			os<<"\n\tHo ten: "<<hoten;
			os<<"\n\tNamsinh: "<<namsinh;
		};		
};
class giaovien:public lop , public nguoi
{
	private:
		string bomon;
	public:
		giaovien(){
			bomon="";
		};
		giaovien(string bomon){
			this->bomon=bomon;
		};
		~giaovien(){	
		};
		void nhap(){
			lop::nhap();
			nguoi::nhap();
			fflush(stdin);
			cout<<"\n\tNhap ten bo mon: ";
			getline(cin, bomon);
		};
		void display(ostream & os){
			lop::display(os);
			nguoi::display(os);
			fflush(stdin);
			os<<"\n\tBo mon: "<<bomon;
		};	
};
int main(){
	giaovien gv1;
	gv1.nhap();
	ofstream outfile;
	outfile.open("demo.txt");
	gv1.display(outfile);
	outfile.close();
	return 0;
}