-----------------------------------------------------------------------
  
        PAGE 60,80
        TITLE ornek____
-----------------------------------------------------------------------
        
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BASLA   PROC NEAR
-----------------------------------------------------------------------
	//dongu sayisini Cx'e atarýz
	MOV CX, N
	//Cx'i 1 azaltýrýz
	DEC CX
	//Sý'yý yani indisi 0 larýz
	XOR SI, SI
	//dizinin ilk indisindeki degeri Ax'e atarýz 
	MOV AX, DIZI[SI]
	L1:
		//Sý indisini word oldugu için 2'ser 2'ser arttýrýrýz.
		ADD SI, 2
		//1.aldýgýmýz deger ile ikinci degeri karsýlastýrýrýz
		CMP AX, DIZI[SI]
		//eger 1.degerimiz 2.degerimizden buyuk esitse l2 etiketine git
		JGE L2
		//Eger 2.degerimiz 1.degerimizden buyuk ise de onu Ax e ata ve artýk buyuk varsaydýgýmýz deger o olsun
			MOV AX, DIZI[SI]
		L2:
	LOOP L1
	//en son en buyuk sayi BYK degiskenine atanýr
	MOV BYK, AX
	
        RET
BASLA   ENDP

N DW 100
DIZI DW 3, -3, 10, -10, 20, 95 DUP (?)
BYK DW ?

CODESG  ENDS
        END BASLA

