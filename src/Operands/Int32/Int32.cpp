/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Int32
*/

#include "Int32.hpp"

avm::Int32::Int32(const std::string &value) : AOperand(value)
{
    if (static_cast<long>(std::stol(value)) > std::numeric_limits<int32_t>::max())
        throw (OverflowException());
    else if (static_cast<long>(std::stol(value)) < std::numeric_limits<int32_t>::min())
        throw (UnderflowException());
}

avm::eOperandType avm::Int32::getType() const
{
    return (INT32);
}
