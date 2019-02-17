/*
 * Name        : classes.cpp
 * Date        : 03/11/2017
 * Author      : Konstantin Rebrov
 * Language    : C++
 * Description : Experimenting with classes
 * Sources     : C++ Pocket Reference and elsewhere
 */

#include <iostream>
#include <string>
#include <cstdio>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Robot {
 public:
  // constructor
  Robot(string name = "", int height = 0);
  // copy consructor
  Robot(const Robot &robot);
  void PrintOut();
  void set_height(int height);
  void set_name(string name);
  string name();
  int height();
 private:
  int height_;
  string name_;
};

int main() {
  Robot robot1, robot2("Asimo"), robot3("Wall-E", 2);
  robot1.PrintOut();
  robot2.PrintOut();
  robot3.PrintOut();
  printf("%c%s%i\n", 'E', "nter a name for robot", 1);
  string name;
  cin >> name;
  robot1.set_name(name);
  cout << "You entered " << robot1.name();
  cout << "\nEnter " << 'a' << " height for robot" << 2 << endl;
  int height;
  scanf("%i", &height);
  robot1.set_height(height);
  robot1.PrintOut();
  return 0;
}

Robot::Robot(string name, int height) {
  name_ = name;
  height_ = height;
}

Robot::Robot(const Robot &robot) {
  name_ = robot.name();
  height_ = robot.height();
}

void Robot::PrintOut() {
  cout << "The robot's name is " << name_;
  cout << " and it is " << height_ << " feet tall." << endl;
}

void Robot::set_name(string name) {
  name_ = name;
}

void Robot::set_height(int height) {
  height_ = height;
}

string Robot::name() {
  return name_;
}

int Robot::height() {
  return height_;
}
