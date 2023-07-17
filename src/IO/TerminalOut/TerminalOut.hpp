/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** TerminalOut
*/

#ifndef TERMINALOUT_HPP_
#define TERMINALOUT_HPP_

#include <iostream>

#include "IO/IOComponent.hpp"

namespace avm {
    class TerminalOut : public IOComponent {
        public:
            TerminalOut() = default;
            ~TerminalOut() = default;

            bool isInput() const override;

            std::string getLine() override;
            void putLine(const std::string &line) override;
    };
}

#endif /* !TERMINALOUT_HPP_ */
