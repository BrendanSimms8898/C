#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void ArrayToFile(int array[], int size){
FILE * fpoint; //Opens pointer to file}
fpoint = fopen("test1.txt", "wb"); //opens/creates file text for output to be printed to
fwrite(array, sizeof(char), size, fpoint);
fclose(fpoint);
}

int ABC (int argc, char * argv[]){
    int z = atoi(argv[1]); //Variable to = our command line input
    int array[z];
    for (int i =0; i < z; i++) { //starts for loop for every iteration where i < x meaning until i has hit the integer value of our command-line argument
        array[z] = rand() % 1000000;
    }
   ArrayToFile(array, z);
    return 0; //exit status
}

//this program can be used to create an array of up to 500,000 digits and pass that information to a text file, I was unable to figure out a way to further develop this to allow
//this method to be effective in testing sorting algorithim as it lacked a depth to create a large enough sample size for testing so I have decided a different method as will be outlined in my report.
