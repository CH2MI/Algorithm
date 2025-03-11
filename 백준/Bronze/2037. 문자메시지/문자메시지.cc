#include <bits/stdc++.h>
using namespace std;

int a[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int b[26] = {0, 0, 0, 1, 1 ,1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int p, w; cin >> p >> w; cin.ignore();
    string s; getline(cin, s);
    int sum = a[s[0] - 'A'] * p;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ' ') sum += p;

        else {
            if (s[i - 1] != ' ' && b[s[i - 1] - 'A'] == b[s[i] - 'A']) sum += w;
            sum += a[s[i] - 'A'] * p;
        }
    }
    cout << sum;
}