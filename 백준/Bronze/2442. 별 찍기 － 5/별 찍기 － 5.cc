#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int S = 2 * N - 1;
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (; j < N - i - 1; j++) {
            cout << ' ';
        }
        for (; j < N + i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}