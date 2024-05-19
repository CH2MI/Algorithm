#include <iostream>
using namespace std;

int main() {
    int f[46] = {0}; f[0] = 0; f[1] = 1;
    int n;
    cin >> n;
    
    for (int i = 2; i < 46; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    
    cout << f[n];
    
}