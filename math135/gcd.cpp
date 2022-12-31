#include <iostream>
using namespace std;

int gcd(int m, int n) {
  if ((m % n) == 0) { // Base case
    return n;
  } else {
    return gcd(n, m%n);
  }
}

int main(int argc, char *argv[]) {
  // Check if the right number of arguments were given
  if (argc != 3) {
    cout << "Incorrect number of arguments!\n";
    cout << "Usage: ./gcd [int] [int]\n";
    return 0;
  }

  // Convert inputs into int
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  if (n > m)
    cout << gcd(n, m) << endl;
  else
    cout << gcd(m, n) << endl;

  return 0;
}
