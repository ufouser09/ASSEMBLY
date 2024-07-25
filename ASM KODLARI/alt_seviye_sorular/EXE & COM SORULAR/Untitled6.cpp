------------------------------------------------------------------------------------------------

   PROGRAM : �rnek 9-5.ASM
   10 elemanl� word olarak tan�mlanm�� bir dizi i�indeki en b�y�k 
   eleman�n bulunmas� i�in COM yap�s�nda bir program
------------------------------------------------------------------------------------------------

         	PAGE 60,80
         	TITLE En b�y�k eleman�n bulunmas�
CDSEG 		SEGMENT PARA 'CODE'
         	ORG 100H          ; COM program 100H den ba�lar             
         	ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG
BASLA: 		JMP MAXI
------------------------------------------------------------------------------------------------

   ;Eleman say�s�, Dizi elemanlar� ve B�y�k say� i�in gerekli de�i�kenler
------------------------------------------------------------------------------------------------

ELEMAN 		DW 10
DIZI     	DW -4,23,456,4,8,67,-78,9,-99,256
BYKSAY 		DW ?
------------------------------------------------------------------------------------------------

;i�leminin ger�ekle�tirildi�i yordam
------------------------------------------------------------------------------------------------

MAXI     PROC NEAR                 
------------------------------------------------------------------------------------------------
        //eleman sayisi cx e konur              
         MOV CX, ELEMAN       ;Eleman say�s� CX'e yerle�tirildi
         //dizinin bas�ndaki deger s� adresine gider
         LEA SI, DIZI         ;Elemanlara eri�mek i�in SI indis olacak 
         //eleman sayisindan bir eksik kars�last�rma yap�lacag� i�in cx 1 azalt�l�r
         DEC CX               ;Eleman say�s�ndan bir tane eksik i�lem yap 
         //ilk sayiyi buyuk kabul ederek onu ax e atar�z
         MOV AX, [SI]         ;ilk say� b�y�k kabul edilerek AX'e konuyor 
         //bir sonraki indisli elemana erismek i�in S� bir artt�r�r�z
CEVRIM: ADD SI, 2             ;bir sonraki indisli elemana eri�mek i�in (+2)
		//buyuk kobul ettigimiz elemanla ikinci eleman� kars�last�r�r�z
         CMP AX, [SI]         ;say�lar� kar��la�t�r�yoruz
         //buyuk dedigimiz say� s�radaki say�dan buyukse devam etiketine gidip d�ng�y� d�nd�r�r
         JG DEVAM             ;AX b�y�k, bir sonraki eleman ile kar��la�t�r 
         //eger s�radaki say� buyuk dedigimiz sayidan buyukse bu seferde o sayiyi Ax e at�y�p buyuk dedigimiz say� art�k o olur.
         MOV AX, [SI]         ;AX k���k, yeni say�y� AX yazmac�na yerle�tir 
DEVAM: LOOP CEVRIM            ;i�lem� CX de belirlenen say� kadar tekrarla 
         MOV BYKSAY, AX       ;AX yazmac�ndaki de�eri BYKSAY'a yerle�tir. 
         RET                  ;d�n
MAXI     ENDP
CDSEG ENDS
         END BASLA         ; program�n ba�lang�� noktas�



---------------------------------------------------------------------------------------------------------------------------------
