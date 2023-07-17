/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CantLoadException
*/

#include "CantLoadException.hpp"

const char *avm::CantLoadException::what() const noexcept
{
    return "Can't load memory.";
}
