#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	int sum = 0;
	for (auto itr = v.begin(); itr != v.end(); itr++) 
		sum += *itr;
	int average = round((double)sum / N);
	int middle = v[N / 2];
	int range = v[v.size() - 1] - v[0];
	auto itr = v.begin();
	int count = -1, mode = 0, nowCount = 1, nowmode = *itr;
	bool second = false;
	for (itr = itr + 1; itr != v.end(); itr++) {
		if (*itr == nowmode) nowCount++;
		else {
			if (count < nowCount) {
				count = nowCount;
				mode = nowmode;
				second = true;
			}
			else if (count == nowCount && second) {
				count = nowCount;
				mode = nowmode;
				second = false;
			}
			nowCount = 1;
			nowmode = *itr;
		}
	}
	if (count < nowCount) {
		count = nowCount;
		mode = nowmode;
		second = true;
	}
	else if (count == nowCount && second) {
		count = nowCount;
		mode = nowmode;
		second = false;
	}

	cout << average << '\n' << middle << '\n' << mode << '\n' << range;
}