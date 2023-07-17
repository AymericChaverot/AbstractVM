/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** TerminalOut
*/

#include "TerminalOut.hpp"

bool avm::TerminalOut::isInput() const
{
    return false;
}

std::string avm::TerminalOut::getLine()
{
    return "";
}

void avm::TerminalOut::putLine(const std::string &line)
{
    std::cout << line << std::endl;
}
