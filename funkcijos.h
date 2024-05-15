#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

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

#endif