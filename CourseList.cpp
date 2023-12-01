#include "CourseList.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// constructor
CourseList::CourseList()
{
	head = nullptr;
	totalCourse = 0;
}

// destructor
CourseList::~CourseList()
{
	destroyList();
	totalCourse = 0;
}

// destory the list
void CourseList::destroyList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		totalCourse--;
		nodePtr = nextNode;
	}
}

// add course to the list
void CourseList::appendCourseList(string c, string n,int u)
{
	ListNode *nodePtr;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->code = c;
	newNode->name = n;
	newNode->unit = u;
	newNode->courseRegister = false;
	newNode->next = nullptr;
	
	if(!head)
		head = newNode;
	else
	{
		nodePtr = head;
		while(nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
	totalCourse++;
}

// found course in the list
bool CourseList::courseFound(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
			found = true;
		else
			nodePtr = nodePtr->next;
	}
	
	return found;
}

// check the registration of the course
bool CourseList::checkCourseRegister(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
		{
			found = true;
			if(nodePtr->courseRegister == false)
				return false;
			else
				return true;
		}
		else
			nodePtr = nodePtr->next;
	}
}

// display the list
void CourseList::displayList()
{
	if(!head)
		cout << "Empty List" << endl;
	else
	{
		ListNode *nodePtr;
		nodePtr = head;
		cout<<"\t  Course  |\t\t\t\tCourse Name\t\t\t\t|\t  Credit Hours"<<endl << endl;
		while(nodePtr != nullptr)
		{
			cout << "\t  " << nodePtr->code << "\t\t";
			cout << setw(65) << left<<nodePtr->name;
			cout << "\t"<< nodePtr->unit;
			cout << endl;
			nodePtr = nodePtr->next;
		}
		cout << "\n       ------------------------------------------------------------------------------------------------------\n\n";
	}
}

// set course to register
void CourseList::setCourseRegister(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
		{
			found = true;
			nodePtr->courseRegister = true;
		}
		else
			nodePtr = nodePtr->next;
	}	
}

// set course to unregister
void CourseList::setCourseUnregister(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
		{
			found = true;
			nodePtr->courseRegister = false;
		}
		else
			nodePtr = nodePtr->next;
	}	
}

// total course accessor
int CourseList::getTotalCourse()
{
	return totalCourse;
}

// course details accessor
void CourseList::getCourseDetail(string c, string &n, int &u)
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
		{
			n = nodePtr->name;
			u = nodePtr->unit;
			return;
		}
		else
			nodePtr = nodePtr->next;
	}	
}

// course name accessor
string CourseList::getCourseName(string c) 
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
		{
			found = true;
			 return nodePtr->name;
		}
		else
			nodePtr = nodePtr->next;
	}	
}

// course unit accessor
int CourseList::getCourseUnit(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	bool found = false;
	
	while(nodePtr!= nullptr && !found)
	{
		if(nodePtr->code == c)
		{
			found = true;
			return nodePtr->unit;
		}
		else
			nodePtr = nodePtr->next;
	}		
}
