#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	getline(cin, s);

	// 초기 값 설정
	int i = 0;
	string a;
	while (s[i] != '+' && s[i] != '-') a.push_back(s[i++]);
	int sum = stoi(a);
	int tmp = 0;
	bool sub = false;

	for (; i < s.size();) {
		string t;

		// 빼기가 나왔을 때
		if (s[i++] == '-') {

			// 빼기가 나온 적이 있으면 모아놓은 합을 sum에 빼준다.
			if (sub) sum -= tmp;

			// 처음 나왔으면 모아놓은 합을 sum에 넣어준다.
			else sum += tmp;

			// 처음 나왔는 지 구별을 위해 true로 바꿔준다.
			sub = true;
			tmp = 0;
		}

		while (s[i] != '+' && s[i] != '-' && i < s.size())
			t.push_back(s[i++]);
		tmp += stoi(t);
	}

	// 뺄셈이 나왔으면 모아놓은 합을 sum에 빼준다.
	if (sub) cout << sum - tmp;

	// 안나왔으면 더해준다.
	else cout << sum + tmp;
}