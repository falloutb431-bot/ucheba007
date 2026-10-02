#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "list.hpp"



TEST_CASE("PushBack increases size and stores values in order", "[list][pushback]") {
    List lst;
    lst.PushBack(10);
    REQUIRE(lst.Size() == 1);

    lst.PushBack(20);
    REQUIRE(lst.Size() == 2);

    lst.PushBack(30);
    REQUIRE(lst.Size() == 3);

    
    REQUIRE(lst.PopBack() == 30);
    REQUIRE(lst.PopBack() == 20);
    REQUIRE(lst.PopBack() == 10);
    REQUIRE(lst.Empty() == true);
}



TEST_CASE("PushFront increases size and stores values in reverse order", "[list][pushfront]") {
    List lst;
    lst.PushFront(10);
    REQUIRE(lst.Size() == 1);

    lst.PushFront(20);
    REQUIRE(lst.Size() == 2);

    lst.PushFront(30);
    REQUIRE(lst.Size() == 3);

    
    REQUIRE(lst.PopFront() == 30);
    REQUIRE(lst.PopFront() == 20);
    REQUIRE(lst.PopFront() == 10);
    REQUIRE(lst.Empty() == true);
}



TEST_CASE("PopBack throws on empty list", "[list][popback]") {
    List lst;
    REQUIRE_THROWS_AS(lst.PopBack(), std::runtime_error);
    REQUIRE(lst.Size() == 0);
    REQUIRE(lst.Empty() == true);
}



TEST_CASE("PopFront throws on empty list", "[list][popfront]") {
    List lst;
    REQUIRE_THROWS_AS(lst.PopFront(), std::runtime_error);
    REQUIRE(lst.Size() == 0);
    REQUIRE(lst.Empty() == true);
}



TEST_CASE("Complex usage scenario with mixed operations", "[list][complex]") {
    List lst;

   
    lst.PushBack(1);     
    lst.PushFront(2);     
    lst.PushBack(3);      
    lst.PushFront(4);     
    lst.PushBack(5);      

    REQUIRE(lst.Size() == 5);
    REQUIRE(lst.Empty() == false);

    
    REQUIRE(lst.PopFront() == 4);   
    REQUIRE(lst.PopBack() == 5);     
    REQUIRE(lst.Size() == 3);

    
    lst.PushFront(100);   
    lst.PushBack(200);    
    REQUIRE(lst.Size() == 5);


    REQUIRE(lst.PopFront() == 100);
    REQUIRE(lst.PopFront() == 2);
    REQUIRE(lst.PopBack() == 200);
    REQUIRE(lst.PopBack() == 3);
    REQUIRE(lst.PopBack() == 1);
    REQUIRE(lst.Size() == 0);
    REQUIRE(lst.Empty() == true);

    REQUIRE_THROWS_AS(lst.PopFront(), std::runtime_error);
    REQUIRE_THROWS_AS(lst.PopBack(), std::runtime_error);

  
    lst.PushBack(42);
    REQUIRE(lst.Size() == 1);
    REQUIRE(lst.PopBack() == 42);
    REQUIRE(lst.Empty() == true);
}