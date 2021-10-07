#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>
#include "command.c"
#include "utility.c"

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

int main (int argc, char ** argv) {
    char buf[MAX_BUFFER];                   // line buffer
    char ** args;
	char * arg[MAX_ARGS];                           // working pointer arg strings
    char * prompt = " >" ;                  // shell prompt
	char new_path[MAX_ARGS];				//create new path string
	char CWD[MAX_ARGS];						//create CWD string

	strcat(CWD, getcwd(buf, MAX_BUFFER)); 	// push path of CWD to empty CWD string
	strcat(new_path, "PATH="); 	//push "PATH=" to empty new_path string
	strcat(new_path, CWD); 	// merge new_path string to CWD string 
	strcat(new_path, "/myshell");
	setenv("PATH", new_path, 1); 	//set environment of merged string i.e "PATH=path_of_current_working_directory
	setenv("SHELL", "/myshell", 1); 	//create Shell environment and set enviroment to /myshell
	
	char *listofcommands[] = { //Needed to prevent error of crashing if input was not a command
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

    while (!feof(stdin)) { /* keep reading input until "quit" command or eof of redirected input */
		
		getcwd(buf, MAX_BUFFER); // get current working directory
		
    
		printf ("%s", buf); //print current working directory 
        fputs (prompt, stdout); // write prompt
        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line

			args = line_split(buf); //pass command line through line_split to tokenize the input
            
            		
		if (!strcmp(args[0], "myshell")) { //if arg[0] = "myshell" initiate batch mode
		
		FILE *fptr = fopen(args[1], "r"); //open file which has args[1] as file name
		
		char *line = calloc(MAX_ARGS, sizeof(char*)); 
		char ** command;
		
		while (fgets(line, 200, fptr)) { // while getting lines from pointer file
			printf("\n%s", line); //print tokenized input from file
			command = line_split(line); // let command variable = tokenized input
			command_exe(command); //use execute_command function to execute commands
		}
		
		fclose(fptr); //close files
		
		}
		
		else if (!strcmp(args[0], "environ")){
		environment_command();
		}
		
		for(int x=0; x < sizeof(command_help) / sizeof(char *); x++) 
		if (!strcmp(args[0], listofcommands[x])){ //if args[0] is contained within our list of commands do  
				command_exe(args); //execute command function and pass args
				continue; //continue loop
			}
    }
	}
	return 1;
}
