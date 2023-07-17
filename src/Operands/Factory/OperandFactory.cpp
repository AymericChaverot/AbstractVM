/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** OperandFactory
*/

#include "OperandFactory.hpp"
#include <iostream>

avm::Factory::Factory()
{
}

avm::IOperand *avm::Factory::createOperand(eOperandType type, const std::string &value)
{
    avm::Factory factory;
    std::vector<IOperand *(Factory::*)(const std::string &value)> creators;
    creators.push_back(&Factory::createInt8);
    creators.push_back(&Factory::createInt16);
    creators.push_back(&Factory::createInt32);
    creators.push_back(&Factory::createFloat);
    creators.push_back(&Factory::createDouble);
    if (type < INT8 || type > DOUBLE)
        throw UnknownTypeException();
    return ((factory.*creators[type])(value));
}

avm::IOperand *avm::Factory::createInt8(const std::string &value)
{
    try {
        return (new Int8(value));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit (84);
    }
}

avm::IOperand *avm::Factory::createInt16(const std::string &value)
{
    try {
        return (new Int16(value));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit (84);
    }
}

avm::IOperand *avm::Factory::createInt32(const std::string &value)
{
    try {
        return (new Int32(value));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit (84);
    }
}

avm::IOperand *avm::Factory::createFloat(const std::string &value)
{
    try {
        return (new Float(value));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit (84);
    }
}

avm::IOperand *avm::Factory::createDouble(const std::string &value)
{
    try {
        return (new Double(value));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit (84);
    }
}
