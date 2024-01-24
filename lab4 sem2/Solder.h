#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Voen.h"
#include "Vkaf.h"

class Solder
{
public:
	Solder();
	Solder(Voen voen, Vkaf vkaf, std::string data, std::string time, int status);
	~Solder();

	Voen Getvoen() const;
	Vkaf Getvkaf() const;
	std::string Getdata() const;
	std::string Gettimes() const;
	int Getstatus() const;
	void Input();
	void Print() const;
	void Setstatus(int status);

private:
	Voen voen;
	Vkaf vkaf;
	std::string data;
	std::string time;
	int status;

	bool CheckArguments(Voen voen, Vkaf vkaf, std::string data, std::string time, int status);
};

bool Solder::CheckArguments(Voen voen, Vkaf vkaf, std::string data, std::string time, int status) {
	return status > 0 && status < 3;
}


Solder::Solder()
{
	voen = Voen();
	vkaf = Vkaf();
	data = "�� �������";
	time = "�� �������";
	status = 0;
}


Solder::Solder(Voen voen, Vkaf vkaf, std::string data, std::string time, int status)
{
	this->voen = voen;
	this->vkaf = vkaf;
	this->data = data;
	this->time = time;
	this->status = status;
}

Solder::~Solder()
{
}


Voen Solder::Getvoen() const {
	return voen;
}

Vkaf Solder::Getvkaf() const {
	return vkaf;
}

std::string Solder::Getdata() const {
	return data;
}
std::string Solder::Gettimes() const {
	return time;
}
int Solder::Getstatus() const {
	return status;
}
void Solder::Setstatus(int status) {
	this->status = status;
}

void Solder::Input() {
	Voen voen;
	Vkaf vkaf;
	std::string data;
	std::string time;
	int status;
	std::cout << "\t���� ������ � ����������\n";
	voen.Input();
	//vkaf.Input();
	std::cout << "������� ���� ���� � ���������: ";
	while (getchar() != '\n');
	std::getline(std::cin, data);
	std::cout << "������� ����� ���� � ���������: ";
	std::getline(std::cin, time);
	std::cout << "������� (1-�����, 2- �� �����): ";
	std::cin >> status;
	if (CheckArguments(voen, vkaf, data, time, status)) {
		this->voen = voen;
		this->vkaf = vkaf;
		this->data = data;
		this->time = time;
		this->status = status;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Solder::Print() const {
	std::cout << "\t���������� � ����������\n";
	std::cout << "����: " << this->data << "\t�����: " << this->time << "\t(1-�����, 2- �� �����): " << this->status << "\n\n";
}