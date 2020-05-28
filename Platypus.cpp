#include "Platypus.h"
#
/*-- platypus.cpp------------------------------------------------------------

   This file implements the Platypus member functions.

-------------------------------------------------------------------------*/



//using namespace Platypus;

//declare and define the function random that will simplify our job, not to write srand multiple times and just call it
int random(int a, int b) {
	srand(time(NULL));
	return rand() % a + b;
}
//public function hatch of type Platypus is defined here, setting boolean values, age, gender and weight
void Platypus::hatch() {
	alive = true;
	mutant = false;
	age = 0;
	if (random(2, 1) == 1) gender = 'M';
	else gender = 'F';
	weight = (float)random(10, 1)/10;
}
//definition of the default constructor, where hatch is automatically called
Platypus::Platypus() {
	name = 'A';
	alive = false;
	hatch();
}


//----- Definition of explicit-value  constructor -----
Platypus::Platypus(float weight, short age, char name, char gender) {
	// Check class invariant, no restrictions in this case
	//
	this->name = name;
	this->gender = gender;
	this->weight = weight;
	this->age = age;
	alive = true;
	mutant = false;
}

//definition of accessors----just returning private data members of Class
float Platypus::get_weight() {
	return weight;
}

short Platypus::get_age() {
	return age;
}
char Platypus::get_name() {
	return name;
}
char Platypus::get_gender() {
	return gender;
}

//operator overloading 
/*istream& operator>>(istream& i, Platypus& P)
{
	P.readit(i);
	return i;
} */
ostream& operator<<(ostream& o, Platypus& P) {
	P.print(o);
	return o;
}

//function definitions

bool Platypus::isalive() {
	return alive;
}
bool Platypus::ismutant() {
	return mutant;
}
void Platypus::print(ostream& o) const {
	cout << weight << setw(8) << age << setw(8) << name << setw(8)
		<< gender << setw(8) << alive << endl;
}
//increments age of an object and uses algorithm about chances of being mutant or dead
void Platypus::age_me(short age) {
	if (alive) {
		this->age = age + 1;
		if (random(100, 1) <= 2) mutant = true;
		if (random(100, 1) <= 10*weight) alive = false;
	}
	else cout << "dead platypus";
}

//fight function implements ratio of the weights of objects and finds winner
void Platypus::fight(Platypus other) {
	if (this->alive) {
		if (other.alive) {
			if (random(100, 1) > (this->weight / other.weight) * 50) {
				cout << "Enemy has won ---- " << other.name << endl;
				this->alive = false;
			}
			else {
				cout << "The winner is: " << this->name << endl;
			}
		}
		else cout << "no battle, enemy is dead" << endl;
	}
	else cout << "Platypus is dead!" << endl;
}

//we are feeding an object increasing its weight, strengthening it
void Platypus::eat() {
	if (alive) {
		weight = weight + (float)(random(5.0, 0.1) * weight / 100);
	}
}
