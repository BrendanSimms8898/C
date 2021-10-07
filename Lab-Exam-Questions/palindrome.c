#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Palindrome_Check(char string[], char s1[]){
    int ifpalindrome = 1;  /* Value is 1 if it is a palindrome if not assigns 0 */

    int x;
    int y; /*variable for the second array*/

    for(x=0,y=0;string[x] != '\0'; x++)  /*to eliminate spaces, special characters and capital letters from the string*/
    {
        if (isdigit(string[x]) != 0){ /*iterates through input and checks for digit returns error code and exits if digit is present */
            printf("Invalid input: Numbers not permitted.\n");
            return 1;
        }
        if((string[x] < 'A' || string[x] > 'Z' ) && (string[x] < 'a' || string[x] > 'z')) /*eliminates whitespace and special charcters */
            continue;

        else if(string[x] >= 'A' && string[x] <= 'Z' ) /*ensures all letters are non capital*/
            string[x] += 32;

        s1[y] = string[x];
        y++;
    }
    s1[y] = '\0'; /* assigning the last element with null character */

    int u,slen = strlen(s1); /* Storing kength of altered string */

    for(u=0;u<=slen/2;u++) /* starts the loop from first element to the middle element */
    {
        if(s1[u] != s1[slen-u-1]) /*checks if the elements are true */
        {
            ifpalindrome = 0;   /* checks the first  element with the first element from the last and second element with the penultimate element and so on */
            break;
        }
    }

    // at the end you need to test
    if (ifpalindrome)
        printf("This string is a palindrome.\n");
    else
        printf("This string is not a palindrome.\n");

    }

int main()
{
    char string[100];
    char s1[100];//the string without spaces and special characters will be stored in this

    printf("Please enter a string:  \n");
    scanf("%[^\n]", string);

    Palindrome_Check(string, s1); //Runs the palindrome_check function on the two inputs

    return 0;
}
