#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

class mok {
private:
    vector<int> nd = {0};
    string var = " ", pav = " ";
    int eg = 0;
    double gal_vid = 0.0 , gal_med = 0.0;
public:
    void setvar(string& vardas) {
        var = vardas;
    }
    string getvar() const {
        return var;
    }
    void setpav(string& pavarde) {
        pav = pavarde;
    }
    string getpav() const {
        return pav;
    }
    void seteg(int egzaminas) {
        eg = egzaminas;
    }
    int geteg()const {
        return eg;
    }
    void setgal_vid(double Gal_vid) {
        gal_vid = Gal_vid;
    }
    double getgal_vid() const {
        return gal_vid;
    }
    void setgal_med(double Gal_med) {
        gal_med = Gal_med;
    }
    double getgal_med() const {
        return gal_med;
    }
    void setviennd(int naujasnd) {
        nd.push_back(naujasnd);
    }
    int getviennd(const vector<int>& ND, int i)const {
        return ND[i];
    }
    void setnd(const vector<int>& ND) {
        nd = ND;
    }
    vector<int> getnd() const{
        return nd;
    }
    void isvalymas() {
        nd.clear();
        var.clear();
        pav.clear();
        eg = 0;
        gal_vid = 0;
        gal_med = 0;
    }
    // RULE OF FIVE:

    mok() = default;

    // Destructor
    ~mok() {
        nd.clear();
    }

    // Copy Constructor
    mok(const mok& laikStud) {
        var = laikStud.var;
        pav = laikStud.pav;
        eg = laikStud.eg;
        gal_vid = laikStud.gal_vid;
        gal_med = laikStud.gal_med;
        nd = laikStud.nd;
    }

    // Copy Assignment Operator
    mok& operator=(const mok& laikStud) {
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
    mok(mok&& laikStud) noexcept {
        var = move(laikStud.var);
        pav = move(laikStud.pav);
        eg = laikStud.eg;
        gal_vid = laikStud.gal_vid;
        gal_med = laikStud.gal_med;
        nd = move(laikStud.nd);
        // Reset the moved object
        laikStud.eg = 0;
        laikStud.gal_vid = 0.0;
        laikStud.gal_med = 0.0;
    }

    // Move Assignment Operator
    mok& operator=(mok&& laikStud) noexcept {
        if (this != &laikStud) {
            var = move(laikStud.var);
            pav = move(laikStud.pav);
            eg = laikStud.eg;
            gal_vid = laikStud.gal_vid;
            gal_med = laikStud.gal_med;
            nd = move(laikStud.nd);
            // Reset the moved object
            laikStud.eg = 0;
            laikStud.gal_vid = 0.0;
            laikStud.gal_med = 0.0;
        }
        return *this;
    }

};

void ivedimas(vector<mok>& stud);
void calculateResults(vector<mok>& stud);
char rikiavimoklausimas();
void isvedimas(vector<mok>& stud, ostream& os, char a);
void meniu(int& antrasPasirinkimas);
void meniuAntras(int& ketvirtasPasirinkimas);
bool pagalVarda(const mok& a, const mok& b);
bool pagalPavarde(const mok& a, const mok& b);
bool pagalMediana(const mok& a, const mok& b);
bool pagalVidurki(const mok& a, const mok& b);
milliseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia, high_resolution_clock::time_point pabaiga);
void failuGeneravimas(int studentuKiekis, const string& failoPavadinimas);
void konteineriai(int studentuKiekis, vector<mok>& studentai, char a, vector<mok>& vargsiukai);
void isvalymas(vector<mok>& vektorius);
void failuNuskaitymas(vector<mok>& studentai, string& failoPavadinimas);
int pirmasP(int& pirmasPasirinkimas);
int treciasP(int& treciasPasirinkimas);
void rikiavimas(const int ketvirtaspasirinkimas, vector<mok>& studentai);
