#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<int> v(10, 3);
    v[0] = 4; v[1] = 2;
    
    while (true) {
        string s;
        cin >> s;
        
        if (s == "0") break;
        
        int sum = (int)s.size() + 1;
        
        for (auto c : s) {
            sum += v[c - '0'];
        }
        
        cout << sum << '\n';
     }
}