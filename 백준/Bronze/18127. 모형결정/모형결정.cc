#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long a, b; cin >> a >> b;

    cout << (b + 1) * (2 + b * (a - 2)) / 2;

}