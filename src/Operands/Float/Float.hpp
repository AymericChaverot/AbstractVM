/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include <limits>

#include "Operands/AOperand.hpp"
#include "Operands/Exceptions/OverflowException.hpp"
#include "Operands/Exceptions/UnderflowException.hpp"

namespace avm {
    class Float : public AOperand {
        public:
            Float(const std::string &value);
            ~Float() = default;

            eOperandType getType() const override;
    };
}

#endif /* !FLOAT_HPP_ */
