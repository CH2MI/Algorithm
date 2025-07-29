#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C; cin >> A >> B >> C;

    if (C % 2) A = A ^ B;
    cout << A;
}