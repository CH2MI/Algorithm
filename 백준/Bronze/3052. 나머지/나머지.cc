#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> list;

	int a, t;
	cin >> a;
	t = a % 42;
	list.push_back(t);

	for (int i = 0; i < 9; i++) {
		cin >> a;
		t = a % 42;
		int j;
		for (j = 0; j < list.size(); j++) {
			if (t == list[j]) break;
		}
		if (j == list.size()) list.push_back(t);
	}

	cout << list.size();
}