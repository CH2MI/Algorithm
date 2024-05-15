#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int ret = N;
    int cnt = 0;
    
    do {
        int t;
        
        if (ret < 10) {
            t = ret;
        }
        else {
            t = (ret / 10 + ret % 10);
        }
        
        ret = (ret % 10) * 10 + t % 10;
        ++cnt;
    } while(N != ret);
    
    cout << cnt;
}