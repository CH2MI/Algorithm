#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string s;
vector<int> pi;

void GetPi() {
	pi.assign(N, 0);
	int i = 1, j = 0;

	for (; i < N; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> N >> s;
	pi.assign(N, 0);

	GetPi();
	cout << N - pi[N - 1];
}