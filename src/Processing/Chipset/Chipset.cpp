/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Chipset
*/

#include "Chipset.hpp"

avm::Chipset::Chipset(int ac, char **av)
{
    _output = new TerminalOut();
    if (ac < 2)
        _input = new CinReader();
    else {
        try {
            _input = new FileReader(av[1]);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }
    _command.type = eCommand::UNKNOWN_COMMAND_;
}

void avm::Chipset::run()
{
    std::string line;

    while (1) {
        executeCommand();
        line = _input->getLine();
        if (line[0] == ';' || line.empty())
            continue;
        _command = _processor.run(line);
    }
}

void avm::Chipset::executeCommand()
{
    try {
        switch (_command.type) {
            case PUSH_: _memory.add(Factory::createOperand((eOperandType)_command.param.type, _command.param.value)); break;
            case POP_: _memory.pop(); break;
            case CLEAR_: _memory.clear(); break;
            case DUP_: _memory.dup(); break;
            case SWAP_: _memory.swap(); break;
            case DUMP_: dump(); break;
            case ASSERT_: assert(); break;
            case eCommand::ADD_: math(eOpType::ADD); break;
            case eCommand::SUB_: math(eOpType::SUB); break;
            case eCommand::MUL_: math(eOpType::MUL); break;
            case eCommand::DIV_: math(eOpType::DIV); break;
            case eCommand::MOD_: math(eOpType::MOD); break;
            case eCommand::LOAD_: load(); break;
            case eCommand::STORE_: store(); break;
            case eCommand::PRINT_: print(); break;
            case EXIT_: exit(0); break;
            default: break;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _command.type = eCommand::UNKNOWN_COMMAND_;
}

void avm::Chipset::dump()
{
    std::vector<IOperand *> operands;
    while (_memory.isEmpty() == false) {
        operands.push_back(_memory.get());
        _memory.pop();
        _output->putLine(operands.back()->toString());
    }
    for (int i = operands.size() - 1; i >= 0; i--)
        _memory.add(operands[i]);
}

void avm::Chipset::assert()
{
    IOperand *val = _memory.get();

    if (val->toString() != _command.param.value || val->getType() != (eOperandType)_command.param.type)
        throw AssertFailException();
}

void avm::Chipset::math(eOpType opType)
{
    IOperand *val1 = _memory.get();
    _memory.pop();
    IOperand *val2 = _memory.get();
    _memory.pop();
    switch (opType) {
        case eOpType::ADD: _memory.add(*val1 + *val2); break;
        case eOpType::SUB: _memory.add(*val2 - *val1); break;
        case eOpType::MUL: _memory.add(*val1 * *val2); break;
        case eOpType::DIV: _memory.add(*val2 / *val1); break;
        case eOpType::MOD: _memory.add(*val2 % *val1); break;
        default: break;
    }
}

void avm::Chipset::load()
{
    if (_command.param.type > eOperandType::INT32)
        throw SyntaxException("Load can only be used on an integer");
    _memory.load(std::stoi(_command.param.value));
}

void avm::Chipset::store()
{
    if (_command.param.type > eOperandType::INT32)
        throw SyntaxException("Store can only be used on an integer");
    _memory.store(std::stoi(_command.param.value));
}

void avm::Chipset::print()
{
    IOperand *val = _memory.get();
    std::string line;

    if (val->getType() != eOperandType::INT8)
        throw SyntaxException("Print can only be used on an int8");
    line.push_back(std::stoi(val->toString()));
    _output->putLine(line);
}
