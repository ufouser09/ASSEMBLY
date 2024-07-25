------------------------------------------------------------------------------------

; PROGRAM : Örnek 10-3.ASM
; COM yapýsýndaki programda macro kullanýmý
; Program ekraný temizledikten sonra bir mesaj yazacaktýr
------------------------------------------------------------------------------------

         PAGE 60,80
         TITLE Ekrana mesaj yazma
CDSEG SEGMENT PARA 'CODE'
         ORG 100H           ; COM program 100H den baþlar
         ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG
------------------------------------------------------------------------------------

; INT 10H yardýmýyla ekraný silmeyi saðlayan macro kodu
------------------------------------------------------------------------------------
 
SIL      MACRO
         MOV CX,  OOOOH      ; Ekranýn sol   üst köþesi   sa•:-.1r/sütun adresi
         MOV DX,  184FH      ; Ekranýn sað alt köþesi     satýr/sutun adresi
         MOV BH,  07H        ; öznitelik deðeri    (attribute byte)
         MOV AX,  0600H      ; AH = 06H pencereyi yukarý kaydýrma 
         INT 10H             ; 10H numaralý kesmeyi çaðýr
         ENDM
------------------------------------------------------------------------------------

; INT 21H yardýmýyla ekrana mesaj yazdýran macro
------------------------------------------------------------------------------------

YAZDIR MACRO text
         LEA DX, text        ; DX yazdýrýlacak mesajýn baþýný göstermeli 
         MOV AH, 09H         ; AH = 09H Ekrana mesaj yazma
         INT 21H             ; 21H numaralý kesmeyi çaðýr
         ENDM
------------------------------------------------------------------------------------

      
------------------------------------------------------------------------------------

; Macro'larý kullanarak iþlemi gerçekleþtiren yordam
------------------------------------------------------------------------------------

BASLA PROC NEAR
      SIL           ; SIL isimli macro'yu kullan
      YAZDIR MESAJ  ; YAZDIR makrosunu MESAJ parametresi ile kullan.
      RET
BASLA ENDP
------------------------------------------------------------------------------------

; mesajýn tanýmlandýðý alan
------------------------------------------------------------------------------------

MESAJ DB 'Ekran silindi ve bu mesaj yazildi...','$'
CDSEG ENDS
      END BASL/N   ; programýn baþlangýç noktasý
------------------------------------------------------------------------------------

//MAKRO ÖZELLÝKLERÝ
makrolar yordamlar gibi assembly program parcalarýdýr.ancak yordamlardan farklý olarak derleme asamasýnda isimlerinin gectigi her yere kendilerine ait kod blogunu kopyalarlar.makro kullanýlacagý zaman sadece

//macro_ismi{parametre listesi}
ifadesi de kod içine yazýlmalýdýr.önemli olan makronun adýnýn gectigi yerden önce tanýmlanmýs olmasýdýr.bu makronun kod kesimi içinde ilk olarak kodlanmasý gereken parca olmasý demektir.
eger istenirse makrolar ayrý bir metin dosyasý olarak yazýlýp programa INCLUDE sözde komutu yardýmýyla da dahil edilebilirler.

makronun en genel hali asagýda gösterilmistir

macro_ismi		MACRO{parametre listesi}
				LOCAL....
				ASSUME.......
				
				
				;makro kodu
				
				
				ENDM
makrolar,yerine getirecekleri isin bir parcasý olarak içinde çeþitli etiketler(label) barýndýrabilir.makrolarýn isimlerinin gectigi yerlere kendi kodlarýný yerlestirdikleri bilindigine göre kullanýlan etiketlerin dahil olduklarý programlarda da kullanýlmýs olmasý karýsýklýklara neden olur.
hatta ayný makronun bir kod kesiminde birden fazla kullanýlmasý durumunda da bu problem ile karsý karsýya kalýnýr.kullanýlan etiketlerin tek olmasý LOCAL sözde komutu ile saglanýr.
boylece makro içinde kullanýlan etiketlerin dahil olduklarý kod bloklarý içindeki ayný isimli etiketler ile karýsmasýnýn önune gecilir.

makro içinde ihtiyac duyulmasý durumunda ASSUME sözde komutu ile kesim eþlemelerinde de degisiklik yapýlabilir.	

makrolara parametre aktarýlmasýnýn gerekli oldugu durumda parametreler makro ismini takiben virgul ile ayrýlmak kaydýyla verilebilir.sekil 10-4'de ustal makrosunun program içinde bir yerde kullanýlmasý,sekil 10-5'de ise ayný makronun programýn içinde farkli iki yerde kullanýlmasý durumlarý ve bu programlarýn derlenmesini takiben olusacak kod yapýsý gösterilmektedir.

-SEMA

goruldugu gibi ustal isimli macro isminin ger gectigi yere derleyici tarafýndan yerlestirilmistir.bu sýrada makro içinde kullanýlan L! etiketi derleyici tarafýndan koda dahil edilirken(xx ve yy ile gösterilen sembolik)adres olarak ifade edilmistir.boylece program içerisinde baska bir etiket ile karýsmasý gibi bir olasýlýk kalmamýstýr.makrolarýn isimlerinin gectigi her yere kendilerini yerlestirmeleri nedeniyle derleme sonrasýnda program kodunun buyudugu de dikkat cekmektedir.

//MAKRO ÖRNEKLERÝ
makro kullanýmýný ve parametre aktarma islemlerini yazacagýmýz basit programlar ile birlikte inceleyelim.

//ÖRNEK 10-3
örnegimiz,bilgisayar ekraný temizleyip bit mesaj yazdýrmak olsun.programýmýz daha az kesim tanýmý yapýlmasý ve sade yapýsý nedeni ile com tipinde olup,ekraný temizlemek üzere SIL ve mesaj yazdýrmak için ise Yazdýr isimli makrolardan yararlanýlacaktýr.

makrolarýn ekraný silmesi ve mesaj yazdýrabilmesi için mevcut BIOS/DOS kesme fonksiyonlarýndan INT komutunu kullanarak faydalanacagýz.her ne kadar su ana kadar olan kýsýmda kesme(interrupt)kavramýndan söz edilmemis dahi olsa kesme yordamlarý da assembly komutlardan olusmus program parcalarýdýr.
kesme yordamlarý,yaptýklarý ise göre cagrýlmadan önce ilgili yazmaclarýn ilk degerlerinin uygun sekilde ayarlanmasý ile kullanýlabilir,yaptýklarý isin niteliðine baglý olarak da bir sonuc degeri dondurebilirler.bu özellikleri dikkate alýndýgýnda aslýnda kesimler arasý(intersegment) yordam cagýrmaya çok benzer özellikte çalýsýrlar.

ekraný sýlmek için kullanýcagýmýz INT 10 H-fonksiyon 06H,cx,x,ah ve BH yazmaclardan parametre alýr.ekrana mesaj yazdýrmak için kullanýlacak olan INT 21H-fonksyon 09H ise DX ve AH yazmaclardan parametre almaktadýr.bu kesme yordamlarýný kullanýcak olan SIL isimli makro parametre almayacak ancak YAZDIR isimli makro ekrana yazdýrýlacak olan mesaji parametre olarak alacaktýr.


-KOD

makro kullanýmý ile ilgili örnegimiz uzerinde vurgulanmasý gereken noktalar
1-makrolar mutlaka kullanýlmadan önce tanýmlanmýs olmalýdýr.bu nedenle eger ayný kod kesimi içinde yer alacaklarsa,yordamlardan önce onlarýn tanýmlarýnýn yapýlmasý gerekmektedir.
makrolar istenirse ayrý bir metin dosyasý içine konarak INCLUDE sözde komutu ile programa dahil edilmelidir.

2-makrolar her ne kadar yordamlarda önce tanýmlanmýs olsa da LST uzantýlý dosyanýn sol yanýndaki bellek adresleri incelendiginde tanýmlandýklarý yerde herhangi bir adrese sahip olmadýklarý görülecektir.

3-makrolar ancak yordam içinde adlarýnýn gectigi yerlere kendileri için tanýmlanmýs kod satýrlarýný yazarak bellek üzerinde yer tutmaya baslarlar.LST uzantýlý dosyada MACRO adýnýn yerine ona ait kod yerlestirilmistir.iste bu nedenle programlarýmýz içinde farklý noktalarda cok sayida makro kullanýlmasý programýmýzýn koduna her seferinde mokronun kod blogunun eklenmesi anlamýna gelir ki bu da programýmýzýn kodunun büyümesine neden olur.

4-yazdýr isimli makro,yordam içinde cagrýlýrken yanýna MESAJ isimli degisken parametre olarak verilmiþtir.ancak bu parametreye makro içinde text isimli bir ara tanýmlayýcý ile degerlendirilmektedir.
yazdýr macro text
		lea dx,text
		mov ah,09H
		ýnt 21h
		endm
	yazdýr mesaj	
			
