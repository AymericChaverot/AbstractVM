/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Overflow
*/

#include "OverflowException.hpp"

const char *avm::OverflowException::what() const noexcept
{
    return ("Overflow !");
}
