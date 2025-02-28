#include "datas.hpp"
#include <chrono>

namespace Utils::DataHora
{

time_t obtenhaDataHoraAtual()
{
    auto now = std::chrono::system_clock::now();
    auto nowTimeT = std::chrono::system_clock::to_time_t(now);
    return nowTimeT;
}

} // namespace Utils::DataHora
