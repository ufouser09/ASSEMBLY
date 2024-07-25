               Þekil 25-16: Eþik deðer kontrolü akýþ diyagramý


; COv tipi programda veri kesiminin kod kesiminden once yerleþtirildiði ve 
; 3WP kodu ýle ana yordwrA wýlandýðý yapý kullanýlmýþtýr.

ODESG     SEGMENT PARA 'kod'
          ORG 100h
          ASSuME DS:CODESG, 55:CODESG, CS:CODESG
BASLA:    JMP SICAKLIK
N         DW 365
DIZI      DB 365 DUP(?)
ESIK      DB -20
SONUC     DB ?
SICAKLIK PROC NEAr
          XoR SI, SI              ;DIZI indis yazmasý SI sýfýrlanýr. 
          MOV CX, N               ;DIZI'nin boyutu N, CX yazmacýna atýlýr. 
          MoV AL, ESýk            ;esik degiskenin deðeri AL içerisine konur. 
DON:      CmP SI, CX              ;SI ile CX karþýlaþtýrýlýr.
          jAE YANLIS              ;SI, CX deðerine küçük eþitse YANLIS 
                                  ;etýketine atlanýr.
          cmp AL, DIZI[SI]        ;SI, CX deðerinden buyukse AL ile D1ZI'nin 
                                  ;SI indisindeki eleman karþýlaþtýrýlýr. 
          JG DOGRU                ;AL, DIZI'nin SI indisli elemanýndan 
                                  ;buyükse DOGRU etiketine atlanýr.
          ýNC SI                  ;DIZI byte tammlý olduðu için SI 
                                  ;1 arttýrýlýr.
          JMP DON                 ;Cevrim koþuluna gitmek için DON etiketine 
                                  ;atlanýr.
YANLIS:   MOV SONUC, 0            ;SONUC deðiþkenine 0 deðeri atanarak
          JMP SON                 ;SON etiketýne atlamr. Yani esýk deðerin 
                                  ;altýnda bir deðer bulunamamýþtýr.
DOGRU:    MOV SONUC, 1            ;SoNUC deðiþkemne 1 deðeri atanýr. Yani


