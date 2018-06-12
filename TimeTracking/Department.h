#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>

#include "Employee.h"

using namespace std;

class Department
{
private:
	string name;
	unsigned num;
	unsigned space;
	Employee *Employees;
public:
	Department();
	string getName();
	unsigned getNum();
	unsigned getSpace();
	void setNum(unsigned);
	void setName(string);
	void addEmployee(Employee *);
	/*void removeEmployee(Employee);*/
};

Department::Department()
{
	cin.ignore();
	cout << "  Наименование отдела > ";
	getline(cin, name);
	cout << "  Число рабочих мест > ";
	cin >> space;
	//Employee *Employees = static_cast<Employee*>(operator new[](space * sizeof(Employee)));
	cout << endl;
}

string Department::getName() {
	return name;
}

unsigned Department::getNum() {
	return num;
}

unsigned Department::getSpace() {
	return space;
}

void Department::setNum(unsigned num) {
	this->num = num;
}

void Department::setName(string name) {
	this->name = name;
}

void Department::addEmployee(Employee *EmployeeObj) {
	(Employee *)EmployeeObj.setDepartment(this);
}

/*void Department::removeEmployee(Employee EmployeeObj) {
	~EmployeeObj.remove();
}*/

#endif