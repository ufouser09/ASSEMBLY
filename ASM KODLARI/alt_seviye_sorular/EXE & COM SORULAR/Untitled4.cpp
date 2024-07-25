program ornek 9.3 asm
10 elemanlý bir dizideki tek ve cift sayilarin adedini bulan program
bu programda test komutu kullanýlmýstýr
------------------------------------------------------------------------------------------------

 PAGE 60,80
TITLE 	tek CÝFT/shift kullanarak
SSEG 	SEGMENT PARA STACK 'STACK'
DW 		12 DUP(0)
SSEG 	ends
DSEG 	SEGMENT PARA 'DATA' 
  
  Deðiþken tanýmlarý

DIZI    DW 10,21,43,71,199,67,88,234,0,467
ELEMAN 	DW 10 
TEK_S 	DW 0 
CIFT_S 	DW 0
DSEG    ENDS
CSEG    SEGMENT PARA 'CODE'
TC      PROC   FAR
        ASSUME CS:CSEG, SS:SSEG, DS:DSEG
------------------------------------------------------------------------------------------------

; Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------------------

        PUSH DS
        XOR AX, AX          •
        PUSH AX
------------------------------------------------------------------------------------------------

; DSEG ismiyle tanýmlý kesim  alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------------------

        MOV AX, DSEG  •
        MOV DS, AX
------------------------------------------------------------------------------------------------

; Kontrol iþlemini  gerçekleþtirildiði kod bloðu
------------------------------------------------------------------------------------------------
		//eleman sayisi cx e atýlýr
        MOV CX,ELEMAN       				;Çevrim deðiþkenine eleman sayýsý konur
        //dizinin basýndaki deger Sý adresine gider
        LEA SI,DIZI            				;DIZI'nin baþlangýç adresi SI yazmacýnda
        //Test komutu 0001 le and ler sonuc 0 ise sayi çift 1 ise sayi tektir
CEVRIM: TEST WORD PTR [SI], 0001H
        //sonuc 0 ise çift adresine git                  					;TEST komutu iþlenenleri bozmaz
        JZ cýft           					;Sonuç sýfýr ise sayý çifttir ilgili satýra git 
        //0 degilse tek sayi adedini arttýr
TEK:    INC TEK_S         					;sayý tekdir, tek sayý adedini arttýr
		//bir sonraki elemana erismek için Sý bir artar
CIFT:   ADD SI, 2        					; bir sonraki elemana eriþmek için SI arttýrýlýr 
                        					; DIZI word tanýmlý olduðu için bir sonraki dizi elemaný 2 byte ileride olacaktýr.
        //dongu doner                					
     	LOOP CEVRIM      					; iþlemi dizinin son elemanýna gelinceye kadar tekrarlamayý saðlayan çevrim komutu
        //donguden sonra Ax e eleman sayisi konur             						
   		MOV AX, ELEMAN     					; çevrim sonucunda sadece tek olan kaç tane eleman olduðunu biliyoruz. ELEMAN sayýsýndan çýkartýr 
        //eleman sayisindan Tek sayilari da çýkartýrsan çift sayilari elde edersin                					
  		SUB AX, TEK_S   					; böylece kalanlarýn çift olduðunu bulabiliriz
        MOV CIFT_S, AX  					; bulduðumuz deðeri tanýmlý deðiþkene yaz
        RET
TC      ENDP
CSEG    ENDS
        END TC          					; programýn baþlangýç noktasý


