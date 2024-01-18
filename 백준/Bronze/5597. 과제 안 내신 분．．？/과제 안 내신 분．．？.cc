#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> list;
	for (int i = 0; i < 30; i++) list.push_back(i + 1);
	
	for (int i = 0; i < 28; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < list.size(); j++) 
			if (n == list[j]) 
				list.erase(list.begin() + j);
	}

	for (int i = 0; i < list.size(); i++) 
		cout << list[i] << endl;
}