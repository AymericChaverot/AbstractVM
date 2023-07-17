/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** SyntaxException
*/

#include "SyntaxException.hpp"

avm::SyntaxException::SyntaxException(const std::string &instruction)
{
    _instruction = instruction;
}

const char *avm::SyntaxException::what() const noexcept
{
    return _instruction.c_str();
}
