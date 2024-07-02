#include <stdio.h>

int main(){

    double x, coef, result = 0, proiz = 0;
    
    printf("Введите значение x: " );
    scanf("%lf", &x);

    printf("Введите последовательность: " );
    scanf("%lf", &coef);

    result = coef;
    proiz = 0.0;  

    while (scanf("%lf", &coef) != EOF){

        result = result * x + coef; 
        proiz = proiz * x + result; 
        
    }
    
    printf("%.10g\n", result); 
    printf("%.10g\n", proiz);

    return 0;
}
