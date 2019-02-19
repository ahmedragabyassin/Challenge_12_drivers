/*
 * challenge_13.c
 *
 * Created: 2/18/2019 11:54:02 AM
 * Author : Yassin
 */ 

#include "Includes/BCDSevSegment.h"
#include "Includes/KeyPad.h"
#include "Includes/Lcd.h"
#include "Includes/CommonNumbers.h"

int main(void)
{
	/************************************************************************/
	/* test LCD driver                                                      */
	/************************************************************************/
	#if ENABLE_CODE
	LCD_Init();
	LCD_GotoRowColumn(LCD_ROW2,LCD_COL4);
	LCD_DisplayString("Yassin");
	#endif
	
	#if STOP_CODE
	LCD_DisplayChar('Y');
	LCD_DisplayChar('A');
	LCD_DisplayChar('S');
	LCD_DisplayChar('S');
	LCD_DisplayChar('I');
	LCD_DisplayChar('N');
	#endif
	
	/************************************************************************/
	/* Test Seven Segment and Keypad Drivers                                */
	/************************************************************************/
	#if STOP_CODE
	DIO_SetPinDirection(SEGMENT_A,OUT);
	DIO_SetPinDirection(SEGMENT_B,OUT);
	DIO_SetPinDirection(SEGMENT_C,OUT);
	DIO_SetPinDirection(SEGMENT_D,OUT);
	KeyPad_Init();
	uint8 pressed_key=0;
	#endif

    while (1) 
    {
		/************************************************************************/
		/* Test Seven Segment and Keypad Drivers                                */
		/************************************************************************/
		#if STOP_CODE
		KeyPad_Init();
		BCDSevSegment_Enable(SEG1_EN);
		pressed_key = Scan_KeyPad();
		BCDSevSegment_DisplayNo(pressed_key);
		BCDSevSegment_Disable(SEG1_EN);
		/BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(5);
		BCDSevSegment_Enable(SEG2_EN);
		BCDSevSegment_DisplayNo(9);
		BCDSevSegment_Disable(SEG1_EN);
		BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(5);
		BCDSevSegment_Enable(SEG3_EN);
		BCDSevSegment_DisplayNo(9);
		BCDSevSegment_Disable(SEG1_EN);
		BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(5);
		BCDSevSegment_Enable(SEG4_EN);
		BCDSevSegment_DisplayNo(1);
		BCDSevSegment_Disable(SEG1_EN);
		BCDSevSegment_Disable(SEG2_EN);
		BCDSevSegment_Disable(SEG3_EN);
		BCDSevSegment_Disable(SEG4_EN);
		_delay_us(5); 
		#endif
    }
}

