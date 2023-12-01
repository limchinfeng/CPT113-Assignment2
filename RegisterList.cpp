#include "RegisterList.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// constructor
RegisterList::RegisterList()
{
	head = nullptr;
	totalCourse = 0;
}

// destructor
RegisterList::~RegisterList()
{
	destroyList();
	totalCourse = 0;
}

//delete the list
void RegisterList::destroyList()
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

// add course
void RegisterList::appendCourseWithoutGrade(string c, string n, char t, int u)
{
	ListNode *nodePtr;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->code = c;
	newNode->name = n;
	newNode->type = t;
	newNode->unit = u;
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
	totalUnit += u;
}

// enter course grade
void RegisterList::enterEachCourseGrade()
{
	int g;
	double total=0;
	string code;
	
	ListNode *nodePtr;
	nodePtr = head;
	
	for(int i=0; i<totalCourse; i++)
	{
		displayListWithGrade();
		code = nodePtr->code;
		
		cout<<"\t\t   ____   "<<endl;
		cout<<"\t\t  |  __|  "<<endl;
		cout<<"\t\t  |_|     "<<endl << endl;
		cout<<"\t\t\t Enter your course's grade accourding to these course option(IN NUMBER)\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t\t    _ "<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\t\t __| |  "<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\t\t|____|  "<<endl;
		
		cout << "\t\t\t....................................................................\n\n";
		cout << "\t\t\t\t   1. A  \t\t\t\t   2. A-" << endl;
		cout << "\t\t\t\t   3. B+ \t\t\t\t   4. B" << endl;
		cout << "\t\t\t\t   5. B- \t\t\t\t   6. C+" << endl;
		cout << "\t\t\t\t   7. C  \t\t\t\t   8. C-" << endl;
		cout << "\t\t\t\t   9. D+ \t\t\t\t   10.D" << endl;
		cout << "\t\t\t\t   11.D- \t\t\t\t   12.F" << endl << endl;
		cout << "\t\t\t....................................................................\n\n";	
		cout << "\t\t\t\t         Enter the grade for " << endl;
		cout << "\t\t\t\t         " << nodePtr->code 
			 << " - " << nodePtr->name << endl;
		cout << "\t\t\t\t         Grade Option >> ";
		cin >> g;
		
		if(g<=0||g>12||cin.fail()|| cin.get() != '\n')
		{
			do{		// prompt user to enter valid choice
				cout << endl;
				cout << "\t\t\t\t\tPlease enter a valid grade option. " <<endl;
				cout << "\t\t\t\t\tGrade Option >> ";
				cin.clear();
				cin.ignore();
				cin>>g;	
			}while(g<=0||g>12||cin.fail()|| cin.get() != '\n');	
		}
		
		nodePtr->gradeID = g;
		if(g == 1)
		{
			nodePtr->grade = "A";
		}
		else if(g == 2)
		{
			nodePtr->grade = "A-";
		}
		else if(g == 3)
		{
			nodePtr->grade = "B+";
		}
		else if(g == 4)
		{
			nodePtr->grade = "B";
		}
		else if(g == 5)
		{
			nodePtr->grade = "B-";
		}
		else if(g == 6)
		{
			nodePtr->grade = "C+";
		}
		else if(g == 7)
		{
			nodePtr->grade = "C";
		}
		else if(g == 8)
		{
			nodePtr->grade = "C-";
		}
		else if(g == 9)
		{
			nodePtr->grade = "D+";
		}
		else if(g == 10)
		{
			nodePtr->grade = "D";
		}
		else if(g == 11)
		{
			nodePtr->grade = "D-";
		}
		else if(g == 12)
		{
			nodePtr->grade = "F";
		}
		else
		{
			cout << "\n\n\t\t\t\t\t  Error for entering the grade for " << endl;
			cout << "\t\t\t\t\t  " << nodePtr->code << " - " << nodePtr->name << endl;
			cout << "\t\t\t\t\t  Please update the grade later.";
		}
				
		cout << "\n\t-----------------------------------------------------------";
		cout << "-----------------------------------------------------------\n\n";
		nodePtr = nodePtr->next;
		system("cls");
	}
}

// update new course grade
void RegisterList::updateGrade(string c,int g)
{
	ListNode *nodePtr;
	nodePtr = head;
	
	while(nodePtr->code != c && nodePtr != nullptr)
		nodePtr = nodePtr->next;
	
	if(nodePtr)
	{
		nodePtr->gradeID = g;
		if(g == 1)
			nodePtr->grade = "A";
		else if(g == 2)
			nodePtr->grade = "A-";
		else if(g == 3)
			nodePtr->grade = "B+";
		else if(g == 4)
			nodePtr->grade = "B";
		else if(g == 5)
			nodePtr->grade = "B-";
		else if(g == 6)
			nodePtr->grade = "C+";
		else if(g == 7)
			nodePtr->grade = "C";
		else if(g == 8)
			nodePtr->grade = "C-";
		else if(g == 9)
			nodePtr->grade = "D+";
		else if(g == 10)
			nodePtr->grade = "D";
		else if(g == 11)
			nodePtr->grade = "D";
		else if(g == 12)
			nodePtr->grade = "F";
		else
		{
			cout << "\n\n\t\t\t\t\t  Error for entering the grade for " << endl;
			cout << "\t\t\t\t\t  " << nodePtr->code << " - " << nodePtr->name << endl;
			cout << "\t\t\t\t\t  Please update the grade later.";
		}
	}
	else
		cout << "Course Not Found" << endl;
}

// update course type
void RegisterList::updateType(string c, char t)
{
	ListNode *nodePtr;
	nodePtr = head;
	
	while(nodePtr->code != c && nodePtr != nullptr)
		nodePtr = nodePtr->next;
	
	if(nodePtr)
	{
		nodePtr->type = t;
	}
	else
		cout << "Course Not Found" << endl;
}

// drop course
void RegisterList::dropCourse(string c)
{
	ListNode *nodePtr;
	ListNode *previousNode;
	
	if(!head)
		cout << "List is empty" << endl;
	else
	{
		if(head->code == c)
		{
			totalCourse--;
			totalUnit -= head->unit;
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			nodePtr = head;
			while(nodePtr->code != c && nodePtr != nullptr)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}
			
			if(nodePtr)
			{
			 	totalCourse--;
			 	totalUnit -= nodePtr->unit;
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
			else
				cout << "Cannot delete " << c << endl;
		}
	}
}

// found course in the list
bool RegisterList::courseFound(string c)
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

// display the list
void RegisterList::displayList()
{
	if(!head)
		cout << "\t\t\t\t-----------You haven't register any course-----------" << endl<<endl;
	else
	{
		int i=1;
		ListNode *nodePtr;
		nodePtr = head;
		cout << "       No |\t\t\t\t        Course        \t\t\t\t    | Type | Unit\n\n";
		while(nodePtr != nullptr)
		{
			cout << "       " << i << ".    " << nodePtr->code << " - "
			<< setw(72) << left<<nodePtr->name
			<< " "<< nodePtr->type << "      "<< nodePtr->unit
			<< endl;
			nodePtr = nodePtr->next;
			i++;
		}
		cout << endl << endl;
	}
}

// display the list with grade
void RegisterList::displayListWithGrade()
{
	if(!head)
		cout << "Empty List" << endl;
	else
	{
		int i=1;
		ListNode *nodePtr;
		nodePtr = head;
		cout << "   No |\t\t\t\t        Course       \t\t\t\t| Type | Unit | Grade"<<endl << endl;
		while(nodePtr != nullptr)
		{
			cout << "   " << i << ".    " << nodePtr->code << " - "
			<< setw(64) << left<<nodePtr->name
			<< "  "<< nodePtr->type << "     "<< nodePtr->unit 
			<< "\t  " <<  nodePtr->grade
			<< endl;
			nodePtr = nodePtr->next;
			i++;
		}
		cout << endl;
	}
}

// calculate the current semester GPA
void RegisterList::calcSemesterGPA()
{
	ListNode *nodePtr;
	nodePtr = head;
	double total = 0;
	while(nodePtr!= nullptr)
	{
		if(nodePtr->gradeID == 1)
		{
			total += nodePtr->unit * 4.00;
		}
		else if(nodePtr->gradeID == 2)
		{
			total += nodePtr->unit * 3.67;
		}
		else if(nodePtr->gradeID == 3)
		{
			total += nodePtr->unit * 3.33;
		}
		else if(nodePtr->gradeID == 4)
		{
			total += nodePtr->unit * 3.00;
		}
		else if(nodePtr->gradeID == 5)
		{
			total += nodePtr->unit * 2.67;
		}
		else if(nodePtr->gradeID == 6)
		{
			total += nodePtr->unit * 2.33 ;
		}
		else if(nodePtr->gradeID == 7)
		{
			total += nodePtr->unit * 2.00;
		}
		else if(nodePtr->gradeID == 8)
		{
			total += nodePtr->unit * 1.67;
		}
		else if(nodePtr->gradeID == 9)
		{
			total += nodePtr->unit * 1.33;
		}
		else if(nodePtr->gradeID == 10)
		{
			total += nodePtr->unit * 1.00;
		}
		else if(nodePtr->gradeID == 11)
		{
			total += nodePtr->unit * 0.67;
		}
		else if(nodePtr->gradeID == 12)
		{
			total += nodePtr->unit * 0.00;
		}
		else
		{
		}
		nodePtr = nodePtr->next;
	}	
	gpa = total/totalUnit;
}

// course details mutator
void RegisterList::getCourseDetail(string c, string &n, int &u)
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

// total course accessor
int RegisterList::getTotalCourse()
{
	return totalCourse;
}

// total unit accessor
int RegisterList::getTotalUnit()
{
	return totalUnit;
}

// course type accessor
char RegisterList::getCourseType(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	
	while(nodePtr->code != c && nodePtr != nullptr)
		nodePtr = nodePtr->next;
	
	return nodePtr->type;
}

// course grade id accessor
int RegisterList::getCourseGradeID(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	
	while(nodePtr->code != c && nodePtr != nullptr)
		nodePtr = nodePtr->next;
	
	return nodePtr->gradeID;	
}

// course grade accessor
string RegisterList::getCourseGrade(string c)
{
	ListNode *nodePtr;
	nodePtr = head;
	
	while(nodePtr->code != c && nodePtr != nullptr)
		nodePtr = nodePtr->next;
	
	return nodePtr->grade;	
}

// current semester GPA accessor
double RegisterList::getGPA()
{
	calcSemesterGPA();
	return gpa;
}

