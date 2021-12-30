#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
class benhan
{
	protected:
		string tenba;
		string tienvp;
		string hoten;
		string quequan;
		string namsinh;
	public:
		void docfile( ifstream &);
		void xuat()
		{
			cout<<"\nHo ten: "<<hoten;
			cout<<"\nQue quan: "<<quequan;
			cout<<"\nNam sinh: "<<namsinh;
			cout<<"\nTen benh an: "<<tenba;
			cout<<"\nTien vien phi: "<<tienvp;
			cout<<endl;
		}	
};
void benhan::docfile(ifstream &newfile){

	getline(newfile, hoten, ',');
	
	getline(newfile, quequan, ',');
	getline(newfile, namsinh, ',');
	getline(newfile, tenba, ',');
	getline(newfile, tienvp, ',');
	
};
void menu(benhan * a[], int n)	
{
	ifstream newfile;
	newfile.open("index.txt", ios_base::in);	
	int chon;
		while(1)
				{
				system("cls");
				cout<<"\n\t\tNhap su lua chon!";
				cout<<"\n\t\t1.DOC file .";
				cout<<"\n\t\t2.xuat file .";
				cout<<"\n\t\t3.Dung.";
				cout<<"\n\t\tLUA chon: ";
				cin>>chon;
				if(chon==3) 	break;
				if(chon==1)
					{
						newfile>>n;
						for(int i=0;i<n;i++)
							{
							a[i]->docfile(newfile);
							}
						
					};
				if(chon==2)
					{
					 for(int i=0;i<n;i++){
 						cout<<"\nthong tin banh an thu "<<i+1<<endl;
 						a[i]->xuat();
 					}
 					system("pause");
					};
				}
				newfile.close();
};
int main()
{
	benhan *a[100];
	int n =0;
	menu(a,n);
	system("pause");
	cout<<endl;	
	return 0;		
}