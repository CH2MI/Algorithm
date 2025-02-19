#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 끝나는 시간을 기준으로 오름차순한다.
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), cmp);

	int endTime = 0;
	int count = 0;

	for (auto& i : v) {

		// 시작 시간이 마지막 끝난 시간보다 크거나 같으면 선택한다.
		if (i.first >= endTime) {
			count++;
			endTime = i.second;
		}
	}
	cout << count;
}