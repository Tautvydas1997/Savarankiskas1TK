#include "Studentas.h";

Studentas::Studentas() {
	vardas = "";
	pavarde = "";
	nd.push_back(0);
	egz = 0;
	galutinisV = 0;
	galutinisM = 0;
}

Studentas::Studentas(string v, string p, vector<int> n, int e) {
	vardas = v;
	pavarde = p;
	nd = n;
	egz = e;
	galutinisV = 0;
	galutinisM = 0;
}

Studentas::Studentas(const Studentas& s) {
	vardas = s.vardas;
	pavarde = s.pavarde;
	nd = s.nd;
	egz = s.egz;
	galutinisV = s.galutinisV;
	galutinisM = s.galutinisM;
}

Studentas::~Studentas() {};

ostream& operator<<(ostream& output, const Studentas& S) {

	output << setw(15) << left << S.pavarde << setw(15) << left << S.vardas;
	output << setw(15) << left << S.galutinisV << setw(15) << left << S.galutinisM << endl;
		//output << setw(15) << left << S.galutinisM;
	return output;
}

istream& operator>>(istream& input, Studentas& S) {
	int i = 0, ar = 0, kiek = 0, pazym = 0;
	bool b = false;
	cout << "Naujo studento ivedimas" << endl;
	cout << "Iveskite studento varda:" << endl;
	cin >> S.vardas;
	cout << "Iveskite studento pavarde:" << endl;
	cin >> S.pavarde;
	cout << "Sugeneruoti studento balus? Iveskite \"1\"" << endl;
	cout << "Ivesite rankiniu budu? Iveskite \"2\"" << endl;
	cin >> ar;
	if (ar == 1) {
		cout << "Kiek namu darbu rezultatu sugeneruoti?" << endl;
		cin >> kiek;
		for (i = 0; i < kiek; i++) {
			pazym = rand() % 10;
			S.nd.push_back(pazym);
		}
		pazym = rand() % 10; // egzamino rezultatas
		S.egz = pazym;
	}
	else {
		cout << "Iveskite studento namu darbu rezultatus:" << endl;

		cout << "Baige iveskite 999 ir paspauskite enter" << endl;
		while (i != 999) {
			cin >> i;
			if (i < 11) {
				S.nd.push_back(i);
			}
		}
		cout << "Iveskite egzamino rezultata:" << endl;
		cin >> S.egz;
	}
	cout << "Kokiu budu skaiciuoti galutini pazymi? 0 - Vidurkis / 1 - Mediana" << endl;
	cin >> b;
	S.countGalutinis(b);
	S.budas = b;
	cout << "Duomenys sekmingai ivesti!" << endl;
	return input;
}

string Studentas::getVarda() {
	return vardas;
}

string Studentas::getPavarde() {
	return pavarde;
}

bool Studentas::getBudas() {
	return budas;
}

double Studentas::getGalutinisV() {
	return galutinisV;
}

double Studentas::getGalutinisM() {
	return galutinisM;
}

void Studentas::countGalutinis(bool budas) {
	int k = nd.size();
	int total = 0;
	//if (budas == 1) {
		for (int i = 0; i < k; i++) {
			total += nd[i];
		}
		try {
			galutinisV = total / (double)k;
		}
		catch (exception& e) {
			cout << "Dalyba is nulio negalima!" << endl;
		}
		galutinisV = (galutinisV * 0.4) + (egz * 0.6);
	//}
	//else {
		sort(nd.begin(), nd.end());
		if (k % 2 == 1) {
			k = k / 2;
			galutinisM = (nd[k] * 0.4) + (egz * 0.6);
		}
		else {
			k = k / 2;
			k = (nd[k - 1] + nd[k]) / 2;
			galutinisM = (k * 0.4) + (egz * 0.6);
		}
	//}
}
