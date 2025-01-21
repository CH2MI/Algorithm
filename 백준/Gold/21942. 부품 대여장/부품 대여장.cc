#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> db;
map<string, long long> fine;


int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int L2T(string L) {
    int d = stoi(L.substr(0, 3));
    int h = stoi(L.substr(4, 2));
    int m = stoi(L.substr(7, 2));
    return m + 60 * h + 1440 * d;
}

int D2T(string a, string b) {
    int M = stoi(a.substr(5, 2));
    int d = stoi(a.substr(8, 2));
    int h = stoi(b.substr(0, 2));
    int m = stoi(b.substr(3, 2));

    int time = 0;
    for (int i = 0; i < M - 1; i++) {
        time += month[i] * 1440;
    }
    time += (d - 1) * 1440;
    time += m + 60 * h;
    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, l;
    long long F;
    string L;
    cin >> N >> L >> F;
    l = L2T(L);

    for (int i = 0; i < N; i++) {
        string a, b, item, name;
        cin >> a >> b >> item >> name;
        int t = D2T(a, b);
        string c = item + name;
        auto itr = db.find(c);
        if (itr == db.end()) {
            db.insert({c, t});
        }
        else {
            if (t - itr->second > l) {
                fine[name] += (t - itr->second - l) * F;
            }
            db.erase(itr);
        }
    }

    for (auto& [name, f] : fine) cout << name << ' ' << f << '\n';
    if (fine.empty()) cout << -1;
}