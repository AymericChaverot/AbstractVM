/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Memory
*/

#include "Memory.hpp"

avm::Memory::Memory()
{
    _size_max = 1000;
    _current_size = 0;
    _mode = false;
    _registers.resize(16, nullptr);
}

avm::Memory::Memory(size_t size)
{
    _size_max = size;
    _current_size = 0;
    _mode = true;
    _registers.resize(16);
}

void avm::Memory::add(avm::IOperand *operand)
{
    if (operand == nullptr)
        throw CantLoadException();
    if (_mode) {
        while (_size_max != 0 && _current_size >= _size_max) {
            pop();
        }
        _current_size += getOperandSize(operand);
        _stack.push(operand);
    } else {
        while (_current_size >= _size_max) {
            pop();
        }
        _current_size += 1;
        _stack.push(operand);
    }
}

void avm::Memory::pop()
{
    if (_current_size == 0)
        throw EmptyStackPopException();
    if (_mode) {
        _current_size -= getOperandSize(get());
        _stack.pop();
    } else {
        _current_size -= 1;
        _stack.pop();
    }
}

void avm::Memory::clear()
{
    while (!isEmpty())
        pop();
}

avm::IOperand *avm::Memory::get()
{
    if (_stack.empty())
        throw CantLoadException();
    return (_stack.top());
}

void avm::Memory::load(int index)
{
    add(_registers[index]);
    _registers[index] = nullptr;
}

void avm::Memory::store(int index)
{
    _registers[index] = get();
    pop();
}

void avm::Memory::dup()
{
    add(Factory::createOperand(get()->getType(), get()->toString()));
}

void avm::Memory::swap()
{
    IOperand *first = get();
    pop();
    IOperand *second = get();
    pop();
    add(first);
    add(second);
}

bool avm::Memory::isEmpty() const
{
    return (_stack.empty());
}

size_t avm::Memory::getCurrentSize() const
{
    return (_current_size);
}

size_t avm::Memory::getMaxSize() const
{
    return (_size_max);
}

size_t avm::Memory::getOperandSize(IOperand *operand)
{
    switch (operand->getType()) {
        case (INT8): return (8);
            break;
        case (INT16): return (16);
            break;
        case (INT32): return (32);
            break;
        case (FLOAT): return (32);
            break;
        case (DOUBLE): return (64);
            break;
        default: return (0);
            break;
    }
}
