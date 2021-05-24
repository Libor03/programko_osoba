#include "pch.h"
#include "Osoba.h"
#include "Osoba_new.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void vypis(const RodCislo& rc, const std::string text) {
	cout << text << endl;
	for (int i = 0; i < text.length(); i++) {
		cout << "-";
}
	cout << endl;
	cout << rc << endl;
	return;
}

void vypisy(const RodCislo& jmeno, const std::string prijmeni, const std::string email, const std::string text) {
	cout << jmeno << prijmeni<<email << endl;
	for (int i = 0; i < text.length(); i++) {
		cout << "-";
	}
	cout << endl;
	cout << jmeno << endl;
	return;
}


int main() {
	/*RodCislo rc1;
	RodCislo rc2("6462191472");
	RodCislo rc3(rc2);*/
	Osoba o1;
	/*Osoba o2("6462191109", "Hana", "Rohanova", "rohanova@sspu-opava.cz");
	Zamestnanec z1;
	Zamestnanec z2("6001011236", "Josef", "Vonasek", "vonasek@sspu-opava.cz", "ucitel odbornych predmetu");
	Student s1;
	Student s2("0355179990", "Marie", "Svobodova", "mariesvobodova@email.cz", "IT3");*/
	/*vypis(rc1, "Objekt rc1 vytvoreny vychozim konstruktorem tridy rodneCislo");
	vypis(rc2, "Objekt rc2 vytvoreny konstruktorem s parametry tridy rodneCislo");
	vypis(rc3, "Objekt rc3 vytvoreny kopirovacim konstruktorem tridy rodneCislo");*/
	vypisy(o1, "Objekt o1 vytvoreny vychozim konstruktorem tridy osoba");
	/*vypis(o2, "Objekt o2 vytvoreny konstruktorem s parametry tridy osoba");
	vypis(z1, "Objekt z1 vytvoreny vychozim konstruktorem tridy zamestnanec");
	vypis(z2, "Objekt z2 vytvoreny konstruktorem s parametry ""(rc,jmeno,prijmeni,email,funkce) tridy zamestnanec");
	vypis(s1, "Objekt s1 vytvoreny vychozim konstruktorem tridy student");
	vypis(s2, "Objekt s2 vytvoreny konstruktorem s parametry ""(rc,jmeno,prijmeni,email,trida) tridy student");*/
	return 0;
}