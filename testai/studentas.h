#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class zmogus {
protected:
    string var = " ", pav = " ";
public:
    virtual void setvar(const string& vardas) = 0;
    virtual string getvar() const = 0;
    virtual void setpav(const string& pavarde) = 0;
    virtual string getpav() const = 0;

    zmogus() = default;
    virtual ~zmogus() {};

    zmogus(const zmogus& laikStud);  // Copy constructor
    zmogus(zmogus&& laikStud) noexcept;  // Move constructor
    zmogus& operator=(const zmogus& laikStud);  // Copy assignment operator
    zmogus& operator=(zmogus&& laikStud) noexcept;  // Move assignment operator
};


class mok : public zmogus {
private:
    int eg = 0;
    vector<int> nd = { 0 };
    double gal_vid = 0.0, gal_med = 0.0;
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

    mok() = default;                              // Constructor
    ~mok();                                       // Destructor
    mok(const mok& laikStud);                     // Copy Constructor
    mok& operator=(const mok& laikStud);          // Copy Assignment Operator
    mok(mok&& laikStud) noexcept;                 // Move Constructor
    mok& operator=(mok&& laikStud) noexcept;      // Move Assignment Operator

    friend ostream& operator<< (ostream& output, const mok& stud);

    friend istream& operator>>(istream& input, mok& stud);

};

#endif 