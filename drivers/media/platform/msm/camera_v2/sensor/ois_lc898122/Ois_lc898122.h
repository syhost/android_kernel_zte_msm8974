//********************************************************************************
//
//		<< LC898122 Evaluation Soft>>
//		Program Name	: Ois.h
// 		Explanation		: LC898122 Global Declaration & ProtType Declaration
//		Design			: Y.Yamada
//		History			: First edition						2009.07.30 Y.Tashita
//********************************************************************************

//#include "msm_ois_lc898122.h"
extern void RegReadA_lc898122(unsigned short reg_addr, unsigned char *read_data_8);
extern void RegWriteA_lc898122(unsigned short reg_addr, unsigned char write_data_8);
extern void RamReadA_lc898122(unsigned short ram_addr, void *read_data_16);
extern void RamWriteA_lc898122(unsigned short ram_addr, unsigned short write_data_16);
extern void RamRead32A_lc898122(unsigned short ram_addr, void *read_data_32);
extern void RamWrite32A_lc898122(unsigned short ram_addr, unsigned long write_data_32);

#ifdef	OISINI
	#define	OISINI__
#else
	#define	OISINI__		extern
#endif







#ifdef	OISCMD
	#define	OISCMD__
#else
	#define	OISCMD__		extern
#endif


// Define According To Usage

/****************************** Define���� ******************************/
/*	USE_3WIRE_DGYRO		Digital Gyro I/F 3��Mode�g�p					*/
/*	USE_INVENSENSE		Invensense Digital Gyro�g�p						*/
/*		USE_IDG2020		Inv IDG-2020�g�p								*/
/*	STANDBY_MODE		Standby����g�p(���m�F)							*/
/*	GAIN_CONT			:Gain control�@�\�g�p							*/
/*		(disable)		DSC			:�O�rMode�g�p						*/
/*	HALLADJ_HW			Hall Calibration LSI�@�\�g�p					*/
/************************************************************************/

/**************** Select Gyro Sensor **************/
//#define 	USE_3WIRE_DGYRO    //for D-Gyro SPI interface

#define		USE_INVENSENSE		// INVENSENSE
#ifdef USE_INVENSENSE
//			#define		FS_SEL		0		/* �}262LSB/��/s  */
//			#define		FS_SEL		1		/* �}131LSB/��/s  */
//			#define		FS_SEL		2		/* �}65.5LSB/��/s  */
			#define		FS_SEL		3		/* �}32.8LSB/��/s  */

//			#define		GYROSTBY			/* Sleep+STBY */
#endif

/**************** Model name *****************/
#define		MN_3BSD04P1
/**************** FW version *****************/
#ifdef	MN_3BSD04P1
 #define	MDL_VER			0x07
 #define	FW_VER			0x01
#endif

/**************** Select Mode **************/
#define		STANDBY_MODE		// STANDBY Mode
#define		GAIN_CONT			// Gain Control Mode
//#define		HALLADJ_HW			// H/W Hall adjustment 
#define		PWM_BREAK			// PWM mode select (disable zero cross)

#ifdef	MN_3BSD04P1
 #define		ACTREG_10P2OHM		// Use 10.2ohm
#endif

#define		DEF_SET				// default value re-setting
//#define		USE_EXTCLK_ALL		// USE Ext clk for ALL
//#define		USE_EXTCLK_PWM		// USE Ext clk for PWM
//#define		USE_VH_SYNC			// USE V/H Sync for PWM
//#define		PWM_CAREER_TEST		// PWM_CAREER_TEST
#define		NEUTRAL_CENTER		// Upper Position Current 0mA Measurement
#define		H1COEF_CHANGER			/* H1 coef lvl chage */
#define		MONITOR_OFF			// default Monitor output
//#define		MODULE_CALIBRATION		// for module maker   use float
//#define		AF_PWMMODE			// AF Driver PWM mode
//#define		CORRECT_1DEG			// Correct 1deg   disable 0.5deg



// Command Status
#define		EXE_END		0x02		// Execute End (Adjust OK)
#define		EXE_HXADJ	0x06		// Adjust NG : X Hall NG (Gain or Offset)
#define		EXE_HYADJ	0x0A		// Adjust NG : Y Hall NG (Gain or Offset)
#define		EXE_LXADJ	0x12		// Adjust NG : X Loop NG (Gain)
#define		EXE_LYADJ	0x22		// Adjust NG : Y Loop NG (Gain)
#define		EXE_GXADJ	0x42		// Adjust NG : X Gyro NG (offset)
#define		EXE_GYADJ	0x82		// Adjust NG : Y Gyro NG (offset)
#define		EXE_OCADJ	0x402		// Adjust NG : OSC Clock NG
#define		EXE_ERR		0x99		// Execute Error End

// Common Define
#define	SUCCESS			0x00		// Success
#define	FAILURE			0x01		// Failure

#ifndef ON
 #define	ON				0x01		// ON
 #define	OFF				0x00		// OFF
#endif
 #define	SPC				0x02		// Special Mode

#define	X_DIR			0x00		// X Direction
#define	Y_DIR			0x01		// Y Direction
#define	X2_DIR			0x10		// X Direction
#define	Y2_DIR			0x11		// Y Direction

#define	NOP_TIME		0.00004166F

#ifdef STANDBY_MODE
 // Standby mode
 #define		STB1_ON		0x00		// Standby1 ON
 #define		STB1_OFF	0x01		// Standby1 OFF
 #define		STB2_ON		0x02		// Standby2 ON
 #define		STB2_OFF	0x03		// Standby2 OFF
 #define		STB3_ON		0x04		// Standby3 ON
 #define		STB3_OFF	0x05		// Standby3 OFF
 #define		STB4_ON		0x06		// Standby4 ON			/* for Digital Gyro Read */
 #define		STB4_OFF	0x07		// Standby4 OFF
 #define		STB2_OISON	0x08		// Standby2 ON (only OIS)
 #define		STB2_OISOFF	0x09		// Standby2 OFF(only OIS)
 #define		STB2_AFON	0x0A		// Standby2 ON (only AF)
 #define		STB2_AFOFF	0x0B		// Standby2 OFF(only AF)
#endif


// OIS Adjust Parameter
 #define		DAHLXO_INI		0x0000
 #define		DAHLXB_INI		0xE000
 #define		DAHLYO_INI		0x0000
 #define		DAHLYB_INI		0xE000
 #define		SXGAIN_INI		0x3000
 #define		SYGAIN_INI		0x3000
 #define		HXOFF0Z_INI		0x0000
 #define		HYOFF1Z_INI		0x0000

#ifdef ACTREG_6P5OHM		// MTM 9.5 Actuator ***************************
 #define		BIAS_CUR_OIS	0x33		//2.0mA/2.0mA
 #define		AMP_GAIN_X		0x05		//x150
 #define		AMP_GAIN_Y		0x05		//x150

/* OSC Init */
 #define		OSC_INI			0x2E		/* VDD=2.8V */

/* AF Open para */
 #define		RWEXD1_L_AF		0x7FFF		//
 #define		RWEXD2_L_AF		0x1094		//
 #define		RWEXD3_L_AF		0x72BA		//
 #define		FSTCTIME_AF		0xED		//
 #define		FSTMODE_AF		0x02		//
 
 /* (0.3750114X^3+0.5937681X)*(0.3750114X^3+0.5937681X) 6.5ohm*/
 #define		A3_IEXP3		0x3EC0017F
 #define		A1_IEXP1		0x3F180130
 
#endif
#ifdef ACTREG_10P2OHM		// MTM 10.2 Actuator ***************************
 #define		BIAS_CUR_OIS	0x33		//2.0mA/2.0mA
 #define		AMP_GAIN_X		0x05		//x150
 #define		AMP_GAIN_Y		0x05		//x150

/* OSC Init */
 #define		OSC_INI			0x2E		/* VDD=2.8V */

/* AF Open para */
  #define		RWEXD1_L_AF		0x7FFF		//
  #define		RWEXD2_L_AF		0x75FE		//
  #define		RWEXD3_L_AF		0x7F32		//
  #define		FSTCTIME_AF		0xF1		//
  #define		FSTMODE_AF		0x00		//

 /* (0.3750114X^3+0.55X)*(0.3750114X^3+0.55X) 10.2ohm*/
 #define		A3_IEXP3		0x3EC0017F
 #define		A1_IEXP1		0x3F0CCCCD
 
#endif
#ifdef ACTREG_15OHM					// TDK 10.5 Actuator ***************************
 #define		BIAS_CUR_OIS	0x22		//1.0mA/1.0mA
 #define		AMP_GAIN_X		0x04		//x100
 #define		AMP_GAIN_Y		0x04		//x100

/* OSC Init */
 #define		OSC_INI			0x2E		/* VDD=2.8V */

/* AF Open para */
 #define		RWEXD1_L_AF		0x7FFF		//
 #define		RWEXD2_L_AF		0x5A00		//
 #define		RWEXD3_L_AF		0x7000		//
 #define		FSTCTIME_AF		0x5F		//
 #define		FSTMODE_AF		0x00		//
 
 /* (0.4531388X^3+0.4531388X)*(0.4531388X^3+0.4531388X) 15ohm*/
 #define		A3_IEXP3		0x3EE801CF
 #define		A1_IEXP1		0x3EE801CF
 
#endif

/* AF adjust parameter */
#define		DAHLZB_INI		0x9000
#define		DAHLZO_INI		0x0000
#define		BIAS_CUR_AF		0x00		//0.25mA
#define		AMP_GAIN_AF		0x00		//x6

// Digital Gyro offset Initial value 
#define		DGYRO_OFST_XH	0x00
#define		DGYRO_OFST_XL	0x00
#define		DGYRO_OFST_YH	0x00
#define		DGYRO_OFST_YL	0x00

#define		SXGAIN_LOP		0x3000
#define		SYGAIN_LOP		0x3000

#define		TCODEH_ADJ		0x0000

#define		GYRLMT1H		0x3DCCCCCD		//0.1F

#ifdef	CORRECT_1DEG
 #define		GYRLMT3_S1		0x3F19999A		//0.60F
 #define		GYRLMT3_S2		0x3F19999A		//0.60F

 #define		GYRLMT4_S1		0x40400000		//3.0F
 #define		GYRLMT4_S2		0x40400000		//3.0F

 #define		GYRA12_HGH		0x40000000		/* 2.00F */
 #define		GYRA12_MID		0x3F800000		/* 1.0F */
 #define		GYRA34_HGH		0x3F000000		/* 0.5F */
 #define		GYRA34_MID		0x3DCCCCCD		/* 0.1F */

 #define		GYRB12_HGH		0x3E4CCCCD		/* 0.20F */
 #define		GYRB12_MID		0x3CA3D70A		/* 0.02F */
 #define		GYRB34_HGH		0x3CA3D70A		/* 0.02F */
 #define		GYRB34_MID		0x3C23D70A		/* 0.001F */

#else
 #define		GYRLMT3_S1		0x3ECCCCCD		//0.40F
 #define		GYRLMT3_S2		0x3ECCCCCD		//0.40F

 #define		GYRLMT4_S1		0x40000000		//2.0F
 #define		GYRLMT4_S2		0x40000000		//2.0F

 #define		GYRA12_HGH		0x3FC00000		/* 1.50F */
 #define		GYRA12_MID		0x3F800000		/* 1.0F */
 #define		GYRA34_HGH		0x3F000000		/* 0.5F */
 #define		GYRA34_MID		0x3DCCCCCD		/* 0.1F */

 #define		GYRB12_HGH		0x3E4CCCCD		/* 0.20F */
 #define		GYRB12_MID		0x3CA3D70A		/* 0.02F */
 #define		GYRB34_HGH		0x3CA3D70A		/* 0.02F */
 #define		GYRB34_MID		0x3C23D70A		/* 0.001F */

#endif


//#define		OPTCEN_X		0x0000
//#define		OPTCEN_Y		0x0000

#ifdef USE_INVENSENSE
 #ifdef	MN_3BSD04P1
  #define		SXQ_INI			0x3F800000
  #define		SYQ_INI			0xBF800000

  #define		GXGAIN_INI		0xBF147AE1
  #define		GYGAIN_INI		0x3F147AE1

  #define		GYROX_INI		0x43
  #define		GYROY_INI		0x45
  
  #define		GXHY_GYHX		1
 #endif
#endif


/* Optical Center & Gyro Gain for Mode */
 #define	VAL_SET				0x00		// Setting mode
 #define	VAL_FIX				0x01		// Fix Set value
 #define	VAL_SPC				0x02		// Special mode


struct STFILREG {
	unsigned short	UsRegAdd ;
	unsigned char	UcRegDat ;
} ;													// Register Data Table

struct STFILRAM {
	unsigned short	UsRamAdd ;
	unsigned long	UlRamDat ;
} ;													// Filter Coefficient Table

struct STCMDTBL
{
	unsigned short Cmd ;
	unsigned int UiCmdStf ;
	void ( *UcCmdPtr )( void ) ;
} ;

/*** caution [little-endian] ***/

// Word Data Union
union	WRDVAL{
	unsigned short	UsWrdVal ;
	unsigned char	UcWrkVal[ 2 ] ;
	struct {
		unsigned char	UcLowVal ;
		unsigned char	UcHigVal ;
	} StWrdVal ;
} ;

typedef union WRDVAL	UnWrdVal ;

union	DWDVAL {
	unsigned long	UlDwdVal ;
	unsigned short	UsDwdVal[ 2 ] ;
	struct {
		unsigned short	UsLowVal ;
		unsigned short	UsHigVal ;
	} StDwdVal ;
	struct {
		unsigned char	UcRamVa0 ;
		unsigned char	UcRamVa1 ;
		unsigned char	UcRamVa2 ;
		unsigned char	UcRamVa3 ;
	} StCdwVal ;
} ;

typedef union DWDVAL	UnDwdVal;

// Float Data Union
union	FLTVAL {
	float			SfFltVal ;
	unsigned long	UlLngVal ;
	unsigned short	UsDwdVal[ 2 ] ;
	struct {
		unsigned short	UsLowVal ;
		unsigned short	UsHigVal ;
	} StFltVal ;
} ;

typedef union FLTVAL	UnFltVal ;


typedef struct STADJPAR {
	struct {
		unsigned char	UcAdjPhs ;				// Hall Adjust Phase

		unsigned short	UsHlxCna ;				// Hall Center Value after Hall Adjust
		unsigned short	UsHlxMax ;				// Hall Max Value
		unsigned short	UsHlxMxa ;				// Hall Max Value after Hall Adjust
		unsigned short	UsHlxMin ;				// Hall Min Value
		unsigned short	UsHlxMna ;				// Hall Min Value after Hall Adjust
		unsigned short	UsHlxGan ;				// Hall Gain Value
		unsigned short	UsHlxOff ;				// Hall Offset Value
		unsigned short	UsAdxOff ;				// Hall A/D Offset Value
		unsigned short	UsHlxCen ;				// Hall Center Value

		unsigned short	UsHlyCna ;				// Hall Center Value after Hall Adjust
		unsigned short	UsHlyMax ;				// Hall Max Value
		unsigned short	UsHlyMxa ;				// Hall Max Value after Hall Adjust
		unsigned short	UsHlyMin ;				// Hall Min Value
		unsigned short	UsHlyMna ;				// Hall Min Value after Hall Adjust
		unsigned short	UsHlyGan ;				// Hall Gain Value
		unsigned short	UsHlyOff ;				// Hall Offset Value
		unsigned short	UsAdyOff ;				// Hall A/D Offset Value
		unsigned short	UsHlyCen ;				// Hall Center Value
	} StHalAdj ;

	struct {
		unsigned short	UsLxgVal ;				// Loop Gain X
		unsigned short	UsLygVal ;				// Loop Gain Y
		unsigned short	UsLxgSts ;				// Loop Gain X Status
		unsigned short	UsLygSts ;				// Loop Gain Y Status
	} StLopGan ;

	struct {
		unsigned short	UsGxoVal ;				// Gyro A/D Offset X
		unsigned short	UsGyoVal ;				// Gyro A/D Offset Y
		unsigned short	UsGxoSts ;				// Gyro Offset X Status
		unsigned short	UsGyoSts ;				// Gyro Offset Y Status
	} StGvcOff ;
	
	unsigned char		UcOscVal ;				// OSC value

} stAdjPar ;

OISCMD__	stAdjPar	StAdjPar_lc898122 ;				// Execute Command Parameter

OISCMD__	unsigned char	UcOscAdjFlg_lc898122 ;		// For Measure trigger
  #define	MEASSTR		0x01
  #define	MEASCNT		0x08
  #define	MEASFIX		0x80

OISINI__	unsigned short	UsCntXof_lc898122 ;				/* OPTICAL Center Xvalue */
OISINI__	unsigned short	UsCntYof_lc898122 ;				/* OPTICAL Center Yvalue */

OISINI__	unsigned char	UcPwmMod_lc898122 ;				/* PWM MODE */
#define		PWMMOD_CVL	0x00		// CVL PWM MODE
#define		PWMMOD_PWM	0x01		// PWM MODE

#define		INIT_PWMMODE	PWMMOD_CVL		// initial output mode

OISINI__	unsigned char	UcCvrCod ;				/* CverCode */
 #define	CVER122		0x93		 // LC898122
 #define	CVER122A	0xA1		 // LC898122A


// Prottype Declation
OISINI__ void	IniSet_lc898122( void ) ;													// Initial Top Function
OISINI__ void	IniSetAf_lc898122( void ) ;													// Initial Top Function

OISINI__ void	ClrGyr_lc898122( unsigned short, unsigned char ); 							   // Clear Gyro RAM
	#define CLR_FRAM0		 	0x01
	#define CLR_FRAM1 			0x02
	#define CLR_ALL_RAM 		0x03
OISINI__ void	BsyWit_lc898122( unsigned short, unsigned char ) ;				// Busy Wait Function
OISINI__ void	WitTim_lc898122( unsigned short ) ;											// Wait
OISINI__ void	MemClr_lc898122( unsigned char *, unsigned short ) ;							// Memory Clear Function
OISINI__ void	GyOutSignal_lc898122( void ) ;									// Slect Gyro Output signal Function
OISINI__ void	GyOutSignalCont_lc898122( void ) ;								// Slect Gyro Output Continuos Function
#ifdef STANDBY_MODE
OISINI__ void	AccWit_lc898122( unsigned char ) ;								// Acc Wait Function
OISINI__ void	SelectGySleep_lc898122( unsigned char ) ;						// Select Gyro Mode Function
#endif
#ifdef	GAIN_CONT
OISINI__ void	AutoGainControlSw_lc898122( unsigned char ) ;							// Auto Gain Control Sw
#endif
OISINI__ void	DrvSw_lc898122( unsigned char UcDrvSw ) ;						// Driver Mode setting function
OISINI__ void	AfDrvSw_lc898122( unsigned char UcDrvSw ) ;						// AF Driver Mode setting function
OISINI__ void	RamAccFixMod_lc898122( unsigned char ) ;							// Ram Access Fix Mode setting function
OISINI__ void	IniPtMovMod_lc898122( unsigned char ) ;							// Pan/Tilt parameter setting by mode function
OISINI__ void	ChkCvr_lc898122( void ) ;													// Check Function
	
OISCMD__ void			SrvCon_lc898122( unsigned char, unsigned char ) ;					// Servo ON/OFF
OISCMD__ unsigned short	TneRun_lc898122( void ) ;											// Hall System Auto Adjustment Function
OISCMD__ unsigned char	RtnCen_lc898122( unsigned char ) ;									// Return to Center Function
OISCMD__ void			OisEna_lc898122( void ) ;											// OIS Enable Function
OISCMD__ void			OisEnaLin_lc898122( void ) ;											// OIS Enable Function for Line adjustment
OISCMD__ void			TimPro_lc898122( void ) ;											// Timer Interrupt Process Function
OISCMD__ void			S2cPro_lc898122( unsigned char ) ;									// S2 Command Process Function
 #ifdef	MN_3BSD04P1
	#define		DIFIL_S2		0x3F7FFE00
 #endif
OISCMD__ void			SetSinWavePara_lc898122( unsigned char , unsigned char ) ;			// Sin wave Test Function
	#define		SINEWAVE	0
	#define		XHALWAVE	1
	#define		YHALWAVE	2
	#define		CIRCWAVE	255
OISCMD__ unsigned char	TneGvc_lc898122( void ) ;											// Gyro VC Offset Adjust

OISCMD__ void			SetZsp_lc898122( unsigned char ) ;									// Set Zoom Step parameter Function
OISCMD__ void			OptCen_lc898122( unsigned char, unsigned short, unsigned short ) ;	// Set Optical Center adjusted value Function
OISCMD__ void			StbOnnN_lc898122( unsigned char , unsigned char ) ;					// Stabilizer For Servo On Function
#ifdef	MODULE_CALIBRATION
OISCMD__ unsigned char	LopGan_lc898122( unsigned char ) ;									// Loop Gain Adjust
#endif
#ifdef STANDBY_MODE
 OISCMD__ void			SetStandby_lc898122( unsigned char ) ;								/* Standby control	*/
#endif
#ifdef	MODULE_CALIBRATION
OISCMD__ unsigned short	OscAdj_lc898122( void ) ;											/* OSC clock adjustment */
#endif

#ifdef	HALLADJ_HW
 #ifdef	MODULE_CALIBRATION
 OISCMD__ unsigned char	LoopGainAdj_lc898122(   unsigned char );
 #endif
 OISCMD__ unsigned char	BiasOffsetAdj_lc898122( unsigned char , unsigned char );
#endif
OISCMD__ void			GyrGan_lc898122( unsigned char , unsigned long , unsigned long ) ;	/* Set Gyro Gain Function */
OISCMD__ void			SetPanTiltMode_lc898122( unsigned char ) ;							/* Pan_Tilt control Function */
#ifndef	HALLADJ_HW
 OISCMD__ unsigned long	TnePtp_lc898122( unsigned char, unsigned char ) ;					// Get Hall Peak to Peak Values
 #ifdef	MN_3BSD04P1
	#define		HALL_H_VAL	0x3F800000			/* 1.0 */
 #endif
 OISCMD__ unsigned char	TneCen_lc898122( unsigned char, UnDwdVal ) ;							// Tuning Hall Center
 #define		PTP_BEFORE		0
 #define		PTP_AFTER		1
#endif
#ifdef GAIN_CONT
OISCMD__ unsigned char	TriSts_lc898122( void ) ;													// Read Status of Tripod mode Function
#endif
OISCMD__ unsigned char	DrvPwmSw_lc898122( unsigned char ) ;											// Select Driver mode Function
	#define		Mlnp		0					// Linear PWM
	#define		Mpwm		1					// PWM
 #ifdef	NEUTRAL_CENTER											// Gyro VC Offset Adjust
 OISCMD__ unsigned char	TneHvc_lc898122( void ) ;											// Hall VC Offset Adjust
 #endif	//NEUTRAL_CENTER
OISCMD__ void			SetGcf_lc898122( unsigned char ) ;									// Set DI filter coefficient Function
OISCMD__	unsigned long	UlH1Coefval ;		// H1 coefficient value
#ifdef H1COEF_CHANGER
 OISCMD__	unsigned char	UcH1LvlMod_lc898122 ;		// H1 level coef mode
 OISCMD__	void			SetH1cMod_lc898122( unsigned char ) ;								// Set H1C coefficient Level chang Function
 #define		S2MODE		0x40
 #define		ACTMODE		0x80
 #define		MOVMODE		0xFF
#endif
OISCMD__	unsigned short	RdFwVr_lc898122( void ) ;										// Read Fw Version Function
