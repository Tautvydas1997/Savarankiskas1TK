#include "FailuKurimas.h"

void FailuKurimas(int c) {

	auto start = high_resolution_clock::now();
	ofstream output("Studentai.txt");
	string vardas = "Vardas";
	string pavarde = "Pavarde";
	output << setw(15) << left << vardas << setw(15) << left << pavarde << setw(5) << left << "ND1" << setw(5) << left << "ND2"
		<< setw(5) << left << "ND3" << setw(5) << left << "ND4" << setw(5) << left << "ND5" << setw(10) << left << "Egzaminas" << endl;

	for (long i = 1; i <= c; i++) {
		output << setw(15) << left << vardas + to_string(i) << setw(15) << left << pavarde + to_string(i) << setw(5) << left << rand() % 10 + 1
			<< setw(5) << left << rand() % 10 + 1 << setw(5) << left << rand() % 10 + 1 << setw(5) << left << rand() % 10 + 1
			<< setw(5) << left << rand() % 10 + 1 << setw(10) << left << rand() % 10 + 1 << endl;
	}

	output.close();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Faila sukurti uztruko: " << duration.count() << "ms." << endl;
}
