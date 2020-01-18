#include "CPU.h"

bool powerStatus = POWER_ON;
uint16_t clockRate = CLOCK_MS;

bool
initCPU(uint32_t memSize)
{
	Memory mem(memSize);
	regFile registerFile;
	FunctionTable funcTable;
	MIPSFunc func;
	uint32_t inputBinaryInstruction = 0;
	Instruction instr(0);
	while (powerStatus)
	{
		sleep(clockRate);
		printRegisterFile(registerFile);
		std::cout << ">";
		std::cin >> inputBinaryInstruction;
		instr = Instruction(inputBinaryInstruction);
		func = funcTable.getFunc(instr);
		func(instr, mem, registerFile);
		//std::cout << "\t\t\t================================\n";
	}

	return true;
}