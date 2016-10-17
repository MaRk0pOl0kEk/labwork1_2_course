#include <iostream>
#include "methods.h"

using namespace std;

int main(/*int argc,char **argv*/)


  /*  if (argc==2)
    {
        if (argv[1]=="LCM"){ */
        {   unsigned int x0,N;
            cin >> x0;
            cin >> N;
            unsigned int mass[N];
            LinearCongruentMethod xN(x0);
            for (int i = 0; i < N; i++) {
                mass[i]=xN.rand(x0);
                cout << mass[i] << ' ';
            }

     /*   else if(argv[1]=="QCM"){

        }
        else if (argv[1]=="FIB"){

        }
        else if(argv[1]=="ICS"){

        }

        else if(argv[1]=="ASSOCIATION"){

        }
        else
        {
            cout << "Enter new name of method";
            cin.clear();
            cin.get();
        }
    }
    if ((argc==3)&&(argv[1]=="normal"))
    {
        if(argv[2]=="3sig") {
            TheRuleOfThreeSigma() xN;
        }
    }

*/

    return 0;
}
