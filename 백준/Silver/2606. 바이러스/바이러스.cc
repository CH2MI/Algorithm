#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<int> visited;

// 자기 자신도 카운트 하므로 -1부터 시작한다.
int cnt = -1;

void dfs(int index) {

	// 이미 방문했으면 건너뛴다.
	if (visited[index]) return;

	// 방문하지 않았다면 탐색을 진행한다.
	cnt++;
	visited[index]++; 
	for (int i = 0; i < arr[index].size(); i++) 
		dfs(arr[index][i]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	arr.assign(N, vector<int>());
	visited.assign(N, 0);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}

	dfs(0);

	cout << cnt;
	
}