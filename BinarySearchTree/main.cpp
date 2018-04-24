/*
 * Author: Walter Smith
 * Date: 4/04/2018
 * Assignment: Program 5- BinarySearchTrees
 * File: main.cpp
 * Description: Method to implement methods ran in bst.cpp
 */

#include <cstdlib>

#include "BinarySearchTree.h"

using namespace std;

/*
 * 
 */
int main() {
    BinarySearchTree bst;
    string j = "";
    while (j != "5") {
        cout << "1. Insert" << "\n" << "2. Display (Will get rid of all courses that haven't been put in more than once)" << "\n" << "3. Start Over" <<"\n" << "4. Search" <<"\n" << "5. Exit" << endl;
        cin >> j;
        if (j == "1") {
            cout << "Enter Insert" << endl;
            int k;
           
            while(!(cin>>k)){
                cout<<"Please only insert a number"<<endl;
                cin.clear();
                cin.ignore(99999,'\n');
                
            }
          
            bst.Insert(k); 
        } else if (j == "2") {
            if (!bst.empty()) {
                cout << "List of all the courses: " << endl;
                bst.Display();
                bst.DeleteAllOnes();
                cout << "List of courses more than one student interested: " << endl;
                bst.Display();

            }else{
                cout<<"Tree is empty"<<endl;
            }
        } else if (j == "3") {
            bst=BinarySearchTree();
        }else if(j=="4"){
            cout << "Enter What You Want to Find" << endl;
            int k;
            while(!(cin>>k)){
                cout<<"Please only insert a number"<<endl;
                cin.clear();
                cin.ignore(99999,'\n');
                
            }
            bst.IsThere(k);
            if(bst.IsThere(k)){
                cout<<k;
                cout<<" in the tree"<<endl;
            }else{
                cout<<"Can't be Found"<<endl;
            }
        }else if (j == "5") {
            cout<<"Good Bye"<<endl;
        } else {
            cout << "Wrong input" << endl;
        }




    }

}

