#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	string s;
	cin >> s;

	int mn = (int)1e9;

	int cnt = 0; bool r = true;
	// 빨간 공을 왼쪽으로 넘길 때
	for (int i = 0; i < N; i++) {
		if (r && s[i] == 'B') r = false;
		else if (!r && s[i] == 'R') cnt++;
	}
	mn = min(cnt, mn);

	cnt = 0; r = true;
	// 빨간 공을 오른쪽으로 넘길 때
	for (int i = N - 1; i >= 0; i--) {
		if (r && s[i] == 'B') r = false;
		else if (!r && s[i] == 'R') cnt++;
	}
	mn = min(cnt, mn);

	cnt = 0; bool b = true;
	// 파란 공을 왼쪽으로 넘길 때
	for (int i = 0; i < N; i++) {
		if (b && s[i] == 'R') b = false;
		else if (!b && s[i] == 'B') cnt++;
	}
	mn = min(cnt, mn);

	cnt = 0; b = true;
	// 파란 공을 오른쪽으로 넘길 때
	for (int i = N - 1; i >= 0; i--) {
		if (b && s[i] == 'R') b = false;
		else if (!b && s[i] == 'B') cnt++;
	}
	mn = min(cnt, mn);

	cout << mn;
}