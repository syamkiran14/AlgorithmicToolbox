#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
	vector<vector<int> > DP(a.size()+1, vector<int>(b.size()+1,0));	
	
	for(int i=1;i<=a.size();++i){
			//DP[i][0]=0;
			for(int j=1;j<=b.size();++j){
				//DP[0][j]=0;
				if(a[i-1] == b[j-1])
					DP[i][j] = 1 + DP[i-1][j-1];
				else
					DP[i][j] = std::max(DP[i-1][j],DP[i][j-1]);			
			}
		}
		
//	std::cout << a.size()<<"\t"<<b.size()<<"\n";
return DP[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
	
  std::cout << lcs2(a, b) << std::endl;
}
