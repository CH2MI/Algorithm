#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));

    for (int i = 0; i <= (int)A.size(); i++) dp[i][0] = i;
    for (int i = 0; i <= (int)B.size(); i++) dp[0][i] = i;

    for (int i = 1; i <= (int)A.size(); i++) {
        for (int j = 1; j <= (int)B.size(); j++) {
            if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
    }

    cout << dp.back().back();


}