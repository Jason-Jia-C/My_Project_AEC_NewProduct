/*
项目名称：
PCBA料号：
编写时间：
修改版本：
芯片型号: SH79F1615P	 LQFP32		外部晶振 11.0592M
功能: 
	内部128K晶振
	外部11.0592M晶振
	休眠功耗?uA
*----------NB be here!---------- 
* 　　　┏┓　　　┏┓ 
* 　　┏┛┻━━━┛┻┓ 
* 　　┃　　　　　　　┃ 
* 　　┃　　　━　　　┃ 
* 　　┃　┳┛　┗┳　┃ 
* 　　┃　　　　　　　┃ 
* 　　┃　　　┻　　　┃ 
* 　　┃　　　　　　　┃ 
* 　　┗━┓　　　┏━┛ 
* 　　　　┃　　　┃神兽保平安
* 　　　　┃　　　┃代码无BUG！ 
* 　　　　┃　　　┗━━━┓ 
* 　　　　┃　　-_-　 　　┣┓ 
* 　　　　┃　　　　　　　┏┛ 
* 　　　　┗┓┓┏━┳┓┏┛ 
* 　　　　　┃┫┫　┃┫┫ 
* 　　　　　┗┻┛　┗┻┛ 
* ━━━━━━神兽出没━━━━━━by:Jason Jia 
*/
#include <CONFIG_1615.H>

#define KEY1	P0_4
#define KEY2	P3_3
#define EN33	P2_4
#define CE57	P2_3
#define COB1	P2_2
#define COB2	P2_1
#define RXD		P3_1
#define TXD		P3_2

#define COM1	P0_0
#define COM2	P0_1
#define	COM3	P0_2
#define	COM4	P0_3
#define	DPY		P1
#define Time	P0_7

#define CHG_G	P0_6
#define CHG_R	P0_5

//DPY
#define C_0		0										//#define C_0		0x3F									
#define C_1		1										//#define C_1		0x06
#define C_2		2										//#define C_2		0x5B
#define C_3		3										//#define C_3		0x4F
#define C_4		4										//#define C_4		0x66
#define C_5		5										//#define C_5		0x6D
#define C_6		6										//#define C_6		0x7D
#define C_7		7										//#define C_7		0x07
#define C_8		8										//#define C_8		0x7F
#define C_9		9										//#define C_9		0x6F
#define C_dp	10										//#define C_dp		0x80
#define C_E		11										//#define C_E		0x79
#define C_r		12										//#define C_r		0x70
#define Close	13

//RF
#define RF_F	0x46
#define RF_O	0x4F
#define RF_M	0x6D
#define RF_E	0x45
#define	RF_0 	0x30
#define RF_1	0x31
#define	RF_2	0x32
#define RF_3	0x33
#define	RF_4	0x34
#define	RF_5	0x35
#define	RF_6	0x36
#define	RF_7	0x37
#define	RF_8	0x38
#define	RF_9	0x39
#define RF_D	0x2E
#define RF_SW_C 0
#define RF_SW_O	1
#define RF_BAT_CLOSE	1
#define RF_BAT_OPEN		0

//Hlat
section0 bool	b_halt_flag=0;
section2 uint8	u8_tm_halt_100ms=0;
//Time
section0 bool	b_tm0_1ms_flag=0;
section0 bool	b_tm0_100ms_flag=0;
section0 bool	b_tm0_1s_flag=0;
section0 bool	b_tm0_10s_flag=0;

section2 uint8	u8_tm0_1ms_cnt=0;
section2 uint8	u8_tm0_100ms_cnt=0;
section2 uint8	u8_tm0_1s_cnt=0;

//ADC									   
section0 bool	b_adc_finish;
section2 uint16	u8_adc_cnt;
section2 uint16 u16_adc_vdd;
section2 uint16 u16_adc_sum;
section2 uint16	u16_adc_max;
section2 uint16	u16_adc_min;
section2 uint16 u16_adc_finish;

//KEY
section0 bool	b_key1=0;
section0 bool	b_key_trg1=0;
section0 bool	b_key_date1=0;
section0 bool	b_key_cont1=0;
section2 uint8	u8_tm_key1_1ms=0;

section0 bool	b_key2=0;
section0 bool	b_key_trg2=0;
section0 bool	b_key_date2=0;
section0 bool 	b_key_cont2=0;
section2 uint8	u8_tm_key2_1ms=0;

//CHG
section0 bool	b_CHG_G=1;
section0 bool	b_CHG_trgG=0;
section0 bool	b_CHG_dateG=0;
section0 bool	b_CHG_contG=0;
section2 uint8	u8_tm_CHGG_1ms=0;

section0 bool	b_CHG_R=1;
section0 bool	b_CHG_trgR=0;
section0 bool	b_CHG_dateR=0;
section0 bool	b_CHG_contR=0;
section2 uint8	u8_tm_CHGR_1ms=0;

section0 bool	b_chg_flag=0;
section0 bool	b_chg_full_flag=0;
section0 bool	b_dpy_chg_500ms_flag=0;
section0 bool	b_dpy_chg_100ms_flag=0;
section0 bool	b_dpy_chg_turn_flag=0;
section2 uint8	u8_dpy_chg_cnt=0;	
section2 uint8	u8_dpy_chg_100ms_cnt=0;


//MODE
section2 uint8	u8_led_mode=0;
section2 uint8	u8_rf_mode=0;


//RF

section2 u8_rf_rx[30];
section2 uint8 u8_rx_dpy[5];
section2 u8_rf_wt[3]={
		RF_SW_C,RF_O,RF_F,
};
/*	RF_F	0x46	RF_O	0x4F	RF_M	0x6D	RF_E	0x45	
	RF_0 	0x30	RF_1	0x31	RF_2	0x32	RF_3	0x33
	RF_4	0x34	RF_5	0x35	RF_6	0x36	RF_7	0x37
	RF_8	0x38	RF_9	0x39 	RF_D	0x2E 				*/
section2 uint8	u8_rf_rx_cmp[14]={
		RF_0,RF_1,RF_2,RF_3,RF_4,RF_5,RF_6,RF_7,RF_8,RF_9,RF_D,RF_O,RF_M,RF_E
};
section0 bool	b_rf_rx_start_flag=0;
section0 bool	b_rf_rx_finish_flag=0;
section0 bool	b_rf_rx_wait_flag=0;
section0 bool	b_rf_rx_cmp_flag=0;
section0 bool	b_rx_dpy_ready_flag=0;
section0 bool	b_rx_lose_flag=0;
section0 bool	b_rf_wt_finish_flag=0;
section0 bool	b_rf_wt_lose_flag=0;
section2 uint8	u8_rf_rx_buf=0;
section2 uint8	u8_rf_rx_i=0;
section2 uint8	u8_tm_rf_rx_100ms=0;
section2 uint8	u8_tm_rf_wt_100ms=0;
section2 uint8	u8_rf_rx_type=0;
section2 uint8	u8_rf_rx_type_pos=0;
section2 uint8	u8_rf_rx_type_cnt1=0;
section2 uint8	u8_rf_rx_type_cnt2=0;
section2 uint8	u8_rf_rx_dpy_cnt1=0;
section2 uint8	u8_rf_rx_dpy_cnt2=0;
section2 uint8	u8_rf_rx_dpy_cnt3=0;
section2 uint8 	u8_tm_rf_sw_1s=0;
section0 bool	b_rf_bat_sw_flag=0;
section2 uint8	u8_tm_rf_sw_100ms=0;

//DPY
section0 bool	b_dpy_flag=0;
section2 uint8	u8_dpy_bit=0;
section2 uint8	u8_dpy_var[4]=
					{
						C_E,C_r,C_0,C_5
					};
section2 uint8	u8_dpy_con[14]=									
					{
						0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x80,0x79,0x70,0x00		
					};
section2 uint8	u8_dpy_chg[10]=
					{
						0x01,0x02,0x04,0x08,0x10,0x20,0x39,0x09,0x09,0x0F
					};



void Seg_Set();
void MixSeg_Set();
void Time_Set();
void Interrupt_Set();
void Euart_Set();
void ADC_Set();
void CMP_Set();
void PWM_Set();
void IO_Set();

void Delay_Wdt(uint16 u16_Delay_cnt);
/*	
	Interrupt Number:
	INT0 0;		Time0 1;	INT1 2;		Time1 3;	Euart 4;	Time2 5;	ADC 6;		
	CMP1 8;		CMP2 9;		INT4 10;	Time3 11;	MCM	12;		PWM3 13;	SCM 14;
*/
void int0_isr(void)			interrupt 0
{	IE0		= 0;	}
void int1_isr(void)			interrupt 2
{	IE1		= 0;	}
void time1_isr(void)		interrupt 3
{	TF1		= 0;	}
void time2_isr(void) 		interrupt 5
{	TF2		= 0;	}
void adc_isr(void)			interrupt 6
{	ADCON1	&= B10111111;	ADCMPCON	&= B11000000;	}
void cmp1_isr(void)			interrupt 8
{	CMP1CON &= B11101111;	}
void cmp2_isr(void)			interrupt 9
{	CMP2CON0&= B11111110;	}
void time3_isr(void)		interrupt 11
{	T3CON	&= B01111111;	}
void mcm_isr(void)			interrupt 12
{	PWMINTF &= B00000000;	}
void pwm3_isr(void)			interrupt 13
{	PWM3CON &= B11111101;	}
/*
	Time0 Working IN Mode1 Period = (Fsys/12/(65536-[TH0:TL0]))
	1ms		TH0 = 0xFC		TL0 = 0x67	
*/
void time0_isr(void)		interrupt 1
{
	TF0		= 0;						//Clean Time0 Interrupt Flag
	TR0		= 1;						//Start Time0
	TL0 	= B01100111;				//0x67
	TH0		= B11111100;				//0xFC
	b_tm0_1ms_flag=1;
	Time=~Time;
	if(u8_led_mode==2)
		CE57=~CE57;
	
}
/*
	Euat Working IN Mode1 BuadRate = (Fsys/16/(32768-SBRT))
	19200 	SBRT = 0x7FDC	(32732	36)
	9600	SBRT = 0x7FB8	(32696	72)
*/
void uart_isr(void)			interrupt 4																			 	
{
	//	ES0 = 0;
	if(RI)							//接收中断
	{
		RI = 0x00;
		ACC = SBUF;
		if(b_rf_wt_finish_flag==1)
		{
			u8_rf_rx_buf = ACC;
			u8_tm_rf_rx_100ms=10;
			u8_tm_rf_wt_100ms=0;
			if(b_rf_rx_finish_flag == 0)
			{
				u8_rf_rx[u8_rf_rx_i]=u8_rf_rx_buf;
				u8_rf_rx_i++;
				if((u8_rf_rx_i>29)||u8_rf_rx_buf==0x0A)
				{
					b_rf_rx_finish_flag=1;
					b_rf_wt_finish_flag=0;
					u8_tm_rf_rx_100ms=0;
					u8_rf_rx_i=0;
				}	
			} 	
		}
	}
//	ES0 = 1;	
}
void int4_isr(void)			interrupt 10
{
	IEN1	&=	B00001000;				//Open INT4
	IENC	|=	B11111111;				//Open INT4.7
	PCON	&=	B00110000;				//Doubler Trigger
	EXF1	&= 	B00000000;				//INT4 ALL Interrupt Flag is Zero				
}

void Delay_Wdt(uint16 u16_Delay_cnt)
{
	while(u16_Delay_cnt>1)
	{
		CLR_WDT();
		u16_Delay_cnt--;	
	}
}
void Seg_Set()
{
	MixSeg_Set();
	Interrupt_Set();
	Time_Set();
	Euart_Set();
	ADC_Set();
	CMP_Set();
	PWM_Set();
	IO_Set();
}
void MixSeg_Set()
{
	
	//System Clock Set
	CLKCON	= B00001000;				//Open 11.0592MHZ
	Delay_Wdt(10);
	CLKCON	= B00001100;				//7:NC 6-5:Fsys=Fosc(OSCSCLK) 4:NA 3:Select double Oscilltor 2:Open HF System Clock	1:Select OSCSCLK = OSCXCLK
	PCON	= B00110000;				//7:SMOD,Baud Rate Doubler In Mode2 BuadRate (0)=Fsys/64 (1)=Fsys/32 6:SSTAT,SconSeg Working Mode Select 0-SM0~SM2 1-FE~TXCOL 5-4:IN41-IT40,00 Low Level Trig 01 Falling Edge Trig 10 Rising Edge Trig 11 Double Trig 3-2:GF1-GF0 1:PD 0:IDL
	BUZCON	= B00000000;				//7-5:NC 4-1:BCA[3-0],BUZ Clock Select	0:BZEN	0 P1.4=IO	1 P1.4=BUZOUT
	RSTSTAT	= B00000010;				//7:WDOF 6:NC 5:PORF 4:LVRF 3:CLRF 2-0:WDT[2:0] 000=4096MS 001=1024MS 010=256MS 011=128MS 100=64MS 101=16MS 110=4MS 111=1MS	
}
void Interrupt_Set()
{
/*	IEN0	= B10000000;				//7:EA,All Interrupt EN 6:EADC,ADC EN 5:ET2,Time EN 4:ES,Euart EN 3:ET1,Time1 EN 2:EX1,INT1 EN 1:ET0,Time0 EN 0:EX0,INT0 EN
	IEN1	= B00000000;				//7:ESCM,SCM EN 6:EPWM3,PWM3 EN 5:EMCM,MCM EN(Motor Control Module) 4:ET3,Time3 EN 3:EX4,INT4 EN 2:ECPM2,ECPM2 EN 1:ECPM1,ECPM1 EN 0:NC 
	IENC	= B00000000;				//7-0:EXS4X,INT4 Path Select 0:DisAllow 1:Allow
	EXF1	= B00000000;				//7-0:IF4X,INT4 Interrupt Request Flag 0:NO	1:YES*/
		IEN0	= B10010010;				//Open EA Open Euart Open Time0
		IEN1	= B00000000;				//Close INT4
		IENC	= B00000000;				//Open INT4 Channel	(Open EXS47)
		TCON	= B00000000;				
		PCON	= B00110000;				//INT4 Double Trigger
		EXF1	= B00000000;	 
}
void CMP_Set()
{
	CMP1CON	= B00000000;				//7:CMP1EN 6:C1NCHS 5:C1OUT 4:C1IF 3:NC 2:C1PCHS 1:C1DEB1 0:C1DEB0
	CMP2CON0= B00000000;				//7:CMP2EN 6:C2NCHS 5:C2PCHS1 4:C2PCHS0 3:C2SMT1 2:C2SMT0 1:C2OUT 0:C2IF
//	CMP2CON1= B00000000;				//AMP and CMP2 Control Seg1
	CMP2CON2= B00000000;				//CMP2 Control Seg2
}
void PWM_Set()
{
//MCM (Motor Control Module)PWM0/1/2
	PTCON	= B00000000;				//7-6:NC 5-4:PTMOD1 PTMOD0,PWM Count Working Mode Select 3-2:PTCLK1 PTCLK0,PWM Count Clock Select 00=Fsys/1 01=Fsys/2 10=Fsys/4 11=Fsys/8 1-0 POSTPS1 POSTPS0
	PWMCON1	= B00000000;				//PWM Control Seg 1
	PWMCON2	= B00000000;				//PWM Control Seg 2
	PWMOE	= B00000000;				//PWM Output EN Seg
	PMANUALCON1 = B00000000;			//PWM Output Control Seg1
	PMANUALCON2 = B00000000;			//PWM Output Control Seg2
	FLTCON	= B00000000;				//PWM Fault Seg
	PWMINTEN= B00000000;				//PWM Interrupt Control Seg
	PWMINTF	= B00000000;				//PWM Interrupt Flag Seg
	PWMRLDEN= B00000000;				//PWM Segs Revise Control Seg!!! 

	PWMPL	= B00000000;				//PWM Period Seg Low
	PWMPH	= B00000000;			   	//PWM Period Seg High
	PWM0DL	= B00000000;				//PWM0 Duty Cycle Seg Low
	PWM0DH	= B00000000;				//PWM0 Duty Cycle Seg High
	PWM1DL	= B00000000;				//PWM1 Duty Cycle Seg Low
	PWM1DH	= B00000000;				//PWM1 Duty Cycle Seg High
	PWM2DL	= B00000000;				//PWM2 Duty Cycle Seg Low
	PWM2DH	= B00000000;				//PWM2 Duty Cycle Seg High
	PWM01DL	= B00000000;				//PWM01 Duty Cycle Seg Low
	PWM01DH	= B00000000;				//PWM01 Duty Cycle Seg High
	PWM11DL	= B00000000;				//PWM11 Duty Cycle Seg Low
	PWM11DH	= B00000000;				//PWM11 Duty Cycle Seg High
	PWM21DL	= B00000000;				//PWM21 Duty Cycle Seg Low
	PWM21DH	= B00000000;				//PWM21 Duty Cycle Seg High
	PWMDT0L	= B00000000; 				//PWM Dead Zone Control Seg0 Low
	PWMDT0H	= B00000000;				//PWM Dead Zone Control	Seg0 High
	PWMDT1L	= B00000000;				//PWM Dead Zone Control Seg1 LOW												 	
	PWMDT1H = B00000000;				//PWM Dead Zone Control Seg1 High		

//PWM3
	PWM3CON	= B00000000;				//7:PWM3EN Close/Open PWM 6:PWM3S High/Low Level effective 5-4:PWM3CK1-PWM3CK0 Select PWM3 Clock(00:Fsys/1 01:/8 10:/64 11:/256) 3:FLT3EN 2:PWM3IE PWM3 Interrupt allow or disallow 1:PWM3IF PWM Interrpt Flag 0:PWM3OE PWM3 Output Contrl Bit 0:Disallow Output PWM3 is IO 1:Allow PWM3 OutPut
	PWM3P	= B00000000;				//7-0:PWM3 Output Cycle = PWM3P*PWM if(Clock PWM3P==0x00) PWM3S=0,PWMPin Output Low; PWM3S=1,PWMPin Output High
	PWM3D	= B00000000;				//7-0:PWM3 DutyCycle if(PWM3P<=PWM3D)PWM3S=0,PWMPin Output High;PWM3S=0,PWMPin Output Low if(PWM3D=0x00) PWM3S=0,PWMPin Output Low;PWM3S=1,PWMPin Output High
}
void Time_Set()						
{
/*	
	TCON	= B00000000;				//7:TF1 Time1 Flag  6:TR1 Time1 SN  5:TF0 Time0 Flag  4:TR0 Time0 SN 3:IE1,INT1 Flag 2:IT1,INT1 Trig Mode 0 Low Level Trig 1 High Level Trig 1:IE0,INT0 Flag  0:IT0 INT0 Trig Mode 0 Low Level Trig 1 High Level
	TMOD	= B00000000;				//7:GATE1 6:C/T1 Select Time or Count 5-4 M11-M10 Select Time1 Mode(01:Mode1) 3:GATE0 2:C/T0 1-0:M01-M00
	TCON1	= B00000000;				//7:NC 6:TCLK_S1 5:TCLK_S0(Select TimeX Clock=Fsys(0) or 128khz(1)) 4:NC 3:TCLKP1 2:TCLKP0 (Select TimeX Clock=Fsys(1) or Fsys/12(0) 1:TC1 0:TC0(Close CP Out) 
	T2CON	= B00000000;				//7:TF2(Time2 Flag) 6:NC 5:TRG(Select Open(1) or Close(0) Single Trigger) 4:NC 3:NC 2:TR2(Select Time2 is Open(1) or Close(0)) 1:NC 0:NC
	T2MOD	= B10000000;				//7:TCLKP2(Select Time2 Clock Source 1:Time2 Clock = Fsys 0:Time2 Clock = Fsys/12)
	T3CON	= B00000000;				//7:TF3(Time3 Flag)	6:NC 5-4:T3PS.1-T3PS.2(Select X  00:Fsys/1 01:Fsys/8 10:Fsys/64 11:Fsys/256) 3:NC 2:TR3(Close or Open Time3) 1-0:T3CLKS.1 T3CLKS.0(Time3 Clock Setect 00:Fsys T3 is IO 01:Clock is T3 10:128KHz 11:NC)
*/
	TL0 	= B01100111;				//0x67
	TH0		= B11111100;				//0xFC
	TL1 	= B00000000;
	TH1		= B00000000;
	TL2		= B00000000;  
	TH2		= B00000000;
	RCAP2L	= B00000000;
	RCAP2H	= B00000000;
	TL3		= B00000000;
	TH3		= B00000000;

	TCON	= B00010000;				//Start Time0
	TMOD	= B00000001;				//Time0 is Timer   Working Mode is mode1
	TCON1	= B00000000;				//Ft0=Fsys/12
	T2CON	= B00000000;				//Close Time2
	T2MOD	= B00000000;				//Time2 Stauts is Close
	T3CON	= B00000000;				//Close Time3			
}	 
void Euart_Set()
{
	SBUF	= B00000000;				//7-0:SBUF7-0,Euart Date Receiving and Sending Res
	BFINE	= B00000000;				//7-4:NC 3-0:BFINE.3-BFINE.0 Euart Buad Rate Generator Fine Tune Date Res!!
	SCON	= B01010000;				//Mode1	Allow Read		
	SBRTL	= B11011100;				//0xDC
	SBRTH	= B11111111;				//0x7F  Open Buad Rate Generator	BuadRate=(11059200/16/(32768-SBRT)) SBRT=7FB8 SBRT=SBRTH[6:0]<<8+SBRTL
}
void ADC_Set()
{	
	ADT		= B00000000;				//7-4:TADC[7:4],ADC Clock Select 0000 = Fsys/1隆垄01=/2隆垄10=/3隆垄11=/4隆垄100=/6隆垄101=/8隆垄110=/12隆垄111=/16隆垄//1000=/24隆垄1001=/32隆垄1010=/48隆垄1011=/64隆垄1100=/96隆垄1101=/128隆垄1110=/192隆垄1111=/1.5 
										//3-0:TS[3:0],Sample Times Select =  (TS[3:0]+1)*ADC Clock Select	(0111,1000 Fad=Fsys/16 ST=9Tad)
	ADCON1	= B00000000;				//7:ADON,0 Allow ADC 1 DisAllow ADC 6:ADCIF,ADC Finish Interrupt Flag 5:SC,Continuous Conversion ControlBit 0 DisAllow 1 Allow  
										//4:REFC,Ref Voltage Select 0 Vdd 1 Vref 3:ADCIE,0 DisAllow ADC Interrupt 1 Allow 2-1:DisAllow PWM and Time Interrupt Trigger 0:GO/DONE,ADC STARTBIT 0 Stop 1 Start
	ADCON2	= B00000000;				//7-4:GRP[3:0]拢卢ADC Channel = GRP[3:0]+1	3拢潞MODE拢卢Select ADC Mode 0 12BIT 1 10BIT 	2-0:TGAP[1:0],000 NO Wait Time
	SEQCON	= B00000000;				//7:ALR,0 ADD0H<<8+ADD0L>>4 1 ADDOH<<8+ADD0L 6-5:NC 4:REGSEL !!! 0 96H&97H=ADDxL/H 1 96H=SEQCHx
	ADCH1	= B00000000;				//7-0:CH[7:0], 1 P0x=ANx 0 P0x(2-7)=IO
	ADCH2	= B00000000;				//7-4:CH[11:8],1 P1x=ANx 0 P1x(2,3,,6)=IO 3-1:NC 0:BGCHOP,Vbg CHOP ControlBit 0 Close 1 Open 
	CMP2CON1= B00000000;				//7-5:NC 4:BGEN,Vbg ControlBit 1:Open 0:Close Vbg=1.2v 3-0:NC
	SEQCHx	= B00000000;				//7-4:NC 3-0:SEQx[3:0] 0000,CH0 01,CH1 10,CH2 11,CH3 100,CH4 101,CH5 1000,CH8 1001,CH9 1010,CH10 1100,OP1OUT 1110,Vbg
	ADCMPCON= B00000000;				//7-0:Close ALL										//DVbg		= 1.2V/Vdd*4096		Vdd*DVbg	=1.2V*4096		Vdd		= 1.2V*4096/DVbg 

}
/*
COM1 P0_0		COM2 P0_1		COM3 P0_2		COM4 P0_3		KEY2 P0_4		Time P0_7		
DPY	 P1
COB2 P2_1		COB1 P2_2		CE57 P2_3		EN33 P2_4
RXD	 P3_1		TXD	 P3_2		KEY1 P3_3
*/
void IO_Set()
{
/*
	PX:		Select the IO level is High-Level or Low-Level		(1) Is High Level	(0)	Is Low Level
	PXCR:	Select the IO state is Input or Output				(1)	Is Output		(0)	Is Input
	PXPRCR:	Select the IO Pull_Up Res is Open or Close			(1)	Is Open			(0)	Is Close
			   76543210	*/		

	P0		= B00010000;					//0.4 Port is INT47 and KEY	0.7 Port is Time0 Test Port								
	P0CR	= B10001111;					//NEW 0.6&0.5 CHG Status Port	Low is CHG
	P0PCR	= B01110000;					
	P0		= B00010000;														

	P1		= B00000000;					//P1 Port is DPY A~DP
	P1CR	= B11111111;		
	P1PCR	= B00000000;
	P1		= B00000000;					

	P2		= B00000000;					//COB2 sw is 2.1;	COB1 sw is 2.2;		CE sw is 2.3;	EN33 sw is 2.4
	P2CR	= B11111111;
	P2PCR	= B00000000;
	P2		= B00000000;					
										   
	P3		= B00001110;					//RXD sw is 3.1; TXD sw is 3.2;		KEY1 sw is 3.3
	P3CR	= B11110101;
	P3PCR	= B00001010;
	P3		= B00001110;					 				
}
void Low_Power()
{
	if(u8_rf_mode>0||u8_led_mode>0||b_chg_flag==1)
		u8_tm_halt_100ms=0;
	if(u8_tm_halt_100ms>49)
	{
		b_halt_flag=1;
		u8_tm_halt_100ms=0;
	}
	if(b_halt_flag==1)
	{
		P0CR	&= B11111011;					//NEW 0.6&0.5 CHG Status Port	Low is CHG
		IEN1	= B00001000;				//Open INT4
		IENC	= B11111111;				//Open INT4 Channel	(Open EXS47 Open EXS45 Open EXS42 )
		Delay_Wdt(10);
		SUSLO	=	0x55;		
		PCON	|=	B00000011;				//PD and IDL Set T0 One		MCU Enter The Power Off Mode	
		b_halt_flag=0;
		IEN1	&= B11110111;				//Open INT4
		IENC	= B00000000;				//Open INT4 Channel	(Open EXS47 Open EXS45 Open EXS42 )
		P0CR	|= B00000100;					//NEW 0.6&0.5 CHG Status Port	Low is CHG
	}
}

void ADC_Cvn()							//ADC Conversion thread
{	
	ADT		= B10011110;				//0x78	Tad=Fsys/32		Tst=(8+1)* Tad
	ADCON2	= B00000000;				//0x00	ADC Channel is 1 	Working mode is 12BIT		NO Wait Time
	ADCH1	= B00000000;				//0x00	P0x(2-7)=IO
	ADCMPCON= B00000000;
	ADCH2	= B00000001;				//0x00	P1x(2,3,6)=IO		Open Vbg CHOP
	CMP2CON1|=B00010000;				//0x10	Open Vbg			Need Advance 100us Open	Vbg
	SEQCON	= B10010000;				//0x10 	96H-SEQCHx		96H-SEQCH0
	SEQCHx	= B00001110;				//0x0E	ADC Channel = Vbg
	ADCON1	= B10000000;
	Delay_Wdt(1);
	ADCON1	|=B00000001;
	while((ADCON1&0x40)==0){CLR_WDT();}	//While ADC Finish Flag == 0
	ADCON1	&=B10111111;					//CLR ADC Finis Flag
	SEQCON	= B10000000;					//Select ALR = 1
	u16_adc_vdd=((uint16)(ADDxH)<<8)+ADDxL;
}
void ADC_Cal()							//ADC Calculation thread
{
	ADC_Cvn();
	u16_adc_sum	+= u16_adc_vdd;
	if(u16_adc_sum>u16_adc_max)
		u16_adc_max	= u16_adc_sum;
	if(u16_adc_sum<u16_adc_min)
		u16_adc_min = u16_adc_sum;
	u8_adc_cnt++;
	if(u8_adc_cnt>=10)
	{
		u8_adc_cnt=0;
		u16_adc_sum		-=	u16_adc_max;
		u16_adc_sum		-=	u16_adc_min;
		u16_adc_max	 	=	0x0000;
		u16_adc_min		=	0xFFFF;
		u16_adc_finish	=	(u16_adc_sum>>3);
		u16_adc_sum	 	= 	0x0000;
		b_adc_finish	=	1;
	}
}
void COB_Con()
{
	if(u8_led_mode==1)
	{	CE57=1;		P2CR|=B00000100;	COB1=1;				COB2=0;				P2CR&=B11111101;	}				 
	else if(u8_led_mode==2)
	{	COB1=0;				P2CR&=B11111011;	P2CR|=B00000010;	COB2=1;	}
	else if(u8_led_mode==3)
	{	CE57=1;		COB1=0;				P2CR&=B11111011;	P2CR|=B00000010;	COB2=1;	}
	else
	{	CE57=0;		P2CR&=B11111001;	}
}

void KEY_Sca()
{
	if(KEY1!=b_key1)
	{
		if(u8_tm_key1_1ms>35)
		{
			b_key1=KEY1;
			u8_tm_key1_1ms=0;
		} 
	}
	else
	{
		u8_tm_key1_1ms=0;
		b_key_date1=b_key1^0x01;
		b_key_trg1=b_key_date1&(b_key_date1^b_key_cont1);
		b_key_cont1=b_key_date1;
	}
	if(KEY2!=b_key2)
	{
		if(u8_tm_key2_1ms>35)
		{
			b_key2=KEY2;
			u8_tm_key2_1ms=0;
		} 
	}
	else
	{
		u8_tm_key2_1ms=0;
		b_key_date2=b_key2^0x01;
		b_key_trg2=b_key_date2&(b_key_date2^b_key_cont2);
		b_key_cont2=b_key_date2;
	}
	if(CHG_G!=b_CHG_G)
	{
		if(u8_tm_CHGG_1ms>35)
		{
			b_CHG_G=CHG_G;
			u8_tm_CHGG_1ms=0;
		} 
	}
	else
	{
		u8_tm_CHGG_1ms=0;
		b_CHG_dateG=b_CHG_G^0x01;
		b_CHG_trgG=b_CHG_dateG&(b_CHG_dateG^b_CHG_contG);
		b_CHG_contG=b_CHG_dateG;
	}
	if(CHG_R!=b_CHG_R)
	{
		if(u8_tm_CHGR_1ms>35)
		{
			b_CHG_R=CHG_R;
			u8_tm_CHGR_1ms=0;
		} 
	}
	else
	{
		u8_tm_CHGR_1ms=0;
		b_CHG_dateR=b_CHG_R^0x01;
		b_CHG_trgR=b_CHG_dateR&(b_CHG_dateR^b_CHG_contR);
		b_CHG_contR=b_CHG_dateR;
	}
				  
}
void KEY_Con()
{
	KEY_Sca();
	if(b_key_cont1==1&&b_key_trg1==1)				//COB	
	{
		u8_led_mode++;
		if(u8_led_mode>3)
			u8_led_mode=0;
		COB_Con();
	}
	if(b_key_cont2==1&&b_key_trg2==1)				//RF		
	{
 		if(b_chg_flag==0)
		{
			if(u8_rf_mode==0)
			{	
				EN33=1;
				Delay_Wdt(65000);
				Delay_Wdt(18000);
			}
			u8_rf_mode++;
			if(u8_rf_mode>2)
				u8_rf_mode=1;	
			if(u8_rf_mode==1)
				u8_tm_rf_sw_1s=30;
			else if(u8_rf_mode==2)
				u8_tm_rf_sw_1s=15;
			u8_rf_wt[0] = RF_SW_O; 
		}
		else
		{
			u8_rf_mode=0;
			EN33=0;
			u8_rf_wt[0]=RF_SW_C;
		}
	}
}
void CHG_Con()
{
	if(b_CHG_contR==1)
	{
		if(b_chg_flag==0)
		{
			b_chg_flag=1;
			P0CR	&= B11111000;					//NEW 0.6&0.5 CHG Status Port	Low is CHG
			P0PCR	|= B00000111;
			u8_rf_mode=0;
			EN33=0;
			b_dpy_flag=0;
			u8_rf_wt[0]=RF_SW_C;
		}
	}
	if(b_CHG_contR==0)
	{
		if(b_chg_flag==1)
		{
			P0CR	|= B00000111;					//NEW 0.6&0.5 CHG Status Port	Low is CHG
			P0PCR	&= B11111000;
			P0		|= B00000111;

			b_chg_flag=0;
		}
	}
	if(b_CHG_contG==1)
	{
		b_chg_full_flag=1;
	}
	if(b_CHG_contG==0)
	{
		b_chg_full_flag=0;
	}

}
//#define COB1	P2_2	#define COB2	P2_1


void Euart_Wt()
{
	if(u8_rf_wt[0]==RF_SW_O)
	{
		ES=0;
		SBUF	=	u8_rf_wt[u8_rf_mode];
		while(TI==0)
		{
			CLR_WDT();
		}
		TI=0;
		ES=1;
		u8_rf_wt[0]=RF_SW_C;
		b_rf_wt_finish_flag=1;
	}	
	else
		TXD=1;
	if(u8_tm_rf_wt_100ms>200)
	{
		b_rf_wt_lose_flag=1;
		b_rf_wt_finish_flag=0;
		u8_tm_rf_wt_100ms=0;
	}
	if(b_rf_wt_lose_flag==1)
	{
		u8_rf_wt[0]=RF_SW_O;
		b_rf_wt_lose_flag=0;
	}
}
void RX_CMP()
{			
	if(b_rf_rx_finish_flag==1)							//指令全部接收完成，开始区别返回的指令的类型
	{
		for(u8_rf_rx_type_cnt1=0;u8_rf_rx_type_cnt1<30;u8_rf_rx_type_cnt1++)
		{
			for(u8_rf_rx_type_cnt2=11;u8_rf_rx_type_cnt2<14;u8_rf_rx_type_cnt2++)
			{
				if(u8_rf_rx[u8_rf_rx_type_cnt1]==u8_rf_rx_cmp[u8_rf_rx_type_cnt2])
				{
					u8_rf_rx_type=u8_rf_rx_type_cnt2;		//记录象征指令类型的关键字
					u8_rf_rx_type_pos=u8_rf_rx_type_cnt1;	//记录象征指令类型关键的位置
					b_rf_rx_finish_flag=0;
					b_rf_rx_cmp_flag=1;
					return;
				}
				CLR_WDT();
			}
		}
		b_rf_rx_finish_flag=0;
		b_rx_lose_flag=1;								 
	}
	if(b_rf_rx_cmp_flag==1)							//指令类型已经获得，开始读取指令类的数据
	{
		if(u8_rf_rx_type==11) 								//当前返回的指令为打开激光成功反馈
		{
			b_rf_rx_cmp_flag=0;
			u8_dpy_var[0]=C_0;
			u8_dpy_var[1]=C_0;
			u8_dpy_var[2]=C_0;
			u8_dpy_var[3]=C_0;
			b_rx_dpy_ready_flag=1;
			u8_rf_rx_type=0;
		}
		else if(u8_rf_rx_type==12)							//当前返回的指令为所测出的距离
		{	
			u8_rf_rx_dpy_cnt3=0;
			for(u8_rf_rx_dpy_cnt1=(u8_rf_rx_type_pos-6);u8_rf_rx_dpy_cnt1<u8_rf_rx_type_pos;u8_rf_rx_dpy_cnt1++)
			{
				for(u8_rf_rx_dpy_cnt2=0;u8_rf_rx_dpy_cnt2<11;u8_rf_rx_dpy_cnt2++)
				{
					if(u8_rf_rx[u8_rf_rx_dpy_cnt1]==u8_rf_rx_cmp[u8_rf_rx_dpy_cnt2])
					{
						if(u8_rf_rx_dpy_cnt2<10)
						{
							u8_rx_dpy[u8_rf_rx_dpy_cnt3]=u8_rf_rx_dpy_cnt2;
							u8_rf_rx_dpy_cnt3++;
						}
						else
						{
							u8_rx_dpy[(u8_rf_rx_dpy_cnt3-1)]=(u8_rx_dpy[(u8_rf_rx_dpy_cnt3-1)]+20);
						}
						if(u8_rf_rx_dpy_cnt3>3)		//一共只能显示四位，所以大于3直接退出
						{
							b_rf_rx_cmp_flag=0;
							b_rx_dpy_ready_flag=1;	//接收的指令已经读取完毕
							return;
						}
					}
				}
				CLR_WDT();
			}
			b_rx_lose_flag=1;
			b_rf_rx_cmp_flag=0;
		}
		if(u8_rf_rx_type==13)							//当前返回的指令为错误代码
		{
//			u8_rf_rx_dpy_cnt1=(u8_rf_rx_type_pos+2);		//代码值在类型值的后两位
			u8_rx_dpy[0]=C_E;						//类型值已知，可直接填入
			u8_rx_dpy[1]=C_r;						
			u8_rf_rx_dpy_cnt3=2;						//显示值已填入两位
			for(u8_rf_rx_dpy_cnt1=(u8_rf_rx_type_pos+2);u8_rf_rx_dpy_cnt1<(u8_rf_rx_type_pos+4);u8_rf_rx_dpy_cnt1++)
			{
				for(u8_rf_rx_dpy_cnt2=0;u8_rf_rx_dpy_cnt2<10;u8_rf_rx_dpy_cnt2++)
				{
					if(u8_rf_rx[u8_rf_rx_dpy_cnt1]==u8_rf_rx_cmp[u8_rf_rx_dpy_cnt2])
					{
						u8_rx_dpy[u8_rf_rx_dpy_cnt3]=u8_rf_rx_dpy_cnt2;
						u8_rf_rx_dpy_cnt3++;
						if(u8_rf_rx_dpy_cnt3>3)		//一共只能显示四位，所以大于3直接退出
						{
							b_rf_rx_cmp_flag=0;
							b_rx_dpy_ready_flag=1;	//接收的指令已经读取完毕
							return;
						}
					}
				}
			}
			b_rx_lose_flag=1;
			b_rf_rx_cmp_flag=0;
		}
	}	
}
void RF_Clr()
{
	uint8 u8_x;
	for(u8_x=0;u8_x<30;u8_x++)
	{
		u8_rf_rx[u8_x]=0x00;	
	}
}
void RF_Dpy()
{
	uint8	u8_rf_date_ex_cnt;
	if(b_rx_dpy_ready_flag==1)
	{
		if(u8_rf_rx_type==12||u8_rf_rx_type==13)
		{
			for(u8_rf_date_ex_cnt=0;u8_rf_date_ex_cnt<4;u8_rf_date_ex_cnt++)
			{	
					u8_dpy_var[u8_rf_date_ex_cnt]=u8_rx_dpy[u8_rf_date_ex_cnt];
			}
		}	
		u8_rf_rx_type=0;
		RF_Clr();
	}
	else if(b_rx_lose_flag==1)
	{
		u8_dpy_var[0]=C_E;
		u8_dpy_var[1]=C_r;
		u8_dpy_var[2]=C_9;
		u8_dpy_var[3]=C_9;
		b_rx_dpy_ready_flag=1;
		b_rx_lose_flag=0;
		u8_rf_rx_type=0;
		RF_Clr();
	}
	if(b_rf_bat_sw_flag==RF_BAT_CLOSE)
	{
		b_dpy_flag=0;	
		u8_rf_wt[0] = RF_SW_C; 
		EN33=0;
		u8_rf_mode=0;
		b_rf_bat_sw_flag=0;
	}
}

void RF_Con()
{
	Euart_Wt();
	RX_CMP();
	RF_Dpy();	
}
void Dpy_Con()
{
	section0 uint8 u8_x1;
	if(b_chg_flag==0)
	{
		P0|= 0x0F;
		P1 = 0x00;
		if(b_rx_dpy_ready_flag==1||b_dpy_flag==1) 					
		{
			P0&= ((0xF7>>(3-u8_dpy_bit))|0xF0);
			if(u8_dpy_var[u8_dpy_bit]<20)
			{
				u8_x1	=	u8_dpy_var[u8_dpy_bit];
				u8_x1	=	u8_dpy_con[u8_x1];
			}
			else
			{
				u8_x1	=	u8_dpy_var[u8_dpy_bit];
				u8_x1	-=	20;
				u8_x1	=	u8_dpy_con[u8_x1];
				u8_x1	|=	0x80;
			}
			P1	= u8_x1;
	
			u8_dpy_bit++;
			if(u8_dpy_bit>3)
				u8_dpy_bit=0; 
			if(b_rx_dpy_ready_flag==1)
			{
				b_dpy_flag=1;
				b_rx_dpy_ready_flag=0;	
			}
		}
		else
		{
			u8_dpy_bit=0;
			P1 = u8_dpy_con[Close];
			P0&= 0xF0;
		}	
	}
	else
	{
		if(b_chg_full_flag==0)
		{
			if(b_dpy_chg_500ms_flag==1)
			{
				b_dpy_chg_500ms_flag=0;
				COM4=~COM4;
				P1 = u8_dpy_con[C_dp];
			}
		}	
		else
		{
			if(b_dpy_chg_500ms_flag==1)
			{
				b_dpy_chg_500ms_flag=0;
				COM4=0;
				P1 = u8_dpy_con[C_dp];
			}
		}	
	}
}


void SoftWare_Clock()
{
	if(b_tm0_1ms_flag==1)		{u8_tm0_1ms_cnt++;}			
	if(u8_tm0_1ms_cnt>99)	{u8_tm0_1ms_cnt=0;u8_tm0_100ms_cnt++;b_tm0_100ms_flag=1;}
	if(u8_tm0_100ms_cnt>9)	{u8_tm0_100ms_cnt=0;u8_tm0_1s_cnt++;b_tm0_1s_flag=1;}
	if(u8_tm0_1s_cnt>9)		{u8_tm0_1s_cnt=0;b_tm0_10s_flag=1;}


	if(b_tm0_1ms_flag==1)
	{
		b_tm0_1ms_flag=0;
		u8_tm_key1_1ms++;
		u8_tm_key2_1ms++;
		u8_tm_CHGG_1ms++;
		u8_tm_CHGR_1ms++;
		Dpy_Con();

	}
	if(b_tm0_100ms_flag==1)
	{
		b_tm0_100ms_flag=0;
		u8_tm_halt_100ms++;
		if(b_rf_wt_finish_flag==1)
			u8_tm_rf_wt_100ms++;
		else
			u8_tm_rf_wt_100ms=0;

		if(u8_tm_rf_rx_100ms>1)
			u8_tm_rf_rx_100ms--;
		if(u8_tm_rf_rx_100ms==1)
		{
			b_rf_rx_finish_flag=1;
			b_rf_wt_finish_flag=0;
			u8_rf_rx_i=0;
			u8_tm_rf_rx_100ms=0;
		}
		if(b_key_cont2==1&&u8_rf_mode>0)
		{
			u8_tm_rf_sw_100ms++;
			if(u8_tm_rf_sw_100ms>15)
			{
				u8_tm_rf_sw_100ms=0;
				b_rf_bat_sw_flag=RF_BAT_CLOSE;
			}
		}
		else
		{
			u8_tm_rf_sw_100ms=0;
		}
		b_dpy_chg_100ms_flag=1;
		u8_dpy_chg_100ms_cnt++;
		if(u8_dpy_chg_100ms_cnt>4)
		{
			b_dpy_chg_500ms_flag=1;
			u8_dpy_chg_100ms_cnt=0;
		}
	}
	if(b_tm0_1s_flag==1)
	{
		b_tm0_1s_flag=0;
		if(u8_tm_rf_sw_1s>1)
			u8_tm_rf_sw_1s--;
		else
		{
			if(u8_tm_rf_sw_1s==1)
			{
				b_rf_bat_sw_flag=RF_BAT_CLOSE;
				u8_tm_rf_sw_1s=0;
			}
		}
	}
	if(b_tm0_10s_flag)
	{
		b_tm0_10s_flag=0;
	}
}
void main()
{	
	Seg_Set();
//	EN33=1;
	while(1)
	{
		CLR_WDT();
///////////////////////////////////SoftWare Clock////////////////////////////////////////////////////////
	SoftWare_Clock();
/*		 */
	KEY_Con();
	CHG_Con();
	RF_Con();			 
	Low_Power();
///////////////////////////////////SoftWare Clock////////////////////////////////////////////////////////
	}
}
