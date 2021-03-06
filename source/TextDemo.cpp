#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>

#include "TextDemo.hpp"

void init_text() {
  irqInit();
  irqEnable(IRQ_VBLANK);

  consoleInit(	0,		// charbase
					4,		// mapbase
					1,		// background number
					NULL,	// font
					0, 		// font size
					15		// 16 color palette
	);

	// set the screen colors, color 0 is the background color
	// the foreground color is index 1 of the selected 16 color palette
	BG_COLORS[0]=RGB8(58,110,165);
	//BG_COLORS[241]=RGB5(31,31,31);
  BG_COLORS[241]=RGB5(17,17,17);

	REG_DISPCNT |= BG1_ON; // Background 1 on

  REG_BG1CNT |= /*BG_CBB(CBB_0) | BG_SBB(SBB_0) | BG_REG_32x32 |*/ BG_PRIORITY(1);//BG_REG_64x64;
}
