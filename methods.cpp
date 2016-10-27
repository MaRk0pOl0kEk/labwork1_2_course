#include <iostream>
#include <climits>
#include "math.h"
#include <cmath>
#include "methods.h"
#define USIMPLE_MAX 4294967189

using namespace std;
long long GCD(long long x0, long long modul, long long &a, long long &b)
{
    if (x0==0) {
        a = 0;
        b = 1;
        return modul;
    }
    long long x1,y1;
    long long d = GCD(modul % x0, x0, x1, y1);
    a = y1 - (modul/x0) * x1;
    b = x1;
    return d;
}
long long Inverse(long long x0, long long modul)
{
    long long a,b;
    if (GCD(x0,modul,a,b) != 1) { cout << "have no inverse element!";}
    else a = (a%modul + modul)%modul;
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
    unsigned int k=0;
    unsigned int mass[35];
    for (unsigned int i=2;i*i<=modul;i++)
      {
         if (isSimple(i)&&(modul%i==0))
         {
             mass[k]=i;
             k++;
             modul/=i;
             i=2;
         }
      }
   for (unsigned int b = 2, i; b < modul; b++) {
        for (i = 0;i<k;i++) {
            if (b % mass[i] != 0) break;
            }
            if (i == k)
            {
                cout << b+1;
                return b + 1;
            }
   }
    return 0;
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
double maxElement(unsigned int mass[],unsigned int N)
{
    for(unsigned int i=0;i<N;i++){
        
    }
}



//BaseUIntRandom::BaseUIntRandom() {}
unsigned int BaseUIntRandom::rand() {}

LinearCongruentMethod::LinearCongruentMethod(unsigned int x0){ // Використовиє в якості "а" трійку
    Element = x0;
    modul = USIMPLE_MAX;
    a=3 /*generateA(modul)*/ ;
    c=findRelativelyPrime(modul);
}
unsigned int LinearCongruentMethod::rand()
{
    Element = ((a%modul)*(Element%modul)+(c%modul))%modul;
    return Element;
}

QuadraticCongruentMethod::QuadraticCongruentMethod(unsigned int x0)  // Використовиє в якості "а" трійку
{
    Element=x0;
    modul=USIMPLE_MAX;
    a=3 /*generateA(modul)*/ ;
    c=findRelativelyPrime(modul);
    d=generateD(a,modul);
}
unsigned int QuadraticCongruentMethod::rand()
{
    Element=(((d*Element)%modul*(Element))%modul+(a*Element)%modul+c)%modul;
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

TheInverseCongruentSequence::TheInverseCongruentSequence(unsigned int x0):Element(x0),modul(USIMPLE_MAX)  // Використовиє в якості "а" трійку
{
    a=3 /*generateA(modul)*/ ;
    c=findRelativelyPrime(modul);
}
unsigned int TheInverseCongruentSequence::rand() {
    Element = ((a * Inverse(Element, modul) % modul) + c) % modul;
    return Element;
}
Association::Association(unsigned int x0,unsigned int x1) :Element0(x0),Element1(x1),xN(x0),yN(x1),Element2(0),modul(USIMPLE_MAX){}
unsigned int  Association::rand()
{
    Element0=xN.rand();
    Element1=yN.rand();
    Element2=(Element0-Element1)%modul;
    return Element2;
}

BaseIntRandom::BaseIntRandom() {}

TheRuleOfThreeSigma::TheRuleOfThreeSigma(double a,double b, unsigned int x0, unsigned int x1):median(a),variance(b),xN(x0,x1)
{
    sum = findSum();
}
double TheRuleOfThreeSigma::rand()
{
    Element = median + ( (sum-6)*variance );
    return Element;
}
double TheRuleOfThreeSigma::findSum()//variance <= USIMPLE_MAX / 12
{
    double mass[12];
    for (int i=0;i<12;i++)
    {
        mass[i]=((double)xN.rand()/USIMPLE_MAX)*(variance-median)+median;
        sum+=mass[i];
    }
    return sum;
}

TheMethodOfPolarCoordinates::TheMethodOfPolarCoordinates(unsigned int x0):xN(x0),x0(0.),x1(0.)
{
    Element=x0;
}

double TheMethodOfPolarCoordinates::rand()
{
    s=1.;
    while (s>=1)
    {
        u0=(double)xN.rand();
        u1=(double)xN.rand()/USIMPLE_MAX;
        u0/=USIMPLE_MAX;
        v0 = u0 * 2 - 1;
        v1 = u1 * 2 - 1;
        s = v0 * v0 + v1 * v1;
    }
    x0=v0*sqrt(-2*log(s)/s);
    x1=v1*sqrt(-2*log(s)/s);
    return x0;
}
double TheMethodOfPolarCoordinates::output()
{
   return x1;
}

RatioMethod::RatioMethod(unsigned int Element1, unsigned int Element2):xN(Element1,Element2) {}
double RatioMethod::rand()
{
  do {
        u = (double)xN.rand()/USIMPLE_MAX;
        if(u) {
            v = (double)xN.rand() / USIMPLE_MAX;
            x = (v - 0.5) / u * sqrt(8 / exp(1.));
        }
      else continue;
        if  ((x*x <= 5 - 4*u*exp(0.25))||(x*x <= -4 *log(u))) {
            return x;
        }
    }  while (x*x >= 4*exp(-1.35)/u + 1.4);
    return 0;
}

LogarithmMethod::LogarithmMethod(unsigned int Element1, unsigned int Element2, double m):xN(a,b,Element1,Element2),m(m) {}
double LogarithmMethod::rand( )
{
    xN.findSum();
    u=xN.rand();
    x=-m*log(u);
    return x;
}

GammaDistributionMethod::GammaDistributionMethod(unsigned int x0,unsigned int x00, double a):xN(x0),yN(x00),a(a) {}
double GammaDistributionMethod::rand()
{
    do {
        do {
            u = (double)xN.rand()/USIMPLE_MAX;
            y = tan(u * M_PI);
            x = y * sqrt(2 * a - 1) + a - 1;
        } while (x <= 0);
        v=(double)yN.rand()/USIMPLE_MAX;
    }while (v>(1+y*y)*exp((a-1)*log(x/(a-1)) - y*sqrt(2*a-1)));
    return x;
}

