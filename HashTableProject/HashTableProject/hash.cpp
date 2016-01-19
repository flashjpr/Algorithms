//
//  hash.cpp
//  HashTableProject
//
//  Created by Mihai Alexandru Ionut Fleseriu on 19/01/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

//Define the constructor
hashType::hashType(){
    
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty";
        HashTable[i] -> next = NULL;
    }
}

void hashType::AddItem(string name, string drink){
    
    //figures the index for a new person
    int index = Hashing(name);
    
    //check if it's default information, if so override
    if(HashTable[index] -> name == "empty"){
        HashTable[index] -> name = name;
        HashTable[index] -> drink = drink;
    }else{
        //otherwise do not override, but link to the current index a new item
        item* pointer = HashTable[index]; //point to the begining of that index
        item* n = new item;
        
        n -> name = name;
        n -> drink = drink;
        n -> next = NULL;
        
        while (pointer-> next != NULL) {
            pointer = pointer -> next;
        }
        
        //link the last item to the newly created item
        pointer -> next = n;
    }
}

int hashType::NumberOfItemsInIndex(int index){
    int count = 0;
    
    if (HashTable[index] -> name == "empty") {
        return count;
    }else{
        count++;
        item* pointer = HashTable[index];
        while (pointer -> next != NULL) {
            count++;
            pointer = pointer -> next;
        }
    }
    return count;
}

void hashType::PrintTable(){
    //number of elements in each index
    int number;
    
    for (int i = 0; i< tableSize; i++) {
        number = NumberOfItemsInIndex(i);
        cout << "____________________\n";
        cout << "index = " << i << endl;
        cout << HashTable[i] -> name << endl;
        cout << HashTable[i] -> drink << endl;
        cout << "# of items = " << number << endl;
        cout << "____________________\n";
    }
}

int hashType::Hashing(string key)
{
    int hash = 0, index;
    
    //for each character of key, transform it to an integer and save in var hash
    for(int i = 0; i< key.length();i++){
        hash = hash + (int)key[i];
    }

    //deal with out of table size keys
    index = hash % tableSize;
    
    
    return index;
}