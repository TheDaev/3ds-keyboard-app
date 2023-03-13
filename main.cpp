#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdio>


class l{
	public:
	int x,y;char le;
};

int main(int argc, char **argv)
{
	
	gfxInitDefault();

	
	PrintConsole down, top;

	//Initialize console for each window
	consoleInit(GFX_BOTTOM, &down);
	consoleInit(GFX_TOP, &top);
	
	l ld[25];
	
	
	//setting the x
	for (int i=0;i<=26;i++)
	{
	
		ld[i].x = i;
	
	}
	
	//setting the x
	//the first line (a-j)
	for(int i=0;i<9;i++)
	{
		ld[i].x = i;
	}
	//the second line(k-t)
	for(int i=10;i<19;i++)
	{
		ld[i].x = i-10;
	}
	//the last line(t-z)
	for(int i=20;i<25;i++)
	{
		ld[i].x = i-18;
	}
	
	
	
	ld[0].le = 'a';
	ld[1].le = 'b';
	ld[2].le = 'c';
	ld[3].le = 'd';
	ld[4].le = 'e';
	ld[5].le = 'f';
	ld[6].le = 'g';
	ld[7].le = 'h';
	ld[8].le = 'i';
	ld[9].le = 'j';
	ld[10].le = 'k';
	ld[11].le = 'l';
	ld[12].le = 'm';
	ld[13].le = 'n';
	ld[14].le = 'o';
	ld[15].le = 'p';
	ld[16].le = 'q';
	ld[17].le = 'r';
	ld[18].le = 's';
	ld[19].le = 't';
	ld[20].le = 'u';
	ld[21].le = 'v';
	ld[22].le = 'w';
	ld[23].le = 'x';
	ld[24].le = 'y';
	ld[25].le = 'z';
	
	ld[0].y = 0;
	ld[1].y = 0;
	ld[2].y = 0;
	ld[3].y = 0;
	ld[4].y = 0;
	ld[5].y = 0;
	ld[6].y = 0;
	ld[7].y = 0;
	ld[8].y = 0;
	ld[9].y = 0;
	ld[10].y = 1;
	ld[11].y = 1;
	ld[12].y = 1;
	ld[13].y = 1;
	ld[14].y = 1;
	ld[15].y = 1;
	ld[16].y = 1;
	ld[17].y = 1;
	ld[18].y = 1;
	ld[19].y = 1;
	ld[20].y = 2;
	ld[21].y = 2;
	ld[22].y = 2;
	ld[23].y = 2;
	ld[24].y = 2;
	ld[25].y = 2;
	
	
	
	l ls = ld[0];
	int x=0;
	int y=0;
	int ux=4;
	int uy=2;
	std::string cs = "";
	

	consoleSelect(&top);
	printf("\x1b[30;16HPress Start to exit.");
	
	
	
	consoleSelect(&down);
	std::cout<<"	A	B	C	D	E	F	G	H	I	J	"<<std::endl
				
			 <<"	K	L	M	N	O	P	Q	R	S	T	"<<std::endl
			 
			 <<"			U	V	W	X	Y	Z 			"<<std::endl
			 
			 <<"				   [space]                  "<<std::endl;
			 
	
	

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
		
		for(int i=0;i<=26;i++)
		{
			if((x==ld[i].x) && (y==ld[i].y))
			{
				ls = ld[i];
			}
		}
		
		
		
		consoleSelect(&top);
		std::cout<<"\x1b[1;1HCurrent letter: "<<ls.le<<std::endl;
		std::cout<<"\x1b[2;1HString: "<<cs<<std::endl;
		std::cout<<"\x1b[3;1HX: "<<x<<std::endl;
		std::cout<<"\x1b[4;1HY: "<<y<<std::endl;
		
		
		if(kDown & KEY_SELECT)
		{
			cs += " ";
		}
		
		
		
		
		if (kDown & KEY_RIGHT)
		{
			x += 1;
			ux += 4;
		}
		
		if(kDown & KEY_LEFT)
		{
			x -= 1;
			ux -= 4;
		}
		
		if(kDown & KEY_DOWN)
		{
			y +=1;
			uy += 2;
		}
		
		if(kDown & KEY_UP)
		{
			y -=1;
			uy -= 2;
		}
		
		
		if(kDown & KEY_A)
		{
			char a = ls.le;
			cs += a;
		}
		

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	// Exit services
	gfxExit();

	return 0;
}
