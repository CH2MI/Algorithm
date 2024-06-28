#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double A, B, C, I, J, K;
    cin >> A >> B >> C >> I >> J >> K;
    
    double a = A / I;
    double b = B / J;
    double c = C / K;
    
    double m = min({a, b, c});
    a = A - I * m;
    b = B - J * m;
    c = C - K * m;
    
    cout << fixed;
    cout.precision(10);
    
    cout << a << ' ' << b << ' ' << c;
}