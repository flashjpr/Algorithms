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

    Hashy.AddItem("Alex", "part1");
    Hashy.AddItem("Alex2", "part2");
    Hashy.AddItem("Alex3", "part3");
    Hashy.AddItem("Alex4", "part4");
    Hashy.AddItem("Alex5", "part5");
    Hashy.AddItem("Alex6", "part6");
    Hashy.AddItem("Alex7", "part7");
    Hashy.AddItem("Alex8", "part8");
    Hashy.AddItem("Alex9", "part9");
    Hashy.AddItem("Alex10", "part10");
    
    Hashy.PrintTable();
    
    return 0;
}
