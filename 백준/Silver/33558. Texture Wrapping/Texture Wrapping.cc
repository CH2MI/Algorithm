#include <bits/stdc++.h>
using namespace std;

int N, M, U, V;

void c(vector<string>& t) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i >= U && j >= V) cout << t[U - 1][V - 1];
            else if (i >= U) cout << t[U - 1][j];
            else if (j >= V) cout << t[i][V - 1];
            else cout << t[i][j];
        }
        cout << '\n';
    }
}

void r(vector<string>& t) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << t[i % U][j % V];
        }
        cout << '\n';
    }
}

void m(vector<string>& t) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x, y;
            if (i / U % 2) x = U - (i % U) - 1;
            else x = i % U;
            if (j / V % 2) y = V - j % V - 1;
            else y = j % V;

            cout << t[x][y];
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);


    cin >> N >> M >> U >> V;
    vector<string> t(U);
    for (auto& s : t) cin >> s;
    string mode;
    cin >> mode;

    if (mode == "clamp-to-edge") c(t);
    else if (mode == "repeat") r(t);
    else m(t);
}