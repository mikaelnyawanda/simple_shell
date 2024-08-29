Simple Shell Project Description

This is a command-line interpreter that allows users to interact with the operating system by typing commands. The shell processes user input, executes the corresponding commands, and returns the output to the user. In a simple shell project, you typically implement a basic version of a Unix shell using the C programming language.

Key Features:
Command Execution: The shell reads user input, interprets it, and executes the corresponding command using system calls like execve.
Built-in Commands: Implement some basic commands like cd, exit, and pwd within the shell.
Environment Variables: The shell can access and manipulate environment variables.
Input/Output Redirection: Handle redirection of input and output using symbols like >, <, and |.
Process Management: The shell can manage processes, including handling background processes (&).
Error Handling: Proper error handling for invalid commands or syntax errors.

Built-in Commands
cd (Change Directory)

Usage: cd [directory]
Description: Changes the current working directory to the specified directory.
exit

Usage: exit [status]
Description: Exits the shell with an optional status code.
pwd (Print Working Directory)

Usage: pwd
Description: Prints the current working directory.
echo

Usage: echo [string]
Description: Prints the specified string to the terminal.
env

Usage: env
Description: Prints the environment variables.
