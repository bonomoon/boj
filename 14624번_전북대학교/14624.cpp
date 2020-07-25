#include<iostream>

using namespace std;

int main() {
   int n;
   int t;
   cin >> n;
   if (n % 2 == 0) {
      cout << "I LOVE CBNU";
   }
   else {
      int tmp = (n / 2) + 1;
      for (int i = 0; i < n; i++) {
         cout << "*";
      }
      cout << endl;

      for (int j = 0; j < tmp - 1; j++)
         cout << " ";
      cout << "*";
      cout << endl;
      t = tmp - 2;
      int a = 1;
      for (int i = 1; i < tmp; i++) {
         for (int j = 0; j < t; j++) {

            cout << " ";
         }
         cout << "*";
         for (int k = 0; k < a; k++) {
            cout << " ";
         }
         a += 2;
         t--;
         cout << "*";
         cout << endl;

      }
   }
}
