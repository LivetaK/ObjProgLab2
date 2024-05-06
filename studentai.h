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
    mok() = default;

    ~mok() {
        nd.clear();
    }
    void isvalymas() {
        nd.clear();
        var.clear();
        pav.clear();
        eg = 0;
        gal_vid = 0;
        gal_med = 0;
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
