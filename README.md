# CShell
Unix style shell written in C

Download project and run main.c, to enter C Shell. 

tish>> is prompt and will continually prompt user for shell commands and parse
these commands until "bye" is entered. 

Shell keeps a history of past commands entered, and can run commands in foreground 
or background mode by forking child processees and executing built in system commands. 
