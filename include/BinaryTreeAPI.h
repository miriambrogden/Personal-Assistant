#ifndef BINARYTREEAPI_H
#define BINARYTREEAPI_H

//typedefs of function pointers
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

//Definition of a TreeNode
typedef struct binTreeNode TreeNode;
struct binTreeNode{
	void * data;
	TreeNode * left;
	TreeNode * right;
};

//Definition of a binary tree
typedef struct binTree
{
	TreeNode *root;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;
} Tree;

/*
Function: Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
@param: data - the data to be stored within the Node.
@return: Newly created TreeNode
 */
TreeNode* createTreeNode(void * data);

/*
Function: createBinTree allocates memory for Tree and assigned function pointers
@param:  compare [Function pointer to Compare data in tree nodes]
@param:  del     [Function pointer to delete data from node]
@return: Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del);

/*
Function: destroyBinTree - remove all items and free memory
@param:  toDestroy - the tree
@return: none
*/
void  destroyBinTree(Tree * toDestroy);

/*
Function: used to destroy singular nodes - reccursively called inside of destroyBinTree Function
@param: node to destroy
@return: none
*/
void destroyNodesInBinTree(void * theCurr);

/*
Function: Add data to a tree
@param: theTree
@param: data
*/
void addToTree(Tree * theTree, void * toBeAdded);

/*
Function: get the parent of a node in a binary tree
@param: theTree you are searching in
@param: the root of the tree
@param: the data you are getting the parent of (treeNode)
@param: the root of the tree (recursive calls change this value);
@return: a pointed to a node of type TreeNode
*/
void * getParent(Tree* theTree, void * root, void * data, void * prev);

/*
Function: Remove data from the tree
@param: theTree
@param: data to be removed (treeNode)
@return: none
*/
void removeFromTree(Tree * theTree, void * data);

/*
Function: This function searches the tree for the target data
@param: theTree to search
@param: data to find (TreeNode);
@return: NULL if fail, otherwise return data (TreeNode)
*/
void * findInTree(Tree* theTree, void * data);

/*
Function: This function is called in findInTree function and is called reccursively
@param: theTree to search
@param: the root of the tree
@param: the TreeNode you are searching for
@return: NULL if fail, otherwise return data (TreeNode)
*/
void * findNodeInTree(Tree* theTree, void * root, void * data);

/*
Function: find the minimum node branching from a specified tree node
@param: specified TreeNode
@return: minimum TreeNode
*/
void * findMinimum(TreeNode * root);

/*
Function: Get data from the root of the Tree if it exists.
@param: theTree
@return: NULL if tree is empty, otherwise return root
*/
void * getRootData(Tree * theTree);

/*
Function: This function prints the tree using an inOrder traversal
@param: theTree
@param: print function to be used to print the data
@return: none
*/
void printInOrder(Tree * theTree, PrintFunc printData);

/*
Function: reccursive function to be called in printInOrder function
@param: node to be printed
@param: print function
@return: none
*/
void printNodeInOrder(void * curr, PrintFunc printData);

/*
Function: This function prints the tree using an PreOrder traversal
@param: theTree
@param: print function to be used to print the data
@return: none
*/
void printPreOrder(Tree * theTree, PrintFunc printData);

/*
Function: reccursive function to be called in printPreOrder function
@param: node to be printed
@param: print function
@return: none
*/
void printNodePreOrder(void * theCurr, PrintFunc printData);

/*
Function: This function prints the tree using an PostOrder traversal
@param: theTree
@param: print function to be used to print the data
@return: none
*/
void printPostOrder(Tree * theTree, PrintFunc printData);

/*
Function: reccursive function to be called in printPostOrder function
@param: node to be printed
@param: print function
@return: none
*/
void printNodePostOrder(void * theCurr, PrintFunc printData);

/*
Function: Checks if a tree is empty
@param: theTree
@return: 1 if not empty, 0 if empty
*/
int isTreeEmpty(Tree* theTree);

/*
Function: Helper function for checking if a single node has no children
@param: treeNode to check
@return: 0 if false, 1 otherwise
 */
int isLeaf(TreeNode * treeNode);

/*
Function: Helper function for checking if a single node has two children
@param: treeNode to check
@return: 1 if has two children, 0 otherwise
*/
int hasTwoChildren(TreeNode *treeNode);

/*
Function: Helper funciton to get the height of a particular Node in the tree.
@param: treeNode to get height of
@return: height of the node (1-based).
*/
int getHeight(TreeNode* treeNode);

#endif
