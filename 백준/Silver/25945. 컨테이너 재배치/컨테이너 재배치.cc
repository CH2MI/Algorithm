#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	vector<int> v(N);
	int sum = 0;
	for (auto& i : v) {
		cin >> i;
		sum += i;
	}
	
	int l = 0, r = 0;
	if (sum % N == 0) {
		int mid = sum / N;

		for (auto& i : v) {
			if (i < mid) l += mid - i;
			else r += i - mid;
		}
		cout << max(l, r);
	}
	else {
		int lo = sum / N;
		int hi = lo + 1;

		for (auto& i : v) {
			if (i < lo) l += lo - i;
			else if (i > hi) r += i - hi;
		}
		cout << max(l, r);
	}


}