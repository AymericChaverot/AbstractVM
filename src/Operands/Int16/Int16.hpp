/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include <limits>

#include "Operands/AOperand.hpp"
#include "Operands/Exceptions/OverflowException.hpp"
#include "Operands/Exceptions/UnderflowException.hpp"

namespace avm {
    class Int16 : public AOperand {
        public:
            Int16(const std::string &value);
            ~Int16() = default;

            eOperandType getType() const override;
    };
}

#endif /* !INT16_HPP_ */
