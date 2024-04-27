# # Command Interpreter 
At startup, a prompt is displayed, and the user enters the name and arguments of the program that he wants to run. 
The program allows you to run files that are located in the same directory (`sum` and `max_value`) or that are installed on the system.


## How to use

1. **Compilation of the program:**
- make

2. **Starting the program:**
- ./program 

3. **Usage Examples:**

- If the entered command corresponds to a file in the current directory, the program will execute this file:
Example:  
  `sum 1 2 3 4`      
  or  
  `max_value 12 1 3 33 2`    
- If the entered command does not match the file in the current directory, the program will try to execute it as a standard command:
Example:  
  `ls -l`    
  or  
  `nano`