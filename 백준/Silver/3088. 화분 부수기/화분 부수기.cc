#include <iostream>
using namespace std;

bool crash[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;

    int cnt = 0;
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (!crash[a] && !crash[b] && !crash[c]) cnt++; 
        crash[a] = crash[b] = crash[c] = true;  
    }
    cout << cnt;
}