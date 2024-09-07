#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	string name;
	int k, m, e;
};

bool cmp(const Data& A, const Data& B) {
	if (A.k == B.k && A.m == B.m && A.e == B.e) {
		return A.name < B.name;
	}
	else if (A.k == B.k && A.e == B.e) {
		return A.m > B.m;
	}
	else if (A.k == B.k) {
		return A.e < B.e;
	}
	return A.k > B.k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	vector<Data> datas(N);

	for (int i = 0; i < N; i++) {
		cin >> datas[i].name >> datas[i].k >> datas[i].e >> datas[i].m;
	}

	sort(datas.begin(), datas.end(), cmp);

	for (auto& data : datas) {
		cout << data.name << '\n';
	}
}