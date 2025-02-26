#include "strings.hpp"

#include <algorithm>
#include <locale>

namespace Utils::Strings
{

void apararInicio(std::string& input)
{
    input.erase(input.begin(),
                std::find_if(input.begin(),
                             input.end(),
                             [](unsigned char caractere)
                             { return !std::isspace(caractere); }));
}

// trim from end (in place)
void apararFinal(std::string& input)
{
    input.erase(std::find_if(input.rbegin(),
                             input.rend(),
                             [](unsigned char caractere)
                             { return !std::isspace(caractere); })
                    .base(),
                input.end());
}

} // namespace Utils::Strings
