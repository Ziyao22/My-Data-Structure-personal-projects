#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;
//Ziyao Gao zg8rw 10/07/2020
//AVLTree.cpp
AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    insert(root,x);
    //printTree();
}
void AVLTree::insert(AVLNode*& n, const string& x){
  if(n==NULL){
    n=new AVLNode();
    n->value=x;
  }
  else if(x<n->value){
    insert(n->left,x);
    // balance(n);
  }
  else if(x>n->value){
    insert(n->right,x);
    // balance(n);
  }
  else;
  n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
}
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    // printTree();
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  //printTree();
  return pathTo(root,x);
}
string AVLTree::pathTo(AVLNode* currentNode, const string& x)const{
  if(currentNode==NULL&&currentNode->left==NULL&&currentNode->right==NULL)
    return "";
   if(!find(x))
     return "";
   else if(find(x)&&x==currentNode->value)
      return currentNode->value;
   else if(find(x)&&x<currentNode->value)
      return currentNode->value+" "+pathTo(currentNode->left,x);
   else if(find(x)&&x>currentNode->value)
        return currentNode->value+" "+pathTo(currentNode->right,x);
     else return "";
}
// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(find(root,x)==true){
   return true;
    }
   else return false;
}
bool AVLTree::find(AVLNode* currentNode, const string& x)const{
  if(currentNode==NULL)
    return false;
  else if(x<currentNode->value){
   return  find(currentNode->left,x);
   // return true;                                                              
  }
  else if(x>currentNode->value){
   return  find(currentNode->right,x);
   // return true;    
  }
  else if(x==currentNode->value){
   return true;
  }
  else return false;
}
// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}
int AVLTree::numNodes(AVLNode* currentNode)const{
int n=0;
  if(currentNode==NULL){
    return n;
  }
  else {
    n=numNodes(currentNode->left)+numNodes(currentNode->right)+1;
    return n;
  }
}
// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  // AVLNode* currentNode=new AVLNode()
  if(height(n->left)-height(n->right)<-1){
    // rotateLeft(n);
    //   currentNode->value=n->left->value;
    //if(currentNode->value>n->value){
    if(height(n->right->right)-height(n->right->left)<0){
      n->right=rotateRight(n->right);
      n=rotateLeft(n);
  }
      else
      n=rotateLeft(n);
  }
  //  else rotate
  else if(height(n->left)-height(n->right)>1){
    if(height(n->left->left)-height(n->left->right)>0)
      n=rotateRight(n);
    else{
      n->left=rotateLeft(n->left);
      n=rotateRight(n);
  }
  }
  else;
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode*  newNode=n->right;
  AVLNode*  newNode1=newNode->left;
  // newNode=n->right;
  //newNode1=newNode->left;
  newNode->left=n;
  n->right=newNode1;
  //newNode->left=n;
  // n->right=newNode1;
  //newNode->right=n->right->right;
  //n->right=NULL;
  // newNode->right=n->left;
  //n->height=max(n->left->height,n->right->height)+1;
  // newNode->height=max(newNode->left->height,
  //newNode->right->height)+1;
  n->height=max(height(n->left),height(n->right))+1;
  //n->height=height2(n);
  newNode->height=max(height(newNode->left),height(newNode->right))+1;
  // newNode->height=height2(newNode);
  return newNode;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode*  newNode=n->left;
  AVLNode*  newNode1=newNode->right;
  newNode->right=n;
  n->left=newNode1;
  //newNode1=newNode->right;
  //newNode->right=n;
  // n->left=newNode1;
  // newNode1=newNode->right;
  //n->left=newNode->right;
  //newNode->left=n->left->left;
  //n->left=NULL;
  // n->left=newNode->right;
  //   n->height=max(n->left->height,n->right->height)+1;
  // newNode->height=max(newNode->left->height,
  // newNode->right->height)+1;
  //n->height=max(n->left->height,n->right->height)+1;
  //newNode->height=max(newNode->left->height,newNode->right->height)+1;
  n->height=max(height(n->left),height(n->right))+1;
  newNode->height=max(height(newNode->left),height(newNode->right))+1;
  //n->height=height2(n);
  //newNode->height=height2(newNode);
  return newNode;
}
// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}
/*int AVLTree::height2(AVLNode* node)const{
  if(node==NULL){
    return -1;
  }
  else
    return max(height2(node->left),height2(node->right))+1;
    }*/
// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
