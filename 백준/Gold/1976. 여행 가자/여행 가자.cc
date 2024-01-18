#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int Find(int n) {
	if (v[n] == n) return n;
	return v[n] = Find(v[n]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A < B)
		v[B] = A;
	else
		v[A] = B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		v.push_back(i);

	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> t;
			if (t) {
				Union(i, j);
			}
		}
	}
	cin >> t;
	int a = Find(v[t - 1]);
	int i;
	for (i = 1; i < M; i++) {
		cin >> t;
		if (a != Find(v[t - 1])) break;
	}

	if (i == M) cout << "YES";
	else cout << "NO";
}