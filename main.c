#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int startYear;
    int endYear;
} KevinTime;

unsigned long long calcFromZero(int toNum, int a) {
    return (unsigned long long)(toNum / a);
}

unsigned long long calc(int fromNum, int toNum, int a) {
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;

    fromNum--;

    x = calcFromZero(fromNum, a);
    y = calcFromZero(toNum, a);

    z = y - x;

    if(z < 0) {
        return 0;
    }

    return z;
}

unsigned long long getDays(KevinTime time) {
    unsigned long long a;
    unsigned long long b;

    a = time.endYear - time.startYear + 1;
    b = calc(time.startYear, time.endYear, 3) - calc(time.startYear, time.endYear, 48);
    a = a - b;

    return ((42 * a) + (43 * b));
}

int main(int argc, char** argv) {
    int countOfInputs;
    KevinTime* inputs;
    int i;

    scanf("%d", &countOfInputs);

    inputs = malloc(sizeof(KevinTime) * countOfInputs);

    for(i = 0; i < countOfInputs; i++) {
        scanf("%d %d", &inputs[i].startYear, &inputs[i].endYear);
    }

    for(i = 0; i < countOfInputs; i++) {
        printf("%llu\n", getDays(inputs[i]));
    }

    free(inputs);
    inputs = NULL;

    return EXIT_SUCCESS;
}
