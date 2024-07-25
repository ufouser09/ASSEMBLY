-----------------------------------------------------------------------

PAGE 80, 60
-----------------------------------------------------------------------

STKSG SEGMENT PARA STACK 'STK'
	//bu soru 2^10 u bulur
	DW 20 DUP (?)
STKSG ENDS
-----------------------------------------------------------------------

DATASG SEGMENT PARA 'DAT'
	STR DB 'MERHABA'
	A DB 2
	B DB 10
	SONUC DW 0
DATASG ENDS
-----------------------------------------------------------------------

CODESG SEGMENT PARA 'CD'
	ASSUME CS: CODESG, DS: DATASG, SS: STKSG
	SON PROC FAR
-----------------------------------------------------------------------
		
		PUSH DS
		XOR AX, AX
		PUSH AX
-----------------------------------------------------------------------

		MOV AX, DATASG
		MOV DS, AX		;AX DS ye atanýr
-----------------------------------------------------------------------
		//Dx i sýfýrlarýz
		XOR DX, DX		;DX 0 lanýr
		//CX i sýfýrlarýz
		XOR CX, CX		;CX 0 lanýr
		//Ax e 1 degerini atarýz
		MOV AX, 1		;AX e 1 atanýr
		//B sayisini Cl ye atarýz
		MOV CL, B		;CL ye B atanýr
		//Bx i sýfýrlarýz
		XOR BX, BX		;BX 0 lanýr
		//Bl ye A sayisini atarýz
		MOV BL, A		;BL ye A atanýr
		L1:
		MUL BX;DX:AX->Ax*BX
		LOOP L1
		MOV SONUC, AX
-----------------------------------------------------------------------
		
		RETF
	SON ENDP
CODESG ENDS
	END SON
