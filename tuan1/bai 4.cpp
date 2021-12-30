#include<iostream>
using namespace std;
class vector{
	private:
	int a, b, c;
	public:
	 vector(int da=0, int db=0, int dc=0){
 		a=da;
 		b=db;
 		c=dc;
 	};
	 ~vector(){
 		
 	};
	 void nhap();
	 void in();
	 vector tong(vector v);
	
};
void vector::nhap(){
	cout<<"nhap toa do diem a: "<<endl;
	cin>>this->a;
	cout<<"nhap toa do diem b: "<<endl;
	cin>>this->b;
	cout<<"nhap toa do diem c: "<<endl;
	cin>>this->c;
	}
void vector::in(){
	cout<<"\n toa do cua vector da nhap la:("<<this->a<<","<<this->b<<","<<this->c<<")"<<endl;		
}
vector vector::tong(vector v){
	vector t;
	t.a=this->a+v.a;
	t.b=this->b+v.b;
	t.c=this->c+v.c;
	return t;
}
int main(){
	vector v1,v2,V;
	v1.nhap();
	v2.nhap();
	v1.in();
	v2.in();
	V=v1.tong(v2);
	cout<<"tong hai vector da nhap la:";
	V.in();
	return 0;
}