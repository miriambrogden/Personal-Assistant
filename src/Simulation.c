#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTreeAPI.h"
#include "Rule.h"
#include "LinkedListAPI.h"
#include "Simulation.h"

void toLower (char * string){
    for (int i = 0; i<strlen(string); i++){
        string[i] = tolower(string[i]);
    }
}

void discuss(Tree * theTree, char * question, List * ruleList){
    removePunc(question);
    toLower(question);
    int num = getNumberOfWords(question);
    char * words [100];
    double importance[100];
    char * token;
    token = strtok(question, " ");
    for (int i= 0; i<num; i++){
        words[i] = malloc(strlen(token) + 1);
        strcpy(words[i], token);
        token = strtok(NULL, " ");
    }
    for (int j = 0; j<num; j++){
        ruleNode * RN5 = createRule(0, words[j], "", 0, 0);
        TreeNode * TN5 = createTreeNode(RN5);
        TreeNode * found = findInTree(theTree, TN5);
        if (found != NULL){
            ruleNode * foundData = (ruleNode*)(found->data);
            importance[j] = foundData->userRating + foundData->systemRating;
        } else {
            importance[j] = -1;
        }
    }
    int temp = -1;
    int index = -1;
    for (int k = 0; k<num; k++){
        if (importance[k] > temp){
            index = k;
            temp = importance[k];
        }
    }
    if (index != -1){
        ruleNode * RN6 = createRule(0, words[index], "", 0, 0);
        TreeNode * TN6 = createTreeNode(RN6);
        TreeNode * important = findInTree(theTree,TN6);
        if (important != NULL){
            ruleNode * importantData = (ruleNode*)(important->data);
            printf("%s\n", importantData->convo);
            importantData->count = importantData->count + 1;
            Node * theNode = findInList(ruleList, importantData->keyword);
            ruleNode * theNodeData = (ruleNode *)(theNode->data);
            theNodeData->count = importantData->count;
            getFeedback(importantData, ruleList);
        }
    } else {
        printf("I don't even know how to respond to that!\n");
    }
}


void getFeedback(ruleNode * data, List * ruleList){
    double learningRate = 0.05;
    char answer[100];
    while ((strcmp("y", answer) != 0) && (strcmp("n", answer) != 0)){
        printf("Was this feedback helpful? Enter 'y' or 'n': ");
        fgets(answer, 100, stdin);
        removeNewline(answer);
        if (strcmp("y", answer) == 0){
            data->systemRating = data->systemRating + (data->systemRating * learningRate/data->count);
            Node * theNode = findInList(ruleList, data->keyword);
            ruleNode * theNodeData = (ruleNode *)(theNode->data);
            theNodeData->systemRating = data->systemRating;
            printf("Thank you for your feedback\n");
        } else if (strcmp("n", answer) == 0){
            data->systemRating = data->systemRating - (data->systemRating * learningRate/data->count);
            Node * theNode = findInList(ruleList, data->keyword);
            ruleNode * theNodeData = (ruleNode *)(theNode->data);
            theNodeData->systemRating = data->systemRating;
            printf("Thank you for your feedback\n");
        }
    }
}

int getNumberOfWords(char * string){
    int numWord = 0;
    int i = 0;
    for (i=0; i<strlen(string); i++) {
        if ((isalpha(string[i]) && isspace(string[i-1])) || (isalpha(string[i]) && i == 0)) {
           numWord++;
        }
    }
return numWord;
}

void removePunc(char * string){
    int i = 0;
    for(i=0; i<strlen(string); i++){
        if (ispunct(string[i])){
            string[i] = ' ';
        }
        if (isdigit(string[i])){
            string[i] = ' ';
        }
    }
}


void printMenu(){
    printf("\n");
    printf("1. Add a new rule\n");
    printf("2. Remove a rule\n");
    printf("3. Display rules\n");
    printf("4. Modify rule rating\n");
    printf("5. Discuss\n\n");
    printf("9. Quit\n");
}

int checkString(char * string){
    for (int i = 0; i < strlen(string); i++){
        if (string[i] == ' ') {
            return 1;
        }
    }
    for (int i = 0; i < strlen(string); i++){
        if (!isalpha(string[i])){
            return 1;
        }
    }
    return 0;
}

void removeNewline(char line[]){
    if(line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = '\0';
    }
}

int getInt(char* prompt, char max){
    char userInt[100] = "";
    int flag = 1;
    int ascii = 0;
    int maxAscii = (int)(max);
    int zero = (int)('0');
    while(flag != 0){
        flag = 0;
        printf("%s", prompt);
        fgets(userInt, 100, stdin);
        removeNewline(userInt);
        if (strcmp(userInt, "") == 0){
            flag ++;
        }
        if (max != '0'){
            ascii = (int)(userInt[0]);
            if (ascii > maxAscii || ascii == zero){
                flag++;
            }
        }
        for (int j = 0; j<strlen(userInt); j++){
            if (!isdigit(userInt[j])){
                flag++;
            }
        }
        if (flag > 0){
            printf("Error! ");
        }
    }
    int numInts = atoi(userInt);
    return numInts;
}

Node * findInList(List * theList, char * string){
    Node * theCurr = theList->head;
    while (theCurr != NULL){
        ruleNode * data = (ruleNode *)(theCurr->data);
        if (strcmp(data->keyword, string) == 0){
            return theCurr;
        } else {
            theCurr = theCurr->next;
        }
    }
    return NULL;
}
