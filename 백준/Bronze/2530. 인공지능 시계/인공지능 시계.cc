#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    C += D;
    
    if (C > 59) {
        B += C / 60;
        C %= 60;
    }
    
    if (B > 59) {
        A += B / 60;
        B %= 60;
    }
    
    if (A > 23) {
        A %= 24;
    }
    
    cout << A << ' ' << B << ' ' << C;
    
}
