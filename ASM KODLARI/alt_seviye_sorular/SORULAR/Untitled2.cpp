------------------------------------------------------------------------------------

 PROGRAM : �rnek 10-2.Asm
; Toplama isimli yard�mc� vordam�n �a��r�lmas�
------------------------------------------------------------------------------------

       PAGE 60,80
       TITLE yard�mc� yordam �a��rma 
STSEG  SEGMENT PARA  'STACK'
       DW 12 DUP(0)
STSEG  ENDS
DTSEG  SEGMENT   'DATA'
------------------------------------------------------------------------------------

; Kullan�lacak de�i�kenler tan�mlan�r.
------------------------------------------------------------------------------------

SAYI1  DB 12P
SAYI2  DB
SONUC  0H
DTSEG  ENDS
CDSEG SEGMENT PARA 'CODE'
    ASSUME CS:CDSEG, SS:STSEG, DS:DTSEG 
BASLA PROC FAR
------------------------------------------------------------------------------------

; D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------

       PUSH DS
       XOR AX, AX 
       PUSH AX
------------------------------------------------------------------------------------

  ;DATASG ismiyle tan�ml� kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------

       MOV AX, DTSEG 
       MOV DS, AX
------------------------------------------------------------------------------------

  ;i�lem blo�u ba�l�yor
------------------------------------------------------------------------------------

       MOV BH, SAYI1 ; De�erler BH ve BL Yazma�lar� �zerinden
       MOV BL, SAYI2 ; �a��r�lacak olan yard�mc� yordama aktar�l�r 
       CALL TOPLAMA  ; yordam �a��r�l�r
       MOV SONUC, AX ; toplama i�leminin sonucunu AX yazmac�nda
       RET
BASLA  ENDP
CDSEG  ENDS
       END BASLA     ;program�n ba�lang�� noktas�
------------------------------------------------------------------------------------
//KES�MLER ARASI YORDAM KULLANIMI
kullanmak istedigimiz yordamlar her zaman ayn� kesim i�inde bulunmayabilir.bu durumda kesim d�s�ndaki bir yordama erismek ve onu kullanmak ihtiyac� dogabilir.bulunan kesim d�s�ndaki bir yordam�n cagr�larak kullan�lmas�na kesimler aras� cag�rma(intersegment call) adi verilir.kesimler aras� yordamlar�n kullan�m��n iki �nemli nedeni vard�r.bunlar:
1.bir kesim ile s�n�rl� kalmaks�z�n program�m�z�n kodunu istedigimiz kadar buyutebilmek
2.baska birisi tarafindan yaz�lm�s,test edilmis giris ve c�k�s degerleri belli bir yordamdan yararlanabilmek

her ne kadar bu nedenler birbirinden farkli gibi g�r�nse de genel olarak moduler program yazma ihtiyac�n�n dogal bir sonucu olarak ortaya c�kmaktad�rlar.kullanmak istedigimiz yordam�n farkli bir kesimde yer ald�g�n�n derleyiciye bir �ekilde belirtilmesi gerekmektedir.
aksi halde derleyici cagr�lan yordam� ayn� kod kesimi i�inde arayacak,ad� gecen yordam� bulamay�nca da hata vericektir.
bu problemi asmak �zere cag�ran tarafta cagr�lan yordam�n ismi ve tipi EXTRN,cagr�lan tarafta ise yordam�n ismi PUBL�C s�zde komutlar�ndan sonra yaz�lmal�d�r

kesim i�i yordam cag�rmadan farkl� olarak kesimler aras� yordam cag�rmada,cag�ran ve cagr�lan yordamlar ayn� veri kesimini paylasmazlar.bunun i�in aralar�nda parametre aktar�m� yapmalar� gerekir.
parametre aktar�m� i�in aktar�lacak parametre say�na bagl� olarak farkl� yontemler kullan�lmal�d�r.

bu durumu kesimler aras� yordam cag�rma islemine verecegimiz bir �rnek �zerinden incelemeye cal�sal�m

//�RNEK 10-2
�ncelikle byte tipinde 2 degeri BL ve BH yazmaclar� uzerinden alan ve bunlar�n toplam�n� hesaplayarak AX yazmac� �zerinden d�nduren TOPLAMA isminde bir yordam�n var oldugunu varsayarak bu yordamdan servis alacak olan program� yazal�m.
TOPLAMA ismindeki yordam�n giris parametreleri byte oldugu i�in SAYI1 ve SAY�2 isimli byte,toplam degeri AX yazmac� �zerinden d�nd�g� i�in SONUC degeri word olarak  veri kesiminde tan�mlanmal�d�r.

bu �rnegimizde EXTRN komutunun kullan�lmamas� durumunda ne tip hata mesajlar� ile kars�las�lacag�n� inceleyecegiz.al�nan hata mesajlar� dogrultusunda kodumuza EXTRN tan�m�n� ilave ederek hemen ard�ndan TOPLAMA isimli yordam� bar�nd�ran kodu yazacag�z.
son olarak iki farkl� assembly kaynak kodundan ne �ekilde cal�st�r�labilir bir nesne kodu �retilecegini g�recegiz.	
	
hemen g�r�lecegi gibi program�n 37.sat�r�nda toplama isimli sembolun tan�ms�z olduguna ili�kin bir hata mesaji al�yoruz.bu hata toplama isimli yordam�n kod kesimi i�inde yer almama�s veya bu yordam�n harici bir kesimde oldugunun belirtilmemesinden kaynaklanmaktad�r.
EXTRN s�zde komutu program�m�z i�inde atifa bulunacag�m�z herhangi bir sembolun (bu bir yordam ismi olabilecegi gibi bir degisken ismi de olabilir)bizim program�m�z�n d�s�nda bir yerde tan�ml� oldgunu derleyiciye bildirmek i�in kullan�lmaktad�r.
benzer sekilde public s�zde komutu da sembolun tan�mland�g� noktada bu sembole disar�dan bir erisim olacag�n� derleyiciye belirtmek amac�yls kullan�l�r

buna g�re �rnek 10-2 asm isimli program�n bas�nda

EXTRN TOPLAMA :FAR

yaz�lacak olursa derleyici toplama isimli sembolun kesim disinda tan�ml� ve far �zellikte bir yard�mc� yordam oldugunu anl�yacakt�r.EXTRN s�zde komutunda kullan�lan far ifadesi daha �nceden de belirtildigi gibi d�n�s adreslerinin kesim ve g�reli konum ikilisinden olustugunu belirler.
buna g�re program�m�za extrn sat�r�n� ekleyerek tekrar deniyelim


--KOD


extrn tan�m� sayesinde derleme asamas�nda kars�las�lan hata ortadan kalkm�st�r.bu asamadan sonra toplama isimli yordam�n i�inde bulunacag� diger program� da yazmam�z gerekmektedir.
bu programda dikkat edilmesi gereken �nemli nokta toplama yordam�n�n cagr�l�s sekline uygun olarak  far tan�mlanmas�d�r.ancak toplama yordam�n� bunyesinde bulunduran programda da yordam�n baska programlar taraf�ndan kullan�lmas�na imkan veren public s�zde komutu kullan�lmal�d�r.
bu kurallar uyar�nda toplama yordam�n�n i�inde bulundugu program� yazacak olursak asag�daki kodu elde ederiz.


--KOD


