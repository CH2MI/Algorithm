#include <iostream>
using namespace std;

typedef pair<long long, long long> Point;

long long CCW(Point p1, Point p2, Point p3) {
	long long ret =  p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
		
	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}	


bool cross(Point P[]) {
	long long A = CCW(P[0], P[1], P[2]) * CCW(P[0], P[1], P[3]);
	long long B = CCW(P[2], P[3], P[0]) * CCW(P[2], P[3], P[1]);
	return (A < 0 && B < 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Point P[4];
	for (int i = 0; i < 4; i++) {
		cin >> P[i].first >> P[i].second;
	}

	cout << cross(P);
}	