/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** EmptyStackPopException
*/

#include "EmptyStackPopException.hpp"

const char *avm::EmptyStackPopException::what() const noexcept
{
    return "Error: Pop on empty stack";
}
