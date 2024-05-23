/**
* @file studentas.h
* @brief siame faile aprasytos studento ir zmogaus klases
*/


#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 * @class zmogus
 * @brief Abstrakti klase, sukurta aprasyti zmogu.
 */

class zmogus {
protected:
    string var = " "; ///< Zmogaus vardas
    string pav = " "; ///< Zmogaus pavarde
public:
    /**
     * @brief Nustato varda.
     * @param vardas Vardas.
     */
    virtual void setvar(const string& vardas) = 0;

    /**
    * @brief Grazina varda.
    * @return Vardas.
    */
    virtual string getvar() const = 0;

    /**
     * @brief Nustato pavarde.
     * @param pavarde Pavarde.
     */
    virtual void setpav(const string& pavarde) = 0;

    /**
     * @brief Grazina pavarde.
     * @return Pavarde.
     */
    virtual string getpav() const = 0;

    /**
    * @brief Numatytasis konstruktorius.
    */
    zmogus() = default;

    /**
     * @brief Destruktorius.
     */
    virtual ~zmogus() {};

    /**
     * @brief Kopijavimo konstruktorius.
     * @param laikStud Objektas, is kurio kopijuojama.
     */
    zmogus(const zmogus& laikStud);  // Copy constructor

    /**
     * @brief Perkelimo konstruktorius.
     * @param laikStud Objektas, is kurio perkeliama.
     */
    zmogus(zmogus&& laikStud) noexcept;  // Move constructor

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param laikStud Objektas, is kurio kopijuojama.
     * @return Priskirtas objektas.
     */
    zmogus& operator=(const zmogus& laikStud);  // Copy assignment operator

    /**
     * @brief Perkelimo priskyrimo operatorius.
     * @param laikStud Objektas, is kurio perkeliama.
     * @return Priskirtas objektas.
     */
    zmogus& operator=(zmogus&& laikStud) noexcept;  // Move assignment operator
};

/**
 * @class mok
 * @brief Isvestine klase, aprasanti studenta.
 */
class mok : public zmogus {
private:
    int eg = 0; ///< Egzamino balas
    vector<int> nd = { 0 }; ///< Namu darbu pazymiai
    double gal_vid = 0.0; ///< Galutinis balas, apskaiciuotas naudojant vidurki
    double gal_med = 0.0; /// < Galutinis balas, apskaiciuotas naudojant mediana
public:
    /**
     * @brief Nustato varda.
     * @param vardas Vardas.
     */
    void setvar(const string& vardas);

    /**
     * @brief Grazina varda.
     * @return Vardas.
     */
    string getvar() const;

    /**
     * @brief Nustato pavarde.
     * @param pavarde Pavarde.
     */
    void setpav(const string& pavarde);

    /**
     * @brief Grazina pavarde.
     * @return Pavarde.
     */
    string getpav() const;

    /**
     * @brief Nustato egzamino bala.
     * @param egzaminas Egzamino balas.
     */
    void seteg(int egzaminas);

    /**
     * @brief Grazina egzamino bala.
     * @return Egzamino balas.
     */
    int geteg()const;

    /**
     * @brief Nustato galutini bala, apskaiciuota naudojant vidurki.
     * @param Gal_vid Galutinis balas, apskaiciuotas naudojant vidurki.
     */
    void setgal_vid(double Gal_vid);

    /**
     * @brief Grazina galutini bala, apskaiciuota naudojant vidurki.
     * @return Galutinis balas, apskaiciuotas maudojant vidurki.
     */
    double getgal_vid() const;

    /**
     * @brief Nustato galutini bala, apskaiciuota naudojant mediana.
     * @param Gal_vid Galutinis balas, apskaiciuotas naudojant mediana.
     */
    void setgal_med(double Gal_med);

    /**
     * @brief Grazina galutini bala, apskaiciuota naudojant mediana.
     * @return Galutinis balas, apskaiciuotas maudojant mediana.
     */
    double getgal_med() const;

    /**
     * @brief Nustato namu darbu pazymius.
     * @param ND Namu darbu pazymiai.
     */
    void setnd(const vector<int>& ND);

    /**
     * @brief Grazina namu darbu pazymius.
     * @return Namu darbu pazymiai.
     */
    vector<int> getnd() const;

    /**
    * @brief Isvalo objekto duomenis.
    */
    void isvalymas();
    // RULE OF FIVE:

    /**
    * @brief Numatytasis konstruktorius.
    */
    mok() = default;

    /**
     * @brief Destruktorius.
     */
    ~mok();

    /**
     * @brief Kopijavimo konstruktorius.
     * @param laikStud Objektas, is kurio kopijuojama.
     */
    mok(const mok& laikStud);

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param laikStud Objektas, is kurio kopijuojama.
     * @return Priskirtas objektas.
     */
    mok& operator=(const mok& laikStud);

    /**
     * @brief Perkelimo konstruktorius.
     * @param laikStud Objektas, is kurio perkeliama.
     */
    mok(mok&& laikStud) noexcept;

    /**
     * @brief Perkelimo priskyrimo operatorius.
     * @param laikStud Objektas, is kurio perkeliama.
     * @return Priskirtas objektas.
     */
    mok& operator=(mok&& laikStud) noexcept;

    /**
     * @brief Operatorius srauto isvedimui.
     * @param output Srautas.
     * @param stud Studentas.
     * @return Srauto objektas.
     */
    friend ostream& operator<< (ostream& output, const mok& stud);

    /**
     * @brief Operatorius srauto ivedimui.
     * @param input Srautas.
     * @param stud Studentas.
     * @return Srauto objektas.
     */
    friend istream& operator>>(istream& input, mok& stud);

};

#endif 
