#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
	int x, y;
};

bool incr(coordinate a, coordinate b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<coordinate> a;

	for (int i = 0; i < N; i++) {
		coordinate t;
		cin >> t.x >> t.y;
		a.push_back(t);
	}

	sort(a.begin(), a.end(), incr);

	for (int i = 0; i < N; i++) 
		cout << a[i].x << ' ' << a[i].y << '\n';
}