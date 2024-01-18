#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> v;
	deque<int> d;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (v[i] == 0) d.push_back(t);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int T;
		cin >> T;
		d.push_front(T);
		cout << d.back() << ' ';
		d.pop_back();
	}
}