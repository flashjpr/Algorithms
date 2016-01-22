//
//  BST.cpp
//  binarySearchTree
//
//  Created by Mihai Alexandru Ionut Fleseriu on 22/01/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "BST.h"

using namespace std;

BST::BST(){
    root = NULL;
    
};

BST::node* BST::CreateLeaf(int key){
    node* n = new node;
    n -> key = key;
    n -> left = NULL;
    n -> right = NULL;
    
    return n;
}

void BST::AddLeaf(int key){
    //just call the AddLeafPrivate
    //start searching at the root ( where to add the key value)
    AddLeafPrivate(key, root);
}


void BST::AddLeafPrivate(int key, node* Ptr){
    
    //if tree is empty, create it
    if(root == NULL)
        root = CreateLeaf(key);
    //else check if key is < current key
    else if(key < Ptr -> key){
        //if so, call recursively the AddLeafPrivate method to go down - left the tree
        if (Ptr -> left != NULL) {
            AddLeafPrivate(key, Ptr -> left);
        }
        else{
            Ptr -> left = CreateLeaf(key);
        }
    }
    else if(key > Ptr -> key){
        
        if (Ptr -> right != NULL) {
            AddLeafPrivate(key, Ptr -> left);
        }
        else{
            Ptr -> right = CreateLeaf(key);
        }
    }
    //key is equal to the one which we want to add
    else    cout << "The key " << key << " is already in the tree\n";
}