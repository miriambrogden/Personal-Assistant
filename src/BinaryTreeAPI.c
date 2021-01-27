#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTreeAPI.h"

TreeNode* createTreeNode(void * data){
    TreeNode * TN1 = malloc(sizeof(TreeNode));
    TN1->left = NULL;
    TN1->right = NULL;
    TN1->data = data;
    return TN1;
}

Tree * createBinTree(CompareFunc compare, DeleteFunc del){
    Tree * T1 = malloc(sizeof(Tree));
    T1->root = NULL;
    T1->compareFunc = compare;
    T1->deleteFunc = del;
    return T1;
}

void addToTree(Tree * theTree, void * toBeAdded){
    int x;
    int run = 1;
    int y;
    if (theTree->root == NULL){
        theTree->root = toBeAdded;
    } else {
        TreeNode * curr = theTree->root;
        while (run == 1){
            x = theTree->compareFunc(curr, toBeAdded);
            if (x < 0){
                if (curr->left != NULL){
                    curr = curr->left;
                } else {
                    run = 2;
                }
            }
            else if (x == 0 || x > 0){
                if (curr->right != NULL){
                    curr = curr->right;
                } else {
                    run = 2;
                }
            }
        }
        y = theTree->compareFunc(curr, toBeAdded);
        if (y < 0){
            curr->left = toBeAdded;
        } else if (y > 0 || y == 0){
            curr->right = toBeAdded;
        }
    }
}

void printInOrder(Tree * theTree, PrintFunc printData){
    TreeNode * root = theTree->root;
    if (root != NULL){
        printNodeInOrder(root, printData);
    } else {
        printf("Sorry, the tree is Empty\n");
    }
}

void printNodeInOrder(void * theCurr, PrintFunc printData){
    TreeNode * curr = (TreeNode *)(theCurr);
    if (curr->left != NULL){
		printNodeInOrder(curr->left, printData);
	}
    if (curr != NULL){
	    printData(curr);
        printf("\n");
    }
	if (curr->right != NULL){
		printNodeInOrder(curr->right, printData);
	}
}

void printNodePreOrder(void * theCurr, PrintFunc printData){
    TreeNode * curr = (TreeNode *)(theCurr);
    if (curr != NULL){
	    printData(curr);
        printf("\n");
    }
    if (curr->left != NULL){
		printNodePreOrder(curr->left, printData);
	}
	if (curr->right != NULL){
		printNodePreOrder(curr->right, printData);
	}
}

void printPreOrder(Tree * theTree, PrintFunc printData){
    TreeNode * root = theTree->root;
    if (root != NULL){
        printNodePreOrder(root, printData);
    } else {
        printf("Sorry, the tree is Empty\n");
    }
}

void printPostOrder(Tree * theTree, PrintFunc printData){
    TreeNode * root = theTree->root;
    if (root != NULL){
        printNodePostOrder(root, printData);
    } else {
        printf("Sorry, the tree is Empty\n");
    }
}

void printNodePostOrder(void * theCurr, PrintFunc printData){
    TreeNode * curr = (TreeNode*)(theCurr);
    if (curr->left != NULL){
		printNodePostOrder(curr->left, printData);
	}
	if (curr->right != NULL){
		printNodePostOrder(curr->right, printData);
	}
    if (curr != NULL){
        printData(curr);
        printf("\n");
    }
}

void destroyBinTree(Tree * theTree){
    destroyNodesInBinTree(theTree->root);
    free(theTree->root);
    theTree->root = NULL;
}

void destroyNodesInBinTree(void * theCurr){
    TreeNode * root = (TreeNode*)(theCurr);
    TreeNode * curr = (TreeNode*)(theCurr);
    if (curr->left != NULL){
		destroyNodesInBinTree(curr->left);
	}
    if (curr != NULL){
        if (curr != root){
	           free(curr);
        }
    }
	if (curr->right != NULL){
		destroyNodesInBinTree(curr->right);
	}
}

void * findInTree (Tree * theTree, void * data){
    return findNodeInTree(theTree, theTree->root, data);
}

void * findNodeInTree(Tree* theTree, void * root, void * data ){
    TreeNode * curr = (TreeNode*)(root);
    TreeNode * toCheckTNode = (TreeNode*)(data);

    int x;
    if (curr != NULL){
        x = theTree->compareFunc(curr, toCheckTNode);
        if (x < 0){
            return findNodeInTree(theTree, curr->left, toCheckTNode);
        } else if (x > 0){
            return findNodeInTree(theTree, curr->right, toCheckTNode);
        } else if (x == 0){
            return curr;
        }
    }
    return NULL;
}

void * getParent(Tree* theTree, void * root, void * data, void * prev){
    TreeNode * curr = (TreeNode *)(root);
    TreeNode * toFind = (TreeNode*)(data);
    TreeNode * aprev = (TreeNode*)(prev);
    int x;
    if (curr != NULL){
        x = theTree->compareFunc(curr, toFind);
        if (x < 0){
            return getParent(theTree, curr->left, toFind, curr);
        } else if (x > 0){
            return getParent(theTree, curr->right, toFind, curr);
        } else if (x == 0){
            return aprev;
        }
    }
    return NULL;
}

void * getRootData(Tree * theTree){
    if (theTree->root != NULL){
        return theTree->root;
    }
    return NULL;
}

int isTreeEmpty(Tree* theTree){
    if (theTree->root != NULL){
        return 1;
    }
    return 0;
}

int isLeaf(TreeNode * treeNode){
    if (treeNode->right == NULL && treeNode->left == NULL){
        return 1;
    }
    return 0;
}

int hasTwoChildren(TreeNode *treeNode){
    if (treeNode->right != NULL && treeNode->left != NULL){
        return 1;
    }
    return 0;
}

int getHeight( TreeNode* treeNode ){
    if (treeNode == NULL){
        return 0;
    } else {
        int leftHeight = getHeight(treeNode->left);
        int rightHeight = getHeight(treeNode->right);
        if (leftHeight > rightHeight){
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

void removeFromTree(Tree * theTree, void * data){
    TreeNode * curr = (TreeNode *)(data);
    TreeNode * temp = NULL;
    TreeNode * min = NULL;

    if (theTree->root == NULL){
        printf("There were no nodes to be deleted\n");
    } else {
        if (curr->right == NULL && curr->left == NULL){
            TreeNode * parent = getParent(theTree, theTree->root, curr, theTree->root);
            if (parent->right != NULL){
                if (theTree->compareFunc(parent->right, curr) == 0){
                    parent->right = NULL;
                }
            } else if (parent->left != NULL){
                if (theTree->compareFunc(parent->left, curr)== 0){
                    parent->left = NULL;
                }
            }
            free(curr);
            curr = NULL;
        } else if (hasTwoChildren(curr) == 1){
            temp = curr->right;
            min = findMinimum(temp);
            TreeNode * minparent = getParent(theTree, theTree->root, min, theTree->root);
            if (minparent->right != NULL){
                if (theTree->compareFunc(minparent->right, min) == 0){
                    minparent->right = NULL;
                }
            } else if (minparent->left != NULL){
                if (theTree->compareFunc(minparent->left, min)== 0){
                    minparent->left = NULL;
                }
            }
            curr->data = min->data;
            free(min);
            min = NULL;
        } else if (curr->left == NULL || curr->right == NULL){
            if(curr->left == NULL){
                temp = curr->right;
                curr->data = temp->data;
                curr->right = temp->right;
                curr->left = temp->left;
            } else if (curr->right == NULL){
                temp = curr->left;
                curr->data = temp->data;
                curr->right = temp->right;
                curr->left = temp->left;
            }
            free(temp);
        }
    }
}

void * findMinimum(TreeNode * root){
        while (root->left != NULL){
            root = root->left;
        }
    return root;
}
