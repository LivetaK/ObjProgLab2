/**
* @file funkcijos.h
* @brief siame faile aprasytos kode naudojamos funkcijos
*/

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <cassert>
#include "Vector.hpp"

using namespace std;
using namespace std::chrono;

/**
 * @brief Ivedimo funkcija.
 * @details Si funkcija naudojama tik pasirinkus ivedima ranka.
 * @param stud Studentu vektorius.
 */
void ivedimas(Vector<mok>& stud);

/**
 * @brief Rezultatu skaiciavimo funkcija.
 * @param stud Studentu vektorius.
 */
void calculateResults(Vector<mok>& stud);

/**
 * @brief Rikiavimo klausimas.
 * @return Simbolis, nurodantis pagal ka bus rikiuojami duomenys.
 */
char rikiavimoklausimas();

/**
 * @brief Isvedimo funkcija.
 * @details Si funkcija naudojama ir isvedimui i faila, ir i ekrana.
 * @param stud Studentu vektorius.
 * @param os Ivesties srautas.
 * @param a Rikiavimo tipa nurodantis simbolis.
 */
void isvedimas(Vector<mok>& stud, ostream& os, char a);

/**
 * @brief Pirmas meniu.
 * @details Sis meniu atsiranda tada, kada naudotojas pasirenka duomenis ivedineti ranka.
 * @param antrasPasirinkimas Naudotojo pasirinkimas.
 */
void meniu(int& antrasPasirinkimas);

/**
 * @brief Antras meniu.
 * @details Naudotojas renkasi, pagal ka isrikiuotus duomenis nori matyti.
 * @param ketvirtasPasirinkimas Naudotojo pasirinkimas.
 */
void meniuAntras(int& ketvirtasPasirinkimas);

/**
 * @brief Rikiavimo funkcija pagal varda.
 * @param a Pirmas mok objektas.
 * @param b Antras mok objektas.
 * @return Tiesa, jei pirmas vardas yra zemiau uz antra.
 */
bool pagalVarda(const mok& a, const mok& b);

/**
 * @brief Rikiavimo funkcija pagal pavarde.
 * @param a Pirmas mok objektas.
 * @param b Antras mok objektas.
 * @return Tiesa, jei pirma pavarde yra zemiau uz antra.
 */
bool pagalPavarde(const mok& a, const mok& b);

/**
 * @brief Rikiavimo funkcija pagal mediana.
 * @param a Pirmas mok objektas.
 * @param b Antras mok objektas.
 * @return Tiesa, jei pirma mediana yra mazesne uz antra.
 */
bool pagalMediana(const mok& a, const mok& b);

/**
 * @brief Rikiavimo funkcija pagal vidurki.
 * @param a Pirmas mok objektas.
 * @param b Antras mok objektas.
 * @return Tiesa, jei pirmas vidurkis yra mazesnis uz antra.
 */
bool pagalVidurki(const mok& a, const mok& b);

/**
 * @brief Trukmes skaiciavimo funkcija.
 * @param pradzia Pradzios laikas.
 * @param pabaiga Pabaigos laikas.
 * @return Trukmes intervalas milisekundemis.
 */
milliseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia, high_resolution_clock::time_point pabaiga);

/**
 * @brief Failu generavimo funkcija.
 * @param studentuKiekis Studentu Kiekis.
 * @param failoPavadinimas Failo pavadinimas.
 */
void failuGeneravimas(int studentuKiekis, const string& failoPavadinimas);

/**
 * @brief Skirstymo i konteinerius funkcija.
 * @param studentuKiekis Studentu kiekis.
 * @param studentai Studentu vektorius.
 * @param a Rikiavimo tipa nurodantis simbolis.
 * @param vargsiukai Vargsiuku vektorius.
 */
void konteineriai(int studentuKiekis, Vector<mok>& studentai, char a, Vector<mok>& vargsiukai);

/**
 * @brief Vektoriaus isvalymo funkcija.
 * @param vektorius Vektorius, kuri reikia isvalyti.
 */
void isvalymas(Vector<mok>& vektorius);

/**
 * @brief Failu nuskaitymo funkcija.
 * @param studentai Studentu vektorius.
 * @param failoPavadinimas Failo pavadinimas.
 */
void failuNuskaitymas(Vector<mok>& studentai, string& failoPavadinimas);

/**
 * @brief Klausimas naudotojui.
 * @details Funkcija, kuri klausia naudotojo ar jis nori duomenis ivesti ranka, ar nuskaityti is failo.
 * @param pirmasPasirinkimas Naudotojo pasirinkimas.
 * @return Naudotojo pasirinkimas.
 */
int pirmasP(int& pirmasPasirinkimas);

/**
 * @brief Klausimas naudotojui.
 * @details Funkcija, kuri klausia naudotojo ar jis nori, kad duomenys butu isvesti ekrane, ar i faila.
 * @param treciasPasirinkimas Naudotojo pasirinkimas.
 * @return Naudotojo pasirinkimas.
 */
int treciasP(int& treciasPasirinkimas);

/**
 * @brief Rikiavimo funkcija.
 * @param ketvirtaspasirinkimas Ketvirtas pasirinkimas.
 * @param studentai Studentu vektorius.
 */
void rikiavimas(const int ketvirtaspasirinkimas, Vector<mok>& studentai);

/**
 * @brief Testavimo rezultatu funkcija.
 * @param result Testo rezultatas.
 * @param testas Testo pavadinimas.
 */
void testavimoRezultatai(bool result, const string& testas);

#endif
