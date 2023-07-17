/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include <limits>

#include "Operands/AOperand.hpp"
#include "Operands/Exceptions/OverflowException.hpp"
#include "Operands/Exceptions/UnderflowException.hpp"

namespace avm {
    class Int32 : public AOperand {
        public:
            Int32(const std::string &value);
            ~Int32() = default;

            eOperandType getType() const override;
    };
}

#endif /* !INT32_HPP_ */
