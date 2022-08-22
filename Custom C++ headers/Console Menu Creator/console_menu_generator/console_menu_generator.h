#ifndef CONSOLE_MENU_GENERATOR_H_INCLUDED
#define CONSOLE_MENU_GENERATOR_H_INCLUDED

#include "../generic_conventions/generic_conventions.h"

#include <iostream>
#include <vector>
#include <string>


class Menu
{

private:

    std::string header;
    std::vector<std::string> options;
    std::string inputTag;
    uint16_t numOptions;
    std::vector<Menu*> submenus;
    std::vector<uint16_t> actionTokens;
    std::string exitOption;
    uint16_t restoreMenu;

    /// <summary>
    /// Converts an uint16_t to string. If the number is less than 10, adds a '0' at the beginning.
    /// </summary>
    /// <param name="nr"></param>
    /// <returns>string representing at least 2 figures nr</returns>
    std::string noSingleFigure(uint16_t nr)
    {
        std::string result = "";

        if (check::isLesser(nr, uint16_t(10)))
        {
            result += "0";
        }

        result += std::to_string(nr);

        return result;
    }

    /// <summary>
    /// Displays the menu in the console.
    /// </summary>
    void show()
    {
        std::cout << header << std::endl;

        for (uint16_t i = 0; i < numOptions; ++i)
        {
            std::cout << noSingleFigure(i + 1) << ". " << options.at(i) << std::endl;
        }
        std::cout << "00. " << exitOption << std::endl;
    }

    bool isAFigure(char c)
    {
        const int asciiForChar0 = 48;
        const int candidate = (int)c - asciiForChar0;

        if (check::isLesserOrEqual(0, candidate) && check::isLesser(candidate, 10))
        {
            return true;
        }
        return false;
    }

    bool getValidInput(uint16_t &input)
    {
        uint16_t number = 0;
        std::string s;

        const std::string invalidInputMessage = "Please insert a positive integer coresponding to a valid menu option !";

        std::cout << inputTag;

        // std::cin >> s; - stops at space characters, not just at new lines.
        // getline(std::cin, s); - only works reliably if istream buffer is cleared.
        // scanf(" "); - clears istream input buffer.
        scanf(" ");
        getline(std::cin, s);
        
        if (s.empty()) {

            std::cout << invalidInputMessage << std::endl;
            return false;
        }

        int index = 0;
        while (check::isNotEqual(s[index], '\0'))
        {
            if (isAFigure(s[index]))
            {
                const int asciiForChar0 = 48;
                number = number * 10 + ((int)s[index] - asciiForChar0);
            }
            else {

                std::cout << invalidInputMessage << std::endl;
                return false;
            }
            index++;
        }

        if (check::isGreater(number, numOptions))
        {
            std::cout << invalidInputMessage << std::endl;
            return false;
        }

        input = number;
        return true;
    }

public:

    Menu(uint16_t numOptions)
    {
        this->numOptions = numOptions;

        header = "";
        inputTag = "";
        exitOption = "Quit";
        restoreMenu = 0;

        options.clear();
        submenus.clear();
        actionTokens.clear();

        for (uint16_t i = 0; i < numOptions; ++i)
        {
            options.push_back("");
            submenus.push_back(NULL);
            actionTokens.push_back(0);
        }
    }

    void setOption(int index, std::string entry)
    {
        options.at(index) = entry;
    }

    void setExitOption(std::string entry)
    {
        exitOption = entry;
    }

    void setHeader(std::string entry)
    {
        header = entry;
    }

    void setInputTag(std::string entry)
    {
        inputTag = entry;
    }

    void setSubmenu(int index, Menu* entry)
    {
        submenus.at(index) = entry;
        
        if (check::isNotNull(entry))
        {
            actionTokens.at(index) = 0;
        }
    }

    void setActionToken(int index, uint16_t entry)
    {
        actionTokens.at(index) = entry;
    }

    uint16_t launch()
    {
        std::string selectedOption;

        uint16_t input;

        while (true)
        {
            if (check::isEqual(restoreMenu, uint16_t(0)))
            {
                show();
            }

            if (check::isNotEqual(restoreMenu, uint16_t(0)))
            {
                const uint16_t submenuReturn = (submenus.at(restoreMenu - 1))->launch();
                if (check::isNotEqual(submenuReturn, uint16_t(0)))
                {
                    return submenuReturn;
                }
                restoreMenu = 0;
            }
            else if (getValidInput(input))
            {
                if (check::isEqual(input, uint16_t(0)))
                {
                    return 0;
                }
                else if (check::isNotNull(submenus.at(input - 1)))
                {
                    const uint16_t submenuReturn = (submenus.at(input - 1))->launch();
                    if (check::isNotEqual(submenuReturn, uint16_t(0)))
                    {
                        restoreMenu = input;
                        return submenuReturn;
                    }
                    // else {keep running;}
                }
                else
                {
                    return actionTokens.at(input - 1);
                }
            }
        }
    }

};


#endif /// CONSOLE_MENU_GENERATOR_H_INCLUDED