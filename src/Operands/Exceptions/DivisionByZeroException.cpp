/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** DivisionByZeroException
*/

#include "DivisionByZeroException.hpp"

const char *avm::DivisionByZeroException::what() const noexcept
{
    return ("Division by zero !");
}
