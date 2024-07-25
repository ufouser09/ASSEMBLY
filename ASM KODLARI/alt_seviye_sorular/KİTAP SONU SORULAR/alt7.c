
	----------------------------------------------------------------------------------------------------------------

ortalama hesaplama
word tan�ml� bir dizide cift ve tek sayilarin ortalamalar�n� ayr� ayr� bulan exe tipi assembly program�n� yaz�n�z;
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


; Toplam i�lemi double word b�y�kl���ne ta�abilece�inden gerekli kontroller 
; yap�lm��t�r.
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
        			//Dizinin eleman sayisi CX yazmac�na at�l�r
                     MOV CX, N                      ; DIZI'nin eleman say�s� CX'e konur 
                     //dizinin bas�ndaki eleman SI indisine at�l�r
					 LEA SI, DIZI                   ; DIZI'nin adresi SI'ya al�n�r.
           			//s� daki elaman ax e at�l�r
		   DON:      MOV AX, [SI]                   ; SI adresindeki bir word de�eri AX ; yazmac� i�erisine al�n�r.
                    //Say�n�n tek mi cift   mi olup  olmad���n� kontrolol etmek i�in ; say�, 1 ile mant�ksal AND'lenir.                               
                     TEST AX, 0001H                 ; Say�n�n tek mi cift   mi olup ; olmad���n� kontrolol etmek i�in ; say�, 1 ile mant�ksal AND'lenir. ; Sonu� bayraklarda olu�ur.ZF, 0  ; ise say� �ift, 1 ise tektir. 
                                                    
                                                    
                                                     
                                                   
                                        			 ; TEST i�lemi sonucunda Zero Flag ; (ZF), 0 ise C_LABEL etiketine ; atlan�r.
                                                    
                                                    
                	 ADO WORD PTR [TEK_TOP], AX     ; 2 word say�n�n toplam� doubleword ; olabilece�i i�in AX ile DD ; tan�ml� TEK_TOP de�i�keninin ; du�uk anlaml� word u toplan�r.
                                                    
                                                    
                     //Toplam sonucunda elde olu�mu�sa, o da TEK_TOP de�i�keninin y�ksek  anlaml� word ile toplan�r                               
                     ADC WORD PTR [TEK_TOP+2], 0    ; Toplam sonucunda elde olu�mu�sa, ; o da TEK_TOP de�i�keninin y�ksek  ; anlaml� word ile toplan�r.
                                                    
                                                   
                     INC TEK_SAY                    ; TEK_SAY de�i�keni 1 artt�r�l�r. 
                     jMP ARTIR                      ; ARTIR etiketine atlan�r.
           C_LABEL: ADD WORD PTR [CIFT_TOP], AX     ; AX cift ise bu sat�ra gelinmi�tir 
                                                    ; DD tan�ml� CIFT_TOP de�iskeninin ; d���k anlaml� word'� ile AX ; de�eri toplan�r.
                                                    
                                                    
                     ADC WORD PTR [CIFT_TOP+2], 0   ; Toplam sonucunda elde olu�mu�sa, ; o da CIFT_TOP de�i�keninin y�ksek ; anlaml� word ile toplan�r.
                                                    
                                                    
                     INC CIFT_SAY                   ; CIFT_SAY de�i�keni 1 artt�r�l�r. 
           ARTIR:    ADD SI, 2                      ; DIZI word tan�ml� oldu�u i�in SI ; 2 artt�r�ld�.
                                                    
                     LOOP DON                       ; Cevrim i�lemleri CX kez  ; tekrarlan�r.
                                                   
                     MOV DX, WORD PTR [CIFT_TOP+2]  ; 32-bit b�lme i�lemi i�in CIFT_TOP ; de�i�keninin y�ksek anlaml� k�sm� ; DX i�erisine al�n�r.
                                                    
                                                    
                     MOV AX, WORD PTR [CIFT_TOP]    ; D���k anlaml� k�s�m ise AX i�erisine al�n�r.
                                                    
                     DIV CIFT_SAY                   : DX:AX / CIFT_SAY -> B�l�m: AX,; Kalan: DX i�lemi ger�ekle�tirilir 
                                                    
                     MOV CIFT_ORT, AX               ; AX'e olu�an �ift say�lar�n ; ortalamas� CIFT_ORT i�erisine  at�l�r.
                                                    
                                                   
                     MOV DX, WORD PTR [TEK_TOP+2] ; �IFT SAYILAR I�IN YAPILAN
                     MOV AX, WORD PTR [TEK_TOP]    ; I�LEMLER TEK SAYILAR I�IN DE 
                     D�V TEK_SAY                    ; YAPILARAK TEK_ORT DEGERI
                     MOV TEK_ORT, AX               ; BULUNUR.
                     RETF
           ANA       ENDP
           MY_CS     ENDS
                     END ANA


