#include <iostream>
#include <deque>
using namespace std;

struct balloon {
	int value;
	int index;
};

int main() {
	int N;
	cin >> N;
	deque<balloon> d;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		balloon b;
		b.value = t;
		b.index = i;
		d.push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		cout << d.front().index << ' ';
		int t1 = d.front().value;
		d.pop_front();
		if (i == N) break;
		int j = 1;
		if (t1 < 0) j = 0;
		int t2 = abs(t1);
		for (; j < t2; j++) {
			if (t1 > 0) {
				d.push_back(d.front());
				d.pop_front();
			}
			else {
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
}