/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** NoExitException
*/

#include "NoExitException.hpp"

const char *avm::NoExitException::what() const noexcept
{
    return "No exit instruction found";
}
