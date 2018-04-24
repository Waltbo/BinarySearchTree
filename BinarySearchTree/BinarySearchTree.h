/*
 * Author: Walter Smith
 * Date: 4/04/2018
 * Assignment: Program 5- BinarySearchTrees
 * File: BinarySearchTree.h
 * Description: header for BST
 */
#include <iostream>

class node {
    friend class BinarySearchTree;
private:
    int courseNumber;
    int counter;
    node * leftchild;
    node * rightchild;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    bool empty(); // return true if the tree is empty, otherwise return false
    bool Insert(int courseNum); //insert a value x 
    bool IsThere(int courseNum);
    bool IsThere(node*q, int courseNum); //method for recursion
    //return true if x is in the tree, otherwise return false
    void Delete(int courseNum); //if value x is in the tree, remove x
    node* Delete(node *q, int courseNum);
    void Display(); // Display the data values stored from smallest to largest
    void Display(node *q);
    void DeleteAllOnes(); // Driver method to delete all nodes with count equal to one
    void DeleteAllOnes(node *q);
    node* Minimum(node *q);//method to get minimum
    

private:
    node * root; // pointer to the root node
};



