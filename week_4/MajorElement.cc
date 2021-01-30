#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int64_t majority_element(vector<int64_t> &a, int64_t left, int64_t right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    int64_t left_elem = majority_element(a, left, (left + right - 1) / 2 + 1);
    int64_t right_elem = majority_element(a, (left + right - 1) / 2 + 1, right);

    long int lcount = 0;
    for (long int i = left; i < right; i++) {
        if (a[i] == left_elem) lcount += 1;
    }
    if (lcount > (right - left) / 2) return left_elem;

    long int rcount = 0;
    for (long int i = left; i < right; i++) {
        if (a[i] == right_elem) rcount += 1;
    }
    if (rcount > (right - left) / 2) return right_elem;

    return -1;
}

int main() {
    int64_t n;
    std::cin >> n;
    vector<int64_t> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (majority_element(a, 0, a.size()) != -1) << '\n';
}
