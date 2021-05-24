#include "pch.h"
#include "Osoba.h"
#include <ctime>
#pragma warning(disable : 4996)

const std::string defaultRc = "9999999999";

RodCislo::RodCislo(){
	this->rc = defaultRc;
}

RodCislo::RodCislo(const std::string rc){
	if (!setRc(rc)) {
		this->rc = defaultRc;
	}
}

RodCislo::RodCislo(const RodCislo & o){
	this->rc = o.getRc();
}

RodCislo::~RodCislo(){
}

std::string RodCislo::getRc() const{
	return this->rc;
}

bool RodCislo::setRc(const std::string rc){
	if (kontrolaRc(rc)) {
		this->rc = rc;
		return true;
	}

	else {
		return false;
	}
}

std::string RodCislo::datumNarozeni() const{
	if (this->rc == defaultRc) {
		return "";
	}
	return std::to_string(ziskejDen()) + ". " + std::to_string(ziskejMesic()) + ". " + std::to_string(ziskejRok());
}

std::string RodCislo::pohlavi() const{
	return this->rc == defaultRc ? "" : (std::stoi(this->rc.substr(2, 2)) > 50 ? "zena" : "muz");
}

int RodCislo::vek() const{
	if (this->rc == defaultRc) {
		return 0;
	}

	time_t t = time(0);
	struct tm* now = localtime(&t);
	
	int rok = now->tm_year + 1900;
	int mesic = now->tm_mon + 1;
	int den = now->tm_mday;

	int vek = rok - ziskejRok();
	if (ziskejMesic() > mesic) {
		vek -= 1;
	}
	if (ziskejMesic() == mesic && ziskejDen() > den) {
		vek -= 1;
	}

	return vek;
}

bool RodCislo::operator==(const RodCislo &RodCislo) const{
	return this->rc == RodCislo.getRc();
}

RodCislo & RodCislo::operator=(const RodCislo &RodCislo){
	this->rc = RodCislo.getRc();
	return *this;
}


bool RodCislo::kontrolaRc(const std::string rc) const{
	if(rc.length() != 10){
		return false;
	}

	for (int i = 0; i < rc.length(); i++) {
		if (rc[i] < '0' || rc[i] > '9') {
			return false;
		}
	}

	// získali jsme prvních 9 znakù, pøevedli na èíslo a získali zbytek
	// po celoèíselném dìlení 11
	int zbytek = std::stoi(rc.substr(0, 9)) % 11;

	if (std::stoi(rc.substr(9, 1)) == zbytek) {
		return true;
	}

	else if (zbytek == 10 && rc.substr(9, 1) == "0") {
		return true;
	}

	else {
		return false;
	}
}

int RodCislo::ziskejDen() const{
	return std::stoi(this->rc.substr(4, 2));
}

int RodCislo::ziskejMesic() const{
	int mesic = std::stoi(this->rc.substr(2, 2));
	// u žen se k mesíci pøipoèítává 50
	return mesic > 50 ? mesic - 50 : mesic;
}

int RodCislo::ziskejRok() const{
	int rok = std::stoi(this->rc.substr(0, 2));
	return rok < 54 ? rok + 2000 : rok + 1900;
}

std::ostream & operator<<(std::ostream& os, const RodCislo& RodCislo){
	os << "RC: " << RodCislo.getRc() << " narozen: " << RodCislo.datumNarozeni() 
	   << " ma " << RodCislo.vek() << " let je " << RodCislo.pohlavi() << std::endl;
	return os;
}
