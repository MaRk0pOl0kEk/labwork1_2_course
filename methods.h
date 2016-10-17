#pragma once
#include <cmath>
using namespace std;

unsigned int Inverse(unsigned int X0,unsigned int m);
unsigned int GCD(unsigned int a,unsigned int b);
bool isSimple(unsigned int n);
unsigned int findSimple(unsigned int n);
unsigned int findRelativelyPrime(unsigned int);
unsigned int generateA (unsigned int modul);
void setMedian();



class BaseUIntRandom{
public:
    //BaseUIntRandom();
    virtual unsigned int rand()=0;
};

class LinearCongruentMethod : public BaseUIntRandom{
public:
    LinearCongruentMethod(unsigned int x0);
    unsigned int rand(unsigned int Element);

private:
    unsigned int a,c,Element,modul;
};

class QuadraticCongruentMethod : public BaseUIntRandom{
public:
    QuadraticCongruentMethod(unsigned int x0);
    unsigned int rand();

private:
    unsigned int Element,a,c,d,modul;
};

class FiboRandom : public BaseUIntRandom{
public:
    FiboRandom(unsigned int x0,unsigned int x1);
    unsigned int rand();

private:
    unsigned int Element0,Element1,modul;
};

class TheInverseCongruentSequence : public BaseUIntRandom{
public:
    TheInverseCongruentSequence(unsigned int x0);
    unsigned int rand(unsigned int Element);

private:
    unsigned int a,c,modul,Element;
};

class Association : public BaseUIntRandom{
public:
    Association(unsigned int x0,unsigned int x1);
    unsigned int rand(unsigned int & Element0, unsigned int & Element1);

private:
    unsigned int modul,Element0,Element1,Element2;
    LinearCongruentMethod xN;
    TheInverseCongruentSequence yN;
};

class BaseIntRandom{
public:
    //BaseIntRandom();
    virtual double rand()=0;
};

class TheRuleOfThreeSigma : public BaseIntRandom{
public:
    TheRuleOfThreeSigma(double a,double b, unsigned int x0, unsigned int x1);
    double rand();
    double findSum(unsigned int x0, unsigned int x1);

private:
    double median,variance,sum=0,Element;
    Association xN;
};

class TheMethodOfPolarCoordinates : public BaseIntRandom{
public:
    TheMethodOfPolarCoordinates(unsigned int x0);
    void rand(double &x0,double &x1);
    void init(TheInverseCongruentSequence xN);
    void output(double x0,double x1);

private:
    unsigned int Element;
    double u0,u1,v0,v1,s,x0,x1;
    TheInverseCongruentSequence xN;
};

class RatioMethod : public BaseIntRandom{
public:
    RatioMethod(unsigned int Element1, unsigned int Element2);
    double rand(FiboRandom xN);

private:
    unsigned int Element1,Element2;
    double u,v,x;
    FiboRandom xN;
};

class LogarithmMethod : public BaseIntRandom{
public:
    LogarithmMethod(unsigned int Element1, unsigned int Element2,short int m,double a,double b);
    double rand();

private:
    short int m;
    double u,x;
    TheRuleOfThreeSigma xN;
};

class GammaDistributionMethod : public BaseIntRandom{
public:
    GammaDistributionMethod(unsigned int x0,unsigned  int x00, unsigned int Element);
    double rand();

private:
    unsigned int Element;
    double u,y,x,v;
    double a;
    LinearCongruentMethod xN;
    QuadraticCongruentMethod yN;
};