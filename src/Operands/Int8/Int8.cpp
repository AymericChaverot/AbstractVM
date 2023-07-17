/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Int8
*/

#include "Int8.hpp"

avm::Int8::Int8(const std::string &value) : avm::AOperand(value)
{
    if (static_cast<int>(stoi(value)) > std::numeric_limits<int8_t>::max())
        throw OverflowException();
    else if (static_cast<int>(stoi(value)) < std::numeric_limits<int8_t>::min())
        throw UnderflowException();
}

avm::eOperandType avm::Int8::getType() const
{
    return (INT8);
}
