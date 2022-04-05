//
// Created by bravo8234 on 03/04/2022.
//

#ifndef EX3_CPP_A_MATRIX_HPP
#define EX3_CPP_A_MATRIX_HPP
#include <iostream>
#include <vector>
#include <exception>
namespace zich {
    class Matrix {
    private:
        std::vector<std::vector<double>> mat;
        int rowsNum;
        int colNum;
    public:
        Matrix(std::vector<double> vector, int rowNum, int colNum);

        //getters
        std::vector<double> getMatrixAsVector();
        int getRowsNum() const{return this->rowsNum;}
        int getColsNum() const{return this->colNum;}
        std::vector<std::vector<double>>& getMat(){return this->mat;}
        //addition operators
        Matrix &operator+=(double x);

        Matrix &operator+=(Matrix &second);

        friend Matrix operator+(Matrix mat, double x);

        friend Matrix operator+(const Matrix& first, Matrix &second);

        Matrix &operator+();

        Matrix &operator++();

        Matrix operator++(int);

        Matrix& operator=(Matrix first);

        //subtraction operators
        Matrix &operator-=(double x);

        Matrix &operator-=(Matrix &second);

        friend Matrix operator-(double x, Matrix mat);

        friend Matrix operator-(Matrix mat, double x);

        friend Matrix operator-(Matrix first, Matrix &second);

        Matrix &operator-();

        Matrix &operator--();

        Matrix operator--(int);

        //boolean operators
        friend bool operator<(Matrix& first, Matrix &other);

        friend bool operator>(Matrix& first, Matrix &other);

        friend bool operator<=(Matrix& first, Matrix &other);

        friend bool operator>=(Matrix& first, Matrix &other);

        friend bool operator==(Matrix& first, Matrix &other);

        friend bool operator!=(Matrix& first, Matrix &other);

        //multiplication operators
        Matrix &operator*=(double x);

        friend Matrix operator*(Matrix mat, double x);

        friend Matrix operator*(double x, Matrix mat);

        Matrix &operator*=(Matrix &other);

        friend Matrix operator*(Matrix first, Matrix &second);

        //input,output operators
        friend std::ostream &operator<<(std::ostream &os, const Matrix &mat);

        friend std::istream &operator>>(std::istream &os, std::string mat);
    };



}
#endif //EX3_CPP_A_MATRIX_HPP
