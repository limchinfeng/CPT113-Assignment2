#include "Student.h"
#include "PersonalInfo.h"
#include "Semester.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// constructor
Student::Student()
{
	setFullName("");
	setPhoneNumber("");
	setICNumber("");
	matric_number = 0;
	totalCreditHour = 0;
	CGPA = 0.0;
	currentYear = 0;
	currentSemester = 0;
	for(int i=0; i<8; i++)
		sem[8].setValue(0.0,0);
}

// destructor
Student::~Student()
{
	setFullName("");
	setPhoneNumber("");
	setICNumber("");
	matric_number = 0;
	CGPA = 0.0;
	totalCreditHour = 0;
	currentYear = 0;
	currentSemester = 0;
	for(int i=0; i<8; i++)
		sem[8].setValue(0.0,0);
}

// private members mutator
void Student::setInfo(string e,string pw,string n, string p, string ic, int m, int y, int s, double gpa[],int ch[])
{
	setFullName(n);
	setPhoneNumber(p);
	setICNumber(ic);
	matric_number = m;
	currentYear = y;
	currentSemester = s;
	email = e;
	password = pw;
	for(int i=0; i<8; i++)
	{
		sem[i].setValue(gpa[i],ch[i]);
		totalCreditHour += ch[i];
	}
}

// student's email accessor
string Student::getEmail()
{
	return email;
}

// student's password accessor
string Student::getPassword()
{
	return password;
}

// matric number accessor
int Student::getMatricNumber()
{
	return matric_number;
}

// total credit hours accessor
int Student::getTotalCreditHour()
{
	return totalCreditHour;
}

// current year accessor
int Student::getCurrentYear()
{
	return currentYear;
}

// current semester accessor
int Student::getCurrentSemester()
{
	return currentSemester;
}

// current semester GPA and total unit mutator
void Student::setCurrentSemesterGPA(double gpa,int ch)
{
	bool found = false;
	int n=0;
	

	while(!found)
	{
		if(sem[n].getCreditHour() == 0)
		{
			sem[n].setValue(gpa,ch);
			totalCreditHour += ch;
			found = true;
		}
		else
			n++;
	}
	calcCGPA();
}

// calculate current CGPA
void Student::calcCGPA()
{
	double total = 0;
	
	for(int i=0; i<8; i++)
	{
		if(sem[i].getCreditHour() != 0)
		{
			total += sem[i].getGPA() * sem[i].getCreditHour();
		}	
	}
	CGPA = total/totalCreditHour;
}

// print student's infomation
void Student::printInfo()
{
	calcCGPA();	// prevent stale value
	cout<<endl;
	cout<<"\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
	cout<<"\n\t                                       Detail of student "<< endl <<endl;
	cout<<"\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
	cout << setprecision(2) << fixed;
	cout << "\t\t\t\t\tFull Name          : " << getFullName() << endl;
	cout << "\t\t\t\t\tMatric Number      : " << matric_number << endl;
	cout << "\t\t\t\t\tPhone Number       : " << getPhoneNumber() << endl;
	cout << "\t\t\t\t\tIC Number          : " << getICNumber() << endl;
	cout << "\t\t\t\t\tYear               : " << currentYear << endl;
	cout << "\t\t\t\t\tSemester           : " << currentSemester << endl;
	cout << "\t\t\t\t\tCGPA               : " << CGPA << endl;
	cout << "\t\t\t\t\tTotal Credit Hour  : " << totalCreditHour << endl << endl;
	cout << "\t\t\t...................................................................." << endl << endl;		
	for(int i=0; i<8; i++)
	{
		if(sem[i].getCreditHour() != 0)
		{
			cout << "\t\t\t\t\t        ---Semester " << i+1 << "---" << endl;
			cout << "\t\t\t\t\t       GPA         : " << sem[i].getGPA() << endl;
			cout << "\t\t\t\t\t       Credit Hour : " << sem[i].getCreditHour() << endl;
			cout << "\t\t\t\t\t       Dean's 'List: ";
			if(sem[i].getDeanList() == true)
				cout << "Yes" << endl;
			else 
				cout << "No" << endl; 
			cout << endl;
		}
	}	
	cout << endl;
	cout<<"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
