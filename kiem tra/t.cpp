#include<iostream>
#include<string>

using namespace std;

class DieuHoa{
	private:
		char ma[30],tenNuocNK[30],tenHangSX[30];
		float dongia,congsuat;
	public:
		DieuHoa(){
			strcpy(ma," ");
			strcpy(tenHangSX," ");
			strcpy(tenNuocNK," ");
			this->dongia=0;
			this->congsuat=0;
		}
		DieuHoa(char *ma, char *tenNuocNK, char *tenHangSX, float dongia, float congsuat){
			strcpy(ma,ma);
			strcpy(tenNuocNK,tenNuocNK);
			strcpy(tenHangSX,tenHangSX);
			this->dongia=dongia;
			this->congsuat=congsuat;
		}
		friend istream& operator >> (istream& is, DieuHoa &dh){
			fflush(stdin);
			cout<<"\nNhap vao ma dieu hoa: ";is.getline(dh.ma,30);
			cout<<"\nNhap vao ten nuoc nhap khau: ";is.getline(dh.tenNuocNK,30);
			cout<<"\nNhap vao ten hang san xuat: ";is.getline(dh.tenHangSX,30);
			cout<<"\nNhap vao don gia: ";is>>dh.dongia;
			cout<<"\nNhap vao cong suat: ";is>>dh.congsuat;
			return is;
		}
		friend ostream& operator << (ostream& os, DieuHoa &dh){
			cout<<"\nMa dieu hoa: ";os<<dh.ma;
			cout<<"\nTen nuoc nhap khau: ";os<<dh.tenNuocNK;
			cout<<"\nten ahng san xuat: ";os<<dh.tenHangSX;
			cout<<"\nDon gia: ";os<<dh.dongia;
			cout<<"\nCong suat: ";os<<dh.congsuat;
			cout<<"\nThanh tien: ";os<<dh.thanhtien();
			cout<<endl;
			return os;
		}
		float thue(){
			if(congsuat <= 18000)
				return 0.2;
			else
				return 0.4;
		}
		float thanhtien(){
			return (dongia * thue()) * 0.1;
		}
		bool operator < (DieuHoa t){
			if(t.congsuat < congsuat)
				return true;
			else
				return false;
		}
		char *getTenNuocNK(){
			return tenNuocNK;
		}
		char *getTenHangSX(){
			return tenHangSX;
		} 
		void swap(DieuHoa &x , DieuHoa &y){
			DieuHoa tg;
			tg=x ;
			x=y;
			y=tg;
		} 
		/*bool operator == (DieuHoa &dh){
	 		return tenNuocNK = dh.tenNuocNK;
 		}*/
};



int main(){
	int n,i;
	DieuHoa * dh = new DieuHoa[n];
	do{
		cout<<"\n--Nhap vao so dieu hoa n= ";cin>>n;
	}
	while(n<0);
	
	for(i=0;i<n;i++){
		cout<<"\n-Nhap thong tin dieu hoa "<<i+1<<endl;
		cin>>dh[i];
	}
	for(i=0;i<n;i++){
		cout<<"\n-In thong tin dieu hoa "<<i+1<<endl;
		cout<<dh[i];
	}
	
	cout<<"\n--------------Danh sach dieu hoa sau khi sap xep tang dan --------------";
				//Bubble Sort
					/*for (int i = n-1; i >= 1; i--){
					bool swapped= true;
					for (int j = 0; j < i; j++){
						if (dh[j].getTenNuocNK() < dh[j+1].getTenNuocNK()){
							DieuHoa temp = dh[j];
							dh[j] = dh[j+1];
							dh[j+1] = temp;
							swapped = false;
						}
					}
					if (swapped){
						break;
					}
				}*/
				
				//Insertion Sort
				/*int index;
				DieuHoa value;
				for (int i = 1; i < n; i++){
					index = i;
					value = dh[i];
					while (index > 0 && dh[index - 1].getTenNuocNK() > value.getTenNuocNK()	){
						dh[index] = dh[index - 1];
						index --;
					}
					dh[index]=value;
				}*/
				
				
				//Selection Sort
				int indexMin;
				for (int i = 0; i < n-1; i++){
					indexMin = i;
					for (int j = i+1; j < n; j++){
						if (dh[indexMin].getTenNuocNK()< dh[j].getTenNuocNK()){
							indexMin = j;
						}
					}
					if (i != indexMin){
						DieuHoa temp = dh[i];
						dh[i] = dh[indexMin];
						dh[indexMin] = temp;
					}
				}
				
				for(i=0;i<n;i++){
		cout<<"\n--In thong tin MT thu "<<i+1<<endl;
		cout<<dh[i];
	}
	/////////////////////
	for(i=0;i<n;i++){
		if(dh[i].thanhtien() > 1000){
			cout<<"\nDoi tuong co thanh tien > 1000 la: "<<dh[i];
		}
	}

	DieuHoa dhtk;
	int pos; 
	bool KT = false;
	
	for(i=0;i<n;i++){
			if(strcmp(dh[i].getTenHangSX(),"Panasonic")==0){
				pos=i;
				for(int i = pos; i < n - 1; i++){
	   				dh[i] = dh[i+1];
	   			} 
	   			--n;
	   			KT=true;
			}
	}
		
		if(!KT){
			cout<<"\nKhong co hang Panasonic trong danh sach"<<endl;
			cout<<"\nNhap vao vi tri can them: "; 
			cin>>pos; 
			cout<<"\nNhap thong tin may co ten hang Panasonic." ;
			cin>>dhtk;
   			for(int i = n; i >= pos; i--){
      			dh[i] = dh[i-1];
		    }
		    dh[pos] = dhtk;
		    ++n;
		    
		} 
	
	cout<<"\n-------Danh sach MT sau khi tat ca-------";
				
	for(i=0;i<n;i++){
		cout<<"\n--In thong tin MT thu "<<i+1<<endl;
		cout<<dh[i];
	}
}