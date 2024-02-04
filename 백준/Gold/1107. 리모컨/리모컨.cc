#include <iostream>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	set<int> set;

	for (int i = 0; i < 10; i++) {
		set.insert(i);
	}
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		set.erase(t);
	}
	int a, b;

	// 일일히 다 눌렀을 때
	a = abs(100 - N);

	b = 500000;
	for (int i = 0; i <= 1000000; i++) {
		string s = to_string(i);

		// 사용할 수 없는 번호가 있으면 건너 뛴다.
		int f = 0;
		for (int j = 0; j < s.size(); j++) {
			if (set.find(s[j] - '0') == set.end()) {
				f = 1;
				break;
			}
		}
		if (f) continue;

		// 해당 번호로 이동 후 횟수를 확인한다.
		int t = s.size() + abs(i - N);
		if (t < b) {
			//cout << i << ' ' << t << '\n';
			b = t;
		}
	}

	// 이동 후 채널을 옮기는 것과 그냥 옮기는 것 중 최소값을 선택한다.
	cout << min(a, b);
}