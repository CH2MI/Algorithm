#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> answer, pi;

void GetPi(const string& P) {
	int len = (int)P.size();
	pi.assign(len, 0);
	int i = 1, j = 0;

	for (; i < len; i++) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}
}

void KMP(const string& T, const string& P) {
	GetPi(P);

	int lenT = (int)T.size();
	int lenP = (int)P.size();
	int i = 0, j = 0;

	for (; i < lenT; i++) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == lenP - 1) {
				answer.push_back(i - (lenP - 1));
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	KMP(T, P);

	cout << answer.size() << '\n';
	for (const auto& i : answer) cout << i + 1 << ' ';
}