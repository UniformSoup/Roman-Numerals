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
            std::cout << str << " in Roman Numerals is " << RomanNumerals::toRomanNumerals(std::stoul(str)) << '\n';
        else if (RomanNumerals::isRomanNumeral(str))
            std::cout << str << " in Arabic Numerals is " << RomanNumerals::toInteger(str) << '\n';
        else
            std::cout << str << " is invalid input.\n";
    }

    return EXIT_SUCCESS;
}