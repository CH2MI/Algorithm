#include <iostream>
using namespace std;

typedef pair<long long, long long> Point;

long long CCW(Point p1, Point p2, Point p3) {
	long long ret = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);

	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Point p1, p2, p3;
	cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;

	cout << CCW(p1, p2, p3);
}