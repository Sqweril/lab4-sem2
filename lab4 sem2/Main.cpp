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
	cout << "\t\tДемонстрация статического метода и переменной" << endl;
	cout << "Кол-во Солдат: " << Voen::getVoenCounter() << endl;
	A.Input();
	A.Print();


	cout << endl << "Кол-во посещений солдата до приминения оператора перегрузки '+': " << A.Getkategor();
	A = A + 3;
	cout << endl << "Кол-во после: " << A.Getkategor();



	cout << endl << endl << "Тест перегрузки '++'(Постфикс): " << endl;
	B = A++;
	cout << "Кол-во посещений другого солдата: " << B.Getkategor();
	cout << endl << "Кол-во у первого: " << A.Getkategor();

	cout << endl << endl << "Тест перегрузки '++'(Префикс): " << endl;
	B = ++A;
	cout << "Кол-во посещений у нового солдата: " << B.Getkategor();
	cout << endl << "Кол-во у первого: " << A.Getkategor();

	int otsroch;
	int otsrochWithPointer = A.GetotsrochWithPointer(&otsroch);
	cout << endl << endl << "Возвращение кол-ва посещений первого солдата через указатель: " << otsrochWithPointer << endl;
	int& otsrochWithReference = A.GetotsrochWithReference();
	cout << "Возвращение кол-ва посещений первого солдата через ссылку: " << otsrochWithReference << endl;

}