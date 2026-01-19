#include <bits/stdc++.h>
using namespace std;

void ball(int& score, array<int, 3>& base) {
    if (base[2] && base[1] && base[0]) ++score;
    else if (base[2] && base[1]) base[0] = 1;
    else if (base[2] && base[0]) base[1] = 1;
    else if (base[1] && base[0]) base[2] = 1;
    else if (base[1]) base[0] = 1;
    else if (base[0]) base[1] = 1;
    else base[0] = 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;
    array<int, 3> base{};

    int score = 0;
    int b = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;

        if (a == 1) {
            if (++b == 4) {
                ball(score, base);
                b = 0;
            }
        }
        else if (a == 2) {
            ball(score, base);
            b = 0;
        }
        else {
            if (base[2]) {
                ++score;
                base[2] = 0;
            }
            if (base[1]) {
                base[2] = 1;
                base[1] = 0;
            }
            if (base[0]) {
                base[1] = 1;
                base[0] = 0;
            }
            if (++b == 4) {
                base[0] = 1;
                b = 0;
            }
        }
    }

    cout << score;
}
