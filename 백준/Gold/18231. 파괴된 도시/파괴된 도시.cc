#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> d;
vector<int> input;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int M;
	cin >> N >> M;
	adj.assign(N, vector<int>());

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		adj[s - 1].push_back(e - 1);
		adj[e - 1].push_back(s - 1);
	}

	d.assign(N, false);
	int T;
	cin >> T;
	input.assign(T, 0);
	answer.reserve(T);
	for (int i = 0; i < T; i++) {
		cin >> input[i];

		d[--input[i]] = true;
	}

	int cnt = 0;

	for (const auto& i : input) {
		bool f = true;
		for (const auto& j : adj[i]) {
			if (!d[j]) {
				f = false;
				break;
			}
		}
		if (f) {
			cnt++;
			answer.push_back(i);
		}
	}

	

	if (!cnt) {
		cout << "-1";
	}
	else {
		for (const auto& i : answer) {
			d[i] = false;
			for (const auto& j : adj[i]) {
				d[j] = false;
			}
		}

		bool f = false;
		for (int i = 0; i < N; i++) {
			if (d[i]) {
				f = true;
				break;
			}
		}

		if (f) {
			cout << "-1";
		}
		else {
			cout << cnt << '\n';
			for (auto i : answer) {
				cout << i + 1<< ' ';
			}
		}
	}
}