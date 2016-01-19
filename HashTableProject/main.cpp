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

    Hashy.AddItem("Alex", "drink1");
    Hashy.AddItem("Alex2", "drink2");
    Hashy.AddItem("Alex3", "drink3");
    Hashy.AddItem("Alex4", "drink4");
    Hashy.AddItem("Alex5", "drink5");
    Hashy.AddItem("Alex6", "Mojito6");
    Hashy.AddItem("Alex7", "Cuba libre");
    Hashy.AddItem("BBBBB", "Whiskey");
    Hashy.AddItem("Alex9", "Champagne");
    Hashy.AddItem("Alex10", "Wine");

    Hashy.PrintItemsInIndex(1);
//    Hashy.PrintTable();
    return 0;
}
