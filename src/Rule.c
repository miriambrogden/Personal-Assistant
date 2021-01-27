#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTreeAPI.h"
#include "Rule.h"
#include "LinkedListAPI.h"

ruleNode * createRule(double userRating, char* keyword, char * convo, double systemRating, int count){
    ruleNode * RN1 = malloc(sizeof(ruleNode));
    RN1->userRating = userRating;
    RN1->systemRating = systemRating;
    RN1->keyword = malloc(sizeof(char)*1000);
    strcpy(RN1->keyword, keyword);
    RN1->convo = malloc(sizeof(char)*1000);
    strcpy(RN1->convo, convo);
    RN1->count = count;
    return RN1;
}

void printTreeNode(void * theData){
    TreeNode * adata = (TreeNode *)(theData);
    ruleNode * data = (ruleNode*)(adata->data);
    printf("%s   ", data->keyword);
    printf("Rating: %.2lf   ", data->userRating);
    printf("System: %.2lf   ", data->systemRating);
    printf("Occurances: %d", data->count);
}

void printRuleNode(void * aData){
    ruleNode * data = (ruleNode*)(aData);
    printf("%s   ", data->keyword);
    printf("Rating: %.2lf   ", data->userRating);
    printf("System: %.2lf   ", data->systemRating);
    printf("Occurances: %d\n", data->count);
}


int compareRule(const void* a, const void* b){
    TreeNode * toBeAddedNode = (TreeNode *)(a);
    TreeNode * keywordNode = (TreeNode *)(b);
    ruleNode * toBeAddedRule = (ruleNode *)(toBeAddedNode->data);
    ruleNode * keywordRule = (ruleNode*)(keywordNode->data);
    char * toAdd = (char*)(toBeAddedRule->keyword);
    char * keyword = (char *)(keywordRule->keyword);
    return strcmp(toAdd, keyword);
}

void deleteRule(void* data){
}

int compare(const void *first,const void *second){
    return 0;
}

void printNode(void *toBePrinted){
}

void deleteListNode(void *toBeDeleted){
}
