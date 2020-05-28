/*-- platypus.h ---------------------------------------------------------------

  This header file defines the data type Platypus for processing 
  Basic operations are:
	 Default constructor -- Initializes object
	 Explicit-value constructor
	 print:   To print the data of objects
	 <<:      Output overloaded operator
	 accessors: getters
	 functions: age_me, eat, fight, hatch that can be performed on objects

-------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

#ifndef PLATYPUS
#define PLATYPUS


class Platypus {
private:
	/********** Data Members **********/
	float weight;
	short age;
	char name;
	char gender;
	bool alive;
	bool mutant;
public:
	/******** Function Members ********/
	 /***** Class constructors *****/

	Platypus();
	/*----------------------------------------------------------------------
	Construct a class object (default).

	Precondition:  None.
	Postcondition: dead platypus is created;
		that is, age, weight, name, gender and alive mutant are initialized
		to 0, 0, '#', '#', false, false.
-----------------------------------------------------------------------*/
	Platypus(float weight, short age, char name, char gender);

	/*----------------------------------------------------------------------
	  Construct a class object (explicit values).

	 Precondition: weight, age, name and gender are initial
		  values for the data members; they must preserve the class
		  invariant.
	  Postcondition: Data members weight, age,name and gender
		  have been initialized to weight, age, name, gender
		  respectively.
   -----------------------------------------------------------------------*/
   //accesors
	float get_weight();
	short get_age();
	char get_name();
	char get_gender();


	void age_me(short age); //will increment age of an object by one, if it is alive
	void fight(Platypus other); //announces the winner of two objects according to algorithm implemented here
	void eat(); //gains weight gets stronger
	void hatch(); //sets some values for certain objects
	void print(ostream& o) const;

	bool isalive();
	bool ismutant();


	//friend istream& operator>>(istream& i, Platypus& P);
	/*------------------------------------------------------------------------
		Overloaded input operator

		Precondition:  The istream i is open;

		Postcondition : Values have been extracted from in(via input());
		reference to i is returned.
		-------------------------------------------------------------------------- */

	friend ostream& operator<<(ostream& o, Platypus& P);
	/*------------------------------------------------------------------------
	Overloaded ouput operator

	Precondition:  The ostream o is open.
	Postcondition: inserted into print(); reference to out
	  is returned.
------------------------------------------------------------------------*/


};

#endif