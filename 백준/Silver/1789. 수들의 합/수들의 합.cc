#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long N;
	cin >> N;
	
	long long sum = 0, i = 1;
	while (sum <= N) {
	    sum += i++;
	}
	
	// 시작할 때 1, 마지막에 1 더 셌으므로 2를 뺀다.
	cout << i - 2;
}
