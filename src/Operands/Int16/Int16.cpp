/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Int16
*/

#include "Int16.hpp"

avm::Int16::Int16(const std::string &value) : AOperand(value)
{
    if (static_cast<int>(std::stoi(value)) > std::numeric_limits<int16_t>::max())
        throw (OverflowException());
    else if (static_cast<int>(std::stoi(value) < std::numeric_limits<int16_t>::min()))
        throw (UnderflowException());
}

avm::eOperandType avm::Int16::getType() const
{
    return (INT16);
}
