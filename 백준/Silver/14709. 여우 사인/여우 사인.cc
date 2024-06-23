#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    int ncnt = 0;
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            if (b == 3 || b == 4) cnt++;
        }
        else if (a == 3) {
            if (b == 1 || b == 4) cnt++;
        }
        else if (a == 4) {
            if (b == 1 || b == 3) cnt++;
        }
        else ncnt++;
    }
    if (!ncnt && cnt == 3) cout << "Wa-pa-pa-pa-pa-pa-pow!";
    else cout << "Woof-meow-tweet-squeek";
}