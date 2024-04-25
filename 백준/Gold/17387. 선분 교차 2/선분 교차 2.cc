#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<long long, long long> Point;

long long CCW(Point p1, Point p2, Point p3) {
	long long ret = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);

	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}

double getDistance(Point p1, Point p2) {
	double x = p2.first - p1.first;
	double y = p2.second - p1.second;
	return sqrt(x * x + y * y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Point p1, p2, p3, p4;
	cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

	int x = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int y = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	// 겹치는 후보일 때
	if (x <= 0) {

		// 그래도 방향이 다르면 겹친다.
		if (y < 0) {
			cout << '1';
		}

		// 한 직선 위에 있을 때
		else if (!y) {
			double Adist = getDistance(p1, p2);
			double Bdist = getDistance(p3, p4);
			double dist = max({ getDistance(p1, p3), getDistance(p1, p4), getDistance(p3, p2), getDistance(p4, p2)});

			// 총 길이가 두 길이 합한 것 보다 크면 겹치지 않는다.
			if (dist > Adist + Bdist) {
				cout << '0';
			}

			// 같거나 작으면 겹친다.
			else cout << '1';
		}

		// 같으면 겹치지 않는다.
		else cout << '0';
	}

	// 안겹침
	else {
		cout << '0';
	}
}