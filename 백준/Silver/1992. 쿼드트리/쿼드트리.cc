#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

void recursion(int size, int I, int J) {

	int sum = 0;
	for (int i = I; i < I + size; i++) {
		for (int j = J; j < J + size; j++) {
			sum += v[i][j];
		}
	}

	// 한가지 숫자로 이루어졌다면 출력한다.
	if (sum == size * size) {
		cout << '1';
	}
	else if (sum == 0) {
		cout << '0';
	}

	// 다른 색이 섞여있으면 4구역으로 나누어 재귀한다.
	else {
		cout << '(';
		size >>= 1;

		recursion(size, I, J);
		recursion(size, I, J + size);
		recursion(size, I + size, J);
		recursion(size, I + size, J + size);

		cout << ')';
	}


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	v.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		cin.ignore();
		for (int j = 0; j < N; j++) {
			v[i][j] = cin.get() - '0';
		}
	}

	recursion(N, 0, 0);
}