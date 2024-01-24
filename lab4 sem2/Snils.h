#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>

class SNILS
{
public:
	SNILS();
	SNILS(long long int number, int pol);
	~SNILS();

	long long int Getnumber() const;
	int Getpol() const;
	void Input();


private:
	long long int number;
	int pol;

	bool CheckArguments(long long int number, int pol);
};


bool SNILS::CheckArguments(long long int number, int pol) {
	return number > 0 && pol > 0 && pol < 3;
}

SNILS::SNILS()
{
	number = pol = 0;
}


SNILS::SNILS(long long int number, int pol)
{
	if (CheckArguments(number, pol)) {
		this->number = number;
		this->pol = pol;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

SNILS::~SNILS()
{
}


long long int SNILS::Getnumber() const {
	return number;
}

int SNILS::Getpol() const {
	return pol;
}

void SNILS::Input() {
	long long int number;
	int pol;

	std::cout << "������� ����� ������: ";
	std::cin >> number;
	std::cout << "������� ���(1-�������, 2-�������): ";
	std::cin >> pol;
	while (getchar() != '\n');
	if (CheckArguments(number, pol)) {
		this->number = number;
		this->pol = pol;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}