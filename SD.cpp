#include "bibliotekos.h"

int main() {
	int option = 0, kiek = 0, kiekStud = 0;
	string r, bud = "";
	Studentas S;
	vector<Studentas> Studentai;

	while (option != 9) {
		kiek = Studentai.size();
		option = meniu();

		switch (option) {
		case 1:
			// prideti studenta
			cin >> S;
			Studentai.push_back(S);
			break;
		case 2:
			if (Studentai[0].getBudas() == false) {
				bud = "Galutinis(Vidurkis)";
			} else { bud = "Galutinis(Mediana)"; }
			cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << setprecision(2) << fixed << bud << endl;
			cout << "------------------------------------------" << endl;
			for (int j = 0; j < kiek; j++) {
				cout << Studentai[j];
			}
			break;

		case 3:
			FailoSkaitymas();
			cout << endl;
			break;

		case 4:
			cout << "Kiek studentu sugeneruoti faile?" << endl;
			cin >> kiekStud;
			FailuKurimas(kiekStud);
			cout << "Failas sekmingai sukurtas!" << endl;
			break;

		case 5:
			Skirstymas();
			cout << "Studentai sekmingai isrusiuoti!" << endl;
			break;
		}

	}
	return 0;
}
