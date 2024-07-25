------------------------------------------------------------------------------------------------

         	PAGE 60,80
         	TITLE 32 BITLIK POZITIF IKI SAYININ TOPLANMASI     
------------------------------------------------------------------------------------------------
			     
STACKSG 	SEGMENT PARA STACK 'STACK'
         	DW 10 DUP(?)
STACKSG 	ENDS                                               
DATASG 		SEGMENT PARA 'DATA'                               
ASAYISI 	DD       12345678H                              
BSAYISI 	DD       9ABCDEFOH                              
TOPLAM 		DQ        OH
DATASG 		ENDS
CODESG 		SEGMENT PARA 'CODE'                           
         	ASSUME CS:CODESG, DS:DATASG, SS:STACKSG
ANA      	PROC FAR
------------------------------------------------------------------------------------------------

  ;D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------------------

         PUSH DS
         SUB AX, AX 
         PUSH AX
------------------------------------------------------------------------------------------------

; DATASG ismiyle tan�ml� kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------------------

         MOV AX, DATASG
         MOV DS, AX             
------------------------------------------------------------------------------------------------

; Toplama i�leminin ger�ekle�tirildi�i kod blo�u
------------------------------------------------------------------------------------------------
		//a sayisinin baslad�g� adresi S� ya atars�n
         LEA SI, ASAYISI      ; Say�larla bir seferde 64 bit toplama yap�lmad��� i�in 16 bit'lik par�alar halinde okunacakt�r
         //b sayisinin baslad�g� adresi D� ya atars�n
         LEA DI, BSAYISI
		 //toplam degiskenin baslad�g� adresi Bx e atars�n      
         LEA BX, TOPLAM       ; Bu nedenle say�lara SI/DI/BX Yazma�lar� yard�m�yla eri�ilecektir.
        //Ax yazmac�na A sayisinin en dusuk anlaml� wordunu atar�z	                  
         MOV AX, [SI]         ;AX yazmac�na ASAYISI'n�n d���k anlaml� word'�
         //Dx yazmac�na B sayisinin en dusuk anlaml� wordunu atar�z
         MOV DX, [DI]         ;DX yazmac�na BSAYISI'n�n d���k anlaml� word'�
         //sonra ax ile dx i toplar�z
         ADD AX, DX
         //buldugumuz toplam� toplam�n adresine atar�z
         MOV [BX],AX            ; Elde edilen TOPLAM'�n d���k anlaml� word'�ne
         //Ax yazmac�na a n�n dusuk anlaml� wordunu atar�z
         MOV AX, [SI+2]       	;AX yazmac�na ASAYISI'n�n y�ksek anlaml� word'�
         //Dx yazmac�na B Say�s�n�n dusuk anlaml� wordunu
         MOV DX,[DI+2]       	;DX yazmac�na BSAYISI'n�n y�ksek anlaml� word'�
         //A ve B sayisini tekrar topluyoruz ama bu sefer �nceki toplamadan gelen eldeyi de isleme sokuyoruz
         ADC AX,DX             	;Eldeyi de i�leme d�hil ediyoruz ve sonucu
         //buldugumuz toplam� toplam'a at�yoruz
         MOV [BX+2], AX     	;TOPLAM de�i�kenine yaz�yoruz
         //elde olusmussa da bunu en son Bx+4 adresine at�yoruz.
         ADC WORD PTR [BX+4], 0
                            ; iki say�n�n 32 bit toplam�nda elde olu�mu� ise 
                            ; bu de�eri TOPLAM de�i�keninin y�ksek anlaml�
                         	; DWord alan�na aktarabilmek i�in eldeli toplama 
                            ; i�lemi yap�yoruz.
      		RET 
ANA  		ENDP
CODESG		ENDS
     		END     ANA        ; program�n ba�lang�� noktas�


