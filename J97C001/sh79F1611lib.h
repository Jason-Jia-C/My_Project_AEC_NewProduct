/*--------------------------------------------------------------------------
FileName: Sh79F1611lib.H
Device:   SH79F1611
Vision:   V0.0
Data:     2012.04.20
Author:   x
function:
----------------------------------------------------------------------------
Package:
 P48
                               ____________
                              |            |
          TDI / BUZ / B_P14 --| 1      48  |-- B_P13 / INT1 / AN9 / TMS
          TCK / RST / B_P15 --| 2      47  |-- B_P12 / INT0 / AN8 / TDO
               AN10 / B_P16 --| 3      46  |-- B_P11 / OP1P / C1P
             OP2OUT / B_P17 --| 4      45  |-- B_P10 / OP1N
               OP2N / B_P37 --| 5      44  |-- B_P00 / OP1OUT
               OP2P / B_P36 --| 6      43  |-- B_P01 / C1N
                       AVDD --| 7      42  |-- B_P02 / INT45 / AN0 / C2P0
                        VDD --| 8      41  |-- B_P03 / INT46 / AN1 / C2P1
                        GND --| 9      40  |-- B_P04 / INT47 / AN2 / C2P2
                       AGND --| 10     39  |-- B_P05 / AN3 / VREF
      XTAL1 / INT44 / B_P35 --| 11     38  |-- B_P06 / AN4 / C2N
      XTAL2 / INT43 / B_P34 --| 12     37  |-- B_P07 / AN5
                              |            |
              INT42 / B_P33 --| 13     36  |-- B_P40 / AN6
        TXD / INT41 / B_P32 --| 14     35  |-- B_P41 / AN7
        RXD / INT40 / B_P31 --| 15     34  |-- B_P42 / AN11
               PWM3 / B_P30 --| 16     33  |-- B_P43
             PWM0H  / B_P20 --| 17     32  |-- B_P44
             PWM1H  / B_P21 --| 18     31  |-- B_P45 / T2EX
             PWM2H  / B_P22 --| 19     30  |-- B_P46 / T3
              PWM0L / B_P23 --| 20     29  |-- B_P47 / T2
              PWM1L / B_P24 --| 21     28  |-- B_P50 / MOSI
              PWM2L / B_P25 --| 22     27  |-- B_P51 / MISO
           FLT / T0 / B_P26 --| 23     26  |-- B_P52 / SCK
                 T1 / B_P27 --| 24     25  |-- B_P53 / SS
                              |____________|

 P32
                               ____________
                              |            |
 C2P0 / AN0 / INT45 / B_P02 --|- 1     32 -|-- B_P03 / INT46 / AN1 / C2P1
                C1N / B_P01 --|- 2     31 -|-- B_P04 / INT47 / AN2 / C2P2
             OP1OUT / B_P00 --|- 3     30 -|-- B_P05 / AN3 / VREF
               OP1N / B_P10 --|- 4     29 -|-- B_P06 / AN4 / C2N
         C1P / OP1P / B_P11 --|- 5     28 -|-- B_P07 / AN5
   TDO / AN8 / INT0 / B_P12 --|- 6     27 -|-- B_P27 / T1
   TMS / AN9 / INT1 / B_P13 --|- 7     26 -|-- B_P26 / T0 / FLT
         TDI / BUZZ / B_P14 --|- 8     25 -|-- B_P25 / PWM2L
         TCK / REST / B_P15 --|- 9     24 -|-- B_P24 / PWM1L
              AN10 /  B_P16 --|- 10    23 -|-- B_P23 / PWM0L
                      B_P17 --|- 11    22 -|-- B_P22 / PWM2H
                        VDD --|- 12    21 -|-- B_P21 / PWM1H
                        GND --|- 13    20 -|-- B_P20 / PWM0H
      XTAL1 / INT44 / B_P35 --|- 14    19 -|-- B_P30 / PWM3
      XTAL2 / INT43 / B_P34 --|- 15    18 -|-- B_P31 / INT40 / RXD
              INT42 / B_P33 --|- 16    17 -|-- B_P32 / INT41 / TXD
                              |____________|

 P24
                               ____________
                              |            |
               OP1N / B_P10 --|- 1     24 -|-- B_P00 / OP1OUT
         C1P / OP1P / B_P11 --|- 2     22 -|-- B_P01 / C1N
   TDO / AN8 / INT0 / B_P12 --|- 3     22 -|-- B_P02 / INT45 / AN0 / C2P0
   TMS / AN9 / INT1 / B_P13 --|- 4     21 -|-- B_P03 / INT46 / AN1 / C2P1
         TDI / BUZZ / B_P14 --|- 5     20 -|-- B_P04 / INT47 / AN2 / C2P2
         TCK / REST / B_P15 --|- 6     19 -|-- B_P05 / AN3 / VREF
                        VDD --|- 7     18 -|-- B_P06 / AN4 / C2N
                        GND --|- 8     17 -|-- B_P26 / T0 / FLT
      XTAL1 / INT44 / B_P35 --|- 9     16 -|-- B_P25 / PWM2L
      XTAL2 / INT43 / B_P34 --|- 10    15 -|-- B_P24 / PWM1L
        TXD / INT41 / B_P32 --|- 11    14 -|-- B_P22 / PWM2H
        RXD / INT40 / B_P31 --|- 12    13 -|-- B_P21 / PWM1H
                              |____________|

----------------------------------------------------------------------------
SH79F1611	2.7-5.5	@ 33MHz (inRC 33.2MHz)
ROM(FLASH)	16k bytes	movc @a+dptr
RAM			512bytes (ex:128*10 + in:256)
 bdata: in 0x20 - 0x2f         bit
 data:  in 0 - 127 bytes (0x00 - 0x7f)
 idata: in 0 - 255 bytes (0x00 - 0xff)
 xdata: ex 64k  movx @dptr
 pdata(< xdata ): 1 page or ex ram 256bytes , special regist set page, movx @B_RI
----------------------------------------------------------------------------
Attention:
 16*16 bit, 32/16 bit, 32移位
 堆叠 SP 0x00 - 0xFF 任意地址, 向上增长
 volatile 编译器保证不对变数操作优化
 const
 static 静态局部变数
 extern
 新增加寄存器, 注意其功能
 INSCON PCON SUSLO CLKCON XPAGE	B_FAC
 Rest 低电平复位 注意与8051不一样

 外部RAM 1280
 1. 
 	0-0x0ff  访问方式: MOVXA, @RI 或 MOVX @Ri, A
 	0-0x4ff  访问方式: MOVXA, @DPTR 或 MOVX @DPTR, A
 2. 使用XPAGE表示高256字节的RAM地址，然后使用 MOVXA, @RI 或 MOVX @RI,A
----------------------------------------------------------------------------
 代码选项
 OP_LVR [1:0]	00 禁止LVR功能
 				01 允许LVR功能,当电源电压低于 4.3V 重定
 				10 允许LVR功能,当电源电压低于 3.4V 重定
 				11 ??????????????????????
 OP_RST [7]		0  P1.5 作为复位脚
 				1  P1.5 作为IO口
 OP_WDT [6:5]	00 禁止WDT功能
 				01 允许WDT功能
 				10 禁止WDT功能
 				11 在掉电模式下, 不允许WDT, 其他WDT开启
 OP_WMT [4:3]	00 振荡器采用最长预热计数时间
 				01 振荡器采用比较长预热计数时间
 				10 振荡器采用比较短预热计数时间
 				11 振荡器采用最短预热计数时间
 OP_OSC [2:0]	000 内部RC振荡器
 				101 晶体振荡器
 				110 陶瓷振荡器
 				其他 内部RC振荡器
--------------------------------------------------------------------------*/
#ifndef SH79F1611LIB_H
#define SH79F1611LIB_H

/* Includes --------------------------------------------------------------*/
#include "SH79F1611.H"
#include "intrins.H"

 /* --------------------------------------------------------------------------
  *
  */
#define false		0x0
#define true		0x1

#define FALSE		0x0
#define TRUE		0x1

/* --------------------------------------------------------------------------
  *
	Data Type		Bits  	Bytes  		Value Range  
	bit 			1   	-			0 to 1 
	signed char 	8 		1 			-128 to +127 
	unsigned char	8 		1 			0 to 255 
	enum 			16 		2 			-32768 to +32767 
	signed short 	16 		2 			-32768 to +32767 
	unsigned short 	16 		2 			0 to 65535 
	signed int 		16 		2 			-32768 to +32767 
	unsigned int 	16 		2 			0 to 65535 
	signed long 	32 		4 			-2147483648 to 2147483647 
	unsigned long 	32 		4 			0 to 4294967295 
	float 			32 		4 			±1.175494E-38 to ±3.402823E+38 
	sbit 			1   	-			0 to 1 
	sfr 			8 		1 			0 to 255 
	sfr16 			16 		2 			0 to 65535 
  */

#define uchar	unsigned char
#define uint	unsigned int
#define ulong	unsigned long

#define __I		volatile const			// 	 只读
#define __O		volatile const			// 	 只写
#define __IO	volatile const			// 	 读写

#define int8_t	volatile char			// 有符号资料 32 ， 16 ，8
#define int16_t	volatile int
#define int32_t	volatile long

#define uint8_t		unsigned char		// 无符号资料 32 ， 16 ，8
#define uint16_t	unsigned int
#define uint32_t	unsigned long

/* --------------------------------------------------------------------------
  * bit
#define bit0 	0
#define bit1	1
#define bit2	2
#define bit3	3
#define bit4	4
#define bit5	5
#define bit6	6
#define bit7	7
*/

#define B0 	0x01
#define B1	0x02
#define B2	0x04
#define B3	0x08
#define B4	0x10
#define B5	0x20
#define B6	0x40
#define B7	0x80

#define TestBit(var,cbit)	( (var) & (1<<(cbit)) )
#define SetBit(var,cbit)	( (var) |= (1<<(cbit)) )
#define ClrBit(var,cbit)	( (var) &= ~(1<<(cbit)) )
#define CplBit(var,cbit)	( (var) ^= (1<<(cbit)) )

#if 0
/* --------------------------------------------------------------------------
  *   High bit is low adress
  * ex: intdata 0x1234  -- adr 0x1c
  *         data        adr
  *         0x12        0x1c
  *         0x34        0x1d
  */
struct bit_t{

	unsigned char  b0:1;				/* bit0 */
	unsigned char  b1:1;				/* bit1 */
	unsigned char  b2:1;				/* bit2 */
	unsigned char  b3:1;				/* bit3 */
	unsigned char  b4:1;				/* bit4 */
	unsigned char  b5:1;				/* bit5 */
	unsigned char  b6:1;				/* bit6 */
	unsigned char  b7:1;				/* bit7 */
};

typedef union{

	struct bit_t	bits;				/* bit unit 	*/
	unsigned char 	byte;				/* byte unit 	*/
} Typ_IO;
#endif

struct word_t{

	unsigned char  b0:1;				/* bit0 */    /* Low address */
	unsigned char  b1:1;				/* bit1 */
	unsigned char  b2:1;				/* bit2 */
	unsigned char  b3:1;				/* bit3 */
	unsigned char  b4:1;				/* bit4 */
	unsigned char  b5:1;				/* bit5 */
	unsigned char  b6:1;				/* bit6 */
	unsigned char  b7:1;				/* bit7 */

	unsigned char  b8:1;				/* bitb8 */		/* high address */
	unsigned char  b9:1;				/* bitb9 */
	unsigned char  b10:1;				/* bitb10 */
	unsigned char  b11:1;				/* bitb11 */
	unsigned char  b12:1;				/* bitb12 */
	unsigned char  b13:1;				/* bitb13 */
	unsigned char  b14:1;				/* bitb14 */
	unsigned char  b15:1;				/* bitb15 */
};

typedef union{

	struct word_t	bits;				/* bit unit 	*/
	unsigned int 	word;				/* byte unit 	*/
} Typ_WordIO;


typedef union{

	unsigned int Intdata;				/* low address + high address */
	unsigned char Bytedata[2];			/* bytedata[0] + bytedata[1] */
} Typ_Intdata;

typedef union {

	unsigned long Longdata;
	unsigned char Bytedata[4];
} Typ_Longdata;

typedef union{

	unsigned long Longdata[2];
	unsigned char Bytedata[8];
} Typ_TEGdata;



/* --------------------------------------------------------------------------
Interrupt Vectors:
Interrupt	Number				Address
	0		(EXTERNAL INT 0)	0x0003
	1		(TIMER/COUNTER 0)	0x000B
	2		(EXTERNAL INT 1)	0x0013
	3		(TIMER/COUNTER 1)	0x001B
	4		(SERIAL PORT)		0x0023
	5		(TIMER/COUNTER 2)	0x002B
	6		(PCA)				0x0033
	7							0x003B
	8							0x0043
	9							0x004B
	10							0x0053
	11							0x005B
	12							0x0063
	13							0x006B
	14							0x0073
	15							0x007B
	16							0x0083
	17							0x008B
	18							0x0093
	19							0x009B
  	20							0x00A3
  	21							0x00AB
	22							0x00B3
	23							0x00BB
 	24							0x00C3
	25							0x00CB
	26							0x00D3
	27							0x00DB
   	28							0x00E3
  	29							0x00EB
  	30							0x00F3
   	31							0x00FB
 --------------------------------------------------------------------------*/

/*		中断源   	中断号(c)		轮选优先顺序 复位向量		允许位元	标志位元			*/
/*#define RST_VECTOR	-		*/	/* 0		0x0000      -        -							*/
#define INT0_VECTOR		0			/* 1		0x0003      B_EX0      B_IE0					*/
#define T0_VECTOR		1			/* 2		0x000b      B_ET0      B_TF0					*/
#define INT1_VECTOR		2			/* 3		0x0013      B_EX1      B_IE1					*/
#define T1_VECTOR		3			/* 4		0x001b      B_ET1      B_TF1					*/
#define EUART_VECTOR	4			/* 5		0x0023      B_ES       B_RI,B_TI				*/
#define T2_VECTOR		5			/* 6		0x002B      B_ET2      B_TF2+EXF2				*/
#define ADC_VECTOR		6			/* 7		0x0033      B_EADC     B_ADCIF/ADGIF/ADLIF		*/
#define SPI_VECTOR		7			/* 8		0x003B      B_ESPI     B_SPIF					*/
#define CMP1_VECTOR		8			/* 9		0x0043      B_ECMP1    B_C1IF					*/
#define CMP2_VECTOR		9			/* 10		0x004B      B_ECMP2    B_C2IF					*/
#define INT4_VECTOR		10			/* 11		0x0053      B_EX4+ienc  if4x					*/
#define T3_VECTOR		11			/* 12		0x005B      B_ET3      TF3            			*/
#define MCM_VECTOR		12			/* 13		0x0063      B_EMCM+pwmpXie pwmXif				*/
#define PWM3_VECTOR		13			/* 14		0x006B	    B_EPWM3+pwmp3ie pwm3if				*/
#define SCM_VECTOR		14			/* 15		0x0073      B_ESCM      SCMIF					*/

/*#define OVL_VECTOR	15		*/	/* 可遮罩中断 (产生复位或中断，目前固定位复位)	*/

/* --------------------------------------------------------------------------
BYTE Register:
 --------------------------------------------------------------------------*/
/* ----------------------------------------------------------------------- */
/* C51 */
/* sfr	ACC				= 0xE0;		*/	/* 累加器 */
/* sfr	B				= 0xF0;		*/	/* B寄存器  乘数 / 除数放结果 */
/* sfr	AUXC			= 0xF1;		*/	/* C寄存器 16bit 乘数 / 除数  */

/* sfr	PSW				= 0xD0;		*/	/* 程式状态字 */
/* sbit	CY			= 0xD7;			*/
/* sbit	AC			= 0xD6;			*/
/* sbit	F0			= 0xD5;			*/
/* sbit	RS1			= 0xD4;			*/
/* sbit	RS0			= 0xD3;			*/
/* sbit	OV			= 0xD2;			*/
/* sbit	F1			= 0XD1;			*/
/* sbit	P			= 0xD0;			*/

/* sfr	SP				= 0x81;		*/	/* 堆叠指标 内部ram(00 - ff) */
/* sfr	DPL				= 0x82;		*/	/* dptr 资料指标低位元组 */
/* sfr	DPH				= 0x83;		*/	/* dptr 资料指标高位元组 */
/* sfr	DPL1			= 0x84;		*/	/* 资料指标1低位元组 */
/* sfr	DPH1			= 0x85;		*/	/* 资料指标1低位元组 */

/* sfr	INSCON			= 0x86;		*/	/*	资料指标选择 */
//#define B_BKS1	7					/* 00 选择特殊功能寄存器 */
//#define B_BKS0	6					/* 其他 保留 */
/* #define 			5				*/
/* #define 			4				*/
#define B_DIV		3					/* 除法位数选择 0: 8位 , 1: 16位 */
#define B_MUL		2					/* 乘法位数选择 0: 8位 , 1: 16位 */
/* #define			1				*/
#define B_DPS		0					/* 资料指标选择 0: DPTR, 1: DPTR1 */

/* ----------------------------------------------------------------------- */
/* power  */
/* sfr	PCON			= 0x87;		*/ /* 电源控制 */
#define B_SMOD		7					/* 串列传输速率 加倍控制 */
#define B_SSTAT		6					/* 控制SCON_B7_5 的工作方式 */
#define	B_IT41		5					/* 外部中断4 触发模式 */
#define	B_TI40		4
#define B_GF1		3					/* 软体通用标志*/
#define B_GF0		2
#define B_PD		1					/* 掉电模式控制 */
#define B_IDL		0					/* 空闲模式控制 */

/* sfr	SUSLO			= 0x8E;		*/ /* 电源控制保护字 0x55 */

/* ----------------------------------------------------------------------- */
/* FLASH */
/* FLASH: 16 * 1024bytes, 最后64bytes 0x3fc - 0x3fff 被保留不能被使用 */
/* icp/ssp flash 读写 byte 为单位, 擦除 1k bytes 为单位 */

/* sfr	IB_OFFSET		= 0xFB;		*/ 	/* 可编程FLASH低位元位元组偏移 */
/* sfr	IB_DATA 		= 0xFC;		*/	/* 可编程FLASH资料寄存器 */
/* sfr	IB_CON1 		= 0xF2;		*/	/* SSP控制寄存器1 */
/* sfr	IB_CON2 		= 0xF3;		*/	/* SSP控制寄存器2 */
/* sfr	IB_CON3 		= 0xF4;		*/	/* SSP控制寄存器3 */
/* sfr	IB_CON4 		= 0xF5;		*/	/* SSP控制寄存器4 */
/* sfr	IB_CON5 		= 0xF6;		*/	/* SSP控制寄存器5 */

/* sfr XPAGE 			= 0xF7;		*/	/* 1. 用来访问外部RAM，xpage 表示高于256bytes ram address */
										/* 2. 可编程FLASH页选择寄存器 */
#define XPAGE7		7					/* ssp模式 7-2: 被编程的存储单元磁区号*/
#define XPAGE6		6
#define XPAGE5		5
#define XPAGE4		4
#define XPAGE3		3
#define XPAGE2		2
#define XPAGE1		1					/* SSP模式 1-0: 被编程的存储单元高2位元位址 */
#define XPAGE0		0

/* sfr FLASHCON			= 0xA7;		*/   /* FLASH访问控制寄存器 */
/* #define			7				*/
/* #define			6				*/
/* #define			5				*/
/* #define			4				*/
/* #define			3				*/
/* #define			2				*/
/* #define			1				*/
#define B_FAC		0					/* FLASH 访问控制位 0: rom, 1:识别码 */

/* ----------------------------------------------------------------------- */
/* WDT */
/* sfr	RSTSTAT 		= 0xB1;		*/ /* WDT计时器控制寄存器 */
#define	WDOF		7					/* 1: WDT溢出,程式超出范围 */
/* #define			6				*/
#define	PORF		5					/* 1: 上电复位 */
#define	LVRF		4					/* 1: 低压复位 */
#define	CLRF		3					/* 1: rest脚复位 */
#define	WDTT2		2					/* WDT溢出周期	000: 4096ms, 001: 1024ms, 010: 256ms */
#define	WDTT1		1					/*				011: 128ms,  100: 64ms,   101: 16ms  */
#define	WDTT0		0					/*				110: 4ms,    111: 1ms                */

/* ----------------------------------------------------------------------- */
/* SYSTEM CLKCON */
/* sfr	CLKCON			= 0xB2;		*/	/* 系统时钟选择 */
//#define			7
#define CLKS1		6					/* 系统时钟分频 fsys 00: fsoc/1, 01: fosc/2 */
#define CLKS0		5					/*                   10: fsoc/4, 11:fosc/12 */
#define	SCMIF		4					/* 系统时钟故障标志，硬件自动切换到内部128K低频振荡器 */
#define	OSCXON		3					/* 高频系统时钟开关控制, 0:disable, 1:enable */
#define	FS			2					/* 系统时钟切换, 0: osclck = oscclk 低频, 1:oscclk = oscxclk 高频 */
/* #define			1				*/
/* #define			0				*/

/* ----------------------------------------------------------------------- */
/* INTERRUPT */
/* sfr IEN0 			= 0xA8;		*/	/* 中断允许控制寄存器0 */
#define B_EA		7					/* 总中断允许位 */
#define B_EADC		6					/* adc中断允许位 */
#define	B_ET2		5					/* T2溢出允许位 */
#define B_ES		4					/* EUART 中断允许位 */
#define B_ET1		3					/* T1中断允许位 */
#define B_EX1		2					/* INT1中断允许位 */
#define B_ET0		1					/* T0中断允许位 */
#define B_EX0		0					/* INT0中断允许位 */
/*  IEN0   */
sbit	bEA			= 0xAF;
sbit	bEADC		= 0xAE;
sbit	bET2		= 0xAD;
sbit	bES			= 0xAC;
sbit	bET1		= 0xAB;
sbit	bEX1		= 0xAA;
sbit	bET0		= 0xA9;
sbit	bEX0		= 0xA8;

/* sfr	IEN1			= 0xA9;		*/	/* 中断允许控制寄存器1 */
#define	B_ESCM		7					/* SCM中断允许位 0:禁止, 1:允许 */
#define B_EPWM3		6					/* PWM3中断允许位 0:禁止,1:允许  */           // FAULT 中断允许位  B_EFLT
#define	B_EMCM		5					/* PWM012模块中断允许位 0:禁止, 1:允许 */     // PWM中断 总允许位  B_EPWM
#define	B_ET3		4					/* T3溢出中断允许位 0:禁止, 1:允许 */
#define B_EX4		3					/* INT4中断允许位 0:禁止, 1:允许 */
#define	B_ECMP2		2					/* CMP1中断允许位 0:禁止, 1:允许 */
#define	B_ECMP1		1					/* CMP0中断允许位 0:禁止, 1:允许 */
#define	B_ESPI		0					/* SPI 中断允许位 0:禁止, 1:允许 */

/* sfr	IENC			= 0xBA;		*/	/* 外部中断4通道允许控制 */
#define	B_EXS47		7					/* INT47中断允许位 0:禁止, 1:允许 */
#define	B_EXS46		6				    /* INT46中断允许位 0:禁止, 1:允许 */
#define	B_EXS45		5				    /* INT45中断允许位 0:禁止, 1:允许 */
#define	B_EXS44		4				    /* INT44中断允许位 0:禁止, 1:允许 */
#define	B_EXS43		3				    /* INT43中断允许位 0:禁止, 1:允许 */
#define B_EXS42		2					/* INT42中断允许位 0:禁止, 1:允许 */
#define B_EXS41		1                   /* INT41中断允许位 0:禁止, 1:允许 */
#define B_EXS40		0                   /* INT40中断允许位 0:禁止, 1:允许 */

/* 中断优先顺序 H L: 00 等级0最低, 01等级1, 10等级2, 11等级3最高 */
/* sfr IPL0				= 0xB8;		*/	/* 中断优先顺序控制低位0 */
/* #define			7				*/
#define B_PADCL		6
#define	B_PT2L		5
#define B_PSL		4
#define B_PT1L		3
#define B_PX1L		2
#define B_PT0L		1
#define B_PX0L		0

/* sfr IPH0				= 0xB4;		*/	/* 中断优先顺序控制高位0 */
/* #define			7				*/
#define B_PADCH		6					/* ADC */
#define	B_PT2H		5					/* T2 */
#define B_PSH		4					/* Euart */
#define B_PT1H		3					/* T1 */
#define B_PX1H		2					/* INT1 */
#define B_PT0H		1					/* T0 */
#define B_PX0H		0					/* INT0 */

/* sfr IPL1				= 0xB9;		*/	/* 中断优先顺序控制低位0 */
#define	B_PSCML		7					/* SCM */
#define B_PPWM3L		6					/* PWM3 */                   // FLTL B_PFLTL
#define	B_PMCML		5					/* PWM012 */                 // PWM B_PPWML
#define	B_PT3L		4					/* T3 */
#define B_PX4L		3					/* INT4X */
#define	B_PCMP2L	2					/* CMP2 */
#define	B_PCMP1L	1					/* CMP1 */
#define	B_PSPIL		0					/* SPI */

/* sfr IPH1				= 0xB5;		*/	/* 中断优先顺序控制高位1 */
#define	B_PSCMH		7
#define B_PPWM3H		6		// pwm3
#define	B_PMCMH		5
#define	B_PT3H		4
#define B_PX4H		3
#define	B_PCMP2H	2
#define	B_PCMP1H	1
#define	B_PSPIH		0

/* B_EX4 控制 */
/* sfr	EXF1			= 0xD8;		*/	/* 外部中断4控制寄存器 */
#define B_IF47		7					/* INT47请求标志 */ //外部中断处罚模式 B_IT41, B_IT40
#define B_IF46		6					/* INT46请求标志 */
#define	B_IF45		5				    /* INT45请求标志 */
#define	B_IF44		4				    /* INT44请求标志 */
#define B_IF43		3				    /* INT43请求标志 */
#define B_IF42 		2					/* INT42请求标志 */
#define B_IF41  	1                   /* INT41请求标志 */
#define B_IF40  	0                   /* INT40请求标志 */
sbit	bIF47		= 0xDF;
sbit	bIF46		= 0xDE;
sbit	bIF45		= 0xDD;
sbit	bIF44		= 0xDC;
sbit	bIF43		= 0xDB;
sbit	bIF42		= 0xDA;
sbit	bIF41		= 0xD9;
sbit	bIF40		= 0xD8;

/* ----------------------------------------------------------------------- */
/* PORT */
/* sfr	P0				= 0x80;		*/	/* P0 埠资料寄存器 */
#define B_P07		7
#define B_P06		6
#define	B_P05		5
#define	B_P04		4
#define B_P03		3
#define B_P02		2
#define B_P01		1
#define B_P00		0
sbit	bP00		= 0x80;				// P0^0;
sbit	bP01		= 0x81;				// P0^1;
sbit	bP02		= 0x82;				// P0^2;
sbit	bP03		= 0x83;				// P0^3;
sbit	bP04		= 0x84;				// P0^4;
sbit	bP05		= 0x85;				// P0^5;
sbit	bP06		= 0x86;				// P0^6;
sbit	bP07		= 0x87;				// P0^7;

/* sfr	P1				= 0x90;		*/	/* P1 埠资料寄存器 */
#define B_P17		7
#define B_P16		6
#define	B_P15		5
#define	B_P14		4
#define B_P13		3
#define B_P12		2
#define B_P11		1
#define B_P10		0
sbit	bP10		= 0x90;				//P1^0;
sbit	bP11		= 0x91;				//P1^1;
sbit	bP12		= 0x92;				//P1^2;
sbit	bP13		= 0x93;				//P1^3;
sbit	bP14		= 0x94;				//P1^4;
sbit	bP15		= 0x95;				//P1^5;
sbit	bP16		= 0x96;				//P1^6;
sbit	bP17		= 0x97;				//P1^7;

/* sfr	P2				= 0xA0;		*/	/* P2 埠资料寄存器 */
#define B_P27		7
#define B_P26		6
#define	B_P25		5
#define	B_P24		4
#define B_P23		3
#define B_P22		2
#define B_P21		1
#define B_P20		0
sbit	bP20		= 0xA0;				//P2^0;
sbit	bP21		= 0xA1;				//P2^1;
sbit	bP22		= 0xA2;				//P2^2;
sbit	bP23		= 0xA3;				//P2^3;
sbit	bP24		= 0xA4;				//P2^4;
sbit	bP25		= 0xA5;				//P2^5;
sbit	bP26		= 0xA6;				//P2^6;
sbit	bP27		= 0xA7;				//P2^7;

/* sfr	P3				= 0xB0;		*/	/* P3 埠资料寄存器 */
#define B_P37		7
#define B_P36		6
#define	B_P35		5
#define	B_P34		4
#define B_P33		3
#define B_P32		2
#define B_P31		1
#define B_P30		0
sbit	bP30		= 0xB0;				//P3^0;
sbit	bP31		= 0xB1;				//P3^1;
sbit	bP32		= 0xB2;				//P3^2;
sbit	bP33		= 0xB3;				//P3^3;
sbit	bP34		= 0xB4;				//P3^4;
sbit	bP35		= 0xB5;				//P3^5;

/* sfr	P4				= 0xC0;		*/	/* P4 埠资料寄存器 */
#define B_P47		7
#define B_P46		6
#define	B_P45		5
#define	B_P44		4
#define B_P43		3
#define B_P42		2
#define B_P41		1
#define B_P40		0
sbit	bP40		= 0xC0;				//P4^0;
sbit	bP41		= 0xC1;				//P4^1;
sbit	bP42		= 0xC2;				//P4^2;
sbit	bP43		= 0xC3;				//P4^3;
sbit	bP44		= 0xC4;				//P4^4;
sbit	bP45		= 0xC5;				//P4^5;
sbit	bP46		= 0xC6;				//P4^6;
sbit	bP47		= 0xC7;				//P4^7;

/* sfr	P5				= 0xF8;		*/	/* P5 埠资料寄存器 */
#define B_P57		7
#define B_P56		6
#define	B_P55		5
#define	B_P54		4
#define B_P53		3
#define B_P52		2
#define B_P51		1
#define B_P50		0
sbit	bP50		= 0xF8;				//P5^0;
sbit	bP51		= 0xF9;				//P5^1;
sbit	bP52		= 0xFA;				//P5^2;
sbit	bP53		= 0xFB;				//P5^3;
//sbit	bP54		= 0xFC;				//P5^4;
//sbit	bP55		= 0xFD;				//P5^5;
//sbit	bP56		= 0xFE;				//P5^6;
//sbit	bP57		= 0xFF;				//P5^7;

/* sfr	P0CR			= 0xE1;		*/	/* P0 方向控制寄存器 0:input, 1:output */
/* sfr	P1CR			= 0xE2;		*/	/* P1 方向控制寄存器 */
/* sfr	P2CR			= 0xE3;		*/	/* P2 方向控制寄存器 */
/* sfr	P3CR			= 0xE4;		*/	/* P3 方向控制寄存器 */
/* sfr	P4CR			= 0xE5;		*/	/* P4 方向控制寄存器 */
/* sfr	P5CR			= 0xE6;		*/	/* P5 方向控制寄存器 */
/* sfr	P0PCR			= 0xE9;		*/	/* P0 上拉控制寄存器 0:dis pullhigh, 1: en pullhigh */
/* sfr	P1PCR			= 0xEA;		*/	/* P1 上拉控制寄存器 */
/* sfr	P2PCR			= 0xEB;		*/	/* P2 上拉控制寄存器 */
/* sfr	P3PCR			= 0xEC;		*/	/* P3 上拉控制寄存器 */
/* sfr	P4PCR			= 0xED;		*/	/* P4 上拉控制寄存器 */
/* sfr	P5PCR			= 0xEE;		*/	/* P5 上拉控制寄存器 */

/* ----------------------------------------------------------------------- */
/* TIMER 0/1 */
/* sfr TCON				= 0x88;		*/	/* T0/T1 控制寄存器 */
#define B_TF1		7					/* T1 溢出标志 */
#define B_TR1		6					/* T1 启动控制 */
#define	B_TF0		5					/* T0 溢出标志 */
#define	B_TR0		4					/* T0 启动控制 */
#define B_IE1		3					/* INT1 中断标志 */
#define B_IT1		2					/* INT1 触发方式 0:低电平, 1:下奖沿 */
#define B_IE0		1					/* INT0 中断标志  */
#define B_IT0		0					/* INT0 触发方式 0:低电平, 1:下奖沿 */
sbit	bTF1		= 0x8F;
sbit	bTR1		= 0x8E;
sbit	bTF0		= 0x8D;
sbit	bTR0		= 0x8C;
sbit	bIE1		= 0x8B;
sbit	bIT1		= 0x8A;
sbit	bIE0		= 0x89;
//sbit	bIT0		= 0x88;

/* sfr TMOD				= 0x89;		*/	/* T0/T1 模式寄存器 */
#define B_GATE1		7					/* 计时器1门控位 */
#define B_CT1		6					/* 计时器1定时与计数方式选择 */
#define	B_M11		5					/* 计时器1计时器方式选择 00 Mode0, 01 Mode1, 10 Mode2, 11Mode3 */
#define	B_M10		4
#define B_GATE0		3					/* 计时器0门控位 */
#define B_CT0		2					/* 计时器0定时与计数方式选择 */
#define B_M01		1					/* 计时器0计时器方式选择 00 Mode0, 01 Mode1, 10 Mode2, 11Mode3 */
#define B_M00		0

/* sfr	TL0				= 0x8A;		*/	/* T0 低位元位元组 */
/* sfr	TL1				= 0x8B;		*/	/* T1 低位元位元组 */
/* sfr	TH0				= 0x8C;		*/	/* T0 高位位元组 */
/* sfr	TH1				= 0x8D;		*/	/* T1 高位位元组 */

/* sfr T2CON			= 0xC8;		*/	/* T2 控制寄存器 */
#define B_TF2		7					/* T2溢出标志: 0:无溢出（软件清零）,1:溢出硬件置1 */
#define B_EXF2		6					/* T2EX引脚外部事件输入（下降沿）被检测到的标志位:0:无外部事件输入（软件清零）,1:检测外部输入(EXEN2=1,硬件置1) */
#define	B_TRG		5					/* 自动触发控制:0:关闭自动触发,1:开启自动触发 */
//#define			4					/*  */
#define B_EXEN2		3					/* T2EX引脚上的外部事件输入(下降沿)用作捕获/重载触发器的允许控制:0:忽略T2EX引脚时间,1:检测T2EX，产生捕获/重载 */
#define B_TR2		2					/* T2启动控制 */
#define B_CT2		1					/* T2定时计数方式选择 */
#define B_CPRL2		0					/* T2捕获/重载方式选择:,0:16位带重载功能的计数,1:16位带捕获功能的计数 */
sbit	bTF2		= 0xCF;
sbit	bEXF2		= 0xCE;
sbit	bTRG		= 0xCD;
//sbit			= 0xCC;
sbit	bEXEN2		= 0xCB;
sbit	bTR2		= 0xCA;
sbit	bCT2		= 0xC9;
sbit	bCPRL2		= 0xC8;

/* sfr T2MOD				= 0x89;		*/	/* T2模式寄存器 */
#define B_TCLKP2	7						/* T2定时时钟选择 0:系统时钟1/12,1:系统时钟1/1 */
//#define 			6
//#define			5
//#define			4
//#define 			3
//#define 			2
#define B_T20E		1						/* T2输出允许位 T2的用途 0:作为输入或IO,1:作为时钟输出，duty50% */
#define B_DCEN		0                   	/* T2递增减计数器控制 0:递增,1:递减 */

/* sfr	RCAP2L			= 0xCA;		*/	/* T2 低位元位元组 */
/* sfr	RCAP2H			= 0xCB;		*/	/* T2 高位元位元组 */
/* sfr16 RCAP2_16 = 0xCA;			*/

/* sfr	TL2				= 0xCC;		*/	/* T2 低位位元组 */
/* sfr	TH2				= 0xCD;		*/	/* T2 高位位元组 */
/* sfr16 TM2_16 = 0xCC;				*/

/* sfr	TCON1			= 0xCE;		*/	/* T0/T1 控制寄存器1 */
/* #define			7				*/
#define	B_TCLKS1	6					/* T1时钟源选择 0:系统时钟, 1:128K RC 时钟1/8 */
#define	B_TCLKS0	5					/* T0时钟源选择 0:系统时钟, 1:128K RC 时钟1/8 */
/* #define			4				*/
#define	B_TCLKP1	3					/* T1时钟源预分频 0:1/12 系统时钟, 1: 系统时钟 1/1 */
#define	B_TCLKP0	2					/* T1时钟源预分频 0:1/12 系统时钟, 1: 系统时钟 1/1 */
#define B_TC1		1					/* T1 比较器输出控制 */
#define B_TC0		0					/* T0 比较器输出控制 */

/* sfr	T3CON			= 0xAC;			*	/* T3 控制寄存器 TCON3 */
#define	B_TF3		7					/* T3溢出标志 0:无溢出（硬件清零）, 1:溢出（硬件置1） */
//#define			6
#define	B_T3PS1		5					/* T3预分频 00:1/1, 01:1/8, 10:1/64, 11:1/256 */
#define	B_T3PS0		4
//#define			3
#define	B_TR3		2					/* T3定时器控制位 0:停止,1:启动 */
#define B_T3CLKS1	1					/* T3 时钟源选择 00:系统时钟,T3作为IO, 01:T3输入时钟，自动上拉, 10:内部128K RC, 11:保留  */
#define B_T3CLKS0	0

#define T3PRE1		( (0<<(B_T3PS1)) | (0<<(B_T3PS0)) )			/* 1:1  */
#define T3PRE8		( (0<<(B_T3PS1)) | (1<<(B_T3PS0)) )			/* 1:8  */
#define T3PRE64		( (1<<(B_T3PS1)) | (1<<(B_T3PS0)) )			/* 1:64  */
#define T3PRE256	( (1<<(B_T3PS1)) | (0<<(B_T3PS0)) )			/* 1:256 */
#define T3IOFSYS	( (0<<(B_T3CLKS1)) | (0<<(B_T3CLKS0)) )			/* 系统时钟，T3for IO */
#define T3INPUTF	( (0<<(B_T3CLKS1)) | (1<<(B_T3CLKS0)) )			/* T3输入时钟  */
#define T3OFFRC128	( (1<<(B_T3CLKS1)) | (1<<(B_T3CLKS0)) )			/* T3IO 时钟内部RC 128KHz */
#define T3RES		( (1<<(B_T3CLKS1)) | (0<<(B_T3CLKS0)) )			/* 保留 */

/* sfr	TL3				= 0xAA;		*/	/* T2 低位位元组 */
/* sfr	TH3				= 0xAB;		*/	/* T2 高位位元组 */


/* ----------------------------------------------------------------------- */
/* EUART 0 */
/* sfr	SCON			= 0x98;		*/	/* 串列控制 */
										/* B_SSTAT = 0 */
#define B_SM0		7					/* 串列通信方式控制 00,01,10,11 */
#define B_SM1		6
#define	B_SM2		5					/* 多机通讯允许位元 */
										/* B_SSTAT = 1 */
#define B_FE		7					/* 帧出错标志位元 */
#define B_RXOV		6					/* 接收完成标志 */
#define	B_TXCOL		5					/* 发送冲突标志位元 */

#define	B_REN		4					/* 接收允许位 */
#define B_TB8		3					/* 方式2,3 发送第9位 */
#define B_RB8		2					/* 方式1,2,3接收第9位 */
#define B_TI		1					/* 发送中断标志位元 */
#define B_RI		0					/* 接收中断标志位元 */
sbit	bFE			= 0x9F;
sbit	bRXOV		= 0x9E;
sbit	bTXCOL		= 0x9D;

sbit	bSM0		= 0x9F;
sbit	bSM1		= 0x9E;
sbit	bSM2		= 0x9D;

sbit	bREN		= 0x9C;
sbit	bTB8		= 0x9B;
sbit	bRB8		= 0x9A;
sbit	bTI			= 0x99;
sbit	bRI			= 0x98;

/* sfr	SBUF			= 0x99;		*/	/* 串列资料缓冲器 */
/* sfr	SADDR			= 0x9A;		*/	/* 从属地址 */
/* sfr	SADEN			= 0x9B;		*/	/* 从属地址遮罩 */

// PCON	 前面已有
/* sfr	SBRTL			= 0xFD;		*/	/* 波特率发生器 bit7-0 */

/* sfr	SBRTH			= 0xFE;		*/	/* 波特率发生器 bit14-8 */
#define	B_SBRTEN	7					/* 波特率发生器控制位 0:关闭,1:启动 */

/* sfr16 SBRT_16 = 0xFD;			*/

/* sfr	BFINE			= 0xA4;		*/	/* 波特率发生器微调寄存器 bit3-0 */

/* ----------------------------------------------------------------------- */
/* SPI */
/* sfr	SPCON			= 0xA2;		*/	/* SPI控制寄存器 */
#define B_DIR			7				/* 左右移位发送选择 0:先发高位, 1:先发地位 */
#define B_MSTR			6               /* SP主从设备设置 0:spi作为从设备 ,1: spi作为主设备 */
#define B_CPHA			5               /* 时钟采集数据控制 0:sck的第一个沿采集数据, 1:sck的第二个沿采集数据 */
#define B_CPOL			4               /* 时钟极性选择 0:在IDLE状态下SCK处于低电平,1:在IDLE状态下SCK处于高电平 */
#define B_SSDIS			3               /* SS引脚控制 0:打开ss,1:关闭ss ; 如果SSDIS置1，不产生MODF中断请求，在从属模式下，如果CPHA=0,改位不起作用 */
#define B_SPR2			2               /* 串行时钟预分频 000: fsys/4, 001: fsys/8, 010: fsys/16, 011: fsys/32, 100: fsys/64, 其他 fsys/128 */
#define B_SPR1			1
#define B_SPR0			0

/* sfr	SPSTA			= 0xA1;		*/	/* SPI 状态寄存器 */
#define B_SPEN			7				/* SPI控制位 0: 关, 1:开*/
#define B_SPIF			6               /* 数据发送完成标志 0:软件清零,1:数据发送完成,硬件置1 */
#define B_MODF			5               /* 模式故障 0:软件清0, 1:SS与SPI模式不一致，硬件置1 */
#define B_WCOL			4               /* 写入冲突故障 0:软件清0, 1:检测到冲突,硬件置1 */
#define B_SPRXOV		3               /* RXOV 接收超限位 0:软件清0, 1:检测到接收超限，硬件置1 */
//#define 			2
//#define 			1
//#define 			0

/* sfr	SPDAT			= 0xA3;		*/	/* SPI数据寄存器，读接收，写发送 */

/* ----------------------------------------------------------------------- */
/* ADC */
/* sfr	ADCON1			= 0x93;		*/	/* ADC控制1 */
#define B_ADON		7					/* AD允许位 0:disable, 1:enable */
#define B_ADCIF		6					/* AD中断标志位元 0:软件清零,1:序列转换完成 */
#define	B_SC		5					/* 连续转换控制位 0:disable, 1:enbale */
#define	B_REFC		4					/* AD基准源设置 0:AVDD,1:VREF */
#define B_ADCIE		3					/* 序列转换完成中断允许位 0:disable,1:enable */
#define B_PWMTRGEN	2					/* pwm012溢出信号启动序列转换 0:disable, 1:enable */
#define B_TIMTRGEN	1					/* T2溢出信号启动序列转换 0:disable, 1:enable */
#define B_ADGO		0					/* 序列转换启动控制 0:未进行序列转换, 1: SC=0时 置1开始转换,转换结束硬件清零， SC=1时 置1 启动连续转换，硬件不清零 */

/* sfr ADCON2			= 0x92;		*/	/* ADC 控制2 */
#define B_GRP3		7					/* ADC序列通道设置 1-16 */
#define B_GRP2		6
#define	B_GRP1		5
#define	B_GRP0		4
#define B_MODE		3					/* ADC精度模式 0:12bit, 1:10bit */
#define B_TGAP2		2					/* 序列相邻通道时间间隔设置 0～128ADC */
#define B_TGAP1		1
#define B_TGAP0		0

#define BADMODE10	(1<<B_MODE)		// 10
#define BADMODE12	(0<<B_MODE)		// 12

#define AdcChTota1	( (0<<(B_GRP3)) | (0<<(B_GRP2)) | (0<<(B_GRP1)) | (0<<(B_GRP1)) )		/* adc channel total */
#define AdcChTota2	( (0<<(B_GRP3)) | (0<<(B_GRP2)) | (0<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota3	( (0<<(B_GRP3)) | (0<<(B_GRP2)) | (1<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota4	( (0<<(B_GRP3)) | (0<<(B_GRP2)) | (1<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota5	( (0<<(B_GRP3)) | (1<<(B_GRP2)) | (0<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota6	( (0<<(B_GRP3)) | (1<<(B_GRP2)) | (0<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota7	( (0<<(B_GRP3)) | (1<<(B_GRP2)) | (1<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota8	( (0<<(B_GRP3)) | (1<<(B_GRP2)) | (1<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota9	( (1<<(B_GRP3)) | (0<<(B_GRP2)) | (0<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota10	( (1<<(B_GRP3)) | (0<<(B_GRP2)) | (0<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota11	( (1<<(B_GRP3)) | (0<<(B_GRP2)) | (1<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota12	( (1<<(B_GRP3)) | (0<<(B_GRP2)) | (1<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota13	( (1<<(B_GRP3)) | (1<<(B_GRP2)) | (0<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota14	( (1<<(B_GRP3)) | (1<<(B_GRP2)) | (0<<(B_GRP1)) | (1<<(B_GRP1)) )
#define AdcChTota15	( (1<<(B_GRP3)) | (1<<(B_GRP2)) | (1<<(B_GRP1)) | (0<<(B_GRP1)) )
#define AdcChTota16	( (1<<(B_GRP3)) | (1<<(B_GRP2)) | (1<<(B_GRP1)) | (1<<(B_GRP1)) )

#define AdcGaptm0	( (0<<(B_TGAP2)) | (0<<(B_TGAP1)) | (0<<(B_TGAP0)) )		/* adc gap timer adc clock */
#define AdcGaptm2	( (0<<(B_TGAP2)) | (0<<(B_TGAP1)) | (1<<(B_TGAP0)) )
#define AdcGaptm4	( (0<<(B_TGAP2)) | (1<<(B_TGAP1)) | (0<<(B_TGAP0)) )
#define AdcGaptm8	( (0<<(B_TGAP2)) | (1<<(B_TGAP1)) | (1<<(B_TGAP0)) )
#define AdcGaptm16	( (1<<(B_TGAP2)) | (0<<(B_TGAP1)) | (0<<(B_TGAP0)) )
#define AdcGaptm32	( (1<<(B_TGAP2)) | (0<<(B_TGAP1)) | (1<<(B_TGAP0)) )
#define AdcGaptm64	( (1<<(B_TGAP2)) | (1<<(B_TGAP1)) | (0<<(B_TGAP0)) )
#define AdcGaptm128	( (1<<(B_TGAP2)) | (1<<(B_TGAP1)) | (1<<(B_TGAP0)) )


/* sfr ADT				= 0x94;		*/	/* ADC时钟控制寄存器 */
#define B_TADC3		7					/* ADC时钟周期选择 */	
#define B_TADC2		6
#define	B_TADC1		5
#define	B_TADC0		4
#define B_TS3		3					/* ADC采样时间选择 */
#define B_TS2		2
#define B_TS1		1
#define B_TS0		0

/* sfr SEQCON			= 0xA6;		*/ /* ADC映射寄存器 */
#define B_ALR		7					/* ADC结果左右对齐选择位 0:左对齐, 1:右对齐 */
//#define 			6
//#define			5
#define	B_REGSEL	4					/* ADC结果与通道寄存器映射切换控制 0:0x96 0x97做ADC结果, 1:0x96 做通道寄存器用,读写即操作SEQCHX */
#define B_REG3		3					/* 寄存器通道选择 REGSEL=0, ADDxL ADDxH; REGSEL=1, SEQCHx */
#define B_REG2		2
#define B_REG1		1
#define B_REG0		0  
 
#define AdcDataRight	(1<<(B_ALR)) 
#define AdcDataLeft		(0<<(B_ALR)) 

#define SeqChoseDat		(0<<(B_REGSEL)) 
#define SeqChoseCh		(1<<(B_REGSEL)) 


#define AdcSEQCh0	( (0<<(B_REG3)) | (0<<(B_REG2)) | (0<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ0 ADD0HL */
#define AdcSEQCh1	( (0<<(B_REG3)) | (0<<(B_REG2)) | (0<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ1 ADD0HL */
#define AdcSEQCh2	( (0<<(B_REG3)) | (0<<(B_REG2)) | (1<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ2 ADD0HL */
#define AdcSEQCh3	( (0<<(B_REG3)) | (0<<(B_REG2)) | (1<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ3 ADD0HL */
#define AdcSEQCh4	( (0<<(B_REG3)) | (1<<(B_REG2)) | (0<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ4 ADD0HL */
#define AdcSEQCh5	( (0<<(B_REG3)) | (1<<(B_REG2)) | (0<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ5 ADD0HL */
#define AdcSEQCh6	( (0<<(B_REG3)) | (1<<(B_REG2)) | (1<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ6 ADD0HL */
#define AdcSEQCh7	( (0<<(B_REG3)) | (1<<(B_REG2)) | (1<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ7 ADD0HL */
#define AdcSEQCh8	( (1<<(B_REG3)) | (0<<(B_REG2)) | (0<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ8 ADD0HL */
#define AdcSEQCh9	( (1<<(B_REG3)) | (0<<(B_REG2)) | (0<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ9 ADD0HL */
#define AdcSEQCh10	( (1<<(B_REG3)) | (0<<(B_REG2)) | (1<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ10 ADD0HL */
#define AdcSEQCh11	( (1<<(B_REG3)) | (0<<(B_REG2)) | (1<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ11 ADD0HL */
#define AdcSEQCh12	( (1<<(B_REG3)) | (1<<(B_REG2)) | (0<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ12 ADD0HL */
#define AdcSEQCh13	( (1<<(B_REG3)) | (1<<(B_REG2)) | (0<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ13 ADD0HL */
#define AdcSEQCh14	( (1<<(B_REG3)) | (1<<(B_REG2)) | (1<<(B_REG1)) | (0<<(B_REG0)) )		/* SEQ14 ADD0HL */
#define AdcSEQCh15	( (1<<(B_REG3)) | (1<<(B_REG2)) | (1<<(B_REG1)) | (1<<(B_REG0)) )		/* SEQ15 ADD0HL */

/* sfr ADCH1			= 0x95;		*/	/* ADC通道配置 1:IO配置为AD或比较器2, 0:IO */ 
#define B_CH7		7
#define B_CH6		6
#define	B_CH5		5
#define	B_CH4		4
#define B_CH3		3
#define B_CH2		2
#define B_CH1		1
#define B_CH0		0
/* sfr ADCH2			= 0xA5;		*/ /* AD通道配置 */
#define B_CH11		7
#define B_CH10		6
#define	B_CH9		5
#define	B_CH8		4
//#define 			3
//#define 			2
//#define 			1
#define B_BGCHOP	0					/* 基准源CHOP功能 0:Vbg CHOP 关, 1:Vbg CHOP 开 */

/* sfr SEQCHx			= 0x96;	*/	/* SEQ通道寄存器 */ 
//#define 			7
//#define 			6
//#define			5
//#define			4
#define B_SEQX3		3
#define B_SEQX2		2
#define B_SEQX1		1
#define B_SEQX0		0

#define AdcCh0		0			
#define AdcCh1		1
#define AdcCh2		2
#define AdcCh3		3
#define AdcCh4		4
#define AdcCh5		5
#define AdcCh6		6
#define AdcCh7		7
#define AdcCh8		8
#define AdcCh9		9
#define AdcCh10		10			// a
#define AdcCh11		11			// b
#define AdcChOP1	12			// c
#define AdcChOP2	13			// d
#define AdcChVBG	14			// e

/* sfr ADDxL			= 0x96;		*/	/* ADC结果寄存器 */  
/* sfr ADDxH			= 0x97;  	*/
/* sfr16 ADDx_16		= 0x96;		*/

/* sfr ADDGTL			= 0x9E;		*/	/* AD上限比较器寄存器 */
/* sfr ADDGTH			= 0x9F;		*/
/* sfr16 ADDG_16		= 0x9E;		*/

/* sfr ADDLTL			= 0x9C;		*/	/* AD下限比较寄存器 */
/* sfr ADDLTH			= 0x9D;		*/
/* sfr16 ADDL_16		= 0x9C;		*/

/* sfr ADCMPCON			= 0x91;		*/	/* AD比较器 */
#define B_ADLIE		7					/* 下限使能位 0:disable, 1:enable */
#define B_ADHIE		6                   /* 上限使能位 */
#define	B_ADLIF		5                   /* 下限中断标志 0: never 软件清零, 1: happen */
#define	B_ADHIF		4                   /* 上限中断标志 */
#define B_CSEL3		3                   /* 选择比较器比较的对象 */
#define B_CSEL2		2
#define B_CSEL1		1
#define B_CSEL0		0

/* ----------------------------------------------------------------------- */
/*calculating unit */
/* sfr MDSCON			= 0xC1;		*/	/* 16BIT 计算控制寄存器 */
#define B_MD1		7					/* 移位,乘除选择 */
#define B_MD0		6
#define	B_SLR		5					/* 32bit 移位方向设置 */
//#define			4
//#define 			3
#define B_SIGNEN	2					/* 乘除符号使能 0:无符号, 1:带符号 */
#define B_DVERR		1					/* 除法异常 0:除数不为0, 1:除数为0 */
#define B_RUN		0					/* 运算启动，软件置1，硬件清0 */
#define BMUL	( (0<<(B_MD1)) | (0<<(B_MD0)) )						/* X */
#define BDIV	( (0<<(B_MD1)) | (1<<(B_MD0)) )						/* / */
#define BCLR	( (1<<(B_MD1)) | (1<<(B_MD0)) )						/* 0 */
#define BRL		( (1<<(B_MD1)) | (0<<(B_MD0)) | (0<<(B_SLR)) )		/* LEFT */
#define BRR		( (1<<(B_MD1)) | (0<<(B_MD0)) | (1<<(B_SLR)) )		/* RIGHT */

/* sfr OPRDA0			= 0xC2;     */	/* 被除数低16bit, 移位低16bit，结果低16bit，乘数16bit */
/* sfr OPRDA1			= 0xC3;     */
/* sfr16 OPRDAL_16		= 0xC2;     */

/* sfr OPRDA2			= 0xC4;     */	/* 被除数高16bit, 移位高16bit, 结果高16bit            */
/* sfr OPRDA3			= 0xC5;     */
/* sfr16 OPRDAH_16		= 0xC4;     */ 

/* sfr OPRDB0			= 0xC6;     */	/* 除数16bit,     移位次数,    余数,        乘数16bit */
/* sfr OPRDB1			= 0xC7;     */
/* sfr16 OPRDB_16		= 0xC6;     */

/* ----------------------------------------------------------------------- */
/* PWM3 */
/* sfr PWM3CON			= 0xAD;		*/	/* PWM3 控制寄存器 */
#define B_PWM3EN	7					/* PWM3 控制器 0: disable, 1:enable */
#define B_PWM3S		6					/* PWM3 输出电平 0:占空比有效高,其他低, 1:占空比有效低,其他高 */
#define	B_PWM3CK1	5                   /* PWM3时钟选择  00:fsys/1, 01:fsys/8, 10:fsys/64, 11:fsys/256*/
#define	B_PWM3CK0	4
#define B_FLT3EN	3                   /* PWM3故障检测 0:disable, 1:enable CMP1的信号作为故障输入 */
#define B_PWM3IE	2                   /* PWM3中断允许（IEN1_epwm3 同时为1, 才使能） 0:disable, 1: enable */
#define B_PWM3IF	1                   /* PWM3中断标志 0: 无溢出,1:溢出 硬件置1 */
#define B_PWM3OE	0                   /* PWM3 PIN功能选择 0:IO, 1:PWM3输出使用 */

/* sfr PWM3P			= 0xAE;		*/	/* 周期控制寄存器 */
/* sfr PWM3D			= 0xAF;		*/	/* 占空比控制寄存器 */

/* ----------------------------------------------------------------------- */
/* OP&CMP */
/* sfr CMP1CON			= 0xB3;		*/	/* CMP1控制寄存器 */
#define B_CMP1EN	7					/* CMP1使能位0:disable, 1: enable */
#define B_C1NCHS	6					/* CMP1 反相端N选择 0:C1N, 1:内部1.2V  */
#define	B_C1OUT		5					/* CMP1 输出端O状态 0: LOW,  1:HIGH */
#define	B_C1IF		4					/* CMP1输出上升沿中断标志 0:never, 1:happen */
//#define 			3
#define B_C1PCHS	2					/* CMP输出滤波时间 0-16us*/
#define B_C1DEB1	1
#define B_C1DEB0	0

#define IDEB_0		(  (0<<(B_C1DEB1)) | (0<<(B_C1DEB0)) ) 
#define IDEB_1		(  (0<<(B_C1DEB1)) | (1<<(B_C1DEB0)) ) 
#define IDEB_4		(  (1<<(B_C1DEB1)) | (0<<(B_C1DEB0)) ) 
#define IDEB_16		(  (1<<(B_C1DEB1)) | (1<<(B_C1DEB0)) ) 

/* sfr CMP2CON0			= 0xBB;     */
#define B_CMP2EN	7					/* CMP2使能， 0:dis 1:en*/
#define B_C2NCHS	6					/* CMP2反向端选择 0:C2N  1:内部1.2V */
#define	B_C2PCHS1	5					/* CMP2同相输入端选择00-11: C2P0,C2P1,C2P2,OPUT */	
#define	B_C2PCHS0	4
#define B_C2SMT1	3					/* CMP2施密特电压选择: 00-11: 0 - 4*5mV*/
#define B_C2SMT0	2
#define B_C2OUT		1					/* CMP2输出标志 0:LO, 1: HI*/
#define B_C2IF		0					/* CMP2中断标志 0:never, 1: happen */

#define CMP2NchC2N	(0<<(B_C2NCHS))
#define CMP2NchVRF	(1<<(B_C2NCHS))

#define P0CMP2P			(  (0<<(B_C2PCHS1)) | (0<<(B_C2PCHS0)) )  
#define P1CMP2P         (  (0<<(B_C2PCHS1)) | (1<<(B_C2PCHS0)) )  
#define P2CMP2P         (  (1<<(B_C2PCHS1)) | (0<<(B_C2PCHS0)) )  
#define OP2OUTCMP2P     (  (1<<(B_C2PCHS1)) | (1<<(B_C2PCHS0)) )  

#define CMP2Shift0		(  (0<<(B_C2SMT1)) | (0<<(B_C2SMT0)) )  
#define CMP2Shift5		(  (0<<(B_C2SMT1)) | (1<<(B_C2SMT0)) )  
#define CMP2Shift10		(  (1<<(B_C2SMT1)) | (0<<(B_C2SMT0)) )  
#define CMP2Shift20		(  (1<<(B_C2SMT1)) | (1<<(B_C2SMT0)) ) 

/* sfr CMP2CON1			= 0xBC;     */
#define B_PWMTRGS1	7					/* CMP2同步比较控制位 00-11: all,pwm012*/
#define B_PWMTRGS0	6
#define	B_TRGPOL	5					/* 同步比较器控制位 */
#define	B_BGEN		4					/* 基准源1.2V功能控制位 0:DIS 1:EN */
#define B_AMP1EN	3					/* AMP1 使能位 0:dis 1:en*/
#define B_AMP2EN	2					/* AMP2 使能位 */
#define B_C2IFS1	1					/* CMP2中断模式 */
#define B_C2IFS0	0

#define CMP2TRGSer		(  (0<<(B_PWMTRGS1)) | (0<<(B_PWMTRGS0)) )  
#define CMP2TRGPwm0		(  (0<<(B_PWMTRGS1)) | (1<<(B_PWMTRGS0)) )  
#define CMP2TRGPwm1		(  (1<<(B_PWMTRGS1)) | (0<<(B_PWMTRGS0)) )  
#define CMP2TRGPwm2		(  (1<<(B_PWMTRGS1)) | (1<<(B_PWMTRGS0)) ) 

#define CMP2TRGFlagDis	(  (0<<(B_C2IFS1)) | (0<<(B_C2IFS0)) )
#define CMP2TRGFallEn	(  (0<<(B_C2IFS1)) | (1<<(B_C2IFS0)) )
#define CMP2TRGRiseEn	(  (1<<(B_C2IFS1)) | (0<<(B_C2IFS0)) )
#define CMP2TRGDoubEEn	(  (1<<(B_C2IFS1)) | (1<<(B_C2IFS0)) )

/* sfr CMP2CON2			= 0x8F;     */
#define B_C2FT1EN	7					 /* CMP2 滤波使能*/
#define B_C2FT1S2	6					/* CMP2滤波参数 */
#define	B_C2FT1S1	5
#define	B_C2FT1S0	4
#define B_C2FT2EN	3					/* CMP2滤波使能 */
#define B_C2FT2S2	2					/* CMP2滤波常数设置000-111 : 2^n */
#define B_C2FT2S1	1
#define B_C2FT2S0	0

// INC  &  DEC FT1 
#define CMP2IDFTA0		( (0<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (0<<(B_C2FT1EN)) )
#define CMP2IDFTA8		( (0<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA16		( (0<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA32		( (0<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA64		( (0<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA128	( (1<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA256	( (1<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA512	( (1<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )
#define CMP2IDFTA1024	( (1<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT1EN)) )

// INC  &  CLEAR  FT2 
#define CMP2ICFTB0		( (0<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (0<<(B_C2FT2EN)) )
#define CMP2ICFTB2		( (0<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB4		( (0<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB8		( (0<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB16		( (0<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB32		( (1<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB64		( (1<<(B_C2FT1S2)) | (0<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB128	( (1<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (0<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )
#define CMP2ICFTB256	( (1<<(B_C2FT1S2)) | (1<<(B_C2FT1S1)) | (1<<(B_C2FT1S0)) | (1<<(B_C2FT2EN)) )

/* ----------------------------------------------------------------------- */
/* PWM */
/*PWM 0/1/2 */
/* sfr PWMCON1			= 0xD9;     */
#define B_POUTMOD	7					/* PWM012输出模式独立互补控制 0:3ch互补, 1:6ch独立 */
//#define	 		6
#define	B_PWM2LS	5					/* PWM2L 输出极性选择 0:low, 1:high */
#define	B_PWM1LS	4					/* PWM1L 输出极性选择 0:low, 1:high */
#define B_PWM0LS	3					/* PWM0L 输出极性选择 0:low, 1:high */
#define B_PWM2HS	2					/* PWM2H 输出极性选择 0:low, 1:high */
#define B_PWM1HS	1					/* PWM1H 输出极性选择 0:low, 1:high */
#define B_PWM0HS	0					/* PWM0H 输出极性选择 0:low, 1:high */

/* sfr PWMCON2			= 0xBF;     */
#define B_OSYNC		7					/* 手动修改PWMx/PWMx1输出同步位 */
#define B_ZETIM		6                   /* PWM时基计数器启动T2 */
#define	B_PEAD		5                   /* PWM 周期匹配 触发AD */
#define	B_ZEAD		4                   /* PWM 归零 触发AD  */
#define B_PDLDEN	3                   /* PWM 周期匹配 重载占空比死区 */
//#define 			2                   /* */
#define B_DT1		1                   /* 死区寄存器方式选择 */
#define B_DT0		0                   /* */

/* sfr PTCON			= 0xCF;     */
//#define 			7
//#define 			6
#define	B_PTMOD1	5					/* PWM012时基模块PWM计数器工作模式选择 */
#define	B_PTMOD0	4
#define B_PTCLK1	3					/* PWM时基预分配系数选择位断 */
#define B_PTCLK0	2
#define B_P0STPS1	1					/* 后分频系数 */
#define B_P0STPS0	0

#define PWMMODE_EDGE	( (0<<(B_PTMOD1)) | (0<<(B_PTMOD0)) )
#define PWMMODE_MID		( (0<<(B_PTMOD1)) | (1<<(B_PTMOD0)) )
#define PWMMODE_SIG		( (1<<(B_PTMOD1)) | (1<<(B_PTMOD0)) )

#define PWMTBSPRE1		( (0<<(B_PTCLK1)) | (0<<(B_PTCLK0)) )
#define PWMTBSPRE2		( (0<<(B_PTCLK1)) | (1<<(B_PTCLK0)) )
#define PWMTBSPRE4		( (1<<(B_PTCLK1)) | (0<<(B_PTCLK0)) )
#define PWMTBSPRE8		( (1<<(B_PTCLK1)) | (1<<(B_PTCLK0)) )

#define PWMPOSTSCALER1		( (0<<(B_P0STPS1)) | (0<<(B_P0STPS0)) )
#define PWMPOSTSCALER2		( (0<<(B_P0STPS1)) | (1<<(B_P0STPS0)) )
#define PWMPOSTSCALER4		( (1<<(B_P0STPS1)) | (0<<(B_P0STPS0)) )
#define PWMPOSTSCALER8		( (1<<(B_P0STPS1)) | (1<<(B_P0STPS0)) )

/* sfr PWMOE			= 0xEF;     */
#define B_PWMEN		7
//#define 			6
#define B_PWM2LOE	5					/* PWM2L 输出使能 */ /* CHOOSE: PWM & IO */
#define B_PWM1LOE	4					/* PWM1L 输出使能 */
#define B_PWM0LOE	3					/* PWM0L 输出使能 */
#define B_PWM2HOE	2					/* PWM2H 输出使能 */
#define B_PWM1HOE	1					/* PWM1H 输出使能 */
#define B_PWM0HOE	0					/* PWM0H 输出使能 */


/* sfr PMANUALCON1		= 0xB6;     */
//#define 		7
//#define 		6
#define	B_PMANUAL2L	5					/* PWMxx 输出控制 */
#define	B_PMANUAL1L	4
#define B_PMANUAL0L	3
#define B_PMANUAL2H	2
#define B_PMANUAL1H	1
#define B_PMANUAL0H	0

/* sfr PMANUALCON2		= 0xB7;     */
//#define 		7
//#define 		6
#define	B_POUT2L	5			/* PMANUALXX = 1， 控制PWMXX输出电平 */
#define	B_POUT1L	4
#define B_POUT0L	3
#define B_POUT2H	2
#define B_POUT1H	1
#define B_POUT0H	0

/* sfr FLTCON			= 0xD1;     */
#define B_FLT1EN	7				/* 故障检测1 功能控制位元 */
#define B_FLT1SEL	6				/* 贝代方1 匡拒 */
#define	B_FLT2EN	5				/* 故障检测2 控制 */
#define	B_FLT2S		4				/* 故障2 有效电平选择 */
#define	B_FLT2DEB1	3				/* 故障2 输入滤波0-16 */				
#define	B_FLT2DEB0	2
#define B_FLTM		1				/* 探测功能模式选择 */
#define B_FLTSTAT	0				/* 故障检测标志位元 */	

/* sfr PWMINTEN			= 0xBE;     */	/* 中断使能*/
#define B_PWMPIE	7					/* PWM 周期中断允许位 */
#define B_PWMZIE	6					/* PWM 归零中断允许位 */
#define B_PTDD2IE	5					/* PWM2 减占空比中断允许位 */
#define B_PTUD2IE	4					/* PWM2 增占空比中断允许位 */
#define B_PTDD1IE	3					/* PWM1 减占空比中断允许位 */
#define B_PTUD1IE	2					/* PWM1 增占空比中断允许位 */
#define B_PTDD0IE	1					/* PWM0 减占空比中断允许位 */
#define B_PTUD0IE	0					/* PWM0 增占空比中断允许位 */

/* sfr PWMINTF			= 0xE8;     */	/* 中断允许 */
#define B_PWMPIF	7					/* PWM 周期中断允许位 */     
#define B_PWMZIF	6					/* PWM 归零中断允许位 */     
#define B_PTDD2IF	5					/* PWM2 减占空比中断允许位 */
#define B_PTUD2IF	4					/* PWM2 增占空比中断允许位 */
#define B_PTDD1IF	3					/* PWM1 减占空比中断允许位 */
#define B_PTUD1IF	2					/* PWM1 增占空比中断允许位 */
#define B_PTDD0IF	1					/* PWM0 减占空比中断允许位 */
#define B_PTUD0IF	0					/* PWM0 增占空比中断允许位 */

/* sfr PWMRLDEN			= 0xE7;     */	/* PWM 写锁寄存器 0x55,0xaa*/

/* sfr	PWMPL			= 0xDA;		*/	/* PWM周期控制寄存器低8位 */
/* sfr	PWMPH			= 0xDB;		*/	/* PWM周期控制寄存器高4位 */
/* sfr16 PWMP_16		= 0xDA;     */

/* sfr	PWM0DL			= 0xDC;		*/	/* PWM0占空比控制寄存器低8位 */
/* sfr	PWM0DH			= 0xDD;		*/	/* PWM0占空比控制寄存器高4位 */
/* sfr16 PWM0D_16		= 0xDC;     */
sfr	PWM0HDL			= 0xDC;
sfr	PWM0HDH			= 0xDD;
sfr16 PWM0HD_16		= 0xDC;

/* sfr	PWM1DL			= 0xDE;		*/	/* PWM1占空比控制寄存器低8位 */
/* sfr	PWM1DH			= 0xDF;		*/	/* PWM1占空比控制寄存器高4位 */
/* sfr16 PWM1D_16		= 0xDE;     */
sfr	PWM1HDL			= 0xDE;
sfr	PWM1HDH			= 0xDF;
sfr16 PWM1HD_16		= 0xDE;

/* sfr	PWM2DL			= 0xD2;		*/	/* PWM2占空比控制寄存器低8位 */
/* sfr	PWM2DH			= 0xD3;		*/	/* PWM2占空比控制寄存器高4位 */
/* sfr16 PWM2D_16		= 0xD2;     */
sfr	PWM2HDL			= 0xD2;
sfr	PWM2HDH			= 0xD3;
sfr16 PWM2HD_16		= 0xD2;

/* sfr PWM01DL			= 0xD4;     */
/* sfr PWM01DH			= 0xD5;     */
sfr PWM0LDL			= 0xD4;
sfr PWM0LDH			= 0xD5;
sfr16 PWM0LD_16		= 0xD4;

/* sfr PWM11DL			= 0xD6;     */
/* sfr PWM11DH			= 0xD7;     */
sfr PWM1LDL			= 0xD6;
sfr PWM1LDH			= 0xD7;
sfr16 PWM1LD_16		= 0xD6;

/* sfr PWM21DL			= 0xF9;     */
/* sfr PWM21DH			= 0xFA;     */
sfr PWM2LDL			= 0xF9;
sfr PWM2LDH			= 0xFA;
sfr16 PWM2LD_16		= 0xF9;

/* sfr PWMDT0L			= 0xD4;     */	/* PWM死区控制寄存器0低8位 */
/* sfr PWMDT0H			= 0xD5;     */	/* PWM死区控制寄存器0高4位 */
/* sfr16 PWMDT0_16		= 0xD4;     */

/* sfr PWMDT1L			= 0xD6;     */	/* PWM死区控制寄存器1低8位 */
/* sfr PWMDT1H			= 0xD7;     */	/* PWM死区控制寄存器1高4位 */
/* sfr16 PWMDT1_16		= 0xD6;		*/

/* ----------------------------------------------------------------------- */
/* buzzer */
/* sfr	BUZCON			= 0xBD;		*/	/* BUZZ输出控制 */
/* #define			7				*/
/* #define			6				*/
/* #define			5				*/
#define	B_BCA3		4					/* 蜂鸣器输出串列传输速率 fsys/分频 */
#define B_BCA2		3
#define B_BCA1		2
#define B_BCA0		1
#define B_BZEN		0					/* B_P14 输出口控制 0: IO, 1: BUZZ */


#endif


