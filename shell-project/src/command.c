#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"

char *command_help[] = { //command list for help command
    "help",
    "date",
    "cd",
    "enivron",
    "clr",
    "dir",
    "echo",
    "pause",
    "quit"
};

int clearcommand(){
	printf("\e[1;1H\e[2J");
}

//command to list current environment information
int environment_command(){

    extern char **environ;
    for (int i = 0; environ[i] !=NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("\n");

}

// function used to print current system date and time
int datecommand() { //function for date command

    time_t time_now; //declaring time_t as a variable time_now
    char* date_string;

    time_now = time(NULL); // obtain current time

    if (time_now == ((time_t)-1))
    {
        printf("Failed to gather information on current time.\n"); //error code in case time cannot be obtained
    }

    date_string = ctime(&time_now); //using time function (ctime) to convert time obtained to a textual representation

    if (date_string == NULL) //if time is unable to convert and still is NULL value
    {
        printf("Failed to convert current time to a textual representation.\n"); // print error code
    }

    printf("The current date and time of system is: %s", date_string); //Print to stdout in system calender format
    return 0; // return to shell after complete instead of return 0 which will exit program
}

//Function to change the directory
int cd_command(char **args) {
    if (args[1] == NULL) {
		fprintf(stderr, "command error: expected second argument to change directory to.\n");
	}
	else {
        if (chdir(args[1]) != 0) {
            perror("command");
		}
	}
  return 0;
}

//prints list of commands avaliable in shell or if second argument is provided returns specific information on the command and how its used
int helpcommand(char **args) { //help command function
    int x;
    if (args[1] == NULL) { //if no secondary argument is provided for help
        for(x; x < sizeof(command_help) / sizeof(char *); x++) {
		printf(" %s\n", command_help[x]);//it prints a list of available commands
	}
        printf("For more information on specific commands enter 'help' followed by the wanted command.\n");
    }
    else { // if a secondary argument is provided the else loop resolves
            if (!strcmp(args[1], "cd")) { //extra information on "cd" command if second argument passed to help is "cd"
                printf("Changes from Current working directory to the secondary argument provided.\n");
            }
            else if (!strcmp(args[1], "help")) { //extra information on "help" command is provided if it is the second argument
                printf("Help command with no other argument provides a list of available commands, use help (other command) to get specific use of individual commands.\n"); }

                else if (!strcmp(args[1], "dir")) { //extra information on "dir" command is provided if it is the second argument
                    printf("Lists the contents of the current working directory.\n"); }

                    else if (!strcmp(args[1], "clr")) { //extra information on "clr" command is provided if it is the second argument
                        printf("Clears screen of all past entry in shell.\n"); }

                        else if (!strcmp(args[1], "echo")) { //extra information on "echo" command is provided if it is the second argument
                            printf("Prints out individual words ignoring whitespace\n"); }

                            else if (!strcmp(args[1], "pause")) { //extra information on "pause" command is provided if it is the second argument
                                printf("Pauses shell until ENTER key is pressed\n"); }

                                else if (!strcmp(args[1], "quit")) { //extra information on "quit" command is provided if it is the second argument
                                    printf("Exits shell with return 0 exit code\n"); }

                                    else if (!strcmp(args[1], "date")) { //extra information on "date" command is provided if it is the second argument
                                        printf("Prints out system clock current date and time\n"); }

                                        else if (!strcmp(args[1], "environ")){ //extra information on "environ" command is provided if it is the second argument
                                            printf("Lists all the environment strings.\n"); }
        }           /* spacing was used between each else if statement for easier reading from third parties */
    return 0;
}

// Code to list all contents of Current Working Directory
int dircommand(){
struct dirent * di;  //pointer for directory
    DIR *directory = opendir("."); //returning a pointer of DIR type

    if (directory == NULL)  // if opening directory returns nothing
    {
        printf("Directory could not be opened at this time." ); // Error code is printed
    }

    while ((di = readdir(directory)) != NULL) //readdir() used to open the pointer to the directory created above and lists out the directories contents // //While loop occurs while directory is not empty/unreadable
            printf("%s\n", di->d_name); //prints names of directory files

    closedir(directory); //closes the director of that pointer
    return 0;
}


//Code to print arguments following echo command while ignoring white space
int echocommand(char ** args){  //echo command function
    for (int y = 1; args[y]; y++) { // for loop that continues for every arg provided to the echo command{
        printf("%s ", args[y]);     //prints each argument as a string
    }
    printf("\n");   //new line printed at the end of output
    return 0;
}

//Function to pause shell until enter is pressed
int pausecommand() { //pause command function
    printf("Press Enter to continue.");
    getchar(); //pauses until enter is pressed
    return 0;
}
//quit command
int quitcommand() {
	exit(0);
}

// function for carrying out shell command
int command_exe(char *args[]){


    char * command[] = { 
	"clr", 
	"quit", 
	"help", 
	"dir", 
	"environ", 
	"echo", 
	"cd", 
	"pause", 
	"date"}; 	// List of all avaliable command calls
    
	int (*functions[]) (char **) = { 
	&clearcommand, 
	&quitcommand, 
	&helpcommand,
	&dircommand, 
	&environment_command, 
	&echocommand, 
	&cd_command, 
	&pausecommand, 
	&datecommand}; // command functions called in relation to the command call list
    
    //if input matches command invocation, execute command.
    for (int z = 0; command[z]; z++) //for int z in commands list, z++
    {

        if (!strcmp(args[0], command[z])) //if argument = any on the list of command
        {
          return (*functions[z])(args); //return function z and pass args to it
        }
}
}
