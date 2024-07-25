------------------------------------------------------------------------------------

; PROGRAM : �rnek 10-2-1.Asm
; Toplama isimli yard�mc� yordam�n i�inde bulundu�u program                  
------------------------------------------------------------------------------------

          PAGE 60,80                                                           
          TITLE yard�mc� procedure �a��rma
          PUBLIC TOPLAMA
CODES     SEGMENT PARA 'CODE'                                               
          ASSUME CS:CODES
TOPLAMA PROC FAR                                                     

------------------------------------------------------------------------------------

; i�lem blo�u ba�l�yor
------------------------------------------------------------------------------------
 
          XOR AX, AX             ; AX yazmac�n� s�f�rla
          ADD AL, BL             ; AL �zerinde toplamaya ba�la
          ADD AL, BH 
          ADC AH, 0              ; CF olu�mas� durumunda bunu AH'ya aktar 
          RET                    ; �a��r�ld���n yere don
TOPLAMA ENDP
CODES     ENDS
          END
------------------------------------------------------------------------------------
�rnek 10-2-1 asm isimli dosya da al�sa geldigimiz kodlaman�n d�s�nda kalan baz� �zelliklerin vurgulanmas� gereklidir.bunlar:
	1-y�g�n ve veri kesimi tan�mlamalar� yap�lmam�st�r.y�g�n,toplama yordam�n� cag�ran program taraf�ndan tan�mland�g� i�in tekrar tan�mlanmas�na gerek yoktur.ayr�ca toplama yordam� i�inde ayr� bir y�g�n tan�m� yap�lacak olursa d�nus adreslerine erisim mumkun olm�yacakt�r.
	benzer bi�imde toplama yordam�n�n i�inde bulundugu programa has degisken de olmad�g� i�in veri kesimi tan�mlanmam�st�r.
	2-exe tipindeki programlarda kontrolu elinde bulunduran yordam far olarak tan�mlan�rken,geri donusu saglamak �zere gerekli adresleri y�g�na yerlest�rebilmek i�in 
	push ds
	xor ax,ax
	push ax
	
	komutlar� ard�ndan veri kesimine erisebilmek i�in
	
	mov ax,veri_kesim_ismi
	mov ds,ax
	
	komutlar� kullan�lmal�d�r.
	oysa bu komut sat�rlar� �rnek 10-2-1 asm i�inde bulunmaz.bunun arkas�nda yatan neden toplama isimli yordam�n�n kendi bas�na cal�sacak yani kontrolu elinde bulunduracak t�rde olmas�d�r.
	o zaman d�n�s adreslerinin(isletim sistemine donmek i�in)y�g�nda saklanmas�,toplama isimli yordam� cag�ran�n sorumlulugunda olmal�d�r
	
	3-program�n bitisini belirleyen end s�zde komutunun sonunda baslang�c noktas� olarak hicbir yordam isminin yaz�lmam�s olmas� da dikkat cekicidir.�rnek 10-2-1.asm isimli program hicbir zaman kendi bas�na �al�smak �zere tasarlanmad�g� i�in baslang�c noktas� olarak bir yordam ismi yazmaya gerek yoktur.
	
	4-toplama yordam�n�n baska programlar taraf�ndan da cagr�labilmesi i�in 
	PUBL�C TOPLAMA 
	s�zde komutundan yararlan�lm�st�r
	
	
	
	g�r�ld�g� gibi �rnek 10-2.asm isimli program,�rnek 10-2-1.asm isimli program i�inde yer alan bir yordam� kullanmak istemektedir.programlarda kullan�lan EXTRN/PUBLIC s�zde komutlar� yard�m�yla kimin,kimden hangi yordam� kullanacag� belirlenmis derleme islemleri sonucunda �rnek 10-2.OBJ...
	

