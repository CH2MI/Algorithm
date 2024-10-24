#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        
        double count = 0;
        for (int i = 2; i <= N; i++) {
            count += log10(i);
        }
        count += 1;
        cout << (int)count << '\n';
    }
}