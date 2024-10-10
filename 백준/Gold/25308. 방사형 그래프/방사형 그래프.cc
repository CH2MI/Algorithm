#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double px[8] = { 0, sqrt(2) / 2, 1, sqrt(2) / 2, 0, -sqrt(2) / 2, -1, -sqrt(2) / 2 };
double py[8] = { 1, sqrt(2) / 2, 0, -sqrt(2) / 2, -1, -sqrt(2) / 2, 0, sqrt(2) / 2 };

vector<int> v(8), sel;
vector<bool> visited(8);

bool CCW(double ax, double ay, double bx, double by, double cx, double cy) {
	double sum = ax * by + bx * cy + cx * ay - bx * ay - cx * by - ax * cy;

	return sum <= 0;
}

bool Correct() {
	for (int i = 0; i < 8; i++) {
		if (!CCW(px[i] * sel[i], py[i] * sel[i], px[(i + 1) % 8] * sel[(i + 1) % 8], py[(i + 1) % 8] * sel[(i + 1) % 8], px[(i + 2) % 8] * sel[(i + 2) % 8], py[(i + 2) % 8] * sel[(i + 2) % 8])) {
			return false;
		}
	}
	return true;
}

int BackTracking(int cnt) {
	if (cnt == 8) {
		// 해당 조건으로 만들 수 있는지 확인해본다.
		return Correct();
	}

	int c = 0;
	for (int i = 0; i < 8; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		sel.push_back(v[i]);
		c += BackTracking(cnt + 1);
		sel.pop_back();
		visited[i] = false;
	}
	return c;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (auto& i : v) cin >> i;

	sel.reserve(8);
	
	cout << BackTracking(0);
}