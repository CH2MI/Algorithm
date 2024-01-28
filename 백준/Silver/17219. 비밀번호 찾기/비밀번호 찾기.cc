#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_map<string, string> map;
	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		map.insert(make_pair(a, b));
	}

	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		cout << map[a] << '\n';
	}
}