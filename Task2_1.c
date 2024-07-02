#include <stdio.h>

int modul(int num){

    if (num < 0){

        return -num;

    } 

    else {

        return num;
        
    }
}

double sqrt_newton(double x, double e){

    double x0 = 1.0;
    double xi = x0;

    do{

        x0 = xi;
        xi = 0.5 * (xi + x / xi);

    } 

    while (modul((xi - x0) * (xi - x0)) > e);

    return xi;
    
}

int main(){

    double epsilon;
    double x;

    printf("Введите эпсилон: ");
    scanf("%lf", &epsilon);

    printf("Введите числа: \n");

    while (scanf("%lf", &x) != EOF){

        double result = sqrt_newton(x, epsilon);
        printf("%.10g\n", result);

    }

    return 0;
}
