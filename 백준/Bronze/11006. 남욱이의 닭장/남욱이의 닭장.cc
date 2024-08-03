#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        int U = M * 2 - N;
        int t = M - U;
        cout << U << ' ' << t << '\n';
    }
}