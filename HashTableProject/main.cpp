//
//  main.cpp
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

int main(int argc, const char * argv[]) {

    hashType Hashy;
    
    //debug for search function
    //store the name of the person we are looking for
    string name;

//    Hashy.AddItem("Alex", "drink1");
//    Hashy.AddItem("Alex2", "drink2");
//    Hashy.AddItem("Alex3", "drink3");
//    Hashy.AddItem("Alex4", "drink4");
//    Hashy.AddItem("Alex5", "drink5");
//    Hashy.AddItem("Alex6", "Mojito6");
//    Hashy.AddItem("Alex7", "Cuba libre");
//    Hashy.AddItem("BBBBB", "Whiskey");
//    Hashy.AddItem("Alex9", "Champagne");
//    Hashy.AddItem("Alex10", "Wine");
    
    Hashy.AddItem("Alex", "CubaLibre");
    Hashy.AddItem("Larisa", "CocaCola");
    Hashy.AddItem("Strat", "Visinata");
    Hashy.AddItem("Idri", "Vin");
    Hashy.AddItem("Lupu", "Sampanie");
    Hashy.AddItem("Horia", "AquaChioara");
    Hashy.AddItem("Ionu", "Mocachino");
    Hashy.AddItem("Alexut", "Whiskey");
    Hashy.AddItem("Just", "Sampan");
    Hashy.AddItem("Paul", "Wine");

    Hashy.PrintItemsInIndex(3);
//    Hashy.PrintTable();
    
    while (name != "exit") {
        cout << "Remove ";
        cin >> name;
        
        if (name != "exit") {
            Hashy.RemoveItem(name);
        }
    }
    
    Hashy.PrintItemsInIndex(3);
    
//    Hashy.PrintTable();
 
//    while (name != "exit") {
//        cout << "Search for ";
//        cin >> name;
//        
//        if (name != "exit") {
//            Hashy.SearchDrink(name);
//        }
//    }
    
    return 0;
}
