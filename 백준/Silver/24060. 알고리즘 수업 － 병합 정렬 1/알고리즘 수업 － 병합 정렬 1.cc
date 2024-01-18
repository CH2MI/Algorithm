#include <iostream>
using namespace std;

int c = 0, K;

void merge(int *a, int p, int q, int r) {
	int i = p; int j = q + 1; int t = 0;
	int* tmp = new int[r + 1];
	while (i <= q && j <= r) {
		if (a[i] <= a[j]) {
			tmp[t++] = a[i++];
		}
		else tmp[t++] = a[j++];
	}
	while (i <= q) tmp[t++] = a[i++];
	while (j <= r) tmp[t++] = a[j++];
	i = p; t = 0;
	while (i <= r) {
		a[i++] = tmp[t++];
		c++;
		if (c == K) cout << tmp[t - 1];
	}
	delete[] tmp;
}

void merge_sort(int *a, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N >> K;
	int* a = new int[N];
	for (int i = 0; i < N; i++) cin >> a[i];
	
	merge_sort(a, 0, N - 1);
	if (c < K) cout << "-1";
}