#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<bool> v(N);
    
    int cnt = 0;
    while (N--) {
        int i; cin >> i;
        if (v[--i]) cnt++;
        v[i] = true;
    }
    cout << cnt;
}