<h1><b><i>Objektinio programavimo užduotis</i></b></h1>

***

**V3.0**

#Užpildymo greitis

|             | std::vector |    Vector   |
| ----------- | ----------- | ----------- |
| 10 000      | 0 ms        | 0  ms       |
| 100 000     | 0 ms        | 0 ms        |
| 1 000 000   | 3 ms        | 3 ms        |
| 10 000 000  | 36 ms       | 28 ms       |
| 100 000 000 | 391 ms      | 340 ms      |

Atminties perskirstymį skaišius:

|             | std::vector |    Vector   |
| ----------- | ----------- | ----------- |
| 10 000      | 23          | 10          |
| 100 000     | 29          | 14          |
| 1 000 000   | 34          | 17          |
| 10 000 000  | 40          | 20          |
| 100 000 000 | 46          | 24          |




**V1.5**
Pridėta bazinė klasė "zmogus":
```cpp
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
```
Kadangi klasė yra abstrakti, naujas objektas tipo "zmogus", nėra leistinas:


![image](https://github.com/LivetaK/ObjProgLab2/assets/159531709/944fbe49-1fad-4fdc-a9e0-e218090f0647)


Šiai versijai taip pat pritaikyta penkių metodų taisyklė, funkcijos su zmogaus tipo kintamaisiais perkeltos į klasę "zmogus".

**V1.2 RULE OF FIVE**

Rule of five:

1. Destructor (Destruktorius) - išvalo atmintį, kad nebūtų duomenų nutekėjimo

```cpp
mok::~mok() {
    nd.clear();
}
```
2. Copy Constructor (Kopijabvimo konstruktorius) - leidžia saugiai kopijuoti visą objektą
```cpp
mok::mok(const mok& laikStud) {
    var = laikStud.var;
    pav = laikStud.pav;
    eg = laikStud.eg;
    gal_vid = laikStud.gal_vid;
    gal_med = laikStud.gal_med;
    nd = laikStud.nd;
}
```
3. Copy Assignment Operator (Kopijavimo priskyrimo operatorius) - leidžia jau sukurtam objektui priskirti reikšmes iš kito objekto
```cpp
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
```
4. Move Constructor (Perkėlimo konstruktorius) - leidžia perkelti duomenis iš vieno objekto į kitą
```cpp
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
```
5. Move Assignment Operator (Perkįlimo priskyrimo operatorius) - panašus į perkėlimo konstruktorių, bet naudojamas kai duomenys turi būti perkelti į jau egzistuojantį objektą
```cpp
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
```

Įvesties ir išvesties persidengimo metodai:

Jei rašome pvz.: cout << studentas; -  bus išvedami visi objekto "studentas" kintamieji

```cpp
ostream& operator<<(ostream& output, const mok& stud) {
    output << stud.getvar() << " " << stud.getpav() << " " << stud.geteg() << " ";
    vector<int> pazymiai = stud.getnd();
    for (int pazymys : pazymiai) {
        output << pazymys << " ";
    }
    return output;
}
```

Jei rašome pvz.: cin >> studentas; - vartotojas turės švesti visus kintamuosius, kurie turi būti objekte "studentas"

```cpp
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
```

**V1.1 TESTAVIMAS**


CLASS VS STRUCT


struct:


![Screenshot 2024-04-23 230651](https://github.com/LivetaK/ObjProgLab2/assets/159531709/590b1ae8-f7b9-4498-8e31-71df0c0c2c94)
![Screenshot 2024-04-23 230622](https://github.com/LivetaK/ObjProgLab2/assets/159531709/e5b8b8d3-b8f6-46a7-945d-4cdeea9eec32)




class:


![Screenshot 2024-04-23 222206](https://github.com/LivetaK/ObjProgLab2/assets/159531709/866d526c-87a0-45bc-8772-d7cad0ef8686)
![Screenshot 2024-04-23 222247](https://github.com/LivetaK/ObjProgLab2/assets/159531709/42503239-01ce-45dd-9233-9a89788fc126)



Kaip matome, programa su struktūra veikia greičiau.


OPTIMIZAVIMAS



![image](https://github.com/LivetaK/ObjProgLab2/assets/159531709/f09bb864-4a87-4638-a08e-c41322ce1def)

![image](https://github.com/LivetaK/ObjProgLab2/assets/159531709/b1a48bc4-1482-430a-9031-01a3f9f471d8)





KAIP VEIKIA PROGRAMA

Ši programa skaičiuoja studentų galutinį tam tikro kurso balą, naudodama studento pažymius ir egzaminų rezultatus. Programa realizuota su trimis skirtingais konteineriais: vector, deque, list; ir su trejomis skirtingomis strategijomis, todėl galima pasirinkti, kaip norima dirbti. Galima duomenis įvedinėti ranka, galima ir liepti programai juos skaityti iš failo. Štai taip veikia paleista programa:

1. Paleidus programą išvedamas klausimas, kaip norima, kad būtų nuskaityti duomenys - ar iš failo, ar įvesti ranka;
2. Jei pasirenkame duomenis įrašyti ranka, išvedamas pasirinkimo meniu: ar įvedinėjame ranka, ar leidžiame programai sugeneruoti pažymius automatiškai, ar norime kad tiek studentų vardai, tiek jų pažymiai būtų generuojami auromatiškai;
3. Jei pasirinkame, kad duomenys būtų skaitomi iš failo svarbu, kad failas būtų įkeltas į tą patį aplanką kartu su programa;
4. Vedant vis naujus duomenis, programa paklaus jai rūpimų klausimų, kurie būtini galutinio balo skaičiavimui;
5. Jei buvo pasirinkta duomenis skaityti iš failo, reiks pasirinkti, ir kur juos išvesti - ar į ekraną, ar į naujai sugeneruotą failą.

PASIRUOŠIMAS

Prieš naudojant programą, reikia atsisiųsti Visual Studio: https://visualstudio.microsoft.com/downloads/ paspaudę "download" būsite nunaviguoti į puslapį, kuriame bus paaiškinta, kaip dirbti su Visual Studio.

Taip pat reikia atsisiųsti CMake, kuris jums paruoš .exe failus, kad galėtumėte iš karto naudoti programą: https://cmake.org/download/ . Atsisiuntę nueikite į komandinę eilute, nunaviguokite į aplanką, kuriame yra šis projektas (naudokite komandą cd ir įrašykište kelią). Tada įveskite 
```cpp
cmake -G "Visual Studio 17 2022" -A x64 .
```
Ir:
```cpp
cmake --build . --config Release
```


**V1.0 TESTAVIMAS**

---------------------------------------------------------
Testavimo sistemos parametrai:
![Screenshot 2024-03-22 200611](https://github.com/LivetaK/ObjProgLab/assets/159531709/d4f0758b-1db6-4713-8b33-70aa780d6a02)


*********************************************************

PIRMA TESTAVIMO DALIS 

*********************************************************


Rezultatu apibendrinimas ir palyginimas:


![Screenshot 2024-03-23 111932](https://github.com/LivetaK/ObjProgLab/assets/159531709/40d9c592-d1a6-4c26-96ed-116df5bf7ade)


*********************************************************

ANTRA TESTAVIMO DALIS 

*********************************************************


1 STRATEGIJA:



![Screenshot 2024-03-27 151250](https://github.com/LivetaK/ObjProgLab/assets/159531709/291e1fbc-3b37-4c3c-8a3f-09bf16624409)



2 STRATEGIJA



![Screenshot 2024-04-04 201653](https://github.com/LivetaK/ObjProgLab/assets/159531709/229c624b-f8bc-422f-85d5-b3973b72e758)



3 STRATEGIJA


![image](https://github.com/LivetaK/ObjProgLab2/assets/159531709/cb0bd288-d050-4310-8cfb-afb80b59731f)


