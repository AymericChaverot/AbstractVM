/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Double
*/

#include "Double.hpp"

avm::Double::Double(const std::string &value) : AOperand(value)
{
    if (static_cast<long double>(std::stold(value)) > std::numeric_limits<double>::max())
        throw (OverflowException());
    else if (static_cast<long double>(std::stold(value) < std::numeric_limits<double>::min()))
        throw (UnderflowException());
}

avm::eOperandType avm::Double::getType() const
{
    return (DOUBLE);
}
