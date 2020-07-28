#include<cstdio>

int main() {
   long long N;
   scanf("%lld", &N);

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
