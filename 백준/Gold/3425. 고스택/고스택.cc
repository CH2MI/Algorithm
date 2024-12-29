#include <bits/stdc++.h>
#define INF (ll)1e9
using namespace std;

typedef long long ll;
vector<pair<string, ll>> com;

bool cal(stack<ll>& st, string& command, ll X) {
    if (command == "NUM") {
       st.push(X);
    }
    else if (command == "POP") {
        if (st.empty()) return false;
        st.pop();
    }
    else if (command == "INV") {
        if (st.empty()) return false;
        ll tmp = -st.top();
        st.pop();
        st.push(tmp);
    }
    else if (command == "DUP") {
        if (st.empty()) return false;
        st.push(st.top());
    }
    else if (command == "SWP") {
        if (st.size() < 2) return false;
        ll a = st.top(); st.pop();
        ll b = st.top(); st.pop();
        st.push(a); st.push(b);
    }
    else if (command == "ADD") {
        if (st.size() < 2) return false;
        ll a = st.top(); st.pop();
        ll b = st.top(); st.pop();
        ll value = a + b;
        if (abs(value) > INF) return false;
        st.push(value);
    }
    else if (command == "SUB") {
        if (st.size() < 2) return false;
        ll a = st.top(); st.pop();
        ll b = st.top(); st.pop();
        ll value = b - a;
        if (abs(value) > INF) return false;
        st.push(value);
    }
    else if (command == "MUL") {
        if (st.size() < 2) return false;
        ll a = st.top(); st.pop();
        ll b = st.top(); st.pop();
        ll value = b * a;
        if (abs(value) > INF) return false;
        st.push(value);
    }
    else if (command == "DIV") {
        if (st.size() < 2) return false;
        ll a = st.top(); st.pop();
        ll b = st.top(); st.pop();
        if (!a) return false;
        ll value = abs(b) / abs(a);
        if (a * b < 0) value = -value;
        if (abs(value) > INF) return false;
        st.push(value);
    }
    else if (command == "MOD") {
        if (st.size() < 2) return false;
        ll a = st.top(); st.pop();
        ll b = st.top(); st.pop();
        if (!a) return false;
        ll value = abs(b) % abs(a);
        if (b < 0) value = -value;
        if (abs(value) > INF) return false;
        st.push(value);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        com.clear();
        while (1) {
            string s; cin >> s;
            if (s == "QUIT") return 0;
            if (s == "END") break;
            ll n = 0;
            if (s == "NUM") cin >> n;
            com.emplace_back(s, n);
        }

        int N; cin >> N;
        while (N--) {
            stack<ll> st;
            int n; cin >> n;
            st.push(n);

            bool vaild = true;
            for (auto& [command, X] : com) {
                if (!cal(st, command, X)) {
                    vaild = false;
                    break;
                }
            }
            if (vaild && st.size() == 1) cout << st.top() << '\n';
            else cout << "ERROR\n";
        }
        cout << '\n';
    }
}