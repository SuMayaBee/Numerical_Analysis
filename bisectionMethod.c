#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 200
#define F(X) ((X*X*X) +(4*X*X) -10)

int main() {
    double a, b, c, fa, fb, fc, tol=10e-6;
    printf("Enter the number of a and b: ");
    scanf("%lf %lf", &a, &b);
    fa = F(a);
    fb = F(b);

    if(fa*fb>=0) {
        puts("No roots");
        return 0;
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
    puts("Iter\ta\t\tb\t\tc\t\tfa\t\tfb\t\tfc");
    printf("---------------------------------------------------------------------------------------------------------\n");
    int i=0;
    while(i<MAXN) {
        i++;
        c= a + (b-a)/2;
        fc=F(c);
        printf(" %d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,a,b,c,fa,fb,fc);

        if(fabs(fc)<=tol) {
            printf("The approximate solution is: %lf \n", c);
            printf("The iteration number is: %d \n", i);
            return 1;
        } else {
            if(fa*fc>=0) {
                a = c;
                fa=fc;
            } else {
                b = c;
                fb = fc;
            }
        }
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
    return 0;
}
