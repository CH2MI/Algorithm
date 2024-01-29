#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {

		// key : 의상의 종류, value : 의상의 개수
		unordered_map<string, int> costumes;

		int N;
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;

			costumes[b]++;
		}

		int sum = 1;
		
		// 의상을 입는 경우의 수 = 각 의상의 개수 + 1(옷을 입지 않을 때)를 곱해준다.
		for (auto i : costumes) {
			sum *= i.second + 1;
		}

		// 모두 입지 않는 경우의 수 1개를 빼준다.
		cout << --sum << '\n';
	}
}