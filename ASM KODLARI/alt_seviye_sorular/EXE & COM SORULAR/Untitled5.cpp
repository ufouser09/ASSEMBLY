------------------------------------------------------------------------------------------------
 
    PAGE 60,80
TITLE 	HEX digitleri ters yüz etme
SSEG 	SEGMENT PARA STACK 'STACK'
DW 		12 DUP(0)
SSEG 	ends
DSEG 	SEGMENT PARA 'DATA' 
  
	
------------------------------------------------------------------------------------------------
	
	;Dizi elemanlarý ve eleman sayýsý tanýmlanmýþtýr.
------------------------------------------------------------------------------------------------

     ELEMAN DW 10
     DIZI   DW 1234H,2345H,3456H,4567H,5678H,6789H,789AH,89ABH,9ABCH2OABCDH
     DSEG   ENDS
     CSEG   SEGMENT PARA 'CODE'
     ENDIAN PROC FAR
            ASSUME CS:CSEG,SS:SSEG, :DSEG
------------------------------------------------------------------------------------------------

    ;Dönüþ için gerekli olan degerler yýðýnda saklanýyor
------------------------------------------------------------------------------------------------

            PUSH DS 
            SUB AX, AX 
            PUSH AX
 ------------------------------------------------------------------------------------------------
                           
    ;DSEG ismiyle tanýmlý kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------------------

            MOV AX, DSEG 
            MOV DS, AX
------------------------------------------------------------------------------------------------

    ;Kontrol iþleminin gerçekleþtirildiði kod bloðu
------------------------------------------------------------------------------------------------
		//eleman sayisi Cx e atýlýr
            MOV CX,10           ; Eleman sayýsý CX'e yerleþtirildi
            //dizinin basýndaki eleman Sý adresine atanýr
            LEA SI, DIZI        ;Elemanlara eriþmek için SI indis olacak
            //adresteki eleman ax e atanýr
     CEVRIM:MOV AX,[SI]       	;Sayý üzerindeký iþlemi hýzlý yapabilmek için AX yazmacý üzerinden yapýyoruz
            //basýndaki ve sonundaki byte larý degistir                   	
            XCHG AL, AH        	;Düþük ve yüksek anlamlý byte'larý deðiþtir 
            //cx i stack e at cunku cx imiz degiscek birazdan
            PUSH CX             ;Tekrar sayýsýný belirleyen CX yazmaç deðerini yýðýnda sakla
            //cl ye 4 degerini ata                   
            MOV CL, 4          	;döndürme iþleminin tekrar sayýsý CL de
            //cl kadar yani 4 kere saga ötele al ve ah ý
            ROR AL, CL          ;AL ve AH deðerlerini kendi içlerinde CL ile belirlenen deðer kadar (4) saða döndür
       		ROR AH, CL         	
       		//ax üzerinde olusan yeni degeri yerine koy
            MOV [SI], AX       	;AX üzerinde oluþan yeni deðerý yerine koy 
            //indisi 1 arttýr
            ADD SI,1           	;SI'yý sonraki word'ü gösterecek biçimde ayarla 
            //Cx i stack ten çek
     		POP CX             	;Yýðýnda saklanan deðeri alarak iþleme devam et 
            LOOP CEVRIM        	;iþlemi CX de belirlenen sayý kadar tekrarla dön
            RET                	
     ENDIAN ENDP
	CSEG    ENDS
            END ENDIAN         ;programýn baþlangýç noktasý


