//
// Created by bravo8234 on 03/04/2022.
//
#include "Matrix.hpp"
namespace zich{
    std::vector<double> Matrix::getMatrixAsVector() {
        std::vector<double> toRet;
        for(int i =0; i < this->length;i++)
        {
            for(int j =0; j < this->width ;j++) {
                toRet.push_back(this->mat.at(i).at(j));
            }
        }
        return toRet;
    }

    Matrix &Matrix::operator*=(Matrix &other) {
        return NULL;
    }
};