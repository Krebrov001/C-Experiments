int quiz1(char a, char x) {
  int z[3];
  short y = 43;
  char q = 0;
  do {
    y = y - z[q];
    z[q] = a + q;
    q++;
  } while (q < x);
  return a + y;
}
