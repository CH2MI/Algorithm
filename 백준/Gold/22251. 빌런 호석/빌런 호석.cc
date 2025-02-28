#include <bits/stdc++.h>
using namespace std;

int arr[10][10] = {
    {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
};

int N, K, P; string X;
int DFS(int cur, int p  , string s) {
    if (cur >= X.size()) {
        if (X == s) return 0;
        if (stoi(s) <= N && stoi(s) > 0) return 1;
        return 0;
    }

    int sum = 0;
    for (int j = 0; j < 10; j++) {
        if (arr[X[cur] - '0'][j] <= p) sum += DFS(cur + 1, p - arr[X[cur] - '0'][j], s + (char)(j + '0'));
    }
    return sum;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> K >> P >> X;
    for (int i = X.size(); i < K; i++) {
        X.insert(X.begin(), '0');
    }

    cout << DFS(0, P, "");
}