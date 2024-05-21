#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ret = gcd(n, m);
    cout << ret << '\n' << n * m / ret;
}