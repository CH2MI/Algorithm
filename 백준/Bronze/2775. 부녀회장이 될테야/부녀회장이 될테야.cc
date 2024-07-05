#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    vector<vector<int>> v(15, vector<int>(14));
    
    for (int i = 0; i < 14; i++) {
        v[0][i] = i + 1;
    }
    
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k <= j; k++) {
                v[i][j] += v[i - 1][k];
            }
        }
    }
    
    while (T--) {
        int k, n;
        cin >> k >> n;
        
        cout << v[k][n - 1] << '\n';
    }
}