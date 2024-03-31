#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp_min[2][3], dp_max[2][3];

void calculate(int i, int j, int a, int b, int c) {
	dp_max[i][0] = a + max(dp_max[j][0], dp_max[j][1]);
	dp_max[i][1] = b + max({ dp_max[j][0], dp_max[j][1], dp_max[j][2] });
	dp_max[i][2] = c + max(dp_max[j][1], dp_max[j][2]);

	dp_min[i][0] = a + min(dp_min[j][0], dp_min[j][1]);
	dp_min[i][1] = b + min({ dp_min[j][0], dp_min[j][1], dp_min[j][2] });
	dp_min[i][2] = c + min(dp_min[j][1], dp_min[j][2]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	int a, b, c;
	bool index = false;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		calculate(index, !index, a, b, c);
		index = !index;
	}

	cout << max({ dp_max[!index][0], dp_max[!index][1], dp_max[!index][2] }) << ' ' << min({ dp_min[!index][0], dp_min[!index][1], dp_min[!index][2] });
}
