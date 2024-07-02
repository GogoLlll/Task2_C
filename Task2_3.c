#include <stdio.h>
#include <time.h>

int fibonacciIterative(int n){

    if (n <= 1) return n;

    int prev_before = 0;
    int prev = 1;
    int current = 0;

    for (int i = 2; i <= n; ++i){

        current = prev + prev_before;
        prev_before = prev;
        prev = current;

    }

    return current;
}

int fibonacciRecursive(int n){

    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);

}

int main() {

    int i;
    clock_t start, end;
    double finish_time;

    while (scanf("%d", &i) != EOF){

        start = clock();
        int iterativeResult = fibonacciIterative(i);
        end = clock();
        finish_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Итеративное (%d): %d. Время: %f сек.\n", i, iterativeResult, finish_time);

        start = clock();
        int recursiveResult = fibonacciRecursive(i);
        end = clock();
        finish_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Рекурсивное (%d): %d. Время: %f сек.\n", i, recursiveResult, finish_time);
        
    }

    return 0;

}