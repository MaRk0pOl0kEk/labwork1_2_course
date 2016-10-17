#include <iostream>
#include <climits>
#include "methods.h"
#include <cmath>
#define USIMPLE_MAX 4294967189

using namespace std;
unsigned int Inverse(unsigned int X0,unsigned int m) // Знаходить обернене число по модулю m
{
    unsigned int y=1;
    if (X0==0) y=UINT_MAX;
    else{
        while (y<m)
        {
            if((X0%m * y%m)%m==1)
                break;
            else y++;
        }
    }
    return y;
}
unsigned int GCD (unsigned int a,unsigned int b) //НСД
{
    while (b)
    {
        a %= b;
        swap (a, b);
    }
    return a;
}
bool isSimple(unsigned  int n)// Чи є число простим
{
    for(int i=2;i*i<=n;i++){
        if (n%i==0) return false;
        }
    return true;
}
unsigned int findSimple(unsigned int n=UINT_MAX) // Згенерувати просте число,що найближче до заданого знизу
{
    if (n%2==0) n-=1;
    while (!isSimple(n)) {
        n -= 2;
    }
    cout << n;
    return n;
}
unsigned int findRelativelyPrime(unsigned int n) // Згенерувати взаємопросте число
{
    unsigned int a=pow(rand(),2);
    while (n%a==0)
    {
        a++;
    }
    return a;
}
unsigned int generateA (unsigned int modul) //Генерує константу А
{
    unsigned int k=0,b=2;
    unsigned int mass[modul/int(log(modul))];
    for (unsigned int i=2;i<modul/2;i++)
    {
        if (isSimple(i)&&(modul%i==0))
        {
            mass[k]=i;
            k++;
        }
        else continue;
    }
    for(int i=0;i<=k;i++)
    {
        if(b%mass[i]==0) continue;
        else b++;
    }
    return b+1;
}
unsigned int generateD(unsigned int a, unsigned int modul) // Генерує D
{
    unsigned int d;
    if(modul%4==0)  d=(a-1)%4;
    if(modul%2==0) d=(a-1)%2;

    if (a<(2*a)%modul) d=a;
    else d=a*2;
    return d;
}



//BaseUIntRandom::BaseUIntRandom() {}

LinearCongruentMethod::LinearCongruentMethod(unsigned int x0):Element(x0),modul(USIMPLE_MAX),a(generateA(modul)),c(findRelativelyPrime(modul)){}
unsigned int LinearCongruentMethod::rand(unsigned int Element)
{
      Element = (a*Element+c)%modul;
    return Element;
}

QuadraticCongruentMethod::QuadraticCongruentMethod(unsigned int x0):Element(x0),modul(USIMPLE_MAX),a(generateA(modul)),c(findRelativelyPrime(modul)),d(generateD(a,modul)){}
unsigned int QuadraticCongruentMethod::rand()
{
    Element=(d*Element*Element+a*Element+c)%modul;
return Element;
}

FiboRandom::FiboRandom(unsigned int x0,unsigned int x1):Element0(x0),Element1(x1),modul(USIMPLE_MAX){}
unsigned int FiboRandom::rand( )
{
    unsigned int k;
        k = (Element0 + Element1) % modul;
        Element0 = Element1;
        Element1 = k;
    return k;
}

TheInverseCongruentSequence::TheInverseCongruentSequence(unsigned int x0):Element(x0),modul(USIMPLE_MAX),a(generateA(modul)),c(findRelativelyPrime(modul)){}
unsigned int TheInverseCongruentSequence::rand(unsigned int Element)//test p na prostoty
{
    Element=(((a%modul)*(Inverse(Element,modul)%modul))%modul+c%modul)%modul;
    return Element;
}

Association::Association(unsigned int x0,unsigned int x1) :modul(USIMPLE_MAX),Element0(x0),Element1(x1),Element2(),xN(Element0),yN(Element1){}
unsigned int  Association::rand(unsigned int & Element0, unsigned int & Element1)
{
    Element0=xN.rand(Element0);
    Element1=yN.rand(Element1);
    Element2=(Element0-Element1)%modul;
    return Element2;
}

//BaseIntRandom::BaseIntRandom() {}

TheRuleOfThreeSigma::TheRuleOfThreeSigma(double a,double b, unsigned int x0, unsigned int x1):median(a),variance(b),xN(x0,x1),sum(findSum(x0,x1)){}
double TheRuleOfThreeSigma::rand()
{
    Element = median + (sum-6)*variance;
    return Element;
}
double TheRuleOfThreeSigma::findSum(unsigned int x0, unsigned int x1)
{
    double mass[12];
    for (int i=0;i<12;i++)
    {
        mass[i]=(xN.rand(x0,x1)/USIMPLE_MAX)*median;
        sum+=mass[i];
    }
    return sum;
}

TheMethodOfPolarCoordinates::TheMethodOfPolarCoordinates(unsigned int x0):Element(x0),xN(Element),s(1.),x0(0.),x1(0.){}
void TheMethodOfPolarCoordinates::rand(double &x0,double &x1)
{
    while (s>=1)
    {
        v0 = u0 * 2 - 1;
        v1 = u1 * 2 - 1;
        s = v0 * v0 + v1 * v1;
    }
    x0=v0*sqrt(-2*log(s)/s);
    x1=v1*sqrt(-2*log(s)/s);

}
void TheMethodOfPolarCoordinates::init(TheInverseCongruentSequence xN)
{
    u0=xN.rand(Element);
    u1=xN.rand(unsigned (int(u0)))/USIMPLE_MAX;
    u0/=USIMPLE_MAX;
}
void TheMethodOfPolarCoordinates::output(double x0, double x1)
{
    cout << x0 << "\n" << x1;
}

RatioMethod::RatioMethod(unsigned int Element1, unsigned int Element2):xN(Element1,Element2) {}
double RatioMethod::rand(FiboRandom xN)
{
    newValues:
    while (x*x >= 4*exp(-1.35)/u + 1.4){
    while (!u) { u = xN.rand()/USIMPLE_MAX; }
    v = xN.rand()/USIMPLE_MAX;
    x = (v - 0.5) / u * sqrt(8 / exp(1.));
    }
    if ((x*x <= 5 - 4*u*exp(0.25))||(x*x <= -4 *log(u))) return x;
    else goto newValues;
}

LogarithmMethod::LogarithmMethod(unsigned int Element1, unsigned int Element2,short int m,double a=0.5,double b=1./6.):xN(a,b,Element1,Element2),m(m) {}
double LogarithmMethod::rand( )
{
    u=xN.rand();
    x=-m*log(u);
    return x;
}

GammaDistributionMethod::GammaDistributionMethod(unsigned int x0,unsigned int x00, unsigned int Element):xN(x0),yN(x00),Element(Element) {}
double GammaDistributionMethod::rand()
{
    v=yN.rand();
    do {
        do {
            u = xN.rand(Element);
            y = tan(M_PI * u);
            x = y * sqrt(2 * a - 1) + a - 1;
        } while (x <= 0);
    }while (v>(1+y*y)*exp((a-1)*log(x/(a-1)) - y*sqrt(2*a-1)));
    return x;
}

