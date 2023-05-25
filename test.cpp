#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"
#include "Checking.h"
// add includes


TEST_CASE("Functions in DSList", "[DSList]")
{
    DSList<int> ll;
    //Push_front
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    //Size and []
    CHECK(ll.Size() == 3);
    CHECK(ll[0] == 5);
    CHECK(ll[1] == 4);
    CHECK(ll[2] == 3);
    //Pop_front
    ll.pop_front();
    CHECK(ll.Size() == 2);
    //isEmpty
    CHECK(ll.isEmpty() == false);
    //Search element
    CHECK(ll.searchElement(3)==2);
    //insert at
    ll.insert_at(6,2);
    CHECK(ll[2] == 6);
    //remove at
    ll.remove_at(2);
    CHECK(ll.Size() == 2);
    //getTail
    CHECK(ll.getTail() == 4);
    //Clear
    ll.clear();
    CHECK(ll.Size() == 0);
    CHECK(ll.isEmpty() == true);



}

TEST_CASE("Functions in Checking", "Checking")
{
    Checking model;
    model.checkingStack("test_data/DSVector_bad.h");

}

