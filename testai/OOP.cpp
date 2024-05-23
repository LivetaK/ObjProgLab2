#include "studentas.h"
#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"



TEST_CASE("Setteriai ir getteriai", "[SettersGetters]") {

    WARN("REQUIRE stops at [SettersGetters] failure:");

    mok stud;
    stud.setvar("vardas");
    stud.setpav("pavarde");
    stud.seteg(4);
    stud.setnd({ 1, 9, 8 });

    CHECK(stud.getvar() == "vardas");
    CHECK(stud.getpav() == "pavarde");
    CHECK(stud.geteg() == 4);
    CHECK(stud.getnd() == vector<int>({1,9,8}));
 }

TEST_CASE("Kopijavimo konstruktorius", "[Copy Constructor]"){

    WARN("REQUIRE stops at [Copy Constructor] failure:");

    mok originalus;
    originalus.setvar("vardziukas");
    originalus.setpav("pavardziukas");
    originalus.seteg(7);
    originalus.setnd({ 1, 5, 8 });

    mok kopija = originalus;

    CHECK(kopija.getvar() == "vardziukas");
    CHECK(kopija.getpav() == "pavardziukas");
    CHECK(kopija.geteg() == 7);
    CHECK(kopija.getnd() == vector<int>({ 1, 5, 8 }));
}

TEST_CASE("Kopijavimo priskyrimo operatorius", "[Copy Assignment Operator]") {

    WARN("REQUIRE stops at [Copy Assignment Operator] failure:");

    mok originalus2;
    originalus2.setvar("vardenis");
    originalus2.setpav("pavardenis");
    originalus2.seteg(10);
    originalus2.setnd({ 4, 9, 9 });
    mok kopija2;
    kopija2 = originalus2;

    CHECK(kopija2.getvar() == "vardenis");
    CHECK(kopija2.getpav() == "pavardenis");
    CHECK(kopija2.geteg() == 10);
    CHECK(kopija2.getnd() == vector<int>({ 4, 9, 9 }));
 }

 TEST_CASE("Perkelimo konstruktorius", "[Move Constructor]") {

    WARN("REQUIRE stops at [Move Constructor] failure:");

    mok originalus3;
    originalus3.setvar("vardukas");
    originalus3.setpav("pavardukas");
    originalus3.seteg(5);
    originalus3.setnd({ 7, 9, 9 });
    mok movintas = move(originalus3);

    CHECK(movintas.getvar() == "vardukas");
    CHECK(movintas.getpav() == "pavardukas");
    CHECK(movintas.geteg() == 5);
    CHECK(movintas.getnd() == vector<int>({ 7, 9, 9 }));

    CHECK(originalus3.getvar().empty());
    CHECK(originalus3.getpav().empty());
    CHECK(originalus3.geteg() == 0);
    CHECK(originalus3.getnd().empty());
 }

 TEST_CASE("Perkelimo priskyrimo operatorius", "[Move Assignmrnt Operator]") {

    WARN("REQUIRE stops at [Move Assignmrnt Operator] failure:");

    mok originalus4;
    originalus4.setvar("vardzius");
    originalus4.setpav("pavardzius");
    originalus4.seteg(5);
    originalus4.setnd({ 7, 9, 1 });
    mok movintas2;
    movintas2 = move(originalus4);

    CHECK(movintas2.getvar() == "vardzius");
    CHECK(movintas2.getpav() == "pavardzius");
    CHECK(movintas2.geteg() == 5);
    CHECK(movintas2.getnd() == vector<int>({ 7, 9, 1 }));

    CHECK(originalus4.getvar().empty());
    CHECK(originalus4.getpav().empty());
    CHECK(originalus4.geteg() == 0);
    CHECK(originalus4.getnd().empty());
 }

 TEST_CASE("Isvesties operatorius", "[Output Operator]") {

    WARN("REQUIRE stops at [Output Operator] failure:");

    mok studentas;
    studentas.setvar("vardas");
    studentas.setpav("pavarde");
    studentas.seteg(5);
    studentas.setnd({ 5, 10 });

    stringstream output;
    output << studentas;
    CHECK(output.str() == "vardas pavarde 5 5 10 ");

 }

 TEST_CASE("Ivesties operatorius", "[Input Operator]") {

    WARN("REQUIRE stops at [Input Operator] failure:");

    mok studentas2;
    stringstream input("vardas pavarde 1 2 3");
    input >> studentas2;
    CHECK(studentas2.getvar() == "vardas");
    CHECK(studentas2.getpav() == "pavarde");
    CHECK(studentas2.geteg() == 1);
    CHECK(studentas2.getnd() == vector<int>({ 2, 3 }));
 }