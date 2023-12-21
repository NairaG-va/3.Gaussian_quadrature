//\int_{0}^{1} xf(x) dx   \sim   С_{1}f(0) + C_{2}f(x_2)
#include <iostream>
#include <math.h>

double interp(double k2, double k1, double k0);
double integral(double k2, double k1, double k0);

int main(int argc, char* argv[]){
	
	if (argc < 4)
{
   std::cout << "No arguments" << "\n";
   return 1;
}

double k2, k1, k0;

try
{
   k2 = std :: stod(argv[1]);
   k1 = std :: stod(argv[2]);
   k0 = std :: stod(argv[3]);
}
catch(...)
{
   std::cout << "Not able to parse arguments" << "\n";
   return 1;
}

std::cout << integral(k2, k1, k0) << "\n";
std::cout << interp(k2, k1, k0) << "\n";
std::cout << integral(k2, k1, k0) - interp(k2, k1, k0) << "\n";
	
return 0;
}

double interp(double k2, double k1, double k0){

double x1 = 0;
double x2 = 3.0/4.0;

double c1 = 1.0/18.0;
double c2 = 4.0/9.0;

return c1*(k2*x1*x1 + k1*x1 + k0) + c2*(k2*x2*x2 + k1*x2 + k0);
}

double integral(double k2, double k1, double k0){
return k2/4 + k1/3 + k0/2;
}
