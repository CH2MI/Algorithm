#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    char c; cin >> c;
    switch(c) {
        case 'M': cout << "MatKor"; break;
        case 'W': cout << "WiCys"; break;
        case 'C': cout << "CyKor"; break;
        case 'A': cout << "AlKor"; break;
        case '$': cout << "$clear"; break;
    }
}