------------------------------------------------------------------------------------

 PROGRAM : Örnek 10-2.Asm
; Toplama isimli yardýmcý vordamýn çaðýrýlmasý
------------------------------------------------------------------------------------

       PAGE 60,80
       TITLE yardýmcý yordam çaðýrma 
STSEG  SEGMENT PARA  'STACK'
       DW 12 DUP(0)
STSEG  ENDS
DTSEG  SEGMENT   'DATA'
------------------------------------------------------------------------------------

; Kullanýlacak deðiþkenler tanýmlanýr.
------------------------------------------------------------------------------------

SAYI1  DB 12P
SAYI2  DB
SONUC  0H
DTSEG  ENDS
CDSEG SEGMENT PARA 'CODE'
    ASSUME CS:CDSEG, SS:STSEG, DS:DTSEG 
BASLA PROC FAR
------------------------------------------------------------------------------------

; Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------

       PUSH DS
       XOR AX, AX 
       PUSH AX
------------------------------------------------------------------------------------

  ;DATASG ismiyle tanýmlý kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------

       MOV AX, DTSEG 
       MOV DS, AX
------------------------------------------------------------------------------------

  ;iþlem bloðu baþlýyor
------------------------------------------------------------------------------------

       MOV BH, SAYI1 ; Deðerler BH ve BL Yazmaçlarý üzerinden
       MOV BL, SAYI2 ; çaðýrýlacak olan yardýmcý yordama aktarýlýr 
       CALL TOPLAMA  ; yordam çaðýrýlýr
       MOV SONUC, AX ; toplama iþleminin sonucunu AX yazmacýnda
       RET
BASLA  ENDP
CDSEG  ENDS
       END BASLA     ;programýn baþlangýç noktasý
------------------------------------------------------------------------------------
//KESÝMLER ARASI YORDAM KULLANIMI
kullanmak istedigimiz yordamlar her zaman ayný kesim içinde bulunmayabilir.bu durumda kesim dýsýndaki bir yordama erismek ve onu kullanmak ihtiyacý dogabilir.bulunan kesim dýsýndaki bir yordamýn cagrýlarak kullanýlmasýna kesimler arasý cagýrma(intersegment call) adi verilir.kesimler arasý yordamlarýn kullanýmýýn iki önemli nedeni vardýr.bunlar:
1.bir kesim ile sýnýrlý kalmaksýzýn programýmýzýn kodunu istedigimiz kadar buyutebilmek
2.baska birisi tarafindan yazýlmýs,test edilmis giris ve cýkýs degerleri belli bir yordamdan yararlanabilmek

her ne kadar bu nedenler birbirinden farkli gibi görünse de genel olarak moduler program yazma ihtiyacýnýn dogal bir sonucu olarak ortaya cýkmaktadýrlar.kullanmak istedigimiz yordamýn farkli bir kesimde yer aldýgýnýn derleyiciye bir þekilde belirtilmesi gerekmektedir.
aksi halde derleyici cagrýlan yordamý ayný kod kesimi içinde arayacak,adý gecen yordamý bulamayýnca da hata vericektir.
bu problemi asmak üzere cagýran tarafta cagrýlan yordamýn ismi ve tipi EXTRN,cagrýlan tarafta ise yordamýn ismi PUBLÝC sözde komutlarýndan sonra yazýlmalýdýr

kesim içi yordam cagýrmadan farklý olarak kesimler arasý yordam cagýrmada,cagýran ve cagrýlan yordamlar ayný veri kesimini paylasmazlar.bunun için aralarýnda parametre aktarýmý yapmalarý gerekir.
parametre aktarýmý için aktarýlacak parametre sayýna baglý olarak farklý yontemler kullanýlmalýdýr.

bu durumu kesimler arasý yordam cagýrma islemine verecegimiz bir örnek üzerinden incelemeye calýsalým

//ÖRNEK 10-2
öncelikle byte tipinde 2 degeri BL ve BH yazmaclarý uzerinden alan ve bunlarýn toplamýný hesaplayarak AX yazmacý üzerinden dönduren TOPLAMA isminde bir yordamýn var oldugunu varsayarak bu yordamdan servis alacak olan programý yazalým.
TOPLAMA ismindeki yordamýn giris parametreleri byte oldugu için SAYI1 ve SAYÝ2 isimli byte,toplam degeri AX yazmacý üzerinden döndügü için SONUC degeri word olarak  veri kesiminde tanýmlanmalýdýr.

bu örnegimizde EXTRN komutunun kullanýlmamasý durumunda ne tip hata mesajlarý ile karsýlasýlacagýný inceleyecegiz.alýnan hata mesajlarý dogrultusunda kodumuza EXTRN tanýmýný ilave ederek hemen ardýndan TOPLAMA isimli yordamý barýndýran kodu yazacagýz.
son olarak iki farklý assembly kaynak kodundan ne þekilde calýstýrýlabilir bir nesne kodu üretilecegini görecegiz.	
	
hemen görðlecegi gibi programýn 37.satýrýnda toplama isimli sembolun tanýmsýz olduguna iliþkin bir hata mesaji alýyoruz.bu hata toplama isimli yordamýn kod kesimi içinde yer almamaýs veya bu yordamýn harici bir kesimde oldugunun belirtilmemesinden kaynaklanmaktadýr.
EXTRN sözde komutu programýmýz içinde atifa bulunacagýmýz herhangi bir sembolun (bu bir yordam ismi olabilecegi gibi bir degisken ismi de olabilir)bizim programýmýzýn dýsýnda bir yerde tanýmlý oldgunu derleyiciye bildirmek için kullanýlmaktadýr.
benzer sekilde public sözde komutu da sembolun tanýmlandýgý noktada bu sembole disarýdan bir erisim olacagýný derleyiciye belirtmek amacýyls kullanýlýr

buna göre örnek 10-2 asm isimli programýn basýnda

EXTRN TOPLAMA :FAR

yazýlacak olursa derleyici toplama isimli sembolun kesim disinda tanýmlý ve far özellikte bir yardýmcý yordam oldugunu anlýyacaktýr.EXTRN sözde komutunda kullanýlan far ifadesi daha önceden de belirtildigi gibi dönüs adreslerinin kesim ve göreli konum ikilisinden olustugunu belirler.
buna göre programýmýza extrn satýrýný ekleyerek tekrar deniyelim


--KOD


extrn tanýmý sayesinde derleme asamasýnda karsýlasýlan hata ortadan kalkmýstýr.bu asamadan sonra toplama isimli yordamýn içinde bulunacagý diger programý da yazmamýz gerekmektedir.
bu programda dikkat edilmesi gereken önemli nokta toplama yordamýnýn cagrýlýs sekline uygun olarak  far tanýmlanmasýdýr.ancak toplama yordamýný bunyesinde bulunduran programda da yordamýn baska programlar tarafýndan kullanýlmasýna imkan veren public sözde komutu kullanýlmalýdýr.
bu kurallar uyarýnda toplama yordamýnýn içinde bulundugu programý yazacak olursak asagýdaki kodu elde ederiz.


--KOD


