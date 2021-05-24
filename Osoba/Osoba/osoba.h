#pragma once
#ifndef OSOBA_H_
#define OSOBA_H_
#include <string>
#include <ostream>

class RodCislo {
public:
	RodCislo();
	RodCislo(const std::string);
	RodCislo(const RodCislo&);
	virtual ~RodCislo();

	std::string getRc()const;
	bool setRc(const std::string);

	std::string datumNarozeni()const;
	std::string pohlavi()const;
	int vek()const;

	bool operator==(const RodCislo&)const;
	RodCislo& operator=(const RodCislo&);
	friend std::ostream& operator<<(std::ostream&, const RodCislo&);

private:
	std::string rc;

	bool kontrolaRc(const std::string)const;
	int ziskejDen()const;
	int ziskejMesic()const;
	int ziskejRok()const;
};

#endif // !OSOBA_H_
