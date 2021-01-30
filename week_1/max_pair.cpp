#include <iostream>
#include <vector>
#include <algorithm>

int64_t MaxPairwiseProduct(const std::vector<int64_t>& numbers) {
    int n = numbers.size();

	int64_t result =0;
	int max_index1 = -1;
    for (int first = 0; first < n; ++first)
        if( (max_index1 == -1) || (numbers[first] > numbers[max_index1]) ){
        	max_index1 = first;
        }
			
	
	int max_index2 = -1;
	for(int second = 0; second<n; ++second)
		if(second==max_index1){
			continue;
		}
		else if(((second != max_index1)) && ((max_index2==-1)||(numbers[second] > numbers[max_index2]))){
			max_index2=second;
			result = (numbers[max_index1])*numbers[max_index2];
		}
	
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
	
	int64_t result = MaxPairwiseProduct(numbers);
    std::cout << result;
    return 0;
}	