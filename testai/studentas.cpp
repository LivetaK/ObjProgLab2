#include "studentas.h"

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

//RULE OF FIVE ZMOGUS

//copy con
zmogus::zmogus(const zmogus& laikStud)
    : var(laikStud.var),
    pav(laikStud.pav) {};


//copy assignment op
zmogus& zmogus::operator=(const zmogus& laikStud) {
    if (this != &laikStud) {
        var = laikStud.var;
        pav = laikStud.pav;
    }
    return *this;
}
//move con


zmogus::zmogus(zmogus&& laikStud) noexcept
    : var(move(laikStud.var)),
    pav(move(laikStud.pav)) {};


//move assignment op
zmogus& zmogus::operator=(zmogus&& laikStud) noexcept {
    if (this != &laikStud) {
        var = move(laikStud.var);
        pav = move(laikStud.pav);
    }
    return *this;
}

// RULE OF FIVE:

// Destructor
mok::~mok() {
    nd.clear();
}

// Copy Constructor
mok::mok(const mok& laikStud)
    : zmogus(laikStud)
{
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
        zmogus::operator=(laikStud);
        eg = laikStud.eg;
        gal_vid = laikStud.gal_vid;
        gal_med = laikStud.gal_med;
        nd = laikStud.nd;
    }
    return *this;
}

// Move Constructor
mok::mok(mok&& laikStud) noexcept
    : zmogus(move(laikStud)),
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
        zmogus::operator=(move(laikStud));
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