#include <stdio.h>
#include <stdlib.h>
#define F(X) ((X*X)+1)

int main() {
    double a=0.0, b=2.0;
    int n;
    
   
    double sumI = 0.0;
    double sumOdds = 0.0, sumEvens = 0.0;
    double x[100], fx[100];
    x[0] = a;
     double h = (b - a) / n;
      
    for(int i=0; i<=10; i++) {
          x[i]= x[i]+h;
          fx[i] = F(x[i]);
    }
   

    
    double sumX = fx[0] + fx[10];
 
    
    for (int i = 1; i < 10; i++) sumI += fx[i];
    double integration_trapezoidal = (h * (sumX + (2 * sumI))) / 2;

    
 
    for (int i = 1; i < 10; i += 2) sumOdds += fx[i];
    for (int i = 2; i < 9; i += 2) sumEvens += fx[i];
    double integration_simpson = (h / 3) * (fx[0] + fx[10] + (4 * sumOdds) + (2 * sumEvens));

    printf("Trapezoidal value is = %9.6lf\n", integration_trapezoidal);
    printf("Simpson's value is = %9.6lf\n", integration_simpson);

    return 0;
}

