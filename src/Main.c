#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTreeAPI.h"
#include "Rule.h"
#include "LinkedListAPI.h"
#include "Simulation.h"

int main(int argc, char ** argv){
    //open file and check for contents
    FILE * fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        printf("Error opening file!\n");
    } else {
        int size = 0;
        fseek(fptr, 0, SEEK_END);
        size = ftell(fptr);
        if (size == 0){
            printf("File has no contents!\n");
        } else {
            fseek(fptr, 0, SEEK_SET);
            char buffer[1000];
            char keyword[1000];
            char sentence[1000];

            List * ruleList = initializeList(printRuleNode, deleteListNode, compare);

            int line = 0;
            strcpy(keyword, "");
            strcpy(sentence, "");
            //first line is a keyword, next line is a sentence
            while (fgets(buffer,1000,fptr) != NULL){
                removeNewline(buffer);
                if (line == 0){
                    strcpy(keyword, buffer);
                    line = 1;
                } else if (line == 1){
                    strcpy(sentence, buffer);
                    line = 0;
                }
                if ((strcmp(sentence, "")!= 0) && (strcmp(keyword, "") != 0)){
                    //add data from file to a linked list
                    toLower(keyword);
                    ruleNode * aRule = createRule(0.5, keyword, sentence, 0.5, 0);
                    Node * theNode = initializeNode(aRule);
                    insertFront(ruleList, theNode);
                    strcpy(sentence, "");
                    strcpy(keyword, "");
                }
            }
            Node * N1 = ruleList->head;
            Tree * theTree = createBinTree(compareRule, deleteRule);
            //add linked list data from the file, to a binary tree
            while (N1 != NULL){
                ruleNode * data = (ruleNode*)(N1->data);
                ruleNode * RN1 = createRule(0.5, data->keyword, data->convo, 0.5, 0);
                TreeNode * TN1 = createTreeNode(RN1);
                addToTree(theTree, TN1);
                N1 = N1->next;
            }

            int menuOp = 0;
            char newKeyword[1000];
            char newSentence[1000];
            char newUSWord[100];
            double newUS;
            //start the command line to give users options
            while (menuOp != 9){
                printMenu();
                menuOp = getInt("Please enter a menu option: ", '9');
                //add a rule
                if (menuOp == 1){
                    //keyword can only contain letters
                    do {
                        printf("Please enter a keyword: ");
                        strcpy(newKeyword, "");
                        fgets(newKeyword, 1000, stdin);
                        removeNewline(newKeyword);
                    } while (checkString(newKeyword) == 1);

                        strcpy(newSentence, "");
                        printf("Please enter a sentence: ");
                        fgets(newSentence, 1000, stdin);
                        removeNewline(newSentence);

                        //user rating must be between 0 and 1
                    do {
                        printf("Please enter a user rating: ");
                        strcpy(newUSWord, "");
                        fgets(newUSWord, 1000, stdin);
                        sscanf(newUSWord, "%lf", &newUS);
                    } while (newUS > 1 || newUS < 0);

                    toLower(newKeyword); //make sure keyword is case insensitive
                    ruleNode * RN2 = createRule(newUS, newKeyword, newSentence, newUS, 0);
                    TreeNode * TN2 = createTreeNode(RN2);
                    //make sure the keyword doesn't already exist
                    if (findInTree(theTree, TN2) == NULL){
                        //add it to the linked list and the binary tree
                        Node * N2 = initializeNode(RN2);
                        insertFront(ruleList, N2);
                        addToTree(theTree, TN2);
                    } else {
                        printf("Sorry, there is already rule with that keyword\n");
                    }
                }
                //remove a rule
                if (menuOp == 2){
                    do {
                        printf("Please enter a keyword to delete: ");
                        strcpy(newKeyword, "");
                        fgets(newKeyword, 1000, stdin);
                        removeNewline(newKeyword);
                    } while (checkString(newKeyword) == 1);

                    toLower(newKeyword); // case insensitive
                    //check if it is in the tree
                    Node * toDelete = findInList(ruleList, newKeyword);

                    if (toDelete != NULL){
                        destroyBinTree(theTree);
                        theTree = NULL;
                        deleteNodeFromList(ruleList, toDelete);
                        theTree = createBinTree(compareRule, deleteRule);
                        Node * N4 = ruleList->head;
                        while (N4 != NULL){
                            ruleNode * data4 = (ruleNode*)(N4->data);
                            ruleNode * RN4 = createRule(data4->userRating, data4->keyword, data4->convo, data4->systemRating, data4->count);
                            TreeNode * TN4 = createTreeNode(RN4);
                            addToTree(theTree, TN4);
                            N4 = N4->next;
                        }
                        printf("The rule was successfully deleted\n");
                    } else {
                        printf("Sorry, that keyword does not exists\n");
                    }
                }
                //display all rules
                if (menuOp == 3){
                    printInOrder(theTree, printTreeNode);
                }
                //update user rating of a rule
                if (menuOp == 4){
                    do {
                        printf("Please enter a keyword to update: \n");
                        strcpy(newKeyword, "");
                        fgets(newKeyword, 1000, stdin);
                        removeNewline(newKeyword);
                    } while (checkString(newKeyword) == 1);
                    toLower(newKeyword);
                    ruleNode * RN3 = createRule(0, newKeyword, "", 0, 0);
                    TreeNode * TN3 = createTreeNode(RN3);
                    TreeNode * found = findInTree(theTree, TN3);
                    if (found != NULL){
                        printTreeNode(found);
                        printf("\n");
                        do {
                            printf("Please enter a new user rating: \n");
                            strcpy(newUSWord, "");
                            fgets(newUSWord, 1000, stdin);
                            sscanf(newUSWord, "%lf", &newUS);
                        } while (newUS > 1 || newUS < 0);
                        ((ruleNode*)(found->data))->userRating = newUS;
                        Node * theCurr = findInList(ruleList, newKeyword);
                        if (theCurr != NULL){
                            ((ruleNode *)(theCurr->data))->userRating = newUS;
                        }
                        printf("The rating was successfully updated\n");
                    } else {
                        printf("Sorry, the keyword was not found\n");
                    }
                }
                //discuss
                if (menuOp == 5){
                    char question[1000];
                    printf("What is your question? \n");
                    fgets(question, 1000, stdin);
                    removeNewline(question);
                    discuss(theTree, question, ruleList);
                }
                //these are not menu options
                if (menuOp == 6 || menuOp == 7 || menuOp == 8){
                    printf("Error! ");
                }
            }
        }
    }
    return 0;
}
