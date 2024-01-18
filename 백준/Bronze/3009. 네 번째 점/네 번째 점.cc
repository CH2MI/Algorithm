#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> ax, ay;
	int x, y;
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		ax.push_back(a);
		ay.push_back(b);
	}
	for (int i = 0; i < 3; i++) {
		if (count(ax.begin(), ax.end(), ax[i]) == 1) x = ax[i];
		if (count(ay.begin(), ay.end(), ay[i]) == 1) y = ay[i];
	}
	cout << x << ' ' << y;
}