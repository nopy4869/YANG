void GBInt(short int address);

void checkinterrupts()
{																	//Draw the screen on vblank before handling the interrupt! :D
	if(cpu.cycle >= cpu.nextdiv)
	{
		cpu.nextdiv += 256;
		cpu.io[0x04]++;
	}
	if((cpu.cycle >= cpu.nexttimer) && ((cpu.io[0x07] & 0x04) == 0x04))
	{
		switch (cpu.io[0x07] & 0x03)
		{
			case 0:
				cpu.nexttimer += 1024;
				break;
			case 1:
				cpu.nexttimer += 16;
				break;
			case 2:
				cpu.nexttimer += 64;
				break;
			case 3:
				cpu.nexttimer += 256;
				break;
			default:
				msgprint("Some kind of timer error?\r\n");
				break;
		}
		cpu.io[0x05] += 1;
		if(cpu.io[0x05] == 0x00)
		{
			cpu.io[0x0F] |= 0x04;									//had to replace a reference to cpu.io[0x0F] with this. WHAT? TODO: Find out why
			cpu.io[0x05] = cpu.io[0x06];
		}
	}
	checkinput();
//	printf("%d, %d, %d, %d\n", (int)cpu.cycle, (int)cpu.nextlcdchange, (int)(*cpu.LCDC & 0x80), (int)(*cpu.STAT & 0x03));
	if(cpu.cycle >= cpu.nextlcdchange)	//Draw the screen on vblank before handling the interrupt! :D
	{
		switch (*cpu.STAT & 0x03)
		{
			case 2:
				*cpu.STAT = *cpu.STAT | 0x01;
				break;
			case 3:
				*cpu.STAT = *cpu.STAT & 0xFC;
				break;
			case 0:
				if(*cpu.LY == 144)
					*cpu.STAT = *cpu.STAT | 0x01;
				else
					*cpu.STAT = *cpu.STAT | 0x02;
				break;
			case 1:
				if((*cpu.LY >= 154)||(*cpu.LY == 0))
					*cpu.STAT += 0x01;
				break;
		}
		switch (*cpu.STAT & 0x03)
		{
			case 2:
				if((*cpu.STAT & 0x20) == 0x20)
				{
					cpu.io[0x0F] = cpu.io[0x0F] | 0x02;
				}
				cpu.nextlcdchange += 80;
				break;
			case 3:
				cpu.nextlcdchange += 172;
				break;
			case 0:
				if((*cpu.STAT & 0x0F) == 0x0F)
				{
					cpu.io[0x0F] = cpu.io[0x0F] | 0x02;
				}
				cpu.nextlcdchange += 204;
				cpu.io[0x44]++;
				break;
			case 1:
				cpu.io[0x0F] = cpu.io[0x0F] | 0x01;
				if((*cpu.STAT & 0x10) == 0x10)
				{
					cpu.io[0x0F] = cpu.io[0x0F] | 0x02;
				}
				cpu.nextlcdchange += 456;
				cpu.io[0x44]++;
				break;
		}
		if(*cpu.LY == *cpu.LYC)
		{
			*cpu.STAT = *cpu.STAT & 0xFB;
			if((*cpu.STAT & 0x40) == 0x40)
			{
				cpu.io[0x0F] = cpu.io[0x0F] | 0x02;
			}
		}
		else
		{
			*cpu.STAT = *cpu.STAT | 0x04;
		}
		dodisp();
	}
	
	if((cpu.IME == 1) && (cpu.io[0x0F] != 0))
	{
		if(((cpu.io[0x0F] & 0x01) == 0x01) && ((*cpu.IE & 0x01) == 0x01))
		{
			GBInt(0x40);
			cpu.io[0x0F] &= 0xFE;
		}
		if(((cpu.io[0x0F] & 0x02) == 0x02) && ((*cpu.IE & 0x02) == 0x02))
		{
			GBInt(0x48);
			cpu.io[0x0F] &= 0xFD;
		}
		if(((cpu.io[0x0F] & 0x04) == 0x04) && ((*cpu.IE & 0x04) == 0x04))
		{
			GBInt(0x50);
			cpu.io[0x0F] &= 0xFB;
		}
		if(((cpu.io[0x0F] & 0x08) == 0x08) && ((*cpu.IE & 0x08) == 0x08))
		{
			GBInt(0x58);
			cpu.io[0x0F] &= 0xF7;
		}
		if(((cpu.io[0x0F] & 0x10) == 0x10) && ((*cpu.IE & 0x10) == 0x10))
		{
			GBInt(0x60);
			cpu.io[0x0F] &= 0xEF;
		}
	}
	
	if(*cpu.LY >= 154)
		*cpu.LY = 0x00;
}

void GBInt(short int address)
{
	cpu.IME = 0;
	setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
	setmem(cpu.sp--, (cpu.pc & 0x00FF));
	cpu.pc = address;
	cpu.cycle += 12;
}
