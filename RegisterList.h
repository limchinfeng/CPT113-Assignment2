#ifndef REGISTERLIST_H
#define REGISTERLIST_H

#include <iostream>
#include <string>
using namespace std;

class RegisterList {	
	private:
		struct ListNode	// mode
		{
			string code;	// store course code
			string name;	// store course name
			char type;		// store course type
			int unit;		// store course unit
			string grade;	// store course grade
			int gradeID;	// store grade ID
			ListNode *next;	// pointer to the next node
		};
		ListNode *head;		// head of the list
		int totalCourse;	// store total course registered
		int totalUnit;		// store total unit of the registered course
		double gpa;			// store current semester GPA
		
	public:
		RegisterList();	//constructor
		~RegisterList();//destructor
		void destroyList();	//delete the list
		void appendCourseWithoutGrade(string,string,char,int);	// add course
		void enterEachCourseGrade();				// enter course grade
		void updateGrade(string,int);				// update new course grade
		void updateType(string,char);				// update course type
		void dropCourse(string);					// drop course
		bool courseFound(string);					// found course in the list
		void displayList();							// display the list
		void displayListWithGrade();				// display the list with grade
		void calcSemesterGPA();						// calculate the current semester GPA
		void getCourseDetail(string,string&,int&);	// course details mutator
		int getTotalCourse();						// total course accessor
		int getTotalUnit();							// total unit accessor
		char getCourseType(string);					// course type accessor
		int getCourseGradeID(string);				// course grade id accessor
		string getCourseGrade(string);				// course grade accessor
		double getGPA();							// current semester GPA accessor
};

#endif
