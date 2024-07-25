/*

harici karekök (sqroot) yordamýný kullanmak 

sqroot isimli harici yordamý kullanarak,5 word elemanlý dizinin elemanlarýnýn karekök degerlerini hesaplayýp yeni bir diziye yerleþtiren exe tipi assembly programýný yazalým.

*/

//akýs diyagramý yüksek seviye elementlerle hazýrlandýgý için sqroot yordamý cagrýldýgýnda içerisine parametre olarak verilen dizi[i] degerinin otomatik olarak yýðýna atýldýðý ve sqroot yordamýnýn geri dönüþünü ax yazmacý üzerinden yaptýgý akýþ diyagramýný tasarlarken
//bilinmektedir.
//asagida verilen program bu bilgiler ýþýgýnda yazýlmýþtýr.

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
