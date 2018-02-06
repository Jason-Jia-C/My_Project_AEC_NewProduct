/*--------------------------------------------------------------------------
REG79F1611.H

Header file for generic SH79xx series microcontroller.
Copyright (c) 1996-2009 Sionwealth Electronic and Sinowealth Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef REG79F1611_H
#define REG79F1611_H
/* ------------------- BYTE Register-------------------- */
/* CPU */
sfr PSW = 0xD0;            
sfr ACC = 0xE0;
sfr B 	= 0xF0;
sfr AUXC = 0xF1;
sfr SP = 0x81;
sfr DPL = 0x82;
sfr DPH = 0x83;
sfr DPL1 = 0x84;
sfr DPH1 = 0x85;
sfr INSCON   = 0x86;
sfr16 DPTR = 0x82;
/* power  */
sfr PCON  = 0x87;
sfr SUSLO = 0x8E;

/* FLASH */
sfr XPAGE = 0xF7;
sfr IB_OFFSET = 0xFB;
sfr IB_DATA = 0xFC;
sfr IB_CON1 = 0xF2;
sfr IB_CON2 = 0xF3;
sfr IB_CON3 = 0xF4;
sfr IB_CON4 = 0xF5;
sfr IB_CON5 = 0xF6;
sfr FLASHCON = 0xA7;          

/* WDT */
sfr RSTSTAT = 0xB1;

/* CLKCTRL */
sfr CLKCON = 0xB2;

/* INTERRUPT */
sfr IEN0= 0xA8;
sfr IEN1 = 0xA9;
sfr IENC = 0xBA;
sfr IPL0 = 0xB8;
sfr IPL1 = 0xB9;
sfr IPH0 = 0xB4;
sfr IPH1 = 0xB5;
sfr EXF1 = 0xD8;
                  

/* PORT */
sfr P0 = 0x80;       
sfr P0CR = 0xE1;         
        
sfr P0PCR = 0xE9;
sfr P1 = 0x90;            
sfr P1CR = 0xE2;            
sfr P1PCR = 0xEA;
sfr P2 = 0xA0;            
sfr P2CR = 0xE3;            
sfr P2PCR = 0xEB;
sfr P3 = 0xB0;            
sfr P3CR = 0xE4;            
sfr P3PCR = 0xEC;
sfr P4 = 0xC0;            
sfr P4CR = 0xE5;            
sfr P4PCR = 0xED;
sfr P5 = 0xF8;            
sfr P5CR = 0xE6;            
sfr P5PCR = 0xEE;

/* TIMER 0/1 */
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr TCON1 = 0xCE;
sfr T2CON = 0xC8;
sfr T2MOD = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr16 RCAP2_16 = 0xCA;
sfr TL2 = 0xCC;
sfr TH2 = 0xCD;
sfr16 TM2_16 = 0xCC;
sfr T3CON = 0xAC;
sfr TL3 = 0xAA;
sfr TH3 = 0xAB;

/* UART */
sfr SCON = 0x98;
sfr SBUF = 0x99;
sfr SADEN = 0x9B;
sfr SADDR = 0x9A;
sfr SBRTL = 0xFD;
sfr SBRTH = 0xFE;
sfr16 SBRT_16 = 0xFD;
sfr BFINE = 0xA4;

/* SPI */
sfr SPCON = 0xA2;
sfr SPSTA = 0xA1;
sfr SPDAT = 0xA3;

/* ADC */
sfr ADCON1 = 0x93;
sfr ADCON2 = 0x92;
sfr ADT = 0x94;
sfr SEQCON = 0xA6;
sfr ADCH1 = 0x95;
sfr ADCH2 = 0xA5;
sfr SEQCHx = 0x96;
sfr ADDxL = 0x96;
sfr ADDxH = 0x97;
sfr16 ADDx_16 = 0x96;
sfr ADDGTL = 0x9E;
sfr ADDGTH = 0x9F;
sfr16 ADDG_16= 0x9E;
sfr ADDLTL = 0x9C;
sfr ADDLTH = 0x9D;
sfr16 ADDL_16 = 0x9C;
sfr ADCMPCON = 0x91;

/*calculating unit */
sfr MDSCON = 0xC1;
sfr OPRDA0 = 0xC2;
sfr OPRDA1 = 0xC3;
sfr16 OPRDAL_16 = 0xC2;
sfr OPRDA2 = 0xC4;
sfr OPRDA3 = 0xC5;
sfr16 OPRDAH_16 = 0xC4;
sfr OPRDB0 = 0xC6;
sfr OPRDB1 = 0xC7;
sfr16 OPRDB_16 = 0xC6;

/* PWM3 */
sfr PWM3CON = 0xAD;
sfr PWM3P = 0xAE;
sfr PWM3D = 0xAF;

/* OP&CMP */
sfr CMP1CON = 0xB3;
sfr CMP2CON0 = 0xBB;
sfr CMP2CON1 = 0xBC;
sfr CMP2CON2 = 0x8F;

/*PWM 0/1/2 */
sfr PWMCON1 = 0xD9;
sfr PWMCON2 = 0xBF;
sfr PTCON = 0xCF;
sfr PWMOE = 0xEF;
sfr PMANUALCON1 = 0xB6;
sfr PMANUALCON2 = 0xB7;
sfr FLTCON = 0xD1;
sfr PWMINTEN = 0xBE;
sfr PWMINTF = 0xE8;
sfr PWMRLDEN = 0xE7;
sfr PWMPL = 0xDA;
sfr PWMPH = 0xDB;
sfr16 PWMP_16 = 0xDA;
sfr PWM0DL = 0xDC;
sfr PWM0DH = 0xDD;
sfr16 PWM0D_16 = 0xDC;
sfr PWM1DL = 0xDE;
sfr PWM1DH = 0xDF;
sfr16 PWM1D_16 = 0xDE;
sfr PWM2DL = 0xD2;
sfr PWM2DH = 0xD3;
sfr16 PWM2D_16 = 0xD2;
sfr PWM01DL = 0xD4;
sfr PWM01DH = 0xD5;
sfr PWM11DL = 0xD6;
sfr PWM11DH = 0xD7;
sfr PWM21DL = 0xF9;
sfr PWM21DH = 0xFA;
sfr PWMDT0L = 0xD4;
sfr PWMDT0H = 0xD5;
sfr16 PWMDT0_16 = 0xD4;
sfr PWMDT1L = 0xD6;
sfr PWMDT1H = 0xD7;
sfr16 PWMDT1_16 = 0xD6;


/* Buzzer  */
sfr BUZCON = 0xBD;

/*--------------------------  BIT Register -------------------- */
/*  PSW   */
sbit CY = 0xD7;
sbit AC = 0xD6;
sbit F0 = 0xD5;
sbit RS1 = 0xD4;
sbit RS0 = 0xD3;
sbit OV = 0xD2;
sbit F1 = 0XD1;
sbit P = 0xD0;

/*  IPL0   */ 
sbit PADCL = 0xBE;
sbit PT2L = 0xBD;
sbit PSL = 0xBC;
sbit PT1L = 0xBB;
sbit PX1L = 0xBA;
sbit PT0L = 0xB9;
sbit PX0L = 0xB8;

/*  SCON  */
sbit SM0_FE = 0x9F;
sbit SM1_RXOV = 0x9E;
sbit SM2_TXCOL = 0x9D;
sbit REN = 0x9C;
sbit TB8 = 0x9B;
sbit RB8 = 0x9A;
sbit TI = 0x99;
sbit RI = 0x98;

/*  TCON  */
sbit TF1 = 0x8F;
sbit TR1 = 0x8E;
sbit TF0 = 0x8D;
sbit TR0 = 0x8C;
sbit IE1 = 0x8B;
sbit IT1 = 0x8A;
sbit IE0 = 0x89;
sbit IT0 = 0x88;

/*  IEN0   */
sbit EA = 0xAF;
sbit EADC = 0xAE;
sbit ET2 = 0xAD;
sbit ES = 0xAC;
sbit ET1 = 0xAB;
sbit EX1 = 0xAA;
sbit ET0 = 0xA9;
sbit EX0 = 0xA8;

/*  EXF1  */
sbit IF47 = 0xDF;
sbit IF46 = 0xDE;
sbit IF45 = 0xDD;
sbit IF44 = 0xDC;
sbit IF43 = 0xDB;
sbit IF42 = 0xDA;
sbit IF41 = 0xD9;
sbit IF40 = 0xD8;

/* T2CON */
sbit TF2 = 0xCF;
sbit EXF2 = 0xCE;
sbit TRG = 0xCD;

sbit EXEN2 = 0xCB;
sbit TR2 = 0xCA;
sbit CT2 =  0xC9;
sbit CPRL2 = 0xC8;

/*  PWMINTF  */
sbit PWMPIF = 0xEF;
sbit PWMZIF = 0xEE;
sbit PTDD2IF = 0xED;
sbit PTUD2IF = 0xEC;
sbit PTDD1IF = 0xEB;
sbit PTUD1IF = 0xEA;
sbit PTDD0IF = 0xE9;
sbit PTUD0IF = 0xE8;

/* P0 */
sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
sbit P0_4 = P0^4;
sbit P0_5 = P0^5;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;

/* P1 */
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

/* P2 */
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;
sbit P2_5 = P2^5;
sbit P2_6 = P2^6;
sbit P2_7 = P2^7;

/* P3 */
sbit P3_0 = P3^0;
sbit P3_1 = P3^1;
sbit P3_2 = P3^2;
sbit P3_3 = P3^3;
sbit P3_4 = P3^4;
sbit P3_5 = P3^5;
sbit P3_6 = P3^6;
sbit P3_7 = P3^7;

/* P4 */
sbit P4_0 = P4^0;
sbit P4_1 = P4^1;
sbit P4_2 = P4^2;
sbit P4_3 = P4^3;
sbit P4_4 = P4^4;
sbit P4_5 = P4^5;
sbit P4_6 = P4^6;
sbit P4_7 = P4^7;

/* P5 */
sbit P5_0 = P5^0;
sbit P5_1 = P5^1;
sbit P5_2 = P5^2;
sbit P5_3 = P5^3;
   
#endif

