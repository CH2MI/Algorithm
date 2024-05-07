#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    
    while (N--) {
        string s; 
        cin >> s;
        int a = s[0] - '0';
        int b = s[2] - '0';
        cout << a + b << '\n';
    }
}