#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;
//Ziyao Gao zg8rw 10/05/2020
//BInarySearchTree.cpp
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insert(root,x);
  //numNode++;
  // if(root->left==NULL&&root->right==NULL){
  // numNode=1;
  //}
}
void  BinarySearchTree::insert(BinaryNode*& n, const string& x){
  if(n==NULL){
    n=new BinaryNode();
    n->value=x;
  }
  else if(x<n->value)
    insert(n->left,x);
  else if(x>n->value)
    insert(n->right,x);
  else;
  // duplicate...do nothing
}
// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
    //numNode--;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return pathTo(root,x);
    //  return cout<<"The element is not in the tree."<<endl;
  // if(x==root->value){
  //  return root->value;
    // }
  // else if(x<root->value){
    // return pathTo(root->left,x);
    // }
  // else if(x>root->value){
    // return pathTo(root->right,x);
    //  }
    // }
  // else return cout<<"The value is not in the tree."<<endl;
  //  else if(x<root->value){
    
  // }
}
string BinarySearchTree::pathTo(BinaryNode* currentNode, const string& x)const{
  // string a=currentNode->value;
   if(currentNode==NULL&&currentNode->left==NULL&&currentNode->right==NULL)
    return "";
   if(!find(x))
     return "";
   else if(find(x)&&x==currentNode->value)
      return currentNode->value;
   else if(find(x)&&x<currentNode->value)
      // if(x<currentNode->value){
      // pathTo(currentNode->left,x);
      //return currentNode->left->value;
      return currentNode->value+" "+pathTo(currentNode->left,x);
    
     else if(find(x)&&x>currentNode->value)
    // pathTo(currentNode->right,x);
    //return currentNode->right->value;
	return currentNode->value+" "+pathTo(currentNode->right,x);
     else return "";
}
     // else return "";
    // if(currentNode==NULL){
  //  return "";
  // }
  // else return "The element is not in the tree.";
// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(find(root,x)==true){
   return true;
    }
   else return false;
}
bool BinarySearchTree::find(BinaryNode *currentNode,const string& x)const{
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
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  
  // int x=0;
  // if(root==NULL){
  //  return 0;
  // }
  // else //if(root->left==NULL&&root->right==NULL){
    // return 1;
  
  //  else {
  // while(root->left!=NULL||root->right!=NULL){
    // cout<<printTree();
  // x++;
    //  }
  // return x;
  // }
  // int a=0;
  // while(root->left!=NULL||root->right!=NULL){
  //printTree();
  // a++;
  // }
  return numNodes(root);
}
int BinarySearchTree::numNodes(BinaryNode* currentNode)const{
  int n=0;
  if(currentNode==NULL){
    return n;
  }
  else {
    n=numNodes(currentNode->left)+numNodes(currentNode->right)+1;
    return n;
  }
}
// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
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
