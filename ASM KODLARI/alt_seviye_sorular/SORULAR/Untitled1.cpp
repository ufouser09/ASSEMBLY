------------------------------------------------------------------------------------
  
  PROGRAM : �rnek 10-1.ASM
  Kesim i�indeki yordam� �a��ran EXE tipinde program
------------------------------------------------------------------------------------
         PAGE 60,80                                           
         TITLE Sayinin kuvvetini hesaplar                   
STACKSG SEGMENT PARA STACK 'STACK'                         
         DW 10 DUP(?)                                      
STACKSG ENDS 
DATASG SEGMENT PARA 'DATA'                            
                             
------------------------------------------------------------------------------------

------------------------------------------------------------------------------------

 ;Kullanaca��m�z de�i�kenler
------------------------------------------------------------------------------------

SAYI  DW 2
UST   DW 10                      
SONUC DW 0 
DATASG ENDS
CODESG SEGMENT PARA 'CODE'
      ASSUME CS:CODESG, DS:DATASG, SS:STACKSG 
ANA   PROC FAR
------------------------------------------------------------------------------------

 ;D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------

      PUSH DS 
      SUB AX, AX 
      PUSH AX         
------------------------------------------------------------------------------------

 ;DATASG ismiyle tan�ml� kezl��i alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------

      MOV AX, DATASG
      MOV DS, AX  
------------------------------------------------------------------------------------

 ;i�leminin ger�ekle�tirildi�i kod blo�u
------------------------------------------------------------------------------------

      MOV CX, UST  ;UST ve SAYI parametreleri yazma�larda
      MOV BX, SAYI
      CALL USTAL     ; Yordam �a��rma
      MOV SONU� AX ; I�lemin sonucu AX yazmac� �zerinden aktar�l�yor 
      RET       ; d�n
ANA   ENDP
------------------------------------------------------------------------------------

; �st alma islemini ger�ekle�tiren yordam
------------------------------------------------------------------------------------

USTAL PROC NEAR 
    	MOV AX, 1 
Ll:   	MUL   BX       ; �arpma i�lemi AX �zerinden yap�l�yor 
    	LOOP L1
  		RET        ; �a��r�ld���n noktaya d�n
USTAL ENDP
CODESG ENDS
      END ANA     ; program�n ba�lang�� noktas�
------------------------------------------------------------------------------------
//ASSEMBLY PROGRAMIN TEMEL TASLARI:YORDAM VE MAKRO
//her program i�erisinde en az bir tane ana yordam olmas� gerekti�ini vurgulad�k


//YORDAM �ZELL�KLER�
yordam PROC s�zde komutu ile baslay�p ENDP s�zde komutu ile sonlanan bir �ekilde tan�mlanmaktad�r
yordamlar�n ayn� kesim i�inden(intraSegment) ve farkli kesim i�erisinden(intersegment)kullanabilmeleri i�in s�ras�yla NEAR ve FAR olarak tan�mlanmalar� gerekmektedir.
yordamlar�n �a�r�ld�klar� yere donebilmeleri i�in en son komut olarak RET(near tan�ml� yordamlarda) veya RETF (FAR tan�ml� yordamlarda)kullan�lmaktad�r.
ancak ASSEMBLY dili derleyicisi FAR olarak tan�ml� yordamlar RET ile sonland�r�lsa bile bunu RETF oalrak degerlendirecek ve gerekli duzenlemeleri kendi i�inde gerceklestirecektir.
bu nedenle yordam tan�m��n�n ne olduguna bak�lmaks�z�n RET ile yordam�n sonland�r�lmas� bir al�skanl�k olmustur.


//yordam tan�m� en genel sekli asag�da g�sterilmistir.

yordam_ismi    PROC{NEAR|FAR}
				;yordam�n kodu
				RET
yordam ismi     ENDP


//KES�M ��� YORDAM CAGIRMA
//kesim i�i yordam cag�rma(intrasegment call) olarak adland�r�lan bu tip kullan�mda ca��ran ve cagr�lan ayn� kesim i�inde yer al�r.
//bunu �rnek �zerinden inceleyebilmek i�in ayn� kesim i�inde tan�mlanm�s iki yordam sah�p oldugumuzu,bunlardan ANA isimli olan�n ilk olarak �al�st�r�lan(yani kontrolu el�nde bulunduran yordam)oldugunu,
//USTAL isimli olan�n ise ANA taraf�ndan cagr�lan ve NEAR olarak tan�mlanm�s bir yordam oldugunu dusunelim.


cdseg		segment para 'CODE'
ustal		proc near**//2-buraya gelir
			mov ax,1
			mul bx
			loop l1
			ret//3-sonra burdaki kodu isledikten sonra
ustal		endp
ANA 		proc far
			
			....
			mov cx,ust
			mov bx,sayi
			call ustal**//1-bu proc near'a gider
			mov sonuc,ax//4-kod buradan devam eder
			
			.....
			ret
ana			endp
cdseg		ends
			end ana


//KES�M ���NDEK� YORDAMIN CAGRILMASI(intrasegment call)
//cagr�lan yordam sayinin ust ile belirlenen kuvvetini hesaplayan islemini yapmakta ve call ustal komutu yard�m�yla cagr�lmaktad�r.cag�rma islemiyle program�n ak�s� ustal �s�ml� yordam�n oldugu adrese aktar�lmakta(1)
//islemler gerceklestirildikten sonra (2) ret komutunun cal�st�r�lmas�yla birlikte cag�rma isleminin yap�ld�g� kod parcas� i�inde yer alan ve call komutunu takip eden sat�ra geri d�n�lmektedir.boylece ana isimli yordam�n kald�g� noktadan islemlere devam edebilmesini saglamaktad�r(3)
//kesim i�i cag�rma isleminin gerceklesmesi siras�nda bize dogrudan islem olarak g�r�nmeyen,daha dogrusu kullan�lan call komutunun gereg� olarak otomat�k olarak yerine getirilen baz� ara islemler de vard�r.bu islemlerin neler oldugunu ve ne amacla yap�ld�g�n� maddeler halinde ac�klayal�m
.
.
.
.
.
.
------------------------------------------------------------------------------------
//yordam�n ayn� program i�inde birden fazla yerde �a�r�lmas� durumundaki ak�� incelendiginde her cag�rmada kontrolun dogrudan ustal �s�ml� yordam�n oldugu adrese aktar�ld�g�,
//islemler�n tamamlanmas�na takiben ret komutu ile geri donuldugu g�r�l�r.bu sayde yordamlar kac kere �a�r�l�rsa �agr�ls�n hep ayn� adresten cal�st�r�ld�klar� �c�n program�n kodu buyumez.

//ancak her cag�rma islemi geri donebilmek i�in gerekli adreslerin y�g�na at�lmas�,kontrolun aktar�lacag� g�reli konum degerinin �p yazmac�na atanmas� ve islemin bitimini takiben donus i�in gerekli adres degerinin y�g�ndan cekilmesi gibi islemleri de i�ermesi nedeniyle ister istemez belli bir gecikmeye neden olur. 
.
.
.
.
.
.
.
.
.
.
------------------------------------------------------------------------------------

//AYNI YORDAMIN KOD ���NDE B�RDEN FAZLA YERDE CAGRILMASI
kesim i�i yordam kullan�m� konusundaki bilgilerimizi pekistirmek i�in ve durumu cal�san program parcalar� uzerinden incelemek �zere ornek 10-1'den yararlanal�m

//�RNEK 10-1
sekil 10-1'de verilen ve bir sayinin kuvvetini almay� saglayan USTAL isimli yordam� EXE tipinde bir program i�inde kullanal�m.
ustal isimli yordam giris verilerini 
BX ve CX yazmaclar� uzerinden almakta islem sonucunda hesaplanan degeri ise AX yazmac� �zerinde tutmaktad�r.
�st almak i�in carpma isleminden yararlan�lacakt�r.

program�m�zdaki SAY�,UST ve SONUC isimli degiskenler word olarak tan�mlanm�st�r.
burada SAY� ve UST degerleri buyuk secilecek olursa elde edilecek deger SONUC isimli degiskene s�gmayacak kadar buyuk olacakt�r.
buna g�re,program�m�z� test ederken giris degerlerini �zenle secmek gerekecektir






