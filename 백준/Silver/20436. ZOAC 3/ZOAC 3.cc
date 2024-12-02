#include <iostream>
#include <vector>
#include <cmath>
#define INF (int)1e9
using namespace std;

int keyboard[3][10] = {
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ' '},
    {'z', 'x', 'c', 'v', 'b', 'n', 'm', ' ', ' ', ' ' }
};

pair<int, int> getcoord(char c) {
    pair<int, int> ans{-1, -1};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 10; j++)
            if (keyboard[i][j] == c) ans = {i, j};
    return ans;
}

int getdist(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string s;
vector<vector<vector<int>>> dp;

int DP(int i, char l, char r, pair<int, int>& left, pair<int, int>& right) {
    if (i == (int)s.size()) return 0;

    if (dp[i][l - 'a'][r - 'a'] != INF) return dp[i][l - 'a'][r - 'a'];

    pair<int, int> cur = getcoord(s[i]);

    if (cur.first < 2 && cur.second < 5 || cur.first == 2 && cur.second < 4) dp[i][l - 'a'][r - 'a'] = DP(i + 1, s[i], r, cur, right) + getdist(left, cur) + 1;
    else dp[i][l - 'a'][r - 'a'] = DP(i + 1, l, s[i], left, cur) + getdist(right, cur) + 1;

    return dp[i][l - 'a'][r - 'a'];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char l, r; cin >> l >> r >> s;

    dp.assign(s.size(), vector<vector<int>>(26, vector<int>(26, INF)));
    pair<int, int> left = getcoord(l), right = getcoord(r);
    cout << DP(0, l, r, left, right);
}