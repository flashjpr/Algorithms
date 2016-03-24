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
    int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key, node* parent);
    void RemoveRootNode();
    //bool-indicate relationship between parent and matching node
    void RemoveMatch(node* parent, node* match, bool left);
    node* ReturnNode(int key);
    //helper function for decontruction
    void RemoveSubtree(node* Ptr);

public:
    
    //contructor prototype
    BST();
    //deconstructor: called when BST goes out of scope
    ~BST();
    void AddLeaf(int key);
    void PrintInOrder();
    int ReturnRootKey();
    void PrintChildren(int key);
    //create a helper function for deletion
    int FindSmallest();
    void RemoveNode(int key);
    
};

#endif /* BST_h */
