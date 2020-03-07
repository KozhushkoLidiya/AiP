#include <iostream>

using namespace std;

int main()
{
    float R;
    float r_1;
    float r_2;
    float S;
    float P;
    float d;

      std::cout << "Enter R = ";
      std::cin >>  R;

      std::cout << "Enter r_1 = ";
      std::cin >>  r_1;

      std::cout << "Enter r_2 = ";
      std::cin >>  r_2;

      d=R+r_1;
      S=0.25*3.14*(d*d);
      P=3.14*R+3.14*r_1+2*3.14*r_2;

      std::cout << "S Salinon = " << S << std::endl;
      std::cout << "P Salinon = " << P << std::endl;

    return 0;
}
