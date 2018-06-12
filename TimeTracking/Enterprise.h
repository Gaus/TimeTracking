#ifndef ENTERPRISE_H
#define ENTERPRISE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "Employee.h"
#include "Status.h"

using namespace std;

class Enterprise
{
private:
	unsigned day;
	unsigned space; //������⢮ ࠡ��� ���� ��������
	unsigned workPlace; //������⢮ ������� ࠡ��� ���� � ��������
	unsigned *places;
	string name;
	Employee *EmployeeObj;

public:
	Enterprise(string, unsigned);

	unsigned getDay();
	unsigned getSpace();
	string getName();
	Employee *getEmployee(unsigned);

	void setName(string);
	void deletePlace(unsigned);
	void listEmployee();
	void nextDay();
};

Enterprise::Enterprise(string name, unsigned space)
{
	this->day = 0;
	this->name = name;
	this->space = space;
	this->workPlace = 1;

	places = new unsigned [space] {0};
	EmployeeObj = static_cast<Employee*>(operator new[](space * sizeof(Employee))); //�뤥����� ����� ��� ���㤭���� ��������
	new (EmployeeObj) Employee;
	EmployeeObj[0].setNum(1);
	EmployeeObj[0].setStatus(new Working());
	places[0] = 1;
}

unsigned Enterprise::getDay() {
	return day;
}

unsigned Enterprise::getSpace() {
	return space;
}

string Enterprise::getName() {
	return name;
}

void Enterprise::deletePlace(unsigned i) {
	places[i] = 0;
	workPlace--;
}

Employee *Enterprise::getEmployee(unsigned num) {
	if (places[num])
		return EmployeeObj + num;
	else
		return nullptr;
}

void Enterprise::listEmployee() {
	cout << "| � |         ���     �������|   �����   | ��ࠡ�⠭� |" << endl
		<< "|---|------------------------|------------|------------|" << endl;
	for (unsigned i = 0; i < space; i++)
		if (places[i])
			cout << "|" << setw(3) << EmployeeObj[i].getNum() << "|"
			<< setw(12) << EmployeeObj[i].getName()
			<< setw(12) << EmployeeObj[i].getSurname() << "|"
			<< setw(12) << EmployeeObj[i].getStatus()->getName() << "|"
			<< setw(12) << EmployeeObj[i].getWorked() << "|" << endl;
}

void Enterprise::nextDay() {
	srand(time(0));

	int appear = rand() % 5;
	int value = rand() % 1000;
	int seed = rand() % workPlace;

	for (unsigned i = 0; i < space; i++) // ���������� ��ࠡ�⠭���� �६��� � ������� ࠡ���饬� ࠡ�⭨��
		if (places[i])
		{
			if (day % 7 && (day % 7 - 6) || !day) // ���� ��室��� ����
				if (EmployeeObj[i].getStatus()->getName() != "����⠥�" &&
					EmployeeObj[i].getStatus()->getName() != "�������஢��")
					EmployeeObj[i].getStatus()->change(EmployeeObj + seed); // ��������� ����� � ��� ��ࠡ����� ࠡ�⭨���
				else
				{
					if (EmployeeObj[i].getStatus()->getName() == "�������஢��")
					{
						BussinessTrip *EmployeeTravel = static_cast<BussinessTrip*>(EmployeeObj[i].getStatus());
						EmployeeTravel->changeTravelDay(); // ��������� ������⢠ ���� � �������஢��
						if (!EmployeeTravel->changeTravelDay())
							EmployeeObj[i].setStatus(new Working());
					}
					EmployeeObj[i].setWorked(i + 1);
				}
			if (!(day % 30)) // ���㫥��� ��ࠡ�⠭��� �६��� �� ���祭�� �����
				EmployeeObj[i].setWorked(0);
		}
		else
			break;
	if (!appear && workPlace <= space) // 25 %  蠭� ������ ������ ���㤭���, �᫨ ���� ᢮������ ���� � ��������
		for (unsigned i = 1; i < space; i++)
			if (!places[i])
			{
				new (EmployeeObj + i) Employee;
				EmployeeObj[i].setNum(i + 1);
				EmployeeObj[i].setStatus(new Working);
				places[i] = 1;
				workPlace++;
				break;
			}
	EmployeeObj[seed].getStatus()->change(EmployeeObj + seed); //��������� ����� ��砩�� ��࠭���� ࠡ�⭨��
	day++;
}

void Enterprise::setName(string name) {
	this->name = name;
}
#endif