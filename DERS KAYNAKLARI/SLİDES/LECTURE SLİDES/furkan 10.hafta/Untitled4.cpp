		INCLUDE 091221.mac
cseg	SEGMENT PARA 'tum'
		ORG 100h
		ASSUME CS:cseg, DS:cseg, SS:cseg
		ANA		PROC FAR
--------------------------------------------------------------------------------
		//sý indisi 0 lanýr		
		XOR SI, SI
		//N degiskeni Cx yazmacýna atanýr
		MOV CX, n
		//dizinin Sý indisindeki deger 1 saga SAR'lanýr bu da 2 ye bolme manasýna gelir
L1:		SAR dizi[SI], 1
		//Sý degiskeni 1 arttýrýrýz
		INC SI
		//dongü döner
		LOOP L1
		ENKCK dizi, n
		MOV kck, AL
		RET
ANA		ENDP
dizi	DB 10, -2, 4, 5, 10, 3, 5, 17
n		DW 8
kck		DB ?
cseg	ENDS
		END ANA
