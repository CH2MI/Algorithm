#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class coordinate {
public:
	int x, y;
	coordinate(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool operator < (const coordinate a) {
		if (x < a.x || (x == a.x && y < a.y)) return true;
		return false;
	}
	bool operator > (const coordinate a) {
		if (x > a.x || (x == a.x && y > a.y)) return true;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<coordinate> a;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		coordinate t(x, y);
		a.push_back(t);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < N; i++) {
		cout << a[i].x << ' ' << a[i].y << '\n';
	}
}