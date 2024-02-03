#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;

void recursion(int size, int& w, int& b, int i, int j) {

	// 해당 부분이 다 같은 색으로 이루어져 있는지 확인한다 .
	int sum = 0;
	for (int i1 = i; i1 < i + size; i1++) {
		for (int j1 = j; j1 < j + size; j1++) {
			sum += arr[i1][j1];
		}
	}
	if (sum == 0) w++;
	else if (sum == size * size) b++;

	// 두 색이 섞여 있으면 4부분으로 나누어 재귀호출한다.
	else {
		int s = size / 2;
		recursion(s, w, b, i, j);
		recursion(s, w, b, i + s, j);
		recursion(s, w, b, i, j + s);
		recursion(s, w, b, i + s, j + s);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 

	int N;
	cin >> N;
	arr.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int w = 0, b = 0;
	recursion(N, w, b, 0, 0);
	cout << w << '\n' << b;
}