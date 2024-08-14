#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> A(N, vector<int>(N, 5));
	vector<vector<int>> B(N, vector<int>(N));
	for (auto& i : B)
		for (auto& j : i)
			cin >> j;

	vector<vector<deque<int>>> Trees(N, vector<deque<int>>(N, deque<int>()));

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Trees[x - 1][y - 1].push_front(z);
	}
	vector<pair<int, int>> Breed;
	Breed.reserve(100000);

	while (K--) {
		
		// 봄
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				auto& s = Trees[i][j];

				int t = s.size();
				for (int k = 0; k < s.size(); k++) {

					// 양분을 먹을 수 있을 때
					if (s[k] <= A[i][j]) {
						A[i][j] -= s[k];
						s[k] += 1;

						// 번식을 할 수 있는 나이
						if (s[k] % 5 == 0) {
							Breed.push_back({ i, j });
						}
					}

					else {
						t = k;
						break;
					}
				}

				// 여름
				for (int k = s.size() - 1; k >= t; k--) {
					A[i][j] += s[k] / 2;
					s.pop_back();
				}			
			}
		}

		// 가을
		for (auto& [x, y] : Breed) {
			for (int k = 0; k < 8; k++) {
				int i = x + dy[k];
				int j = y + dx[k];

				if (i < 0 || i >= N || j < 0 || j >= N) continue;
				Trees[i][j].push_front(1);
			}
		}
		Breed.clear();

		// 겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] += B[i][j];
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			count += Trees[i][j].size();
		}
	}

	cout << count;
}