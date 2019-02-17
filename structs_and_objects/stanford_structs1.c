struct student {
  char* name;
  char suid[8];
  int numUnits;
};

int main() {
  struct student student1;
  struct student* ptr_student = &student1;
  student1.suid[0] = 'A';
  student1.suid[1] = 'B';
  student1.suid[2] = 'C';
  student1.suid[3] = 'D';
  student1.suid[4] = 'E';
  student1.suid[5] = 'F';
  student1.suid[6] = 'G';
  student1.suid[7] = 'H';
  student1.numUnits = 12;

  return 0;
}
