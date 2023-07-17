/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include <limits>

#include "Operands/AOperand.hpp"
#include "Operands/Exceptions/OverflowException.hpp"
#include "Operands/Exceptions/UnderflowException.hpp"

namespace avm {
    class Double : public AOperand {
        public:
            Double(const std::string &value);
            ~Double() = default;

            eOperandType getType() const override;
    };
}

#endif /* !DOUBLE_HPP_ */
