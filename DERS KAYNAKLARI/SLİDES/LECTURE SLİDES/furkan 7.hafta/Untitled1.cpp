-----------------------------------------------------------------------

datasg		SEGMENT PARA 'data'
a			DB 17
b			DB 12
c			DB 16
tip			DB 2
datasg		ENDS
-----------------------------------------------------------------------

stacksg		SEGMENT PARA STACK 'y'
			DW 12 DUP(?)
stacksg		ENDS
codesg		SEGMENT PARA 'kod'
			ASSUME CS:codesg, DS:datasg, SS:stacksg
-----------------------------------------------------------------------

UCGEN		PROC FAR
-----------------------------------------------------------------------

			PUSH DS
			XOR AX, AX
			PUSH AX
-----------------------------------------------------------------------

			MOV AX, datasg
			MOV DS, AX
-----------------------------------------------------------------------
			//Al yazmacýna A sayisina atarýz.			
			MOV AL, a
			//Bl yazmacýna B sayisiný atarýz
			MOV BL, b
			//Cl yazmacýna C sayisini atarýz.
			MOV CL, c
			//A sayisi ile B sayisini karsýlastýrýrýz
			CMP AL, BL
			//A sayisi ile B sayisi eger esitse j1 etiketine atla
			JE J1
			//A sayisi ile B sayisi esit degilse B ve C'yi karsýlastýr
			CMP BL, CL
			//Eger a ve b esit cýktýktan sonra B ve c De esit cýkmýssa o zaman son etiketine atla
			JE SON
			//Eger a ve b esit çýkmýs B ve c esit cýkmamýs ise o zaman a ve c yi karsýlastýr.
			CMP AL, CL
			//eger a ve b esit çýkmýs b ve c esit cýkmamýs ise ve a ve c esit cýkmis ise son etiketine atla
			JE SON
			//eger a ve b esit çýkmýs b ve c esit cýkmamýs ise ve a ve c esit cýkmamýs ise tip etiketine 3 degerini atarýz
			MOV tip, 3
			//son etiketine atlanýr
			JMP SON
			//eger a ve b esit cýkmýs ise a ve c yi karsýlastýr
J1:			CMP AL, CL
			//eger a ve b esit cýkmýs ve a ve c esit degilse son etiketine atla
			JNE SON
			//eger a ve b esit cýkmýs ve a ve c esit cýkmýs ise tip etiketine 1 degerini ata
			MOV tip, 1
			//son etiketine atla
			JMP SON	
SON:		RETF
UCGEN		ENDP
codesg		ENDS
			END UCGEN
