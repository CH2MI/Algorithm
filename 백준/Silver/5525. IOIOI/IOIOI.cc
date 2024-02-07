#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (s[i] == 'I') {
			int t = 0;
			while (i < M && s[i + 1] == 'O' && s[i + 2] == 'I') {
				t++;
				i += 2;
				if (t == N) {
					t--;
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}