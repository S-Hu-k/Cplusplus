#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar a[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,0x80, 0x90 };
uchar b[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
uchar second = 00, minute = 00, hour = 04, year = 18, month = 12, day = 17, count;
sbit Key1 = P3 ^ 3; //计时停止
sbit Key2 = P3 ^ 2; //调位
sbit Key3 = P3 ^ 1; //加一 
sbit Key4 = P3 ^ 0; //切换
sbit LED1 = P0 ^ 1;

void Delayms(uint t)
{
	uint i, j;
	for (i = 0; i < t; i++)
		for (j = 0; j < 125; j++);
}

void closefucker()
{
	P2 = (P2 & 0x1f) | 0xa0;
	P0 &= 0xaf;
	P2 &= 0x1f;
}

void Dispaly1(uchar second, uchar minute, uchar hour)
{
	P2 = (P2 & 0x1f) | 0xc0;				//位选1
	P0 = b[0];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[hour / 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选2
	P0 = b[1];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[hour % 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选3
	P0 = b[2];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = 0xbf;
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选4
	P0 = b[3];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[minute / 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选5
	P0 = b[4];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[minute % 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选6
	P0 = b[5];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = 0xbf;
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选7
	P0 = b[6];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[second / 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选8
	P0 = b[7];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[second % 10];
	P2 &= 0x1f;
	Delayms(5);
}


void Dispaly2(uchar day, uchar month, uchar year)
{
	P2 = (P2 & 0x1f) | 0xc0;				//位选1
	P0 = b[0];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[day / 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选2
	P0 = b[1];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[day % 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选3
	P0 = b[2];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = 0xbf;
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选4
	P0 = b[3];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[month / 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选5
	P0 = b[4];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[month % 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选6
	P0 = b[5];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = 0xbf;
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选7
	P0 = b[6];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[year / 10];
	P2 &= 0x1f;
	Delayms(5);

	P2 = (P2 & 0x1f) | 0xc0;				//位选8
	P0 = b[7];
	P2 &= 0x1f;

	P2 = (P2 & 0x1f) | 0xe0;
	P0 = a[year % 10];
	P2 &= 0x1f;
	Delayms(5);

}
void Keyscan1()
{
	static uchar i = 0, j = 0;
	if (Key1 == 0)
	{
		Delayms(10); //消抖 
		if (Key1 == 0)
			while (!Key1); //等待按键弹起
		i++;
	}
	if (i % 2 == 1)
	{
		LED1 = 0;
		TR0 = 0;
	}
	if (i % 2 == 0)
	{
		LED1 = 1;
		TR0 = 1;
	}
	if (Key2 == 0)
	{
		Delayms(10);
		if (Key2 == 0)
			while (!Key2);
		j++;
	}
	if (j % 4 == 1)
	{
		if (Key3 == 0)
		{
			Delayms(10);
			if (Key3 == 0)
				while (!Key3);
			second++;
			if (second == 60)
				second = 0;
		}
	}
	if (j % 4 == 2)
	{
		if (Key3 == 0)
		{
			Delayms(10);
			if (Key3 == 0)
				while (!Key3);
			minute++;
			if (minute == 60)
				minute = 0;
		}
	}
	if (j % 4 == 3)
	{
		if (Key3 == 0)
		{
			Delayms(10);
			if (Key3 == 0)
				while (!Key3);
			hour++;
			if (hour == 24)
				hour = 0;
		}
	}




}
void Keyscan2()
{
	static uchar m = 0, n = 0;
	if (Key1 == 0)
	{
		Delayms(10);
		if (Key1 == 0)
			while (!Key3);	  //等待按键释放
		m++;
	}
	if (m % 2 == 1)
	{
		LED1 = 0;
		TR0 = 0;
	}
	if (m % 2 == 0)
	{
		LED1 = 1;
		TR0 = 1;
	}
	if (Key2 == 0)
	{
		Delayms(10);
		if (Key2 == 0)
			while (!Key2);
		n++;
	}
	if (n % 4 == 1)
	{
		if (Key3 == 0)
		{
			Delayms(10);
			if (Key3 == 0)
				while (!Key3);
			day++;
			if (day == 30)
				day = 0;
		}
	}
	if (n % 4 == 2)
	{
		if (Key3 == 0)
		{
			Delayms(10);
			if (Key3 == 0)
				while (!Key3);
			month++;
			if (month == 12)
				month = 0;
		}
	}
	if (n % 4 == 3)
	{
		if (Key3 == 0)
		{
			Delayms(10);
			if (Key3 == 0)
				while (!Key3);
			year++;
			if (year == 99)
				year = 0;
		}
	}




}
void main()
{

	closefucker();

	TMOD = 0x01;
	TH0 = (65536 - 10000) / 256;
	TL0 = (65536 - 10000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	while (1)
	{
		static uchar h = 0;
		if (Key4 == 0)
		{
			Delayms(10);
			if (Key4 == 0)
				while (!Key4);
			h++;
		}
		if (h % 2 == 1)
		{
			Dispaly2(year, month, day);
			Keyscan2();
		}
		if (h % 2 == 0)
		{
			Dispaly1(second, minute, hour);
			Keyscan1();
		}

	}
}
void time0_int(void) interrupt 1
{
	TH0 = (65536 - 10000) / 256;
	TL0 = (65536 - 10000) % 256;
	count++;
	if (count == 100)
	{
		count = 0;
		second++;
		if (second == 60)
		{
			second = 0;
			minute++;
			if (minute == 60)
			{
				minute = 0;
				hour++;
				if (hour == 24)
				{
					hour = 0;
					day++;
					if (day == 30)
					{
						day = 0;
						month++;
						if (month == 12)
						{
							month = 0;
							year++;
							if (year == 99)
							{
								year = 0;
							}
						}
					}
				}
			}
		}
	}
}
