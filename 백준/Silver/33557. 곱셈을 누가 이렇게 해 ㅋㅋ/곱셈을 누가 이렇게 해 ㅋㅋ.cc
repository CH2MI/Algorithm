#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        long long A, B, ret1;
        cin >> A >> B;

        ret1 = A * B;

        string ret2;
        while (A > 0 && B > 0) {
            string t = to_string((A % 10) * (B % 10));
            A /= 10, B /= 10;
            t += ret2;
            ret2 = t;
        }
        while (A > 0) {
            string t = to_string(A % 10);
            A /= 10;
            t += ret2;
            ret2 = t;
        }
        while (B > 0) {
            string t = to_string(B % 10);
            B /= 10;
            t += ret2;
            ret2 = t;
        }
        cout << (ret1 == stoll(ret2)) << '\n';
    }

}