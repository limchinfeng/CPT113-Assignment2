#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <iostream>
#include <string>
using namespace std;

class PersonalInfo
{
  private:
    string fullname;  		// store full name
    string phoneNumber;  	// store phone number
    string IC_number;  		// store ic number
  public:  
    PersonalInfo();   			 // constructor
    ~PersonalInfo();  			// destructor
    void setFullName(string);   // full name mutator
    void setPhoneNumber(string);// phone number mutator
    void setICNumber(string);  	// ic number mutator
    string getFullName();    	// full name accessor
    string getPhoneNumber();  	// phone number accessor
    string getICNumber();    	// ic number accessor
};
#endif
