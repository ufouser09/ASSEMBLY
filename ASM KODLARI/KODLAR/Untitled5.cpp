//D�Z�N�N SIRALI OLUP OLMADIGININ KONTROLU

MOV BX,0
XOR SI,SI
MOV CX,N
DEC CX
DON:CMP BX,0
JNE SON_IF
CMP SI,CX
JGE SON_IF
MOV AL,DIZI[SI]
CMP AL,DIZI[SI+1]

JLE ARTTIR
MOV BX,1
ARTTIR:INC SI
JMP DON
SON_IF:CMP BX,0
JNE SIRASIZ
MOV S,1
JMP SON
SIRASIZ:MOV S,0

SON RETF
ANA ENDP
MYCS ENDS
END ANA
