#include <stdio.h>

int main(){

    double x, coef, result;
    
    printf("Введите x: " );
    scanf("%lf", &x);
    
    printf("Введите коэффициент: " );
    scanf("%lf", &coef);

   

    result = coef;

    while (scanf("%lf", &coef) != EOF){

        result = result * x + coef;

    }

    printf("Значение многочлена: %.10g\n", result); 
    
    return 0;
}
