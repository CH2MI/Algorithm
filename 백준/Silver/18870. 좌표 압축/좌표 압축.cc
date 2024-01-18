#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	int value;
	int index;
};

bool incrValue(Data a, Data b) {
	return a.value < b.value;
}

bool incrIndex(Data a, Data b) {
	return a.index < b.index;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector <Data> a;
	for (int i = 0; i < N; i++) {
		Data t;
		cin >> t.value;
		t.index = i;
		a.push_back(t);
	}

	sort(a.begin(), a.end(), incrValue);

	int i = 0, count = 0;
	while (i < N) {
		int t = a[i].value;
		do {
			a[i].value = count;
			i++;
		} while (i < N - 1 && a[i].value == t );
		if (i == N - 1 && a[i].value == t) {
			a[i].value = count;
			i++;
		}
		count++;
	}

	sort(a.begin(), a.end(), incrIndex);

	for (int i = 0; i < N; i++) 
		cout << a[i].value << ' ';
	
}