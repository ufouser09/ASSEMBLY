		PUBLIC TOPLAMA
codes	SEGMENT PARA 'yordamlar'
		ASSUME CS:codes
TOPLAMA	PROC FAR
--------------------------------------------------------------------------------
		//Ax 0 lan�r
		XOR AX, AX
		//Al yazmac�na Bl degeri atan�r Bl'de de sayi 1 degiskeni vard�r
		MOV AL, BL
		//sayi 1 ile sayi 2 toplan�r
		ADD AL, BH
		//eger tasma varsa ah de saklan�r
		ADC AH, 0
		RETF
TOPLAMA	ENDP
codes	ENDS
		END
