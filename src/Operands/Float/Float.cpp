/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Float
*/

#include "Float.hpp"

avm::Float::Float(const std::string &value) : AOperand(value)
{
    if (static_cast<double>(std::stod(value)) > std::numeric_limits<float>::max())
        throw (OverflowException());
    else if (static_cast<double>(std::stod(value)) < std::numeric_limits<float>::min())
        throw (UnderflowException());
}

avm::eOperandType avm::Float::getType() const
{
    return (FLOAT);
}
