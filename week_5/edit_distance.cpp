#include <iostream>
#include <string>
#include<vector>

using std::string;
using namespace std;

int64_t edit_distance(const string &str1, const string &str2) {
	int i=0,j=0;
	//int64_t DP[100][100]={0};
	vector<vector<int> > DP( str1.length()+1 , vector<int> (str2.length()+1, 0));
	
	
	for(i=1;i<=str1.length();++i){
		DP[i][0]=i;
		for(j=1;j<=str2.length();++j){
			DP[0][j]=j;
			int64_t ins = DP[i][j-1]+1;
			int64_t del = DP[i-1][j]+1;
			int64_t mat = DP[i-1][j-1];
			int64_t mim = DP[i-1][j-1]+1;
		
			if(str1[i-1] == str2[j-1]){
				DP[i][j] = min(ins,min(del,mat));
			}
			else{
				DP[i][j] = min(ins,min(del,mim));
			}
						
		}
	}
	return DP[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
