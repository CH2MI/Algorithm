#include <iostream>
#include <cmath>
#include <algorithm>
#define x first
#define y second
using namespace std;

typedef pair<double, double> point;

int CCW(const point& A, const point& B, const point& C) {
	double ret = (A.x * B.y + B.x * C.y + C.x * A.y) - (B.x * A.y + C.x * B.y + A.x * C.y);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}

double GetDistance(const point& A, const point& B) {
	double dx = B.x - A.x;
	double dy = B.y - A.y;
	return sqrt(dx * dx + dy * dy);
}

point GetCross(const point& A, const point& B, const point& C, const point& D) {
	double d = (A.x - B.x) * (C.y - D.y) - (A.y - B.y) * (C.x - D.x);
	double n1 = (A.x * B.y - A.y * B.x);
	double n2 = (C.x * D.y - C.y * D.x);
	double x = (n1 * (C.x - D.x) - n2 * (A.x - B.x)) / d;
	double y = (n1 * (C.y - D.y) - n2 * (A.y - B.y)) / d;
	return { x, y };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cout << fixed;
	cout.precision(9);


	point p[4];
	for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;

	int x = CCW(p[0], p[1], p[2]) * CCW(p[0], p[1], p[3]);
	int y = CCW(p[2], p[3], p[0]) * CCW(p[2], p[3], p[1]);

	if (x <= 0) {

		// 한점에서 만난다.
		if (y < 0) {
			cout << 1 << '\n';
			auto c = GetCross(p[0], p[1], p[2], p[3]);
			cout << c.x << ' ' << c.y;
		}

		else if (y == 0) {
			double da = GetDistance(p[0], p[1]);
			double db = GetDistance(p[2], p[3]);
			double d = max({ GetDistance(p[0], p[2]), GetDistance(p[0], p[3]), GetDistance(p[1], p[2]), GetDistance(p[1], p[3])});

			// 한점에서 만난다.
			if (da + db == d) {
				cout << 1 << '\n';
				if (p[0] == p[2] || p[0] == p[3]) cout << p[0].x << ' ' << p[0].y;
				else cout << p[1].x << ' ' << p[1].y;
 			}

			// 한 점 or 여러 점에서 만난다.
			else if (da + db > d) {
				double dc = (p[1].y - p[0].y) / (p[1].x - p[0].x);
				double dd = (p[3].y - p[2].y) / (p[3].x - p[2].x);

				cout << 1 << '\n';

				// 기울기가 다르면 한점에서 만난다.
				if (dc != dd) {
					auto c = GetCross(p[0], p[1], p[2], p[3]);
					cout << c.x << ' ' << c.y;
				}
			}
			
			// 두 선분이 만나지 않는다.
			else {
				cout << 0;
			}
		}

		// 두 선분이 만나지 않는다.
		else {
			cout << 0;
		}
	}

	// 두 선분이 만나지 않는다.
	else {
		cout << 0;
	}

}