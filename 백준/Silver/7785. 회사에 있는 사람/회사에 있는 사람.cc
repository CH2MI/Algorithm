#include <iostream>
#include <map>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	map<string, string> m;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name, value;
		cin >> name >> value;
		if (value == "enter")
			m.insert(make_pair(name, value));
		else {
			m.erase(name);
		}
	}

	for (auto iter = m.rbegin(); iter != m.rend(); iter++)
		cout << iter->first << '\n';
}