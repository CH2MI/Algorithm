#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        string name;
        int age, weight;
        cin >> name >> age >> weight;
        if (name == "#") break;
        cout << name << ' ';
        if (age > 17 || weight >= 80) cout << "Senior\n";
        else cout << "Junior\n";
    }
}