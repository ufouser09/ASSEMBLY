------------------------------------------------------------------------------------

; PROGRAM : �rnek 10-3.ASM
; COM yap�s�ndaki programda macro kullan�m�
; Program ekran� temizledikten sonra bir mesaj yazacakt�r
------------------------------------------------------------------------------------

         PAGE 60,80
         TITLE Ekrana mesaj yazma
CDSEG SEGMENT PARA 'CODE'
         ORG 100H           ; COM program 100H den ba�lar
         ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG
------------------------------------------------------------------------------------

; INT 10H yard�m�yla ekran� silmeyi sa�layan macro kodu
------------------------------------------------------------------------------------
 
SIL      MACRO
         MOV CX,  OOOOH      ; Ekran�n sol   �st k��esi   sa�:-.1r/s�tun adresi
         MOV DX,  184FH      ; Ekran�n sa� alt k��esi     sat�r/sutun adresi
         MOV BH,  07H        ; �znitelik de�eri    (attribute byte)
         MOV AX,  0600H      ; AH = 06H pencereyi yukar� kayd�rma 
         INT 10H             ; 10H numaral� kesmeyi �a��r
         ENDM
------------------------------------------------------------------------------------

; INT 21H yard�m�yla ekrana mesaj yazd�ran macro
------------------------------------------------------------------------------------

YAZDIR MACRO text
         LEA DX, text        ; DX yazd�r�lacak mesaj�n ba��n� g�stermeli 
         MOV AH, 09H         ; AH = 09H Ekrana mesaj yazma
         INT 21H             ; 21H numaral� kesmeyi �a��r
         ENDM
------------------------------------------------------------------------------------

      
------------------------------------------------------------------------------------

; Macro'lar� kullanarak i�lemi ger�ekle�tiren yordam
------------------------------------------------------------------------------------

BASLA PROC NEAR
      SIL           ; SIL isimli macro'yu kullan
      YAZDIR MESAJ  ; YAZDIR makrosunu MESAJ parametresi ile kullan.
      RET
BASLA ENDP
------------------------------------------------------------------------------------

; mesaj�n tan�mland��� alan
------------------------------------------------------------------------------------

MESAJ DB 'Ekran silindi ve bu mesaj yazildi...','$'
CDSEG ENDS
      END BASL/N   ; program�n ba�lang�� noktas�
------------------------------------------------------------------------------------

//MAKRO �ZELL�KLER�
makrolar yordamlar gibi assembly program parcalar�d�r.ancak yordamlardan farkl� olarak derleme asamas�nda isimlerinin gectigi her yere kendilerine ait kod blogunu kopyalarlar.makro kullan�lacag� zaman sadece

//macro_ismi{parametre listesi}
ifadesi de kod i�ine yaz�lmal�d�r.�nemli olan makronun ad�n�n gectigi yerden �nce tan�mlanm�s olmas�d�r.bu makronun kod kesimi i�inde ilk olarak kodlanmas� gereken parca olmas� demektir.
eger istenirse makrolar ayr� bir metin dosyas� olarak yaz�l�p programa INCLUDE s�zde komutu yard�m�yla da dahil edilebilirler.

makronun en genel hali asag�da g�sterilmistir

macro_ismi		MACRO{parametre listesi}
				LOCAL....
				ASSUME.......
				
				
				;makro kodu
				
				
				ENDM
makrolar,yerine getirecekleri isin bir parcas� olarak i�inde �e�itli etiketler(label) bar�nd�rabilir.makrolar�n isimlerinin gectigi yerlere kendi kodlar�n� yerlestirdikleri bilindigine g�re kullan�lan etiketlerin dahil olduklar� programlarda da kullan�lm�s olmas� kar�s�kl�klara neden olur.
hatta ayn� makronun bir kod kesiminde birden fazla kullan�lmas� durumunda da bu problem ile kars� kars�ya kal�n�r.kullan�lan etiketlerin tek olmas� LOCAL s�zde komutu ile saglan�r.
boylece makro i�inde kullan�lan etiketlerin dahil olduklar� kod bloklar� i�indeki ayn� isimli etiketler ile kar�smas�n�n �nune gecilir.

makro i�inde ihtiyac duyulmas� durumunda ASSUME s�zde komutu ile kesim e�lemelerinde de degisiklik yap�labilir.	

makrolara parametre aktar�lmas�n�n gerekli oldugu durumda parametreler makro ismini takiben virgul ile ayr�lmak kayd�yla verilebilir.sekil 10-4'de ustal makrosunun program i�inde bir yerde kullan�lmas�,sekil 10-5'de ise ayn� makronun program�n i�inde farkli iki yerde kullan�lmas� durumlar� ve bu programlar�n derlenmesini takiben olusacak kod yap�s� g�sterilmektedir.

-SEMA

goruldugu gibi ustal isimli macro isminin ger gectigi yere derleyici taraf�ndan yerlestirilmistir.bu s�rada makro i�inde kullan�lan L! etiketi derleyici taraf�ndan koda dahil edilirken(xx ve yy ile g�sterilen sembolik)adres olarak ifade edilmistir.boylece program i�erisinde baska bir etiket ile kar�smas� gibi bir olas�l�k kalmam�st�r.makrolar�n isimlerinin gectigi her yere kendilerini yerlestirmeleri nedeniyle derleme sonras�nda program kodunun buyudugu de dikkat cekmektedir.

//MAKRO �RNEKLER�
makro kullan�m�n� ve parametre aktarma islemlerini yazacag�m�z basit programlar ile birlikte inceleyelim.

//�RNEK 10-3
�rnegimiz,bilgisayar ekran� temizleyip bit mesaj yazd�rmak olsun.program�m�z daha az kesim tan�m� yap�lmas� ve sade yap�s� nedeni ile com tipinde olup,ekran� temizlemek �zere SIL ve mesaj yazd�rmak i�in ise Yazd�r isimli makrolardan yararlan�lacakt�r.

makrolar�n ekran� silmesi ve mesaj yazd�rabilmesi i�in mevcut BIOS/DOS kesme fonksiyonlar�ndan INT komutunu kullanarak faydalanacag�z.her ne kadar su ana kadar olan k�s�mda kesme(interrupt)kavram�ndan s�z edilmemis dahi olsa kesme yordamlar� da assembly komutlardan olusmus program parcalar�d�r.
kesme yordamlar�,yapt�klar� ise g�re cagr�lmadan �nce ilgili yazmaclar�n ilk degerlerinin uygun sekilde ayarlanmas� ile kullan�labilir,yapt�klar� isin niteli�ine bagl� olarak da bir sonuc degeri dondurebilirler.bu �zellikleri dikkate al�nd�g�nda asl�nda kesimler aras�(intersegment) yordam cag�rmaya �ok benzer �zellikte �al�s�rlar.

ekran� s�lmek i�in kullan�cag�m�z INT 10 H-fonksiyon 06H,cx,x,ah ve BH yazmaclardan parametre al�r.ekrana mesaj yazd�rmak i�in kullan�lacak olan INT 21H-fonksyon 09H ise DX ve AH yazmaclardan parametre almaktad�r.bu kesme yordamlar�n� kullan�cak olan SIL isimli makro parametre almayacak ancak YAZDIR isimli makro ekrana yazd�r�lacak olan mesaji parametre olarak alacakt�r.


-KOD

makro kullan�m� ile ilgili �rnegimiz uzerinde vurgulanmas� gereken noktalar
1-makrolar mutlaka kullan�lmadan �nce tan�mlanm�s olmal�d�r.bu nedenle eger ayn� kod kesimi i�inde yer alacaklarsa,yordamlardan �nce onlar�n tan�mlar�n�n yap�lmas� gerekmektedir.
makrolar istenirse ayr� bir metin dosyas� i�ine konarak INCLUDE s�zde komutu ile programa dahil edilmelidir.

2-makrolar her ne kadar yordamlarda �nce tan�mlanm�s olsa da LST uzant�l� dosyan�n sol yan�ndaki bellek adresleri incelendiginde tan�mland�klar� yerde herhangi bir adrese sahip olmad�klar� g�r�lecektir.

3-makrolar ancak yordam i�inde adlar�n�n gectigi yerlere kendileri i�in tan�mlanm�s kod sat�rlar�n� yazarak bellek �zerinde yer tutmaya baslarlar.LST uzant�l� dosyada MACRO ad�n�n yerine ona ait kod yerlestirilmistir.iste bu nedenle programlar�m�z i�inde farkl� noktalarda cok sayida makro kullan�lmas� program�m�z�n koduna her seferinde mokronun kod blogunun eklenmesi anlam�na gelir ki bu da program�m�z�n kodunun b�y�mesine neden olur.

4-yazd�r isimli makro,yordam i�inde cagr�l�rken yan�na MESAJ isimli degisken parametre olarak verilmi�tir.ancak bu parametreye makro i�inde text isimli bir ara tan�mlay�c� ile degerlendirilmektedir.
yazd�r macro text
		lea dx,text
		mov ah,09H
		�nt 21h
		endm
	yazd�r mesaj	
			
