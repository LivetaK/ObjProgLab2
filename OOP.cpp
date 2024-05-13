#include "studentai.h"

int main() {
    int pirmasPasirinkimas, antrasPasirinkimas, treciasPasirinkimas, ketvirtasPasirinkimas, n;
    string vardas, pavarde;
    int pazymys, egzaminas;
    vector<int> pazymiai;
    vector<mok> studentai;

    string vardai[] = { "Liveta", "Roberta", "Paulina", "Ugne", "Gabriele", "Kamile", "Marija", "Rugile", "Jovita", "Adriana" };
    string pavardes[] = { "Kavaliauskaite", "Jurpalyte", "Podgaiska", "Mockute", "Vaitiekute", "Zobelaite", "Zubareva", "Macaite", "Vencauskaite", "Sirokyte" };

    srand(time(NULL));

    pirmasP(pirmasPasirinkimas);    //PASIRINKIMAS, AR DUOMENYS IVEDAMI RANKA, AR NUSKAITOMI IS FAILO

    if (pirmasPasirinkimas == 1) {    //JEI NORIMA DUOMENIS IVESTI RANKA

        do {
            meniu(antrasPasirinkimas);
            switch (antrasPasirinkimas) {
            case 1: { //NEZINOMAS KIEKIS STUDENTU IR PAZYMIU
                cout << "Noredami ivesti naujo studento duomenis, iveskite bet kokia raide. Noredami uzbaigti iveskite 'stop'" << endl;
                string a;
                while (cin >> a && a != "stop") {
                    ivedimas(studentai);
                }
                cout << "baige";
                calculateResults(studentai);
                isvedimas(studentai, cout, rikiavimoklausimas());
                break;
            }
            case 2: { //GENERUOJAMI PAZYMIAI
                cout << "Iveskite studentu kieki: " << endl;
                while (!(cin >> n) || n < 1) {
                    cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                };
                mok naujasStud;
                for (int i = 0; i < n; i++) {
                    cout << "Iveskite studento varda ir pavarde: " << endl;
                    cin >> vardas >> pavarde;
                    naujasStud.setvar(vardas);
                    naujasStud.setpav(pavarde);
                    int pazymiukiekis;
                    cout << "Kiek pazymiu norite, kad programa sugeneruotu?: " << endl;
                    while (!(cin >> pazymiukiekis) || pazymiukiekis < 1) {
                        cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    };
                    int sum = 0;
                    for (int j = 0; j < pazymiukiekis; j++) {
                        int rand_paz = rand() % 10 + 1;
                        pazymiai.push_back(rand_paz);
                        sum += rand_paz;
                    }
                    naujasStud.setnd(pazymiai);
                    naujasStud.seteg(rand() % 10 + 1);
                    studentai.push_back(naujasStud);
                }
                calculateResults(studentai);
                isvedimas(studentai, cout, rikiavimoklausimas());
                break;
            }
            case 3: { //GENERUOJAMI IR VARDAI IR PAZYMIAI
                cout << "Iveskite studentu kieki:" << endl;
                while (!(cin >> n) || n < 1) {
                    cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                };
                cout << "Kiek pazymiu norite, kad programa sugeneruotu kiekvienam studentui?" << endl;
                int pazymiukiekis;
                while (!(cin >> pazymiukiekis) || pazymiukiekis < 1) {
                    cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                };
                mok naujasStud;
                for (int i = 0; i < n; i++) {
                    naujasStud.setvar(vardai[rand() % (sizeof(vardai) / sizeof(vardai[0]))]);
                    naujasStud.setpav(pavardes[rand() % (sizeof(pavardes) / sizeof(pavardes[0]))]);
                    double sum = 0;
                    for (int j = 0; j < pazymiukiekis; j++) {
                        int rand_paz = rand() % 10 + 1;
                        pazymiai.push_back(rand_paz);
                        naujasStud.setnd(pazymiai);
                        sum += rand_paz;
                    }
                    naujasStud.seteg(rand() % 10 + 1);
                    studentai.push_back(naujasStud);
                }
                calculateResults(studentai);
                isvedimas(studentai, cout, rikiavimoklausimas());
                break;
            }
            case 4: { //PROGRAMA BAIGTA
                cout << "Programa baigta." << endl;
                break;
            }
            default: {
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
            }
            }
        } while (antrasPasirinkimas != 4);
        //TRINAMI VEKTORIAI
        isvalymas(studentai);
    }
    else { //NORIMA DUOMENIS SKAITYTI IS FAILO

        // FAILU GENERAVIMAS
        /*cout << "Kiek studentu norite, kad programa sugeneruotu?" << endl;
        int studentuKiekis;
        while (!(cin >> studentuKiekis) || studentuKiekis < 0) {
            cout << "Neteisinga ivestis, bandykite dar karta" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        string failoPavadinimas = "studentai" + to_string(studentuKiekis) + ".txt";
        auto failoGeneravimoPradzia = high_resolution_clock::now();
        failuGeneravimas(studentuKiekis, failoPavadinimas);
        auto failoGeneravimoPabaiga = high_resolution_clock::now();
        cout << "--------------------------------------------------------" << endl;
        cout << "failas sugeneruotas" << endl;
        cout << "--------------------------------------------------------" << endl;*/

        // FAILAS JAU EGZISTUOJA (TYRIMUI)

       // FAILAS JAU EGZISTUOJA (TYRIMUI)

        /*int studentuKiekis = 1000000;
        string failoPavadinimas = "studentai" + to_string(studentuKiekis) + ".txt";*/
        
        // NAUDOTOJAS ĮVEDA FAILO PAVADINIMA
        
        cout << "Kiek studentu reikes apdoroti programai?" << endl;
        int studentuKiekis;
        while (!(cin >> studentuKiekis) || studentuKiekis < 1) {
            cout << "Neteisinga ivestis. Bandykite dar karta" << endl;
        };
        cout << "Iveskite failo pavadinima" << endl;
        int failoPav;
        cin >> failoPav;
        string failoPavadinimas = failoPav + ".txt";
        
        //NUSKAITYMAS IS FAILO BAIGTAS

        //SKAICIUOJAMI REZULTATAI
        auto skaicPradzia = high_resolution_clock::now();
        calculateResults(studentai);
        auto skaicPabaiga = high_resolution_clock::now();
        cout << "--------------------------------------------------------" << endl;
        cout << "rezultatai apskaiciuoti" << endl;
        cout << "--------------------------------------------------------" << endl;
        //BAIGTAS REZULTATU SKAICIAVIMAS

        //PASIRINKIMAS, AR NORIMA, KAD DUOMENYS BUTU ISVESTI I EKRANA AR I FAILA
        treciasP(treciasPasirinkimas);

        if (treciasPasirinkimas == 1) { //NORIMA, KAD DUOMENYS BUTU ISVESTI EKRANE
            meniuAntras(ketvirtasPasirinkimas);

            auto rikiavimoPradzia = high_resolution_clock::now();

            rikiavimas(ketvirtasPasirinkimas, studentai);       //RIKIUOJAMI STUDENTAI

            auto rikiavimoPabaiga = high_resolution_clock::now();

            cout << "--------------------------------------------------------" << endl;
            cout << "duomenys surikiuoti" << endl;
            cout << "--------------------------------------------------------" << endl;

            //KONTEINERIU KURIMAS
            vector<mok> vargsiukai;

            char kl = rikiavimoklausimas();

            auto rusiavimoPradzia = high_resolution_clock::now();

            konteineriai(studentuKiekis, studentai, kl, vargsiukai);

            auto rusiavimoPabaiga = high_resolution_clock::now();

            cout << "--------------------------------------------------------" << endl;
            cout << "studentai paskirstyti i konteinerius" << endl;
            cout << "--------------------------------------------------------" << endl;
            //KONTEINERIAI SUKURTI

            //ISVEDIMAS I EKRANA

            auto isvedimoPradzia = high_resolution_clock::now();

            cout << "VARGSIUKAI:" << endl;
            isvedimas(vargsiukai, cout, kl);

            cout << "KIETIAKAI: " << endl;
            isvedimas(studentai, cout, kl);

            auto isvedimoPabaiga = high_resolution_clock::now();
            cout << "Darbas su " << studentuKiekis << "studentu failu" << endl;
            //cout << "Failo su " << studentuKiekis << " studentu generavimas truko: " << trukmesSkaiciavimas(failoGeneravimoPradzia, failoGeneravimoPabaiga).count() << " ms" << endl;
            cout << "Nuskaitymas truko: " << trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() << " ms" << endl;
            cout << "Skaiciavimas truko: " << trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() << " ms" << endl;
            cout << "Rikiavimas truko: " << trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() << " ms" << endl;
            cout << "Rusiavimas i konteinerius truko: " << trukmesSkaiciavimas(rusiavimoPradzia, rusiavimoPabaiga).count() << " ms" << endl;
            cout << "Isvedimas truko: " << trukmesSkaiciavimas(isvedimoPradzia, isvedimoPabaiga).count() << " ms" << endl;
            cout << endl;
            cout << "Programa truko: " << trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() + trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() + trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() + trukmesSkaiciavimas(rusiavimoPradzia, rusiavimoPabaiga).count() + trukmesSkaiciavimas(isvedimoPradzia, isvedimoPabaiga).count() << "ms" << endl;
        }
        else {//NORIMA, KAD DUOMENYS BUTU ISVESTI I FAILUS

            //SUKURIAMI FAILAI ISVEDIMUI
            ofstream out1("Vargsiukai.txt");
            if (!out1)
                cout << "Nepavyko atidaryti failo isvedimui." << endl;

            ofstream out2("Kietiakai.txt");
            if (!out2)
                cout << "Nepavyko atidaryti failo isvedimui." << endl;

            cout << "--------------------------------------------------------" << endl;
            cout << "failai isvedimui sukurti" << endl;
            cout << "--------------------------------------------------------" << endl;

            meniuAntras(ketvirtasPasirinkimas);

            auto rikiavimoPradzia = high_resolution_clock::now();
            rikiavimas(ketvirtasPasirinkimas, studentai);
            auto rikiavimoPabaiga = high_resolution_clock::now();

            cout << "--------------------------------------------------------" << endl;
            cout << "duomenys isrikiuoti" << endl;
            cout << "--------------------------------------------------------" << endl;
            //RIKIAVIMAS BAIGTAS

            //KONTEINERIU KURIMAS
            vector<mok> vargsiukai;

            char kl = rikiavimoklausimas();

            auto rusiavimoPradzia = high_resolution_clock::now();
            konteineriai(studentuKiekis, studentai, kl, vargsiukai);
            auto rusiavimoPabaiga = high_resolution_clock::now();

            cout << "--------------------------------------------------------" << endl;
            cout << "studentai paskirstyti i konteinerius" << endl;
            cout << "--------------------------------------------------------" << endl;

            //ISVEDIMAS
            auto isvedimoPradzia = high_resolution_clock::now();
            isvedimas(vargsiukai, out1, kl);
            isvedimas(studentai, out2, kl);
            auto isvedimoPabaiga = high_resolution_clock::now();

            cout << "--------------------------------------------------------" << endl;
            cout << "duomenys isvesti" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << "Darbas su " << studentuKiekis << "studentu failu" << endl;
            // cout << "Failo su " << studentuKiekis << " studentu generavimas truko: " << trukmesSkaiciavimas(failoGeneravimoPradzia, failoGeneravimoPabaiga).count() << " ms" << endl;
            cout << "Nuskaitymas truko: " << trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() << " ms" << endl;
            cout << "Skaiciavimas truko: " << trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() << " ms" << endl;
            cout << "Rikiavimas truko: " << trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() << " ms" << endl;
            cout << "Rusiavimas i konteinerius truko: " << trukmesSkaiciavimas(rusiavimoPradzia, rusiavimoPabaiga).count() << " ms" << endl;
            cout << "Isvedimas truko: " << trukmesSkaiciavimas(isvedimoPradzia, isvedimoPabaiga).count() << " ms" << endl;
            cout << endl;
            cout << "Programa truko: " << trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() + trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() + trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() + trukmesSkaiciavimas(rusiavimoPradzia, rusiavimoPabaiga).count() + trukmesSkaiciavimas(isvedimoPradzia, isvedimoPabaiga).count() << "ms" << endl;

            out1.close();
            out2.close();
            //isvalymas(vargsiukai);
            //isvalymas(studentai);
        }
    }

}
