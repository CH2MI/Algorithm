#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;
		if (k == 0) s.pop();
		else s.push(k);
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}