/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** IOComponent
*/

#ifndef IOCOMPONENT_HPP_
#define IOCOMPONENT_HPP_

#include <string>

namespace avm {
    class IOComponent {
        public:
            virtual ~IOComponent() = default;

            virtual bool isInput() const = 0;

            virtual std::string getLine() = 0;
            virtual void putLine(const std::string &line) = 0;
    };
}

#endif /* !IOCOMPONENT_HPP_ */
