/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Processor
*/

#include "Processor.hpp"

avm::Processor::Processor(const unsigned int &frequency) : _frequency(frequency)
{
}

avm::command_t avm::Processor::run(const std::string &line)
{
    asm_command_t asm_command;
    command_t command;
    clock_gettime(CLOCK_REALTIME, &_time_start);
    asm_command.name = line.substr(0, line.find(' '));
    asm_command.value = line.substr(line.find(' ') + 1, line.size());
    command = _command_handler.run(asm_command);
    clock_gettime(CLOCK_REALTIME, &_time_end);
    applyFrequency();
    return command;
}

void avm::Processor::applyFrequency()
{
    return;
}
