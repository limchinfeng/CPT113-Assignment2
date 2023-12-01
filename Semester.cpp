#include "Semester.h"
#include <iostream>
using namespace std;

// constructor
Semester::Semester()
{
	gpa=0.0;
	credit_hour=0;
	deanList = false;
}


// destructor
Semester::~Semester()
{
	gpa=0.0;
	credit_hour=0;
	deanList = false;
}

// private member mutator
void Semester::setValue(double g,int c)
{
	gpa=g;
	credit_hour=c;	
	setDeanList();		
}

// gpa mutator
void Semester::setGPA(double g)
{
	gpa=g;
	setDeanList();
}

// credit hour mutator
void Semester::setCreditHour(int c)
{
	credit_hour=c;
	setDeanList();
}

// dean's list mutator
void Semester::setDeanList()
{
	if(gpa >= 3.5 && credit_hour>11)
		deanList = true;
	else
		deanList = false;
}

// gpa accessor
double Semester::getGPA()
{
	return gpa;
}

// credit hour accessor
int Semester::getCreditHour()
{
	return credit_hour;
}

// dean's list accessor
bool Semester::getDeanList()
{
	return deanList;
}
