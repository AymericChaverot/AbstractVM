/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** AOperand
*/

#ifndef AVM_AOPERAND_HPP
#define AVM_AOPERAND_HPP

#include <cmath>

#include "Operands/IOperand.hpp"
#include "Operands/Exceptions/DivisionByZeroException.hpp"

namespace avm {
    class AOperand : public IOperand {
        public:
            AOperand(const std::string &value);
            ~AOperand() override = default;

            std::string toString() const override;

            IOperand *operator+(const IOperand &rhs) const override;
            IOperand *operator-(const IOperand &rhs) const override;
            IOperand *operator*(const IOperand &rhs) const override;
            IOperand *operator/(const IOperand &rhs) const override;
            IOperand *operator%(const IOperand &rhs) const override;

        private:
            eOperandType getMostPreciseType(const IOperand &rhs) const;
            std::string _value;
    };
}

#endif //AVM_AOPERAND_HPP
