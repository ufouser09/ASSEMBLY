
;|.............:::BU PROGRAM GIRILEN 10 ADET RAKAMI SIRALAMAKTADIR:::................|
;|--------------------------PROGRAMI YAZAN: SELMAN UZUN -----------------------------|
;|-------------------------------------(08.08.2010)----------------------------------| 
     org 0100h
    .model small
    .stack
    .data
                
    sayilar db 10 dup(?) ;10 boyutlu bir dizi
    mesaj1  db "Siralanacak Rakamlari Giriniz: $"
    mesaj2  db "Rakamlarin Siralanisi         :$"
    altagec db  0Ah,0Dh,24h
    
    .code
    
;_____________________________________________________________________________________
    
    lea dx, mesaj1      ;Ekrana basilacak mesaj1'in adresi dx kayitcisina atandi
    mov ah, 9           ;Rutinle,
    int 21h             ;ekrana yazdiriliyor
           
 sayiyerles proc        ;sayilari yerlestiren prosedurun baslangici
    mov cx,0            ;sayacin ilk degeri sifir
 giristekrar:           
    inc cx              ;cx sayac registerinin degerini arttiriyorum cx=cx+1
    mov si,cx           ;si kaynak registerine cx sayac registerini atiyorum
    mov	ah, 01			;Klavyeden bir rakam,
	int   	21h			;giriliyor.
	mov	sayilar[si],al	;Girilen rakam dizi indeksine ataniyor
	cmp cx,10           ;birinci operant ikincisinden kucukse, 
	jb giristekrar      ;dallan
 sayiyerles endp        ;prosedurun sonu
 
;_____________________________________________________________________________________

    mov dx,10            ;dx registerine 10 degerini ver
    
  sayisirala proc        ;Klavyeden girilen 10 adet rakami siralayan prosedurun baslangici
 
 basa_don:               ;Dongusel adimlarin basi
    mov cx,0             ;cx sayac registerine 0 degerini ata.
 karsilastir:            ;Dizi elemanlarini karsilastirma noktasi
    mov si,cx            ;si kaynak registirina cx sayacinin degerini ver
    mov al,sayilar[si]   ;si index degerine sahip dizinin degerini al kayitcisina ata
    mov bl,sayilar[si+1] ;si+1 index degerine sahip dizinin degerini al kayitcisina ata
    cmp bl,al            ;bl kayitcisinin degeri al'den buyuk yada esitse,
    jae takasyok         ;al,bl kayitci degerlerini dizi icerisinde takas yapma
    mov sayilar[si],bl   ;oyle degilse sagdaki dizi elemaninin degerini soldakine ata, 
    mov sayilar[si+1],al ;soldaki dizi elemaninin degerini de sagdakine ata
 takasyok:               ;takas gerekmez
    inc cx               ;cx kayitcisinin degerini 1 arttir cx=cx+1
    cmp cx,dx            ;cx kayitcisinin degeri dx kaytcisinin degerine esit veya buyukse
    jnb dongukontrol     ;dongunun durumunu kontrol et
    jmp karsilastir      ;aksi durumda sonraki dongu adimina gec, degerleri karsilastir
 dongukontrol:           ;dongunun durum kontrolu
    dec dx               ;sonraki dongu adimina gecmek icin dx degerini 1 azalt dx=dx-1
    cmp dx,0             ;dongu adiminin sonuna geldiyse (dx=0 ise)
    je  siralamaya_son   ;siralamayi durdur
    jmp basa_don         ;dongu adiminin sonunda degilse sonraki dongu adimine gec, karsilastir
 siralamaya_son:         ;siralamayi bitir prosedurun sonuna git
 
 sayisirala endp         ;prosedur sonu
 
;_______________________________________________________________________________________

    lea dx,        altagec ;Alt satira,
    mov ah, 9              ;gecis,
    int 21h                ;yapiliyor. (ekrana yazdirma rutini)
    
    mov dx, offset mesaj2  ;Ekrana basilacak mesaj2'nin adresi dx kayitcisina atandi
    mov ah, 9              ;Rutinle ekrana,
    int 21h                ;basiliyor
    

 ekranabas  proc        ;Girisi yapilan dizi rakamlarini ekrana basan prosedur
    
    mov cx,0            ;sayacin ilk degeri sifir 
    mov ah, 2           ;Ekrana, (bknz. int 21h)
 tekrar:
    mov di,cx           ;di hedef registerine cx sayac registerini atiyorum
    mov dl,sayilar[di]  ;Ekrana basilacak sayilar dizininin elemani
    
    int 21h             ;rakam basiliyor
    inc cx              ;cx sayac registerinin degerini arttiriyorum cx=cx+1
    cmp cx,11           ;cx sayac registeri 11 degerine esitse
    je  bitir           ;dallan
    jmp tekrar          ;degilse tekrar etiketine dallan
 bitir:
    mov ah,4ch          ;ekrana,
    int 21h             ;donus   
               
 ekranabas endp         ;prosedurun sonu
    hlt
      
