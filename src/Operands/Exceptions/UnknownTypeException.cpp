/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** UnknownTypeException
*/

#include "UnknownTypeException.hpp"

const char *avm::UnknownTypeException::what() const noexcept
{
    return ("Unknown type !");
}
