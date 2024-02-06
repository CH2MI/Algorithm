#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		int n;
		string command, l;
		cin >> command >> n;
		deque<int> d;
		cin.ignore();
		getline(cin, l);
		int i = 1;

		// 문자열 파싱
		while (l[i] != ']') {
			string t;
			if (l[i] == ',') i++;
			while (l[i] != ',' && l[i] != ']') t.push_back(l[i++]);
			d.push_back(stoi(t));
		}
		
		// 실제로 뒤집지 않고 뒤집어지는지 판단만 한다.
		bool R = false;
		bool f = true;
		i = 0;
		for (; i < command.size(); i++) {

			// R이면 뒤집는다.
			if (command[i] == 'R') R = !R;
			else {

				// D일 때 비어있으면 error를 출력한다.
				if (d.empty()) {
					cout << "error\n";
					f = false;
					break;
				}
				else {
					
					// 뒤집어지지 않았으면 처음 값을 제거한다.
					if (!R) d.pop_front();

					// 뒤집어졌다면 마지막 값을 제거한다.
					else d.pop_back();
				}
			}
		}
		
		// 값을 출력한다.
		if (f) {
			cout << '[';
			if (!R && !d.empty()) {
				auto itr = d.begin();
				for (; itr != (d.end() - 1); itr++) {
					cout << *itr << ',';
				}
				cout << *itr;
			}
			else if (R && !d.empty()){
				auto itr = d.rbegin();
				for (; itr != (d.rend() - 1); itr++) {
					cout << *itr << ',';
				}
				cout << *itr;
			}
			cout << "]\n";
		}
	}
}