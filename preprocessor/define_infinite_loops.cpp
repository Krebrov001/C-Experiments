#define PRODUCT(x, y) DIVIDE( (x), (1/(y)) )
#define DIVIDE(x, y) PRODUCT( (x), (1/(y)) )

int main() {
  int j;
  j = DIVIDE(15, 5);

  return 0;
}
