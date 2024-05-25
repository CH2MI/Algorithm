#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    N = 1000 - N;
    int cnt = 0;
    cnt += N / 500;
    N %= 500;
    cnt += N / 100;
    N %= 100;
    cnt += N / 50;
    N %= 50;
    cnt += N / 10;
    N %= 10;
    cnt += N / 5;
    N %= 5;
    cnt += N;
    cout << cnt;
}