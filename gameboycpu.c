void msgprint(char* msg);
void hang();
void stop();

inline char fn(char input)
{
	return input >> 4;
}

inline char ln(char input)
{
	return input & 0x0F;
}

inline void oprun()
{
	msgprint("\"Unsupported opcode %02X\r\n\", cpu.opcode");
}

void cb()
{
	unsigned short cache;
	unsigned short cache2;
	cpu.opcode = get8(++cpu.pc);
	switch (cpu.opcode)
	{
        case 0x00:
                cpu.f = 0x80;
		        cache = cpu.b & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.b = cpu.b << 1;
                cpu.b = cpu.b | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x01:
                cpu.f = 0x80;
		        cache = cpu.c & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.c = cpu.c << 1;
                cpu.c = cpu.c | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x02:
                cpu.f = 0x80;
		        cache = cpu.d & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.d = cpu.d << 1;
                cpu.d = cpu.d | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x03:
                cpu.f = 0x80;
		        cache = cpu.e & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.e = cpu.e << 1;
                cpu.e = cpu.e | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x04:
                cpu.f = 0x80;
		        cache = cpu.h & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.h = cpu.h << 1;
                cpu.h = cpu.h | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x05:
                cpu.f = 0x80;
		        cache = cpu.l & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.l = cpu.l << 1;
                cpu.l = cpu.l | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x06:
                cpu.f = 0x80;
		        cache = get8(hl()) & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                setmem(hl(), (get8(hl()) << 1));
                setmem(hl(), (get8(hl()) | cache2));
                cpu.f = cpu.f | cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x07:
                cpu.f = 0x80;
		        cache = cpu.a & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.a = cpu.a << 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x08:
                cpu.f = 0x80;
		        cache = cpu.b & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.b = cpu.b >> 1;
                cpu.b = cpu.b | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x09:
                cpu.f = 0x80;
		        cache = cpu.c & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.c = cpu.c >> 1;
                cpu.c = cpu.c | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x0A:
                cpu.f = 0x80;
		        cache = cpu.d & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.d = cpu.d >> 1;
                cpu.d = cpu.d | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x0B:
                cpu.f = 0x80;
		        cache = cpu.e & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.e = cpu.e >> 1;
                cpu.e = cpu.e | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x0C:
                cpu.f = 0x80;
		        cache = cpu.h & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.h = cpu.h >> 1;
                cpu.h = cpu.h | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x0D:
                cpu.f = 0x80;
		        cache = cpu.l & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.l = cpu.l >> 1;
                cpu.l = cpu.l | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x0E:
                cpu.f = 0x80;
		        cache = get8(hl()) & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                setmem(hl(), (get8(hl()) >> 1));
                setmem(hl(), (get8(hl()) | cache2));
                cpu.f = cpu.f | cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x0F:
                cpu.f = 0x80;
		        cache = cpu.a & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.a = cpu.a >> 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x10:
                cpu.f = 0x90;
		        cache = cpu.b & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.b = cpu.b << 1;
                cpu.b = cpu.b | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x11:
                cpu.f = 0x90;
		        cache = cpu.c & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.c = cpu.c << 1;
                cpu.c = cpu.c | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x12:
                cpu.f = 0x90;
		        cache = cpu.d & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.d = cpu.d << 1;
                cpu.d = cpu.d | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x13:
                cpu.f = 0x90;
		        cache = cpu.e & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.e = cpu.e << 1;
                cpu.e = cpu.e | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x14:
                cpu.f = 0x90;
		        cache = cpu.h & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.h = cpu.h << 1;
                cpu.h = cpu.h | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x15:
                cpu.f = 0x90;
		        cache = cpu.l & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.l = cpu.l << 1;
                cpu.l = cpu.l | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x16:
                cpu.f = 0x90;
		        cache = get8(hl()) & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                setmem(hl(), (get8(hl()) << 1));
                setmem(hl(), (get8(hl()) | cache2));
                cpu.f = cpu.f | cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x17:
                cpu.f = 0x90;
		        cache = cpu.a & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.a = cpu.a << 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x18:
                cpu.f = 0x90;
		        cache = cpu.b & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.b = cpu.b >> 1;
                cpu.b = cpu.b | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x19:
                cpu.f = 0x90;
		        cache = cpu.c & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.c = cpu.c >> 1;
                cpu.c = cpu.c | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x1A:
                cpu.f = 0x90;
		        cache = cpu.d & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.d = cpu.d >> 1;
                cpu.d = cpu.d | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x1B:
                cpu.f = 0x90;
		        cache = cpu.e & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.e = cpu.e >> 1;
                cpu.e = cpu.e | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x1C:
                cpu.f = 0x90;
		        cache = cpu.h & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.h = cpu.h >> 1;
                cpu.h = cpu.h | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x1D:
                cpu.f = 0x90;
		        cache = cpu.l & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.l = cpu.l >> 1;
                cpu.l = cpu.l | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x1E:
                cpu.f = 0x90;
		        cache = get8(hl()) & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                setmem(hl(), (get8(hl()) >> 1));
                setmem(hl(), (get8(hl()) | cache2));
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x1F:
                cpu.f = 0x90;
		        cache = cpu.a & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.a = cpu.a >> 1;
                cpu.a = cpu.a | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x20:
                cpu.f = 0x80;
		        cache = cpu.b & 0x80;
                cache = cache >> 3;
                cpu.b = cpu.b << 1;
                cpu.f = cpu.f | cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x21:
                cpu.f = 0x80;
		        cache = cpu.c & 0x80;
                cache = cache >> 3;
                cpu.c = cpu.c << 1;
                cpu.f = cpu.f | cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x22:
                cpu.f = 0x80;
		        cache = cpu.d & 0x80;
                cache = cache >> 3;
                cpu.d = cpu.d << 1;
                cpu.f = cpu.f | cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x23:
                cpu.f = 0x80;
		        cache = cpu.e & 0x80;
                cache = cache >> 3;
                cpu.e = cpu.e << 1;
                cpu.f = cpu.f | cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x24:
                cpu.f = 0x80;
		        cache = cpu.h & 0x80;
                cache = cache >> 3;
                cpu.h = cpu.h << 1;
                cpu.f = cpu.f | cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x25:
                cpu.f = 0x80;
		        cache = cpu.l & 0x80;
                cache = cache >> 3;
                cpu.l = cpu.l << 1;
                cpu.f = cpu.f | cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x26:
                cpu.f = 0x80;
		        cache = get8(hl()) & 0x80;
                cache = cache >> 3;
                setmem(hl(), (get8(hl()) << 1));
                cpu.f = cpu.f | cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x27:
                cpu.f = 0x80;
		        cache = cpu.a & 0x80;
                cache = cache >> 3;
                cpu.a = cpu.a << 1;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x28:
                cpu.f = 0x80;
		        cache = cpu.b & 0x01;
                cache = cache << 4;
                cache2 = cpu.b & 0x80;
                cpu.b = cpu.b >> 1;
                cpu.b = cpu.b | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x29:
                cpu.f = 0x80;
		        cache = cpu.c & 0x01;
                cache = cache << 4;
                cache2 = cpu.c & 0x80;
                cpu.c = cpu.c >> 1;
                cpu.c = cpu.c | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x2A:
                cpu.f = 0x80;
		        cache = cpu.d & 0x01;
                cache = cache << 4;
                cache2 = cpu.d & 0x80;
                cpu.d = cpu.d >> 1;
                cpu.d = cpu.d | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x2B:
                cpu.f = 0x80;
		        cache = cpu.e & 0x01;
                cache = cache << 4;
                cache2 = cpu.e & 0x80;
                cpu.e = cpu.e >> 1;
                cpu.e = cpu.e | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x2C:
                cpu.f = 0x80;
		        cache = cpu.h & 0x01;
                cache = cache << 4;
                cache2 = cpu.h & 0x80;
                cpu.h = cpu.h >> 1;
                cpu.h = cpu.h | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x2D:
                cpu.f = 0x80;
		        cache = cpu.l & 0x01;
                cache = cache << 4;
                cache2 = cpu.l & 0x80;
                cpu.l = cpu.l >> 1;
                cpu.l = cpu.l | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x2E:
                cpu.f = 0x80;
		        cache = get8(hl()) & 0x01;
                cache = cache << 4;
                cache2 = get8(hl()) & 0x80;
                setmem(hl(), (get8(hl()) >> 1));
                setmem(hl(), (get8(hl()) | cache2));
                cpu.f = cpu.f | cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x2F:
                cpu.f = 0x80;
		        cache = cpu.a & 0x01;
                cache = cache << 4;
                cache2 = cpu.a & 0x80;
                cpu.a = cpu.a >> 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
		case 0x30:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.b & 0x0F;
		        cpu.b = cpu.b >> 4;
		        cpu.b += cache << 4;
		        break;
		case 0x31:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.c & 0x0F;
		        cpu.c = cpu.c >> 4;
		        cpu.c += cache << 4;
		        break;
		case 0x32:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.d & 0x0F;
		        cpu.d = cpu.d >> 4;
		        cpu.d += cache << 4;
		        break;
		case 0x33:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.e & 0x0F;
		        cpu.e = cpu.e >> 4;
		        cpu.e += cache << 4;
		        break;
		case 0x34:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.h & 0x0F;
		        cpu.h = cpu.h >> 4;
		        cpu.h += cache << 4;
		        break;
		case 0x35:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.l & 0x0F;
		        cpu.l = cpu.l >> 4;
		        cpu.l += cache << 4;
		        break;
		case 0x36:
		        cpu.f = cpu.f & 0x80;
		        cache = get8(hl()) & 0x0F;
		        setmem(hl(), (get8(hl()) >> 4));
		        setmem(hl(), (get8(hl()) + (cache << 4)));
                cpu.cycle += 8;
		        break;
		case 0x37:
		        cpu.f = cpu.f & 0x80;
		        cache = cpu.a & 0x0F;
		        cpu.a = cpu.a >> 4;
		        cpu.a += cache << 4;
		        break;
        case 0x38:
                cpu.f = 0x80;
		        cache = cpu.b & 0x01;
                cache = cache << 4;
                cpu.b = cpu.b >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.b == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x39:
                cpu.f = 0x80;
		        cache = cpu.c & 0x01;
                cache = cache << 4;
                cpu.c = cpu.c >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.c == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x3A:
                cpu.f = 0x80;
		        cache = cpu.d & 0x01;
                cache = cache << 4;
                cpu.d = cpu.d >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.d == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x3B:
                cpu.f = 0x80;
		        cache = cpu.e & 0x01;
                cache = cache << 4;
                cpu.e = cpu.e >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.e == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x3C:
                cpu.f = 0x80;
		        cache = cpu.h & 0x01;
                cache = cache << 4;
                cpu.h = cpu.h >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.h == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x3D:
                cpu.f = 0x80;
		        cache = cpu.l & 0x01;
                cache = cache << 4;
                cpu.l = cpu.l >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.l == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x3E:
                cpu.f = 0x80;
		        cache = get8(hl()) & 0x01;
                cache = cache << 4;
                setmem(hl(), (get8(hl()) >> 1));
                cpu.f = cpu.f | cache;
                if(get8(hl()) == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x3F:
                cpu.f = 0x80;
		        cache = cpu.a & 0x01;
                cache = cache << 4;
                cpu.a = cpu.a >> 1;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x40:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x41:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x42:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x43:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x44:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x45:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x46:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x47:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 0;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x48:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x49:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x4A:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x4B:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x4C:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x4D:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x4E:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x4F:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 1;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x50:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x51:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x52:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x53:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x54:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x55:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x56:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x57:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 2;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x58:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x59:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x5A:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x5B:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x5C:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x5D:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x5E:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x5F:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 3;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x60:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x61:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x62:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x63:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x64:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x65:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x66:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x67:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 4;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x68:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x69:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x6A:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x6B:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x6C:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x6D:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x6E:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x6F:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 5;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x70:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x71:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x72:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x73:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x74:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x75:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x76:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x77:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 6;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x78:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.b >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x79:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.c >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x7A:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.d >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x7B:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.e >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x7C:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.h >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x7D:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.l >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x7E:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = get8(hl()) >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0x7F:
                cpu.f = cpu.f & 0x10;
                cpu.f = cpu.f | 0x20;
                cache = cpu.a >> 7;
                cache = cache & 0x01;
                if(cache == 1)
					cpu.f = cpu.f | 0x80;
                break;
        case 0x80:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0x81:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0x82:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0x83:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0x84:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0x85:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0x86:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0x87:
                cache = 0x01 << 0;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0x88:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0x89:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0x8A:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0x8B:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0x8C:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0x8D:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0x8E:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0x8F:
                cache = 0x01 << 1;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0x90:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0x91:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0x92:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0x93:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0x94:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0x95:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0x96:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0x97:
                cache = 0x01 << 2;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0x98:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0x99:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0x9A:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0x9B:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0x9C:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0x9D:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0x9E:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0x9F:
                cache = 0x01 << 3;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0xA0:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0xA1:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0xA2:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0xA3:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0xA4:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0xA5:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0xA6:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0xA7:
                cache = 0x01 << 4;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0xA8:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0xA9:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0xAA:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0xAB:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0xAC:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0xAD:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0xAE:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0xAF:
                cache = 0x01 << 5;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0xB0:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0xB1:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0xB2:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0xB3:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0xB4:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0xB5:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0xB6:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0xB7:
                cache = 0x01 << 6;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0xB8:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.b = cpu.b & cache;
                break;
        case 0xB9:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.c = cpu.c & cache;
                break;
        case 0xBA:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.d = cpu.d & cache;
                break;
        case 0xBB:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.e = cpu.e & cache;
                break;
        case 0xBC:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.h = cpu.h & cache;
                break;
        case 0xBD:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.l = cpu.l & cache;
                break;
        case 0xBE:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                setmem(hl(), (get8(++cpu.pc) & cache));
                cpu.cycle += 8;
                break;
        case 0xBF:
                cache = 0x01 << 7;
                cache = cache ^ 0xFF;
                cpu.a = cpu.a & cache;
                break;
        case 0xC0:
                cache = 0x01 << 0;
                cpu.b = cpu.b | cache;
                break;
        case 0xC1:
                cache = 0x01 << 0;
                cpu.c = cpu.c | cache;
                break;
        case 0xC2:
                cache = 0x01 << 0;
                cpu.d = cpu.d | cache;
                break;
        case 0xC3:
                cache = 0x01 << 0;
                cpu.e = cpu.e | cache;
                break;
        case 0xC4:
                cache = 0x01 << 0;
                cpu.h = cpu.h | cache;
                break;
        case 0xC5:
                cache = 0x01 << 0;
                cpu.l = cpu.l | cache;
                break;
        case 0xC6:
                cache = 0x01 << 0;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xC7:
                cache = 0x01 << 0;
                cpu.a = cpu.a | cache;
                break;
        case 0xC8:
                cache = 0x01 << 1;
                cpu.b = cpu.b | cache;
                break;
        case 0xC9:
                cache = 0x01 << 1;
                cpu.c = cpu.c | cache;
                break;
        case 0xCA:
                cache = 0x01 << 1;
                cpu.d = cpu.d | cache;
                break;
        case 0xCB:
                cache = 0x01 << 1;
                cpu.e = cpu.e | cache;
                break;
        case 0xCC:
                cache = 0x01 << 1;
                cpu.h = cpu.h | cache;
                break;
        case 0xCD:
                cache = 0x01 << 1;
                cpu.l = cpu.l | cache;
                break;
        case 0xCE:
                cache = 0x01 << 1;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xCF:
                cache = 0x01 << 1;
                cpu.a = cpu.a | cache;
                break;
        case 0xD0:
                cache = 0x01 << 2;
                cpu.b = cpu.b | cache;
                break;
        case 0xD1:
                cache = 0x01 << 2;
                cpu.c = cpu.c | cache;
                break;
        case 0xD2:
                cache = 0x01 << 2;
                cpu.d = cpu.d | cache;
                break;
        case 0xD3:
                cache = 0x01 << 2;
                cpu.e = cpu.e | cache;
                break;
        case 0xD4:
                cache = 0x01 << 2;
                cpu.h = cpu.h | cache;
                break;
        case 0xD5:
                cache = 0x01 << 2;
                cpu.l = cpu.l | cache;
                break;
        case 0xD6:
                cache = 0x01 << 2;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xD7:
                cache = 0x01 << 2;
                cpu.a = cpu.a | cache;
                break;
        case 0xD8:
                cache = 0x01 << 3;
                cpu.b = cpu.b | cache;
                break;
        case 0xD9:
                cache = 0x01 << 3;
                cpu.c = cpu.c | cache;
                break;
        case 0xDA:
                cache = 0x01 << 3;
                cpu.d = cpu.d | cache;
                break;
        case 0xDB:
                cache = 0x01 << 3;
                cpu.e = cpu.e | cache;
                break;
        case 0xDC:
                cache = 0x01 << 3;
                cpu.h = cpu.h | cache;
                break;
        case 0xDD:
                cache = 0x01 << 3;
                cpu.l = cpu.l | cache;
                break;
        case 0xDE:
                cache = 0x01 << 3;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xDF:
                cache = 0x01 << 3;
                cpu.a = cpu.a | cache;
                break;
        case 0xE0:
                cache = 0x01 << 4;
                cpu.b = cpu.b | cache;
                break;
        case 0xE1:
                cache = 0x01 << 4;
                cpu.c = cpu.c | cache;
                break;
        case 0xE2:
                cache = 0x01 << 4;
                cpu.d = cpu.d | cache;
                break;
        case 0xE3:
                cache = 0x01 << 4;
                cpu.e = cpu.e | cache;
                break;
        case 0xE4:
                cache = 0x01 << 4;
                cpu.h = cpu.h | cache;
                break;
        case 0xE5:
                cache = 0x01 << 4;
                cpu.l = cpu.l | cache;
                break;
        case 0xE6:
                cache = 0x01 << 4;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xE7:
                cache = 0x01 << 4;
                cpu.a = cpu.a | cache;
                break;
        case 0xE8:
                cache = 0x01 << 5;
                cpu.b = cpu.b | cache;
                break;
        case 0xE9:
                cache = 0x01 << 5;
                cpu.c = cpu.c | cache;
                break;
        case 0xEA:
                cache = 0x01 << 5;
                cpu.d = cpu.d | cache;
                break;
        case 0xEB:
                cache = 0x01 << 5;
                cpu.e = cpu.e | cache;
                break;
        case 0xEC:
                cache = 0x01 << 5;
                cpu.h = cpu.h | cache;
                break;
        case 0xED:
                cache = 0x01 << 5;
                cpu.l = cpu.l | cache;
                break;
        case 0xEE:
                cache = 0x01 << 5;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xEF:
                cache = 0x01 << 5;
                cpu.a = cpu.a | cache;
                break;
        case 0xF0:
                cache = 0x01 << 6;
                cpu.b = cpu.b | cache;
                break;
        case 0xF1:
                cache = 0x01 << 6;
                cpu.c = cpu.c | cache;
                break;
        case 0xF2:
                cache = 0x01 << 6;
                cpu.d = cpu.d | cache;
                break;
        case 0xF3:
                cache = 0x01 << 6;
                cpu.e = cpu.e | cache;
                break;
        case 0xF4:
                cache = 0x01 << 6;
                cpu.h = cpu.h | cache;
                break;
        case 0xF5:
                cache = 0x01 << 6;
                cpu.l = cpu.l | cache;
                break;
        case 0xF6:
                cache = 0x01 << 6;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xF7:
                cache = 0x01 << 6;
                cpu.a = cpu.a | cache;
                break;
        case 0xF8:
                cache = 0x01 << 7;
                cpu.b = cpu.b | cache;
                break;
        case 0xF9:
                cache = 0x01 << 7;
                cpu.c = cpu.c | cache;
                break;
        case 0xFA:
                cache = 0x01 << 7;
                cpu.d = cpu.d | cache;
                break;
        case 0xFB:
                cache = 0x01 << 7;
                cpu.e = cpu.e | cache;
                break;
        case 0xFC:
                cache = 0x01 << 7;
                cpu.h = cpu.h | cache;
                break;
        case 0xFD:
                cache = 0x01 << 7;
                cpu.l = cpu.l | cache;
                break;
        case 0xFE:
                cache = 0x01 << 7;
                setmem(hl(), (get8(hl()) | cache));
                cpu.cycle += 8;
                break;
        case 0xFF:
                cache = 0x01 << 7;
                cpu.a = cpu.a | cache;
                break;
		default:
		        oprun();
		        break;
	}
}

void cycle()
{
	unsigned short cache;
	unsigned short cache2;
	signed short   cache3;
	signed short   cache4;
	unsigned int   cache5;
	signed char    cache6;
	cpu.opcode = get8(cpu.pc);
	switch (cpu.opcode)
	{
        case 0x00:														//NOP
                if(cpu.err == 1)
                {
					msgprint("00\r\n");
					hang();
				}
				cpu.cycle += 4;
                break;
        case 0x01:
				cpu.c = get8(++cpu.pc);
				cpu.b = get8(++cpu.pc);
				cpu.cycle += 12;
                break;
        case 0x02:
                setmem(bc(), cpu.a);
				cpu.cycle += 8;
                break;
        case 0x03:
                bci();
				cpu.cycle += 8;
                break;
        case 0x04:
                cpu.b++;
				cpu.f = cpu.f & 0x10;
                if((cpu.b & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.b == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x05:
                cpu.b--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.b & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.b == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x06:
                cpu.b = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x07:
                cpu.f = 0x80;
		        cache = cpu.a & 0x80;
                cache = cache >> 3;
                cache2 = cache;
                cache2 = cache2 >> 4;
                cpu.a = cpu.a << 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0x08:														//IGNORE Z80 SPEC!
                cache = get16(++cpu.pc);
                setmem(cache++, (cpu.sp >> 8));
                setmem(cache, cpu.sp);
                cpu.pc++;
				cpu.cycle += 20;
                break;
        case 0x09:
				cache5 = hl() + bc();
				if(cache5 > 0xFFFF)
					cpu.f |= 0x10;
				if((cpu.h & 0x0F) > ((cache5 & 0x0F00) >> 8))
					cpu.f |= 0x20;
				cpu.h = (cache5 & 0xFF00) >> 8;
				cpu.l = cache5 & 0xFF;
				cpu.cycle += 8;
                break;
        case 0x0A:
		        cpu.a = get8(bc());
				cpu.cycle += 8;
                break;
        case 0x0B:
                bcd();
				cpu.cycle += 8;
                break;
        case 0x0C:
                cpu.c++;
				cpu.f = cpu.f & 0x10;
                if((cpu.c & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.c == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x0D:
                cpu.c--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.c & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.c == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x0E:
                cpu.c = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x0F:
                cpu.f = 0x80;
		        cache = cpu.a & 0x01;
                cache = cache << 4;
                cache2 = cache;
                cache2 = cache2 << 3;
                cpu.a = cpu.a >> 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0x10:														//IGNORE Z80 SPEC!
                stop();
				cpu.cycle += 4;
                break;
        case 0x11:
				cpu.e = get8(++cpu.pc);
				cpu.d = get8(++cpu.pc);
				cpu.cycle += 12;
                break;
        case 0x12:
                setmem(de(), cpu.a);
				cpu.cycle += 8;
                break;
        case 0x13:
                dei();
				cpu.cycle += 8;
                break;
        case 0x14:
                cpu.d++;
				cpu.f = cpu.f & 0x10;
                if((cpu.d & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.d == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x15:
                cpu.d--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.d & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.d == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x16:
                cpu.d = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x17:
                cpu.f = 0x90;
		        cache = cpu.a & 0x80;
                cache = cache >> 3;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 >> 4;
                cpu.a = cpu.a << 1;
                cpu.a = cpu.a | cache2;
                cpu.f = cpu.f | cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0x18:
                cache = cpu.pc;
                cache6 = sget8(++cpu.pc);
                cpu.pc = cache + cache6;
				cpu.pc++;
				cpu.cycle += 12;
                break;
        case 0x19:
				cache5 = hl() + de();
				if(cache5 > 0xFFFF)
					cpu.f |= 0x10;
				if((cpu.h & 0x0F) > ((cache5 & 0x0F00) >> 8))
					cpu.f |= 0x20;
				cpu.h = (cache5 & 0xFF00) >> 8;
				cpu.l = cache5 & 0xFF;
				cpu.cycle += 8;
                break;
        case 0x1A:
		        cpu.a = get8(de());
				cpu.cycle += 8;
                break;
        case 0x1B:
                ded();
				cpu.cycle += 8;
                break;
        case 0x1C:
                cpu.e++;
				cpu.f = cpu.f & 0x10;
                if((cpu.e & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.e == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x1D:
                cpu.e--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.e & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.e == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x1E:
                cpu.e = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x1F:
                cpu.f = 0x90;
		        cache = cpu.a & 0x01;
                cache = cache << 4;
                cache2 = cpu.f & 0x10;
                cache2 = cache2 << 3;
                cpu.a = cpu.a >> 1;
                cpu.a = cpu.a | cache2;
                cache = cache & 0x90;
                cpu.f = cpu.f & cache;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0x20:
				if((cpu.f & 0x80) != 0x80)
				{
					cache = cpu.pc;
					cache6 = sget8(++cpu.pc);
					cpu.pc = cache + cache6;
					cpu.pc++;
					cpu.cycle += 12;
				}
				else
				{
					cpu.pc++;
					cpu.cycle += 8;
				}
                break;
        case 0x21:
				cpu.l = get8(++cpu.pc);
				cpu.h = get8(++cpu.pc);
				cpu.cycle += 12;
                break;
        case 0x22:														//IGNORE Z80 SPEC!
                setmem(hl(), cpu.a);
                hli();
				cpu.cycle += 8;
                break;
        case 0x23:
                hli();
				cpu.cycle += 8;
                break;
        case 0x24:
                cpu.h++;
				cpu.f = cpu.f & 0x10;
                if((cpu.h & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.h == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x25:
                cpu.h--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.h & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.h == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x26:
                cpu.h = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x27:
				cache   = (cpu.a & 0x0F);
				cache2  = (cpu.a & 0xF0);
				cache3 = 0;
				cpu.f = cpu.f & 0x40;
//				if((cpu.f & 0x40) != 0x40)
//				{
					if(cache > 0x09)
					{
						cache -= 0x0A;
						cache3 = 0x10;
					}
					cache2 += cache3;
					if(cache2 > 0x90)
					{
						cache2 -= 0xA0;
						cpu.f = cpu.f | 0x10;
					}
					else
					{
						cpu.f = cpu.f & 0xEF;
					}
//				}
				cpu.a = cache+cache2;
		        if(cpu.a == 0)
		        {
					cpu.f = cpu.f | 0x80;
					break;
				}
				cpu.cycle += 4;
                break;
        case 0x28:
				if((cpu.f & 0x80) == 0x80)
				{
					cache = cpu.pc;
					cache6 = sget8(++cpu.pc);
					cpu.pc = cache + cache6;
					cpu.pc++;
					cpu.cycle += 12;
				}
				else
				{
					cpu.pc++;
					cpu.cycle += 8;
				}
                break;
        case 0x29:
				cache5 = hl() + hl();
				if(cache5 > 0xFFFF)
					cpu.f |= 0x10;
				if((cpu.h & 0x0F) > ((cache5 & 0x0F00) >> 8))
					cpu.f |= 0x20;
				cpu.h = (cache5 & 0xFF00) >> 8;
				cpu.l = cache5 & 0xFF;
				cpu.cycle += 8;
                break;
        case 0x2A:														//IGNORE Z80 SPEC!
                cpu.a = get8(hl());
                hli();
				cpu.cycle += 8;
                break;
        case 0x2B:
                hld();
				cpu.cycle += 8;
                break;
        case 0x2C:
                cpu.l++;
				cpu.f = cpu.f & 0x10;
                if((cpu.l & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.l == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x2D:
                cpu.l--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.l & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.l == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x2E:
                cpu.l = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x2F:
                cpu.a = cpu.a ^ 0xFF;
				cpu.cycle += 4;
                break;
        case 0x30:
				if((cpu.f & 0x10) != 0x10)
				{
					cache = cpu.pc;
					cache6 = sget8(++cpu.pc);
					cpu.pc = cache + cache6;
					cpu.pc++;
					cpu.cycle += 12;
				}
				else
				{
					cpu.pc++;
					cpu.cycle += 8;
				}
                break;
        case 0x31:
				cpu.sp = get16(++cpu.pc);
				cpu.pc++;
				cpu.cycle += 12;
                break;
        case 0x32:														//IGNORE Z80 SPEC!
                setmem(hl(), cpu.a);
                hld();
				cpu.cycle += 8;
                break;
        case 0x33:
                cpu.sp++;
				cpu.cycle += 8;
                break;
        case 0x34:
                setmem(hl(), (get8(hl())+1));
				cpu.f = cpu.f & 0x10;
                if((get8(hl()) & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(get8(hl()) == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 12;
                break;
        case 0x35:
                setmem(hl(), (get8(hl())-1));
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((get8(hl()) & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(get8(hl()) == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 12;
                break;
        case 0x36:
                setmem(hl(), get8(++cpu.pc));
				cpu.cycle += 12;
                break;
        case 0x37:
                cpu.f = cpu.f & 0x90;
				cpu.f = cpu.f | 0x10;
				cpu.cycle += 4;
                break;
        case 0x38:
				if((cpu.f & 0x10) == 0x10)
				{
					cache = cpu.pc;
					cache6 = sget8(++cpu.pc);
					cpu.pc = cache + cache6;
					cpu.pc++;
					cpu.cycle += 12;
				}
				else
				{
					cpu.pc++;
					cpu.cycle += 8;
				}
                break;
        case 0x39:
				cache5 = hl() + cpu.sp;
				if(cache5 > 0xFFFF)
					cpu.f |= 0x10;
				if((cpu.h & 0x0F) > ((cache5 & 0x0F00) >> 8))
					cpu.f |= 0x20;
				cpu.h = (cache5 & 0xFF00) >> 8;
				cpu.l = cache5 & 0xFF;
				cpu.cycle += 8;
                break;
        case 0x3A:														//IGNORE Z80 SPEC!
                cpu.a = get8(hl());
                hld();
				cpu.cycle += 8;
                break;
        case 0x3B:
                cpu.sp--;
				cpu.cycle += 8;
                break;
        case 0x3C:
                cpu.a++;
				cpu.f = cpu.f & 0x10;
                if((cpu.a & 0x0F) == 0)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x3D:
                cpu.a--;
				cpu.f = cpu.f & 0x10;
				cpu.f = cpu.f | 0x40;
                if((cpu.a & 0x0F) != 0x0F)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x3E:
		        cpu.a = get8(++cpu.pc);
				cpu.cycle += 8;
                break;
        case 0x3F:
                cpu.f = cpu.f & 0x90;
                if((cpu.f & 0x10) == 0x10)
                {
					cpu.f = cpu.f & 0xE0;
				}
				else
				{
					cpu.f = cpu.f | 0x10;
				}
				cpu.cycle += 4;
                break;
        case 0x40:
                cpu.b = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x41:
                cpu.b = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x42:
                cpu.b = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x43:
                cpu.b = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x44:
                cpu.b = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x45:
                cpu.b = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x46:
		        cpu.b = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x47:
                cpu.b = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x48:
                cpu.c = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x49:
                cpu.c = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x4A:
                cpu.c = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x4B:
                cpu.c = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x4C:
                cpu.c = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x4D:
                cpu.c = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x4E:
		        cpu.c = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x4F:
                cpu.c = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x50:
                cpu.d = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x51:
                cpu.d = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x52:
                cpu.d = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x53:
                cpu.d = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x54:
                cpu.d = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x55:
                cpu.d = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x56:
		        cpu.d = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x57:
                cpu.d = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x58:
                cpu.e = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x59:
                cpu.e = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x5A:
                cpu.e = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x5B:
                cpu.e = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x5C:
                cpu.e = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x5D:
                cpu.e = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x5E:
		        cpu.e = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x5F:
                cpu.e = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x60:
		        cpu.h = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x61:
		        cpu.h = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x62:
		        cpu.h = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x63:
		        cpu.h = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x64:
		        cpu.h = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x65:
		        cpu.h = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x66:
		        cpu.h = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x67:
                cpu.h = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x68:
		        cpu.l = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x69:
		        cpu.l = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x6A:
		        cpu.l = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x6B:
		        cpu.l = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x6C:
		        cpu.l = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x6D:
		        cpu.l = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x6E:
		        cpu.l = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x6F:
                cpu.l = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x70:
                setmem(hl(), cpu.b);
				cpu.cycle += 8;
                break;
        case 0x71:
                setmem(hl(), cpu.c);
				cpu.cycle += 8;
                break;
        case 0x72:
                setmem(hl(), cpu.d);
				cpu.cycle += 8;
                break;
        case 0x73:
                setmem(hl(), cpu.e);
				cpu.cycle += 8;
                break;
        case 0x74:
                setmem(hl(), cpu.h);
				cpu.cycle += 8;
                break;
        case 0x75:
                setmem(hl(), cpu.l);
				cpu.cycle += 8;
                break;
        case 0x76:
                cpu.halt = 1;
				cpu.cycle += 4;
                break;
        case 0x77:
                setmem(hl(), cpu.a);
				cpu.cycle += 8;
                break;
        case 0x78:
                cpu.a = cpu.b;
				cpu.cycle += 4;
                break;
        case 0x79:
                cpu.a = cpu.c;
				cpu.cycle += 4;
                break;
        case 0x7A:
                cpu.a = cpu.d;
				cpu.cycle += 4;
                break;
        case 0x7B:
                cpu.a = cpu.e;
				cpu.cycle += 4;
                break;
        case 0x7C:
                cpu.a = cpu.h;
				cpu.cycle += 4;
                break;
        case 0x7D:
                cpu.a = cpu.l;
				cpu.cycle += 4;
                break;
        case 0x7E:
		        cpu.a = get8(hl());
				cpu.cycle += 8;
                break;
        case 0x7F:
                cpu.a = cpu.a;
				cpu.cycle += 4;
                break;
        case 0x80:
                cache = cpu.a;
                cache2 = cpu.a + cpu.b;
		        cpu.a += cpu.b;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.b & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x81:
                cache = cpu.a;
                cache2 = cpu.a + cpu.c;
		        cpu.a += cpu.c;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.c & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x82:
                cache = cpu.a;
                cache2 = cpu.a + cpu.d;
		        cpu.a += cpu.d;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.d & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x83:
                cache = cpu.a;
                cache2 = cpu.a + cpu.e;
		        cpu.a += cpu.e;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.e & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x84:
                cache = cpu.a;
                cache2 = cpu.a + cpu.h;
		        cpu.a += cpu.h;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.h & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x85:
                cache = cpu.a;
                cache2 = cpu.a + cpu.l;
		        cpu.a += cpu.l;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.l & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x86:
                cache = cpu.a;
                cache2 = cpu.a + get8(hl());
		        cpu.a += get8(hl());
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (get8(hl()) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 8;
                break;
        case 0x87:
                cache = cpu.a;
                cache2 = cpu.a + cpu.a;
		        cpu.a += cpu.a;
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (cpu.a & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x88:
                cache = cpu.a;
		        cache2 = cpu.a + (cpu.b + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.b + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.b + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x89:
                cache = cpu.a;
                cache2 = cpu.a + (cpu.c + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.c + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.c + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x8A:
                cache = cpu.a;
                cache2 = cpu.a + (cpu.d + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.d + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.d + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x8B:
                cache = cpu.a;
                cache2 = cpu.a + (cpu.e + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.e + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.e + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x8C:
                cache = cpu.a;
                cache2 = cpu.a + (cpu.h + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.h + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.h + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x8D:
                cache = cpu.a;
                cache2 = cpu.a + (cpu.l + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.l + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.l + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x8E:
                cache = cpu.a;
                cache2 = cpu.a + (get8(hl()) + ((cpu.f & 0x10) >> 4));
		        cpu.a += ((get8(hl())) + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((get8(hl()) + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 8;
                break;
        case 0x8F:
                cache = cpu.a;
		        cache2 = cpu.a + (cpu.a + ((cpu.f & 0x10) >> 4));
		        cpu.a += (cpu.a + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((cpu.a + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x90:				
				cpu.f = 0x70;
				if(cpu.a > cpu.b)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.b & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.b)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.b;
				cpu.cycle += 4;
                break;
        case 0x91:
				cpu.f = 0x70;
				if(cpu.a > cpu.c)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.c & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.c)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.c;
				cpu.cycle += 4;
                break;
        case 0x92:
				cpu.f = 0x70;
				if(cpu.a > cpu.d)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.d & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.d)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.d;
				cpu.cycle += 4;
                break;
        case 0x93:
				cpu.f = 0x70;
				if(cpu.a > cpu.e)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.e & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.e)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.e;
				cpu.cycle += 4;
                break;
        case 0x94:
				cpu.f = 0x70;
				if(cpu.a > cpu.h)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.h & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.h)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.h;
				cpu.cycle += 4;
                break;
        case 0x95:
				cpu.f = 0x70;
				if(cpu.a > cpu.l)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.l & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.l)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.l;
				cpu.cycle += 4;
                break;
        case 0x96:
                cache4 = get8(hl());
				cpu.f = 0x70;
				if(cpu.a > cache4)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cache4 & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cache4)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cache4;
				cpu.cycle += 8;
                break;
        case 0x97:
				cpu.f = 0x70;
				if(cpu.a > cpu.a)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.a & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.a)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cpu.a;
				cpu.cycle += 4;
                break;
        case 0x98:
                cache3 = cpu.a;
                cache4 = (cpu.b + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.b + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				
/*				cpu.f = 0x70;
				if(cpu.a > cache4)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cache4 & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cache4)
					cpu.f = cache4 | 0x80;
		        cpu.a -= cache4;*/
				cpu.cycle += 4;
                break;
        case 0x99:
                cache3 = cpu.a;
                cache4 = (cpu.c + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.c + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x9A:
                cache3 = cpu.a;
                cache4 = (cpu.d + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.d + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x9B:
                cache3 = cpu.a;
                cache4 = (cpu.e + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.e + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x9C:
                cache3 = cpu.a;
                cache4 = (cpu.h + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.h + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x9D:
                cache3 = cpu.a;
                cache4 = (cpu.l + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.l + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0x9E:
                cache3 = cpu.a;
                cache4 = (get8(hl()) + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (get8(hl()) + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 8;
                break;
        case 0x9F:
                cache3 = cpu.a;
                cache4 = (cpu.a + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (cpu.a + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
				cpu.cycle += 4;
                break;
        case 0xA0:
                cpu.a = cpu.a & cpu.b;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA1:
                cpu.a = cpu.a & cpu.c;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA2:
                cpu.a = cpu.a & cpu.d;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA3:
                cpu.a = cpu.a & cpu.e;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA4:
                cpu.a = cpu.a & cpu.h;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA5:
                cpu.a = cpu.a & cpu.l;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA6:
                cpu.a = cpu.a & get8(hl());
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 8;
                break;
        case 0xA7:
                cpu.a = cpu.a & cpu.a;
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA8:
                cpu.a = cpu.a ^ cpu.b;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xA9:
                cpu.a = cpu.a ^ cpu.c;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xAA:
                cpu.a = cpu.a ^ cpu.d;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xAB:
                cpu.a = cpu.a ^ cpu.e;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xAC:
                cpu.a = cpu.a ^ cpu.h;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xAD:
                cpu.a = cpu.a ^ cpu.l;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xAE:
                cpu.a = cpu.a ^ get8(hl());
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 8;
                break;
        case 0xAF:
                cpu.a = cpu.a ^ cpu.a;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB0:
                cpu.a = cpu.a | cpu.b;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB1:
                cpu.a = cpu.a | cpu.c;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB2:
                cpu.a = cpu.a | cpu.d;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB3:
                cpu.a = cpu.a | cpu.e;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB4:
                cpu.a = cpu.a | cpu.h;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB5:
                cpu.a = cpu.a | cpu.l;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB6:
                cpu.a = cpu.a | get8(hl());
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 8;
                break;
        case 0xB7:
                cpu.a = cpu.a | cpu.a;
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB8:
				cpu.f = 0x40;
				if(cpu.a > cpu.b)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.b & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.b)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xB9:
				cpu.f = 0x40;
				cpu.f = 0x40;
				if(cpu.a > cpu.c)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.c & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.c)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xBA:
				cpu.f = 0x40;
				if(cpu.a > cpu.d)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.d & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.d)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xBB:
				cpu.f = 0x40;
				if(cpu.a > cpu.e)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.e & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.e)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xBC:
				cpu.f = 0x40;
				if(cpu.a > cpu.h)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.h & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.h)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xBD:
				cpu.f = 0x40;
				if(cpu.a > cpu.l)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.l & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.l)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xBE:
				cpu.f = 0x40;
                cache4 = get8(hl());
				if(cpu.a > cache4)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cache4 & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cache4)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 8;
                break;
        case 0xBF:
				if(cpu.a > cpu.a)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cpu.a & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cpu.a)
					cpu.f = cpu.f | 0x80;
				cpu.cycle += 4;
                break;
        case 0xC0:
				if((cpu.f & 0x80) != 0x80)
				{
					cpu.sp++;
					cpu.pc = get16(cpu.sp);
					cpu.sp++;
					cpu.pc--;
					cpu.cycle += 20;
				}
				else
				{
					cpu.cycle += 8;
				}
                break;
        case 0xC1:
                cpu.c = get8(++cpu.sp);
                cpu.b = get8(++cpu.sp);
                cpu.cycle += 12;
                break;
        case 0xC2:
				if((cpu.f & 0x80) != 0x80)
				{
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 16;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xC3:
                cpu.pc = get16(++cpu.pc);
                cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xC4:
				if((cpu.f & 0x80) != 0x80)
				{
					setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
					setmem(cpu.sp--, (cpu.pc & 0x00FF));
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 24;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xC5:
                setmem(cpu.sp--, cpu.b);
                setmem(cpu.sp--, cpu.c);
                cpu.cycle += 16;
                break;
        case 0xC6:
                cache = cpu.a;
		        cache2 = cpu.a + get8(++cpu.pc);
		        cpu.a += get8(cpu.pc);
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + (get8(cpu.pc) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
                cpu.cycle += 8;
                break;
        case 0xC7:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xC8:
				if((cpu.f & 0x80) == 0x80)
				{
					cpu.sp++;
					cpu.pc = get16(cpu.sp);
					cpu.sp++;
					cpu.pc--;
					cpu.cycle += 20;
				}
				else
				{
					cpu.cycle += 8;
				}
                break;
        case 0xC9:
                cpu.sp++;
                cpu.pc = get16(cpu.sp);
                cpu.sp++;
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xCA:
				if((cpu.f & 0x80) == 0x80)
				{
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 16;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xCB:
                cb();
                cpu.cycle += 12;
                break;
        case 0xCC:
				if((cpu.f & 0x80) == 0x80)
				{
					setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
					setmem(cpu.sp--, (cpu.pc & 0x00FF));
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 24;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xCD:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, ((cpu.pc & 0x00FF)));
				cpu.pc = get16(++cpu.pc);
				cpu.pc--;
                cpu.cycle += 12;										//Is this right? docs say 12, code says 24. changing to 12
                break;
        case 0xCE:
                cache = cpu.a;
                cache2 = cpu.a + (get8(++cpu.pc) + ((cpu.f & 0x10) >> 4));
		        cpu.a += (get8(cpu.pc) + ((cpu.f & 0x10) >> 4));
				cpu.f = 0;
                if(cache2 > 0x00FF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x0F) + ((get8(cpu.pc) + ((cpu.f & 0x10) >> 4)) & 0x0F)) >= 0x10)
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
                cpu.cycle += 8;
                break;
        case 0xCF:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xD0:
				if((cpu.f & 0x10) != 0x10)
				{
					cpu.sp++;
					cpu.pc = get16(cpu.sp);
					cpu.sp++;
					cpu.pc--;
					cpu.cycle += 20;
				}
				else
				{
					cpu.pc+=2;
					cpu.cycle += 8;
				}
                break;
        case 0xD1:
                cpu.e = get8(++cpu.sp);
                cpu.d = get8(++cpu.sp);
                cpu.cycle += 12;
                break;
        case 0xD2:
				if((cpu.f & 0x10) != 0x10)
				{
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 16;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xD3:														//----------------
                msgprint("D3\r\n");
                hang();
                break;
        case 0xD4:
				if((cpu.f & 0x10) != 0x10)
				{
					setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
					setmem(cpu.sp--, (cpu.pc & 0x00FF));
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 24;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xD5:
                setmem(cpu.sp--, cpu.d);
                setmem(cpu.sp--, cpu.e);
                cpu.cycle += 16;
                break;
        case 0xD6:
                cache4 = get8(++cpu.pc);
				cpu.f = 0x70;
				if(cpu.a > cache4)
					cpu.f = cpu.f ^ 0x10;
				if((cpu.a & 0x0F) > (cache4 & 0x0F))
					cpu.f = cpu.f ^ 0x20;
				if(cpu.a == cache4)
					cpu.f = cpu.f | 0x80;
		        cpu.a -= cache4;
                cpu.cycle += 8;
                break;
        case 0xD7:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xD8:
				if((cpu.f & 0x10) == 0x10)
				{
					cpu.sp++;
					cpu.pc = get16(cpu.sp);
					cpu.sp++;
					cpu.pc--;
					cpu.cycle += 20;
				}
				else
				{
					cpu.cycle += 8;
				}
                break;
        case 0xD9:														//IGNORE Z80 SPEC!
				cpu.sp++;
				cpu.pc = get16(cpu.sp);
				cpu.sp++;
				cpu.pc--;
				cpu.IME = 1;
                cpu.cycle += 16;
                break;
        case 0xDA:
				if((cpu.f & 0x10) == 0x10)
				{
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 16;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
				break;
        case 0xDB:														//----------------
                msgprint("D8\r\n");
                hang();
                break;
        case 0xDC:
				if((cpu.f & 0x10) == 0x10)
				{
					setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
					setmem(cpu.sp--, (cpu.pc & 0x00FF));
					cpu.pc = get16(++cpu.pc);
					cpu.pc--;
					cpu.cycle += 24;
				}
				else
				{
					cpu.pc++;
					cpu.pc++;
					cpu.cycle += 12;
				}
                break;
        case 0xDD:														//----------------
                msgprint("DD\r\n");
                hang();
                break;
        case 0xDE:
                cache3 = cpu.a;
                cache4 = (get8(++cpu.pc) + ((cpu.f & 0x10) >> 4));
		        cpu.a -= (get8(cpu.pc) + ((cpu.f & 0x10) >> 4));
				cpu.f = cpu.f & 0x40;
                if(!((cache3 - cache4) < 0))
                {
					cpu.f = cpu.f | 0x10;
				}
                if(!(((cache3 & 0x000F) - (cache4 & 0x000F)) < 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cpu.a == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
                cpu.cycle += 8;
                break;
        case 0xDF:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xE0:														//IGNORE Z80 SPEC!
                setmem((0xFF00 + get8(++cpu.pc)), cpu.a);
                cpu.cycle += 12;
                break;
        case 0xE1:
                cpu.l = get8(++cpu.sp);
                cpu.h = get8(++cpu.sp);
                cpu.cycle += 12;
                break;
        case 0xE2:														//IGNORE Z80 SPEC!
                setmem(cpu.c+0xFF00, cpu.a);
                cpu.cycle += 8;
                break;
        case 0xE3:														//----------------
                msgprint("E3\r\n");
                hang();
                break;
        case 0xE4:														//----------------
                msgprint("E4\r\n");
                hang();
                break;
        case 0xE5:
                setmem(cpu.sp--, cpu.h);
                setmem(cpu.sp--, cpu.l);
                cpu.cycle += 16;
                break;
        case 0xE6:
                cpu.a = cpu.a & get8(++cpu.pc);
                cpu.f = 0x20;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0xE7:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xE8:														//IGNORE Z80 SPEC!
                cache = cpu.sp;
                cache5 = cpu.sp + sget8(++cpu.pc);
		        cpu.sp += sget8(cpu.pc);
				cpu.f = cpu.f & 0x00;
                if(cache5 > 0xFFFF)
                {
					cpu.f = cpu.f | 0x10;
				}
                if(((cache & 0x00FF) + sget8(cpu.pc)) >= 0x0100)
                {
					cpu.f = cpu.f | 0x20;
				}
                cpu.cycle += 16;
                break;
        case 0xE9:
                cpu.pc = hl();
                cpu.pc--;
                cpu.cycle += 4;
                break;
        case 0xEA:														//IGNORE Z80 SPEC!
                setmem(get16(++cpu.pc), cpu.a);
                cpu.pc++;
                cpu.cycle += 16;
                break;
        case 0xEB:														//----------------
                msgprint("EB\r\n");
                hang();
                break;
        case 0xEC:														//----------------
                msgprint("EC\r\n");
                hang();
                break;
        case 0xED:														//----------------
                msgprint("ED\r\n");
                hang();
                break;
        case 0xEE:
                cpu.a = cpu.a ^ get8(++cpu.pc);
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0xEF:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xF0:														//IGNORE Z80 SPEC!
                cpu.a = get8(0xFF00 + get8(++cpu.pc));
                cpu.cycle += 12;
                break;
        case 0xF1:
                cpu.f = get8(++cpu.sp);
                cpu.a = get8(++cpu.sp);
                cpu.cycle += 12;
                break;
        case 0xF2:														//IGNORE Z80 SPEC!
                cpu.a = get8(cpu.c+0xFF00);
                cpu.cycle += 8;
                break;
        case 0xF3:
                cpu.IME = 0;
                cpu.cycle += 4;
                break;
        case 0xF4:														//----------------
                msgprint("F4\r\n");
                hang();
                break;
        case 0xF5:
                setmem(cpu.sp--, cpu.a);
                setmem(cpu.sp--, cpu.f);
                cpu.cycle += 16;
                break;
        case 0xF6:
                cpu.a = cpu.a | get8(++cpu.pc);
                cpu.f = 0x00;
                if(cpu.a == 0)
					cpu.f = cpu.f | 0x80;
                cpu.cycle += 8;
                break;
        case 0xF7:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
        case 0xF8:														//IGNORE Z80 SPEC!
                //cpu.hl = cpu.sp + get8(++cpu.pc);   with flags... fun.
                cache6 = sget8(++cpu.pc);
                cpu.l = cpu.sp + cache6;											//TODO: Research this behavior!!!
                cpu.h = (cpu.sp + cache6) >> 8;
				cpu.f = cpu.f & 0x00;
                if((cpu.h >> 7) != (cpu.sp >> 15))
                {
					cpu.f = cpu.f | 0x10;
				}
                if((cpu.h & 0x01) != ((cpu.sp & 0x0100) >> 8))
                {
					cpu.f = cpu.f | 0x20;
					cpu.h += 1;
				}
                cpu.cycle += 12;
                break;
        case 0xF9:
                cpu.sp = hl();
                cpu.cycle += 8;
                break;
        case 0xFA:														//IGNORE Z80 SPEC!
		        cpu.a = get8(get16(++cpu.pc));
                cpu.cycle += 16;
                break;
        case 0xFB:
                cpu.IME = 1;
                cpu.cycle += 4;
                break;
        case 0xFC:														//----------------
                msgprint("FC\r\n");
                hang();
                break;
        case 0xFD:														//----------------
                msgprint("FD\r\n");
                hang();
                break;
        case 0xFE:
				cpu.f = 0x40;
                cache3 = cpu.a;
                cache4 = get8(++cpu.pc);
                cache  = cpu.a - get8(cpu.pc);
				cpu.f = cpu.f & 0x40;
                if(cache3 < cache4)
                {
					cpu.f = cpu.f | 0x10;
				}
                if((((cache3 & 0x000F) - (cache4 & 0x000F)) >= 0))
                {
					cpu.f = cpu.f | 0x20;
				}
                if(cache == 0)
                {
					cpu.f = cpu.f | 0x80;
				}
                cpu.cycle += 8;
                break;
        case 0xFF:
				setmem(cpu.sp--, ((cpu.pc & 0xFF00) >> 8));
				setmem(cpu.sp--, (cpu.pc & 0x00FF));
				cpu.pc = (cpu.opcode - 0xC7);
				cpu.pc--;
                cpu.cycle += 16;
                break;
	}
}
