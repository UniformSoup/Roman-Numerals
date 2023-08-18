#include <iostream>
#include <algorithm>
#include <string>

#include "RomanNumerals.hpp"

int main(int argc, char* argv[])
{
    for (size_t i = 1; i < argc; ++i)
    {
        auto str = std::string(argv[i]);

        if (std::all_of(str.begin(), str.end(), isdigit))
            std::cout << "In Roman Numerals, " << str << " is " << RomanNumerals::toRomanNumerals(std::stoul(str)) << ".\n";
        else if (RomanNumerals::isRomanNumeral(str))
            std::cout << "In Arabic Numerals, " << str << " is " << RomanNumerals::toInteger(str) << ".\n";
        else
            std::cout << str << " is Invalid Input.\n";
    }

    return EXIT_SUCCESS;
}