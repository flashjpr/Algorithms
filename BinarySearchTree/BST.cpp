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

int BST::ReturnRootKey(){
    if (root != NULL)
        return root -> key;
    else
        return -1; // return a negative number, because we have only positive numbers in the BT
}

void BST::PrintChildren(int key){
    node* Ptr = ReturnNode(key);
    
    if (Ptr != NULL) {
        cout << "Parent node = " << Ptr -> key << endl;
        
        Ptr -> left == NULL ?
        cout << "Left child is NULL\n" :
        cout << "Left child is " << Ptr -> left -> key << endl;
        
        Ptr -> right == NULL ?
        cout << "Right child is NULL\n" :
        cout << "Right child is " << Ptr -> right -> key << endl;
        
    }else cout << "Key " << key << " is not in the tree\n";
}


int BST::FindSmallest(){
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr){
    if (root == NULL) {
        cout << "Tree is empty\n";
        return -1;
    }else{
        if (Ptr -> left != NULL) {
            //recursively call the FindSmallestPrivate function to search
            return FindSmallestPrivate(Ptr -> left);
        }else{
            //found the smallest in the subtree
            return Ptr -> key;
        }
    }
}

void BST::RemoveNode(int key){
    //call the private function and start at the root(as a parent)
    return RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent){

    if(root != NULL){
        if(root -> key == key)  RemoveRootNode();
        else{
            //look at the left child:
            if (key < parent -> key && parent-> left != NULL) {
                
                parent -> left -> key == key ?
                RemoveMatch(parent, parent -> left, true):
                //recursively call the RemoveNodePrivate with new parent = left node
                RemoveNodePrivate(key, parent -> left);
            }else if (key > parent -> key && parent-> right != NULL) {
                
                parent -> right -> key == key ?
                RemoveMatch(parent, parent -> right, false):
                //we need to move to the right
                RemoveNodePrivate(key, parent -> right);
            }else   cout << "Key " << key << " is not found in the tree";
        }
    }else   cout << "Tree is empty\n";
}

void BST::RemoveRootNode(){
    
    if (root != NULL) {
        node* deletePointer = root;
        int rootKey = root -> key;
        int smallestInRightSubtree;
        
        //case 0: 0 children
        if(root -> left == NULL && root -> right == NULL){
            root = NULL;
            delete deletePointer;
        }//case 1: 1 root has a child
        else if (root -> left == NULL && root -> right != NULL){
            
            //case 1.1 child is attached to root's right side
            root = root -> right;
            
            deletePointer -> right = NULL;//completely disconect the node from the tree
            delete deletePointer;
        
            cout << "The root node with key " << rootKey << " was deleted. " <<
                    "The new root contains key " << root -> key << endl;
        }//case 1:  child has a child
        else if (root -> left != NULL && root -> right == NULL){
            
            //case 1.2 child is attached to rooot's right side
            root = root -> left;
            
            deletePointer -> left = NULL;//completely disconect the node from the tree
            delete deletePointer;
            
            cout << "The root node with key " << rootKey << " was deleted. " <<
            "The new root contains key " << root -> key << endl;
        }
        //case 2 : root 2 children
        else{
            smallestInRightSubtree = FindSmallestPrivate(root -> right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root -> key = smallestInRightSubtree;
            cout << "The root key with key " << rootKey << " was replaced by the key :" << root -> key << endl;
        }
    }else{
        cout << "Tree is already empty. Cannot delete the root";
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left){
    if (root != NULL) {
        node* deletePointer;
        int matchKey = match -> key;
        int smallestInRightSubtree;
        
        //case 0 - matching node has 2 children
        if (match -> left == NULL && match -> right == NULL) {
            deletePointer = match;
            
            left == true ?
            parent -> left = NULL:
            parent -> right = NULL;
            
            delete deletePointer;
            cout << "Node with key : " << matchKey << " has been deleted";
        }
        //case 1 - 1 child
        else if( match -> left == NULL && match -> right != NULL){
            
            left == true ?
            parent -> left = match -> right :
            parent -> right = match -> right;
            
            match -> right = NULL;//disconnect matching node from the tree
            deletePointer =  match;
            delete deletePointer;
            cout << "Node with key : " << matchKey << " has been deleted";
        }else if( match -> left != NULL && match -> right == NULL){
            
            left == true ?
            parent -> left = match -> left :
            parent -> right = match -> left;
            
            match -> left = NULL;//disconnect matching node from the tree
            deletePointer =  match;
            delete deletePointer;
            cout << "Node with key : " << matchKey << " has been deleted";
        }
        //case 2 - 2 children
        else{
            smallestInRightSubtree = FindSmallestPrivate(match -> right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            //overwrite the key of the node to be deleted to the smallestInRightSubtree, and delete that node
            match -> key = smallestInRightSubtree;
        }
    }else{
        cout << "Can't remove match because tree is empty.";
    }
}




