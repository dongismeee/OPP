#include <iostream>
using namespace std;
class SP{
	
	private:
		int pt;
		int pa;
	public:
		void in();
		SP();
		SP(int pt, int pa);
		~SP();
		SP tong2(SP p);	
};
SP::SP(){
	this->pt =0;
	this->pa =0;
}
SP::SP(int pt, int pa){
	this->pt=pt;
	this->pa=pa;
}
SP::~SP(){
	
}
void SP::in(){
	if(this->pa>=0)
		cout<<this->pt<<" + "<<this->pa<<"*i";
	else
		cout<<this->pt<<" - "<<abs(this->pa)<<"*i";
}
SP SP::tong2(SP p){
	
	SP tong;
	tong.pt=this->pt+p.pt;
	tong.pa=this->pa+p.pa;
	return tong;	
}
int main(){
	cout<<"------LIEN QUAN MOBILE-TONG 2 SO PHUC ---"<<endl;
	cout<<"-----------------------------------------"<<endl;
	SP p1(5,-6),p2(7,-10),p3(-99,1111);
	SP p4,p5;
	p4=p1.tong2(p2);
	p5=p4.tong2(p3);
	cout<<"tong 2 so phuc vua duoc khoi tao la: "<<endl;
	p5.in();
	cout<<endl;
	return 0;
	
	
}