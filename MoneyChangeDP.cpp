#include<iostream>
#include<algorithm>
using namespace std;
int64_t Darray[100000];

int64_t rchng(int64_t m){
	if(m==0)
		return 0;
	else if(m<=100000 && Darray[m]!=0){
		 return Darray[m];
	}
	else{
		int64_t coins = min(rchng(m-1) + 1,min(rchng(m-3) + 1,rchng(m-4) + 1));
		if(m<100000)
			Darray[m]=coins;
		return coins;	
	}
};
	
int main(){
	int64_t m;
	cin>>m;
	cout<<rchng(m);
}	
