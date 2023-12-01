#ifndef COURSELIST_H
#define COURSELIST_H
#include <iostream>
#include <string>
using namespace std;

class CourseList {
	private:
		struct ListNode	// node
		{
			string code;		// store course code
			string name;		// store course name
			int unit;			// store course unit
			bool courseRegister;// determine registration of the course
			ListNode *next;		// pointer to the next node
		};
		ListNode *head;			// head of the list
		int totalCourse;		// store total course avaliable
		
	public:
		CourseList();								// constructor
		~CourseList();								// destructor
		void destroyList();							// destory the list
		void appendCourseList(string,string,int);	// add course to the list
		bool courseFound(string);					// found course in the list
		bool checkCourseRegister(string);			// check the registration of the course
		void displayList();							// display the list
		void setCourseRegister(string);				// set course to register
		void setCourseUnregister(string);			// set course to unregister
		int getTotalCourse();						// total course accessor
		void getCourseDetail(string,string&,int&);	// course details accessor
		string getCourseName(string);				// course name accessor
		int getCourseUnit(string);					// course unit accessor
};

#endif
