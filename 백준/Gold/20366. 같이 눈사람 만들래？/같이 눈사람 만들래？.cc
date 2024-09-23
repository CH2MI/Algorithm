#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);

	for (auto& i : v) {
		cin >> i;
	}

	vector<tuple<int, int, int>> snowman;
	snowman.reserve(N * (N - 1) / 2);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			snowman.push_back({ v[i] + v[j], i, j });
		}
	}
	sort(snowman.begin(), snowman.end());
	int mn = INT_MAX;
	int len = snowman.size();

	for (int i = 0; i < len - 1; i++) {
		auto& [lv, la, lb] = snowman[i];
		for (int j = i + 1; j < len; j++) {
			auto& [rv, ra, rb] = snowman[j];
			int diff = rv - lv;

			// 서로 같은 눈덩이를 갖고 있을 때
			if (ra == la || ra == lb || rb == la || rb == lb) continue;
		
			mn = min(diff, mn);
			break;
		}
	}
	
	cout << mn;
}