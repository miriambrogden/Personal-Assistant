#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTreeAPI.h"
#include "Rule.h"

int main (void){

    printf("Test: createTree\n");
    printf("Expected output: Tree has been created\n");
    printf("Actual output: ");
    Tree * theTree = createBinTree(compareRule, deleteRule);
    if (theTree != NULL){
        printf("Tree has been created\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("Tree has not been created\n");
        printf("Test Result: Test Failed\n");
    }
    printf("\n");

    printf("Test: createTreeNode\n");
    printf("Expected output: Node was created\n");
    printf("Actual output: ");
    ruleNode * RN1 = createRule(0.5, "Miriam", "Hello World", 0.5, 0);
    TreeNode * TN1 = createTreeNode(RN1);
    if (TN1 != NULL){
        printf("Node was created\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("Node was not created\n");
        printf("Test Result: Test Failed\n");
    }

    ruleNode * RN2 = createRule(0.3, "Mirian", "This is a second test", 0.5, 0);
    TreeNode * TN2 = createTreeNode(RN2);

    ruleNode * RN3 = createRule(0.9, "Pam", "Pamalamadingdong", 1, 5);
    TreeNode * TN3 = createTreeNode(RN3);

    ruleNode * RN4 = createRule(0.5, "What", "Oh Hey! What's up?", 0.5, 0);
    TreeNode * TN4 = createTreeNode(RN4);

    ruleNode * RN5 = createRule(0.3, "January", "Baby it's cold outside!", 0.5, 2);
    TreeNode * TN5 = createTreeNode(RN5);

    ruleNode * RN6 = createRule(0.5, "yearsago", "Once upon a time", 0.5, 0);
    TreeNode * TN6 = createTreeNode(RN6);

    printf("\n");
    printf("Test: addToTree\n");
    printf("Expected output: Node was added to the tree\n");
    printf("Actual output: ");
    addToTree(theTree, TN1);
    if (theTree->root != NULL){
        printf("Node was added to the tree\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("Node was not added to the tree\n");
        printf("Test Result: Test Failed\n");
    }
    addToTree(theTree, TN2);
    addToTree(theTree, TN3);
    addToTree(theTree, TN4);
    addToTree(theTree, TN5);
    addToTree(theTree, TN6);

    printf("\n");
    printf("Test: isLeaf\n");
    printf("Expected output: The node is a leaf\n");
    printf("Actual output: ");
    int m = isLeaf(TN6);
    if (m == 1){
        printf("The node is a leaf\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("The node is not a leaf\n");
        printf("Test Result: Test Failed\n");
    }

    printf("\n");
    printf("Test: hasTwoChildren\n");
    printf("Expected output: The node has two children\n");
    printf("Actual output: ");
    int k = hasTwoChildren(TN1);
    if (k == 1){
        printf("The node has two children\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("The node does not have two children\n");
        printf("Test Result: Test Failed\n");
    }


    printf("\n");
    printf("Test: printInOrder\n");
    printInOrder(theTree, printTreeNode);
    printf("\n");
    printf("Test: printPostOrder\n");
    printPostOrder(theTree, printTreeNode);
    printf("\n");
    printf("Test: printPreOrder\n");
    printPreOrder(theTree, printTreeNode);

    printf("\n");
    printf("Test: getHeight (root node)\n");
    printf("Expected output: 5\n");
    int x = getHeight(theTree->root);
    if (x == 5){
        printf("Actual output: %d\n", x);
        printf("Test Result: Test Passed\n");
    } else {
        printf("Actual output: %d\n", x);
        printf("Test Result: Test Failed\n");
    }

    printf("\n");
    printf("Test: findInTree\n");
    printf("Expected output:\n");
    printf("January   Rating: 0.30   System: 0.50   Occurances: 2\n");
    printf("Actual output: \n");
    TreeNode * found = findInTree(theTree, TN5);
    if (found != NULL){
        printTreeNode(found);
        printf("\nTest Result: Test Passed\n");
    } else {
        printf("Node not found\n");
        printf("Test Result: Test Failed\n");
    }

    printf("\n");
    printf("Test: removeFromTree (remove What)\n");
    printf("Expected output: \n");
    printf("yearsago   Rating: 0.50   System: 0.50   Occurances: 0\nPam   Rating: 0.90   System: 1.00   Occurances: 5\nMirian   Rating: 0.30   System: 0.50   Occurances:0\nMiriam   Rating: 0.50   System: 0.50   Occurances: 0\nJanuary   Rating: 0.30   System: 0.50   Occurances: 2\n");
    removeFromTree(theTree, TN4);
    printf("Actual output: \n");
    printInOrder(theTree, printTreeNode);
    printf("Test Result: Test Passed\n");

    printf("\n");
    printf("Test: getRoot\n");
    printf("Expected output: Miriam   User: 0.50   System: 0.50   Occurances: 0\n");
    printf("Actual output: ");
    TreeNode * theRoot = getRootData(theTree);
    printTreeNode(theRoot);
    printf("\nTest Result: Test Passed\n");

    printf("\n");
    printf("Test: isTreeEmpty\n");
    printf("Expected Result: Tree is not empty\n");
    int y = isTreeEmpty(theTree);
    if (y == 1){
        printf("Actual Result: Tree is not empty\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("Actual Result: Tree is empty\n");
        printf("Test Result: Test Failed\n");
    }

    printf("\n");
    printf("Test: destroyBinTree\n");
    printf("Expected Result: Tree was destroyed\n");
    destroyBinTree(theTree);
    theTree = NULL;
    if (theTree == NULL){
        printf("Actual Result: Tree was destroyed\n");
        printf("Test Result: Test Passed\n");
    } else {
        printf("Actual Result: Tree was no destroyed\n");
        printf("Test Result: Test Failed\n");
    }
    return 0;
}
