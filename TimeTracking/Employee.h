#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

#include "Enterprise.h"

using namespace std;
class Status;

class Employee
{
private:
	unsigned num;
	unsigned salary;
	unsigned timeWork; //�������� �६� � �����
	double worked; //������⢮ ��ࠡ�⠭���� �६���
	string name;
	string surname;
	string post;
	Status *type;
public:
	Employee();
	~Employee();
	unsigned getNum();
	unsigned getSalary();
	unsigned getTimeWork();
	double getWorked();
	string getName();
	string getSurname();
	Status *getStatus();
	void getInfo();

	void setNum(unsigned);
	void setWorked(unsigned);
	void setStatus(Status *);
	void setInfo();
};

Employee::Employee()
{
	cout << "� �������� ����� ���� ���㤭��!" << endl;
	setInfo();
	worked = 0;
}

Employee::~Employee()
{
	delete type;
	cout << "����㤭�� 㢮���!" << endl;	
	cin.get();
}

unsigned Employee::getNum() {
	return num;
}

unsigned Employee::getSalary() {
	return salary;
}

unsigned Employee::getTimeWork() {
	return timeWork;
}

double Employee::getWorked() {
	return worked;
}

string Employee::getName() {
	return name;
}

string Employee::getSurname() {
	return surname;
}

Status *Employee::getStatus() {
	return type;
}

void Employee::getInfo() {
	cout << "  ���: " << name << endl;
	cout << "  �������: " << surname << endl;
	cout << "  ���������: " << post << endl;
	cout << "  ����� (� �㡫��): " << salary << endl;
	cout << "  ����祥 �६� �� ����� (� ���): " << timeWork << endl;
}

void Employee::setNum(unsigned num) {
	this->num = num;
}

void Employee::setWorked(unsigned arg) {
	if (arg)
	{
		srand(time(0) + arg);

		double s;
		double x;
		double y;
		do
		{
			x = (rand() % 101 - 50) / 50.0;
			y = (rand() % 101 - 50) / 50.0;
			s = x*x + y*y;
			x = x * sqrt(-2 * log(s) / s);
		} while (s > 1 || s == 0);
		worked += x * 1.3 + 8;
	}
	else
		worked = 0;
}

void Employee::setStatus(Status *type) {
	this->type = type;
}

void Employee::setInfo() {
	cout << "  ��� > ";
	getline(cin, name);
	cout << "  ������� > ";
	getline(cin, surname);
	cout << "  ��������� > ";
	getline(cin, post);
	cout << "  ����� (� �㡫��) > ";
	cin >> salary;
	cout << "  ����祥 �६� �� ����� (� ���) > ";
	cin >> timeWork;
}
#endif