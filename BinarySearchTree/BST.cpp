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
        //if we point to smth, recursively try again
        if (Ptr -> left != NULL) {
            AddLeafPrivate(key, Ptr -> left);
        }
        else{
            Ptr -> left = CreateLeaf(key);
        }
    }
    else if(key > Ptr -> key){
        //if we point to smth, recursively try again
        if (Ptr -> right != NULL) {
            AddLeafPrivate(key, Ptr -> right);
        }
        else{
            Ptr -> right = CreateLeaf(key);
        }
    }
    //key is equal to the one which we want to add
    else {
        cout << "The key " << key << " is already in the tree\n";
    }
}

void BST::PrintInOrder(){
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr){
    
    if (root != NULL) {
        //if possible, go left
        if(Ptr -> left != NULL){
            PrintInOrderPrivate(Ptr -> left);
        }
        cout << Ptr -> key << " ";
        //if possible go right
        if (Ptr -> right != NULL) {
            PrintInOrderPrivate(Ptr -> right);
        }
    }else{
        cout << "Empty tree\n";
    }
}

BST::node* BST::ReturnNode(int key){
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key,node* Ptr){
    
    if( Ptr != NULL){
        if (Ptr -> key == key) {
            return Ptr;
        }else{
            if (key < Ptr -> key)
                return ReturnNodePrivate(key, Ptr -> left);
            else
                return ReturnNodePrivate(key, Ptr -> right);
        }
    }else return NULL;
}











