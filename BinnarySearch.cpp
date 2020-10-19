#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int64_t binary_search(const vector<int64_t> &a, int64_t x) {
  int64_t left = 0, right = (int)a.size(); 
  
  while (left <= right) {
          int mid = left + (right - left) / 2;
          if (x == a[mid]) return mid;
          else if (x < a[mid]) right = mid - 1;
          else left = mid + 1; 
	}
  return -1;
}

int main() {
  int64_t n;
  std::cin >> n;
  vector<int64_t> a(n);
  for (long int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int64_t m;
  std::cin >> m;
  vector<int64_t> b(m);
  for (long int i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  for (long int i = 0; i < m; i++) {
	  std::cout << binary_search(a, b[i]) << ' ';
  }
}
