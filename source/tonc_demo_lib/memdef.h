//
//  Memory map defines. All of them
//
//! \file tonc_memdef.h
//! \author J Vijn
//! \date 20060508 - 20060924
//
// === NOTES ===
// * This is a _small_ set of typedefs, #defines and inlines that can
//   be found in tonclib, and might not represent the
//   final forms.
// * '0'-defines are prefixed with '_', to indicate their zero-ness
//   and presents a safety from things like doing `if(x&0)'

#ifndef __MEMDEF__
#define __MEMDEF__

// --- Prefixes ---
// REG_DISPCNT		: DCNT
// REG_DISPSTAT		: DSTAT

// OAM attr 0		: OA0
// OAM attr 1		: OA1
// OAM attr 2		: OA2


// --- REG_DISPCNT -----------------------------------------------------

#define DCNT_MODE0				 0	//!< Mode 0; bg 0-4: reg
#define DCNT_MODE1			0x0001	//!< Mode 1; bg 0-1: reg; bg 2: affine
#define DCNT_MODE2			0x0002	//!< Mode 2; bg 2-2: affine
#define DCNT_MODE3			0x0003	//!< Mode 3; bg2: 240x160\@16 bitmap
#define DCNT_MODE4			0x0004	//!< Mode 4; bg2: 240x160\@8 bitmap
#define DCNT_MODE5			0x0005	//!< Mode 5; bg2: 160x128\@16 bitmap
#define DCNT_GB				0x0008	//!< (R) GBC indicator
#define DCNT_PAGE			0x0010	//!< Page indicator
#define DCNT_OAM_HBL		0x0020	//!< Allow OAM updates in HBlank
#define DCNT_OBJ_2D				 0	//!< OBJ-VRAM as matrix
#define DCNT_OBJ_1D			0x0040	//!< OBJ-VRAM as array
#define DCNT_BLANK			0x0080	//!< Force screen blank
#define DCNT_BG0			0x0100	//!< Enable bg 0
#define DCNT_BG1			0x0200	//!< Enable bg 1
#define DCNT_BG2			0x0400	//!< Enable bg 2
#define DCNT_BG3			0x0800	//!< Enable bg 3
#define DCNT_OBJ			0x1000	//!< Enable objects
#define DCNT_WIN0			0x2000	//!< Enable window 0
#define DCNT_WIN1			0x4000	//!< Enable window 1
#define DCNT_WINOBJ			0x8000	//!< Enable object window

#define DCNT_MODE_MASK		0x0007
#define DCNT_MODE_SHIFT			 0
#define DCNT_MODE(n)	   ((n)<<DCNT_MODE_SHIFT)

#define DCNT_LAYER_MASK		0x1F00
#define DCNT_LAYER_SHIFT		 8
#define DCNT_LAYER(n)	  ((n)<<DCNT_LAYER_SHIFT)

#define DCNT_WIN_MASK		0xE000
#define DCNT_WIN_SHIFT		  13
#define DCNT_WIN(n)			((n)<<DCNT_WIN_SHIFT)

#define DCNT_BUILD(mode, layer, win, obj1d, objhbl)				\
(																\
		(((win)&7)<<13) | (((layer)&31)<<8) | (((obj1d)&1)<<6)	\
	| (((oamhbl)&1)<<5) | ((mode)&7)							\
)


// --- REG_BGxCNT ---

//#define BG_MOSAIC			0x0040	//!< Enable Mosaic
#define BG_4BPP					 0	//!< 4bpp (16 color) bg (no effect on affine bg)
#define BG_8BPP				0x0080	//!< 8bpp (256 color) bg (no effect on affine bg)
#define BG_WRAP				0x2000	//!< Wrap around edges of affine bgs
#define BG_SIZE0				 0
#define BG_SIZE1			0x4000
#define BG_SIZE2			0x8000
#define BG_SIZE3			0xC000
#define BG_REG_32x32			 0	//!< reg bg, 32x32 (256x256 px)
#define BG_REG_64x32		0x4000	//!< reg bg, 64x32 (512x256 px)
#define BG_REG_32x64		0x8000	//!< reg bg, 32x64 (256x512 px)
#define BG_REG_64x64		0xC000	//!< reg bg, 64x64 (512x512 px)
#define BG_AFF_16x16			 0	//!< affine bg, 16x16 (128x128 px)
#define BG_AFF_32x32		0x4000	//!< affine bg, 32x32 (256x256 px)
#define BG_AFF_64x64		0x8000	//!< affine bg, 64x64 (512x512 px)
#define BG_AFF_128x128		0xC000	//!< affine bg, 128x128 (1024x1024 px)

#define BG_PRIO_MASK	0x0003
#define BG_PRIO_SHIFT		0
#define BG_PRIO(n)		((n)<<BG_PRIO_SHIFT)

#define BG_CBB_MASK		0x000C
#define BG_CBB_SHIFT		 2
#define BG_CBB(n)		((n)<<BG_CBB_SHIFT)

#define BG_SBB_MASK		0x1F00
#define BG_SBB_SHIFT		 8
#define BG_SBB(n)		((n)<<BG_SBB_SHIFT)

#define BG_SIZE_MASK	0xC000
#define BG_SIZE_SHIFT		14
#define BG_SIZE(n)		((n)<<BG_SIZE_SHIFT)


#define BG_BUILD(cbb, sbb, size, bpp, prio, mos, wrap)		\
(															\
	   ((size)<<14)  | (((wrap)&1)<<13) | (((sbb)&31)<<8	\
	| (((bpp)&8)<<4) | (((mos)&1)<<6)   | (((cbb)&3)<<2)	\
	| ((prio)&3)											\
)


// --- REG_DISPSTAT ----------------------------------------------------

#define DSTAT_IN_VBL	0x0001	//!< Now in VBlank
#define DSTAT_IN_HBL	0x0002	//!< Now in HBlank
#define DSTAT_IN_VCT	0x0004	//!< Now in set VCount
#define DSTAT_VBL_IRQ	0x0008	//!< Enable VBlank irq
#define DSTAT_HBL_IRQ	0x0010	//!< Enable HBlank irq
#define DSTAT_VCT_IRQ	0x0020	//!< Enable VCount irq

#define DSTAT_VCT_MASK	0xFF00
#define DSTAT_VCT_SHIFT		 8
#define DSTAT_VCT(n)	((n)<<DSTAT_VCT_SHIFT)


// --- REG_KEYINPUT --------------------------------------------------------

#define KEY_A			0x0001	//!< Button A
#define KEY_B			0x0002	//!< Button B
#define KEY_SELECT		0x0004	//!< Select button
#define KEY_START		0x0008	//!< Start button
#define KEY_RIGHT		0x0010	//!< Right D-pad
#define KEY_LEFT		0x0020	//!< Left D-pad
#define KEY_UP			0x0040	//!< Up D-pad
#define KEY_DOWN		0x0080	//!< Down D-pad
#define KEY_R			0x0100	//!< Shoulder R
#define KEY_L			0x0200	//!< Shoulder L

#define KEY_ANY			0x03FF	//!< any key
#define KEY_DIR			0x00F0	//!< any-dpad
#define KEY_ACCEPT		0x0009	//!< A or start
#define KEY_CANCEL		0x0002	//!< B (well, it usually is)
#define KEY_SHOULDER	0x0300	//!< L or R

#define KEY_RESET		0x000F	//!< St+Se+A+B

#define KEY_MASK		0x03FF



// --- Reg screen entries ----------------------------------------------

#define SE_HFLIP		0x0400	//!< Horizontal flip
#define SE_VFLIP		0x0800	//!< Vertical flip

#define SE_ID_MASK		0x03FF
#define SE_ID_SHIFT			 0
#define SE_ID(n)		((n)<<SE_ID_SHIFT)

#define SE_FLIP_MASK	0x0C00
#define SE_FLIP_SHIFT		10
#define SE_FLIP(n)	 ((n)<<SE_FLIP_SHIFT)

#define SE_PALBANK_MASK		0xF000
#define SE_PALBANK_SHIFT		12
#define SE_PALBANK(n)		((n)<<SE_PALBANK_SHIFT)


#define SE_BUILD(id, pbank, hflip, vflip)	\
( ((id)&0x03FF) | (((hflip)&1)<<10) | (((vflip)&1)<<11) | ((pbank)<<12) )


// --- OAM attribute 0 -------------------------------------------------

#define ATTR0_REG				 0	//!< Regular object
#define ATTR0_AFF			0x0100	//!< Affine object
#define ATTR0_HIDE			0x0200	//!< Inactive object
#define ATTR0_AFF_DBL		0x0300	//!< Double-size affine object
#define ATTR0_AFF_DBL_BIT	0x0200
#define ATTR0_BLEND			0x0400	//!< Enable blend
#define ATTR0_WINDOW		0x0800	//!< Use for object window
#define ATTR0_MOSAIC		0x1000	//!< Enable mosaic
#define ATTR0_4BPP				 0	//!< Use 4bpp (16 color) tiles
#define ATTR0_8BPP			0x2000	//!< Use 8bpp (256 color) tiles
#define ATTR0_SQUARE			 0	//!< Square shape
#define ATTR0_WIDE			0x4000	//!< Tall shape (height &gt; width)
#define ATTR0_TALL			0x8000	//!< Wide shape (height &lt; width)

#define ATTR0_Y_MASK		0x00FF
#define ATTR0_Y_SHIFT			 0
#define ATTR0_Y(n)		((n)<<ATTR0_Y_SHIFT)

#define ATTR0_MODE_MASK		0x0300
#define ATTR0_MODE_SHIFT		 8
#define ATTR0_MODE(n)		((n)<<ATTR0_MODE_SHIFT)

#define ATTR0_SHAPE_MASK	0xC000
#define ATTR0_SHAPE_SHIFT		14
#define ATTR0_SHAPE(n)	((n)<<ATTR0_SHAPE_SHIFT)


#define ATTR0_BUILD(y, shape, bpp, mode, mos, bld, win)				\
(																	\
	((y)&255) | (((mode)&3)<<8) | (((bld)&1)<<10) | (((win)&1)<<11) \
	| (((mos)&1)<<12) | (((bpp)&8)<<10)| (((shape)&3)<<14)			\
)


// --- OAM attribute 1 -------------------------------------------------

#define ATTR1_HFLIP			0x1000	//!< Horizontal flip (reg obj only)
#define ATTR1_VFLIP			0x2000	//!< Vertical flip (reg obj only)
// Base sizes
#define ATTR1_SIZE_8			 0
#define ATTR1_SIZE_16		0x4000
#define ATTR1_SIZE_32		0x8000
#define ATTR1_SIZE_64		0xC000
// Square sizes
#define ATTR1_SIZE_8x8			 0	//!< Size flag for  8x8 px object
#define ATTR1_SIZE_16x16	0x4000	//!< Size flag for 16x16 px object
#define ATTR1_SIZE_32x32	0x8000	//!< Size flag for 32x32 px object
#define ATTR1_SIZE_64x64	0xC000	//!< Size flag for 64x64 px object
// Tall sizes
#define ATTR1_SIZE_8x16			 0	//!< Size flag for  8x16 px object
#define ATTR1_SIZE_8x32		0x4000	//!< Size flag for  8x32 px object
#define ATTR1_SIZE_16x32	0x8000	//!< Size flag for 16x32 px object
#define ATTR1_SIZE_32x64	0xC000	//!< Size flag for 32x64 px object
// Wide sizes
#define ATTR1_SIZE_16x8			 0	//!< Size flag for 16x8 px object
#define ATTR1_SIZE_32x8		0x4000	//!< Size flag for 32x8 px object
#define ATTR1_SIZE_32x16	0x8000	//!< Size flag for 32x16 px object
#define ATTR1_SIZE_64x32	0xC000	//!< Size flag for 64x64 px object


#define ATTR1_X_MASK		0x01FF
#define ATTR1_X_SHIFT			 0
#define ATTR1_X(n)			((n)<<ATTR1_X_SHIFT)

#define ATTR1_AFF_ID_MASK		0x3E00
#define ATTR1_AFF_ID_SHIFT		 9
#define ATTR1_AFF_ID(n)		((n)<<ATTR1_AFF_ID_SHIFT)

#define ATTR1_FLIP_MASK		0x3000
#define ATTR1_FLIP_SHIFT		12
#define ATTR1_FLIP(n)		((n)<<ATTR1_FLIP_SHIFT)

#define ATTR1_SIZE_MASK		0xC000
#define ATTR1_SIZE_SHIFT		14
#define ATTR1_SIZE(n)		((n)<<ATTR1_SIZE_SHIFT)


#define ATTR1_BUILDR(x, size, hflip, vflip)	\
( ((x)&511) | (((hflip)&1)<<12) | (((vflip)&1)<<13) | (((size)&3)<<14) )

#define ATTR1_BUILDA(x, size, affid)			\
( ((x)&511) | (((affid)&31)<<9) | (((size)&3)<<14) )


// --- OAM attribute 2 -------------------------------------------------

#define ATTR2_ID_MASK		0x03FF
#define ATTR2_ID_SHIFT			 0
#define ATTR2_ID(n)			((n)<<ATTR2_ID_SHIFT)

#define ATTR2_PRIO_MASK		0x0C00
#define ATTR2_PRIO_SHIFT		10
#define ATTR2_PRIO(n)		((n)<<ATTR2_PRIO_SHIFT)

#define ATTR2_PALBANK_MASK	0xF000
#define ATTR2_PALBANK_SHIFT		12
#define ATTR2_PALBANK(n)	((n)<<ATTR2_PALBANK_SHIFT)


#define ATTR2_BUILD(id, pbank, prio)			\
( ((id)&0x3FF) | (((pbank)&15)<<12) | (((prio)&3)<<10) )




// --- REG_TMxCNT ------------------------------------------------------

/*!	\defgroup grpTimerTM	Timer Control Flags
	\ingroup grpMemBits
	\brief	Bits for REG_TMxCNT
*/
/*!	\{	*/

#define TM_FREQ_SYS			 0	//!< System clock timer (16.7 Mhz)
#define TM_FREQ_1			 0	//!< 1 cycle/tick (16.7 Mhz)
#define TM_FREQ_64		0x0001	//!< 64 cycles/tick (262 kHz)
#define TM_FREQ_256		0x0002	//!< 256 cycles/tick (66 kHz)
#define TM_FREQ_1024	0x0003	//!< 1024 cycles/tick (16 kHz)
#define TM_CASCADE		0x0004	//!< Increment when preceding timer overflows
#define TM_IRQ			0x0040	//!< Enable timer irq
#define TM_ENABLE		0x0080	//!< Enable timer

#define TM_FREQ_MASK	0x0003
#define TM_FREQ_SHIFT		 0
#define TM_FREQ(n)		((n)<<TM_FREQ_SHIFT)

/*!	\}	/defgroup	*/



#endif // __MEMDEF__
