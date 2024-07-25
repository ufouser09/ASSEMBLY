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
		MOV DS, AX		;AX DS ye atan�r
-----------------------------------------------------------------------
		//Dx i s�f�rlar�z
		XOR DX, DX		;DX 0 lan�r
		//CX i s�f�rlar�z
		XOR CX, CX		;CX 0 lan�r
		//Ax e 1 degerini atar�z
		MOV AX, 1		;AX e 1 atan�r
		//B sayisini Cl ye atar�z
		MOV CL, B		;CL ye B atan�r
		//Bx i s�f�rlar�z
		XOR BX, BX		;BX 0 lan�r
		//Bl ye A sayisini atar�z
		MOV BL, A		;BL ye A atan�r
		L1:
		MUL BX;DX:AX->Ax*BX
		LOOP L1
		MOV SONUC, AX
-----------------------------------------------------------------------
		
		RETF
	SON ENDP
CODESG ENDS
	END SON
