/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Int8
*/

#ifndef INT8_HPP
#define INT8_HPP

#include <limits>

#include "Operands/AOperand.hpp"
#include "Operands/Exceptions/OverflowException.hpp"
#include "Operands/Exceptions/UnderflowException.hpp"

namespace avm {
    class Int8 : public AOperand {
        public:
            Int8(const std::string &value);
            ~Int8() = default;

            eOperandType getType() const override;
    };
}

#endif //INT8_HPP
