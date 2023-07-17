/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <stack>
#include "Operands/Factory/OperandFactory.hpp"
#include "Exceptions/EmptyStackPopException.hpp"
#include "Exceptions/CantLoadException.hpp"

namespace avm {
    class Memory {
        public:
            Memory();
            Memory(size_t size);
            ~Memory() = default;

            void add(IOperand *operand);
            void pop();
            void clear();
            void dup();
            void swap();

            IOperand *get();

            void load(int index);
            void store(int index);

            bool isEmpty() const;

            size_t getCurrentSize() const;
            size_t getMaxSize() const;

        private:
            size_t getOperandSize(IOperand *operand);

            bool _mode;
            size_t _current_size;
            size_t _size_max;
            std::stack<IOperand *> _stack;
            std::vector<IOperand *> _registers;
    };
}

#endif /* !MEMORY_HPP_ */
