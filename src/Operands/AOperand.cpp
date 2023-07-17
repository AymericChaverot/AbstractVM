/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** AOperand
*/

#include "AOperand.hpp"
#include "Operands/Factory/OperandFactory.hpp"

avm::AOperand::AOperand(const std::string &value)
{
    _value = value;
}

std::string avm::AOperand::toString() const
{
    if (getType() == FLOAT || getType() == DOUBLE)
        return (_value.substr(0, _value.find_last_not_of('0') + (_value[_value.find_last_not_of('0')] == '.' ? 2 : 1)));
    return (_value);
}

avm::IOperand *avm::AOperand::operator+(const avm::IOperand &rhs) const
{
    eOperandType type = getMostPreciseType(rhs);
    std::string value;
    if (type == INT8 || type == INT16 || type == INT32)
        value = std::to_string(std::stoi(_value) + std::stoi(rhs.toString()));
    else
        value = std::to_string(std::stod(_value) + std::stod(rhs.toString()));
    return (avm::Factory::createOperand(getMostPreciseType(rhs), value));
}

avm::IOperand *avm::AOperand::operator-(const avm::IOperand &rhs) const
{
    eOperandType type = getMostPreciseType(rhs);
    std::string value;
    if (type == INT8 || type == INT16 || type == INT32)
        value = std::to_string(std::stoi(_value) - std::stoi(rhs.toString()));
    else
        value = std::to_string(std::stod(_value) - std::stod(rhs.toString()));
    return (avm::Factory::createOperand(getMostPreciseType(rhs), value));
}

avm::IOperand *avm::AOperand::operator*(const avm::IOperand &rhs) const
{
    eOperandType type = getMostPreciseType(rhs);
    std::string value;
    if (type == INT8 || type == INT16 || type == INT32)
        value = std::to_string(std::stoi(_value) * std::stoi(rhs.toString()));
    else
        value = std::to_string(std::stod(_value) * std::stod(rhs.toString()));
    return (avm::Factory::createOperand(getMostPreciseType(rhs), value));
}

avm::IOperand *avm::AOperand::operator/(const avm::IOperand &rhs) const
{
    eOperandType type = getMostPreciseType(rhs);
    std::string value;
    if (std::stod(rhs.toString()) == 0)
        throw avm::DivisionByZeroException();
    if (type == INT8 || type == INT16 || type == INT32)
        value = std::to_string(std::stoi(_value) / std::stoi(rhs.toString()));
    else
        value = std::to_string(std::stod(_value) / std::stod(rhs.toString()));
    return (avm::Factory::createOperand(getMostPreciseType(rhs), value));
}

avm::IOperand *avm::AOperand::operator%(const avm::IOperand &rhs) const
{
    eOperandType type = getMostPreciseType(rhs);
    if (std::stod(rhs.toString()) == 0)
        throw avm::DivisionByZeroException();
    std::string value;
    if (type == INT8 || type == INT16 || type == INT32)
        value = std::to_string(std::stoi(_value) % std::stoi(rhs.toString()));
    else
        value = std::to_string(std::fmod(std::stod(_value), std::stod(rhs.toString())));
    return (avm::Factory::createOperand(getMostPreciseType(rhs), value));
}

avm::eOperandType avm::AOperand::getMostPreciseType(const avm::IOperand &rhs) const
{
    eOperandType type = getType();
    eOperandType typeRhs = rhs.getType();
    return (type > typeRhs ? type : typeRhs);
}
