#include<iostream>
#include<math.h>
int main(){
   int64_t n1=0,n2=1,n3,i,size;
    std::cin>>size;
	if(size<=1){
	    std::cout<<size;
	}
	else{
	    for(i=1;i<size;i++){
	        n3=n1+n2;
	        n1=n2;
	        n2=n3;
	    }
	    std::cout<<n3;
	}
}  