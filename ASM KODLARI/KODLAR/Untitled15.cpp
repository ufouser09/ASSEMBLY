/*

harici karek�k (sqroot) yordam�n� kullanmak 

sqroot isimli harici yordam� kullanarak,5 word elemanl� dizinin elemanlar�n�n karek�k degerlerini hesaplay�p yeni bir diziye yerle�tiren exe tipi assembly program�n� yazal�m.

*/

//ak�s diyagram� y�ksek seviye elementlerle haz�rland�g� i�in sqroot yordam� cagr�ld�g�nda i�erisine parametre olarak verilen dizi[i] degerinin otomatik olarak y���na at�ld��� ve sqroot yordam�n�n geri d�n���n� ax yazmac� �zerinden yapt�g� ak�� diyagram�n� tasarlarken
//bilinmektedir.
//asagida verilen program bu bilgiler ���g�nda yaz�lm��t�r.

EXTRN SQROOT:FAR
MYSS SEGMENT PARA STACK 'STACK'
DW 12 DUP(?)
MYSS ENDS
MYDS SEGMENT PARA 'DATA'
DIZI DW 16,2,4,8,9
KOK DW 5 DUP(?)
ELEMAN DW 5
MYDS ENDS 
MYCD SEGMENT PARA 'CODE'

ASSUME CS:MYCD,SS:MYSS,DS:MYDS
MAIN PROC FAR
PUSH DS
XOR AX,AX
PUSH AX
MOV AX,MYDS
MOV DS,AX
MOV CX,ELEMAN
XOR SI,SI
L1:PUSH DIZI[SI]
CALL SQROOT
MOV KOK[SI],AX
ADD SI,2
LOOP L1
RET
MAIN ENDP
MYCD ENDS
END MAIN
