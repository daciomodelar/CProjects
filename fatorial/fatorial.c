#include <stdio.h>
#include <stdlib.h>

unsigned long fatorial(int n);
// 8 -> 8 * 7 * 6 ..... * 1
/**
argc - arguments count
argv - arguments values
*/

int main(int argc, char* argv[]) {

   if (argc < 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

   int n = atoi(argv[1]);
   if (n > 22) {
     printf("Parâmetro máximo: 22\n");
     return 1;
   }
   //printf("Parametro: %d\n", n);

   unsigned long r = fatorial(n);
   printf("Fatorial(%d)=%lu\n", n, r);

}

unsigned long fatorial(int n) {

  if ((n == 0) || (n == 1)) {
    return 1;
  }

  unsigned long r = n * fatorial(n - 1);
  //printf("Recursividade %lu\n", r);
  return r;
}

