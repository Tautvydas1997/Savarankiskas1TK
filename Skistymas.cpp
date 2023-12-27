#include "Skirstymas.h"

void Skirstymas() {
    ifstream open_f("Studentai.txt");
    string vardas, pavarde;
    int nd1, nd2, nd3, nd4, nd5, egz;
    int line = 0, kiek = 0;
    vector<Studentas> STs;
    vector<Studentas>::iterator it;
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

    STs.shrink_to_fit();
    open_f.close();
    
    kiek = STs.size();
    vector<Studentas> vargsiukai;
    //vargsiukai.reserve(50000);


    auto start2 = high_resolution_clock::now();

    it = STs.begin();
    while (it != STs.end()) {
        if (it->getGalutinisV() < 5) {
            vargsiukai.push_back(*it);
            it = STs.erase(it);
        }
        else {
            it++;
        }
    }

    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Studentus surusiuoti uztruko: " << duration2.count() << "ms." << endl;

    STs.clear();
    vargsiukai.shrink_to_fit();
    kiek = vargsiukai.size();
    auto start3 = high_resolution_clock::now();

    ofstream outVar("Vargsiukai.txt");
    outVar << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << setprecision(2) << fixed << "Galutinis(Vidurkis)" << endl;
    for (int j = 0; j < kiek; kiek++) {
        outVar << setw(15) << left << vargsiukai[j].getVarda() << setw(15) << left << vargsiukai[j].getPavarde() << setw(5) << left << vargsiukai[j].getGalutinisV() << endl;
    }
    outVar.close();
    vargsiukai.clear();
    kiek = STs.size();
    ofstream outKiet("Kietekai.txt");
    outKiet << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << setprecision(2) << fixed << "Galutinis(Vidurkis)" << endl;
    for (int j = 0; j < kiek; kiek++) {
        outKiet << setw(15) << left << STs[j].getVarda() << setw(15) << left << STs[j].getPavarde() << setw(5) << left << STs[j].getGalutinisV() << endl;
    }
    outKiet.close();
    STs.clear();


    //ofstream outKiet("Kietekai.txt");
    //outKiet << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << setprecision(2) << fixed << "Galutinis(Vidurkis)" << endl;
    //for (it = kietekai.begin(); it != kietekai.end(); it++) {
    //    outKiet << setw(15) << left << it->getVarda() << setw(15) << left << it->getPavarde() << setw(5) << left << it->getGalutinisV() << endl;
    //}
    //outKiet.close();
    //kietekai.clear();
    //auto stop3 = high_resolution_clock::now();
    //auto duration3 = duration_cast<milliseconds>(stop3 - start3);
    //cout << "Irasyti studentus i du skirtingus failus uztruko: " << duration3.count() << "ms." << endl;

}
