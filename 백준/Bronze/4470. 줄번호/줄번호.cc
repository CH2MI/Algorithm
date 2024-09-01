#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    for (int i = 1; i <= N; i++) {
        string s;
        getline(cin, s);
        cout << i << ". " << s << '\n';
    }
}