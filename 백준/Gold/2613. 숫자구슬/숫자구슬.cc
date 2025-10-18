#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;

int solve(int mid) {
    int cnt = 0, sum = 0;

    for (int i = 0; i < N; i++) {
        if (v[i] > mid) return 0;
        if (sum + v[i] > mid) {
            ++cnt;
            sum = 0;
        }
        sum += v[i];
    }
    return cnt + 1 <= M;
}

void trace(int value) {
    list<int> ans;
    int cnt = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum + v[i] > value) {
            ans.push_back(cnt);
            cnt = 0;
            sum = 0;
        }
        ++cnt;
        sum += v[i];
    }
    ans.push_back(cnt);

    auto itr = ans.begin();
    while ((int)ans.size() < M) {
        if (*itr > 1) {
            --*itr;
            ans.insert(itr, 1);
        }
        else itr++;
    }
    for (int& i : ans) cout << i << ' ';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    v.assign(N, 0);
    for (int& i : v) cin >> i;

    int lo = 0, hi = accumulate(v.begin(), v.end(), 0);
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }

    cout << hi << '\n';
    trace(hi);
}