#include <iostream>
#include <queue>
#include <map>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;

	priority_queue<pair<int, int>> easy, hard;
	map<int, int> enable;

	cin >> N;
	while (N--) {
		int P, L;
		cin >> P >> L;
		easy.push({ -L, -P });
		hard.push({ L, P });
		enable[P] = L;
	}
	
	cin >> M;
	while (M--) {
		string c;
		int P, L;
		cin >> c;
		
		if (c == "recommend") {
			cin >> P;

			if (P == 1) {
				pair<int, int> p;
				do {
					p = hard.top();
					hard.pop();

					
				} while (enable[p.second] == -1 || enable[p.second] != p.first);

				hard.push(p);
				cout << p.second << '\n';
			}

			else {
				pair<int, int> p;
				do {
					p = easy.top();
					easy.pop();


				} while (enable[-p.second] == -1 || enable[-p.second] != -p.first);

				easy.push(p);
				cout << -p.second << '\n';
			}
		}

		else if (c == "add") {
			cin >> P >> L;
			easy.push({ -L, -P });
			hard.push({ L, P });
			enable[P] = L;
		}
		else {
			cin >> P;
			enable[P] = -1;
		}
	}
}