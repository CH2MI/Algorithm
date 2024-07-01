#include <iostream>
using namespace std;

int main()
{
    
    int N;
    cin >> N;
    N--;
    string s;
    cin >> s;
    while(N--) {
        string t;
        cin >> t;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?' && s[i] != t[i]) s[i] = '?';
        }
    }
    cout << s;
}