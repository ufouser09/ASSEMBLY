//alt seviye programlama dersinin yil sonu notlar� hesaplanmaktadir.esik degerin alt�nda notu alan ogrencilerin basarisiz,esik degerin ustunde notu olan ogrencilerin not ortalamas� hesaplanir ve ortalama alt�nda kalan ogrenciler butunlemeye girmeye hak kazan�r.
//ortalaman�n ustundeki ogrenciler ise derstten basarili olur.280 kisinin ald�g� derstten basarili basarisiz ve butunlemeye kalan ogrencilerin sayisini bulunuz
mystack SEGMENT PARA STACK 'y'
DW 20 DUP(?)
mystack ENDS

myds SEGMENT PARA 'v'
n DW 280
kalan DW 0
but DW 0
basarili DW 0
topNOT DW 0
esik DB 40
notlar DB 280 DUP(?)
myds ENDS
mycs SEGMENT 'k'
ASSUME cs:mycs,ss:mystack,ds:myds
ANA PROC FAR

PUSH DS
XOR AX,AX
PUSH AX
MOV AX,MYDS
MOV DS,AX

	XOR SI,SI
	MOV CX,N
L1:MOV AL,NOTLAR[SI]
	CMP AL,ES�K
	JAE ES�KUSTU
	INC KALAN
	JMP D1
	ES�KUSTU: CBW
	ADD TOPNOT,AX
D1:INC SI
	LOOP L1
	MOV CX,N
	SUB CX,KALAN
	XOR DX,DX
	MOV AX,TOPNOT
	DIV CX
	XOR SI,SI
	MOV CX,N
L2:MOV AH,NOTLAR[SI]
	CMP AL,AH
	JBE GECT�
	CMP AH,ES�K
	JB KALD�
	INC BUT
	JMP KALDI
GECT�:INC BASARILI
KALDI:INC SI
	LOOP L2
	RETF
	CAN ENDP
	MYCS ENDS
	END CAN
