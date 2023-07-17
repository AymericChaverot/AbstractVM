/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** UnknownInstructionException
*/

#include "UnknownInstructionException.hpp"

avm::UnknownInstructionException::UnknownInstructionException(
    const std::string &instruction)
{
    _instruction = instruction;
}

const char *avm::UnknownInstructionException::what() const noexcept
{
    return (_instruction.c_str());
}
