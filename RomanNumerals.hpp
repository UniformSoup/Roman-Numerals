#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

namespace RomanNumerals
{
    const std::unordered_map<char, unsigned int> numeralsToIntegers =
    {
        {'M', 1000}, {'D', 500}, {'C', 100}, 
        {'L', 50},   {'X', 10},  {'V', 5},
        {'I', 1}
    };

    const std::vector<std::pair<unsigned int, std::string>> integersToNumerals = 
    {
        {1000, "M"}, {900, "CM"}, {500, "D"},
        {400, "CD"}, {100, "C"},  {90, "XC"},
        {50, "L"},   {40, "XL"},  {10, "X"},
        {9, "IX"},   {5, "V"},    {4, "IV"},
        {1, "I"}
    };

    unsigned int toInteger(std::string const& str)
    {
        unsigned int res = 0;
        unsigned int lastNumeral = 0;

        for (size_t i = str.size(); i > 0; --i)
        {
            unsigned int currentNumeral = numeralsToIntegers.at(str[i - 1]);
            res += (lastNumeral <= currentNumeral) ? currentNumeral : -currentNumeral; 
            lastNumeral = currentNumeral;
        }

        return res;
    }

    std::string toRomanNumerals(unsigned int integer)
    {
        std::string res = "";

        while (integer > 0)
        {
            for (auto const& pair : integersToNumerals)
            {
                if (pair.first <= integer)
                {
                    integer -= pair.first;
                    res += pair.second;
                    break;
                }
            }
        }

        return res;
    }

    bool isRomanNumeral(std::string const& str)
    {
        for (size_t i = 0; i < str.size(); ++i)
            if (numeralsToIntegers.find(std::toupper(str[i])) == numeralsToIntegers.end())
                return false;

        return true;
    }

}