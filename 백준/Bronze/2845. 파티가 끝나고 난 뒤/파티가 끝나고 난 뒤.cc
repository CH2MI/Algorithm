#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int v = N * M;
    
    for (int i = 0; i < 5; i++) {
        int t; cin >> t;
        cout << t - v << ' ';
    }
}