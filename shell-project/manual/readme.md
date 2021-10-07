# Brendan Simms, 19500949 - MyShell

Using the shell:

	List of Supported commands:
		
		-- 'clr' which can be used to clear the screen
		
		--'quit' can be used to exit the terminal
		
		--'dir' used to list the enviroment strings
		
		--'environ' used to list all environment strings
		
		--'date' displays the current system date and time
		
		--'cd' <directory> this can be used to change the CWD of the teminal to the second supplied argument
		
		--'pause' Pauses the shell and returns to running when Enter is pressed
		
		--'echo' prints out the arguments following it to the terminal
		
		--'help' used to get a list of avaliable commands, when used help <command> lists out instructions ffor how <command> works
		
		
	Batchfile: 
	
		-- My shell contains Batchffile but it does have it's limitations. To activate Batchfile in the cmd of your system simply type /myshell <batchfile>
		
		--This should run each command in the file one by one but certain commands cause this to break like echo.
		
	
	Enviroment Concepts:
	
		--The 'enviroment' is an array of strings that are made avaliable to the processes. This is important when you are talking about child processes as they recieve the enviroment strings when a process is forked
		unfortunately I was unable to code this but it becomes particullarly necessary for enviromeent strings to be passed to child process to ensure that the Child process also has the CWD assigned to it.
		
	Processes:
	
		--When a system runs a program this is known as a process, as mentioned when talking about enviroment strings, forking exists in c and this splits the process into a parent and child process that run similatniously.
	
	Extra Commands 
	
		-- my extra command is 'date', this add the ability for any user of the shell to have the date and time of their system printed out on screen so it is readily avaliable to them whule they are working on the shell.
		
	I/O Redirection:
	
		-- I was unable to figure out I/O redirection but it can be particullary useful when wishing to store data on the actions carried out in the shell as you can pass the output to a txt file.