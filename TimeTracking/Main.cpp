#include <iostream>
#include <string>

#include "Enterprise.h"
#include "Employee.h"
#include "Status.h"

using namespace std;

class Menu
{
private:
	Enterprise *EnterpriseObj;
public:
	Menu(Enterprise);
	void infoEmployee();
	void rename();
	void payroll();
};

Menu::Menu(Enterprise EnterpriseObj)
{
	unsigned com;
	this->EnterpriseObj = &EnterpriseObj;
	while (1)
	{
		system("cls");
		cout << "             �������� " << EnterpriseObj.getName() << endl;
		cout.fill('=');
		cout.width(56);
		cout << "" << endl;
		cout << "���� " << EnterpriseObj.getDay();
		if (EnterpriseObj.getDay() % 7 &&
			(EnterpriseObj.getDay() % 7 - 6) ||
			!EnterpriseObj.getDay())
			cout << " (�㤭�)" << endl;
		else
			cout << " (��室��)" << endl;
		cout.width(56);
		cout << "" << endl;
		cout.fill(' ');
		EnterpriseObj.listEmployee();
		cout.fill('=');
		cout.width(56);
		cout << "" << endl;
		cout.fill(' ');
		cout << "�롥�� ����⢨�: \n"
			<< "  1 > ���ଠ�� � ���㤭���\n"
			<< "  2 > ��२�������� ��������\n"
			<< "  3 > �������� ��௫���\n"
			<< "  4 > ������騩 ����\n";
		cin >> com;
		cin.ignore();
		switch (com)
		{
		case 1:
			infoEmployee();
			break;
		case 2:
			rename();
			break;
		case 3:
			payroll();
			break;
		case 4:
			EnterpriseObj.nextDay();
			break;
		default:exit(0);
		}
	}
}

void Menu::infoEmployee() {
	unsigned num;
	unsigned com;
	Employee *EmployeeObj;
	cout << "������ � ���㤭��� > ";
	cin >> num;
	cin.ignore();
	if (num <= EnterpriseObj->getSpace() && num > 0)
	{
		EmployeeObj = EnterpriseObj->getEmployee(num - 1);
		EmployeeObj->getInfo();
		cout << "����⢨� � ���㤭����: \n"
			<< "  1 > �������� �����\n"
			<< "  2 > ��ࠢ��� � �������஢��\n"
			<< "  3 > �������\n";
		cin >> com;
		cin.ignore();
		switch (com)
		{
		case 1:
			EmployeeObj->setInfo();
			break;
		case 2:
			EmployeeObj->setStatus(new BussinessTrip());
			break;
		case 3:
			EmployeeObj->~Employee();
			EmployeeObj = nullptr;
			EnterpriseObj->deletePlace(num - 1);
			break;
		default: break;
		}
	}
}

void Menu::payroll() {
	unsigned wage;
	Employee *EmployeeObj;
	cout << "         ���     �������    ��௫��  " << endl;
	for (unsigned i = 0; i < EnterpriseObj->getSpace(); i++)
	{
		EmployeeObj = EnterpriseObj->getEmployee(i);
		if (EmployeeObj)
		{
			wage = EmployeeObj->getSalary() * EmployeeObj->getWorked() / EmployeeObj->getTimeWork();
			cout << setw(12) << EmployeeObj->getName()
				<< setw(12) << EmployeeObj->getSurname()
				<< setw(12) << wage << endl;
		}
	}
	cin.get();
}

void Menu::rename() {
	string name;
	cout << "������ ����� ��� �������� > ";
	getline(cin, name);
	EnterpriseObj->setName(name);
}

void main()
{	
	unsigned space;
	unsigned nDepartment;
	string name;

	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "���� ���������� � ��⥬� ���� ࠡ�祣� �६���!\n\n";
	cout << "�������� ���ଠ�� � ��������:\n\n"
		<< "������������ > ";
	getline(cin, name);
	cout << "��᫮ ࠡ��� ���� > ";
	cin >> space;
	cin.ignore();

	Enterprise EnterpriseObj(name, space);
	Menu MenuObj(EnterpriseObj);
}