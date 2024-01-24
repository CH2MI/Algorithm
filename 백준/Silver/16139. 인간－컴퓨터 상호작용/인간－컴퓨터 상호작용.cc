#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	int N;
	cin >> s >> N;
	vector<vector<int>> sum;
	// 26개 배열을 만들어 각알파벳이 나온 합을 계속해서 sum에 푸시한다.
	vector<int> v(26, 0);
	sum.push_back(v);
	for (int i = 0; i < s.size(); i++) {
		v[s[i] - 'a']++;
		sum.push_back(v);
	}
	// 누적 합을 이용해 계산한다.
	for (int i = 0; i < N; i++) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		int d = a - 'a';
		cout << sum[c + 1][d] - sum[b][d] << '\n';
	}
}
