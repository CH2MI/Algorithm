#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;

    string mn, mx;
    int mncount = 0, mxcount = 0;

    for (auto c : s) {

        // k가 나왔을 때
        if (c == 'K') {
            // 최댓값은 M...MK 형태로 계산
            mx += '5';
            for (int i = 0; i < mxcount; i++) mx += '0';
            mxcount = 0;

            // 최솟값은 M....M 그리고 K 형태로 계산
            if (mncount) mn += '1';
            for (int i = 1; i < mncount; i++) mn += '0';
            mncount = 0;
            mn += '5';
        }

        else {
            mxcount++; mncount++;
        }
    }

    for (int i = 0; i < mxcount; i++) mx += '1';
    if (mncount) mn += '1';
    for (int i = 1; i < mncount; i++) mn += '0';

    cout << mx << '\n' << mn;
}