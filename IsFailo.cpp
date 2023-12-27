#include "IsFailo.h"

void FailoSkaitymas() {
	ifstream open_f("kursiokai.txt");
    string vardas, pavarde;
    int nd1, nd2, nd3, nd4, nd5, egz;
    int line = 0, kiek = 0;
    vector<Studentas> STs;

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
            }
    }
    open_f.close();

    sort(STs.begin(), STs.end(), [](Studentas lhs, Studentas rhs) {
        return lhs.getPavarde() < rhs.getPavarde();
        });

    cout << endl;
    cout << "Pavarde    Vardas    Galutinis (vid.)    Galutinis(med.)" << endl;
    cout << "-------------------------------------------------------------" << endl;
    kiek = STs.size();
    for (int j = 0; j < kiek; j++) {
        STs[j].countGalutinis(false);
        cout << STs[j];
    }
}
