#ifndef RULE_H
#define RULE_H

//ruleNode struct definition
typedef struct aRuleNode ruleNode;
struct aRuleNode{
	double userRating;
    double systemRating;
    char * keyword;
    char * convo;
    int count;
};

/*
Function: print data inside a ruleNode
@param: ruleNode data
@return: none
*/
void printRuleNode(void * aData);

/*
Function: print ruleNode data given a TreeNode
@param: TreeNode to print
@return: none
*/
void printTreeNode(void * theData);

/*
Function: compare two treeNodes based on the keywords inside of their data
@param: first TreeNode
@param: second TreeNode
@return: value of strcmp of two keywords
*/
int compareRule(const void* a, const void* b);

/*
Function: dummy function - user defined
@param: data to be deleted
@return: none
*/
void deleteRule(void* data);

/*
Function: create a rule with all the data passed in
@param: user rating of rule
@param: keyword of rule
@param: sentence or feedback given when that rule is used
@param: system rating of rule (usually same as user rating)
@param: number of occurances that rule has been used(initially set to 0)
@return: pointer to a ruleNode containing given data
*/
ruleNode * createRule(double userRating, char* keyword, char * convo, double systemRating, int count);

#endif
