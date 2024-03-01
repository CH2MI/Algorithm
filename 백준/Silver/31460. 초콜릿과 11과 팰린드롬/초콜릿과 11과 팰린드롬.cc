#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		int N;
		cin >> N;
		if (N == 1) cout << "0\n";
		else if (N % 2 == 0) {
			int i = 0;
			string s;
			for (; i < N; i++) {
				s.push_back('1');
			}
			cout << s << '\n';
		}
		else if (N % 2 == 1) {
			int i = 0;
			string s;
			for (; i < N / 2; i++) {
				s.push_back('1');
			}
			if (N / 2 % 2 == 0) {
				s.push_back('0');
			}
			else s.push_back('2');
			++i;
			for (; i < N; i++) {
				s.push_back('1');
			}
			cout << s << '\n';
		}
	}
}