#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> dist(N);
	vector<int> price(N);

	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	int k = 0;
	long long nowdist = 0;
	long long P = 1000000001;
	long long sum = 0;
	while (k < N) {

		// 현재 기름 값보다 도착한 기름 값이 싸다면 기존 지점에선 해당 지점까지의 양만 주유한다.
		if (price[k] < P || k == N - 1) {
			sum += nowdist * P;
			nowdist = dist[k];
			P = price[k];
		}

		// 비싸면 이전 주유소에서 더 주유해야한다.
		else {
			nowdist += dist[k];
		}
		k++;
	}

	cout << sum;
}