#include <iostream>
#include <deque>
using namespace std;

bool compare(deque<char>& tmp, string& bomb) {
	int l = bomb.size();
	for (int i = 0; i < l; i++) {
		if (tmp[i] != bomb[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, bomb;
	cin >> s >> bomb;
	deque<char> storage, tmp;

	int L = s.size();
	int l = bomb.size();
	for (int i = 0; i < L; i++) {
		tmp.push_back(s[i]);

		// 비교할 문자열의 크기가 부족하면 다음 문자열을 넣는다.
		if (tmp.size() < l) continue;

		// 폭탄이 터질 때
		if (compare(tmp, bomb)) {
			tmp.clear();

			// 폭탄이 터졌다면 폭탄의 길이 - 1개 만큼 채운다.
			while (!storage.empty() && tmp.size() < l - 1) {
				tmp.push_front(storage.back());
				storage.pop_back();
			}
		}

		// 폭탄이 터지지 않았을 때
		else {
			storage.push_back(tmp.front());
			tmp.pop_front();
		}
	}

	if (storage.empty() && tmp.empty()) cout << "FRULA";
	else {
		for (auto i : storage) cout << i;
		for (auto i : tmp) cout << i;
	}
}