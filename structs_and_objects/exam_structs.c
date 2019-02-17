struct foo {
  double four;
  char three;
  short one;
  int five[5];
  char two;
};

int bar(struct foo* f)  // struct pointer, array of structs
{
  f[0].three = f[0].two + f[1].three;
  f[0].five[3] = f[0].five[-1];
  f[0].one = f[1].three;
}
