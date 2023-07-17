/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** OperandFactory
*/

#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include <vector>

#include "Operands/Exceptions/UnknownTypeException.hpp"
#include "Operands/IOperand.hpp"
#include "Operands/Int8/Int8.hpp"
#include "Operands/Int16/Int16.hpp"
#include "Operands/Int32/Int32.hpp"
#include "Operands/Float/Float.hpp"
#include "Operands/Double/Double.hpp"

namespace avm {
    class Factory {
        public:
            Factory();
            ~Factory() = default;

            static IOperand *createOperand(eOperandType type, const std::string &value);
        private:
            IOperand *createInt8(const std::string &value);
            IOperand *createInt16(const std::string &value);
            IOperand *createInt32(const std::string &value);
            IOperand *createFloat(const std::string &value);
            IOperand *createDouble(const std::string &value);
    };
}

#endif //OPERANDFACTORY_HPP
