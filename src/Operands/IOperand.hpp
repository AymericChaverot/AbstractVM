/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** IOperand
*/

#pragma once

#include <string>

namespace avm {
    enum eOperandType {
        INT8,
        INT16,
        INT32,
        FLOAT,
        DOUBLE,
        UNKNOWN
    };

    class IOperand {
        public:
            virtual ~IOperand() = default;

            virtual std::string toString() const = 0; // String that represents the instance

            virtual eOperandType getType() const = 0; // Type of the instance

            virtual IOperand *operator+(const IOperand &rhs) const = 0; // Sum
            virtual IOperand *operator-(const IOperand &rhs) const = 0; // Difference
            virtual IOperand *operator*(const IOperand &rhs) const = 0; // Product
            virtual IOperand *operator/(const IOperand &rhs) const = 0; // Quotient
            virtual IOperand *operator%(const IOperand &rhs) const = 0; // Modulo
    };
}
