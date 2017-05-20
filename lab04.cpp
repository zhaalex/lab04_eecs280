qs#include "lab04.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/* EmployeeRecord */

void EmployeeRecord_init( EmployeeRecord *rec, string in_name, string in_gender, int in_age, int in_rank )
{
	// TASK 1: Implement setRecord
	rec->name = in_name;
	rec->gender = in_gender;
	rec->age = in_age;
	rec->rank = in_rank;
}

void EmployeeRecord_promote( EmployeeRecord *rec )
{
	// TASK 1: Implement promote
	++(rec->rank);
}

void EmployeeRecord_demote( EmployeeRecord *rec )
{
	// TASK 1: Implement demote
	--(rec->rank);
}

void EmployeeRecord_printInfo( const EmployeeRecord *rec )
{
	cout << "Name: " << rec->name << " Gender: " << rec->gender << " Age: " << rec->age << " Rank: " << rec->rank << endl;
}

/* Employee */


Employee::Employee( string in_name, string in_gender, int in_age, int in_rank )
			: name(in_name), gender(in_gender), age(in_age), rank(in_rank) {
	// TASK 2: Implement Constructor
	//Nothing to do here
}

void Employee::promote()
{
	// TASK 2: Implement promote
	++(this->rank);
}

void Employee::demote()
{
	// TASK 2: Implement demote
	--(this->rank);
}

void Employee::printInfo()
{
	cout << "Name: " << name << " Gender: " << gender << " Age: " << age << " Rank: " << rank << endl;
}

int main()
{
	vector<EmployeeRecord> eecsSoft;

	EmployeeRecord employeeOneJoe;
	string employeeOneName = "Joe";
	string employeeTwoName = "Jordan";
	string M = "Male";
	string F = "Female";

	EmployeeRecord_init(&employeeOneJoe, employeeOneName, M, 33, 14);
	EmployeeRecord employeeTwoJordan;
	EmployeeRecord_init(&employeeTwoJordan, employeeTwoName, F, 28, 21);

	// TASK 3: Create two employees with EmployeeRecord and add to eecsSoft
	eecsSoft.push_back(employeeOneJoe);
	eecsSoft.push_back(employeeTwoJordan);


	vector<Employee> umichWorks;

	string employeeThreeName = "Daved";
	string employeeFourName = "Wand";
	Employee employeeThreeDaved = Employee(employeeThreeName, M, 49, 55);
	Employee employeeFourWand = Employee(employeeFourName, F, 41, 71);
	// TASK 3: Create two employees with Employee and add to umichWorks
	umichWorks.push_back(employeeThreeDaved);
	umichWorks.push_back(employeeFourWand);


	int eecsSoftSize = eecsSoft.size();
	
	cout << "Welcome to eecsSoft! Here are our loyal employees: " << endl;
	for( int index = 0; index < eecsSoftSize; ++index )
	{
		EmployeeRecord_printInfo( &eecsSoft[index] );
	}

	// TASK 3: Promote one employee and demote the other at eecsSoft
	EmployeeRecord_demote(&eecsSoft[0]);
	EmployeeRecord_promote(&eecsSoft[1]);

	cout << "Here is the new info for the employees of eecsSoft: " << endl;
	for( int index = 0; index < eecsSoftSize; ++index )
	{
		EmployeeRecord_printInfo( &eecsSoft[index] );
	}
	
	int umichWorksSize = umichWorks.size();

	cout << endl << "Welcome to umichWorks! Here are our loyal employees: " << endl;
	for( int index = 0; index < umichWorksSize; ++index )
	{
		umichWorks[index].printInfo();
	}

	// TASK 3: Promote one employee and demote the other at umichWorks
	umichWorks[1].demote();
	umichWorks[0].promote();


	cout << "Here is the new info for the employees of umichWorks: " << endl;
	for( int index = 0; index < umichWorksSize; ++index )
	{
		umichWorks[index].printInfo();
	}

	return 0;
}
