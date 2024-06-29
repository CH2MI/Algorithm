#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    
    while (T--) {
        int N; cin >> N;
        vector<int> v(N);
        
        
        for (auto& i : v) {
            cin >> i;
            if (i % 2) i++;
        }
        
        int cnt = 0;
        
        while (true) {
            int mn = *min_element(v.begin(), v.end());
            int mx = *max_element(v.begin(), v.end());
            
            if (mn == mx) break;
            
            vector<int> a(N);
            
            for (int i = 0; i < N; i++) {
                int t = v[i] / 2;
                v[i] -= t;
                a[(i + 1) % N] += t;
            }
            cnt++;
            
            for (int i = 0; i < N; i++) {
                v[i] = v[i] + a[i];
                if (v[i] % 2) v[i]++;
            }
        }
        cout << cnt << '\n';
    }
}