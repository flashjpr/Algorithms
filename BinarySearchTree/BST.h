//
//  BST.h
//  binarySearchTree
//
//  Created by Mihai Alexandru Ionut Fleseriu on 22/01/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//

#ifndef BST_h
#define BST_h


class BST{
    
private:

    struct node{
        int key;
        node* left;
        node* right;
    };
    node* root;
    
    node* CreateLeaf(int key);
    void AddLeafPrivate(int key, node* Ptr);
    void PrintInOrderPrivate(node* Ptr);
    node* ReturnNodePrivate(int key, node* Ptr);
public:
    
    //contructor prototype
    BST();
    void AddLeaf(int key);
    void PrintInOrder();
    node* ReturnNode(int key);

};

#endif /* BST_h */
