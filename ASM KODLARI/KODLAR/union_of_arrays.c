//A �irketinde �al��anlar�n dogum yili d1 dizisinde B �irketinde calisanlarin yaslari d2 dizisinde tutulmaktad�r.
//once A �irketinde �al��an a1 ki�inin ,sonra B �irketinde �al��an b2 ki�inin bu bilgileri boyutu a1+b1 olan d3 dizisine aktarmak i�in gerekli olan asm kodunu yaz�n�z

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
