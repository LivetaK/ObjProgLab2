#include "studentai.h"


void ivedimas(list<mok>& stud) {
    mok naujas_stud;
    cout << "Iveskite studento varda ir pavarde:" << endl;
    cin >> naujas_stud.var >> naujas_stud.pav;
    int pazymys;
    cout << "Iveskite studento tarpinius namu darbu rezultatus(noredami uzbaigti, iveskite neigiama skaiciu):" << endl;
    while (true) {
        cin >> pazymys;
        if (cin.fail() || pazymys > 10 || pazymys == 0) {
            cin.clear();
            cin.ignore();
            cout << "Netinkamas formatas, bandykite dar karta" << endl;
            continue;
        }

        if (pazymys < 0) {
            break;
        }
        naujas_stud.nd.push_back(pazymys);
    }
    try {
        if (naujas_stud.nd.empty()) {
            throw runtime_error("Neivestas nei vienas pazymys.");
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        exit(1);
    }
    cout << "Iveskite studento egzamino rezultata:" << endl;
    while (!(cin >> naujas_stud.eg) || naujas_stud.eg < 1 || naujas_stud.eg > 10) {
        cout << "Netinkamas formatas, bandykite dar karta" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    stud.push_back(naujas_stud);
}

void meniu(int& antrasPasirinkimas) {
    cout << "Pasirinkite" << endl;
    cout << "1. Ivesti studentu duomenis ranka." << endl;
    cout << "2. Pazymius sugeneruoti automatiskai." << endl;
    cout << "3. Automatiskai sugeneruoti ir pazymius, ir studentu vardus, pavardes." << endl;
    cout << "4. Baigti darba." << endl;
    cout << "Jusu pasirinkimas: ";
    while (!(cin >> antrasPasirinkimas)) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        meniu(antrasPasirinkimas);
    }
}

void calculateResults(list<mok>& stud) {

    for (auto i = stud.begin(); i != stud.end(); i++) {
        double sum = accumulate(i->nd.begin(), i->nd.end(), 0.0);
        double vid = sum / i->nd.size();
        i->gal_vid = (0.4 * vid + 0.6 * i->eg);
        i->nd.sort();
        if (i->nd.size() % 2 == 0) {
            auto v1 = next(i->nd.begin(), i->nd.size() / 2 - 1);
            auto v2 = next(i->nd.begin(), i->nd.size() / 2);
            i->gal_med = ((*v1 + *v2) / 2.0 * 0.4) + 0.6 * i->eg;
        }
        else {
            auto middle = next(i->nd.begin(), i->nd.size() / 2);
            i->gal_med = (*middle * 0.4) + (0.6 * i->eg);
        }
    }
}

char rikiavimoklausimas() {
    cout << "Jei norite matyti galutini rezultata apskaiciuota pagal:" << endl;
    cout << "vidurki - iveskite V" << endl;
    cout << "mediana - iveskite M" << endl;
    char a;
    while (!(cin >> a) || (a != 'V' && a != 'v' && a != 'M' && a != 'm')) {
        cout << "Netinkama ivestis, bandykite dar karta" << endl;
        cin.clear();
        cin.ignore();
    }
    return a;
}
void isvedimas(list<mok>& stud, ostream& os, char a) {

    if (a == 'V' || a == 'v') {
        os << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
        os << "--------------------------------------------------------------" << endl;
        for (auto i = stud.begin(); i != stud.end(); i++) {
            os << left << setw(20) << i->var << setw(20) << i->pav << setw(20) << fixed << setprecision(2) << i->gal_vid << endl;
        }
    } if (a == 'M' || a == 'm') {
        os << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
        os << "--------------------------------------------------------------" << endl;
        for (auto i = stud.begin(); i != stud.end(); i++) {
            os << left << setw(20) << i->var << setw(20) << i->pav << setw(20) << fixed << setprecision(2) << i->gal_med << endl;
        }
    }
}

void meniuAntras(int& antrasPasirinkimas) {
    cout << "jei norite, kad duomenys butu isrikiuoti pagal:" << endl;
    cout << "varda - iveskite 1" << endl;
    cout << "pavarde - iveskite 2" << endl;
    cout << "vidurki - iveskite 3" << endl;
    cout << "mediana - iveskite 4" << endl;
    while (!(cin >> antrasPasirinkimas) || antrasPasirinkimas < 1 || antrasPasirinkimas > 4) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool pagalVarda(const mok& a, const mok& b) {
    return stoi(a.var.substr(6, 1)) < stoi(b.var.substr(6, 1));
}
bool pagalPavarde(const mok& a, const mok& b) {
    return stoi(a.pav.substr(7, 1)) < stoi(b.pav.substr(7, 1));
}
bool pagalMediana(const mok& a, const mok& b) {
    return a.gal_med < b.gal_med;
}
bool pagalVidurki(const mok& a, const mok& b) {
    return a.gal_vid < b.gal_vid;
}

milliseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia, high_resolution_clock::time_point pabaiga) {
    auto trukme = duration_cast<milliseconds>(pabaiga - pradzia);
    return trukme;
}

void failuGeneravimas(int studentuKiekis, const string& failoPavadinimas) {
    ofstream generate(failoPavadinimas);
    stringstream Stud;
    Stud << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(5) << "ND1" << left << setw(5) << "ND2" << left << setw(5) << "ND3" <<
        left << setw(5) << "ND4" << left << setw(5) << "ND5" << left << setw(5) << "ND6" << left << setw(5) << "ND7" << left << setw(5) << "ND8" << left << setw(5) << "ND9"
        << left << setw(5) << "ND10" << left << setw(5) << "Eg." << endl;

    for (int i = 0; i < studentuKiekis; ++i) {
        Stud << left << setw(6) << "Vardas" << left << setw(14) << i + 1 << left << setw(7) << "Pavarde" << left << setw(13) << i + 1;
        for (int j = 0; j < 10; j++) {
            int rand_paz = rand() % 10 + 1;
            Stud << left << setw(5) << rand_paz;
        }
        int rand_eg = rand() % 10 + 1;
        Stud << left << setw(5) << rand_eg << endl;
    }
    generate << Stud.str();
    generate.close();
    Stud.str("");
}

void konteineriai(int studentuKiekis, list<mok>& studentai, char a, list<mok>& kietiakai) {
    if (a == 'M' || a == 'm') {
        for (int i = 0; i < studentuKiekis; i++) {
            if (studentai.back().gal_med >= 5) {
                kietiakai.push_back(studentai.back());
                studentai.pop_back();
            }
        }
    }
    else {
        for (int i = 0; i < studentuKiekis; i++) {
            if (studentai.back().gal_vid >= 5) {
                kietiakai.push_back(studentai.back());
                studentai.pop_back();
            }
        }
    }
}

void isvalymas(list<mok>& vektorius) {
    for (auto i = vektorius.begin(); i != vektorius.end(); ++i) {
        i->nd.clear();
    }
    vektorius.clear();
}
void failuNuskaitymas(list<mok>& studentai, string& failoPavadinimas) {
    ifstream file;
    do {
        file.open(failoPavadinimas);
        if (!file) {
            cout << "Nepavyko atidaryti failo." << endl;
            cin >> failoPavadinimas;
        }
    } while (!file.is_open());

    int pazymys;
    int laikinas = 0;
    string line;
    istringstream iss;
    string grade = "";
    getline(file, line);
    while (getline(file, line)) {
        iss.str(line);
        mok laikinasstud;
        iss >> laikinasstud.var >> laikinasstud.pav;
        while (iss >> grade) {
            try {
                if (stoi(grade) >= 0 && stoi(grade) <= 10) {
                    laikinasstud.nd.push_back(std::stoi(grade));
                }
            }
            catch (std::exception& e) {

            }
        }
        laikinasstud.eg = laikinasstud.nd.back();
        laikinasstud.nd.pop_back();
        studentai.push_back(laikinasstud);
        iss.clear();

    }
    file.close();
}
int pirmasP(int& pirmasPasirinkimas) {
    cout << "Jei norite duomenis ivesti ranka, iveskite 1, jei norite, kad duomenys butu nuskaityti is failo, iveskite 2" << endl;
    cin >> pirmasPasirinkimas;
    while (!(pirmasPasirinkimas == 1 || pirmasPasirinkimas == 2)) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> pirmasPasirinkimas;
    }
    return pirmasPasirinkimas;
}

int treciasP(int& treciasPasirinkimas) {
    cout << "jei norite, kad duomenys butu isvesti ekrane, iveskite 1, jei i faila, iveskite 2" << endl;
    cin >> treciasPasirinkimas;
    while (!(treciasPasirinkimas == 1 || treciasPasirinkimas == 2)) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore();
        cin >> treciasPasirinkimas;
    }
    return treciasPasirinkimas;
}

void rikiavimas(int ketvirtasPasirinkimas, list<mok>& studentai) {
    switch (ketvirtasPasirinkimas) {//RIKIAVIMAS
    case 1:
    {
        studentai.sort(pagalVarda);
        break;
    }
    case 2:
    {
        studentai.sort(pagalPavarde);
        break;
    }
    case 3:
    {
        studentai.sort(pagalVidurki);
        break;
    }
    case 4:
    {
        studentai.sort(pagalMediana);
        break;
    }
    }
}
