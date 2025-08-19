#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1000000007;

long long cal(vector<vector<long long>>& A, vector<vector<long long>>& B, int i, int j) {
    long long sum = 0;
    for (int k = 0; k < 8; k++)
        sum = (sum + A[i][k] * B[k][j] % MOD) % MOD;

    return sum % MOD;
}

vector<vector<long long>> Recursion(vector<vector<long long>>& A, int B) {
    vector<vector<long long>> ret(8, vector<long long>(8));

    if (B == 1) {
        return A;
    }

    auto C = Recursion(A, B / 2);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            ret[i][j] = cal(C, C, i, j);

    if (B % 2) {
        C = ret;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                ret[i][j] = cal(C, A, i, j);
    }

    return ret;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int D; cin >> D;

    vector<vector<long long>> adj
    {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    cout << Recursion(adj, D)[0][0];

}