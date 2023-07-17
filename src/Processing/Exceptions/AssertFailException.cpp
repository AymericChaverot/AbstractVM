/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** AssertFailException
*/

#include "AssertFailException.hpp"

const char *avm::AssertFailException::what() const noexcept
{
    return "Error: Assert instruction is not true";
}
