/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Chipset
*/

#ifndef CHIPSET_HPP_
#define CHIPSET_HPP_

#include "Processing/Processor.hpp"
#include "Memory/Memory.hpp"
#include "IO/TerminalOut/TerminalOut.hpp"
#include "IO/CinReader/CinReader.hpp"
#include "IO/FileReader/FileReader.hpp"
#include "Processing/Exceptions/AssertFailException.hpp"

namespace avm {
    enum eOpType {
        ADD,
        SUB,
        MUL,
        DIV,
        MOD
    };

    class Chipset {
        public:
            Chipset(int ac, char **av);
            ~Chipset() = default;

            void run();

        private:
            void executeCommand();
            void dump();
            void assert();
            void math(eOpType opType);
            void load();
            void store();
            void print();

            Memory _memory;
            Processor _processor;
            command_t _command;
            IOComponent *_input;
            IOComponent *_output;
    };
}

#endif /* !CHIPSET_HPP_ */
