#include <iostream>
#include <windows.h>  
#include "Solder.h"

using namespace std;

int Voen::voenCounter = 0;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Voen A, B;
	cout << "\t\t������������ ������������ ������ � ����������" << endl;
	cout << "���-�� ������: " << Voen::getVoenCounter() << endl;
	A.Input();
	A.Print();


	cout << endl << "���-�� ��������� ������� �� ���������� ��������� ���������� '+': " << A.Getkategor();
	A = A + 3;
	cout << endl << "���-�� �����: " << A.Getkategor();



	cout << endl << endl << "���� ���������� '++'(��������): " << endl;
	B = A++;
	cout << "���-�� ��������� ������� �������: " << B.Getkategor();
	cout << endl << "���-�� � �������: " << A.Getkategor();

	cout << endl << endl << "���� ���������� '++'(�������): " << endl;
	B = ++A;
	cout << "���-�� ��������� � ������ �������: " << B.Getkategor();
	cout << endl << "���-�� � �������: " << A.Getkategor();

	int otsroch;
	int otsrochWithPointer = A.GetotsrochWithPointer(&otsroch);
	cout << endl << endl << "����������� ���-�� ��������� ������� ������� ����� ���������: " << otsrochWithPointer << endl;
	int& otsrochWithReference = A.GetotsrochWithReference();
	cout << "����������� ���-�� ��������� ������� ������� ����� ������: " << otsrochWithReference << endl;

}