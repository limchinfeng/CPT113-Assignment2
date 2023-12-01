/*

CPT113 Assignment 2 Group 10
Purpose of the Program: The main purpose of our program is used for the course registration for a student 
						who is majoring in computer science in University Group 10. This program is a 
						Computer Science Student's Registration System and it allows the student to add 
						and drop course(s), calculate students' GPA, and determine the Dean's' List of the 
						current semester based on the current semester's GPA and total units

Input file: "G10File.txt"
Email :G10@student.usm.my
Password :G10

YouTube link: 
Group: 10
Written by :
	LIM CHIN FENG	(157968)
	KHOO JIA XIN	(158764)
	LEE JIA QIAN	(159349)
	
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "RegisterList.h"	// import RegisterList class
#include "CourseList.h"		// import CourseList class
#include "Student.h"		// import Student class
using namespace std;

//functions
void readFile(CourseList&, Student&);
void loginPage(Student);
void registerCourse(CourseList&, RegisterList&, Student);
void HomePage(CourseList, RegisterList&,Student);
void enterCourseResult(RegisterList&,Student&);
void showStudentSemesterResult(RegisterList,Student);

// Course registration function
void addCourse(CourseList&, RegisterList&, Student);
void dropCourse(CourseList&, RegisterList&, Student);
void editCourseType(RegisterList&);
void updateCourseGrade(RegisterList&, Student&);

// menu guideline
void HomePageChoice();
void RegistrationMenu();
void GradeMenu();

// To make sure user enter the corrent input
void validation_Choice(int, int &);
void validation_type(char &);

// decoration
void logo();
void showEnd();
void coverPage();
void loginLogo();
void welcome();
void registration();
void homePage();
void resultSlip();
void courseGrade();
void decorateUpperFrame();
void decorateLowerFrame();


int main()
{
	// Objects declaration
	Student student;			
	RegisterList list;			
	CourseList AllCourseList;
	
	// read the details of the student and course that available for registration
	readFile(AllCourseList,student);
	
	// student login page
	loginPage(student);
	
	// course registration
	registerCourse(AllCourseList, list,student);
	
	// student home page
	HomePage(AllCourseList,list,student);
	
	// prompt user to enter the result of their courses
	enterCourseResult(list,student);
	
	// show student semester result
	showStudentSemesterResult(list,student);
	
	showEnd();

	return 0;
} 

//Read student's infomation and course available from the file
void readFile(CourseList &AllCourseList, Student &student)
{
	ifstream dataFile;
	dataFile.open("G10File.txt");	//open file
	
	string name,phone,ICnumber,email,password;
	int matricNo,currentYear,currentSemester;
	string courseCode,courseName;
	int unit, sem, creditHour[8];
	double gpa[8];
	
	coverPage();	// starting page decoration
	
	if(dataFile)	// if successfully open the file
	{				// read the file
		getline(dataFile,email,'\t');
		getline(dataFile,password,'\t');
		getline(dataFile,name,'\t');
		dataFile >> phone;
	 	dataFile >> ICnumber;
		dataFile >> matricNo;
		dataFile >> currentYear;
		dataFile >> currentSemester;
		dataFile.ignore();
		for(int i=0; i<8; i++)
		{
			dataFile >> gpa[i];
			dataFile >> creditHour[i];
		}
		dataFile.ignore();
		student.setInfo(email,password,name,phone,ICnumber,matricNo,currentYear,currentSemester,gpa,creditHour);	
				
		while(!dataFile.eof())
		{
			getline(dataFile,courseCode,'\t'); 
			getline(dataFile,courseName,'\t');
			dataFile >> unit;
			dataFile.ignore();
			
			AllCourseList.appendCourseList(courseCode,courseName,unit);
		}
	}
	else {  //Show error message and exit program if fail to open the file
		cout << endl;	
		cout << "\tError opening file. Please enter the correct file!"  << endl;
		cout << "\tProgram terminates." << endl; 
		exit(EXIT_FAILURE); 
	}	
	
	dataFile.close();	// close file
}

// login page for student to enter the registration page
void loginPage(Student student)
{
	string email,password;
	
	loginLogo();// login logo
	
	// prompt user to enter his email
	cout << "\t\t\tPlease enter your student email: ";
	cin >> email;
	
	if(email == student.getEmail())	// prompt user to enter his password if email is correct
	{
		cout << "\t\t\tPlease enter your password: ";
		cin >> password;
		if(password == student.getPassword())	// successfully login if password is correct
		{
			cout << "\n\n\t\t      ->You have successfully login to your student account<-\n\n";
			system("pause");
			system("cls");
		}
		else	// exit if password is incorrect
		{
			cout << "\n\n\t\t\t\t\t >>Password Error!<<" << endl;
			cout << "\t\t\t\t\t>>Please try again!<<" << endl;
			exit(0);
		}
	}
	else	// exit if email is incorrect
	{
		cout << "\n\n\t\t\t\t\t   >>Email Error!<<" << endl;
		cout << "\t\t\t\t\t>>Please try again!<<" << endl;
		exit(0);
	}
}

// Registration
void registerCourse(CourseList &AllCourseList, RegisterList& list, Student student)
{
	welcome();// Welcome page decoration
	
	cout << "\n\n\t\t\t\t  " << student.getFullName() << ", welcome to the new semester! "<<endl;

	cout << "\n\t\t\t       Please register your course for Year " << student.getCurrentYear() 
		 << " Semester " << student.getCurrentSemester() << ". " << endl <<endl;
	system("pause");
 	
 	bool exit = false;
	int choice;
	
 	
	do{
		system("cls");
		registration();
		
		list.displayList();	// display current course that the user have registered
		cout << "\t\t\t\t\t\t    Current Unit :" << list.getTotalUnit() << endl; 
		cout << "\t\t\t\t\t\t    Total Course :" << list.getTotalCourse() << endl << endl; 		
 		RegistrationMenu();
 		cin >> choice;
 		validation_Choice(5,choice);	// make sure the input is in the range
		
		system("cls");
				
		switch(choice)
		{
			// show all the available courses 
			case 1 : {
				cout << "\n\t\t\t\t\t---1. Show All Course List---\n\n\n" << endl;
				AllCourseList.displayList();
				system("pause");
				break;
			}
			
			// add course
			case 2 : {
				cout << "\n\t\t\t\t\t\t---2. Add Course---\n" << endl;
				addCourse(AllCourseList, list,student);
				break;
			}
			
			// drop course
			case 3 : {
				cout << "\n\t\t\t\t\t     ---3. Drop Course---\n" << endl;	
				dropCourse(AllCourseList, list,student);			
				break;
			}
			
			// edit course type
			case 4 : {
				cout << "\n\t\t\t\t      ---4. Edit Registered Course Type---\n" << endl;
				editCourseType(list);	
				break;
			}
			
			// Exit registration
			case 5 : {
				if(list.getTotalUnit() < 9)  // not allow user to exit if credit hours is less than 9
				{
					cout << "\n\n\t\t\t      Error!" << endl;
					cout << "\t\t\t      You should register at least 9 and not more than 25 credit hours." << endl;
					cout << "\t\t\t      Please add courses until you have at least 9 credit hours! " << endl << endl;
					cout << "\n\t\t\t\t\t\t   Current Unit :" << list.getTotalUnit() << endl; 
					cout << "\t\t\t\t\t\t   Total Course :" << list.getTotalCourse() << endl << endl;
					system("pause");
				}
				else
					exit = true;
				break;
			}
		}
	}while(!exit);	
}

// Student home page
void HomePage(CourseList AllCourseList,RegisterList &list, Student student)
{
	bool exit = false;
	int choice;
	do{
		system("cls");
		
		// show the choice for the user to choose
		HomePageChoice();	
		cin >> choice;	
		validation_Choice(6, choice); // make sure the input is in the range
		
		system("cls");
		
		switch(choice)
		{
			// show student's details
			case 1 : {
				cout << "\n\t\t\t\t         ---1. Show Student's Details---\n\n\n";
				student.printInfo();
				cout << "\t\t\t\t          ---Year " << student.getCurrentYear() << " Semester " 
					 << student.getCurrentSemester() << " Course---\n\n\n"; 
				list.displayList();
				cout << endl << "\t\t\t\t\t\tCurrent Unit : " << list.getTotalUnit() << endl;
				cout << "\t\t\t\t\t\tTotal Course : " << list.getTotalCourse() << endl;	
				system("pause");
				break;
			}		
			
			// show all the course that registered by the user
			case 2 : {
				cout << "\n\t\t\t\t\t---2. Show Course Registered List---\n\n\n";
				cout << "\t\t\t\t          ---Year " << student.getCurrentYear() << " Semester " 
					 << student.getCurrentSemester() << " Course---\n\n\n"; 
				list.displayList();
				cout << endl << "\t\t\t\t\t\tCurrent Unit : " << list.getTotalUnit() << endl;
				cout << "\t\t\t\t\t\tTotal Course : " << list.getTotalCourse() << endl << endl;		
				system("pause");
				break;
			}
			
			// add course
			case 3 : {
				cout << "\n\t\t\t\t\t ---3. Add Course---\n\n\n";
				addCourse(AllCourseList, list,student);
				break;
			}
			
			// drop course
			case 4 : {
				cout << "\n\t\t\t\t\t      ---4. Drop Course---\n\n\n";	
				dropCourse(AllCourseList, list,student);			
				break;
			}
			
			// edit course type
			case 5 : {
				cout << "\n\t\t\t\t          ---5. Edit Registered Course Type---\n\n\n";
				editCourseType(list);	
				break;
			}		
				
			// Exit
			case 6 : {
				if(list.getTotalUnit() < 9) // not allow user to exit if credit hours is less than 9
				{
					cout << "\n\n\t\t\t      Error!" << endl;
					cout << "\t\t\t      You should register at least 9 and not more than 25 credit hours." << endl;
					cout << "\t\t\t      Please add courses until you have at least 9 credit hours!" << endl << endl;
					cout << "\n\t\t\t\t\t\t   Current Unit :" << list.getTotalUnit() << endl; 
					cout << "\t\t\t\t\t\t   Total Course :" << list.getTotalCourse() << endl << endl;
					system("pause");
				}
				else
					exit = true;
				break;
			}
		}		
	}while(!exit);
	system("cls");
}

// prompt user to enter each course's result
void enterCourseResult(RegisterList &list, Student &student)
{
	int choice;
	
	// guideline for the user to enter the course's grade
	courseGrade();// decorate logo
	decorateUpperFrame();
	cout << "\t\t      Enter your course's grade accourding to these course option(IN NUMBER)"<< endl;
	decorateLowerFrame();
	GradeMenu();
	system("pause");
	system("cls");
	
	// decorate logo
	list.enterEachCourseGrade();	// function the allow user to enter the grade
	list.displayListWithGrade();	// display the courses with grade
	
	// ask user whether want to update or change the course's grade
	cout << "\n\t\t\t\t\t   Do you want to update grade for your course?" << endl;
	cout << "\t\t\t\t\t   1. Yes" << endl;
	cout << "\t\t\t\t\t   2. No" << endl;
	cout << "\t\t\t\t\t   Choice >> ";
	cin >> choice;
	validation_Choice(2,choice);	// make sure the input is in the range
	
	system("cls");
	if(choice == 1)	// update or change the course's grade
		updateCourseGrade(list,student);
	else
	{
		return;	// exit
	}
}

// show student semester result
void showStudentSemesterResult(RegisterList list, Student student)
{
	cout << setprecision(2) << fixed;
	double gpa = list.getGPA();
	int unit = list.getTotalUnit();
	int totalCourse = list.getTotalCourse();
	student.setCurrentSemesterGPA(gpa,unit);
	
	resultSlip();
	cout << "\n\n\t\t\t\t\t ---Year " << student.getCurrentYear() << " Semester " 
		 << student.getCurrentSemester() << " Result---\n\n\n";
	list.displayListWithGrade();
	cout << "\t\t\t\t            GPA            : " << gpa << endl;
	cout << "\t\t\t\t            Current Unit   : " << list.getTotalUnit() << endl;
	cout << "\t\t\t\t            Total Course   : " << list.getTotalCourse() << endl;
	cout << endl << endl;	
	student.printInfo();
	system("pause");
	system("cls");
}

// add course 
void addCourse(CourseList &AllCourseList, RegisterList& list, Student student)
{
	bool exit = false,found;
	string code,name;
	char type;
	int unit;
	int unitRegister,choice;
	
	do{
		unitRegister = list.getTotalUnit();
		found = false;
		AllCourseList.displayList();	// display course that available to register
		
		// display current courses that have been registered	
		list.displayList();
		cout << "\t\t\t\t\t\t   Current Unit :" << unitRegister << endl;
		cout << "\t\t\t\t\t\t   Total Course :" << list.getTotalCourse() << endl << endl; 
		
		// prompt user to choose the course that want to register by entering the course's code
		cout << "\t\t\t\t     Enter the course code that you wish to add: " << endl;
		cout << "\t\t\t\t     Course Code >> ";
		cin >> code;
		cout<<endl;
			
		do{
			// if found the course in the list and is not registered
			if(AllCourseList.courseFound(code) && AllCourseList.checkCourseRegister(code) == false)
			{
				AllCourseList.getCourseDetail(code,name,unit);
				unitRegister += unit;
				if(unitRegister >25)	// not allow to register is total unit is more than 25
				{
					cout << endl << "\t\t\t\t   You are not allowed to add this course!" << endl;
					cout << "\t\t\t\t   Reason : Total Credit Hours will more than 25" << endl;
					cout << "\t\t\t\t   You can add other course or drop current course first." << endl << endl;
					found = true;					
				}
				else	// prompt user to enter the course type
				{
					cout << endl << "\t\t\t\t     Enter the course type for " << code << ":\n\t\t\t\t   " 
						 << "  ->" << name << "<-" << endl;
					cout << "\t\t\t\t	         [T,U,E,M]" << endl;
					cout << "\t\t\t\t     Course Type >> ";
					cin >> type;
					validation_type(type); // make sure the input is in the range
					list.appendCourseWithoutGrade(code,name,type,unit);	// add the course to the linked list
					AllCourseList.setCourseRegister(code);				// set the register course code to yes
					found = true;	// exit the loop if found the course
					cout << "\n\n\t\t\t\t\t\t     ---Done---\n\n";
					break;
				}
			}
			// if found the course in the list and have been registered
			else if(AllCourseList.courseFound(code) && AllCourseList.checkCourseRegister(code) == true)
			{
				// not allow the user to register that course again
				AllCourseList.getCourseDetail(code,name,unit);
				cout << "\t\t\t   -Register ERROR.You have added " << code << "-" 
					 << name << " before!-" << endl;
				found = true;	// exit the loop if found the course
			}
	
			// if didn't found the course in the list, prompt user to enter the code again	
			if(!found)
			{
				cout << "\n\t\t\t\t   Course not found! Please enter the course code again!" << endl;
				cout << "\t\t\t\t   Course Code >> ";
				cin >> code;
			}
			
		}while(!found);
				
		if(list.getTotalUnit() == 25)	// force user to exit the add course founction if total unit is 25
		{
			list.displayList();
			cout << "\t\t\t\t\t\t   Current Unit : " << list.getTotalUnit() << endl; 
			cout << "\t\t\t\t\t\t   Total Course : " << list.getTotalCourse() << endl << endl << endl; 
			cout << "\t\t\t\t   You have reach the MAXIMUM credit hour!" << endl;
			cout << "\t\t\t\t   You will be directed to the Registration Page." << endl << endl;
			exit = true;	// exit the function
		}
		
		// ask user wants to continue or not if the total unit exceed the minimum total unit(9)		
		if(!exit && list.getTotalUnit() >8)	
		{
			system("pause");
			system("cls");
			list.displayList();
			cout << "\t\t\t\t\t\t   Current Unit :" << list.getTotalUnit() << endl;
			cout << "\t\t\t\t\t\t   Total Course :" << list.getTotalCourse() << endl << endl;  
			cout << "\t\t\t\t\t Do you want to continue to add course?" << endl;
			cout << "\t\t\t\t\t 1. Yes" << endl;
			cout << "\t\t\t\t\t 2. No" << endl;
			cout << "\t\t\t\t\t Choice >> ";
			cin >> choice;
			validation_Choice(2,choice);// make sure the input is in the range
			if(choice == 2)	// exit if user don't want to add course
			{
				exit = true;
			}
		}
		else
			system("pause");
				
		system("cls");	
	}while(!exit);		
}

// drop course
void dropCourse(CourseList &AllCourseList, RegisterList& list, Student student)
{
	bool found = false,exit = false;
	string code,name;
	int choice,unit;
	
	if(list.getTotalUnit() == 0)	// force uesr to exit if user didn't add any course
	{
		cout << "\t\t\t\t   You didn't register any course yet." << endl;
		cout << "\t\t   Please register your course first before you can drop any course!\n\n";
		system("pause");
		return;
	}
	
	
	do{
		found = false;
		// display the current registered course list and total unit and course accumulate
		list.displayList();
		cout << "\t\t\t\t\t\t   Current Unit :" << list.getTotalUnit() << endl;
		cout << "\t\t\t\t\t\t   Total Course :" << list.getTotalCourse() << endl;		
		
		
		// prompt user to enter the course code that the user want to drop
		cout << "\n\t------------------------------------------------------------------------------------------------------\n\n";
		cout << "\t\t\t\t     Enter the course code that you want to drop:" << endl;
		cout << "\t\t\t\t     Course Code >> ";
		cin >> code;
		
		
		do{
			// drop the course if found the course code in the registered course list
			if(list.courseFound(code) == true)
			{
				list.dropCourse(code);
				AllCourseList.setCourseUnregister(code);			
				cout << "\n\n\t\t\t\t\t\t     ---Done---\n\n";
				system("pause");
				system("cls");
				
				// display the current registered course list
				list.displayList();
				cout << "\t\t\t\t\t\t   Current Unit : " << list.getTotalUnit() << endl;
				cout << "\t\t\t\t\t\t   Total Course : " << list.getTotalCourse() << endl << endl;  
				
				found = true;	// exit the loop if found the course
			}
			// ask user to enter the course code again if didn't find the course code in the course list
			
			if(!found)
			{
				cout << "\n\t\t\t\t     You didn't register this course : " << code << "!" << endl;
				cout << "\t\t\t\t     Please enter the course code again." << endl;
				cout << "\t\t\t\t     Course Code >> ";
				cin >> code;
				
			}
		}while(!found);
		
		cout << endl;
		
		// exit if user have no registered course
		if(list.getTotalUnit() == 0){
			cout << "\n\t\t\t\t\t     You have no any registered course now!" << endl;
			cout << "\t\t\t\t\t     Please register your course first!\n";
			system("pause");
			return;
		}
		
		// ask user whether want to continue to drop course
		if(!exit)
		{
			cout << "\t\t\t\t\t Do you want to continue drop course?" << endl;
			cout << "\t\t\t\t\t 1. Yes" << endl;
			cout << "\t\t\t\t\t 2. No" << endl;
			cout << "\t\t\t\t\t Choice >> ";
			cin >> choice;
			validation_Choice(2,choice);// make sure the input is in the range
			if(choice == 2)	// exit if do no want to drop course
			{
				exit = true;
			}
		}
		system("cls");
	}while(!exit);
	
}

// edit registered course type
void editCourseType(RegisterList& list)
{
	bool found = false,exit = false;
	string code,name;
	int unit,choice;
	char type;
	
	do{	// display the current registered course list 
		found = false;
		list.displayList();
		cout << "\t\t\t\t\t\t   Current Unit : " << list.getTotalUnit() << endl;
		cout << "\t\t\t\t\t\t   Total Course : " << list.getTotalCourse() << endl;		
		
		// force uesr to exit if user didn't add any course
		if(list.getTotalUnit() == 0)
		{
			cout << "\n\t\t\t\t\t  You didn't add any course yet." << endl;
			cout << "\t\t\t Please add your course first before you can update the course's type!\n\n";
			system("pause");
			return;			
		}

		// prompt user to enter the course code that the user want change it's course type
		cout << "\n  --------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\t\t\t    Enter the course code that you want to change it's course type." << endl;
		cout << "\t\t\t    Course Code >> ";
		cin >> code;
		
		
		do{
			if(list.courseFound(code))	// if found the course in the registered course list
			{
				// prompt user to enter the new course type
				list.getCourseDetail(code,name,unit);
				cout << endl << endl;
				cout << "\t\t\t\t          Enter the course type of " << endl;
				cout << "\t\t\t\t          " << code << " - " << name << endl;
				cout << "\t\t\t\t	         [T,U,E,M]" << endl;
				cout << "\t\t\t\t          Course Type >> ";
				cin >> type;
				validation_type(type);	// make user the input is in the range
				cout << endl;
				
				// change the course type if the course type entered is not same with the previous course type
				if(list.getCourseType(code) != type)
				{
					list.updateType(code,type);
					cout << "\n\n\t\t\t\t\t\t     ---Done---\n\n";
					system("pause");
					system("cls");
				}	
				
				// no change the course type since the previous course type is same with the current course type	
				else
				{
					cout << "\t\t\t\t    The course type that you want to update for " << endl; 
					cout << "\t\t\t\t    " << code << " - " << name << " is the same (" << type << ")\n\n";
					system("pause");
					system("cls");
				}
				found = true;	//exit the loop if found the course
			}
			else	// error message if coundn't found the course code in the registered course list
				cout << "\n\t\t\t\t     You didn't register this course : " << code << "!\n\n\n";
			
			// ask user to enter the course code again if didn't find the course code in the course list
			if(!found)
			{
				cout << "\t\t\t\t     Please enter the course code again." << endl;
				cout << "\t\t\t\t     Course Code >> ";
				cin >> code;
			}
		
		}while(!found);
		
		// ask user whether want to continue to change course type	
		if(!exit)
		{
			list.displayList();
			cout << endl << "\n\t\t\t\t  Do you want to continue to change other course's type?" << endl;
			cout << "\t\t\t\t  1. Yes" << endl;
			cout << "\t\t\t\t  2. No" << endl;
			cout << "\t\t\t\t  Choice >> ";
			cin >> choice;
			validation_Choice(2, choice);	// make sure the input is in the range
			if(choice == 2)	// exit if do no want to change course type
			{
				exit = true;
			}
		}
		system("cls");
	}while(!exit);
	
}

// update each course grade
void updateCourseGrade(RegisterList& list, Student& student)
{
	bool found = false,exit = false;
	string code,name;
	int unit,choice,grade;
	
	do{
		found = false;
		// display the current registered course with grade
		list.displayListWithGrade();
		cout << endl << "\t\t\t\t\t\t   Current Unit : " << list.getTotalUnit() << endl;
		cout << "\t\t\t\t\t\t   Total Course : " << list.getTotalCourse() << endl;		
		
		// prompt user to enter the course code that the user want change it's course grade
		cout << "\n  -------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\t\t\t     Enter the course code that you want to change it's course grade:" << endl;
		cout << "\t\t\t     Course Code >> ";
		cin >> code;
		
		do{
			// prompt user to enter the course grade if found the course code in the registered course list
			if(list.courseFound(code))
			{
				GradeMenu();
				list.getCourseDetail(code,name,unit);
				cout << endl << endl;
				cout << "\t\t\t\t\t  Enter the course grade of " << endl;
				cout << "\t\t\t\t\t  " << code << " - " << name << endl;
				cout << "\t\t\t\t\t  Course Grade >> ";
				cin >> grade;
				validation_Choice(12, grade);	// make sure the input is in the range
				
				// change the course grade if current grade is not same with the previous grade
				if(list.getCourseGradeID(code) != grade)
				{
					list.updateGrade(code,grade);
					cout << "\n\n\t\t\t\t\t\t       ---Done---\n\n";
					system("pause");
					system("cls");
				}	
				else	// show error message if current grade is same with the previous grade
				{
					cout << "\t   The course grade that you want to update for " 
					<< code << " - " << name << " is the same (" << list.getCourseGrade(code) << ")" << endl << endl;
					system("pause");
					system("cls");
				}
				found = true;	// exit the loop
			}
			else	// error message if coundn't found the course code in the registered course list	
				cout << "\n\t\t\t\t\t You didn't register this course : " << code << "!" << endl;

			// ask user to enter the course code again if didn't find the course code in the course list			
			if(!found)
			{
				cout << "\t\t\t\t\t Please enter the course code again." << endl;
				cout << "\t\t\t\t\t Course Code >> ";
				cin >> code;
			}
		
		}while(!found);
		
		// ask user whether want to continue to change course grade		
		if(!exit)
		{
			cout << endl;
			list.displayListWithGrade();
			cout << "\n\t\t\t\t   Do you want to continue to change other course's grade?" << endl;
			cout << "\t\t\t\t   1. Yes" << endl;
			cout << "\t\t\t\t   2. No" << endl;
			cout << "\t\t\t\t   Choice >> ";
			cin >> choice;
			validation_Choice(2, choice);	// make sure the input is in the range
			if(choice == 2)	// exit if do no want to change course grade
			{
				exit = true;
			}
		}
		system("cls");
	}while(!exit);
}

// make sure the choice is in the range
void validation_Choice(int x, int &choice)
{
	if(choice<=0||choice>x||cin.fail()|| cin.get() != '\n')
	{
		do{		// prompt user to enter valid choice
			cout << endl;
			cout << "\t\t\t\t\t\tPlease enter a valid choice. " <<endl;
			cout << "\t\t\t\t\t\tChoice >> ";
			cin.clear();
			cin.ignore();
			cin>>choice;	
		}while(choice<=0||choice>x||cin.fail()|| cin.get() != '\n');	
	}
}

// make sure the course type is in the range
void validation_type(char &type)
{
	if((type!='T'&&type!='U'&&type!='M'&&type!='E')||cin.fail()||cin.get() != '\n')
	{
		do{		// prompt user to enter valid choice
			cout << endl;
			cout << "\n\t\t\t\t   Please enter a valid type (T,U,E,M): " <<endl;
			cout << "\t\t\t\t   Type >> ";
			cin.clear();
			cin.ignore();
			cin >> type;
		}while((type!='T'&&type!='U'&&type!='M'&&type!='E')||cin.fail()|| cin.get() != '\n');	
	}
}

// home page menu 
void HomePageChoice()
{
	homePage();
	cout <<	"\t\t\t\t\t\t>>>>>> Home Page <<<<<<" << endl;
	cout << "\t\t\t\t\t    1. Show Student Details" << endl;
	cout << "\t\t\t\t\t    2. Show Course Registered List" << endl;
	cout << "\t\t\t\t\t    3. Add Course" << endl;
	cout << "\t\t\t\t\t    4. Drop Course" << endl;
	cout << "\t\t\t\t\t    5. Edit Registered Course Type" << endl;
	cout << "\t\t\t\t\t    6. Exit" << endl << endl;	
	cout << "\t\t\t\t\t\t      Select >> " ;
}

// registration page menu
void RegistrationMenu()
{
	cout <<	"\t\t\t\t\t\t >>>>>> Main Menu <<<<<<" << endl;
	cout << "\t\t\t\t\t   1. Show All Course List" << endl;
	cout << "\t\t\t\t\t   2. Add Course" << endl;
	cout << "\t\t\t\t\t   3. Drop Course" << endl;
	cout << "\t\t\t\t\t   4. Edit Registered Course Type" << endl;
	cout << "\t\t\t\t\t   5. Exit Registration" << endl << endl;	
	cout << "\t\t\t\t\t\t   Select >> " ;	
}

// grade menu
void GradeMenu()
{
	cout << "\t\t\t...................................................................." << endl << endl;
	cout << "\t\t\t\t   1. A  \t\t\t\t   2. A-" << endl;
	cout << "\t\t\t\t   3. B+ \t\t\t\t   4. B" << endl;
	cout << "\t\t\t\t   5. B- \t\t\t\t   6. C+" << endl;
	cout << "\t\t\t\t   7. C  \t\t\t\t   8. C-" << endl;
	cout << "\t\t\t\t   9. D+ \t\t\t\t   10.D" << endl;
	cout << "\t\t\t\t   11.D- \t\t\t\t   12.F" << endl << endl;
	cout << "\t\t\t...................................................................." << endl << endl;			
}

// logo decoration
void logo()
{
	cout<<"\t   __   __   __   __   _  ___      ___  ______   ______   _____   _   _______  ___    ___      "<<endl;
	cout<<"\t  |  | |  | |  \\ |  | | | \\  \\    /  / |  ____| |  __  | |  ___| | | |__   __| \\  \\  /  / "<<endl;
	cout<<"\t  |  | |  | |   \\|  | | |  \\  \\  /  /  | |__    | |__| | | |___  | |    | |     \\  \\/  /  "<<endl;
	cout<<"\t  |  | |  | | |\\ \\  | | |   \\  \\/  /   |  __|   |    __| |____ | | |    | |      \\    /   "<<endl;
	cout<<"\t  |  |_|  | | | \\   | | |    \\    /    | |____  | |\\ \\    ___| | | |    | |       |  |     "<<endl;
	cout<<"\t  |_______| |_|  \\__| |_|     \\__/     |______| |_| \\_\\  |_____| |_|    |_|       |__|     "<<endl;
	cout<<"\t              ________   ______   ______   __   __   ______      __    ______             "<<endl;
	cout<<"\t             |  ______| |  __  | |  __  | |  | |  | |  __  |    /  |  |  __  |            "<<endl;
	cout<<"\t             | |  ____  | |__| | | |  | | |  | |  | | |__| |   /__ |  | |  | |            "<<endl;
	cout<<"\t             | | |_   | |    __| | |  | | |  | |  | |  ____|     | |  | |  | |            "<<endl;
	cout<<"\t             | |___| |  | |\\ \\   | |__| | |  |_|  | | |         _| |_ | |__| |          "<<endl;
	cout<<"\t             |_______|  |_| \\_\\  |______| |_______| |_|        |_____||______|          "<<endl;
	cout<<endl<<endl;	
}

// ending decoration
void showEnd()
{
	cout<<"\t\t        __________________________________________________________       "<<endl;
	cout<<"\t\t     __|                 ______   __    _   _____                 |__     "<<endl;
	cout<<"\t\t  __|                   |  ____| |  \\  | | |  __ \\                   |__  "<<endl;      
	cout<<"\t\t |                      | |__    |   \\ | | | |  \\ |                     | "<<endl;
	cout<<"\t\t |                      |  __|   | |\\ \\| | | |   ||                     | "<<endl;
	cout<<"\t\t |__                    | |____  | | \\   | | |__/ |                   __| "<<endl;
	cout<<"\t\t    |__                 |______| |_|  \\__| |_____/                 __|    "<<endl;
	cout<<"\t\t       |__________________________________________________________|        "<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Thank you." << endl << endl;
	exit(0);
}

// cover page message
void coverPage()
{
	logo();
	cout << "\t\tThe main purpose of our program is used for the course registration for a student who" << endl; 
	cout << "\t\t      is majoring in computer science in University Group 10. This program is a " << endl;
	cout << "\t\t      Computer Science Student's Registration System and it allows the student to " << endl;
	cout << "\t\t    add and drop course(s), calculate students' GPA, and determine the Dean's' List" << endl;
	cout << "\t\t      of the current semester based on the current semester's GPA and total units" << endl;
	cout << "\n\n\t\t\t\t\t       Prepared by:"<<endl;
	cout << "\t\t\t\t\t  LIM CHIN FENG (157968)"<<endl;
	cout << "\t\t\t\t\t   LEE JIA QIAN (159349)"<<endl;
	cout << "\t\t\t\t\t   KHOO JIA XIN (158764)"<<endl;
	cout << endl<<endl<<endl;
	system("pause");
	system("cls");
}

// login page logo decoration
void loginLogo()
{
	cout<<endl;
	cout<<"\t\t                                      _____                   "<<endl;
	cout<<"\t\t      |                 _            |                    _ | "<<endl;
	cout<<"\t\t      |      ___   ___     ___       |___    __ __   ___    | "<<endl;
	cout<<"\t\t      |     |   | |   | | |   |      |      |  |  | |   | | | "<<endl;
	cout<<"\t\t      |____ |___| |___| | |   |      |_____ |  |  | |__/| | | "<<endl;
	cout<<"\t\t                      |                                       "<<endl;
	cout<<"\t\t                   ___|                                       "<<endl <<endl <<endl;
}

// welcome page logo decoration
void welcome()
{
	cout<<"\t\t   ___          ___  ______   __       ______   ______   __      __   ______      "<<endl;
	cout<<"\t\t   \\  \\        /  / |  ____| |  |     /  ____| |  __  | |  \\    /  | |  ____|  "<<endl;
	cout<<"\t\t    \\  \\  /\\  /  /  | |__    |  |    |  /      | |  | | |   \\  /   | | |__    "<<endl;
	cout<<"\t\t     \\  \\/  \\/  /   |  __|   |  |    | |       | |  | | | |\\ \\/ /| | |  __|  "<<endl;
	cout<<"\t\t      \\   /\\   /    | |____  |  |___ |  \\____  | |__| | | | \\__/ | | | |____    "<<endl;
	cout<<"\t\t       \\_/  \\_/     |______| |______| \\______| |______| |_|      |_| |______|   "<<endl;
}

// registration page logo decoration
void registration()
{
	cout<<"\t ______   ______   _______   __   ______   _______   ______    ______    _______   __   ______   __     _       "<<endl;
	cout<<"\t|  __  \\ |  ____| |  _____| |  | |  ____| |__   __| |  __  \\  /  __  \\  |__   __| |  | |  __  | |  \\   | |  "<<endl;
	cout<<"\t| |__| | | |__    | |  ___  |  | | |____     | |    | |__| | |  |__|  |    | |    |  | | |  | | |   \\  | |     "<<endl;
	cout<<"\t|    __/ |  __|   | | |__ | |  | |____  |    | |    |    __/ |   __   |    | |    |  | | |  | | | |\\ \\ | |    "<<endl;
	cout<<"\t| |\\ \\   | |____  | |___| | |  |  ____| |    | |    | |\\ \\   |  |  |  |    | |    |  | | |__| | | | \\ \\| |"<<endl;
	cout<<"\t|_| \\_\\  |______| |_______| |__| |______|    |_|    |_| \\_\\  |__|  |__|    |_|    |__| |______| |_|  \\___| "<<endl;
	cout<<endl<<endl;
}

// upper frame decoration
void decorateUpperFrame()
{
		cout<<"\t\t   ____   "<<endl;
		cout<<"\t\t  |  __|  "<<endl;
		cout<<"\t\t  |_|     "<<endl << endl;
}

// lower frame decoration
void decorateLowerFrame()
{
	cout<<"\t\t\t\t\t\t\t\t\t\t\t    _ "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t __| |  "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t|____|  "<<endl;
}

// home page logo decoration
void homePage()
{
	cout<<"\t\t     _   _   _____   __      __   ______        _____    ___    ______   ______     "<<endl;
	cout<<"\t\t    | | | | |  _  | |  \\    /  | |  ____|      |  _  \\  / _ \\  |  ____| |  ____| "<<endl;
	cout<<"\t\t    | |_| | | | | | |   \\  /   | | |__         | |_|  || |_| | | |  __  | |__      "<<endl;
	cout<<"\t\t    |  _  | | | | | | |\\ \\/ /| | |  __|        |  ___/ |  _  | | | |  | |  __|    "<<endl;
	cout<<"\t\t    | | | | | |_| | | | \\  / | | | |____       | |     | | | | | |__| | | |____    "<<endl;
	cout<<"\t\t    |_| |_| |_____| |_|  \\/  |_| |______|      |_|     |_| |_| |______| |______|   "<<endl; 
	cout<< endl << endl;
}

// result slip logo decoration
void resultSlip()
{
	cout<<"\t      _____    ______   ______   _    _   _     _______         ______   _       _   _____    "<<endl;
	cout<<"\t     |  _  \\  |  ____| |  ____| | |  | | | |   |__   __|       |  ____| | |     | | |  __ \\ "<<endl;
	cout<<"\t     | |_|  | | |__    | |____  | |  | | | |      | |          | |____  | |     | | | |__| |  "<<endl;
	cout<<"\t     |     /  |  __|   |____  | | |  | | | |      | |          |____  | | |     | | |  ___/   "<<endl;
	cout<<"\t     | |\\ \\   | |____   ____| | | |__| | | |____  | |           ____| | | |____ | | | |     "<<endl;
	cout<<"\t     |_| \\_\\  |______| |______| |______| |______| |_|          |______| |______||_| |_|     "<<endl;
}

// course grade logo decoration
void courseGrade()
{
	cout<<"\t   ______   _____   _    _   _____    ______   ______       _______   _____     ___    _____    ______      \n";
	cout<<"\t  |  ____| |  _  | | |  | | |  _  \\  |  ____| |  ____|     |  _____| |  _  \\   / _ \\  |  _  \\  |  ____| \n";
	cout<<"\t  | |      | | | | | |  | | | |_|  | | |____  | |__        | |  ___  | |_|  | | |_| | | | \\  | | |__       \n";
	cout<<"\t  | |      | | | | | |  | | |     /  |____  | |  __|       | | |_  | |     /  |  _  | | | |  | |  __|       \n";
	cout<<"\t  | |____  | |_| | | |__| | | |\\ \\    ____| | | |____      | |___| | | |\\ \\   | | | | | |_/  | | |____  \n";
	cout<<"\t  |______| |_____| |______| |_| \\_\\  |______| |______|     |_______| |_| \\_\\  |_| |_| |_____/  |______| \n";
	cout<< endl;
}
