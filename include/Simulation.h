#ifndef SIMULATION_H
#define SIMULATION_H

/*
Function: print out the menu options to the userRating
@param: none
@return: none
*/
void printMenu();

/*
Function: check to see if a string is all letters
@param: string to check
@return: 1 if invalid string, 0 if all letters
*/
int checkString(char * string);

/*
Function: get integer input from the user
@param: prompt to get user input
@param: character representing maximum value user can enter. set to 0 if not max value
@return: valid integer input from user
*/
int getInt(char* prompt, char max);

/*
Function: remove a new line from a string
@param: string to remove newline from
@return: none
*/
void removeNewline(char line[]);

/*
Function: find a Node in a list based on a string. Node data must be a rule node and contain a keyword
@param: list to find node in
@param: string to find
@return: node found in list, or NULL
*/
Node * findInList(List * theList, char * string);

/*
Function: remove all punctuation in a string and replace it with a space
@param: string to remove punctuation from
@return: none
*/
void removePunc(char * string);

/*
Function: user can discuss with the program by asking a question. The program will then search through the binary tree and provide feedback based on the user's input
@param: tree to search
@param: question provided by the user
@param: list containing nodes containing ruleNode data
@return: none
*/
void discuss(Tree * theTree, char * question, List * ruleList);

/*
Function: get the number of words (separated by spaces) in a line of text
@param: line of text to search
@return: number of words found
*/
int getNumberOfWords(char * string);

/*
Function: prompts the user to provide feedback based on the programs output after answering a question
@param: node used to provide answer to the user
@param: list containing nodes containing ruleNode data
@return: none
*/
void getFeedback(ruleNode * data, List * ruleList);

/*
Function: converts a string to all lowercase letters
@param: string to convert
@return: none
*/
void toLower (char * string);

#endif
