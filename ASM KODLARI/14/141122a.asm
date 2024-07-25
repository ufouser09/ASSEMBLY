my_ss		SEGMENT PARA STACK 'stack'
			DW 20 DUP(?)
my_ss		ENDS
my_ds		SEGMENT PARA 'data'
dizi		DW 3, 5, 9, 12, 0, 6, 5, 13
eleman		DW 8
tek_top		DD 0
cift_top	DD 0
tek_say		DW 0
cift_say	DW 0
tek_ort		DW ?
cift_ort	DW ?
my_ds		ENDS
my_cs		SEGMENT PARA 'code'
			ASSUME CS:my_cs, DS:my_ds, SS:my_ss
ANA			PROC FAR
			PUSH DS
			XOR AX, AX
			PUSH AX
			MOV AX, my_ds
			MOV DS, AX
			MOV CX, eleman
			LEA SI, dizi
don:		MOV AX, [SI]
			TEST AX, 0001h
			JZ cift
			ADD WORD PTR [tek_top], AX
			ADC WORD PTR [tek_top+2], 0
			INC tek_say
			JMP artir
cift:		ADD WORD PTR [cift_top], AX
			ADC WORD PTR [cift_top+2], 0
			INC cift_say
artir:		ADD SI, 2
			LOOP don
			
			MOV DX, WORD PTR [tek_top+2]
			MOV AX, WORD PTR [tek_top]
			DIV tek_say
			MOV tek_ort, AX
			
			MOV DX, WORD PTR [cift_top+2]
			MOV AX, WORD PTR [cift_top]
			DIV cift_say
			MOV cift_ort, AX			
			
			RETF
ANA			ENDP
my_cs		ENDS
			END ANA