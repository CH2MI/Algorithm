#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> v(N);
    
    for (auto& i : v) {
        cin >> i;
    }
    
    sort(v.begin(), v.end());
    int i;
    for (i = 0; i < N; i++) {
        if (i + 1 != v[i]) {
            cout << i + 1;
            break;
        }
    }
    if (i == N) cout << i + 1;
}