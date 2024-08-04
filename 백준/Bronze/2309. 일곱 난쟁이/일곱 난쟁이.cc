#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(9);
    for (auto& i : v) cin >> i;
    vector<int> t{ 0, 0, 0, 0, 0, 0, 0, 1, 1 };
    
    sort(v.begin(), v.end());
    int sum;
    do {
        sum = 0;
        for (int i = 0; i < 9; i++) {
            if (!t[i]) {
                sum += v[i];
            }
        }
    } while (sum != 100 && next_permutation(t.begin(), t.end()));
    
    for (int i = 0; i < 9; i++) {
        if (!t[i]) cout << v[i] << '\n';
    }
}