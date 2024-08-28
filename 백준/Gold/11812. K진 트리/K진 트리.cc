#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;

int GetLevel(long long a) {
	int level = 1;
	for (long long i = 1, node = 1; node <= a;) {
		i *= K;
		node += i;
		level++;
	}
	return level;
}

long long GetParent(long long a) {
	return (a - 1) / K;
}

int LCA(long long a, long long b) {
	int dist = 0;
	while (GetLevel(a) > GetLevel(b)) {
		a = GetParent(a);
		dist++;
	}
	while (GetLevel(a) < GetLevel(b)) {
		b = GetParent(b);
		dist++;
	}

	while (a != b) {
		a = GetParent(a);
		b = GetParent(b);
		dist += 2;
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long N;
	int Q;
	cin >> N >> K >> Q;

	while (Q--) {
		long long a, b;
		cin >> a >> b;
		
		if (K == 1) {
			cout << abs(a - b) << '\n';
		}
		else 
			cout << LCA(a - 1, b - 1) << '\n';
	}
}