#include <iostream>
using namespace std;
template <class T>
class MyPair{
	private:
		T a,b;
	public:
		MyPair(T first, T second){
			a = first;
			b = second;
		}
		void printf(){
			cout<<"\nFirst = "<< a <<", Second = "<<b<<endl;		
		}
		T getMax(){
			T MAX = a;
			if(a < b)
			MAX = b;
			return MAX;
		};
};
int main(){
	MyPair<int> pair1(100,200);
	pair1.printf();
	cout<<"\nMax: "<<pair1.getMax()<<endl;
	MyPair<char> pair2('b','c');
	pair2.printf();
	cout<<"\nMax: "<<pair2.getMax()<<endl;
	return 0;
}