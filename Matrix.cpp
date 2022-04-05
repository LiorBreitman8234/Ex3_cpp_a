//
// Created by bravo8234 on 03/04/2022.
//
#include "Matrix.hpp"

#include <utility>
namespace zich{
    std::vector<double> Matrix::getMatrixAsVector() {
        std::vector<double> toRet;
        for(int i =0; i < this->rowsNum;i++)
        {
            for(int j =0; j < this->colNum ;j++) {
                toRet.push_back(this->mat.at(i).at(j));
            }
        }
        return toRet;
    }

    Matrix::Matrix(std::vector<double> vector, int rowNum, int colNum) {
        for(int i =0; i < rowNum;i++)
        {
            this->mat.emplace_back();
            std::copy(vector.begin()+(i*colNum),vector.begin()+(i*colNum)+colNum, std::back_inserter(this->mat.at(i)));
        }
        this->colNum = colNum;
        this->rowsNum = rowNum;
    }
    bool operator==(Matrix& first, Matrix& other)
    {
        if(first.getRowsNum() != other.getRowsNum() || first.getColsNum() != other.getColsNum()){
            return false;
        }
        std::vector<double> firstVect = first.getMatrixAsVector();
        std::vector<double> secondVect = other.getMatrixAsVector();
        return (firstVect == secondVect);
    }
    bool operator!=(Matrix& first, Matrix& other)
    {
        return !(first == other);
    }

    bool operator>(Matrix& first, Matrix& other){
        std::vector<double> firstVec = first.getMatrixAsVector();
        std::vector<double> secondVec = other.getMatrixAsVector();
        double sum1 = 0,sum2 = 0;
        for(double i : firstVec)
        {
            sum1 += i;
        }
        for(double i : secondVec)
        {
            sum2 += i;
        }
        return sum1>sum2;
    }

    bool operator<(Matrix& first, Matrix& other)
    {
        return other>first;
    }

    bool operator<=(Matrix& first, Matrix& other)
    {
        return !(first>other);
    }

    bool operator>=(Matrix& first, Matrix& other)
    {
        return !(first<other);
    }

    Matrix &Matrix::operator+=(double x) {
        for(int i =0; i < this->rowsNum;i++)
        {
            for(int j =0; j < this->colNum;j++)
            {
                this->mat.at(i).at(j) +=x;
            }
        }
        return *this;
    }

    Matrix operator+(Matrix mat, double x){
        Matrix copy = std::move(mat);
        copy+=x;
        return copy;
    }

    Matrix& Matrix::operator+=(Matrix &second) {
        if(this->rowsNum != second.getRowsNum() || this->colNum != second.getColsNum()){
            throw std::invalid_argument("matrices need to be in same size");
        }
        for(int i =0; i > this->rowsNum;i++)
        {
            for(int j =0; j < this->colNum;j++)
            {
                this->mat.at(i).at(j) += second.getMat().at(i).at(j);
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix& first, Matrix& second){
        Matrix copy = first;
        copy += second;
        return copy;
    }

    Matrix& Matrix::operator+() {
        return *this;
    }

    Matrix &Matrix::operator++() {
        *this+=1;
        return *this;
    }

    Matrix Matrix::operator++(int) {
        Matrix& old = *this;
        operator++();
        return old;
    }

    Matrix& Matrix::operator=(Matrix first) {
        if (this == &first) {
            return *this;
        }
        this->mat = std::vector<std::vector<double>>();
        this->rowsNum = first.getRowsNum();
        this->colNum = first.getColsNum();
        for (int i = 0; i < this->rowsNum; i++) {
            mat.emplace_back(std::vector<double>());
            for (int j = 0; j < this->colNum; j++) {
                this->mat.at(i).push_back(first.getMat().at(i).at(j));
                {
                }
            }
        }
        return *this;
    }

    Matrix &Matrix::operator-=(double x) {
        for(int i =0; i < this->rowsNum;i++)
        {
            for(int j =0; j < this->colNum;j++)
            {
                this->mat.at(i).at(j) -= x;
            }
        }
        return *this;
    }

    Matrix &Matrix::operator-=(Matrix &second) {
        if(this->rowsNum != second.getRowsNum() || this->colNum != second.getColsNum()){
            throw std::invalid_argument("matrices need to be in same size");
        }
        for(int i =0; i > this->rowsNum;i++)
        {
            for(int j =0; j < this->colNum;j++)
            {
                this->mat.at(i).at(j) -= second.getMat().at(i).at(j);
            }
        }
        return *this;
    }

    Matrix operator-(double x, Matrix mat) {
        return (mat-=x);
    }
    Matrix operator-(Matrix mat, double x) {
        return (mat-=x);
    }

    Matrix operator-(Matrix first, Matrix &second) {
        return (first-=second);
    }

    Matrix &Matrix::operator-() {
        return (*this)*=-1;
    }

    Matrix &Matrix::operator*=(double x) {
        for(int i =0 ; i < this->rowsNum;i++)
        {
            for(int j =0; j < this->colNum;j++)
            {
                this->mat.at(i).at(j)*=x;
            }
        }
        return *this;
    }

    Matrix operator*(Matrix mat, double x) {
        return mat*=x;
    }

    Matrix operator*(double x, Matrix mat) {
        return mat*=x;
    }

    Matrix &Matrix::operator*=(Matrix &other) {
        if(this->colNum!= other.rowsNum)
        {
            throw std::invalid_argument("first matrix columns need to be the same as second matrix rows");
        }
        std::vector<std::vector<double>> newMat;

    }

    Matrix operator*(Matrix first, Matrix &second) {
        return first*=second;
    }

    Matrix &Matrix::operator--() {
        *this-=1;
        return *this;
    }

    Matrix Matrix::operator--(int) {
        Matrix copy = *this;
        operator--();
        return copy;
    }


};