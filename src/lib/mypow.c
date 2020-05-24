int mypow(short base, short exponent) {
  int output = 1;

  while(exponent != 0) {
    output = output * base;
    exponent -= 1;
  }

  return output;
}
