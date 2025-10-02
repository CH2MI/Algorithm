#include <bits/stdc++.h>
using namespace std;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char keys[4] = {'W', 'A', 'S', 'D'};
 
int N;
vector<vector<int>> v;
 
bool ExecuteEvent(string& event, int pre, int cur) {
    if (event == "Down")
        return !pre && cur;
    if (event == "Stay")
        return pre && cur;
    if (event == "Up")
        return pre && !cur;
    return false;
}
 
void Move(array<int, 2> &p, int d) {
    array<int, 2> nxt = {p[0] + dx[d], p[1] + dy[d]};
    if (nxt[0] < 0 || nxt[0] >= N || nxt[1] < 0 || nxt[1] >= N) return;
    if (v[nxt[0]][nxt[1]] == 1) return;
    p = nxt;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int M; cin >> N >> M;
 
    v.assign(N, vector<int>(M));
 
    array<int, 2> p{};
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
 
            if (v[i][j] == 2) {
                v[i][j] = 0;
                p = {i, j};
            }
        }
    }
 
    vector<string> event(4);
    vector<int> preState(4);
    for (auto& s : event) cin >> s;
 
    string s; cin >> s;
 
    for (auto c : s) {
        for (int i = 0; i < 4; i++) {
            if (c == keys[i]) {
                if (ExecuteEvent(event[i], preState[i], 1))
                    Move(p, i);
                preState[i] = 1;
            }
            else {
                if (ExecuteEvent(event[i], preState[i], 0))
                    Move(p, i);
                preState[i] = 0;
            }
        }
    }
 
    cout << p[0] + 1 << ' ' << p[1] + 1;
}
