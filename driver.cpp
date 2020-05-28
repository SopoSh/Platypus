#include "Platypus.h"
#include "Platypus.cpp"

int main()
{
    Platypus p1(2.11, 3, 's', 'F'); //create one platypus object, explicit constructor
    p1.print(cout);
    Platypus p2(3.35, 2, 'm', 'M'); 
    p2.print(cout);
    //we can feed this platypus and increase its age
    p1.fight(p2);

    //default constructor, that calls hatch function giving it weight and gender
    Platypus p3;
    p3.eat(); //increments weight
    p3.print(cout);

    Platypus p4(2.33, 4, 'r', 'F');
    p4.age_me(4); //increments age
    p4.print(cout);
}

