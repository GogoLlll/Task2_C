#include <stdio.h>

int main(){
    
    double x, coef, result = 0, proiz= 0, integral = 0;
    int n, stepen;

    printf("Введите степень многочлена: " );
    scanf("%d", &n);

    printf("Введите значение x: " );
    scanf("%lf", &x);

    printf("Введите последовательность: " );
    scanf("%lf", &coef);

    
    stepen = n + 1;
    result = coef;
    proiz = 0.0;


    while (scanf("%lf", &coef) != EOF){

        result = result * x + coef; 
        proiz = proiz * x + result; 
        
    }

    double dx = x / 1000.0;
    double integral_value = 0.0;

    for (double i = 0; i < x; i += dx){
        
        double timely_i = 0.0;
        double x_value = i;

        for (int j = 0; j <= n; j++){

            scanf("%lf", &coef);
            timely_i = timely_i * x_value + coef;

        }

        integral_value += timely_i * dx;

    }

    printf("%.10g\n", result); 
    printf("%.10g\n", proiz); 
    printf("%.10g\n", integral_value); 

    return 0;
}