#include <iostream>
using namespace std;

int main() {
    bool cube[8][8][8] = { false, };
    
    int N, M;
    cin >> N >> M;
    
    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;
        
        cube[i][j][k] = true;
    }
    
    int count = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (cube[i][j][k]) {
                    if (cube[i - 1][j][k] && cube[i + 1][j][k] && cube[i][j - 1][k] && cube[i][j + 1][k] && cube[i][j][k - 1] && cube[i][j][k + 1])
                        count++;
                }
            }
        }
    }
    
    cout << count;
    
}