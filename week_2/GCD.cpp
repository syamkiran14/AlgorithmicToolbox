#include <iostream>
#include<cmath>
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int64_t Eucludian(int64_t a, int64_t b){
	if(a!=b){
		for(int i=0;fabs(a-b)!=0;i++){
			if(a>b)
				a=a-b;
			else
				b=b-a;
			
		}
	}
	return gcd_naive(a,b);
}

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  if(a==b){
	  std::cout<<a;
  }
  else
	  std::cout <<Eucludian(a, b) << std::endl;
  return 0;
  
}
