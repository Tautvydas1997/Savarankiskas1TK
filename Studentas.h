#pragma once
#include "bibliotekos.h"

class Studentas {
	string vardas;
	string pavarde;
	vector<int> nd; // Namu darbu ivertinimu masyvas
	int egz; // Egzamino rezultatas
	bool budas; // Galutinio skaiciavimo budas
	double galutinisV; // Galutinis balas
	double galutinisM;

public:
	Studentas();

	Studentas(string v, string p, vector<int> n, int e);

	Studentas(const Studentas& s);

	~Studentas();

	void countGalutinis(bool budas);

	friend ostream& operator<<(ostream& output, const Studentas& S);
	friend istream& operator>>(istream& input, Studentas& S);

	string getVarda();
	string getPavarde();
	bool getBudas();
	double getGalutinisV();
	double getGalutinisM();
};
