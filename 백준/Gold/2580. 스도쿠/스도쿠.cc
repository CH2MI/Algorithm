#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

struct coordinate {
	int x, y;
	coordinate(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

vector<coordinate> v;
int arr[MAX][MAX];

bool is_Right(coordinate c, int value) {
	int x = c.x, y = c.y;

	for (int i = 0; i < MAX; i++) 
		if (arr[x][i] == value) return false;
	for (int i = 0; i < MAX; i++)
		if (arr[i][y] == value) return false;

	while (x % 3 != 0) x--;
	while (y % 3 != 0) y--;
	for (int i = x; i < x + 3; i++) 
		for (int j = y; j < y + 3; j++) 
			if (arr[i][j] == value) return false;
		
	return true;
}

bool solve(int count, int index) {
	if (count == 0) return true;
	bool result = false;;
	coordinate c = v[index];
	for (int i = 1; i <= MAX; i++) {
		if (is_Right(c, i)) {
			arr[c.x][c.y] = i;
			if (solve(count - 1, index + 1)) {
				result = true;
				break;
			}
			else arr[c.x][c.y] = 0;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int count = 0;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				count++;
				coordinate t(i, j);
				v.push_back(t);
			}
		}
	}
	solve(count, 0);


	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}