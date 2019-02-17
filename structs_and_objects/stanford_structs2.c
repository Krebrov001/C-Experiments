#include <string.h>

struct student {
  char* name;
  char suid[8];
  int numUnits;
};

int main() {
  struct student pupils[4];
  pupils[0].numUnits = 70;
  pupils[2].name = strdup("abc");
  pupils[0].suid[6] = 'm';
  pupils[0].suid[7] = 'w';
  pupils[3].name = pupils[0].suid+6;
  strcpy(pupils[1].suid, "40415xx");
  pupils[1].numUnits = 68;

  return 0;
}
