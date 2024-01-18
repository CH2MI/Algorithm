#include <iostream>
#include <string>
using namespace std;

int main() {
	int c, sum = 0;
	int a[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
	while ((c = cin.get() - 65) >= 0) 
		sum += a[c];
	cout << sum;
}