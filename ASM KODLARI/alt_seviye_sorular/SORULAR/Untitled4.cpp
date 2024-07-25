------------------------------------------------------------------------------------

; PROGRAM : Örnek 10-2-1.Asm
; Toplama isimli yardýmcý yordamýn içinde bulunduðu program                  
------------------------------------------------------------------------------------

          PAGE 60,80                                                           
          TITLE yardýmcý procedure çaðýrma
          PUBLIC TOPLAMA
CODES     SEGMENT PARA 'CODE'                                               
          ASSUME CS:CODES
TOPLAMA PROC FAR                                                     

------------------------------------------------------------------------------------

; iþlem bloðu baþlýyor
------------------------------------------------------------------------------------
 
          XOR AX, AX             ; AX yazmacýný sýfýrla
          ADD AL, BL             ; AL üzerinde toplamaya baþla
          ADD AL, BH 
          ADC AH, 0              ; CF oluþmasý durumunda bunu AH'ya aktar 
          RET                    ; çaðýrýldýðýn yere don
TOPLAMA ENDP
CODES     ENDS
          END
------------------------------------------------------------------------------------
örnek 10-2-1 asm isimli dosya da alýsa geldigimiz kodlamanýn dýsýnda kalan bazý özelliklerin vurgulanmasý gereklidir.bunlar:
	1-yýgýn ve veri kesimi tanýmlamalarý yapýlmamýstýr.yýgýn,toplama yordamýný cagýran program tarafýndan tanýmlandýgý için tekrar tanýmlanmasýna gerek yoktur.ayrýca toplama yordamý içinde ayrý bir yýgýn tanýmý yapýlacak olursa dönus adreslerine erisim mumkun olmýyacaktýr.
	benzer biçimde toplama yordamýnýn içinde bulundugu programa has degisken de olmadýgý için veri kesimi tanýmlanmamýstýr.
	2-exe tipindeki programlarda kontrolu elinde bulunduran yordam far olarak tanýmlanýrken,geri donusu saglamak üzere gerekli adresleri yýgýna yerlestýrebilmek için 
	push ds
	xor ax,ax
	push ax
	
	komutlarý ardýndan veri kesimine erisebilmek için
	
	mov ax,veri_kesim_ismi
	mov ds,ax
	
	komutlarý kullanýlmalýdýr.
	oysa bu komut satýrlarý örnek 10-2-1 asm içinde bulunmaz.bunun arkasýnda yatan neden toplama isimli yordamýnýn kendi basýna calýsacak yani kontrolu elinde bulunduracak türde olmasýdýr.
	o zaman dönüs adreslerinin(isletim sistemine donmek için)yýgýnda saklanmasý,toplama isimli yordamý cagýranýn sorumlulugunda olmalýdýr
	
	3-programýn bitisini belirleyen end sözde komutunun sonunda baslangýc noktasý olarak hicbir yordam isminin yazýlmamýs olmasý da dikkat cekicidir.örnek 10-2-1.asm isimli program hicbir zaman kendi basýna çalýsmak üzere tasarlanmadýgý için baslangýc noktasý olarak bir yordam ismi yazmaya gerek yoktur.
	
	4-toplama yordamýnýn baska programlar tarafýndan da cagrýlabilmesi için 
	PUBLÝC TOPLAMA 
	sözde komutundan yararlanýlmýstýr
	
	
	
	görüldügü gibi örnek 10-2.asm isimli program,örnek 10-2-1.asm isimli program içinde yer alan bir yordamý kullanmak istemektedir.programlarda kullanýlan EXTRN/PUBLIC sözde komutlarý yardýmýyla kimin,kimden hangi yordamý kullanacagý belirlenmis derleme islemleri sonucunda örnek 10-2.OBJ...
	

