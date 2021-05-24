#include "pch.h"
#include "Osoba_new.h"
#include <ctime>
#pragma warning(disable : 4996)
std::string defaultFunkce = "ucitel";
Zamestnanec::Zamestnanec()
{
	this->funkce = "ucitel";
}

Zamestnanec::Zamestnanec(const std::string funkce)
{
	if (!setFunkce(funkce)) {
		this->funkce = defaultFunkce;
	}
}

Zamestnanec::Zamestnanec(const Zamestnanec& o)
{
	this->funkce = o.getFunkce();
}

Zamestnanec::~Zamestnanec()
{
}

std::string Zamestnanec::getFunkce() const
{
	return std::string();
}

bool Zamestnanec::setFunkce(const std::string funkce)
{
	
	this->funkce = funkce;
	return true;
	
}

Osoba::Osoba()
{
	this->jmeno = "Karel";
	this->prijmeni = "Novak";
	this->email = "karelnovak@gmail.com";
}

Osoba::Osoba(const std::string jmeno, const std::string prijmeni, const std::string email)
{
	this->jmeno = getJmeno();
	this->prijmeni = getPrijmeni();
	this->email = getEmail();
}

Osoba::Osoba(const Osoba&)
{
}

Osoba::~Osoba()
{
}

std::string Osoba::getJmeno() const
{
	return this->jmeno;
}

std::string Osoba::getPrijmeni() const
{
	return this->prijmeni;
}

std::string Osoba::getEmail() const
{
	return this->email;
}

bool Osoba::setJmeno(const std::string jmeno)
{
	this->jmeno = jmeno;
	return true;
}

bool Osoba::setPrijmeni(const std::string prijmeni)
{
	this->prijmeni = prijmeni;
	return true;
}

bool Osoba::setEmail(const std::string email)
{
	this->email = email;	
	return true;
}
