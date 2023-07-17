/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CommandHandler
*/

#include "CommandHandler.hpp"

avm::command_t avm::CommandHandler::run(const avm::asm_command_t &command)
{
    if (command.name == "push")
        return (push(command));
    if (command.name == "pop")
        return (pop());
    if (command.name == "clear")
        return (clear());
    if (command.name == "dup")
        return (dup());
    if (command.name == "swap")
        return (swap());
    if (command.name == "dump")
        return (dump());
    if (command.name == "assert")
        return (assert(command));
    if (command.name == "add")
        return (add());
    if (command.name == "sub")
        return (sub());
    if (command.name == "mul")
        return (mul());
    if (command.name == "div")
        return (div());
    if (command.name == "mod")
        return (mod());
    if (command.name == "load")
        return (load(command));
    if (command.name == "store")
        return (store(command));
    if (command.name == "print")
        return (print());
    if (command.name == "exit")
        return (exit());
    throw UnknownInstructionException(command.name + " is not a valid instruction");
}

int avm::CommandHandler::getParamType(const std::string &value)
{
    if (value.find("int8") != std::string::npos)
        return eParamType::INT_8;
    if (value.find("int16") != std::string::npos)
        return eParamType::INT_16;
    if (value.find("int32") != std::string::npos)
        return eParamType::INT_32;
    if (value.find("float") != std::string::npos)
        return eParamType::FLOAT_;
    if (value.find("double") != std::string::npos)
        return eParamType::DOUBLE_;
    throw SyntaxException(value + " is not a valid type");
}

std::string avm::CommandHandler::getParamValue(const std::string &value)
{
    std::string tmp = value.substr(value.find('(') + 1);
    tmp = tmp.substr(0, tmp.find(')'));
    if (tmp == "")
        throw SyntaxException(value + " is not a valid value");
    return tmp;
}

avm::command_t avm::CommandHandler::push(const avm::asm_command_t &command)
{
    command_t cmd;

    cmd.type = PUSH_;
    cmd.param.type = getParamType(command.value);
    cmd.param.value = getParamValue(command.value);
    return cmd;
}

avm::command_t avm::CommandHandler::pop()
{
    command_t cmd;

    cmd.type = POP_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::clear()
{
    command_t cmd;

    cmd.type = CLEAR_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::dup()
{
    command_t cmd;

    cmd.type = DUP_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::swap()
{
    command_t cmd;

    cmd.type = SWAP_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::dump()
{
    command_t cmd;

    cmd.type = DUMP_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::assert(const avm::asm_command_t &command)
{
    command_t cmd;

    cmd.type = ASSERT_;
    cmd.param.type = getParamType(command.value);
    cmd.param.value = getParamValue(command.value);
    return cmd;
}

avm::command_t avm::CommandHandler::add()
{
    command_t cmd;

    cmd.type = ADD_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::sub()
{
    command_t cmd;

    cmd.type = SUB_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::mul()
{
    command_t cmd;

    cmd.type = MUL_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::div()
{
    command_t cmd;

    cmd.type = DIV_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::mod()
{
    command_t cmd;

    cmd.type = MOD_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::load(const avm::asm_command_t &command)
{
    command_t cmd;

    cmd.type = LOAD_;
    cmd.param.type = getParamType(command.value);
    cmd.param.value = getParamValue(command.value);
    return cmd;
}

avm::command_t avm::CommandHandler::store(const avm::asm_command_t &command)
{
    command_t cmd;

    cmd.type = STORE_;
    cmd.param.type = getParamType(command.value);
    cmd.param.value = getParamValue(command.value);
    return cmd;
}

avm::command_t avm::CommandHandler::print()
{
    command_t cmd;

    cmd.type = PRINT_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}

avm::command_t avm::CommandHandler::exit()
{
    command_t cmd;

    cmd.type = EXIT_;
    cmd.param.type = UNKNOWN_TYPE_;
    cmd.param.value = "";
    return cmd;
}
