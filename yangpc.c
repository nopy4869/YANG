#include <stdio.h>
#include <stdlib.h>
#include <sdl2/sdl.h>
#include "gameboycommon.c"
#include "gameboycpu.c"

char printing = 1;

FILE* logfile;
FILE* link;

int SDLLOADED = 0;

#ifndef LINUX
#include <windows.h>

LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds, Frequency;

void waitcycletimer()
{
	unsigned short int cdiff;
	cdiff = cpu.cycle - cpu.lastcycle;
	if((cpu.colormode & 0x10) == 0x10)
		cdiff /= 8;
	else
		cdiff /= 4;
	for(;;)
	{
		QueryPerformanceCounter(&EndingTime);
		ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

		ElapsedMicroseconds.QuadPart *= 1000000;
		ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
		if(ElapsedMicroseconds.QuadPart > cdiff)
			break;
	}
}

void setcycletimer()
{
	QueryPerformanceFrequency(&Frequency); 
	QueryPerformanceCounter(&StartingTime);
}

#else
#include <time.h>

unsigned long long time_in_micros, start_time_in_micros;


void waitcycletimer()
{
	unsigned short int cdiff;
	cdiff = cpu.cycle - cpu.lastcycle;
	cdiff /= 4;
	struct timeval tv;
	for(;;)
	{
		gettimeofday(&tv,NULL);
		if(((1000000 * tv_sec + tv_usec) - start_time_in_micros) > cdiff)
			break;
	}
}

void setcycletimer()
{
	struct tm as;
	cpu.lastcycle = cpu.cycle;
	gettimeofday(&as,NULL);
	start_time_in_micros = 1000000 * as.tm_sec + as.tm_usec;
}
#endif

//#define GREY_SCALE_FACTOR 0x16
//#define GREY_SCALE_FACTOR 0x64
#define GREY_SCALE_FACTOR 0x85

SDL_Window* sWindow = NULL;
SDL_Surface* sScreen = NULL;
SDL_Window* sWindow2 = NULL;
SDL_Surface* sScreen2 = NULL;
SDL_Window* sWindow3 = NULL;
SDL_Surface* sScreen3 = NULL;
SDL_Window* sWindow4 = NULL;
SDL_Surface* sScreen4 = NULL;
SDL_Event e;
SDL_AudioSpec device;
SDL_AudioDeviceID devicenum;

void exit(int __status);
void SDLExit();
int SDLInit();
void SetFBPixel(int pixx, int pixy, int pixc);

signed int fb[160][144];

void hang()
{
	msgprint("Core Error\r\n");
	if(cpu.cartloaded)
	{
		char temp = cpu.dbug;
		cpu.dbug = 2;
		dodebug();
		cpu.dbug = temp;
		dumpstate();
	}
	SDLExit();
	exit(1);
}

void dumpstate()
{
	FILE* dump;
	unsigned char temp;
	int loop;
	dump = fopen("cpu.state", "wb+");
	if(dump == NULL)
	{
		msgprint("Failed to open state file.\r\n");
		return;
	}
	fwrite(&cpu.IME, 1, 1, dump);
	fwrite(&cpu.mbcmode, 1, 1, dump);
	fwrite(&cpu.mbcramen, 1, 1, dump);
		
	fwrite(&cpu.rombank, 1, 1, dump);
	fwrite(&cpu.crambank, 1, 1, dump);
	fwrite(&cpu.wrambank, 1, 1, dump);
	fwrite(&cpu.vrambank, 1, 1, dump);
	fwrite(&cpu.opcode, 1, 1, dump);
	fwrite(&cpu.err, 1, 1, dump);
		
	fwrite(&cpu.colormode, 1, 1, dump);
	fwrite(&cpu.ramen, 1, 1, dump);
	fwrite(&cpu.halt, 1, 1, dump);
		
	fwrite(&cpu.dbug, 1, 1, dump);
	fwrite(&cpu.SDL, 1, 1, dump);
	fwrite(&cpu.ispaused, 1, 1, dump);
	fwrite(&cpu.forceGBMode, 1, 1, dump);
	fwrite(&cpu.stepthru, 1, 1, dump);
	fwrite(&cpu.lcdstate, 1, 1, dump);
	fwrite(&cpu.a, 1, 1, dump);
	fwrite(&cpu.b, 1, 1, dump);
	fwrite(&cpu.c, 1, 1, dump);
	fwrite(&cpu.d, 1, 1, dump);
	fwrite(&cpu.e, 1, 1, dump);
	fwrite(&cpu.f, 1, 1, dump);
	fwrite(&cpu.h, 1, 1, dump);
	fwrite(&cpu.l, 1, 1, dump);
	fwrite(&cpu.sp, 2, 1, dump);
	fwrite(&cpu.pc, 2, 1, dump);
	fwrite(&cpu.cycle, 8, 1, dump);
	fwrite(&cpu.lastcycle, 8, 1, dump);
	fwrite(&cpu.nextdiv, 8, 1, dump);
	fwrite(&cpu.nexttimer, 8, 1, dump);
	fwrite(&cpu.nextlcdchange, 8, 1, dump);
	fclose(dump);
	dump = fopen("crash.dump", "wb+");
	if(dump == NULL)
	{
		msgprint("Failed to open dump file.\r\n");
		return;
	}
	for(loop = 0x0000; loop < 0x10000; loop++)
	{
		temp = get8(loop);
		cpu.pc = temp - 1;
		fwrite(&temp, 1, 1, dump);
	}
	fclose(dump);
	msgprint("Dumped state!\r\n");
	return;
}

void dodebug()
{
	int temp;
	if(cpu.dbug < 4)
	{
		fprintf(logfile, "PC: %04X	CYCLE: %I64d\r\n", cpu.pc, cpu.cycle);
		temp = cpu.pc;
		cpu.pc -= 1;
		fprintf(logfile, "Data: %02X %02X %02X %02X\r\n", get8(temp), get8(temp+1), get8(temp+2), get8(temp+3));
		if(get8(temp) == 0xCB)
			fprintf(logfile, "Data: %04X\r\n", get16(cpu.pc+1));
		cpu.pc = temp;
		fprintf(logfile, "Registers:\r\n");
		fprintf(logfile, " A:  %02X        F: %02X\r\n", cpu.a, cpu.f);
		fprintf(logfile, " B:  %02X        C: %02X\r\n", cpu.b, cpu.c);
		fprintf(logfile, " D:  %02X        E: %02X\r\n", cpu.d, cpu.e);
		fprintf(logfile, " H:  %02X        L: %02X\r\n", cpu.h, cpu.l);
		fprintf(logfile, "SP:  %04X   [SP]: %04X\r\n\r\n", cpu.sp, get16(cpu.sp));
		fprintf(logfile, "Graphics:\r\n");
		fprintf(logfile, "Y: %d		C: %d\r\n\r\n", *cpu.LY, *cpu.LYC);
	}
	if(cpu.dbug == 3)
	{
		return;
	}
	char input = 0;
	if(cpu.breakset)
	{
		if(!((cpu.breakpc[0] <= cpu.cycle)&&(cpu.cycle <= cpu.breakpc[1])))
		{
			return;
		}
	}
	else
	{
		printf("PC: %04X	CYCLE: %I64d\n", cpu.pc, cpu.cycle);
		temp = cpu.pc;
		cpu.pc -= 1;
		printf("Data: %02X %02X %02X %02X\r\n", get8(temp), get8(temp+1), get8(temp+2), get8(temp+3));
		if(get8(temp) == 0xCB)
			printf("Data: %04X\n", get16(temp+1));
		cpu.pc = temp;
		printf("Registers:\n");
		printf(" A:  %02X        F: %02X\n", cpu.a, cpu.f);
		printf(" B:  %02X        C: %02X\n", cpu.b, cpu.c);
		printf(" D:  %02X        E: %02X\n", cpu.d, cpu.e);
		printf(" H:  %02X        L: %02X\n", cpu.h, cpu.l);
		printf("SP:  %04X   [SP]: %04X\n\n", cpu.sp, get16(cpu.sp));
		printf("Graphics:\n");
		printf("Y: %d		C: %d\n\n", *cpu.LY, *cpu.LYC);
		if((cpu.dbug < 2) || (cpu.dbug == 5))
			input = getchar();
		if(input == 'n')
		{
			cpu.breakset = 1;
			cpu.breakpc[0] = cpu.pc;
			cpu.breakpc[1] = cpu.pc + cpu.breakgran;
			cpu.breakset = 1;
		}
		else if(input == 'b')
		{
			cpu.breakset = 0;
		}
		else if(input == 'd')
		{
			dumpstate();
		}
		else if(input == 'm')
		{
			printf("Menu!\n");
			printf("Type command!\n");
			for(;;)
			{
				printf("1-5 for break granularity\n");
				input = getchar();
				if(input == '1')
					cpu.breakgran = 1;
				else if(input == '2')
					cpu.breakgran = 2;
				else if(input == '3')
					cpu.breakgran = 3;
				else if(input == '4')
					cpu.breakgran = 4;
				else if(input == '5')
					cpu.breakgran = 5;
				else if(input == '6')
					break;
			}
		}
	}
	return;
}

void stop()
{
	if(cpu.colormode == 0x03)
	{
		cpu.colormode = 0x11;
		*cpu.KEY1 = 0x80;
	}
	if(cpu.colormode == 0x31)
	{
		cpu.colormode = 0x01;
		*cpu.KEY1 = 0x00;
	}
}

void checkinput()
{
	unsigned char oldpad = cpu.pad;
	while(SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if( e.type == SDL_WINDOWEVENT )
		{
			if( e.window.event == SDL_WINDOWEVENT_CLOSE )
				hang();
		}
		//User presses a key
		else if( e.type == SDL_KEYDOWN )
		{
			//Select surfaces based on key press
			switch( e.key.keysym.sym )
			{
				case SDLK_DOWN:
					cpu.pad = cpu.pad | 0x80;
					break;
				case SDLK_UP:
					cpu.pad = cpu.pad | 0x40;
					break;
				case SDLK_LEFT:
					cpu.pad = cpu.pad | 0x20;
					break;
				case SDLK_RIGHT:
					cpu.pad = cpu.pad | 0x10;
					break;
				case SDLK_z:
					cpu.pad = cpu.pad | 0x08;
					break;
				case SDLK_x:
					cpu.pad = cpu.pad | 0x04;
					break;
				case SDLK_s:
					cpu.pad = cpu.pad | 0x02;
					break;
				case SDLK_a:
					cpu.pad = cpu.pad | 0x01;
					break;
				case SDLK_f:
					dodebug();
					break;
				default:
					printf("Unknown input pressed\n");
					break;
			}
		}
		else if( e.type == SDL_KEYUP )
		{
			//Select surfaces based on key press
			switch( e.key.keysym.sym )
			{
				case SDLK_DOWN:
					cpu.pad = cpu.pad & 0x7F;
					break;
				case SDLK_UP:
					cpu.pad = cpu.pad & 0xBF;
					break;
				case SDLK_LEFT:
					cpu.pad = cpu.pad & 0xDF;
					break;
				case SDLK_RIGHT:
					cpu.pad = cpu.pad & 0xEF;
					break;
				case SDLK_z:
					cpu.pad = cpu.pad & 0xF7;
					break;
				case SDLK_x:
					cpu.pad = cpu.pad & 0xFB;
					break;
				case SDLK_s:
					cpu.pad = cpu.pad & 0xFD;
					break;
				case SDLK_a:
					cpu.pad = cpu.pad & 0xFE;
					break;
				default:
					printf("Unknown input released\n");
					break;
			}
		}
	}
	if(oldpad != cpu.pad)
	{
		cpu.halt = 0;
		if((*cpu.P1 & 0x30) == 0x30)
		{
			unsigned char bpad = cpu.pad & 0x0F;
			unsigned char dpad = cpu.pad & 0xF0;
			dpad = dpad >> 4;
			dpad = dpad | bpad;
			*cpu.P1 = dpad;
		}
		else if((*cpu.P1 & 0x30) == 0x10)
		{
			unsigned char dpad = cpu.pad & 0xF0;
			dpad = dpad >> 4;
			dpad += *cpu.P1 & 0xF0;
			*cpu.P1 = dpad;
		}
		else if((*cpu.P1 & 0x30) == 0x20)
		{
			unsigned char bpad = cpu.pad & 0x0F;
			bpad += *cpu.P1 & 0xF0;
			*cpu.P1 = bpad;
		}
		else
		{
			return;
		}
//		if(cpu.forceGBMode == 1)
//		{
			cpu.io[0x0F] |= 0x10;
//		}
	}
}

void mesgprint(int num, char* msg, ...)
{
	int x;
	int temp[4];
	va_list args;
	va_start(args, msg);
	if(num > 3)
		num = 4;
	for(x = 0; x < num; x++)
	{
		temp[x] = va_arg(args,int);
	}
	switch(num)
	{
		case 1:
			printf(msg, temp[0]);
			if(SDLLOADED == 0) break;
			fprintf(logfile, msg, temp[0]);
			break;
		case 2:
			printf(msg, temp[0], temp[1]);
			if(SDLLOADED == 0) break;
			fprintf(logfile, msg, temp[0], temp[1]);
			break;
		case 3:
			printf(msg, temp[0], temp[1], temp[2]);
			if(SDLLOADED == 0) break;
			fprintf(logfile, msg, temp[0], temp[1], temp[2]);
			break;
		case 4:
			printf(msg, temp[0], temp[1], temp[2], temp[3]);
			if(SDLLOADED == 0) break;
			fprintf(logfile, msg, temp[0], temp[1], temp[2], temp[3]);
			break;
		default:
			printf(msg);
			if(SDLLOADED == 0) break;
			fprintf(logfile, msg);
			break;
	}
	va_end(args);
	return;
}

void msgprint(char* msg)
{
	if(SDLLOADED == 0)
		printf(msg);
	else
	{
		fprintf(logfile, msg);
		if(printing == 1)
			printf(msg);
	}
}

void loadcart(char* romname)
{
	int x = 1024;
	void* pt;
	FILE* rom;
	mesgprint(1, "\r\nFilename: %s\r\n\r\n", romname);
	rom = fopen(romname, "rb");
	if(rom == NULL)
	{
		msgprint("Invalid file.\r\n");
		hang();
	}
	pt = cpu.rom;
	while(x == 1024)
	{
		x = fread(pt,32,1024,rom);
		pt += (32*x);
	}
	fclose(rom);
	msgprint("Rom file closed.\r\n");
	
	cpu.carttype = &cpu.rom[0x0147];
	mesgprint(1, "Cart type: %02X\r\n", (unsigned int) *cpu.carttype);
	
	for(x=0;x<10;x++)
	{
		if(*cpu.carttype == saveable[x])
		{
			rom = fopen("file.sav", "rb");
			if(rom == NULL)
				break;
			fread(cpu.cram,128,1024,rom);
			fclose(rom);
		}
	}
}

int setup()
{
	int success = 0;
	if( SDLInit() != 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = 1;
		exit(1);
	}
	SDLLOADED = 1;
	return success;
}

int loginit()
{
	
	logfile = fopen("log.txt", "wb+");
	if(logfile == NULL)
		return 1;
	link = fopen("link.bin", "wb+");
	if(link == NULL)
		return 1;
	return 0;
}

int SDLInit()
{
	int x, y;
	SCREEN_SCALE = 1;
	SCREEN_WIDTH = 160*SCREEN_SCALE;
	SCREEN_HEIGHT = 144*SCREEN_SCALE;
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER ) < 0 )
	{
		printf("SDL Error: %s\n", SDL_GetError() );
		return 1;
	}
	sWindow = SDL_CreateWindow( "YANG v0.01 (display broken)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if(sWindow == NULL)
	{
		return 1;
	}
	sScreen = SDL_GetWindowSurface( sWindow );
	if(cpu.FlagBackground)
	{
		sWindow2 = SDL_CreateWindow( "Background", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256, 256, SDL_WINDOW_SHOWN );
		if(sWindow2 == NULL)
		{
			return 1;
		}
		sScreen2 = SDL_GetWindowSurface( sWindow2 );
	}
	if(cpu.FlagWindow)
	{
		sWindow3 = SDL_CreateWindow( "Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256, 256, SDL_WINDOW_SHOWN );
		if(sWindow3 == NULL)
		{
			return 1;
		}
		sScreen3 = SDL_GetWindowSurface( sWindow3 );
	}
	if(cpu.FlagOAM)
	{
		sWindow4 = SDL_CreateWindow( "OAM (Not coded yet)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256, 256, SDL_WINDOW_SHOWN );
		if(sWindow4 == NULL)
		{
			return 1;
		}
		sScreen4 = SDL_GetWindowSurface( sWindow4 );
	}
	for(x = 0; x < 160; x++)
		for(y = 0; y < 144; y++)
			SetFBPixel(x,y,0xFFFFFF);
//	if(SDLAudioInit() != 0)
//	{
//		return 2;
//	}
	return 0;
}

void SDLExit()
{
	fclose(logfile);
	fclose(link);
	SDL_Quit();
}

void SetFBPixel(int pixx, int pixy, int pixc)
{
	SDL_PixelFormat *fmt;
	Uint32 sx;
	Uint8 Bpp;
	
	fmt = sScreen->format;
	Bpp = fmt->BytesPerPixel;
	sx = sScreen->w;
	
	int* point;
	point = sScreen->pixels+(((Bpp*sx)*(pixy))+(Bpp*pixx));
	*point = pixc;
}

void SetWPixel(int pixx, int pixy, int pixc, unsigned char window)
{
	SDL_PixelFormat *fmt;
	Uint32 sx;
	Uint8 Bpp;
	SDL_Surface* surf;
	
	if(window == 0)
	{
		surf = sScreen2;
	}
	else if(window == 1)
	{
		surf = sScreen3;
	}
	else if(window == 2)
	{
		surf = sScreen4;
	}
	
	fmt = surf->format;
	Bpp = fmt->BytesPerPixel;
	sx = surf->w;
	
	int* point;
	point = surf->pixels+(((Bpp*sx)*(pixy))+(Bpp*pixx));
	*point = pixc;
}

void resize(char ud)
{
	/*												TODO: Rewrite this
	SDL_DestroyWindow(sWindow);
	if((ud == 1) && (SCREEN_SCALE < 21))
	{
		SCREEN_SCALE += 1;
	}
	if((ud == 0) && (SCREEN_SCALE > 1))
	{
		SCREEN_SCALE -= 1;
	}
	SDL_Quit();
	SDLInit();
	*/
}

unsigned int getbgtile(char tilenum, char bg)
{
	union tileu
	{
		unsigned char utile;
		signed char stile;
	} tile;
	tile.utile = tilenum;
	unsigned int atile;
	if((*cpu.LCDC & 0x04) != 0x04)										//TODO: This is in no way right, right?.
	{
		atile = tile.utile + 0x8000;
	}
	else
	{
		atile = tile.stile + 0x9000;
	}
	return atile;
}

unsigned int gettile(char tilenum)
{
	union tileu
	{
		unsigned char utile;
		signed char stile;
	} tile;
	tile.utile = tilenum;
	unsigned int atile;
	if((*cpu.LCDC & 0x10) == 0x10)										//TODO: This is in no way right, right?.
	{
		atile = tile.utile + 0x8000;
	}
	else
	{
		atile = tile.stile + 0x9000;
	}
	return atile;
}

void drawline(unsigned char y)
{
	char drawBG, drawWin, OAMOnTop;
	drawBG   = 1;
	drawWin  = 1;
	OAMOnTop = 0;
	
	if((*cpu.LCDC & 0x80) != 0x80)
	{
		int x;
			for(x = 0; x < 160; x++)
				SetFBPixel(x,y,0x008080);
		return;
	}
	if((*cpu.LCDC & 0x01) == 0x00)
	{
		if((cpu.colormode == 0) && (cpu.forceGBMode == 1))
		{
			drawBG = 0;													//DMG: background becomes white
		}
		if((cpu.colormode == 1) && (cpu.forceGBMode == 0))
		{
			OAMOnTop = 1;												//CGB: background & window lose priority
		}
		if((cpu.colormode == 0) && (cpu.forceGBMode == 0))
		{
			drawBG  = 0;												//CGB in DMG: background & window become white
			drawWin = 0;
		}
	}
	
}

void drawtile(unsigned char tilenum, char x, char y, char window)
{
	unsigned int taddress = 0x9800;
	unsigned char tile[16];
	unsigned char pallet[4];
	unsigned int tbitmap[8][8];
	signed char tind1, tind2;
	unsigned char tind3;
	unsigned char temp;
	if(window == 1)
	{
		taddress += 0x400;
	}
	taddress += tilenum;
	unsigned int address;
	address = gettile(get8(taddress));								//NOTE: This is broken?
	for(tind1 = 0; tind1 < 16; tind1++)
	{
		tile[tind1] = get8(address+tind1);
	}
	temp = *cpu.BGP;
	for(tind1 = 0; tind1 < 4; tind1++)
	{
		pallet[tind1] = (temp >> (tind1*2)) & 0x03;
	}
	for(tind1 = 0; tind1 < 8; tind1++)
	{
		for(tind2 = 0; tind2 < 8; tind2++)
		{
			tind3 = tind1 * 2;
			tbitmap[tind1][tind2] = 0;
			tbitmap[tind1][tind2] = ((tile[tind3] >> (8 - tind2)) & 0x01);
			tbitmap[tind1][tind2] |= ((tile[tind3+1] >> (7 - tind2)) & 0x02);
			temp = 255 - (pallet[tbitmap[tind1][tind2]] * GREY_SCALE_FACTOR);
			tbitmap[tind1][tind2] = temp | (temp << 8) | (temp << 16);
			SetWPixel((8*x)+tind2,(8*y)+tind1,tbitmap[tind1][tind2],window);
//			printf("%02X", tbitmap[tind1][tind2]);
		}
//		printf("\n");
	}
}

void drawscreen()														//This function is called on the GB's VBlank in order to blit the framebuffer.
{
	SDL_UpdateWindowSurface( sWindow );
}

void drawbackground()													//This function is called on the GB's VBlank in order to blit the framebuffer.
{
	char tilex, tiley;
	//20 tiles x 18 tiles
	for(tiley = 0; tiley < 32; tiley++)
	{
		for(tilex = 0; tilex < 32; tilex++)
		{
			if(cpu.FlagBackground)
				drawtile((tiley*32)+tilex, tilex, tiley, 0);
			if(cpu.FlagWindow)
				drawtile((tiley*32)+tilex, tilex, tiley, 1);
		}
	}
	if(cpu.FlagBackground)
		SDL_UpdateWindowSurface( sWindow2 );
	if(cpu.FlagWindow)
		SDL_UpdateWindowSurface( sWindow3 );
	if(cpu.FlagOAM)
		SDL_UpdateWindowSurface( sWindow4 );
}

void dodisp()
{
	switch (*cpu.STAT & 0x03)
	{
		case 2:
			break;
		case 3:
			break;
		case 0:
			drawline(*cpu.LY);
			break;
		case 1:
			if((cpu.FlagBackground == 1) || (cpu.FlagWindow == 1) || (cpu.FlagOAM == 1))
				drawbackground();
			drawscreen();
			break;
	}
}

void linkterm(char indata)
{
	fwrite(&indata, 1, 1, link);
	printf("%c", indata);
	return;
}

void linkstop()
{
	cpu.io[0x01] = 0xFF;			//No gameboy present.
	cpu.io[0x02] &= 0x7F;
	cpu.io[0x0F] |= 0x08;
	return;
}

#include "gameboyinterrupts.c"
#include "yang.c"
