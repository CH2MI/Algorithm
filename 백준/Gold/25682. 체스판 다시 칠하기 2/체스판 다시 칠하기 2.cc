#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K; 
	vector<string> arr;
	vector<vector<int>> sum1(N + 1, vector<int>(M + 1));
	vector<vector<int>> sum2(N + 1, vector<int>(M + 1));
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		arr.push_back(s);
	}
	
	// 칠해야 하는 갯수를 구한다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if ((i + j - 2) % 2 == 0) {
				if (arr[i - 1][j - 1] == 'B') {
					sum1[i][j]++;
				}
				else {
					sum2[i][j]++;
				}
			}
			else if ((i + j - 2) % 2 == 1) {
				if (arr[i - 1][j - 1] == 'B') {
					sum2[i][j]++;
				}
				else {
					sum1[i][j]++;
				}
			}
			sum1[i][j] += sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
			sum2[i][j] += sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
		}
	}

	int Min = K * K;

	for (int i = 1; i <= N - K + 1; i++) {
		for (int j = 1; j <= M - K + 1; j++) {
			int i1 = i + K - 1;
			int j1 = j + K - 1;

			// 구간에서 칠해야하는 개수를 구한다.
			int n1 = sum1[i1][j1] - sum1[i - 1][j1] - sum1[i1][j - 1] + sum1[i - 1][j - 1];
			int n2 = sum2[i1][j1] - sum2[i - 1][j1] - sum2[i1][j - 1] + sum2[i - 1][j - 1];
			Min = min({Min, n1, n2});
		}
	}
	cout << Min;
	
}