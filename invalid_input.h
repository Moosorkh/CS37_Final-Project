#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <string>

class InvalidInput
{
private:
    const std::string message;

public:
    InvalidInput(std::string input);
    void print_reason() const;
};

#endif