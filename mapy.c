#include "DSP281x_Device.h"
#include "math.h"
#include "stdlib.h"
//#include "IQmathLib.h"

//double LSobr=2; //liczba suwuw nape³niania na obrót
//double n=6333;//liczba obrotów na minutê
//double AFR=14.7;//stosunek masy powietrza do paliwa
//double m=123.87;
double md[512]={-36.15,-35.60,-35.07,-34.54,-34.01,-33.49,-32.97,-32.46,-31.95,-31.45,-30.95,-30.46,-29.97,-29.48,-29.01,-28.53,-28.06,-27.60,-27.14,-26.68,-26.23,-25.79,-25.35,-24.91,-24.48,-24.05,-23.63,-23.21,-22.80,-22.39,-21.98,-21.58,-21.18,-20.79,-20.40,-20.02,-19.64,-19.26,-18.89,-18.52,-18.16,-17.80,-17.44,-17.09,-16.74,-16.40,-16.06,-15.72,-15.38,-15.05,-14.72,-14.40,-14.08,-13.76,-13.45,-13.13,-12.82,-12.52,-12.21,-11.91,-11.61,-11.32,-11.02,-10.73,-10.44,-10.15,-9.87,-9.58,-9.30,-9.02,-8.74,-8.46,-8.18,-7.91,-7.63,-7.36,-7.08,-6.81,-6.54,-6.26,-5.99,-5.72,-5.44,-5.17,-4.89,-4.62,-4.34,-4.06,-3.78,-3.50,-3.21,-2.93,-2.64,-2.35,-2.05,-1.76,-1.46,-1.15,-0.85,-0.53,-0.40,-0.20,0.00,0.40,0.71,1.01,1.31,1.61,1.90,2.19,2.47,2.75,3.04,3.31,3.59,3.87,4.14,4.41,4.68,4.95,5.22,5.49,5.76,6.02,6.29,6.56,6.82,7.09,7.36,7.63,7.90,8.17,8.44,8.71,8.98,9.25,9.53,9.81,10.09,10.37,10.65,10.93,11.22,11.51,11.80,12.09,12.39,12.69,12.99,13.29,13.60,13.91,14.22,14.53,14.85,15.17,15.50,15.83,16.16,16.49,16.83,17.17,17.52,17.86,18.22,18.57,18.93,19.30,19.66,20.03,20.41,20.79,21.17,21.56,21.95,22.34,22.74,23.15,23.56,23.97,24.38,24.81,25.23,25.66,26.09,26.53,26.97,27.42,27.87,28.33,28.79,29.26,29.72,30.20,30.68,31.16,31.65,32.14,32.64,33.14,33.65,34.16,34.68,35.20,35.72,36.25,36.79,37.33,37.87,38.42,38.98,39.54,40.10,40.67,41.25,41.83,42.41,43.00,43.59,44.19,44.80,45.41,46.02,46.64,47.26,47.89,48.53,49.17,49.81,50.46,51.12,51.78,52.44,53.11,53.79,54.47,55.16,55.85,56.55,57.25,57.96,58.68,59.40,60.12,60.85,61.59,62.33,63.08,63.83,64.59,65.35,66.13,66.90,67.68,68.47,69.27,70.07,70.87,71.69,72.50,73.33,74.16,75.00,75.84,76.69,77.55,78.41,79.28,80.16,81.04,81.93,82.82,83.73,84.64,85.55,86.48,87.41,88.35,89.29,90.24,91.20,92.17,93.14,94.13,95.12,96.11,97.12,98.13,99.15,100.18,101.22,102.26,103.32,104.38,105.45,106.53,107.61,108.71,109.82,110.93,112.05,113.18,114.32,115.47,116.63,117.80,118.98,120.17,121.37,122.57,123.79,125.02,126.26,127.50,128.76,130.03,131.31,132.60,133.90,135.21,136.54,137.87,139.22,140.57,141.94,143.32,144.71,146.12,147.53,148.96,150.40,151.85,153.32,154.80,156.29,157.79,159.31,160.84,162.38,163.94,165.51,167.09,168.69,170.30,171.93,173.57,175.23,176.90,178.58,180.28,181.99,183.72,185.47,187.23,189.00,190.80,192.60,194.43,196.27,198.12,199.99,201.88,203.79,205.71,207.65,209.61,211.58,213.58,215.59,217.61,219.66,221.72,223.81,225.91,228.03,230.16,232.32,234.50,236.69,238.91,241.14,243.39,245.67,247.96,250.28,252.61,254.96,257.34,259.74,262.15,264.59,267.05,269.53,272.03,274.55,277.10,279.67,282.26,284.87,287.50,290.16,292.84,295.54,298.26,301.01,303.78,306.58,309.40,312.24,315.10,317.99,320.91,323.84,326.81,329.79,332.80,335.84,338.90,341.98,345.09,348.23,351.39,354.58,357.79,361.03,364.29,367.58,370.89,374.23,377.60,380.99,384.41,387.86,391.33,394.83,398.36,401.91,405.49,409.10,412.73,416.39,420.08,423.80,427.54,431.31,435.11,438.94,442.79,446.67,450.58,454.52,458.48,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00,460.00
}; //masowy przep³yw powietrza w zale¿noœci od wskazañ ADC przep³ywomierza (ustawiony na 9 bit);
//double Q_wtr=671; //wydajnoœæ wtryskiwacza
double tz=0.5; //czas zw³oki otwarcia wtryskiwacza
//double t_wtr=0; //czas wtrysku
//double sprawdzam,A,B,R,D,Z,G,P;
//unsigned int przedwtrysk[255]={15808,15808,15808,15808,15808,15808,15808,13807,12172,11478,10859,10308,9820,9389,9009,8675,8381,8229,8086,7953,7828,7709,7596,7488,7406,7329,7256,7186,7119,7053,6988,6925,6770,6716,6660,6604,6545,6486,6425,6362,6297,6230,6160,6089,6015,5938,5859,5807,5754,5699,5644,5587,5528,5469,5407,5345,5281,5215,5148,5080,5009,4938,4864,4789,4712,4633,4552,4470,4385,4317,4249,4179,4107,4035,3961,3886,3809,3731,3652,3572,3490,3407,3322,3236,3148,3060,2969,2877,2784,2689,2592,2494,2395,2293,2190,2086,1980,1872,1763,1652,1539,1424,1308,1190,1070,948,825,700,572,443,313,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//}; //wartoœæ przedwtrysku (czasu otwarcia wtryskiwaczaw jednostkach [10us]) dawki paliwa w zale¿noœci od temperatury cieczy ch³odz¹cej, temperatura w jednostkach wskazañ ADC
unsigned int pierwszy_wtrysk[255]={3645,3645,3645,3645,3645,3645,3645,4068,4541,4798,5070,5356,5659,5979,6317,6674,7052,7277,7509,7749,7996,8252,8515,8787,9004,9218,9429,9637,9843,10048,10251,10453,10949,11122,11299,11478,11659,11844,12032,12222,12416,12612,12812,13015,13221,13431,13643,13780,13919,14059,14200,14343,14487,14633,14780,14928,15078,15230,15383,15537,15694,15851,16011,16172,16334,16498,16664,16832,17001,17135,17270,17406,17543,17682,17821,17962,18104,18246,18390,18535,18682,18829,18977,19127,19278,19430,19583,19738,19894,20050,20209,20368,20529,20691,20854,21018,21184,21351,21520,21689,21861,22033,22207,22382,22558,22736,22916,23097,23279,23462,23647,23834,24022,24211,24402,24595,24789,24984,25182,25380,25580,25782,25986,26190,26397,26574,26751,26930,27110,27292,27474,27658,27843,28029,28217,28406,28596,28787,28979,29173,29368,29565,29763,29962,30162,30364,30567,30771,30977,31184,31393,31603,31814,32027,32241,32457,32674,32893,33127,33363,33601,33840,34081,34324,34568,34814,35062,35312,35563,35817,36072,36329,36587,36848,37110,37375,37641,37909,38179,38451,38725,39001,39278,39558,39840,40124,40409,40697,40987,41335,41686,42041,42398,42758,43122,43488,43857,44230,44606,44985,45367,45753,46142,46534,46929,47328,47730,48136,48545,48957,49373,49793,50216,50643,51073,51348,51624,51902,52181,52462,52744,53028,53313,53600,53888,54178,54470,54763,55057,55354,55651,55951,56252,56554,56859,57165,57472,57781,58092,58405,58719,59035,59353,59672,59993,60316,60640,60967,61295,61624,61956,62289,62624,62961,63300
};
//wartoœæ pierwszego wtrysku rozruchowego (czasu otwarcia wtryskiwacza w jednostkach [10us]) w zale¿noœci od temperatury cieczy ch³odz¹cej , temperatura w jednostkach wskazañ ADC

//ADC ustawienie wstêpne sequencer 1 co 1ms, sequencer 2 co 1 sekundê, trzeba ogarn¹æ czas s&h
int Napiece_adcA0; //potencjometr na p³ytce na sequencerze 1 // ADCA0=ADC0
int Napiecie_adcB5_TPS_A; // czujnik po³o¿enia przepustnicy char. A, na sequencerze 1// ADCB5=ADC13
int Napiecie_adcB7_TPS_B; // czujnik po³o¿enia przepustnicy char. B na sequencerze 1// ADCB7=ADC15
int Napiecie_adcB0_MAF; // czujnik przep³ywu powietrza na sequencerze 1 // ADCB0=ADC8
int Napiecie_adcB3_tW; // czujnik temperatury wody na sequencerze 2 // ADCB3=ADC11
int Napiecie_adcB1_tP; // czujnik temperatury powietrza na sequencerze 2 // ADCB1=ADC9

int impulsy=0;
//int forward=0;
//int backward=0;
//long Voltage_A0=1;
//long Voltage_B0=4;
Uint32 czas=0;
unsigned long licznik_impulsow=0;
unsigned long wartosc_rejestru_licznika_starsza=0;
unsigned long wartosc_rejestru_licznika_mlodsza=0;
Uint32 zapis_wartosci_CpuTimer0=0;
//double wcis=0;
Uint32 delta=0;
Uint32 predkosc_ob;
Uint32 licznik_wtryskiwacza=0;

double AFRustalony=15; //stan ustalony
double AFR1cieply=13;
double AFR2cieply=14;
double AFR3cieply=14.7;
double AFR4cieply=15;
double AFR5cieply=15.4;

double AFR1zimny=3;
double AFR2zimny=4;
double AFR3zimny=4;
double AFR4zimny=5;
double AFR5zimny=5;
double AFR6zimny=6;
double AFR61zimny=6.2;
double AFR7zimny=6.5;
double AFR8zimny=6.5;
double AFR9zimny=7.3;
double AFR10zimny=7.6;
double AFR11zimny=8.0;
double AFR12zimny=8.2;
double AFR13zimny=9.3;
double AFR14zimny=9.9;
double AFR15zimny=10.4;



// Prototype statements for functions found within this file.
void pompa_paliwa(void);
void obliczenie_dawki(double AFR);
void ustalony(void);
void rozruch(void);
void obliczenie_czasu_wtrysku(void);
interrupt void licznik_isr(void);
void predkosc_obrotowa(void);
void proznia(void);
int serwo_ustaw(int kat);
void serwo_algorytm(int temp_ch, int kat);
void GPIOoff(void);
interrupt void adc_isr(void);
interrupt void cpu_timer0_isr(void);
void InitSystem(void);
void Gpio_select(void);
void InitAdc(void);
void InitPieCtrl(void);
void InitPieVectTable(void);
void wylacz_wtryskiwacz(void);
void MAFsredni(void);
void Vsredni(void);
void dotrysk(void);


long int MAF_sredni=0;// wartosc usredniona maf z 10 impulsów wa³u korbowego

long int bufor=0;
long int licznik=0;

long int V_sredni=0;
long int bufor_v=0;
long int licznik_v=0;
long int predkoscTPS=0;

int licznik_usredniania=3;
int modulo_usredniania=4;

int katA=160;
void main(void)
{

	//unsigned int i=0;
	//unsigned int twtr[46]= {0,1304,1507,1744,1913,2150,2319,2488,2725,2827,2962,3064,3165,3300,3436,3537,3639,3707,3740,3808,3842,3876,3910,3930,3952,3973,3995,4017,4040,4063,4086,4109,4133,4158,4182,4207,4233,4259,4285,4312,4339,4366,4395,4423,4452,4482};
	//unsigned int ADC[1000];
	InitSystem();		// Initialize the DSP's core Registers

	// Speed_up the silicon A Revision.
	// No need to call this function for Rev. C  later silicon versions
	//SpeedUpRevA();

	Gpio_select();		// Setup the GPIO Multiplex Registers
	GPIOoff();
	InitPieCtrl();		// Function Call to init PIE-unit ( code : DSP281x_PieCtrl.c)

	InitPieVectTable(); // Function call to init PIE vector table ( code : DSP281x_PieVect.c )

	InitAdc();

	// re-map PIE - entry for Timer 0 Interrupt
	EALLOW;  // This is needed to write to EALLOW protected registers
   	PieVectTable.TINT0 = &cpu_timer0_isr;
   	PieVectTable.ADCINT=&adc_isr;
   	PieVectTable.CAPINT1=&licznik_isr;
   	//PieVectTable.CAPINT1=&enkoder_isr;

   	//IER=1;
   	EDIS;    // This is needed to disable write to EALLOW protected registers

	InitCpuTimers();

	// Configure CPU-Timer 0 to interrupt every 10 us:
	// 150MHz CPU Freq, 1 µseconds interrupt period
    ConfigCpuTimer(&CpuTimer0, 150, 10);

    // Enable TINT0 in the PIE: Group 1 interrupt 7
   	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

   	// Enable ADC interrupt: PIE-Group1 , interrupt 6
   	PieCtrlRegs.PIEIER1.bit.INTx6 = 1;

   	//W³¹czenie przerwania od CAP1INT: Pie Grupa 3, przerwanie 5
   	PieCtrlRegs.PIEIER3.bit.INTx5 = 1;

	// Enable CPU INT1 which is connected to CPU-Timer 0 oraz ADC:
    IER = 1;
    //W³¹czenie CPU INT3 które jest powi¹zane z przerwaniem od CAP1INT
    IER |=4;


	// Enable global Interrupts and higher priority real-time debug events:
   	EINT;   // Enable Global interrupt INTM
   	ERTM;   // Enable Global realtime interrupt DBGM

   	CpuTimer0Regs.TCR.bit.TSS = 0;

   	//Configuring ADC
   	AdcRegs.ADCTRL1.bit.SEQ_CASC=0; //dual-mode
   	AdcRegs.ADCTRL1.bit.CONT_RUN=0; //no continuous run
   	AdcRegs.ADCTRL1.bit.CPS=15;//prescaler =CLK/2 //15 = CLK/16
    AdcRegs.ADCTRL1.bit.ACQ_PS=15;
   	AdcRegs.ADCMAXCONV.bit.MAX_CONV2=0x0006; //ustawienie ilosci konwersji
   	AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 0x0; // Setup ADCINA0 as 1st SEQ1 conv.// Assumes EVA Clock is already enabled in InitSysCtrl();
   	AdcRegs.ADCCHSELSEQ3.bit.CONV09 = 0xD; // Setup ADCINB5 as 2nd SEQ1 conv.// Drive T1PWM / T2PWM by T1/T2 - logic
   	AdcRegs.ADCCHSELSEQ3.bit.CONV10 = 0xF; // Setup ADCINB7 as 3rd SEQ1 conv.
   	AdcRegs.ADCCHSELSEQ3.bit.CONV11 = 0x8; // Setup ADCINB0 as 4th SEQ1 conv.
   	AdcRegs.ADCCHSELSEQ4.bit.CONV12 = 0x9; // Setup ADCINB1 as 5th SEQ1 conv.
   	AdcRegs.ADCCHSELSEQ4.bit.CONV13 = 0xB; // Setup ADCINB3 as 6th SEQ1 conv.
   	AdcRegs.ADCTRL2.bit.EVB_SOC_SEQ2=1; // Enable EVASOC to start SEQ1// Polarity of GP Timer 1 Compare = Active low
   	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 1;  // Enable SEQ1 interrupt (every EOEvaRegs.GPTCONA.bit.T1PIN = 1;
   	AdcRegs.ADCTRL3.bit.ADCCLKPS=15;	   // Divide HSPCLK by 4


   	// Configure EVA
   	    // Assumes EVA Clock is already enabled in InitSysCtrl();
   	    // Disable T1PWM / T2PWM outputs
   	    EvbRegs.GPTCONB.bit.TCMPOE = 0;
   	   	// Polarity of GP Timer 1 Compare = forced low
   		EvbRegs.GPTCONB.bit.T3PIN = 0;
   		EvbRegs.GPTCONB.bit.T3TOADC = 10;       // Enable EVASOC in EVA /'10' setting of period interrupt flag


   		EvbRegs.T3CON.bit.FREE = 0;				// Stop on emulation suspend
   	    EvbRegs.T3CON.bit.SOFT = 0;				// Stop on emulation suspend
   	    EvbRegs.T3CON.bit.TMODE = 2;			// Continuous up count mode
   	    EvbRegs.T3CON.bit.TENABLE = 1;			// enable GP Timer 1
   	   	EvbRegs.T3CON.bit.TCLKS10 = 0;			// internal clock
   	   	EvbRegs.T3CON.bit.TCLD10 = 0;			// Compare Reload when zero
   	   	EvbRegs.T3CON.bit.TECMPR = 0;			// Disable Compare operation



   	   	EvbRegs.T3CON.bit.TPS = 7;				// prescaler = 128
   	   	EvbRegs.T3PR = 700;					//1 ms dla ADC

   	 // Poni¿ej inicjalizacja PWM1:
   	   			EvaRegs.ACTRA.bit.CMP1ACT=1; //forced low
   	    	    EvaRegs.ACTRA.bit.SVRDIR=0;
   	    	    EvaRegs.ACTRA.bit.D=0;

   	    		EvaRegs.DBTCONA.bit.EDBT1=0;
   	    		EvaRegs.DBTCONA.bit.EDBT2=0;
   	    		EvaRegs.DBTCONA.bit.EDBT3=0;

   	   			EvaRegs.CMPR1=0;

   	   			EvaRegs.COMCONA.bit.CENABLE=1; //w³¹czenie porównywania
   	    		EvaRegs.COMCONA.bit.CLD=0; //prze³adowanie CMPRx gdy T1CNT==0
   	    		EvaRegs.COMCONA.bit.SVENABLE=0; //wy³¹czenie obs³ugi sterowania wektorowego
   	    		EvaRegs.COMCONA.bit.FCOMPOE=1; //zalaczenie wyjsc
   	   			//EvaRegs.GPTCONA.bit.T1PIN = 1; //dotyczy pinu T1PWM nie PWM1
   	    		//EvaRegs.GPTCONA.bit.T1TOADC = 0;       // Disable EVASOC in EVA /'00' ADC interrupt flag set disabled


   	    		EvaRegs.T1CON.bit.FREE = 0;				// Stop on emulation suspend
   	    	    EvaRegs.T1CON.bit.SOFT = 0;				// Stop on emulation suspend
   	    	    EvaRegs.T1CON.bit.TMODE = 2;			// Continuous up count mode
   	    	    EvaRegs.T1CON.bit.TENABLE = 1;			// enable GP Timer 2
   	    	   	EvaRegs.T1CON.bit.TCLKS10 = 0;			// internal clock
   	    	   	EvaRegs.T1CON.bit.TCLD10 = 0;			// Compare Reload when zero
   	    	   	EvaRegs.T1CON.bit.TECMPR = 1;			// Enable Compare operation


   	    	   	EvaRegs.T1CON.bit.TPS = 7;				// preskaler = 2
   	    	   	EvaRegs.T1PR = 65535;					//pelny zakres dla wtryskiwacza


   	// Konfiguracja ECAP1 - czêœæ EVA

   	   	EvaRegs.CAPCONA.bit.CAPRES=0; //reset modu³u
   	   	EvaRegs.CAPCONA.bit.CAP12EN=0x0001; //w³¹czenie cap1 i cap2 (01enable for capture)
   	   	EvaRegs.CAPCONA.bit.CAP3EN=0x0000;
   	   	EvaRegs.CAPCONA.bit.CAP3TSEL=1; //u¿yj GP Timer 1
   	   	EvaRegs.CAPCONA.bit.CAP12TSEL=1; //u¿yj GP Timer 1, bo jest w³¹czony do wywo³ywania ADC
   	   	EvaRegs.CAPCONA.bit.CAP3TOADC=0; //wy³¹czenie wywo³ywania startu ADC przez CAP3
   	   	EvaRegs.CAPCONA.bit.CAP2EDGE=0;
   	   	EvaRegs.CAPCONA.bit.CAP1EDGE=2; //CAP1 ustawiony na reakcjê na zbocze opadaj¹ce
   	   	EvaRegs.CAPCONA.bit.CAP3EDGE=0;
   	   	EvaRegs.EVAIMRC.bit.CAP1INT=1; //CAP1 wlaczenie przerwania

   	   	EvbRegs.CAPCONB.bit.CAPRES=0;
   	   	EvbRegs.CAPCONB.bit.CAP45EN=0x0001;
   	   	EvbRegs.CAPCONB.bit.CAP6EN=0x0000;
   	    EvbRegs.CAPCONB.bit.CAP6TSEL=0; //u¿yj GP Timer 4
   	    EvbRegs.CAPCONB.bit.CAP45TSEL=1; //u¿yj GP Timer 3, bo jest w³¹czony do wywo³ywania ADC
   	    EvbRegs.CAPCONB.bit.CAP6TOADC=0; //wy³¹czenie wywo³ywania startu ADC przez CAP3
   	    EvbRegs.CAPCONB.bit.CAP5EDGE=0;
   	    EvbRegs.CAPCONB.bit.CAP4EDGE=2; //CAP1 ustawiony na reakcjê na zbocze opadaj¹ce
   	    EvbRegs.CAPCONB.bit.CAP6EDGE=0;
   	    //EvbRegs.EVBIMRC.bit.CAP4INT=0; //CAP1 wlaczenie przerwania

   	    EvaRegs.T1CNT=0;
   	    EvbRegs.T3CNT=0;
   	    //GpioDataRegs.GPADAT.bit.GPIOA14=1;
   	 	serwo_ustaw(0);
   	 	serwo_ustaw(160);
   		serwo_ustaw(110);


while(1){
	wylacz_wtryskiwacz();
}
}

void wylacz_wtryskiwacz(void){
	if((EvaRegs.T1CNT>=czas)&&(GpioDataRegs.GPADAT.bit.GPIOA0==1)){ //czas_otwarcia wtryskiwacza
		GpioDataRegs.GPADAT.bit.GPIOA0=0;
		licznik_wtryskiwacza++;
		/*EvaRegs.T1CON.bit.TENABLE=0;
		EvaRegs.ACTRA.bit.CMP1ACT=0; //forced low*/
	}
}

void Gpio_select(void)
{
	EALLOW;
	GpioMuxRegs.GPAMUX.all = 0x0;	// all GPIO port Pin's to I/O
	GpioMuxRegs.GPAMUX.bit.CAP1Q1_GPIOA8|=1; //czujnik prêdkosci obrotowej jako CAP1_QEP1
	//GpioMuxRegs.GPAMUX.bit.PWM1_GPIOA0|=1; //wyjscie wtryskiwacza PWM


    GpioMuxRegs.GPBMUX.all = 0x0;
    //GpioMuxRegs.GPBMUX.bit.CAP4Q1_GPIOB8|=1;

    GpioMuxRegs.GPDMUX.all = 0x0;
    GpioMuxRegs.GPFMUX.all = 0x0;
    GpioMuxRegs.GPEMUX.all = 0x0;
    GpioMuxRegs.GPGMUX.all = 0x0;

    GpioMuxRegs.GPADIR.bit.GPIOA0=1; //wyjœcie steruj¹ce wtryskiwaczem paliwa
    GpioMuxRegs.GPADIR.bit.GPIOA1=0; //pusty jako wejscie
    GpioMuxRegs.GPADIR.bit.GPIOA2=0; //pusty jako wejscie
    GpioMuxRegs.GPADIR.bit.GPIOA3=0; //pusty jako wejscie
    GpioMuxRegs.GPADIR.bit.GPIOA4=0; //pusty jako wejscie
    GpioMuxRegs.GPADIR.bit.GPIOA5=0; //pusty jako wejscie
    GpioMuxRegs.GPADIR.bit.GPIOA6=1; //wyjœcie steruj¹ce obrotami silnika przepustnicy //zamieniæ z a0
    GpioMuxRegs.GPADIR.bit.GPIOA7=1; //wyjœcie steruj¹ce obrotami silnika przepustnicy
    //GpioMuxRegs.GPADIR.bit.GPIOA8=0; //wejœcie cyfrowe magnetoindukcyjnego czujnika prêdkoœci obrotowej
    GpioMuxRegs.GPADIR.bit.GPIOA9=1; //wyjœcie w³¹czaj¹ce mo¿liwoœæ sterowania obrotami silnika przepustnicy
    GpioMuxRegs.GPADIR.bit.GPIOA10=0; //wejœcie cyfrowe czujnika zamkniêcia przepustnicy
    GpioMuxRegs.GPADIR.bit.GPIOA11=1; //wyjœcie steruj¹ce przekaŸnikiem pompy paliwa
    GpioMuxRegs.GPADIR.bit.GPIOA12=0; //pusty jako wejscie
    GpioMuxRegs.GPADIR.bit.GPIOA13=0; //wejœcie cyfrowe w³¹cznika stacyjki
    GpioMuxRegs.GPADIR.bit.GPIOA14=1; //wyjœcie steruj¹ce zaworem podciœnienia
    GpioMuxRegs.GPADIR.bit.GPIOA15=0; //pusty jako wejscie

    //GpioMuxRegs.GPADIR.all = 0x00FF;	// GPIO Port a15-a8 input , a7-a0 output
    GpioMuxRegs.GPBDIR.all = 0x0;	// GPIO PORT as input
    GpioMuxRegs.GPDDIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPEDIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPFDIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPGDIR.all = 0x0;	// GPIO PORT  as input

    GpioMuxRegs.GPAQUAL.all = 0xFF;	// Set GPIO input qualifier values to zero // input qualifier x00 brak x01 sysclkout/2 x02 s/4 ... xFFF sys/510
    GpioMuxRegs.GPBQUAL.all = 0xFF;
    GpioMuxRegs.GPDQUAL.all = 0x0;
    GpioMuxRegs.GPEQUAL.all = 0x0;
    EDIS;
}

void InitSystem(void)
{
   	EALLOW;
   	SysCtrlRegs.WDCR= 0x00E8;		// Setup the watchdog
   									// 0x00E8  to disable the Watchdog , Prescaler = 1
   									// 0x00AF  to NOT disable the Watchdog, Prescaler = 64
   	SysCtrlRegs.SCSR = 0; 			// Watchdog generates a RESET
   	SysCtrlRegs.PLLCR.bit.DIV = 10;	// Setup the Clock PLL to multiply by 5

   	SysCtrlRegs.HISPCP.all = 0x1; // Setup Highspeed Clock Prescaler to divide by 2
   	SysCtrlRegs.LOSPCP.all = 0x2; // Setup Lowspeed CLock Prescaler to divide by 4

   	// Peripheral clock enables set for the selected peripherals.
   	SysCtrlRegs.PCLKCR.bit.EVAENCLK=1;
   	SysCtrlRegs.PCLKCR.bit.EVBENCLK=1;
   	SysCtrlRegs.PCLKCR.bit.SCIAENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.SCIBENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.MCBSPENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.SPIENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.ECANENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.ADCENCLK=1;
   	EDIS;
}

interrupt void cpu_timer0_isr(void)
{
	wylacz_wtryskiwacz();

	CpuTimer0.InterruptCount++;

	if(CpuTimer0.InterruptCount%4==0){
		wylacz_wtryskiwacz();
		rozruch();
		wylacz_wtryskiwacz();
    }
    if(CpuTimer0.InterruptCount%4==1){
    	wylacz_wtryskiwacz();
    	//ustalony();
    	wylacz_wtryskiwacz();
    	Vsredni();
    }

    if(CpuTimer0.InterruptCount%4==2){
    	wylacz_wtryskiwacz();
    	serwo_algorytm(Napiecie_adcB3_tW, Napiecie_adcB5_TPS_A); //algorytm serwa wykorzystuje napiêcie z ADC - temperature cieczy chlodzacej oraz polozenie przepustnicy z kanalu A

    	MAFsredni();
    	wylacz_wtryskiwacz();
    }

    if(CpuTimer0.InterruptCount%4==3){
    	wylacz_wtryskiwacz();
    	predkosc_obrotowa();

    	proznia();
    	pompa_paliwa();
    	wylacz_wtryskiwacz();

    }

   	// Serve the watchdog every Timer 0 interrupt
   //	EALLOW;
	//SysCtrlRegs.WDKEY = 0x55;		// Serve watchdog #1
	//EDIS;

   // Acknowledge this interrupt to receive more interrupts from group 1
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
  //  DINT;
  //  	    PieCtrlRegs.PIEIER1.all = TempPIEIER;
}

interrupt void adc_isr(void)
{//odczyt zmiennych z ADC i zapis


	Napiece_adcA0=AdcRegs.ADCRESULT8>>4; //potencjometr na p³ytce
	Napiece_adcA0=Napiece_adcA0/16;

	Napiecie_adcB5_TPS_A=AdcRegs.ADCRESULT9>>4; //potencjometr przepustnicy A
	Napiecie_adcB5_TPS_A=Napiecie_adcB5_TPS_A/16;

	Napiecie_adcB7_TPS_B=AdcRegs.ADCRESULT10>>4; //potencjometr przepustnicy B
	Napiecie_adcB7_TPS_B=Napiecie_adcB7_TPS_B/16;

	Napiecie_adcB0_MAF=AdcRegs.ADCRESULT11>>4; //przep³ywomierz powietrza
	Napiecie_adcB0_MAF=Napiecie_adcB0_MAF/8;

	Napiecie_adcB1_tP=AdcRegs.ADCRESULT12>>4; //tempertatura powietrza
	Napiecie_adcB1_tP=Napiecie_adcB1_tP/16;

	Napiecie_adcB3_tW=AdcRegs.ADCRESULT13>>4; //temperatura wody
	Napiecie_adcB3_tW=Napiecie_adcB3_tW/16;
	//Voltage_B1=((108*Voltage_B0)/12285);

	wylacz_wtryskiwacz();

	AdcRegs.ADCTRL2.bit.RST_SEQ2=1; //reset ADC sequencer1 (Register ADCCTRL2)
	AdcRegs.ADCST.bit.INT_SEQ2_CLR = 1; //Clear Interrupt Flag ADC Sequencer 1 (Register ADCST)


	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; //Acknowledge PIE Interrupt
	 //DINT;
	//PieCtrlRegs.PIEIER1.all = TempPIEIER;
}

void GPIOoff(void){
	GpioDataRegs.GPADAT.all=0;
}

void serwo_algorytm(int temp_ch, int kat){

	if((kat<60)) kat=60;
	//if(GpioDataRegs.GPADAT.bit.GPIOA10==0){ //ruszamy serwem przepustnicy tylko wtedy gdy kierowca nie dotyka pedalu przyspieszenia
	if((temp_ch>=214)) kat=150; //214 ADC -> -20 stopni celsjusza; ADC -> k¹t 17*
	if((temp_ch>=188)&&(temp_ch<214)) kat=150; //188 ADC -> -10 stopni celsjusza; ADC -> 170 k¹t 16*
	if((temp_ch>=157)&&(temp_ch<188)) kat=140; // 157 ADC -> -0 stopni celsjusza; ADC -> 159 k¹t 15*
	if((temp_ch>=124)&&(temp_ch<157)) kat=130; // 124 ADC -> 10 stopni celsjusza; ADC -> 138 k¹t 13*
	if((temp_ch>=110)&&(temp_ch<124)) kat=130; //110 ADC -> 15 stopni celsjusza; ADC -> 106 k¹t 10*
	if((temp_ch>=90)&&(temp_ch<110)) kat=130; //90 ADC ->  22 stopnie celsjusza; ADC -> 85 k¹t 8*
	if((temp_ch>=46)&&(temp_ch<90)) kat=120; //46 ADC ->  40 stopni celsjusza; ADC -> 64 k¹t 6*
	if(temp_ch<46) kat=100; //46 ADC -> 160 stopni celsjusza; ADC -> 53 k¹t 5*
	serwo_ustaw(kat);
}

int serwo_ustaw(int kat){
	 	 //0-255 (zgodnie z voltage B0)
		if(GpioDataRegs.GPADAT.bit.GPIOA10==1){
					//GpioDataRegs.GPADAT.bit.GPIOA9=1;//
					//GpioDataRegs.GPADAT.bit.GPIOA6=0;//hamowanie silnikowe (fast motor stop) in1=in2, ena=1
					//GpioDataRegs.GPADAT.bit.GPIOA7=0;//
					GpioDataRegs.GPADAT.bit.GPIOA9=0;//wylaczenie silnika (free running motor stop)in1=x in2=x ena=0
		return 0;
		}
		if((Napiecie_adcB5_TPS_A>(kat-6))&&(Napiecie_adcB5_TPS_A<(kat+6))){
					//GpioDataRegs.GPADAT.bit.GPIOA9=1;//
					//GpioDataRegs.GPADAT.bit.GPIOA6=0;//hamowanie silnikowe (fast motor stop) in1=in2, ena=1
					//GpioDataRegs.GPADAT.bit.GPIOA7=0;//
					GpioDataRegs.GPADAT.bit.GPIOA9=0;//wylaczenie silnika (free running motor stop)in1=x in2=x ena=0
				}
		else{
							if((Napiecie_adcB5_TPS_A<(kat+6))){
								GpioDataRegs.GPADAT.bit.GPIOA9 = 1;
								GpioDataRegs.GPADAT.bit.GPIOA6 = 0; //wysuw
								GpioDataRegs.GPADAT.bit.GPIOA7 = 1;
							}
							if((Napiecie_adcB5_TPS_A>(kat-6))){
								GpioDataRegs.GPADAT.bit.GPIOA9 = 1;
								GpioDataRegs.GPADAT.bit.GPIOA6 = 1; //wsuw
								GpioDataRegs.GPADAT.bit.GPIOA7 = 0;
							}
			}
return 0;
}

void proznia(void){
	if((GpioDataRegs.GPADAT.bit.GPIOA10==0)||((Uint32)predkosc_ob<1400)){ //bylo: if(((Uint32)predkosc_ob<1000)&&(GpioDataRegs.GPADAT.bit.GPIOA10==0))
		GpioDataRegs.GPADAT.bit.GPIOA14=1;
	}
	if((GpioDataRegs.GPADAT.bit.GPIOA10==1)&&((Uint32)predkosc_ob>=1900)){ //bylo: if(((Uint32)predkosc_ob<1000)&&(GpioDataRegs.GPADAT.bit.GPIOA10==0))
			GpioDataRegs.GPADAT.bit.GPIOA14=0;
		}
}
void pompa_paliwa(void){
	if(GpioDataRegs.GPADAT.bit.GPIOA13==0){
			GpioDataRegs.GPADAT.bit.GPIOA11=1;
		}
	if(GpioDataRegs.GPADAT.bit.GPIOA13==1) GpioDataRegs.GPADAT.bit.GPIOA11=0;
}


void predkosc_obrotowa(void){ //liczymy co æwieræ obrotu wa³u rozrz¹du czyli co pó³ obrotu wa³u korbowego
	if(wartosc_rejestru_licznika_starsza<wartosc_rejestru_licznika_mlodsza)	{
		delta=(wartosc_rejestru_licznika_mlodsza-wartosc_rejestru_licznika_starsza);
		delta=delta*40;
		predkosc_ob=120000000/delta; //przerwanie Timer0 co 10 mikrosekund, st¹d delta*10 to ilosc mikrosekund
		//predkosc_ob=(1.0)/predkosc_ob;
	}
}

interrupt void licznik_isr(void){
	wylacz_wtryskiwacz();

	licznik_impulsow++; //pierwsze przerwanie pojawi siê dopiero po zape³nieniu pierwszego bufora FIFO

	if((licznik_impulsow%2==0)){ //licznik parzysty - podstawiamy starsz¹ wartosc rejestru
				wartosc_rejestru_licznika_starsza=CpuTimer0.InterruptCount;
		}

	if(licznik_impulsow%2==1){ //licznik nieparzysty - podstawiamy m³odsz¹ wartosc rejestru
				wartosc_rejestru_licznika_mlodsza=CpuTimer0.InterruptCount;
		}

	//if(EvaRegs.CAPFIFOA.bit.CAP1FIFO==2||EvaRegs.CAPFIFOA.bit.CAP1FIFO==3){ //odczyt najstarszej wartoœci tylko gdy zape³nione bufory
	//if(EvbRegs.CAPFIFOB.bit.CAP4FIFO==3||EvbRegs.CAPFIFOB.bit.CAP4FIFO==3){
	//wartosc_rejestru_licznika_starsza=EvbRegs.CAP4FIFO;
	//wartosc_rejestru_licznika_mlodsza=EvbRegs.CAP4FIFO;
	//}


	//wartosc_rejestru_licznika_mlodsza=EvaRegs.CAP1FBOT;
	//zapisanie wartoœci modulo z obecnej
	//licznika CPUtimer0;

	GpioDataRegs.GPADAT.bit.GPIOA0=1; //wlaczenie wtryskiwacza
	/*EvaRegs.T1CON.bit.TENABLE=0;
	//EvaRegs.T1CNT=0;
	EvaRegs.CMPR1=czas;
	EvaRegs.ACTRA.bit.CMP1ACT=1; //active low
	EvaRegs.T1CON.bit.TENABLE=1;*/
	EvaRegs.T1CNT=0;
	EvaRegs.EVAIFRC.bit.CAP1INT=1; //reset flagi przerwania
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3; //Acknowledge PIE Interrupt
}

void ustalony(void){ //obliczenie czasu wtrysku dla stanu ustalonego jazdy
	if((Uint32)predkosc_ob>5000) obliczenie_dawki(AFRustalony);
}

void obliczenie_dawki(double AFR){
	double t_wtr=0, max_f_twtr=0;
	t_wtr=(((((md[MAF_sredni]/AFR)*8.33333335)/((double)predkosc_ob)))/(0.0111833))+tz; //t_wtr=(((((m/AFR)*8.33333335)/n))/(0.0111833)); jest to czas wtrysku wyrazony w milisekundach
	t_wtr=t_wtr*585.9374989; //konwersja z milisekund do jednostek zegara - jednostka zegara ustawiona na 1,70666667us bo 1/30MHz*1/5*2*preskaler, preskaler = 128
	max_f_twtr=(17578125/predkosc_ob)-5;
	if((((long)t_wtr)<((long)max_f_twtr))&&(((long)t_wtr)<=65000)){
		czas=t_wtr;
	}
	if((((long)t_wtr)>=((long)max_f_twtr))&&(((long)t_wtr)<=65000)) {
		czas=max_f_twtr; //maksymalny czas wtrysku to 85,3333ms
	}
	if((((long)t_wtr)>=((long)max_f_twtr))&&(((long)t_wtr)>65000)) {
		czas=65000;
	}
}
void rozruch(void){ //obliczenie czasu wtrysku dla rozruchu
	int czy_byl_przedwtrysk=0;
if(1){//(Napiecie_adcB3_tW>0)&&((Uint32)predkosc_ob<=5000)){//jeœli temperatura wody <=17*C zimny rozruch
	if(licznik_impulsow==1) czas=pierwszy_wtrysk[Napiecie_adcB3_tW];
	if(licznik_impulsow>1&&licznik_impulsow<7) czas=(pierwszy_wtrysk[Napiecie_adcB3_tW]/2);
	if(licznik_impulsow>=7&&licznik_impulsow<15) {
		obliczenie_dawki(AFR1zimny); //4.704
	}
	if(licznik_impulsow>=30&&licznik_impulsow<45) { //11.76
			obliczenie_dawki(AFR2zimny);
		}
		if(licznik_impulsow>=45&&licznik_impulsow<60) { //11.76
				obliczenie_dawki(AFR3zimny);
			}
		if(licznik_impulsow>=60&&licznik_impulsow<75) { //11.76
				obliczenie_dawki(AFR4zimny);
			}
		if(licznik_impulsow>=90&&licznik_impulsow<105) { //11.76
				obliczenie_dawki(AFR5zimny);
			}
		if(licznik_impulsow>=105&&licznik_impulsow<130) { //12.3
			obliczenie_dawki(AFR6zimny);
		}
		if(licznik_impulsow>=130&&licznik_impulsow<145) { //12.3
					obliczenie_dawki(AFR61zimny);
		}
		if(licznik_impulsow>=145&&licznik_impulsow<150) {//12.8
			obliczenie_dawki(AFR7zimny);
		}
		/*if(licznik_impulsow>=150&&licznik_impulsow<200) {//12.8
				obliczenie_dawki(AFR8zimny);
			}*/
		if(licznik_impulsow>=150) {//12.8
						obliczenie_dawki(AFR8zimny);
					}
		/*if(licznik_impulsow>=200&&licznik_impulsow<250) {//12.8
				obliczenie_dawki(AFR9zimny);
			}
		if(licznik_impulsow>=250&&licznik_impulsow<300) {//12.8
				obliczenie_dawki(AFR10zimny);
			}
		if(licznik_impulsow>=300&&licznik_impulsow<350) {//12.8
					obliczenie_dawki(AFR11zimny);
				}
		if(licznik_impulsow>=350&&licznik_impulsow<400) {//12.8
					obliczenie_dawki(AFR12zimny);
				}
		if(licznik_impulsow>=400&&licznik_impulsow<450) {//12.8
					obliczenie_dawki(AFR13zimny);
				}
		if(licznik_impulsow>=450&&licznik_impulsow<500) {//12.8
					obliczenie_dawki(AFR14zimny);
				}
		if(licznik_impulsow>=500) {//13
			obliczenie_dawki(AFR15zimny);
		}*/
}
/*if((Napiecie_adcB3_tW<=40)&&((Uint32)predkosc_ob<=5000)){// jeœli temperatura wody >17*C rozgrzany rozruch
	if(((Uint32)predkosc_ob==0)&&(GpioDataRegs.GPADAT.bit.GPIOA13==0)&&(czy_byl_przedwtrysk==0)){
		czas=przedwtrysk[Napiecie_adcB3_tW];
		czy_byl_przedwtrysk=1;
		GpioDataRegs.GPADAT.bit.GPIOA0=1; //wlaczenie wtryskiwacza
		EvaRegs.T1CNT=0; //reset licznika czasu wtrysku
	}

	if(licznik_impulsow==1) {
		czas=pierwszy_wtrysk[Napiecie_adcB3_tW];
	}
	if(licznik_impulsow>1&&licznik_impulsow<7) czas=((pierwszy_wtrysk[Napiecie_adcB3_tW])/2);
	if(licznik_impulsow>=7&&licznik_impulsow<15) {
		obliczenie_dawki(AFR1cieply); //7.35
	}
	if(licznik_impulsow>=30&&licznik_impulsow<45) { //11.76
		obliczenie_dawki(AFR2cieply);
	}
	if(licznik_impulsow>=45&&licznik_impulsow<60) { //11.76
			obliczenie_dawki(AFR3cieply);
		}
	if(licznik_impulsow>=60&&licznik_impulsow<75) { //11.76
			obliczenie_dawki(AFR4cieply);
		}
	if(licznik_impulsow>=90&&licznik_impulsow<105) { //11.76
			obliczenie_dawki(AFR2cieply);
		}
	if(licznik_impulsow>=105&&licznik_impulsow<130) { //12.3
		obliczenie_dawki(AFR3cieply);
	}
	if(licznik_impulsow>=145&&licznik_impulsow<150) {//12.8
		obliczenie_dawki(AFR4cieply);
	}
	if(licznik_impulsow>=150&&licznik_impulsow<200) {//12.8
			obliczenie_dawki(AFR4cieply);
		}
	if(licznik_impulsow>=200&&licznik_impulsow<250) {//12.8
			obliczenie_dawki(AFR4cieply);
		}
	if(licznik_impulsow>=250&&licznik_impulsow<300) {//12.8
			obliczenie_dawki(AFR4cieply);
		}
	if(licznik_impulsow>=300&&licznik_impulsow<350) {//12.8
				obliczenie_dawki(AFR4cieply);
			}
	if(licznik_impulsow>=350&&licznik_impulsow<400) {//12.8
				obliczenie_dawki(AFR4cieply);
			}
	if(licznik_impulsow>=400&&licznik_impulsow<450) {//12.8
				obliczenie_dawki(AFR4cieply);
			}
	if(licznik_impulsow>=450&&licznik_impulsow<500) {//12.8
				obliczenie_dawki(AFR4cieply);
			}
	if(licznik_impulsow>=500) {//13
		obliczenie_dawki(AFR5cieply);
	}
}*/
}

void MAFsredni(void){

		bufor=Napiecie_adcB0_MAF+bufor;
		licznik++;
		if(licznik_impulsow<licznik_usredniania){ //potestuj
			MAF_sredni=Napiecie_adcB0_MAF;
		}
		if((licznik_impulsow%modulo_usredniania)==0&&licznik_impulsow!=0){
			MAF_sredni=bufor/licznik;
			licznik=0;
			bufor=0;
		}
}
void Vsredni(void){

	bufor_v=predkosc_ob+bufor_v;
	licznik_v++;
	if(licznik_impulsow<licznik_usredniania){ //potestuj
					V_sredni=predkosc_ob;
				}
				if((licznik_impulsow%modulo_usredniania)==0&&licznik_impulsow!=0){
					V_sredni=bufor_v/licznik_v;
					licznik_v=0;
					bufor_v=0;
				}
				bufor_v=0;

	//MAF_sredni=Napiecie_adcB0_MAF;
}

/*void dotrysk(void){
if(Napiecie_adcB7_TPS_B>0) AFR8zimny=1;

}

void V_TPS(void){
if((EvaRegs.T3PR==0)){ //licznik parzysty - podstawiamy starsz¹ wartosc rejestru
				wartosc_starszaTPS=Napiecie_adcB5_TPS_A;
		}

if(EvaRegs.T3PR==700){ //licznik nieparzysty - podstawiamy m³odsz¹ wartosc rejestru
				wartosc_mlodszaTPS=Napiecie_adcB5_TPS_A;
		}
if(wartosc_rejestru_licznika_starsza<wartosc_rejestru_licznika_mlodsza)	{
		deltaTPS=(wartosc_rejestru_licznika_mlodsza-wartosc_rejestru_licznika_starsza);
		deltaTPS=delta*40;
		predkosc_ob=120000000/delta; //przerwanie Timer0 co 10 mikrosekund, st¹d delta*10 to ilosc mikrosekund
		//predkosc_ob=(1.0)/predkosc_ob;
	}
}
*/
