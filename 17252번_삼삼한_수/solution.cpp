#include<cstdio>

int main() {
   int N;
   scanf("%d", &N);

   if (N == 0) {
      printf("NO\n");
      return 0;
   }

   while(N != 0) {
      if (N % 3 == 2) {
         break;
      }
      N /= 3;
   }
   printf("%s\n", N > 0  ? "NO" : "YES");

   return 0;
}
