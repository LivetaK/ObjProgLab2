#include "Vector.hpp"
#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"


TEST_CASE("Size", "[size]"){

    WARN("REQUIRE stops at [size] failure:");

    Vector<int> v = { 1, 2, 3, 4 };
    CHECK(v.Size() == 4);

}
TEST_CASE("Is Empty", "[IsEmpty]"){

    WARN("REQUIRE stops at [IsEmpty] failure:");

    Vector<int> v;
    CHECK(v.Size() == 0);

}
TEST_CASE("PushBack", "[pushback]"){

    WARN("REQUIRE stops at [pushback] failure:");

    Vector<int> v = { 1, 2, 3 };
    v.PushBack(4);

    CHECK(v.Size() == 4);
    CHECK(v[3] == 4);
}

TEST_CASE("Pop back", "[PopBack]"){

    WARN("REQUIRE stops at [PopBack] failure:");

    Vector<int> v = { 1, 2, 3, 4};
    v.PopBack();
    CHECK(v.Size() == 3);
}

TEST_CASE("Clear", "[clear]"){

    WARN("REQUIRE stops at [clear] failure:");

    Vector<int> v = { 1, 2, 3, 4, 6 };
    v.Clear();
    CHECK(v.Size() == 0);

}

