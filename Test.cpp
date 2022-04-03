//
// Created by bravo8234 on 03/04/2022.
//
#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
TEST_CASE("matrix initialization and simple operators"){
    std::vector<double> vet = {1,2,3,4,5,6,7,8,9};
    std::vector<double> checkOn = {2,3,4,5,6,7,8,9,10};
    std::vector<double> mulTest = {2,4,6,8,10,12,14,16,18};
    zich::Matrix mat{vet,3,3};\
    zich::Matrix test{checkOn,3,3};
    CHECK(mat.getMatrixAsVector() == vet);
    CHECK(test.getMatrixAsVector() == checkOn);
    zich::Matrix add = mat+1;
    CHECK(add.getMatrixAsVector() == test.getMatrixAsVector());
    zich::Matrix sub = add-1;
    CHECK(sub.getMatrixAsVector() == vet);
    sub++;
    CHECK(sub.getMatrixAsVector() == checkOn);
    sub--;
    CHECK(sub.getMatrixAsVector() == vet);
    zich::Matrix addN = 1+sub;
    CHECK(addN.getMatrixAsVector() == checkOn);
    sub -= 1;
    zich::Matrix mul = sub*2;
    CHECK(mul.getMatrixAsVector() == mulTest);
}
TEST_CASE("bad use of operators"){
    std::vector<double> vector = {1,2,3,4};
    std::vector<double> second = {1,2,3,4,5,6,7,8,9};
    zich::Matrix first{vector,2,2};
    zich::Matrix secondM{second,3,3};
    CHECK_THROWS(first+secondM);
    CHECK_THROWS(first-secondM);
    CHECK_THROWS(secondM-first);
    CHECK_THROWS(secondM*first);
    CHECK_THROWS(first*secondM);
    CHECK_THROWS(first+=secondM);
    CHECK_THROWS(first-=secondM);
    CHECK_THROWS(secondM-=first);
    CHECK_THROWS(first*=secondM);
    CHECK_THROWS(secondM*=first);
    CHECK_THROWS_MESSAGE((first+secondM),"matrices need to be in same size");
    CHECK_THROWS_MESSAGE((first*secondM),"matrices need to be in same size");

}
