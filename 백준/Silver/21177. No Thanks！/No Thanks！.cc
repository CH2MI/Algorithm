#include <iostream>
using namespace std;

int arr[90001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        arr[t]++;
    }

    int sum = 0;
    bool f = false;
    for (int i = 1; i < 90001; i++) {
        if (!arr[i]) continue;
        if (arr[i - 1]) continue;
        sum += i;
    }
    cout << sum;
}