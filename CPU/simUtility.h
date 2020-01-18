#pragma once


#include <chrono>
#include <iostream>
#include <thread>

#include "..\include\regFile.hpp"
#include "..\include\memory.hpp"
#include "..\include\function_table.hpp"
#include "..\include\instruction.hpp"

#define POWER_ON 1
#define CLOCK_MS 200

void
sleep(const uint16_t);

void
togglePower(bool&);

void
printRegisterFile(regFile&);