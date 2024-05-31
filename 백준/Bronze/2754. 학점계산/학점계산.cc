#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    float sum = 4.0f;
    switch(s[0]) {
        case 'F':
        sum -= 1.0f;
        case 'D':
        sum -= 1.0f;
        case 'C':
        sum -= 1.0f;
        case 'B':
        sum -= 1.0f;
    }
    
    if (sum != 0.0f) {
        if (s[1] == '+') sum += 0.3f;
        else if (s[1] == '-') sum -= 0.3f;
    }
    printf("%.1f", sum);
    
}