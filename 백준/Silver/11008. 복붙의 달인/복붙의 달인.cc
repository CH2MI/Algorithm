#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    while (N--) {
        string s, p;
        cin >> s >> p;
        int slen = (int)s.size(), plen = (int)p.size();

        int cnt = 0;
        for (int i = 0; i < slen; i++) {
            if (i <= slen - plen && s.substr(i, plen) == p) {
                i += plen - 1;
            }
            cnt += 1;
        }

        cout << cnt << '\n';
    }
}