void mesgprint(int num, char* msg, ...);
void msgprint(char* msg);
void linkterm(char indata);
void linkstop();
void dodebug();
void dumpstate();
void hang();
char setmem(int addr, unsigned char value);

extern char printing;

enum
{
	ROM_ONLY					= 0x00,
	ROM_MBC1					= 0x01,
	ROM_MBC1_RAM				= 0x02,
	ROM_MBC1_RAM_BATT			= 0x03,
	ROM_MBC2_RAM				= 0x05,
	ROM_MBC2_RAM_BATT			= 0x06,
	ROM_RAM						= 0x08,
	ROM_RAM_BATT				= 0x09,
	ROM_MMM01					= 0x0B,
	ROM_MMM01_SRAM				= 0x0C,
	ROM_MMM01_SRAM_BATT			= 0x0D,
	ROM_MBC3_TIMER_BATT			= 0x0F,
	ROM_MBC3_TIMER_RAM_BATT		= 0x10,
	ROM_MBC3					= 0x11,
	ROM_MBC3_RAM				= 0x12,
	ROM_MBC3_RAM_BATT			= 0x13,
	ROM_MBC5					= 0x19,
	ROM_MBC5_RAM				= 0x1A,
	ROM_MBC5_RAM_BATT			= 0x1B,
	ROM_MBC5_RUMBLE				= 0x1C,
	ROM_MBC5_RUMBLE_SRAM		= 0x1D,
	POCKET_CAMERA				= 0xFD,
	RHUDSON_HUC_3				= 0xFE,
	RHUDSON_HUC_1				= 0xFF
};

enum
{
	MODE_GMB,
	MODE_CGB,
	MODE_AGB
};

enum
{
	COLOR_WHITE,
	COLOR_LIGHT_GRAY,
	COLOR_DARK_GRAY,
	COLOR_BLACK
};

enum
{
	BG_MAP_0 = 0x9800,
	BG_MAP_1 = 0x9C00
};

char saveable [] = {
	0x03, 0x06,
	0x09, 0x0C,
	0x0D, 0x0F,
	0x10, 0x13,
	0x1B, 0x1D 
};
/*	 Interrupt Enable Register
    --------------------------- FFFF
     FAST Internal RAM
    --------------------------- FF80
     Empty but unusable for I/O			   //nonexistant in this version
    --------------------------- FF4C	   //expanded here to 80 in size
     I/O ports							   //expanded here to 80 in size
    --------------------------- FF00
     Empty but unusable for I/O
    --------------------------- FEA0
     Sprite Attrib Memory (OAM)
    --------------------------- FE00
     Echo of 4kB Work RAM (Bank CGB)
    --------------------------- F000
     Echo of 4kB Work RAM
    --------------------------- E000
     4kB Work RAM (Bank 1-7 CGB)
    --------------------------- D000
     4kB Work RAM
    --------------------------- C000
     8kB Cart RAM bank
    --------------------------- A000
     8kB Video RAM    (Bank 0-1 CGB)
    --------------------------- 8000 --
     16kB switchable ROM bank         |
    --------------------------- 4000  |= 32kB Cartrigbe
     16kB ROM bank #0                 |
    --------------------------- 0000 --
*/
struct memmap
	{
		void* chunk;
		int size;
		int start;
		char warn;
	};
	
struct gameboy
	{
//		unsigned char memory[0x10000];			//yeah, let's make things "easy" and define only the used memory
												//echo memory will be a LOT easier with this, because we can just
												//create MaPpInGs
												
		unsigned char rom[8*(1024)*(1024)];		//apparently the largest possible rom size?
		unsigned char cram[128*(1024)];			//apparently the largest possible cart ram size?
//		unsigned char screen[160][144];			//This is a lot of bytes...
//		unsigned char screen[64][64];			//But it wasn't even right, because 
													//A:The real size for the screen buffer is 256x256 pixels (32x32 sprites), and
													//B:Each pixel is really 2 bits anyway
		unsigned char* screen;					//which still wasn't right, because it's better in this case to just use a pointer
													//to the vram area it uses, for the sake of "consistency".
													
		unsigned int display[160][144];		//Which still wasn't... oh wait, nevermind, it's because screw logic, I want some freaking color :3

		unsigned char vram[16*(1024)];
		unsigned char wram[32*(1024)];
		unsigned char euro[0x60];				//Extra Unusable Rarely Opened memory lol :D
		unsigned char oam[0xA0];
		unsigned char io[0x80];
		unsigned char fram[0x80];
		
		unsigned char pad;
		
		unsigned char* carttype;		//DON'T FORGET TO ADD TO THESE THE START ADDRESS OF THE ROM
		unsigned char* romsize;
		unsigned char* ramsize;
		
//This is a troll line. Everything below here is mapped to
//			a memory location in the 4C block (IO)
//-------------------------------------------------------//
		
		
		unsigned char* P1;			//joypad
		unsigned char* SB;			//Serial buffer
		unsigned char* SC;			//Serial control
		unsigned char* DIV;			//Div register		Incremented 16384 times/second writing sets to 00
		unsigned char* TIMA;		//Timer counter
		unsigned char* TMA;			//Timer modulo
		unsigned char* TAC;			//Timer control
		unsigned char* IF;			//Interrupt flag
		
		
		unsigned char* nr10;
		unsigned char* nr11;
		unsigned char* nr12;
		unsigned char* nr13;
		unsigned char* nr14;
		unsigned char* nr21;
		unsigned char* nr22;
		unsigned char* nr23;
		unsigned char* nr24;
		unsigned char* nr30;
		unsigned char* nr31;
		unsigned char* nr32;
		unsigned char* nr33;
		unsigned char* nr34;
		unsigned char* nr41;
		unsigned char* nr42;
		unsigned char* nr43;
		unsigned char* nr44;
		unsigned char* nr50;
		unsigned char* nr51;
		unsigned char* nr52;
		
		unsigned char* wpram;
		
		unsigned char* LCDC;		//LCD control
		unsigned char* STAT;		//LCD status
		unsigned char* SCY;			//Scroll Y
		unsigned char* SCX;			//Scroll X
		unsigned char* LY;			//LCDC Y coord
		unsigned char* LYC;			//LCDC Y compare (Used with STAT)
		unsigned char* DMA;			//DMA's 0x8C bytes from (thisaddress * 0x100) into OAM
		unsigned char* BGP;			//BG pallete data
		unsigned char* OBP0;		//Obj0 pallete data
		unsigned char* OBP1;		//Obj1 pallete data
		unsigned char* WY;			//Window Y position
		unsigned char* WX;			//Window X position
		unsigned char* KEY1;		//CGB Speed switch
		unsigned char* SVBK;		//CGB Work Ram Bank
		unsigned char* RP;			//CGB IR port

//Remember the troll line? We killed it. The ultimate troll

		unsigned char* IE;		//Interrupt enable,		ADD from FRAM
		unsigned char IME;
		
		
		unsigned char a, b, c, d, e, f, h, l;
		unsigned short sp, pc;
		
		unsigned short breakpc[2];
		unsigned char breakgran;
		char breakset;
		
		unsigned char mbcmode;
		unsigned char mbcramen;
		
		unsigned char rombank;
		unsigned char crambank;
		unsigned char wrambank;
		unsigned char vrambank;
		unsigned char opcode;
		unsigned char err;
		
		unsigned char colormode;										//0x01 for color mode, 0x03 for doublespeed wait mode, 0x11 for doublespeed mode
		unsigned char ramen;
		unsigned char halt;
		
		unsigned char dbug;
		unsigned char FlagBackground;
		unsigned char FlagWindow;
		unsigned char FlagOAM;
		unsigned char WarnLevel;
		unsigned char BreakOnWarn;
		unsigned char SDL;
		unsigned char ispaused;
		unsigned char cartloaded;
		unsigned char forceGBMode;
		unsigned char stepthru;
		unsigned long long int cycle;
		unsigned long long int lastcycle;
		unsigned char lcdstate;
		unsigned long long int nextdiv;
		unsigned long long int nexttimer;
		unsigned long long int nextlcdchange;
		char romname[16];
		struct memmap mapping[12];
	};
	struct gameboy cpu;

void prelemmapmem()
{
	cpu.carttype	= &cpu.rom[0x0147];
	cpu.romsize		= &cpu.rom[0x0148];
	cpu.ramsize		= &cpu.rom[0x0149];
	cpu.P1			= &cpu.io[0x00];
	cpu.SB			= &cpu.io[0x01];
	cpu.SC			= &cpu.io[0x02];
	cpu.DIV			= &cpu.io[0x04];
	cpu.TIMA		= &cpu.io[0x05];
	cpu.TMA			= &cpu.io[0x06];
	cpu.TAC			= &cpu.io[0x07];
	cpu.IF			= &cpu.io[0x0F];
	cpu.nr10		= &cpu.io[0x10];
	cpu.nr11		= &cpu.io[0x11];
	cpu.nr12		= &cpu.io[0x12];
	cpu.nr13		= &cpu.io[0x13];
	cpu.nr14		= &cpu.io[0x14];
	cpu.nr21		= &cpu.io[0x16];
	cpu.nr22		= &cpu.io[0x17];
	cpu.nr23		= &cpu.io[0x18];
	cpu.nr24		= &cpu.io[0x19];
	cpu.nr30		= &cpu.io[0x1A];
	cpu.nr31		= &cpu.io[0x1B];
	cpu.nr32		= &cpu.io[0x1C];
	cpu.nr33		= &cpu.io[0x1D];
	cpu.nr34		= &cpu.io[0x1E];
	cpu.nr41		= &cpu.io[0x20];
	cpu.nr42		= &cpu.io[0x21];
	cpu.nr43		= &cpu.io[0x22];
	cpu.nr44		= &cpu.io[0x23];
	cpu.nr50		= &cpu.io[0x24];
	cpu.nr51		= &cpu.io[0x25];
	cpu.nr52		= &cpu.io[0x26];
	cpu.wpram		= &cpu.io[0x30];
	cpu.LCDC		= &cpu.io[0x40];
	cpu.STAT		= &cpu.io[0x41];
	cpu.SCY			= &cpu.io[0x42];
	cpu.SCX			= &cpu.io[0x43];
	cpu.LY			= &cpu.io[0x44];
	cpu.LYC			= &cpu.io[0x45];
	cpu.DMA			= &cpu.io[0x46];
	cpu.BGP			= &cpu.io[0x47];
	cpu.OBP0		= &cpu.io[0x48];
	cpu.OBP1		= &cpu.io[0x49];
	cpu.WY			= &cpu.io[0x4A];
	cpu.WX			= &cpu.io[0x4B];
	cpu.KEY1		= &cpu.io[0x4D];
	cpu.RP			= &cpu.io[0x56];
	cpu.SVBK		= &cpu.io[0x70];
	cpu.IE			= &cpu.fram[0x7F];
}

void domemmap()
{
	cpu.mapping[0].chunk   = cpu.rom;
	cpu.mapping[0].size    = 0x4000;
	cpu.mapping[0].start   = 0x0000;
	cpu.mapping[0].warn    = 0;
	
	cpu.mapping[1].chunk   = (cpu.rom + (cpu.rombank*0x4000));
	cpu.mapping[1].size    = 0x4000;
	cpu.mapping[1].start   = 0x4000;
	cpu.mapping[1].warn    = 0;
	
	cpu.mapping[2].chunk   = (cpu.vram + (cpu.vrambank*0x2000));
	cpu.mapping[2].size    = 0x2000;
	cpu.mapping[2].start   = 0x8000;
	cpu.mapping[2].warn    = 1;
	
	cpu.mapping[3].chunk   = (cpu.cram + (cpu.wrambank*0x2000));
	cpu.mapping[3].size    = 0x2000;
	cpu.mapping[3].start   = 0xA000;
	cpu.mapping[3].warn    = 1;
	
	cpu.mapping[4].chunk   = cpu.wram;
	cpu.mapping[4].size    = 0x1000;
	cpu.mapping[4].start   = 0xC000;
	cpu.mapping[4].warn    = 0;
	
	cpu.mapping[5].chunk   = (cpu.wram + (cpu.wrambank*0x1000));
	cpu.mapping[5].size    = 0x1000;
	cpu.mapping[5].start   = 0xD000;
	cpu.mapping[5].warn    = 0;
	
	cpu.mapping[6].chunk   = cpu.wram;
	cpu.mapping[6].size    = 0x1000;
	cpu.mapping[6].start   = 0xE000;
	cpu.mapping[6].warn    = 1;
	
	cpu.mapping[7].chunk   = (cpu.wram + (cpu.wrambank*0x1000));
	cpu.mapping[7].size    = 0x0E00;
	cpu.mapping[7].start   = 0xF000;
	cpu.mapping[7].warn    = 1;
	
	cpu.mapping[8].chunk   = cpu.oam;
	cpu.mapping[8].size    = 0x00A0;
	cpu.mapping[8].start   = 0xFE00;
	cpu.mapping[8].warn    = 1;
	
	cpu.mapping[9].chunk   = cpu.euro;
	cpu.mapping[9].size    = 0x0060;
	cpu.mapping[9].start   = 0xFEA0;
	cpu.mapping[9].warn    = 2;
	
	cpu.mapping[10].chunk   = cpu.io;
	cpu.mapping[10].size    = 0x0080;
	cpu.mapping[10].start   = 0xFF00;
	cpu.mapping[10].warn    = 2;
	
	
	cpu.mapping[11].chunk   = cpu.fram;
	cpu.mapping[11].size    = 0x0080;
	cpu.mapping[11].start   = 0xFF80;
	cpu.mapping[11].warn    = 0;
}

void cpuinit()
{
	prelemmapmem();
	cpu.colormode		= 0;
	cpu.cycle			= 0x00;
	cpu.pc				= 0x100;
	cpu.sp				= 0xFFFE;
	cpu.a				= 0x01;											//This is for Original Gameboys. A value of 0x11h would be for color gameboys
	cpu.f				= 0xB0;											//a 1 in bit 0 in this register signals that the system is a gameboy advanced
	cpu.b				= 0x00;
	cpu.c				= 0x13;
	cpu.d				= 0x00;
	cpu.e				= 0xD8;
	cpu.h				= 0x01;
	cpu.l				= 0x4D;
	cpu.IME				= 0x01;
	cpu.nextdiv			= 256;
	*cpu.DIV			= 0x00;
	*cpu.TIMA			= 0x00;
	*cpu.TMA			= 0x00;
	*cpu.TAC			= 0x00;
	*cpu.nr10			= 0x80;
	*cpu.nr11			= 0xBF;
	*cpu.nr12			= 0xF3;
	*cpu.nr14			= 0xBF;
	*cpu.nr21			= 0x3F;
	*cpu.nr22			= 0x00;
	*cpu.nr24			= 0xBF;
	*cpu.nr30			= 0x7F;
	*cpu.nr31			= 0xFF;
	*cpu.nr32			= 0x9F;
	*cpu.nr33			= 0xBF;
	*cpu.nr41			= 0xFF;
	*cpu.nr42			= 0x00;
	*cpu.nr43			= 0x00;
	*cpu.nr44			= 0xBF;
	*cpu.nr50			= 0x77;
	*cpu.nr51			= 0xF3;
	*cpu.nr52			= 0xF1;
	*cpu.LCDC			= 0x91;
	*cpu.STAT			= 0x85;
	*cpu.SCY			= 0x00;
	*cpu.SCX			= 0x00;
	*cpu.LY				= 0x00;
	*cpu.LYC			= 0x00;
	*cpu.BGP			= 0xFC;
	*cpu.OBP0			= 0xFF;
	*cpu.OBP1			= 0xFF;
	*cpu.WY				= 0x00;
	*cpu.WX				= 0x00;
	*cpu.IE				= 0x00;
	*cpu.P1				= 0x3F;
	
	//These next 7 are undocumented registers
	
	cpu.io[0x6C]		= 0xFF;											//0xFF if not in CGB mode
	cpu.io[0x72]		= 0x00;
	cpu.io[0x73]		= 0x00;
	cpu.io[0x74]		= 0xFF;											//0xFF if not in CGB mode
	cpu.io[0x75]		= 0x8F;
	cpu.io[0x76]		= 0x00;
	cpu.io[0x77]		= 0x00;
	
	//Ok that was suspenseful
	
	*cpu.KEY1			= 0x00;
	
	cpu.rombank			= 0x01;
	cpu.crambank		= 0x00;
	cpu.wrambank		= 0x01;
	cpu.vrambank		= 0x00;
	cpu.opcode			= 0x00;
	cpu.err				= 0x00;
	cpu.nextlcdchange	= 0x00;
	
	if((cpu.forceGBMode == 1) && (cpu.rom[0x0143] == 0xC0))
	{
		msgprint("Unable to run rom in Original Gameboy mode.\nGameboy Color Exclusive.\n");
		msgprint("Will proceed, but be WaRnEd\n");
	}
	else if(cpu.forceGBMode != 1)
	{
		if((cpu.rom[0x0143] == 0x80) || (cpu.rom[0x0143] == 0xC0))
		{
			cpu.colormode	= 1;
			cpu.a			= 0x11;
			cpu.f			= 0xB1;	
			cpu.io[0x6C]	= 0xFE;
			cpu.io[0x74]	= 0x00;
		}
	}
	printing = 1;
	domemmap();
	int x;
	unsigned char val = 0xFF;
	for(x = 0x8000; x < 0xFEA0; x++)
	{
		setmem(x, val);
		val += val - (val % 3);
	}
}

int SCREEN_WIDTH;
int SCREEN_HEIGHT;
int SCREEN_SCALE;

void mbc(int addr, int value)
{
	unsigned char* temp;
	temp = cpu.carttype;
	if((*temp == ROM_MBC1_RAM) || (*temp == ROM_MBC1_RAM_BATT))
	{
		if(addr <= 0x1FFF)
		{
			if((value & 0x0A) == 0x0A)
			{
				cpu.mbcramen = 1;
			}
			else
			{
				cpu.mbcramen = 0;
			}
		}
		if((0x2000 <= addr) && (addr <= 0x3FFF))
		{
			value &= 0x1F;
			if(value == 0)
			{
				value = 1;
			}
			cpu.rombank = (cpu.rombank | 0x1F) & (value | 0xE0);
		}
		if((0x4000 <= addr) && (addr <= 0x5FFF))
		{
			value = value & 0x03;
			if(cpu.mbcmode == 0)
			{
				value = value << 5;					//NOTE: Is this right?
				cpu.rombank = (cpu.rombank | 0x60) & (value | 0x1F);
			}
			else
			{
				cpu.crambank = value;
			}
			
		}
		if((0x6000 <= addr) && (addr <= 0x7FFF))
		{
			if(value == 0)
			{
				cpu.mbcmode = 0;					//NOTE: Note below might also apply here.
			}
			else if(value == 1)
			{
				cpu.mbcmode = 1;					//NOTE: This might need changing, docs say only rom banks 00-1F can be used in mode1 but doesn't specify the mbc clearing the upper 2 bits of the rom bank.
			}
		}
	}
								//This fUnCtIoN is
								//StUbBeD
}

unsigned short swapbytes(unsigned short bytes)
{
	unsigned short cache;
	cache = bytes >> 8;
	bytes = bytes << 8;
	bytes += cache;
	return bytes;
}

unsigned short bc()
{
	unsigned short result = 0;
	result += cpu.b;
	result = result << 8;
	result += cpu.c;
	return result;
}

unsigned short de()
{
	unsigned short result = 0;
	result += cpu.d;
	result = result << 8;
	result += cpu.e;
	return result;
}

unsigned short hl()
{
	unsigned short result = 0;
	result += cpu.h;
	result = result << 8;
	result += cpu.l;
	return result;
}

void hld()
{
	unsigned short result = 0;
	result += cpu.h;
	result = result << 8;
	result += cpu.l;
	result -= 1;
	cpu.l = result & 0x00FF;
	result = result >> 8;
	cpu.h = result;
}

void hli()
{
	unsigned short result = 0;
	result += cpu.h;
	result = result << 8;
	result += cpu.l;
	result += 1;
	cpu.l = result & 0x00FF;
	result = result >> 8;
	cpu.h = result;
}

void bcd()
{
	unsigned short result = 0;
	result += cpu.b;
	result = result << 8;
	result += cpu.c;
	result -= 1;
	cpu.c = result & 0x00FF;
	result = result >> 8;
	cpu.b = result;
}

void bci()
{
	unsigned short result = 0;
	result += cpu.b;
	result = result << 8;
	result += cpu.c;
	result += 1;
	cpu.c = result & 0x00FF;
	result = result >> 8;
	cpu.b = result;
}

void ded()
{
	unsigned short result = 0;
	result += cpu.d;
	result = result << 8;
	result += cpu.e;
	result -= 1;
	cpu.e = result & 0x00FF;
	result = result >> 8;
	cpu.d = result;
}

void dei()
{
	unsigned short result = 0;
	result += cpu.d;
	result = result << 8;
	result += cpu.e;
	result += 1;
	cpu.e = result & 0x00FF;
	result = result >> 8;
	cpu.d = result;
}

signed char sget8(int addr)
{
	int x;
	signed char* temp;
	domemmap();
	for(x=0;x<12;x++)
	{
		if((cpu.mapping[x].start <= addr)&&(addr < (cpu.mapping[x].start + cpu.mapping[x].size)))
		{
			if((cpu.pc == addr) && (cpu.mapping[x].warn >= cpu.WarnLevel))
			{
				mesgprint(1, "Execution at %04X.\r\n", addr);
				if(cpu.mapping[x].warn >= cpu.BreakOnWarn)
				{
					msgprint("Halting.\r\n");
					hang();
				}
				msgprint("Continuing.\r\n\r\n");
			}
			addr -= cpu.mapping[x].start;
			temp = cpu.mapping[x].chunk + addr;
			return *temp;
		}
		if(addr == 0xFFFF)
		{
			addr -= 0xFF80;
			temp = (signed char*)(cpu.fram + addr);
			return *temp;
		}
	}
	cpu.err = 1;
	mesgprint(1, "\nIt's sget8(%04X) again\n", addr);
	hang();
	return 0x00;
}

unsigned char get8(int addr)
{
	int x;
	unsigned char* temp;
	domemmap();
	for(x=0;x<12;x++)
	{
		if((cpu.mapping[x].start <= addr)&&(addr < (cpu.mapping[x].start + cpu.mapping[x].size)))
		{
			if((cpu.pc == addr) && (cpu.mapping[x].warn >= cpu.WarnLevel))
			{
				mesgprint(1, "Execution at %04X.\r\n", addr);
				if(cpu.mapping[x].warn >= cpu.BreakOnWarn)
				{
					msgprint("Halting.\r\n");
					hang();
				}
				msgprint("Continuing.\r\n\r\n");
			}
			addr -= cpu.mapping[x].start;
			temp = cpu.mapping[x].chunk + addr;
			return *temp;
		}
		if(addr == 0xFFFF)
		{
			addr -= 0xFF80;
			temp = cpu.fram + addr;
			return *temp;
		}
	}
	cpu.err = 1;
	mesgprint(1, "\nIt's get8(%04X) again\n", addr);
	hang();
	return 0x00;
}

unsigned short get16(int addr)
{
	int x;
	int work;
	int touched = 0;
	unsigned short result = 0;
	unsigned char* temp;
	domemmap();
	work = (addr+1);
	for(x=0;x<12;x++)
	{
		if((cpu.mapping[x].start <= work)&&(work < (cpu.mapping[x].start + cpu.mapping[x].size)))
		{
			work -= cpu.mapping[x].start;
			temp = cpu.mapping[x].chunk;
			temp += work;
			result = *temp;
			touched = 1;
			break;
		}
		if(work == 0x10000)
		{
			work -= 0x10000;
			temp = cpu.rom;
			temp += work;
			result = *temp;
			touched = 1;
			break;
		}
	}
	if(touched == 0)
	{
		mesgprint(1, "get16[0]: Bad read at %04X.\n", work);
	}
	result = result << 8;
	touched = 0;
	for(x=0;x<12;x++)
	{
		if((cpu.mapping[x].start <= addr)&&(addr < (cpu.mapping[x].start + cpu.mapping[x].size)))
		{
			addr -= cpu.mapping[x].start;
			temp = cpu.mapping[x].chunk + addr;
			result += *temp;
			touched = 1;
			break;
		}
		if(addr == 0xFFFF)
		{
			addr -= 0xFF80;
			temp = cpu.fram;
			temp += addr;
			result = *temp;
			touched = 1;
			break;
		}
	}
	if(touched == 0)
	{
		mesgprint(1, "get16[1]: Bad read at %04X.\n", addr);
	}
	return result;
}

/*	 Interrupt Enable Register
    --------------------------- FFFF
     FAST Internal RAM
    --------------------------- FF80
     Empty but unusable for I/O
    --------------------------- FF4C
     I/O ports
    --------------------------- FF00
     Empty but unusable for I/O
    --------------------------- FEA0
     Sprite Attrib Memory (OAM)
    --------------------------- FE00
     Echo of 4kB Work RAM (Bank CGB)
    --------------------------- F000
     Echo of 4kB Work RAM
    --------------------------- E000
     4kB Work RAM (Bank 1-7 CGB)
    --------------------------- D000
     4kB Work RAM
    --------------------------- C000
     8kB Cart RAM bank
    --------------------------- A000
     8kB Video RAM    (Bank 0-1 CGB)
    --------------------------- 8000 --
     16kB switchable ROM bank         |
    --------------------------- 4000  |= 32kB Cartrigbe
     16kB ROM bank #0                 |
    --------------------------- 0000 --
*/

/*

		unsigned char rombank;
		unsigned char crambank;
		unsigned char wrambank;
		unsigned char vrambank;
*/

char ioset(int addr, unsigned char value)
{
	int x;
	addr -= 0xFF00;
	cpu.io[addr] = value;
	if(addr == 0x01)
	{
//		printf("%c", value);
		linkterm(value);
	}
	if(addr == 0x02)
	{
		linkstop();
	}
	if(addr == 0x04)
	{
		cpu.io[0x04] = 0;
	}
	if(addr == 0x4C)
	{
		for(x=0; x < 0xA0; x++)
		{
			if(value < 0xF2)
				cpu.oam[x] = get8((value*0x100)+x);							//TODO: Make OAM DMAs take time. INSTANTANEOUS WRITES ARE NOT CORRECT!!!
		}
	}
	if(addr == 0x40)
	{
//		printf("%d, 0x%02X\n", cpu.cycle, value);
		if((value & 0x80) != 0x80)
		{
			msgprint("Stopping display\n");
			if(*cpu.LY <144)
			{
				mesgprint(2, "HARDWARE DAMAGE!!!\nLCD DISABLED NOT DURING VBLANK\nCycle: %d\n", cpu.cycle);
				hang();
			}
		}
		else if((value & 0x80) == 0x80)
		{
			msgprint("Starting display\n");	
		}
	}
	if((addr == 0x4D) && (value == 0x01));
	{
		if(cpu.colormode == 0x01)
			cpu.colormode = 0x03;
		if(cpu.colormode == 0x11)
			cpu.colormode = 0x31;
	}
	return value;
}

char setmem(int addr, unsigned char value)
{
	if((0x0000 <= addr)&&(addr < 0x4000))
		mbc(addr, value);
	if((0x4000 <= addr)&&(addr < 0x8000))
		mbc(addr, value);
	if((0x8000 <= addr)&&(addr < 0xA000))
		cpu.vram[(addr-0x8000) + (cpu.vrambank * ((8)*(1024)))] = value;
	if((0xA000 <= addr)&&(addr < 0xC000))
		cpu.cram[(addr-0xA000) + (cpu.crambank * ((8)*(1024)))] = value;
	if((0xC000 <= addr)&&(addr < 0xD000))
		cpu.wram[addr-0xC000] = value;
	if((0xD000 <= addr)&&(addr < 0xE000))
		cpu.wram[(addr-0xD000) + (cpu.wrambank * ((4)*(1024)))] = value;
	if((0xE000 <= addr)&&(addr < 0xF000))
		cpu.wram[addr-0xE000] = value;
	if((0xF000 <= addr)&&(addr < 0xFE00))
	{
//		printf("Writing to wram address %04X\n", addr);
		cpu.wram[(addr-0xF000) + (cpu.wrambank * ((4)*(1024)))] = value;
	}
	if((0xFE00 <= addr)&&(addr < 0xFEA0))
		cpu.oam[addr-0xFE00] = value;
	if((0xFEA0 <= addr)&&(addr < 0xFF00))
	{
		cpu.euro[addr - 0xFEA0] = value;
		msgprint(".");
	}
	if((0xFF00 <= addr)&&(addr < 0xFF80))
		ioset(addr, value);
//	if((0xFF4C <= addr)&&(addr < 0xFF80))
//		mbc(addr, value);
	if((0xFF80 <= addr)&&(addr <= 0xFFFF))
		cpu.fram[addr-0xFF80] = value;
	return 0;
}
