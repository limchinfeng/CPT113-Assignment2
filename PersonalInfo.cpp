#include "PersonalInfo.h"
#include <string>
#include <iostream>
using namespace std;

// constructor
PersonalInfo::PersonalInfo()
{
  fullname="";
  phoneNumber="";
  IC_number="";
}

// destructor
PersonalInfo::~PersonalInfo()
{
  fullname="";
  phoneNumber="";
  IC_number="";
}

// full name mutator
void PersonalInfo::setFullName(string name)
{
  fullname=name;
}

// phone number mutator
void PersonalInfo::setPhoneNumber(string phone)
{
  phoneNumber=phone;
}

// ic number mutator
void PersonalInfo::setICNumber(string ic_number)
{
  IC_number=ic_number;
}

// full name accessor
string PersonalInfo::getFullName()
{
  return fullname;
}

// phone number accessor
string PersonalInfo::getPhoneNumber()
{
  return phoneNumber;
}

// ic number accessor
string PersonalInfo::getICNumber()
{
  return IC_number;
}
