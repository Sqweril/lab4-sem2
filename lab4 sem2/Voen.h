#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "PersData.h"

class Voen
{
public:
	Voen();
	Voen(PersData persdata, int kategor, int otsroch);
	~Voen();

	PersData Getpersdata() const;
	int Getkategor() const;
	int Getotsroch() const;
	void Input();
	void Print() const;
	void Setotsroch(int otsroch);
	static int getVoenCounter();
	int GetotsrochWithPointer(int* result);
	int& GetotsrochWithReference();
	Voen operator +(int value)const
	{
		Voen temp;
		temp.persdata = this->persdata;
		temp.kategor = this->kategor + value;
		temp.otsroch = this->otsroch;
		return temp;
	}

	Voen operator ++(int)
	{
		Voen temp(*this);
		kategor++;
		voenCounter++;
		return temp;
	}
	Voen& operator++()
	{
		++kategor;
		return *this;
	}


private:
	PersData persdata;
	int kategor;
	int otsroch;
	static int voenCounter;

	bool CheckArguments(PersData persdata, int kategor, int otsroch);
};

bool Voen::CheckArguments(PersData persdata, int kategor, int otsroch) {
	return kategor > 0 && otsroch > 0;
}


Voen::Voen()
{
	persdata = PersData();
	kategor = 0;
	otsroch = 0;
	voenCounter++;
}


Voen::Voen(PersData persdata, int kategor, int otsroch)
{
	this->persdata = persdata;
	this->kategor = kategor;
	this->otsroch = otsroch;
	voenCounter++;
}

Voen::~Voen()
{
	voenCounter--;
}


PersData Voen::Getpersdata() const {
	return persdata;
}

int Voen::Getkategor() const {
	return kategor;
}

int Voen::Getotsroch() const {
	return otsroch;
}
void Voen::Setotsroch(int otsroch) {
	this->otsroch = otsroch;
}

int Voen::getVoenCounter()
{
	return voenCounter;
}

int Voen::GetotsrochWithPointer(int* result)
{
	*result = this->otsroch;
	return *result;
}

int& Voen::GetotsrochWithReference()
{
	return otsroch;
}


void Voen::Input() {
	PersData persdata;
	int kategor;
	int otsroch;
	std::cout << "\tВвод данных призывника с военкомата\n";
	persdata.Input();
	std::cout << "Введите сколько раз посещал военкомат: ";
	std::cin >> kategor;
	std::cout << "Введите отсрочку: ";
	std::cin >> otsroch;
	if (CheckArguments(persdata, kategor, otsroch)) {
		this->persdata = persdata;
		this->kategor = kategor;
		this->otsroch = otsroch;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

void Voen::Print() const {
	std::cout << "\tИнформация о призывнике с военкомата\n";
	std::cout << "ФИО: " << this->persdata.Getfio() << "\tКатегория: " << this->kategor << "\tНаличие отсрочки: " << this->otsroch << "\n\n";
}