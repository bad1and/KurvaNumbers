#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <signal.h>

long long maxnum = 4294967296; //2^32
int count = 0;

// ростое число
bool is_prime(long long num) {
    if (num == 1 || num == 2) {
        return true;
    }
    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// добавление к чисоам 1379
void generate_numbers(char *str) {
    long long num = atoll(str);
    if (num >= maxnum || !is_prime(num)) {
        return;
    }
    count++;
    printf("\n%lld",num);

    char next_str[21];
    snprintf(next_str, sizeof(next_str), "%s1", str); //число в формат строку
    generate_numbers(next_str);
    snprintf(next_str, sizeof(next_str), "%s3", str);
    generate_numbers(next_str);
    snprintf(next_str, sizeof(next_str), "%s7", str);
    generate_numbers(next_str);
    snprintf(next_str, sizeof(next_str), "%s9", str);
    generate_numbers(next_str);
}

void handle_error(int sig) {
    printf("\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        maxnum = atoll(argv[1]); // в инт
    } else {
        system("clear");
        printf("Лимит установлен по умолчанию: %lld\n", maxnum);
    }

    signal(SIGSEGV, handle_error);

    clock_t start_time = clock();

    //нач простые числа
    generate_numbers("1");
    generate_numbers("2");
    generate_numbers("3");
    generate_numbers("5");
    generate_numbers("7");

    printf("\nНайдено простых чисел: %d\n", count);

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Время выполнения: %.6lf секунд\n", elapsed_time);

    return 0;
}
