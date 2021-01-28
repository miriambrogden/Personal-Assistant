Student Name: Miriam Snow
Date: December 2, 2017

Description of the Assignment:
This program simulates a personal assistant. Rules for the personal assistant are recieved through a text file at the beginning of the program, and can also be entered and removed by the user while the program is running. User ratings for rules can also be modified by the user through the menu. All rules are placed in a binary search tree. All rules can be outputed to the user as well as their user rating, system rating and number of occurances. The user can also discuss with the personal assistant and recieve feedback from the program based on the importance of the words they input.

How to Run the Program:
To run the main program, begin by downloading a .txt file with the dictionary information. An example file is in the docs directory. Then, type "make main" into the command line and execute the program by typing "./bin/runme insertpath/filename.txt". For example, to run the program with the file in the docs folder, type "./bin/runme docs/file1.txt". Follow the prompts as they show up on the screen. The main menu will only accept integers 1-5 and 9 to quit.
To run the TestMain.c program, type "make test" then execute the program by typing "./bin/testme".
Type "make clean" to remove all files in the bin directory.

Personalization:
I didn't make any modifications to the personalization of the rules. Rules read from the file have a default system rating and user rating of 0.5. When a rule is added by the user, the system rating is set to the same value as the user rating entered by the user. When rules are added or searched for, the keywords are made all lower case to make rules case insensitive. Learning rate is a constant value of 0.05 throughout the program. Feedback is given by calculating the importance of each word in the sentence (user rating + system rating) and outputting the sentence with the highest keyword importance.

Assumptions or limitations:
File input must have a keyword on a line followed by a sentence on a new line. Keywords must only contain letters. User ratings must be a value between 0 and 1.
