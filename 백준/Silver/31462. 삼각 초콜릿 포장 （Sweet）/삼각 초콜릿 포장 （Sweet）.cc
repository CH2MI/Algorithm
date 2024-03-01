#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	cin.ignore();

	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		getline(cin, v[i]);
	}

	vector<vector<bool>> selected(N, vector<bool>(N));
	bool b = true;
	for (int i = 0; i < N; i++) {
		int l = v[i].size();
		for (int j = 0; j < l; j++) {
			if (v[i][j] == 'B' && !selected[i][j]) {
				if (i + 1 < N && j + 1 < l) {
					if (v[i][j + 1] == 'B' && v[i + 1][j + 1] == 'B') {
						selected[i][j] = selected[i][j + 1] = selected[i + 1][j + 1] = true;
					}
				}
				if (!selected[i][j]) {
					b = false; 
				}
			}
			if (v[i][j] == 'R' && !selected[i][j]) {
				if (i + 1 < N) {
					if (v[i + 1][j] == 'R' && v[i + 1][j + 1] == 'R' && !selected[i + 1][j]) {
						selected[i][j] = selected[i + 1][j] = selected[i + 1][j + 1] = true;
					}
				}
				if (!selected[i][j]) {
					b = false;
				}
			}
		}
	}
	cout << b;

}