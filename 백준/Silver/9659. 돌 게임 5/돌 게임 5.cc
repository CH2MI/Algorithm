#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    if (N % 2) cout << "SK";
    else cout << "CY";
}