/*
karekök hesabý-sqroot(harici yordam)

verilen pozitif bir tam sayýnýn karekökünü hesaplamak için sayýdan sýrasý ile 1,3,5,... gibi tek sayilar çýkartýlarak sonuc sýfýrdan kucuk cýkana kadar iþleme devam ediliyor.
gerçekleþtirilen iþlem sayisi verilen sayýnýn karekök degerini(tam sayi olarak)verir.
karekök alma iþlemini gerçekleþtiren harici yordamýn assembly programýný yazalým.

*/

//BU PROGRAM YIGIN ÜZERÝNDEN 1 WORD OLARAK ALDIGI PARAMETRENÝN KAREKÖK DEGERÝNÝ AX YAZMACI ÜZERÝNDEN DÖNDÜRÜR
//YIGINDAKÝ PARAMETREYÝ KALDIRIR.

PUBLÝC SQROOT
MYCODE SEGMENT PARA CODE
ASSUME CS:MYCODE
SQROOT PROC FAR
PUSH DX
PUSH BX
PUSH BP
MOV BP,SP
MOV DX,1
XOR AX,AX
MOV BX,[BP+10]
SUB BX,DX
L1:JL SON
INC AX
ADD DX,2
SUB BX,DX
JMP L1
SON:POP BP
POP BX
POP DX
RET 2
SQROOTENDP
MYCODE ENDS
END
