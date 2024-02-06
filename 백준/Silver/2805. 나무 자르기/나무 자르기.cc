#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool f(long long M, int mid) {
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {

		// 절단기 높이가 나무보다 클 때 잘라낸 조각의 크기를 더한다.
		if (v[i] <= mid) continue;
		sum += v[i] - mid;
	}

	// 잘라낸 나무가 M보다 길면 참을 반환
	if (sum >= M) return true;
	return false;
}

int solve(int M) {
	int left = 0;
	int right = 1000000000;
	int ans = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		// 잘라낸 나무가 M보다 크면 절단기의 높이를 높여본다.
		if (f(M, mid)) {
			left = mid + 1;
			ans = mid;
		}

		// 나무가 부족하므로 절단기의 높이를 낮춰본다.
		else {
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	v.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	cout << solve(M);
}