struct foo {
  double four;
  char three;
  short one;
  int five[5];
  char two;
};

int main() {
  struct foo str[2];
  str[0].four = 0;
  str[0].three = 'a';
  str[0].one = 9;
  str[0].five[0] = 1;
  str[0].five[1] = 2;
  str[0].five[2] = 3;
  str[0].five[3] = 4;
  str[0].five[4] = 5;
  str[0].two = 'b';

  str[1].four = 0;
  str[1].three = 'c';
  str[1].one = 8;
  str[1].five[0] = 1;
  str[1].five[1] = 2;
  str[1].five[2] = 3;
  str[1].five[3] = 4;
  str[1].five[4] = 5;
  str[1].two = 'd';
}
