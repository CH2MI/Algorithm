#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(20, 0);
	for (int i = 0; i < N; i++) {
		string s;
		int t;
		cin >> s;
		if (s == "add") {
			cin >> t;
			v[t - 1] = 1;
		}
		else if (s == "remove") {
			cin >> t;
			v[t - 1] = 0;
		}
		else if (s == "check") {
			cin >> t;
			cout << v[t - 1] << '\n';
		}
		else if (s == "toggle") {
			cin >> t;
			v[t - 1] = !v[t - 1];
		}
		else if (s == "all") {
			for (int i = 0; i < 20; i++)
				v[i] = 1;
		}
		else {
			for (int i = 0; i < 20; i++)
				v[i] = 0;
		}
	}
}