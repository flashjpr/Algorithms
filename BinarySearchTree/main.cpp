//
//  main.cpp
//  binarySearchTree
//
//  Created by Mihai Alexandru Ionut Fleseriu on 22/01/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//

#include <iostream>
#include "BST.h"

using namespace std;


int main(int argc, const char * argv[]) {

    int SomeKeyValues[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
    
    BST tree;
    
    cout << "Outputin the tree in order\nBefore adding numbers\n";
    
    tree.PrintInOrder();
    
    for (int i = 0; i < 16; i++) {
        tree.AddLeaf(SomeKeyValues[i]) ;
    }
    cout << endl;
    
    cout << "Outputin the tree in order\nAfter numbers have been added\n";
    tree.PrintInOrder();
    cout << endl << endl;
    
//    tree.PrintChildren(tree.ReturnRootKey());
    
    for (int i = 0; i < 16; i++) {
        tree.PrintChildren(SomeKeyValues[i]) ;
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
