#include <iostream>

int get_change(int m) {
	int coins=0;
	for(int i=0;m!=0;i++){
		if(m<=4){
			coins=coins+m;
			m=0;
		}
		else if(m<=9 && m>4){
			coins = coins+1+(m-5);
			m=0;
		}
		else if(m>9){
			coins = coins + (m/10);
			m = m%10;
		}	
			
	}
	
	return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
