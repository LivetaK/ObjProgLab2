#include "studentai.h"

// klase
void mok::setvar(const string& vardas) {
    var = vardas;
}
string mok::getvar() const {
    return var;
}
void mok::setpav(const string& pavarde) {
    pav = pavarde;
}
string mok::getpav() const {
    return pav;
}
void mok::seteg(int egzaminas) {
    eg = egzaminas;
}
int mok::geteg()const {
    return eg;
}
void mok::setgal_vid(double Gal_vid) {
    gal_vid = Gal_vid;
}
double mok::getgal_vid() const {
    return gal_vid;
}
void mok::setgal_med(double Gal_med) {
    gal_med = Gal_med;
}
double mok::getgal_med() const {
    return gal_med;
}
void mok::setnd(const vector<int>& ND) {
    nd = ND;
}
vector<int> mok::getnd() const {
    return nd;
}
void mok::isvalymas() {
    nd.clear();
    var.clear();
    pav.clear();
    eg = 0;
    gal_vid = 0;
    gal_med = 0;
}
// RULE OF FIVE:

// Destructor
mok::~mok() {
    nd.clear();
}

// Copy Constructor
mok::mok(const mok& laikStud) {
    var = laikStud.var;
    pav = laikStud.pav;
    eg = laikStud.eg;
    gal_vid = laikStud.gal_vid;
    gal_med = laikStud.gal_med;
    nd = laikStud.nd;
}

// Copy Assignment Operator
mok& mok::operator=(const mok& laikStud) {
    if (this != &laikStud) {
        var = laikStud.var;
        pav = laikStud.pav;
        eg = laikStud.eg;
        gal_vid = laikStud.gal_vid;
        gal_med = laikStud.gal_med;
        nd = laikStud.nd;
    }
    return *this;
}

// Move Constructor
mok::mok(mok&& laikStud) noexcept
:   var(move(laikStud.var)),
    pav(move(laikStud.pav)),
    eg(laikStud.eg),           
    gal_vid(laikStud.gal_vid),
    gal_med(laikStud.gal_med),
    nd(move(laikStud.nd))
{
    laikStud.eg = 0;
    laikStud.gal_vid = 0.0;
    laikStud.gal_med = 0.0;
}


// Move Assignment Operator
mok& mok::operator=(mok&& laikStud) noexcept {
    if (this != &laikStud) {
        var = move(laikStud.var);
        pav = move(laikStud.pav);
        eg = laikStud.eg;
        gal_vid = laikStud.gal_vid;
        gal_med = laikStud.gal_med;
        nd = move(laikStud.nd);

        laikStud.eg = 0;
        laikStud.gal_vid = 0.0;
        laikStud.gal_med = 0.0;
    }
    return *this;
}

ostream& operator<<(ostream& output, const mok& stud) {
    output << stud.getvar() << " " << stud.getpav() << " " << stud.geteg() << " ";
    vector<int> pazymiai = stud.getnd();
    for (int pazymys : pazymiai) {
        output << pazymys << " ";
    }
    return output;
}

istream& operator>>(istream& input, mok& stud) {
    string vardas, pavarde;
    int pazymys, egzaminas;
    vector<int> namuD;
    input >> vardas >> pavarde >> egzaminas;
    stud.setvar(vardas);
    stud.setpav(pavarde);
    stud.seteg(egzaminas);
    stud.getnd().clear(); 
    while (input >> pazymys) {
        namuD.push_back(pazymys);
    }
    stud.setnd(namuD);
    return input;
}
//klases pabaiga


void ivedimas(vector<mok>& stud) {
    mok naujas_stud;
    cout << "Iveskite studento varda ir pavarde:" << endl;
    string vardas, pavarde;
    cin >> vardas >> pavarde;
    naujas_stud.setvar(vardas);
    naujas_stud.setpav(pavarde);
    vector<int> pazymiai;
    int pazymys, egzaminas;

    cout << "Iveskite studento tarpinius namu darbu rezultatus(noredami uzbaigti, iveskite neigiama skaiciu):" << endl;
    while (cin >> pazymys) {
        if (pazymys > 10 || pazymys == 0) {
            cin.clear();
            cin.ignore();
            cout << "Netinkamas formatas, bandykite dar karta" << endl;
            continue;
        }

        if (pazymys < 0) {
            break;
        }
        pazymiai.push_back(pazymys);
    }
    try {
        if (pazymiai.empty()) {
            throw runtime_error("Neivestas nei vienas pazymys.");
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        exit(1);
    }
    naujas_stud.setnd(pazymiai);

    cout << "Iveskite studento egzamino rezultata:" << endl;
    while (!(cin >> egzaminas) || egzaminas < 1 || egzaminas > 10) {
        cout << "Netinkamas formatas, bandykite dar karta" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    naujas_stud.seteg(egzaminas);

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

void calculateResults(vector<mok>& stud) {

    for (int i = 0; i < stud.size(); i++) {
        vector<int> pazymiai = stud[i].getnd();
        double sum = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
        double vid = sum / pazymiai.size();
        stud[i].setgal_vid(0.4 * vid + 0.6 * stud[i].geteg());
        sort(pazymiai.begin(), pazymiai.end());
        if (pazymiai.size() % 2 == 0) {
            stud[i].setgal_med((pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2.0 * 0.4 + 0.6 * stud[i].geteg());
        }
        else {
            stud[i].setgal_med(pazymiai[pazymiai.size() / 2] * 0.4 + 0.6 * stud[i].geteg());
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
void isvedimas(vector<mok>& stud, ostream& os, char a) {

    if (a == 'V' || a == 'v') {
        os << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
        os << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < stud.size(); i++) {
            os << left << setw(20) << stud[i].getvar() << setw(20) << stud[i].getpav() << setw(20) << fixed << setprecision(2) << stud[i].getgal_vid() << endl;
        }
    } if (a == 'M' || a == 'm') {
        os << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
        os << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < stud.size(); i++) {
            os << left << setw(20) << stud[i].getvar() << setw(20) << stud[i].getpav() << setw(20) << fixed << setprecision(2) << stud[i].getgal_med() << endl;
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
    return stoi(a.getvar().substr(6, 1)) < stoi(b.getvar().substr(6, 1));
}
bool pagalPavarde(const mok& a, const mok& b) {
    return stoi(a.getpav().substr(7, 1)) < stoi(b.getpav().substr(7, 1));
}
bool pagalMediana(const mok& a, const mok& b) {
    return a.getgal_med() < b.getgal_med();
}
bool pagalVidurki(const mok& a, const mok& b) {
    return a.getgal_vid() < b.getgal_vid();
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

    for (int i = 0; i < studentuKiekis; i++) {
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

void konteineriai(int studentuKiekis, vector<mok>& studentai, char a, vector<mok>& vargsiukai) {
    if (a == 'M' || a == 'm') {
        auto partitionIt = partition(studentai.begin(), studentai.end(),
            [](const mok& student) {
                return student.getgal_med() < 5;
            });

        vargsiukai.insert(vargsiukai.end(), studentai.begin(), partitionIt);
        studentai.erase(studentai.begin(), partitionIt);
    }
    else {
        auto partitionIt = partition(studentai.begin(), studentai.end(),
            [](const mok& student) {
                return student.getgal_vid() < 5;
            });

        vargsiukai.insert(vargsiukai.end(), studentai.begin(), partitionIt);
        studentai.erase(studentai.begin(), partitionIt);
    }

}

void isvalymas(vector<mok>& vektorius) {
    for (int i = 0; i < vektorius.size(); i++) {
        vektorius[i].isvalymas();
    }
    vektorius.clear();
}

void failuNuskaitymas(vector<mok>& studentai, string& failoPavadinimas) {
    string vardas, pavarde;
    int pazymys, egzaminas;
    vector<int> pazymiai;

    ifstream file;
    do {
        file.open(failoPavadinimas);
        if (!file) {
            cout << "Nepavyko atidaryti failo. Galut suklydote, vesdami pavadinima?! Bandykite dar karta" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin >> failoPavadinimas;
        }
    } while (!file.is_open());


    int laikinas = 0;
    string line;
    istringstream iss;
    getline(file, line);
    while (getline(file, line)) {
        iss.str(line);
        mok laikinasstud;
        iss >> vardas >> pavarde;
        laikinasstud.setvar(vardas);
        laikinasstud.setpav(pavarde);
        while (iss >> pazymys) {
            try {
                if (pazymys >= 0 && pazymys <= 10) {
                    pazymiai.push_back(pazymys);
                    laikinasstud.setnd(pazymiai);
                }
            }
            catch (std::exception& e) {

            }
        }
        egzaminas = laikinasstud.getnd().back();
        laikinasstud.seteg(egzaminas);
        laikinasstud.getnd().pop_back();
        studentai.push_back(laikinasstud);
        pazymiai.clear();
        iss.clear();

    }
    file.close();
}
int pirmasP(int& pirmasPasirinkimas) {
    cout << "Jei norite duomenis ivesti ranka, iveskite 1, jei norite, kad duomenys butu nuskaityti is failo, iveskite 2, jei norite testuoti, iveskite 3" << endl;
    cin >> pirmasPasirinkimas;
    while (!(pirmasPasirinkimas == 1 || pirmasPasirinkimas == 2 || pirmasPasirinkimas == 3)) {
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

void rikiavimas(int ketvirtasPasirinkimas, vector<mok>& studentai) {
    switch (ketvirtasPasirinkimas) {//RIKIAVIMAS
    case 1:
    {
        sort(studentai.begin(), studentai.end(), pagalVarda);
        break;
    }
    case 2:
    {
        sort(studentai.begin(), studentai.end(), pagalPavarde);
        break;
    }
    case 3:
    {
        sort(studentai.begin(), studentai.end(), pagalVidurki);
        break;
    }
    case 4:
    {
        sort(studentai.begin(), studentai.end(), pagalMediana);
        break;
    }
    }
}
void testavimoRezultatai(bool result, const string& testas) {
    cout << testas << ": " << (result ? "PASS" : "FAIL") << endl;
}
