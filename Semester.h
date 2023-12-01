#ifndef SEMESTER_H
#define SEMESTER_H
#include <iostream>
using namespace std;

class Semester
{
	private:
		double gpa;		// store gpa
		int credit_hour;// store credit hour
		bool deanList;	// store dean's list
	public:
		Semester();					// constructor
		~Semester();				// destructor
		void setValue(double,int);	// private member mutator
		void setGPA(double g);	  	// gpa mutator
		void setCreditHour(int c);	// credit hour mutator
		void setDeanList();		  	// dean's list mutator
		double getGPA();		  	// gpa accessor
		int getCreditHour();	  	// credit hour accessor
		bool getDeanList();		 	 // dean's list accessor
};
#endif


