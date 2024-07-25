------------------------------------------------------------------------------------------------

   PROGRAM : Örnek 9-5.ASM
   10 elemanlý word olarak tanýmlanmýþ bir dizi içindeki en büyük 
   elemanýn bulunmasý için COM yapýsýnda bir program
------------------------------------------------------------------------------------------------

         	PAGE 60,80
         	TITLE En büyük elemanýn bulunmasý
CDSEG 		SEGMENT PARA 'CODE'
         	ORG 100H          ; COM program 100H den baþlar             
         	ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG
BASLA: 		JMP MAXI
------------------------------------------------------------------------------------------------

   ;Eleman sayýsý, Dizi elemanlarý ve Büyük sayý için gerekli deðiþkenler
------------------------------------------------------------------------------------------------

ELEMAN 		DW 10
DIZI     	DW -4,23,456,4,8,67,-78,9,-99,256
BYKSAY 		DW ?
------------------------------------------------------------------------------------------------

;iþleminin gerçekleþtirildiði yordam
------------------------------------------------------------------------------------------------

MAXI     PROC NEAR                 
------------------------------------------------------------------------------------------------
        //eleman sayisi cx e konur              
         MOV CX, ELEMAN       ;Eleman sayýsý CX'e yerleþtirildi
         //dizinin basýndaki deger sý adresine gider
         LEA SI, DIZI         ;Elemanlara eriþmek için SI indis olacak 
         //eleman sayisindan bir eksik karsýlastýrma yapýlacagý için cx 1 azaltýlýr
         DEC CX               ;Eleman sayýsýndan bir tane eksik iþlem yap 
         //ilk sayiyi buyuk kabul ederek onu ax e atarýz
         MOV AX, [SI]         ;ilk sayý büyük kabul edilerek AX'e konuyor 
         //bir sonraki indisli elemana erismek için Sý bir arttýrýrýz
CEVRIM: ADD SI, 2             ;bir sonraki indisli elemana eriþmek için (+2)
		//buyuk kobul ettigimiz elemanla ikinci elemaný karsýlastýrýrýz
         CMP AX, [SI]         ;sayýlarý karþýlaþtýrýyoruz
         //buyuk dedigimiz sayý sýradaki sayýdan buyukse devam etiketine gidip döngüyü döndürür
         JG DEVAM             ;AX büyük, bir sonraki eleman ile karþýlaþtýr 
         //eger sýradaki sayý buyuk dedigimiz sayidan buyukse bu seferde o sayiyi Ax e atýyýp buyuk dedigimiz sayý artýk o olur.
         MOV AX, [SI]         ;AX küçük, yeni sayýyý AX yazmacýna yerleþtir 
DEVAM: LOOP CEVRIM            ;iþlemý CX de belirlenen sayý kadar tekrarla 
         MOV BYKSAY, AX       ;AX yazmacýndaki deðeri BYKSAY'a yerleþtir. 
         RET                  ;dön
MAXI     ENDP
CDSEG ENDS
         END BASLA         ; programýn baþlangýç noktasý



---------------------------------------------------------------------------------------------------------------------------------
