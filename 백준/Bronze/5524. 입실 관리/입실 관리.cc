#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        string s;
        cin >> s;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << '\n';
    }
}