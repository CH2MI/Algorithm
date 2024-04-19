#include <iostream>
#include <vector>
#include <cmath>
#define MAX 4000000
using namespace std;

bool arr[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector<int> Prime;

	for (int i = 2; i <= MAX; i++) {
		if (!arr[i]) {
			Prime.push_back(i);
			for (int j = i + i; j <= MAX; j += i) {
				arr[j] = 1;	
			}
		}
	}
	int N;
	cin >> N;

	int len = Prime.size();
	int l, r, sum, cnt;
	l = r = cnt = 0;
	sum = Prime[0];

	while (r < len) {
		if (sum < N) {
			if (++r < len) sum += Prime[r];
		}

		else if (sum > N) {
			sum -= Prime[l++];
		}
		
		else {
			++cnt;
			sum = sum - Prime[l++] + Prime[++r];
		}
	}
	cout << cnt;
}	