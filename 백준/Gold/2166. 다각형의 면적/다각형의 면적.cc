#include <iostream>
#include <vector>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<double, double> lld;

inline double CalArea(const lld& a, const lld& b, const lld& c) {
	double sum = 0;
	sum = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
	return sum / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;

	vector<lld> v(N);

	for (auto& [a, b] : v) {
		cin >> a >> b;
	}

	double sum = 0;
	for (int i = 2; i < N; i++) {
		sum += CalArea(v[0], v[i - 1], v[i]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(sum);
}