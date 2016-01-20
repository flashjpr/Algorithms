//
//  Header.h
//  HashTableProject
//
//  Created by Mihai Alexandru Ionut Fleseriu on 19/01/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#ifndef Header_h
#define Header_h

//create class hashType
class hashType{
    
private:
    static const int tableSize = 4;
    
    struct item{
        string name;
        string drink;
        item* next;
    };
    
    //define the hash table
    item* HashTable[tableSize];
    
public :
    //constructor
    hashType();
    
    //define the prototipe for the Hash function
    int Hashing(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void SearchDrink(string name);
    void RemoveItem(string name);
};

#endif /* Header_h */
