#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cmp(string str1, string str2) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (str1[i] != str2[i]) sum++;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		int N;
		cin >> N;
		vector<string> v;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}

		// 32이상이면 똑같은 것이 3개 이상 존재하므로 거리는 0이다.
		if (N > 32) {
			cout << "0\n";
			continue;
		}

		int Min = 12;

		// 3중 for 문으로 최소 거리를 찾는다.
		for (int i = 0; i < N - 2; i++) {
			for (int j = i + 1; j < N - 1; j++) {
				for (int k = j + 1; k < N; k++) {
					int sum = 0;
					sum += cmp(v[i], v[j]) + cmp(v[j], v[k]) + cmp(v[i], v[k]);
					if (Min > sum) Min = sum;
				}
			}
		}
		cout << Min << '\n';
	}


}