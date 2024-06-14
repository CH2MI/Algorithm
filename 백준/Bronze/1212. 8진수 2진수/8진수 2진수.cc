#include <iostream>
using namespace std;

string b[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main() {
    string s;
    cin >> s;
    string r;
    for (auto i : s) {
        r.push_back(b[i - '0'][0]);
        r.push_back(b[i - '0'][1]);
        r.push_back(b[i - '0'][2]);
    }
    
    int i = 0;
    while (r[i] == '0') i++;
    int l = r.size();
    for (i; i < l; i++) cout << r[i];
    if (s == "0") cout << '0';
}