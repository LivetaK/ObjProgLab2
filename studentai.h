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
#include <cassert>

using namespace std;
using namespace std::chrono;

class mok {
private:
    string var = " ", pav = " ";
    int eg = 0;
    vector<int> nd = { 0 };
    double gal_vid = 0.0 , gal_med = 0.0;
public:
    void setvar(const string& vardas);
    string getvar() const;
    void setpav(const string& pavarde);
    string getpav() const;
    void seteg(int egzaminas);
    int geteg()const;
    void setgal_vid(double Gal_vid);
    double getgal_vid() const;
    void setgal_med(double Gal_med);
    double getgal_med() const;
    void setnd(const vector<int>& ND);
    vector<int> getnd() const;
  
    void isvalymas();
    // RULE OF FIVE:
    // Constructor
    mok() = default;

    // Destructor
    ~mok();

    // Copy Constructor
    mok(const mok& laikStud);

    // Copy Assignment Operator
    mok& operator=(const mok& laikStud);

    // Move Constructor
    mok(mok&& laikStud) noexcept;

    // Move Assignment Operator
    mok& operator=(mok&& laikStud) noexcept;

    friend ostream& operator<< (ostream& output, const mok& stud);

    friend istream& operator>>(istream& input, mok& stud);

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
void testavimoRezultatai(bool result, const string& testas);
