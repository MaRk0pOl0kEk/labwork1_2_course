#include <iostream>
#include "methods.h"

using namespace std;

int main(){

    short int chooseMethod=1;
    cout << "Evenly distributed:\t"
         "For use Linear Congruent Method: 1\n\t\t\t\t"<<
         "For use Quadratic Congruent Method: 2\n\t\t\t\t\t"<<
         "For use Fibonacci correlation: 3\n\t\t\t\t\t"<<
         "For use Inverse Congruent Sequence: 4\n\t\t\t\t\t"<<
         "For use Assotiation method: 5\n\n"<<
         "Normal distributed:\t"<<
         "For use Rule of 3 sigma: 6\n\t\t\t\t\t"<<
         "For use Method of Polar coordinates: 7\n\t\t\t\t\t"<<
         "For use Ratio method: 8\n\n"<<
         "Other metods:\t\t"<<
         "For use Logarithm method for generate significant distribution: 9\n\t\t\t\t\t"<<
         "For use Arens Method: 10\n\n";
    while (chooseMethod) {
        cout << "Choose one of the methods for generate random sequence: ";
        cin >> chooseMethod;

        switch (chooseMethod) {

            case 1: {
                unsigned int x0, N;
                cout << "Enter first element of sequence:";
                cin >> x0;
                cout << "Enter the membership sequences:";
                cin >> N;
                //unsigned int mass[N];
                LinearCongruentMethod xN(x0);
                for (int i = 0; i < N; i++) {

                    int k;

                    k = xN.rand();
                    if (i == N - 1) { cout << k << "\n\n"; }
                    else if (i % 7 == 6) { cout << k << " ->\n"; }
                    else cout << k << " --> ";
                }
                break;
            }
            case 2: {
                unsigned int x0, N;
                cout << "Enter first element of sequence: ";
                cin >> x0;
                cout << "Enter the membership sequences: ";
                cin >> N;
                unsigned int mass[N];
                QuadraticCongruentMethod xN(x0);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 3: {
                unsigned int x0, x1, N;
                cout << "Enter first and the second elements of sequence:\n";
                cin >> x0;
                cin >> x1;
                cout << "Enter the membership sequences: ";
                cin >> N;
                unsigned int mass[N];
                FiboRandom xN(x0, x1);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] <<" ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 4: {
                unsigned int x0, N;
                cout << "Enter first element of sequence: ";
                cin >> x0;
                cout << "Enter the membership sequences: ";
                cin >> N;
                unsigned int mass[N];
                TheInverseCongruentSequence xN(x0);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 5: {
                unsigned int x0, x1, N;
                cout << "Enter first and the second elements of sequence:\n";
                cin >> x0;
                cin >> x1;
                cout << "Enter the membership sequences: ";
                cin >> N;
                unsigned int mass[N];
                Association xN(x0, x1);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 6: {
                double a, b;
                unsigned int x0, x1, N;
                cout << "Enter median(it's number,near which you generete bigger part of membership sequences): ";
                cin >> a;
                cout << "Enter variace(neighborhood median): ";
                cin >> b;
                cout << "Enter first and the second elements of sequence:\n";
                cin >> x0;
                cin >> x1;
                cout << "Enter the membership sequences: ";
                cin >> N;
                double mass[N];
                TheRuleOfThreeSigma xN(a, b, x0, x1);
                for (int i = 0; i < N; i++) {
                    xN.findSum();
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 7: {
                unsigned int x0, N;
                cout << "Enter first element of sequence:";
                cin >> x0;
                cout << "Enter the membership sequences:";
                cin >> N;
                double mass[N];
                TheMethodOfPolarCoordinates xN(x0);
                for (int i = 0; i < N; i++) {
                    if (i%2==0) {mass[i]=xN.rand();}
                    else if (i%2==1) {mass[i] = xN.output();}
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 8: {
                unsigned int x0, x1, N;
                cout << "Enter first and the second elements of sequence:\n";
                cin >> x0;
                cin >> x1;
                cout << "Enter the membership sequences: ";
                cin >> N;
                double mass[N];
                RatioMethod xN(x0, x1);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 9: {
                unsigned int x0, x1, N;
                double u, x, m;
                cout << "Enter first and the second elements of sequence:\n";
                cin >> x0;
                cin >> x1;
                cout << "Enter the membership sequences: ";
                cin >> N;
                cout << "Enter the constant(variance) m: ";
                cin >> m;
                double mass[N];
                LogarithmMethod xN(x0, x1, m);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }
            case 10: {
                unsigned int x0, x00, N;
                double a;
                cout << "Enter first element for main sequence: ";
                cin >> x0;
                cout << "Enter first element for subsidiary sequence: ";
                cin >> x00;
                cout << "Enter the constant(variance) a (must be double >= 0.5): ";
                cin >> a;
                while (a < 0.5) {cout << "Please,enter correct value: "; cin >> a;}
                cout << "Enter the membership sequences: ";
                cin >> N;
                double mass[N];
                GammaDistributionMethod xN(x0, x00, a);
                for (int i = 0; i < N; i++) {
                    mass[i] = xN.rand();
                    if (i == N - 1) { cout << mass[i] << "\n\n"; }
                    else if (i % 7 == 6) { cout << mass[i] << " ->\n"; }
                    else cout << mass[i] << " --> ";
                }
                break;
            }

           default: {
                cout << "Enter new name of method";
                cin.clear();
                cin.get();
            }

        }
    }

    return 0;
}
