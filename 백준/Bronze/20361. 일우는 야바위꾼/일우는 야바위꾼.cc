#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N, X, K;
   cin >> N >> X >> K;
   
   vector<bool> cup(N);
   cup[X - 1] = true;
   
   for (int i = 0; i < K; i++) {
       int A, B;
       cin >> A >> B;
       swap(cup[A - 1], cup[B - 1]);
   }
   
   for (int i = 0; i < N; i++) {
       if (cup[i]) {
           cout << i + 1;
       }
   }
}