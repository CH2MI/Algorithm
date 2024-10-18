#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long S, K; 
    cin >> S >> K;

    long long avg = S / K;
    long long r = S % K;

    vector<long long> v(K, avg);

    for (int i = 0; i < r; i++) {
        v[i % K]++;
    }
    
    long long sum = 1;
    for (auto i : v) sum *= i;

    cout << sum;
}