#include <iostream>
#include <ostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdarg>
//#include<curses.h>
//#include <ncurses.h>
#include <algorithm>
using namespace std;


class Matrix{

public:
  int num_rows, num_col;
  char name;



  double** values;


  //hussien
  Matrix();
  ~Matrix();
//Doaa
 enum MI{MI_ZEROS, MI_ONES, MI_EYE, MI_RAND, MI_VALUE};

//rowan
  Matrix(int num_rows, int num_col, int initialization= MI_ZEROS, double initializationValue = 0.0 );
  Matrix(int num_rows, int num_col, double first, ...);
  Matrix(const Matrix& m);
  Matrix(double d);
  Matrix(string s);


//rawan
  void copy(const Matrix& m);
  void copy(double d);
  void copy(string s);
  void reset();

  string getString();

  Matrix operator=(const Matrix& m);
  Matrix operator=(double d);
  Matrix operator=(string s);

//hossam
  void add(const Matrix& m);
  void operator+=(Matrix& m);
  void operator+=(double d);
  Matrix operator+(Matrix& m);
  Matrix operator+(double d);


  void sub(const Matrix& m);
  void operator-=(Matrix& m);
  void operator-=(double d);
  Matrix operator-(Matrix& m);
  Matrix operator-(double d);

//hussien
  void mul(Matrix& m);
  void operator*=(Matrix& m);
  void operator*=(double d);
  Matrix operator*(Matrix& m);
  Matrix operator*(double d);

//Doaa & zeinab
 Matrix division(Matrix a, Matrix b);

  Matrix multiply_by_no( double d);
  Matrix getMinormatrix();
  Matrix operator/(Matrix b);
  Matrix operator/(double d);
  void operator/=( Matrix b);
  void operator/=(double b);

//bahnsasay
  Matrix operator++();//Pre Increment
  Matrix operator++(int);//Post Increment ,int is not used
  Matrix operator--();//Pre Increment
  Matrix operator--(int);//Post Increment ,int is not used

  Matrix operator-();
  Matrix operator+();


  friend istream &operator>>( istream &input, Matrix &D )

  { for (int i = 0; i<D.num_rows; i++)
   { for (int j = 0; j<D.num_col; j++)
   { input >> D.values[i][j] ;
   }
   }
   return input;
   }

  friend ostream &operator<< (ostream &output, const Matrix &D) {
  	for (int i = 0; i<D.num_rows; i++)
  	{
  		for (int j = 0; j<D.num_col; j++)
  		{
  			output << D.values[i][j] << " ";
  		}
  		output << endl;
  	}
  	return output;
  }


//mostafa
  void setSubMatrix(int iR,int iC, Matrix& m);
  Matrix getSubMatrix(int r, int c, int nr, int nc);
  Matrix getCofactor(int r,int c);

  void addColumn(Matrix& m);
  void addRow(Matrix& m);

//samir
  double& operator[](int i){return values[i/num_col][i%num_col];}
  double& operator()(int i){return values[i/num_col][i%num_col];}
  double& operator()(int r, int c){return values[r][c];}

  int getn(){return num_rows*num_col;};
  int getnR(){return num_rows;};
  int getnC(){return num_col;};
//doaa & zienab
static Matrix augment(Matrix, Matrix);
Matrix gaussianEliminate();
Matrix rowReduceFromGaussian();
Matrix inverse();
void swapRows(int r1, int r2);
Matrix createIdentity(int size);
Matrix getTranspose();
Matrix operator^(int power);

};


class CComplex {
double R;
double I;

public:

CComplex();
CComplex(string s);
CComplex(double R, double I);
CComplex(const CComplex& C);
void copy(const CComplex& C);
string getString();
double magnitude();
double angle();
void negative();
double real();
double imaginary();
static CComplex addComplex(const CComplex& A, const CComplex& B);
void add(const CComplex& C);
CComplex operator=(const CComplex& C);
CComplex operator=(double D);
void operator+=(CComplex& C);
void operator-=(CComplex& C);
CComplex operator+=(double D);
CComplex operator+(CComplex& C);
CComplex operator-(CComplex& C);
CComplex operator+(double D);
CComplex operator*(CComplex& A);
CComplex operator/(CComplex& A);
void operator/=(CComplex& A);
void operator*=(CComplex& A);
CComplex operator-(); //Negative
CComplex operator^(double D);
void operator^=(double d);
operator const string(); //Cast
 friend istream& operator >> (istream& is, CComplex& C) {
  is>>C.R;
  is>>C.I;
  return is;
}
friend ostream& operator << (ostream& os, CComplex &C)
{
  os<<C.getString();
  return os;
}
CComplex operator++(); //Pre Increment
CComplex operator++(int); //Post Increment, int is not used
double operator[](string name); //Index
double operator()(string name, string info = ""); //Argument
bool operator<(CComplex &A);
bool operator>(CComplex &A);
bool operator<=(CComplex &A);
bool operator>=(CComplex &A);
bool operator==(CComplex &A);
};s
