
	----------------------------------------------------------------------------------------------------------------

ortalama hesaplama
word tanýmlý bir dizide cift ve tek sayilarin ortalamalarýný ayrý ayrý bulan exe tipi assembly programýný yazýnýz;
	----------------------------------------------------------------------------------------------------------------

n=10--------------------------------->CX
dizi[n]={.....}--------------------->SI
cift_top=0-------------------->DX:AX
cift_say=0
tek_top=0------------------------>DX:AX
tek_say=0

for(i=1;i<n;i++)
if(dizi[i]mod 2==0)
tek_say++
tek_top+=dizi[i]
else{
	cift_say++
	cift_top+=dizi[i]
}


tek_ort=tek_top/tek_say---------------------->tek_ort->AX
cift_ort=cift_top/cift_say--------------------->cift_ort->AX

stop
			----------------------------------------------------------------------------------------------------------------


; Toplam iþlemi double word büyüklüðüne taþabileceðinden gerekli kontroller 
; yapýlmýþtýr.
			----------------------------------------------------------------------------------------------------------------


MY_SS   SEGMENT PARA STACK 'STACK'
        DW ZO DUP(?)
MY_SS   ENDS

MY_DS   SEGMENT PARA 'DATA'
DIZI    DW 7FFFH,7AB2H,70ABH,7111N,71FAH,7232H,7AF8H,78C6H,753DH,70E0H
N       DW 10
TEK_TOP DD 0
CIFT_TOP DD 0 
TEK_SAY DW 0 
CIFT_SAY DW 0 
TEK ORT DW ? 
CIFT_ORT DW ? 
MY_DS ENDS

MY_CS   SEGMENT PARA 'CODE'
        ASSUME DS:MY_DS, SS:MY_SS, CS:MY_CS 
ANA     PROC FAR
			----------------------------------------------------------------------------------------------------------------




                     PUSH DS
                     XOR AX, AX 
                     PUSH AX
          			----------------------------------------------------------------------------------------------------------------
           
					 MOV AX, MY_DS 
                     MOV DS, AX 
             		----------------------------------------------------------------------------------------------------------------
        			//Dizinin eleman sayisi CX yazmacýna atýlýr
                     MOV CX, N                      ; DIZI'nin eleman sayýsý CX'e konur 
                     //dizinin basýndaki eleman SI indisine atýlýr
					 LEA SI, DIZI                   ; DIZI'nin adresi SI'ya alýnýr.
           			//sý daki elaman ax e atýlýr
		   DON:      MOV AX, [SI]                   ; SI adresindeki bir word deðeri AX ; yazmacý içerisine alýnýr.
                    //Sayýnýn tek mi cift   mi olup  olmadýðýný kontrolol etmek için ; sayý, 1 ile mantýksal AND'lenir.                               
                     TEST AX, 0001H                 ; Sayýnýn tek mi cift   mi olup ; olmadýðýný kontrolol etmek için ; sayý, 1 ile mantýksal AND'lenir. ; Sonuç bayraklarda oluþur.ZF, 0  ; ise sayý çift, 1 ise tektir. 
                                                    
                                                    
                                                     
                                                   
                                        			 ; TEST iþlemi sonucunda Zero Flag ; (ZF), 0 ise C_LABEL etiketine ; atlanýr.
                                                    
                                                    
                	 ADO WORD PTR [TEK_TOP], AX     ; 2 word sayýnýn toplamý doubleword ; olabileceði için AX ile DD ; tanýmlý TEK_TOP deðiþkeninin ; duþuk anlamlý word u toplanýr.
                                                    
                                                    
                     //Toplam sonucunda elde oluþmuþsa, o da TEK_TOP deðiþkeninin yüksek  anlamlý word ile toplanýr                               
                     ADC WORD PTR [TEK_TOP+2], 0    ; Toplam sonucunda elde oluþmuþsa, ; o da TEK_TOP deðiþkeninin yüksek  ; anlamlý word ile toplanýr.
                                                    
                                                   
                     INC TEK_SAY                    ; TEK_SAY deðiþkeni 1 arttýrýlýr. 
                     jMP ARTIR                      ; ARTIR etiketine atlanýr.
           C_LABEL: ADD WORD PTR [CIFT_TOP], AX     ; AX cift ise bu satýra gelinmiþtir 
                                                    ; DD tanýmlý CIFT_TOP deðiskeninin ; düþük anlamlý word'ü ile AX ; deðeri toplanýr.
                                                    
                                                    
                     ADC WORD PTR [CIFT_TOP+2], 0   ; Toplam sonucunda elde oluþmuþsa, ; o da CIFT_TOP deðiþkeninin yüksek ; anlamlý word ile toplanýr.
                                                    
                                                    
                     INC CIFT_SAY                   ; CIFT_SAY deðiþkeni 1 arttýrýlýr. 
           ARTIR:    ADD SI, 2                      ; DIZI word tanýmlý olduðu için SI ; 2 arttýrýldý.
                                                    
                     LOOP DON                       ; Cevrim iþlemleri CX kez  ; tekrarlanýr.
                                                   
                     MOV DX, WORD PTR [CIFT_TOP+2]  ; 32-bit bölme iþlemi için CIFT_TOP ; deðiþkeninin yüksek anlamlý kýsmý ; DX içerisine alýnýr.
                                                    
                                                    
                     MOV AX, WORD PTR [CIFT_TOP]    ; Düþük anlamlý kýsým ise AX içerisine alýnýr.
                                                    
                     DIV CIFT_SAY                   : DX:AX / CIFT_SAY -> Bölüm: AX,; Kalan: DX iþlemi gerçekleþtirilir 
                                                    
                     MOV CIFT_ORT, AX               ; AX'e oluþan çift sayýlarýn ; ortalamasý CIFT_ORT içerisine  atýlýr.
                                                    
                                                   
                     MOV DX, WORD PTR [TEK_TOP+2] ; ÇIFT SAYILAR IÇIN YAPILAN
                     MOV AX, WORD PTR [TEK_TOP]    ; IÞLEMLER TEK SAYILAR IÇIN DE 
                     DýV TEK_SAY                    ; YAPILARAK TEK_ORT DEGERI
                     MOV TEK_ORT, AX               ; BULUNUR.
                     RETF
           ANA       ENDP
           MY_CS     ENDS
                     END ANA


