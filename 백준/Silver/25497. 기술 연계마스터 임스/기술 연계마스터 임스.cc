#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; 
	string s;
	cin >> N >> s;

	int cnt = 0;
	int L = 0, S = 0;
	bool error = false;

	for (auto c : s) {
		if (!error) {
			if (c <= '9') cnt++;
			else if (c == 'L') L++;
			else if (c == 'S') S++;
			else if (c == 'R') {
				if (!L) error = true;
				else {
					L--; 
					cnt++;
				}
			}
			else {
				if (!S) error = true;
				else {
					S--;
					cnt++;
				}
			}
		}
	}

	cout << cnt;
}