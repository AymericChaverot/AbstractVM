/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Underflow
*/

#include "UnderflowException.hpp"

const char *avm::UnderflowException::what() const noexcept
{
    return ("Underflow !");
}
