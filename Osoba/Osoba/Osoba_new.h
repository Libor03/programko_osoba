#pragma once
#ifndef OSOBA_H_NEW_
#define OSOBA_H_NEW_
#include <string>
#include <ostream>
#include "osoba.h"


class Osoba : public RodCislo
{
public:
	Osoba();
	Osoba(const std::string, const std::string, const std::string);
	Osoba(const Osoba&);
	virtual ~Osoba();

	std::string getJmeno()const;
	std::string getPrijmeni()const;
	std::string getEmail()const;
	

	bool setJmeno(const std::string);
	bool setPrijmeni(const std::string);
	bool setEmail(const std::string);

private:
	std::string jmeno;
	std::string prijmeni;
	std::string email;
};



class Zamestnanec : public Osoba {
public:
	Zamestnanec();
	Zamestnanec(const std::string);
	Zamestnanec(const Zamestnanec&);
	virtual ~Zamestnanec();

	std::string getFunkce()const;
	bool setFunkce(const std::string);

	

private:
	std::string funkce;
};


class Student : public Osoba {
public:
	Student();
	Student(const std::string);
	Student(const Student&);
	virtual ~Student();

	std::string getFunkce()const;
	bool setFunkce(const std::string);
};

#endif // !OSOBA_H_
