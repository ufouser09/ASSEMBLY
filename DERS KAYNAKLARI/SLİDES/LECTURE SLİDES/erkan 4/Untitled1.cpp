-----------------------------------------------------------------------

        PAGE 60,80
        TITLE ornek____
-----------------------------------------------------------------------
        
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BILGI:  JMP BASLA
-----------------------------------------------------------------------

N DW 100
DIZI DW 3, -3, 10, -10, 20, 95 DUP (?)
BYK DW ?
-----------------------------------------------------------------------

BASLA   PROC NEAR
-----------------------------------------------------------------------
	//degisken sayisini Cx yazmacýna atarýz
	MOV CX, N
	//Cx yazmacýný 1 azaltýrýz
	DEC CX
	//Sý'yý 0 larýz
	XOR SI, SI
	//dizinin Sý indisindeki degeri Ax'e atarýz
	MOV AX, DIZI[SI]
	L1:
		//word oldugu için Sý'yý 2'ser 2'ser arttýrýrýz
		ADD SI, 2
		//dizinin ilk degeri ile ikinci degerini karsýlastýrýrýz
		CMP AX, DIZI[SI]
		//eger birinci degerimiz 2.degerimizden daha buyuk ise L2 yazmacýna gider
		JGE L2
			//eger 2.degerimiz 1.degerimizden buyuk ise o zaman da 2.degerimizi 1.degerine atarýz.ve buyuk varsaydýgýmýz deger artýk 2.degerimiz olur
			MOV AX, DIZI[SI]
		L2:
			//döngümüz CX kadar döner
	LOOP L1
	//dizinin en buyuk sayisi BYK degiskenine atanýr
	MOV BYK, AX
	
        RET
BASLA   ENDP
CODESG  ENDS
        END BILGI

