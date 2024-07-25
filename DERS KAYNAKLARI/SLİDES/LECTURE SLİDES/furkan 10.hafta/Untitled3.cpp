		PUBLIC TOPLAMA
codes	SEGMENT PARA 'yordamlar'
		ASSUME CS:codes
TOPLAMA	PROC FAR
--------------------------------------------------------------------------------
		//Ax 0 lanýr
		XOR AX, AX
		//Al yazmacýna Bl degeri atanýr Bl'de de sayi 1 degiskeni vardýr
		MOV AL, BL
		//sayi 1 ile sayi 2 toplanýr
		ADD AL, BH
		//eger tasma varsa ah de saklanýr
		ADC AH, 0
		RETF
TOPLAMA	ENDP
codes	ENDS
		END
