#define INF 100000000
#include<iostream>
#include <queue>
using namespace std;

void dijkstra(int** arr, int** dis, int x, int y, int N) {
	priority_queue<pair<int, pair<int, int>>> pq;

	dis[x][y] = 0;
	pq.push({ 0, { x, y } });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_nodeX = pq.top().second.first;
		int cur_nodeY = pq.top().second.second;
		pq.pop();

		if (cur_dist != dis[cur_nodeX][cur_nodeY]) continue;

		// 상하좌우 거리를 갱신하면서 거리가 기존보다 짧으면 우선순위 큐에 넣어준다.
		if (cur_nodeX != 0) {
			int left_dist = cur_dist + arr[cur_nodeX - 1][cur_nodeY];
			if (left_dist < dis[cur_nodeX - 1][cur_nodeY]) {
				dis[cur_nodeX - 1][cur_nodeY] = left_dist;
				pq.push({ -left_dist, {cur_nodeX - 1, cur_nodeY} });
			}
		}
		if (cur_nodeY != 0) {
			int up_dist = cur_dist + arr[cur_nodeX][cur_nodeY - 1];
			if (up_dist < dis[cur_nodeX][cur_nodeY - 1]) {
				dis[cur_nodeX][cur_nodeY - 1] = up_dist;
				pq.push({ -up_dist, {cur_nodeX, cur_nodeY - 1} });
			}
		}
		if (cur_nodeX != N - 1) {
			int right_dist = cur_dist + arr[cur_nodeX + 1][cur_nodeY];
			if (right_dist < dis[cur_nodeX + 1][cur_nodeY]) {
				dis[cur_nodeX + 1][cur_nodeY] = right_dist;
				pq.push({ -right_dist, {cur_nodeX + 1, cur_nodeY} });
			}
		}
		if (cur_nodeY != N - 1) {
			int down_dist = cur_dist + arr[cur_nodeX][cur_nodeY + 1];
			if (down_dist < dis[cur_nodeX][cur_nodeY + 1]) {
				dis[cur_nodeX][cur_nodeY + 1] = down_dist;
				pq.push({ -down_dist, {cur_nodeX, cur_nodeY + 1} });
			}
		}
		
	}
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		cin.ignore();
		int** arr = new int*[N];
		int** dis = new int* [N];
		for (int i = 0; i < N; i++) {
			arr[i] = new int[N];
			dis[i] = new int[N];
			for (int j = 0; j < N; j++) {
				arr[i][j] = cin.get() - 48;
				dis[i][j] = INF;
			}
			cin.ignore();
		}
		dijkstra(arr, dis, 0, 0, N);
		cout << "#" << test_case << ' ';
		cout << dis[N - 1][N - 1] << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}