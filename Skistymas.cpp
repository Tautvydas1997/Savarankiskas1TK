#include "Skirstymas.h"

void Skirstymas() {
    ifstream open_f("Studentai.txt");
    string vardas, pavarde;
    int nd1, nd2, nd3, nd4, nd5, egz;
    int line = 0, kiek = 0;
    list<Studentas> STs;
    list<Studentas>::iterator it;
    //STs.reserve(1000000);

    auto start1 = high_resolution_clock::now();
    for (string eil; getline(open_f, eil);) {
        if (line == 0) {
            line++;
        }
        else {
            stringstream ssin(eil);
            ssin >> pavarde >> vardas >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> egz;
            vector<int> homeworkGrades;
            homeworkGrades.push_back(nd1);
            homeworkGrades.push_back(nd2);
            homeworkGrades.push_back(nd3);
            homeworkGrades.push_back(nd4);
            homeworkGrades.push_back(nd5);
            Studentas student(vardas, pavarde, homeworkGrades, egz);
            STs.push_back(student);
            line++;
        }
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Nuskaityti faila uztruko: " << duration1.count() << "ms." << endl;

    //STs.shrink_to_fit();
    open_f.close();
    
    kiek = STs.size();
    list<Studentas> vargsiukai, kietekai;
    //vargsiukai.reserve(50000);
    //kietekai.reserve(50000);

    auto start2 = high_resolution_clock::now();

    for (it = STs.begin(); it != STs.end(); it++) {
        it->countGalutinis(0);
        if (it->getGalutinisV() < 5) {
            vargsiukai.push_back(*it);
        }
        else {
            kietekai.push_back(*it);
        }
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Studentus surusiuoti uztruko: " << duration2.count() << "ms." << endl;

    STs.clear();
    //vargsiukai.shrink_to_fit();
    //kietekai.shrink_to_fit();

    auto start3 = high_resolution_clock::now();

    ofstream outVar("Vargsiukai.txt");
    outVar << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << setprecision(2) << fixed << "Galutinis(Vidurkis)" << endl;
    for (it = vargsiukai.begin(); it != vargsiukai.end(); it++) {
        outVar << setw(15) << left << it->getVarda() << setw(15) << left << it->getPavarde() << setw(5) << left << it->getGalutinisV() << endl;
    }
    outVar.close();
    vargsiukai.clear();

    ofstream outKiet("Kietekai.txt");
    outKiet << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << setprecision(2) << fixed << "Galutinis(Vidurkis)" << endl;
    for (it = kietekai.begin(); it != kietekai.end(); it++) {
        outKiet << setw(15) << left << it->getVarda() << setw(15) << left << it->getPavarde() << setw(5) << left << it->getGalutinisV() << endl;
    }
    outKiet.close();
    kietekai.clear();
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(stop3 - start3);
    cout << "Irasyti studentus i du skirtingus failus uztruko: " << duration3.count() << "ms." << endl;

}
