/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** main
*/

#include <utility>
#include "Processing/Chipset/Chipset.hpp"

int main(int ac, char **av)
{
    try {
        avm::Chipset chipset(ac, av);
        chipset.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
