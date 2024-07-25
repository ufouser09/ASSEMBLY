//A þirketinde çalýþanlarýn dogum yili d1 dizisinde B þirketinde calisanlarin yaslari d2 dizisinde tutulmaktadýr.
//once A þirketinde çalýþan a1 kiþinin ,sonra B þirketinde çalýþan b2 kiþinin bu bilgileri boyutu a1+b1 olan d3 dizisine aktarmak için gerekli olan asm kodunu yazýnýz

	LEA DI,d1
	LEA SI,d2
	XOR BX,BX

	MOV CX,a1
L1:MOV AX,[DI]
	MOV d3[BX],AX
	
	ADD DI,2
	ADD BX,2
	LOOP L1
	
	MOV CX,b1
L2:MOV AL,[SI]
	CBW
	MOV d3[BX],AX
	ADD BX,2
	INC SI
	LOOP L2
