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

  ;Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------------------

         PUSH DS
         SUB AX, AX 
         PUSH AX
------------------------------------------------------------------------------------------------

; DATASG ismiyle tanýmlý kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------------------

         MOV AX, DATASG
         MOV DS, AX             
------------------------------------------------------------------------------------------------

; Toplama iþleminin gerçekleþtirildiði kod bloðu
------------------------------------------------------------------------------------------------
		//a sayisinin basladýgý adresi Sý ya atarsýn
         LEA SI, ASAYISI      ; Sayýlarla bir seferde 64 bit toplama yapýlmadýðý için 16 bit'lik parçalar halinde okunacaktýr
         //b sayisinin basladýgý adresi Dý ya atarsýn
         LEA DI, BSAYISI
		 //toplam degiskenin basladýgý adresi Bx e atarsýn      
         LEA BX, TOPLAM       ; Bu nedenle sayýlara SI/DI/BX Yazmaçlarý yardýmýyla eriþilecektir.
        //Ax yazmacýna A sayisinin en dusuk anlamlý wordunu atarýz	                  
         MOV AX, [SI]         ;AX yazmacýna ASAYISI'nýn düþük anlamlý word'ü
         //Dx yazmacýna B sayisinin en dusuk anlamlý wordunu atarýz
         MOV DX, [DI]         ;DX yazmacýna BSAYISI'nýn düþük anlamlý word'ü
         //sonra ax ile dx i toplarýz
         ADD AX, DX
         //buldugumuz toplamý toplamýn adresine atarýz
         MOV [BX],AX            ; Elde edilen TOPLAM'ýn düþük anlamlý word'üne
         //Ax yazmacýna a nýn dusuk anlamlý wordunu atarýz
         MOV AX, [SI+2]       	;AX yazmacýna ASAYISI'nýn yüksek anlamlý word'ü
         //Dx yazmacýna B Sayýsýnýn dusuk anlamlý wordunu
         MOV DX,[DI+2]       	;DX yazmacýna BSAYISI'nýn yüksek anlamlý word'ü
         //A ve B sayisini tekrar topluyoruz ama bu sefer önceki toplamadan gelen eldeyi de isleme sokuyoruz
         ADC AX,DX             	;Eldeyi de iþleme dâhil ediyoruz ve sonucu
         //buldugumuz toplamý toplam'a atýyoruz
         MOV [BX+2], AX     	;TOPLAM deðiþkenine yazýyoruz
         //elde olusmussa da bunu en son Bx+4 adresine atýyoruz.
         ADC WORD PTR [BX+4], 0
                            ; iki sayýnýn 32 bit toplamýnda elde oluþmuþ ise 
                            ; bu deðeri TOPLAM deðiþkeninin yüksek anlamlý
                         	; DWord alanýna aktarabilmek için eldeli toplama 
                            ; iþlemi yapýyoruz.
      		RET 
ANA  		ENDP
CODESG		ENDS
     		END     ANA        ; programýn baþlangýç noktasý


