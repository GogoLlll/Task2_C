#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;     
char curlex;       
void getlex(void); 
int expr(void);    
int add(void);    
int mult(void);    
int power();
void error();      


int calculatePower(int base, int exp){
    
    int result = 1;

    for (int i = 0; i < exp; ++i){

        result *= base;

    }

    return result;
}


int main(){

    int result;
    setjmp(begin);

    printf("==>");
    getlex();

    result = expr();

    if (curlex != '\n')
        error();
    printf("\n%d\n", result);
    return 0;

}

void getlex(){

    while ((curlex = getchar()) == ' ');

}

void error(void){

    printf("\nОШИБКА\n");
    while (getchar() != '\n');
    longjmp(begin, 1);

}

int expr(){

    int e = add();

    while (curlex == '+' || curlex == '-'){

        char op = curlex;
        getlex();

        if (op == '+')
            e += add();
        else
            e -= add();

    }

    return e;
}

int add(){

    int a = power();

    while (curlex == '*' || curlex == '/'){

        char op = curlex;
        getlex();
        int b = power();

        if (op == '*')
            a *= b;
        else{

          if (b == 0){
            printf("\nДеление на ноль!\n");
            error();

          }
          
          else{

            a /= b;

          }
        }
            
    }

    return a;
}

int power(){

    int base = mult();

    while (curlex == '^'){

        getlex();
        int exp = power();

        if (exp < 0){

            printf("\nОшибка: Возведение в отрицательную степень\n");
            error();

        }
        else{

            base = calculatePower(base, exp);
        
        }

    }

    return base;
}


int mult(){

    int m;

    switch (curlex)
    {
    case '0': case '1': case '2': case '3': case '4':  case '5':
    case '6': case '7': case '8': case '9': 
        m = curlex - '0'; 
        break;
    case '(':
        getlex(); 
        m = expr();
        if (curlex == ')') 
            break;
    default: 
        error();
    }

    getlex();
    return m;

}