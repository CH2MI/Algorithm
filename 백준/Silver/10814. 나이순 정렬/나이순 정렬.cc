#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	int age;
	string name;
};

bool incr(Data a, Data b) {
	return a.age < b.age;
}

int main() {
	int N;
	cin >> N;
	vector<Data> a;
	for (int i = 0; i < N; i++) {
		Data t;
		cin >> t.age >> t.name;
		a.push_back(t);
	}

	stable_sort(a.begin(), a.end(), incr);

	for (int i = 0; i < N; i++)
		cout << a[i].age << ' ' << a[i].name << '\n';
}