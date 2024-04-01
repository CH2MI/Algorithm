#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

int D, N, U, T;
vector<pair<int, int>> Tree;
queue<tuple<int, int, int>> q;

int twintale = 0, ponitale = 0;
int roomcnt = 0;

void bfs() {
	q.emplace(1, 0, U);
	while (!q.empty()) {
		auto [i, time, add] = q.front();
		q.pop();

		roomcnt++;

		auto R = Tree[i];

		// 갈라질 때
		if (R.first != 0 && R.second != 0) {
			add += T;
			q.emplace(R.first, time + add, add);
			q.emplace(R.second, time + add, add);
		}

		// 왼쪽으로만 갈 때
		else if (R.first != 0) {
			q.emplace(R.first, time + add, add);
		}

		// 오른쪽으로 갈 때
		else if (R.second != 0) {
			q.emplace(R.second, time + add, add);
		}

		// 못갈 때
		else
			twintale = max(twintale, time);
	}
}

void dfs(int i, int& cnt, int& sum) {

	auto R = Tree[i];

	// 최초 도착
	sum += U;
	cnt++;

	// 제일 마지막 방이면
	if (cnt = roomcnt)
		ponitale = sum;

	// 왼쪽 방에 갔다 오기
	if (R.first) {
		dfs(R.first, cnt, sum);
		sum += U;
	}

	// 오른쪽 방에 갔다 오기
	if (R.second) {
		dfs(R.second, cnt, sum);
		sum += U;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> D >> N >> U >> T;
	D = (int)pow(2, D) - 1;
	
	Tree.assign(D + 1, { 0, 0 });
	for (int i = 1; i <= D; i++) {
		if (2 * i <= D) Tree[i].first = 2 * i;
		if (2 * i + 1 <= D) Tree[i].second = 2 * i + 1;
	}

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		if (e % 2) Tree[s].second = 0;
		else Tree[s].first = 0;
	}

	int sum = 0, cnt = 0;
	bfs();
	dfs(1, cnt, sum);

	// 시작 1은 미포함 하므로 감소한다.
	ponitale -= U;

	if (twintale > ponitale)
		cout << ":blob_twintail_sad:";
	else if (twintale < ponitale)
		cout << ":blob_twintail_aww:";
	else
		cout << ":blob_twintail_thinking:";
}