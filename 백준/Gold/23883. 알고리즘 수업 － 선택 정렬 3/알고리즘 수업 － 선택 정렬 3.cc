#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	map<int, int> m;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		m.emplace(t, i);
		v.push_back(t);
	}

	int a, b, cnt = 0;
	auto itr = m.rbegin();
	int i = N - 1;
	bool check = false;

	while (K--) {

		// 횟수가 남았는데 다 끝났다면
		if (itr == m.rend()) {
			check = true;
			break;
		}

		// 교환 해야 댐
		if (itr->second != i) {
			int j = itr->second;

			// 맵에서 스왑
			m[v[i]] = itr->second;
			itr->second = i;

			// 벡터에서 스왑
			int t = v[i];
			v[i] = v[j];
			v[j] = t;

			a = min(v[i], t);
			b = max(v[i], t);
			//cout << "갱신 " << a << ' ' << b << '\n';
		}

		// 교환 안해도 됨
		else {
			K++;
		}
		itr++;
		i--;
	}
	if (check) cout << "-1\n";
	else {
		cout << a << ' ' << b << '\n';
	}
}
