#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	vector<long long> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int l = 0;
	int r = N - 1;
	
	int retl, retr;
	long long ret = 1e15;

	while (l < r) {
		long long sum = v[l] + v[r];
		if (abs(sum) < ret) {
			ret = abs(sum);
			retl = l;
			retr = r;
		}

		if (sum > 0) r--;
		else l++;
	}

	cout << v[retl] << ' ' << v[retr];
}