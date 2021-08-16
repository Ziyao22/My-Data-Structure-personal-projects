// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Constructor
TreeCalc::TreeCalc() {
   stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  while(!expressionStack.empty()){
     cleanTree(expressionStack.top());
       expressionStack.pop();
      }
  //  expressionStack.empty();
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  //   while(tree->left!=NULL || tree->right!=NULL){
   if(tree->left!=NULL){
     cleanTree(tree->left);
    }
   if(tree->right!=NULL){
    cleanTree(tree->right);
    }
   
   delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
   TreeNode* currentNode=new TreeNode();
   currentNode->value=val;
  if(val.at(0)=='+'){ 
    currentNode->right=expressionStack.top();
    expressionStack.pop();
    currentNode->left=expressionStack.top();
    expressionStack.pop();
    // int a=stoi(currentNode->value);
    expressionStack.push(currentNode);
  }
  else if(val.at(0)=='-'&&val.length()==1){
    currentNode->right=expressionStack.top();
    expressionStack.pop();
    currentNode->left=expressionStack.top();
    expressionStack.pop();
    // int b=stoi(currentNode->value);
    expressionStack.push(currentNode);
  }
  else if(val.at(0)=='*'){
    currentNode->right=expressionStack.top();
    expressionStack.pop();
    currentNode->left=expressionStack.top();
    expressionStack.pop();
    // int c=stoi(currentNode->value);
    expressionStack.push(currentNode);
  }
  else if(val.at(0)=='/'){
    currentNode->right=expressionStack.top();
    expressionStack.pop();
    currentNode->left=expressionStack.top();
    expressionStack.pop();
    // int d=stoi(currentNode->value);
    expressionStack.push(currentNode);
  }
  else{
    // int e=stoi(currentNode->value);
    //currentNode->value=val;
    expressionStack.push(currentNode);
   delete  currentNode;
  }
  // delete  currentNode;
  }

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  // TreeNode* currentTree=new TreeNode();
  // currentTree=tree;
  if(tree->left!=NULL&&tree->right!=NULL){
  cout<<tree->value<<" ";
   printPrefix(tree->left);
   printPrefix(tree->right);
  }
  else if(tree->left!=NULL&&tree->right==NULL){
   cout<<tree->value<<" ";
   printPrefix(tree->left);
   }
  else if(tree->left==NULL&&tree->right!=NULL){
   cout<<tree->value<<" ";
   printPrefix(tree->right);  
   }
  else {cout<<tree->value<<" ";}
  // currentTree=NULL;
}
// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  // TreeNode* currentTree=new TreeNode();
  // currentTree=tree;
  if(tree->left!=NULL&&tree->right!=NULL){
    cout<<"( ";
    printInfix(tree->left);
    cout<<tree->value;
    printInfix(tree->right);
    cout<<")";
  }
  // else if(currentTree->left!=NULL&&currentTree->right==NULL){
    //cout<<currentTree->value<<" ";
  // cout<<"(";
  // printInfix(currentTree->left);
  //cout<<currentTree->value<<") ";
  // }
  // else if(currentTree->left==NULL&&currentTree->right!=NULL){
    //   cout<<currentTree->value<<" ";
    //printInfix(currentTree->right);
    //cout<<")";
  // }
  else {cout<<tree->value<<" ";}
  // currentTree=NULL;
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  // TreeNode* currentTree=new TreeNode();
  // currentTree=tree;
    if(tree->left!=NULL&&tree->right!=NULL){
  // //  cout<<tree->value<<" ";
    printPostfix(tree->left);
   printPostfix(tree->right);
      cout<<tree->value<<" ";
    }
   else if(tree->left!=NULL&&tree->right==NULL){
   cout<<tree->value<<" ";
   printPostfix(tree->left);
   cout<<tree->value<<" ";
   }
   else if(tree->left==NULL&&tree->right!=NULL){
   cout<<tree->value<<" ";
   printPostfix(tree->right);
   cout<<tree->value<<" ";
   }
   else {cout<<tree->value<<" ";}
  // tree=NULL;
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  // TreeNode* currentTree=new TreeNode();
  int result;
  // currentTree=tree;
  // char ch=tree->value.at(0);
  if(tree->value.at(0)=='+'){
  result=calculate(tree->left)+calculate(tree->right);
  return result;
  }
  else if(tree->value.at(0)=='-'&&tree->value.length()==1){
  result=calculate(tree->left)-calculate(tree->right);
  return result;
  }
  else if(tree->value.at(0)=='*'){
  result=calculate(tree->left)*calculate(tree->right);
  return result;
  }
  else if(tree->value.at(0)=='/'){
  result=calculate(tree->left)/calculate(tree->right);
  return result;
  }
  else
    {
       int x;
       x=stoi(tree->value);
      //  expressionStack.push(x);
      return x;
    }
  //else cout<<"Please enter an valid input."endl;
  // delete  currentTree;
  return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
   int top=0;
   while(!expressionStack.empty()){
     top=(calculate(expressionStack.top()));
  	expressionStack.pop();
   }
   return top;
   return 0;
}
