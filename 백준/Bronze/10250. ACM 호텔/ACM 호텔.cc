#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;
        int Y = N / H + 1;
        int X = N % H;
        
        if (!X) {
            X += H;
            --Y;
        }
        
        cout << X * 100 + Y << '\n';
    }
}