#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long gcd(long m, long n) {
  if ((m % n) == 0) { // Base case
    return n;
  } else {
    return gcd(n, m%n);
  }
}

int extendedEuclideanAlg(long _a, long _b, long xr1, long xr2, long yr1, long yr2,\
    long a, long b, long q, long r, char *eeaTabs, long iter, int oldFL) {
  
  if (r == 0) {
    printf("x = %ld, y = %ld, gcd(%ld, %ld) = %ld\n", xr2, yr2, _a, _b, b);
    printf("ax + by = %ld(%ld) + %ld(%ld) = %ld\n", _a, xr2, _b, yr2, b);
    return 0;
  }

  long newX = -1 * xr2 + xr1;
  long newY = -1 * yr2 + yr1;
  long axby = _a * newX + _b * newY;
  long newA = b;
  long newB = r;
  long newQ = newA/newB;
  long newR = newA%newB;

  char a_str[256], b_str[256], q_str[256], r_str[256];
  sprintf(a_str, "%ld", newA);
  sprintf(b_str, "%ld", newB);
  sprintf(q_str, "%ld", newQ);
  sprintf(r_str, "%ld", newR);

  int newFL = (strlen(a_str) + strlen(b_str) + strlen(q_str) + strlen(r_str));
  if ((newFL%8) < 7 && (newFL%8) > 0) {
    eeaTabs = "\t";
    if (newFL < (oldFL-4))
      eeaTabs = "\t\t";
  }

  printf("-%ldrow%ld + row%ld\t|%ld\t|%ld\t|%ld\t\t|%ld = %ld(%ld) + %ld%s|  %ld\n",\
      q, iter + 1, iter, newX, newY, axby, newA, newB, newQ, newR, eeaTabs, newQ);
  extendedEuclideanAlg(_a, _b, xr2, newX, yr2, newY, newA, newB, newQ, newR,\
      eeaTabs, ++iter, oldFL);
  return 0;
}

int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Incorrect number of arguments!\nUsage: ./eea [int] [int]\n");
    return 0;
  }

  char *test;
  char *test2;
  long a = strtol(argv[1], &test, 10);
  long b = strtol(argv[2], &test2, 10);
  long q, r;
  if (a > b) {
    q = a / b;
    r = a % b;
  } else {
    q = b / a;
    r = b % a;
  }

  char q_str[256], r_str[256];
  sprintf(q_str, "%ld", q);
  sprintf(r_str, "%ld", r);

  printf("ax + by = gcd(a,b) | a = %ld, b = %ld\n", a, b);

  char *eeaTabs = "";
  char *firstTab = "\t";
  int formatLength = (strlen(argv[1]) + strlen(argv[2]) + strlen(q_str) + strlen(r_str));
  if ((formatLength%8) < 7) {
    // printf("%i", formatLength);
    eeaTabs = "\t";
    if (formatLength >= 8)
      firstTab = "\t\t";
  }

  printf("\t\t|x\t|y\t|%ldx + %ldy\t|EEA\t%s|  q\n", a, b, firstTab);
  printf("---------------------------------------------------------------------------\n");

  if (a > b) { 
    printf("\t\t|1\t|0\t|%ld\t\t|\t%s|\n", a, firstTab);
    printf("\t\t|0\t|1\t|%ld\t\t|%ld = %ld(%ld) + %ld%s|  %ld\n", \
        b, a, b, q, r, eeaTabs, q);
    extendedEuclideanAlg(a, b, 1, 0, 0, 1, a, b, q, r, eeaTabs, 1, formatLength);
  } else {
    printf("\t\t|0\t|1\t|%ld\t\t|\t%s|\n", b, firstTab);
    printf("\t\t|1\t|0\t|%ld\t\t|%ld = %ld(%ld) + %ld%s|  %ld\n", \
        a, b, a, q, r, eeaTabs, q);
    extendedEuclideanAlg(a, b, 0, 1, 1, 0, b, a, q, r, eeaTabs, 1, formatLength);
  }

  return 0;
}
