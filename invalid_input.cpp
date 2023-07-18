#include "InvalidInput.h"
#include <iostream>

InvalidInput::InvalidInput(std::string input) : message("Invalid input \"" + input + "\".\n") {}

void InvalidInput::print_reason() const
{
    std::cout << message;
}