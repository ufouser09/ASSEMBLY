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
			//Al yazmac�na A sayisina atar�z.			
			MOV AL, a
			//Bl yazmac�na B sayisin� atar�z
			MOV BL, b
			//Cl yazmac�na C sayisini atar�z.
			MOV CL, c
			//A sayisi ile B sayisini kars�last�r�r�z
			CMP AL, BL
			//A sayisi ile B sayisi eger esitse j1 etiketine atla
			JE J1
			//A sayisi ile B sayisi esit degilse B ve C'yi kars�last�r
			CMP BL, CL
			//Eger a ve b esit c�kt�ktan sonra B ve c De esit c�km�ssa o zaman son etiketine atla
			JE SON
			//Eger a ve b esit ��km�s B ve c esit c�kmam�s ise o zaman a ve c yi kars�last�r.
			CMP AL, CL
			//eger a ve b esit ��km�s b ve c esit c�kmam�s ise ve a ve c esit c�kmis ise son etiketine atla
			JE SON
			//eger a ve b esit ��km�s b ve c esit c�kmam�s ise ve a ve c esit c�kmam�s ise tip etiketine 3 degerini atar�z
			MOV tip, 3
			//son etiketine atlan�r
			JMP SON
			//eger a ve b esit c�km�s ise a ve c yi kars�last�r
J1:			CMP AL, CL
			//eger a ve b esit c�km�s ve a ve c esit degilse son etiketine atla
			JNE SON
			//eger a ve b esit c�km�s ve a ve c esit c�km�s ise tip etiketine 1 degerini ata
			MOV tip, 1
			//son etiketine atla
			JMP SON	
SON:		RETF
UCGEN		ENDP
codesg		ENDS
			END UCGEN
