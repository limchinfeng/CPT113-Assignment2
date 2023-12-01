#ifndef STUDENT_H
#define STUDENT_H
#include "PersonalInfo.h"
#include "Semester.h"
#include <iostream>
using namespace std;

class Student : public PersonalInfo{
	
	private:
		Semester sem[8];		// Object of Semester class
		int matric_number;		// store matric number
		int totalCreditHour;	// store total credit hours
		double CGPA;			// store current CGPA
		int currentYear;		// store current year
		int currentSemester;	// store current semester
		string email;			// store student's email
		string password;		// store student's password
		
	public:
		Student();								// constructor
		~Student();								// destructor
		void setInfo(string,string,string, string, string, int, int, int,double[],int[]);// private members mutator
		string getEmail();						// student's email accessor
		string getPassword();					// student's password accessor
		int getMatricNumber();					// matric number accessor
		int getTotalCreditHour();				// total credit hours accessor
		int getCurrentYear();					// current year accessor
		int getCurrentSemester();				// current semester accessor
		void setCurrentSemesterGPA(double,int); // current semester GPA and total unit mutator
		void calcCGPA();						// calculate current CGPA
		void printInfo();						// print student's infomation
};

#endif
