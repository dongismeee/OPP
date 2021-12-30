#include <iostream>
using namespace std;
class dathuc2{
	private:
	 	int a, b, c;
	public:
		dathuc2(int da=0,int db=0,int dc=0) {
			a=da ;
			b=db ;
			c=dc ; 
		}
		~dathuc2(){
			
		}	
		void in();
		dathuc2 tong(dathuc2 d);
		
};
void dathuc2::in()
	{
	cout<<a<<"x^2 + "<<b<<"x + "<<c;
							
}
dathuc2 dathuc2::tong(dathuc2 d)
{
	dathuc2 t;
	t.a=a+d.a;
	t.b=b+d.b;
	t.c=c+d.c;
	return t;
}
int main(){
	dathuc2 d1(3,5,7),d2(4,7,6),T;
	cout<<"-----tong hai da thuc da tao la: "<<endl;
	T = d1.tong(d2);	
	T.in();
	cout<<endl;
	return 1;
	
}


























