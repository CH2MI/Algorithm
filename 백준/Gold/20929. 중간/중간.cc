#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int llo = 1, lhi = N, rlo = 1 , rhi = N;
    int lmid, rmid;
    while (llo != lhi || rlo != rhi) {
        lmid = (llo + lhi) / 2, rmid = (rlo + rhi) / 2;

        int lvalue, rvalue;
        cout << "? A " << lmid << endl;
        cin >> lvalue;
        cout << "? B " << rmid << endl;
        cin >> rvalue;

        if (lvalue < rvalue) {
            llo = lmid + 1;
            rhi = rmid;
        }
        else {
            lhi = lmid;
            rlo = rmid + 1;
        }
    }

    int lvalue, rvalue;
    cout << "? A " << llo << endl;
    cin >> lvalue;
    cout << "? B " << rhi << endl;
    cin >> rvalue;
    cout << "! " << min(lvalue, rvalue) << endl;
}