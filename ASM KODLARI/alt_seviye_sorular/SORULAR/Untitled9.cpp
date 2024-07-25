------------------------------------------------------------------------------------

; PROGRAM :�rnek 11-1.ASM
; Kullan�lacak harici bir yordam ile dizi i�indeki en b�y�k eleman� 
; bulma. kod kesimleri birle�tirili�tir.
------------------------------------------------------------------------------------

     PAGE 60,80
     TITLE Code kesimleri birle�ik - yard�mc� yordam �a��rma
------------------------------------------------------------------------------------

; BUYUK harici bir yordamd�r. FAR olarak tarrmlanm��t�r. 
; DIZI ise ba�ka bir program taraf�ndan kullan�lacakt�r.
------------------------------------------------------------------------------------

     EXTRN BUYUK:FAR
     PUBLIC DIZI
STSEG SEGMENT PARA STACK 'STACK' 
    DW 12 DUP(0)
STSEG ENDS
DTSEG SEGMENT PARA 'DATA'
------------------------------------------------------------------------------------

; kullan�lacak de�i�kenler tan�m�an�r.
------------------------------------------------------------------------------------

	DIZI DW 12,1,5,64,21,65,127,512,0,1024
	ELEMAN DW 10 
	BYK_EL DW ? 
	DTSEG ENDS 
	CDSEG SEGMENT PARA PUBLIC 'CODE' ; Kesim birle�tirilecek
    ASSUME CS:CDSEG,SS:STSEG,DS:DTSEG
	BASLA PROC FAR
------------------------------------------------------------------------------------

; D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------

     PUSH DS
     XOR AX,AX 
     PUSH AX
------------------------------------------------------------------------------------

; DTSEG ismiyle tan�ml� kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------

     MOV AX, DTSEG 
     MOV DS,AX
------------------------------------------------------------------------------------

    islem blo�u ba�l�yor
    MOV CX, ELEMAN    	;Eleman say�s�n� cx ile BUYUK isimli yordama aktar
	CALL BUYUK          ;BUYUK isimli yordam� �a��r�l�r
    MOV BYK_EL,AX       ;En b�y�k de�er AX yazmac� �zerinden geri d�ner
    RET                 ;DOS'a d�n
   	BASLA ENDP
   	CDSEG   ENDS
        END BASLA        ; program�n ba�lang�� noktas�
------------------------------------------------------------------------------------
//ANA VE ALT PROGRAMLARDAK� KES�MLER�N B�RLEST�R�LMES�
gelistirdigimiz uygulamalar�n geregi olarak bazen yararlanacag�m�z yordamlar farkll� programlara ait kod kesimleri i�inde yer alabilir.
bu durumlarda,gerek cag�ran programda(EXTRN yordam_ismi:FAR)gerek ise cagr�lan programlar taraf�nda (PUBL�C yordam_ismi)baz� ek tan�mlamalar�n yap�lm�s olmas� 
 ve yararlan�lacak yordamlar�n i�inde bulunduklar� programlar�n bellege yerlestirilmis(yuklenm�s)olmas� gerekir.

yordamlar yerine getireceklere islevin karmas�kl�ga bagl� olarak degisik buyukluklerde bellek kullan�rlar.yordam� olusturan kod ister 10-15 byte isterse 64 kb buyuklugunde olsun,kod kesimi i�in bellek �zerinde en az 64kb'l�k bir bolge kullan�l�r.
yordamlar,cogu zaman program i�in ayr�lm�s olan kod kesimini tamamen kullanamazlar.kod kesimi i�inde yordamlar taraf�ndan kullan�lamayan bellek alan� da baska bir amac �c�n kullan�lmayacag�ndan bellek etklin bir sekilde kullan�lamam�s olur.

diger yandan uygulama farkl� kesimlerde bulunan yordamlar� kullan�rken kesimler aras� yordam cag�rma(intersegment call)yapmak zorunda kalacak;

1-yordamlar aras�ndaki gidis/gelisin saglanabilmesi i�in kesim ve g�reli konum adreslerini y�g�nda saklanma
2-uzak yordama ulasabilmek i�in CS ve IP yazmaclar�na cagr�lacak olan yordam�n adreslerini yerlestirme
3-retf komutunun islenmesi ile donus adreslerini y�g�ndan alarak IP ve CS yazmaclar�na aktarma

islemleri de g�receli bir gecikme yasanmas�na neden olacakt�r.
bu tespitler,assembly programlar i�in bastan beri vurgulad�g�m�z,sistem kaynaklar�n� mumkun oldugunca az ve etkin kullanma ile h�zl� cal�sma �zellikleriyle �elismektedir.
tespitlerimizin temelindeki problemler,ana ve alt programlar�n kod kesimlerinin birlestirilmesi ile kolayl�kla ortadan kald�r�labilir.

//B�RLEST�R�LM�S(COMB�NED)KOD KES�M� KULLANIMI
farkl� programlar i�indeki kod kesimlerin birlestirilmesi,kesim isimlerinin,kesimin baslang�c adresii belirlemek �zere kullan�lan hizalam(allignment)tiplerinin ile kesimleri gruplamak i�in kullan�lan s�n�f(class)tiplerinin ayn� olmas� ve kesim birlestirme(combine)tiplerinin PUBL�C tan�mlanmas� ile saglan�r.
tablo 11-1'de verilen Ana.ASM isimli program i�indeki basla isimli yordam,tablo 11-2'de verilen ALT.ASM isimli program i�inde yer alan Altprg isimli yordam� kullanmak �zere tasarlanm�st�r.Altprg isimli yordam�nn farkl� bir kesimde oldugu EXTRN s�zde komutu ile (sat�r 3)belirtilmistir.
her iki program�n da kod kesimleri Codesg isminde,kesim hizalama tipileri PARA,birlestirme tipleri PUBL�C ve s�n�f tipleri 'code' olarak (sat�r 6)belirlenmis olup bu sayede her iki program�n kod kesimlerinin birlestirilmesi saglanm�st�r.

ANA.ASM program� i�indeki BASLA isimli yordam,ad�n�n program�n sonundaki END komutunu takiben yaz�lm�s olmas� nedeni ile(sat�r 18)kontrolu elinde bulunduran ana yordam konumundad�r.BASLA isimli yordam�n �ncelikli g�revi geri donus i�in
gerekli adresleri y�g�nda saklamakt�r.(sat�r 9-11).daha sonra CALL komutunu kullanarak ALT.ASM i�inde tan�ml� ALtprg isimli yordam� kesimler aras� yordam cag�rma teknigine uygun olarak cag�rmaktad�r.(sat�r 13).

-SEMA

diger yandan tablo 11-2'de verilen ALT.ASM program� i�indeki Altprg isimli yordam�n baskalar� taraf�ndan kullan�labilmesini saglamak �zere PUBL�C tan�m� yap�lm�st�r.(sat�r 3)kesim tan�m� ANA.ASM program�nda yap�lan kod kesimi tan�m� ile ayn�d�r(sat�r 6)daha �nceki �rneklerimizde de oldugu gibi ALT.ASM isimli program kendi bas�na cal�smak yerine,gelen isteklere hizmet vermek �zere tasarland�g�ndan dolay� END komutundan sonra hicbir baslang�c noktas� belirtilmemistir.(sat�r 14)
.
.
.
.burda da yaz� var
.
.
//�RNEK 11-1
word tan�ml� pozitif say�lardan olusan,10 elemanl� bir dizinin en buyuk eleman� BUYUK isimli harici bir yordam yard�m�yla bulan program� ve s�z konusu harici yordam�n i�inde yer al�cag� yard�mc� program� yazal�m.

�rnegimizde yazmam�z beklenen iki programdan ilki,10 elemanl� dizinin tan�mland�g� ve genel olarak kontrolu elinde bulunduracak olan �rnek 11-1 ASM isimli program,ikincisi  ise buyuk isimli yordam� bulunduracak olan �RNEK 11-1-1.ASM isimli programd�r.buyuk isimli yordam�n FAR olarak tan�mland�g� kabul ederek ilk program�m�z� kodlayacak olursak



