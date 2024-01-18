#include <iostream>
#include <vector>
using namespace std;

int Euclidean(int a, int b) {
	if (b == 0)
		return a;
	return Euclidean(b, a % b);
}

int main() {
	int N, t, f, count = 0;
	vector<int> v;
	cin >> N >> t >> f;
	v.push_back(t);
	v.push_back(f);
	f = f - t;

	for (int i = 1; i < N - 1; i++) {
		cin >> t;
		f = Euclidean(t - v[i], f);
		v.push_back(t);
	}

	int s = v[0];
	for (int i = 1; i < N; i++) {
		s = s + f;
		if (v[i] != s) {
			count++;
			i--;
		}
	}
	cout << count;	
}