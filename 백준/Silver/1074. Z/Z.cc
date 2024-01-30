#include <iostream>
#include <cmath>
using namespace std;



//void recursion(int n, int r, int c, int& cnt, int& flag) {
//	if (n == 1) {
//		if (R == r && C == c) {
//			cout << cnt << '\n';
//			flag = 1;
//		}
//		++cnt;
//		return;
//	}
//	if (flag) return;
//	// 각 사분면에 대해 돈다.
//	recursion(n / 2, r, c, cnt, flag);
//	recursion(n / 2, r, c + n / 2, cnt, flag);
//	recursion(n / 2, r + n / 2, c, cnt, flag);
//	recursion(n / 2, r + n / 2, c + n / 2, cnt, flag);
//}

void recursion(int n, int r, int c, int& cnt) {
	if (n == 1) return;

	// 현재 좌표가 어느 위치에 있는 지 파악한다.
	if (r < n / 2) {

		// 왼쪽 상단 : 그대로 지나가면 된다.
		if (c < n / 2) {
			recursion(n / 2, r, c, cnt);
		}

		// 오른쪽 상단 : 두번째로 지나가는 부분이니 이전 횟수를 더해주고 재귀한다.
		else {
			cnt += pow(n / 2, 2);
			recursion(n / 2, r, c - n / 2, cnt);
		}
	}
	else {

		// 왼쪽 하단 : 세번째로 지나가는 부분이니 이전 횟수를 더해주고 재귀한다.
		if (c < n / 2) {
			cnt += 2 *pow(n / 2, 2);
			recursion(n / 2, r - n / 2, c, cnt);
		}

		// 오른쪽 하단 : 네번째로 지나가는 부분이니 이전 횟수를 더해주고 재귀한다.
		else {
			cnt += 3 * pow(n / 2, 2);
			recursion(n / 2, r - n / 2, c - n / 2, cnt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, R, C;
	cin >> N >> R >> C;
	N = pow(2, N);
	int cnt = 0;

	recursion(N, R, C, cnt);
	cout << cnt;
}