#include <stdio.h>
#include <stdlib.h>

int leap_year(int year){
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char **argv){
    int i, n;
    i = atoi(argv[1]);
    n = atoi(argv[2]);
    for (i = atoi(argv[1]); i <= n; i++){
        if (leap_year(i)){
            printf("%d\n", i);
        }
    }

    return 0;
}