#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int mul = A * B * C;
    string s = to_string(mul);
    int cnt[10] = {0};
    for (auto i : s) {
        cnt[i - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << '\n';
    }
}