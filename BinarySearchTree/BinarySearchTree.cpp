/*
 * Author: Walter Smith
 * Date: 4/04/2018
 * Assignment: Program 5- BinarySearchTrees
 * File: BinarySearchTree.cpp
 * Description: creates and makes methods for binary search trees
 */
#include "BinarySearchTree.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

BinarySearchTree::BinarySearchTree() {//makes a tree
    root = NULL;
}

bool BinarySearchTree::empty() {//returns true if empty
    if (root == NULL) {
        return true;
    } else {
        return false;
    }
}

bool BinarySearchTree::Insert(int courseNum) {
    node *q = root;
    node *p = NULL;
    node* r = new node;
    r->courseNumber = courseNum;//holds data for insert
    r->counter = 1;//sets the counter to one for that course if it just got put in
    r->leftchild = r->rightchild = NULL;//sets children to NULL
    if (empty() == false) {//starts if its not empty
        while (q != NULL) {
            if (courseNum == q->courseNumber) {//instead of adding the same value to the tree it just makes that counter higher
                q->counter++;
                cout << "Incremented " << courseNum << endl;
                return false;
            }
            p = q;
            if (courseNum < q->courseNumber) {//moves node to the correct position
                q = q->leftchild;
            } else {
                q = q->rightchild;
            }
        }
    }
    if (root == NULL) {//places the input
        root=r;
        cout << "Inserted " << courseNum << " as root " << endl;
    } else if (courseNum < p->courseNumber) {
        p->leftchild = r;
        cout << "Inserted " << courseNum << " as left " << endl;
    } else {
        p->rightchild = r;
        cout << "Inserted " << courseNum << " as right " << endl;
    }
    return true;
}

bool BinarySearchTree::IsThere(int courseNum) {
    return IsThere(root, courseNum);
}

bool BinarySearchTree::IsThere(node* q, int courseNum) {//Goes through the list to check and see if there is the course
    if (q == NULL) {
        return false;
    }
    if (courseNum == q->courseNumber) {//true if it finds it
        return true;
    }
    if (courseNum < q->courseNumber) {//keeps iterating until it just cant
        return IsThere(q->leftchild, courseNum);
    }
    return IsThere(q->rightchild, courseNum);
}

node* BinarySearchTree::Delete(node* q, int courseNum) {
    if (q == NULL) {
        return q;
    }
    if ((q->leftchild!=NULL)&&(courseNum < q->courseNumber)) {//Checks to see if NULL and if its not checks and see if its less than or more than return it as a node
        q->leftchild = Delete(q->leftchild, courseNum);
    } else if ((q->rightchild!=NULL)&&(courseNum > q->courseNumber)) {
        q->rightchild = Delete(q->rightchild, courseNum);
    }
    else if (courseNum == q->courseNumber){
        if(q->leftchild==NULL){
            return q->rightchild;
        }else if(q->rightchild==NULL){
            return q->leftchild;
        }else{//finds the minimum node and sets it to what needs to be switched 
            node *p = Minimum(q->rightchild);
            q->courseNumber=p->courseNumber;
            q->counter=p->counter;
            q->rightchild = Delete(q->rightchild, p->courseNumber);
        }    
    }
    return q;
}
void BinarySearchTree::Delete(int courseNum) {
    root = Delete(root, courseNum);
}
node* BinarySearchTree::Minimum(node*q){//Finds the minimum by searching left most
    while(q->leftchild != NULL){
        q=q->leftchild;
    }
    return q;
}
void BinarySearchTree::Display(){
    Display(root);
}
void BinarySearchTree::Display(node* q){//uses inorder to display
    if(q != NULL){
        Display(q->leftchild);
        cout<<q->courseNumber << ": "<< q->counter<<endl;
        Display(q->rightchild);
    }
}
void BinarySearchTree::DeleteAllOnes(){
    DeleteAllOnes(root);
}
void BinarySearchTree::DeleteAllOnes(node* q){//uses post order to delete all ones
    if(q!=NULL){
        DeleteAllOnes(q->leftchild);
        DeleteAllOnes(q->rightchild);
        if(q->counter==1){
            Delete(q->courseNumber);
        }
        
    }
}




