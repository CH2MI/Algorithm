#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        float average = reduce(v.begin(), v.end()) / N;
        int cnt = 0;
        for (auto i : v) {
            if (average < i) cnt++;
        }
        
        printf("%.3f%%\n", (float)cnt / N * 100);
    }
}