#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> points;
vector<int> parent;
vector<tuple<double, int, int>> dists;

inline double GetDist(const pair<int, int>& A, const pair<int, int>& B) {
	double dist = pow(abs(A.first - B.first), 2) + pow(abs(A.second - B.second), 2);
	return sqrt(dist);
}

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return false;

	parent[B] = A;
	return true;
}

double Kruskal(int cnt) {
	int index = 0;
	double sum = 0;
	while (cnt < N - 1) {
		auto& [dist, i, j] = dists[index];
		if (Union(i, j)) {
			sum += dist;
			cnt++;
		}
		index++;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M;
	cin >> N >> M;

	points.assign(N, pair<int, int>());
	parent.assign(N, -1);
	dists.reserve(N * (N - 1));

	for (auto& [x, y] : points) cin >> x >> y;
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			dists.push_back({ GetDist(points[i], points[j]), i, j });
		}

	}
	sort(dists.begin(), dists.end());

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		if (Union(s - 1, e - 1)) cnt++;
	}

	cout << fixed;
	cout.precision(2);
	cout << Kruskal(cnt);
}