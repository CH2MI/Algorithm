#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int t; cin >> t;
        sum += t < 40 ? 40 : t;
    }
    cout << sum / 5;
}