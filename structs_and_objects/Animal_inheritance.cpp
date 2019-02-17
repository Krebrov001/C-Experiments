#include <cstdlib>  // for EXIT_SUCCESS
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;


class Animal {
  public:
    // Default constructor
    Animal();

    // Overloaded constuctor
    Animal(int height, int weight, string name);

    // Destructor for the Animal class.
    ~Animal();

    /**
     * Sets the height of the animal.
     *
     * @param int mt - the height of the animal in meters.
     */
    void setHeight(int mt);

    /**
     * Sets the weight of the animal.
     *
     * @param int kg - the weight of the animal in kilograms.
     */
    void setWeight(int kg);

    /**
     * Sets the name of the animal.
     *
     * @param string animalName - the name of the animal.
     */
    void setName(string animalName);

    // Returns the height of the animal in meters.
    int getHeight();

    // Returns the weight of the animal in kilograms.
    int getWeight();

    // Returns the name of the animal.
    string getName();

    // Returns a string description of the animal.
    string toString();

  private:
    int height;
    int weight;
    string name;

    // A static variable is shared by all instances of the Animal class.
    static int numOfAnimals;
};


// class Dog inherits from the Animal class.
// : public inherits all the data members and methods that the Animal class has.
class Dog : public Animal {};


int main() {
    // Create an Animal by calling the default constructor.
    Animal fred;

    // Confirm that indeed the default constuctor was used to set the variables.
    cout << fred.toString() << endl;

    fred.setHeight(33);
    fred.setWeight(10);
    fred.setName("Fred");

    // Confirm that indeed the variables got set by the methods.
    cout << fred.toString() << endl;

    cout << endl;

    // Create an Animal by calling the overloaded constructor.
    Animal tom(40, 15, "Tom");

    // Confirm that the variables got set from the parameters
    // to the overloaded constructor.
    cout << tom.toString() << endl;

    cout << endl;

    Dog gref;
    gref.setHeight(8);
    gref.setWeight(3);
    gref.setName("Gref");

    cout << gref.toString() << endl;
    cout << gref.getName() << " info:" << endl;
    cout << "height: " << gref.getHeight() << endl;
    cout << "weight: " << gref.getWeight() << endl;

    return EXIT_SUCCESS;
}


// Give an initial value to the static variable.
int Animal::numOfAnimals = 0;


Animal::Animal()
{
    height = 0;
    weight = 0;
    name = "name";
    ++numOfAnimals;
}


Animal::Animal(int height, int weight, string name)
{
    // this is a pointer pointing to the "current" object
    // distinguishes the data members of the Animal class from the paramters.
    this->height = height;
    this->weight = weight;
    this->name = name;
    ++numOfAnimals;
}


Animal::~Animal()
{
    cout << "Animal " << this->name << " destroyed" << endl;
}


void Animal::setHeight(int mt)
{
    height = mt;
}


void Animal::setWeight(int kg)
{
    weight = kg;
}


void Animal::setName(string animalName)
{
    name = animalName;
}


int Animal::getHeight()
{
    return height;
}


int Animal::getWeight()
{
    return weight;
}


string Animal::getName()
{
    return name;
}


string Animal::toString()
{
    ostringstream output;

    output << "Animal " << name << " is " << height << " meters tall "
           << "and weights " << weight << " kilograms.";
    
    return output.str();
}

