------------------------------------------------------------------------------------

; PROGRAM :örnek 11-1.ASM
; Kullanýlacak harici bir yordam ile dizi içindeki en büyük elemaný 
; bulma. kod kesimleri birleþtiriliþtir.
------------------------------------------------------------------------------------

     PAGE 60,80
     TITLE Code kesimleri birleþik - yardýmcý yordam çaðýrma
------------------------------------------------------------------------------------

; BUYUK harici bir yordamdýr. FAR olarak tarrmlanmýþtýr. 
; DIZI ise baþka bir program tarafýndan kullanýlacaktýr.
------------------------------------------------------------------------------------

     EXTRN BUYUK:FAR
     PUBLIC DIZI
STSEG SEGMENT PARA STACK 'STACK' 
    DW 12 DUP(0)
STSEG ENDS
DTSEG SEGMENT PARA 'DATA'
------------------------------------------------------------------------------------

; kullanýlacak deðiþkenler taným¦anýr.
------------------------------------------------------------------------------------

	DIZI DW 12,1,5,64,21,65,127,512,0,1024
	ELEMAN DW 10 
	BYK_EL DW ? 
	DTSEG ENDS 
	CDSEG SEGMENT PARA PUBLIC 'CODE' ; Kesim birleþtirilecek
    ASSUME CS:CDSEG,SS:STSEG,DS:DTSEG
	BASLA PROC FAR
------------------------------------------------------------------------------------

; Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------

     PUSH DS
     XOR AX,AX 
     PUSH AX
------------------------------------------------------------------------------------

; DTSEG ismiyle tanýmlý kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------

     MOV AX, DTSEG 
     MOV DS,AX
------------------------------------------------------------------------------------

    islem bloðu baþlýyor
    MOV CX, ELEMAN    	;Eleman sayýsýný cx ile BUYUK isimli yordama aktar
	CALL BUYUK          ;BUYUK isimli yordamý çaðýrýlýr
    MOV BYK_EL,AX       ;En büyük deðer AX yazmacý üzerinden geri döner
    RET                 ;DOS'a dön
   	BASLA ENDP
   	CDSEG   ENDS
        END BASLA        ; programýn baþlangýç noktasý
------------------------------------------------------------------------------------
//ANA VE ALT PROGRAMLARDAKÝ KESÝMLERÝN BÝRLESTÝRÝLMESÝ
gelistirdigimiz uygulamalarýn geregi olarak bazen yararlanacagýmýz yordamlar farkllý programlara ait kod kesimleri içinde yer alabilir.
bu durumlarda,gerek cagýran programda(EXTRN yordam_ismi:FAR)gerek ise cagrýlan programlar tarafýnda (PUBLÝC yordam_ismi)bazý ek tanýmlamalarýn yapýlmýs olmasý 
 ve yararlanýlacak yordamlarýn içinde bulunduklarý programlarýn bellege yerlestirilmis(yuklenmýs)olmasý gerekir.

yordamlar yerine getireceklere islevin karmasýklýga baglý olarak degisik buyukluklerde bellek kullanýrlar.yordamý olusturan kod ister 10-15 byte isterse 64 kb buyuklugunde olsun,kod kesimi için bellek üzerinde en az 64kb'lýk bir bolge kullanýlýr.
yordamlar,cogu zaman program için ayrýlmýs olan kod kesimini tamamen kullanamazlar.kod kesimi içinde yordamlar tarafýndan kullanýlamayan bellek alaný da baska bir amac ýcýn kullanýlmayacagýndan bellek etklin bir sekilde kullanýlamamýs olur.

diger yandan uygulama farklý kesimlerde bulunan yordamlarý kullanýrken kesimler arasý yordam cagýrma(intersegment call)yapmak zorunda kalacak;

1-yordamlar arasýndaki gidis/gelisin saglanabilmesi için kesim ve göreli konum adreslerini yýgýnda saklanma
2-uzak yordama ulasabilmek için CS ve IP yazmaclarýna cagrýlacak olan yordamýn adreslerini yerlestirme
3-retf komutunun islenmesi ile donus adreslerini yýgýndan alarak IP ve CS yazmaclarýna aktarma

islemleri de göreceli bir gecikme yasanmasýna neden olacaktýr.
bu tespitler,assembly programlar için bastan beri vurguladýgýmýz,sistem kaynaklarýný mumkun oldugunca az ve etkin kullanma ile hýzlý calýsma özellikleriyle çelismektedir.
tespitlerimizin temelindeki problemler,ana ve alt programlarýn kod kesimlerinin birlestirilmesi ile kolaylýkla ortadan kaldýrýlabilir.

//BÝRLESTÝRÝLMÝS(COMBÝNED)KOD KESÝMÝ KULLANIMI
farklý programlar içindeki kod kesimlerin birlestirilmesi,kesim isimlerinin,kesimin baslangýc adresii belirlemek üzere kullanýlan hizalam(allignment)tiplerinin ile kesimleri gruplamak için kullanýlan sýnýf(class)tiplerinin ayný olmasý ve kesim birlestirme(combine)tiplerinin PUBLÝC tanýmlanmasý ile saglanýr.
tablo 11-1'de verilen Ana.ASM isimli program içindeki basla isimli yordam,tablo 11-2'de verilen ALT.ASM isimli program içinde yer alan Altprg isimli yordamý kullanmak üzere tasarlanmýstýr.Altprg isimli yordamýnn farklý bir kesimde oldugu EXTRN sözde komutu ile (satýr 3)belirtilmistir.
her iki programýn da kod kesimleri Codesg isminde,kesim hizalama tipileri PARA,birlestirme tipleri PUBLÝC ve sýnýf tipleri 'code' olarak (satýr 6)belirlenmis olup bu sayede her iki programýn kod kesimlerinin birlestirilmesi saglanmýstýr.

ANA.ASM programý içindeki BASLA isimli yordam,adýnýn programýn sonundaki END komutunu takiben yazýlmýs olmasý nedeni ile(satýr 18)kontrolu elinde bulunduran ana yordam konumundadýr.BASLA isimli yordamýn öncelikli görevi geri donus için
gerekli adresleri yýgýnda saklamaktýr.(satýr 9-11).daha sonra CALL komutunu kullanarak ALT.ASM içinde tanýmlý ALtprg isimli yordamý kesimler arasý yordam cagýrma teknigine uygun olarak cagýrmaktadýr.(satýr 13).

-SEMA

diger yandan tablo 11-2'de verilen ALT.ASM programý içindeki Altprg isimli yordamýn baskalarý tarafýndan kullanýlabilmesini saglamak üzere PUBLÝC tanýmý yapýlmýstýr.(satýr 3)kesim tanýmý ANA.ASM programýnda yapýlan kod kesimi tanýmý ile aynýdýr(satýr 6)daha önceki örneklerimizde de oldugu gibi ALT.ASM isimli program kendi basýna calýsmak yerine,gelen isteklere hizmet vermek üzere tasarlandýgýndan dolayý END komutundan sonra hicbir baslangýc noktasý belirtilmemistir.(satýr 14)
.
.
.
.burda da yazý var
.
.
//ÖRNEK 11-1
word tanýmlý pozitif sayýlardan olusan,10 elemanlý bir dizinin en buyuk elemaný BUYUK isimli harici bir yordam yardýmýyla bulan programý ve söz konusu harici yordamýn içinde yer alýcagý yardýmcý programý yazalým.

örnegimizde yazmamýz beklenen iki programdan ilki,10 elemanlý dizinin tanýmlandýgý ve genel olarak kontrolu elinde bulunduracak olan örnek 11-1 ASM isimli program,ikincisi  ise buyuk isimli yordamý bulunduracak olan ÖRNEK 11-1-1.ASM isimli programdýr.buyuk isimli yordamýn FAR olarak tanýmlandýgý kabul ederek ilk programýmýzý kodlayacak olursak



