#include <stdio.h>

double str2double(char str[]){

    double result = 0.0;
    int sign = 1;
    int decimal = 0;
    int decimalMultiplier = 1;
    int i = 0;

    if (str[i] == '-'){

        sign = -1;
        ++i;

    }

    for (; str[i] != '\0' && str[i] != '.'; ++i){

        if (str[i] >= '0' && str[i] <= '9'){

            result = result * 10 + (str[i] - '0');

        }

    }

    if (str[i] == '.'){

        ++i; 

        for (; str[i] != '\0'; ++i){

            if (str[i] >= '0' && str[i] <= '9'){

                decimal = decimal * 10 + (str[i] - '0');
                decimalMultiplier *= 10;

            }

        }

    }

    result += (double)decimal / decimalMultiplier;
    return result * sign;

}

int main(){

    char str[100];

    while (scanf("%s", str) != EOF){

        double number = str2double(str);
        printf("%.10g\n", number);

    }

    return 0;

}
