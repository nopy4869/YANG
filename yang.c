//
//This is Yet Another Gameboy Emulator.
//
//Quick guide:
//	gameboycommon.c			-the definition of the cpu and some useful functions for indexing the register groups
//	gameboycpu.c			-Just the opcode implimentataion
//	gameboyinterrupts.c		-Just the interrupt handling
//	yang.c					-The main emulator core
//	yangpc.c				-The implimentation of the PC related function calls
//
//General Notes:
//	All platform specific code has been isolated into the various platform specific
//	files and is abstracted in the rest of the program as such.
//
//	The Gameboy was, afterall, a PoRtAbLe CoNsOlE =[%^)
//
//yangpc.c Notes:
//	Some code here has been borrowed from MSDN in relation to the Windows performance
//	counter, and some was borrowed from stackexchange for the Linux microsecond code
//
//Here before you now is the code, completely unfinished, maybe -P-o-k-e-m-o-n- something will run soon?
//

void loadcart();
void cpuinit();
void checkinput();
void checkinterrupts();

int main(int argc, char** argv)
{
	int x;
	cpu.cartloaded = 0;
	cpu.forceGBMode = 1;
	cpu.BreakOnWarn = 3;
	cpu.WarnLevel = 1;
	cpu.dbug = 0;
	if(loginit() != 0)
	{
		printf("Log init failed.\n");
		return 1;
	}
	printf("\r\n");
	msgprint("Yet ANother Gameboy\r\n\"Because the world NEEDS yet another\"\r\nCopyright 2016 nopy4869\r\n\r\n");
	msgprint("Initial setup complete!\r\n");
	for(x=1; x < argc; x++)
	{
		if(strncmp(argv[x], "-d", 2) == 0)
		{
			if(argv[x][2] != 0)
				cpu.dbug = atoi(&argv[x][2]);
			else
				cpu.dbug = 1;
			mesgprint(1, "Debug mode: %d\r\n", (int)cpu.dbug);
		}
		else if(strncmp(argv[x], "-B", 2) == 0)
		{
			if(argv[x][2] != 0)
				cpu.BreakOnWarn = atoi(&argv[x][2]);
			else
				cpu.BreakOnWarn = 1;
			mesgprint(1, "Execution stopping level: %d\r\n", (int)cpu.BreakOnWarn);
		}
		else if(strncmp(argv[x], "-W", 2) == 0)
		{
			if(argv[x][2] != 0)
				cpu.WarnLevel = atoi(&argv[x][2]);
			else
				cpu.BreakOnWarn = 1;
			mesgprint(1, "Execution warning level: %d\r\n", (int)cpu.WarnLevel);
		}
		else if(strncmp(argv[x], "-s", 2) == 0)
		{
			cpu.dbug = 3;
		}
		else if(strncmp(argv[x], "-c", 2) == 0)
		{
			cpu.forceGBMode = 0;
		}
		else if(strncmp(argv[x], "-g", 2) == 0)
		{
			cpu.forceGBMode = 1;
		}
		else if(strncmp(argv[x], "-w", 2) == 0)
		{
			cpu.FlagWindow = 1;
		}
		else if(strncmp(argv[x], "-b", 2) == 0)
		{
			cpu.FlagBackground = 1;
		}
		else if(strncmp(argv[x], "-o", 2) == 0)
		{
			cpu.FlagOAM = 1;
		}
		else
		{
			if(cpu.cartloaded == 1)
			{
				msgprint("Only one rom, please :(\r\n");
				cpu.cartloaded = 0;
				break;
			}
			loadcart(argv[x]);
			msgprint("Cartridge loaded!\r\n");
			cpu.cartloaded = 1;
		}
	}
	if(cpu.cartloaded == 0)
	{
		msgprint("\r\nInvalid arguments.\r\n\r\n");
		msgprint("\r\nArguments are as follows:\r\n");
		msgprint("    -d#       Sets debug level, # is between 0 and 3 inclusive\r\n");
		msgprint("               When no number is given, this defaults to level 1\r\n");
		msgprint("              Debug levels are as follows:\r\n");
		msgprint("                1:Logs and prints everything, breaks on every command, has a menu.\r\n");
		msgprint("                2:Logs and prints everything, doesn't stop after commands.\r\n");
		msgprint("                3:Logs everything, skips printing.\r\n");
		msgprint("                4:Prints everything, skips instruction logging, doesn't stop after commands.\r\n");
		msgprint("                5:Prints everything, skips instruction logging, breaks on every command.\r\n");
		msgprint("               WARNING: Logs with instruction logging get Very Big Very Fast...\r\n\r\n");
		msgprint("    -W#       Sets the level of execution bounds warning on address spaces\r\n");
		msgprint("               1 warns on execution from echo ram, 2 warns on\r\n");
		msgprint("               execution from IO and the undefined memory area.\r\n\r\n");
		msgprint("    -B#       Sets the level of execution limits on address spaces\r\n");
		msgprint("               1 exits on execution from echo ram, 2 exits on\r\n");
		msgprint("               execution from IO and the undefined memory area.\r\n");
		msgprint("              NOTE: In order to do anything, this must be at least\r\n");
		msgprint("                equal to the warn level (default is 1)\r\n\r\n");
		msgprint("    -s        Sets debug level to 3\r\n\r\n");
		msgprint("    -c        Force color mode\r\n\r\n");
		msgprint("    -g        Force original gameboy mode\r\n\r\n");
		msgprint("    -w -b -o  Turn on viewing tiledata for Window, Background,\r\n");
		msgprint("               and OAM respectively.\r\n\r\n");
		msgprint("Is your refridgerator running?\r\nThen you'd better catch it!\r\n\r\n");
		hang();
	}
	setup();
	cpuinit();
	msgprint("CPU setup complete!\r\n");
	for(;;)
	{
//		setcycletimer();
		if(cpu.halt == 0)
		{
			if(cpu.dbug > 0)
			{
				dodebug();
			}
			cycle();
			cpu.pc += 1;
		}
		else
		{
			cpu.cycle += 4;
		}
		checkinterrupts();
//		waitcycletimer();
	}
	return 0;
}
