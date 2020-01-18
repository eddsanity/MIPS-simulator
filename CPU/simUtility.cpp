#include "simUtility.h"

void
sleep(const uint16_t sleepPeriod)
{
	std::chrono::milliseconds timespan(sleepPeriod);
	std::this_thread::sleep_for(timespan);
}

void
togglePower(bool& powerStatus)
{
	powerStatus != powerStatus;
}

void
printRegisterFile(regFile& rf)
{
	std::cout << "PC:\t\t" << rf.getPC() << "\n";
	std::cout << "HI:\t\t" << rf.getHI() << "\tLO:\t\t" << rf.getLO() << "\n";
	for (int i = 0; i < 32; ++i)
		if (i % 2 == 0)
			std::cout << "reg $" << i << ": \t" << rf.getReg(i) << "\t";
		else
			std::cout << "reg $" << i << ": \t" << rf.getReg(i) << std::endl;
}