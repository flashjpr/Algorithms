//
// Created by Mihai Alexandru Ionut Fleseriu on 24/03/2016.
//

/*
 * The aim of this program is to convert an std::int32_teger to an English std::string.
 *
 * For example, for the following inputs it should return the following outputs:
 *       1  -> one
 *       2  -> two
 *      10  -> ten
 *     100  -> one hundred
 *     981  -> nine hundred eighty one
 * 8000000  -> eight million()
 *
 * The program should support both positive and negative integers within
 * the range of a 32-bit std::int32_t integer.
 *
 * */

#include <iostream>
#include <string>

std::string scalesToStrings[] = { "", "thousand", "million", "billion" };
std::string digitsToStrings[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
std::string tensToStrings[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };


/*
 * This method formats accordingly to print a space between strings
 * */
std::string formatString (std::string input) {
    if (input == "" ) {
        return "";
    }
    return " " +input;
}

/*
 * This method receives a hundred block of integers and converts it to a string representation.
 * */
std::string convertHundreds (std::int32_t blockOfHundreds) {

    if ( blockOfHundreds < 20 ) {
        return digitsToStrings[ blockOfHundreds ];
    }
    std::int32_t tens = blockOfHundreds / 10;
    std::int32_t ones = blockOfHundreds % 10;
    return tensToStrings[ tens ] + formatString( digitsToStrings[ ones ] );
}

/*
 * This method receives a thousands block of integers and converts it to a string representation.
 * */
std::string convertThousands (std::int32_t blockOfThousands) {
    if ( blockOfThousands < 100 ) {
        return convertHundreds( blockOfThousands );
    }
    else {
        std::int32_t hundreds = blockOfThousands / 100;
        std::int32_t blockOfHundreds = blockOfThousands % 100;
        return digitsToStrings[ hundreds ] + " hundred" + formatString( convertHundreds( blockOfHundreds ) );
    }
}



std::int32_t main() {

    // Var declaration and reading
    std::int32_t input;
    std::cin >> input;
    std::string number;
    bool sign;
    std::int32_t blockIndex;
    blockIndex = 0;

    // Determine the sign of theinput (positive or negative)
    sign = false;
    if (input < 0 ) { 
        sign = true;
       input =input * -1;
    }

    // Convert
    while (input > 0) {

        if (input % 1000 != 0 ) {
            number = convertThousands(input % 1000 ) + formatString (scalesToStrings[blockIndex] + formatString(number));
        }

        input /= 1000;
        blockIndex++;
    }

    if (sign) {
        number = "(minus) " + number;
    }
    
    if (number == "") {
        number = "zero";
    }
    
    std::cout << "The equivalent string representation is: \"" << number << "\""<< std::endl;
}