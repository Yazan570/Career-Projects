
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
.stack 100
.data 
input db "Please enter a number of base 5 (digits from 0-4 only allowed and a max of 5 digits): "   
F db 0
num dw 0
decimal dw ?
revdecdigits db 0,0,0,0 
decdigits db 0,0,0,0
binary dw ?
hexa dw ?              
msg db 0dh,0ah,"Error",0dh,0ah,"Press any key to continue: " 
digits dw 0,0,0,0,0
indxofDigits dw 0 
numofDigits dw 0  
revbindigits db 0,0,0,0,0,0,0,0,0,0,0,0
bindigits db 0,0,0,0,0,0,0,0,0,0,0,0
revhexdigits db 0,0,0
hexdigits db 0,0,0
decmsg db "Decimal: "
binmsg db "Binary: "
hexmsg db "HexaDecimal: "
.code   
mov ax,@data
mov ds,ax
start:   
call Intro
mov num,0
mov F,0
mov si,0
mov di,0
repeat:call GetNum
       cmp si,0
       jne continuee
       cmp F,1
       jne continuee
       jmp l6
       continuee: 
       cmp F,1
       je here
       inc si        
       cmp si,6
       je l6
      inc di 
      cmp F,0       
       je repeat
       
   
   here: mov numofDigits,di
   dec di
   mov indxofDigits,di
   inc di                        
   mov cx,di 
   dec di
   mov dx,0
   mov bx,10 
   mov ax,num
   conv: 
        
         div bx
         mov digits+di,dx
         sub di,2
         mov dx,0
         loop conv
         mov num,ax   
         mov cx,numofDigits
         mov si,0
         mov bx,0
         mov di,indxofDigits
         todec: push cx
                 cmp si,0
                 je x
                 cmp si,1
                 je y 
                 cmp si,2
                 je z
                 cmp si,3
                 je w
                 cmp si,4
                 je q
                 x: mov bx,1
                 jmp c
                 y:mov bx,5
                 jmp c
                 z: mov bx,25                                      
                 jmp c
                 w: mov bx,125
                 jmp c
                 q: mov bx,625
                c:mov cx,bx
                mov ax,0 
                inner: 
                add ax,digits+di
                loop inner
                add decimal,ax 
                pop cx
                inc si
                sub di,2
                loop todec
                
        
        mov ax,decimal
        mov cx,12
        mov si,0
        mov bx,2
        tobin: mov dx,0
               div bx      
               mov revbindigits+si,dl 
               inc si 
               cmp ax,0 
               loopne tobin 
          
          mov cx,si
          mov si,0
          mov di,11      
          copy: 
          mov al,revbindigits+si
          mov bindigits+di,al
                inc si
                dec di
                loop copy     
         push si       
         mov ax,decimal
                
         mov cx,4
         mov si,0
         mov bx,10
         dc:
         mov dx,0 
         div bx
         mov revdecdigits+si,dl
         inc si
         cmp ax,0
         loopne dc
         mov cx,si
         dec si
         mov di,0
         loo:mov al,revdecdigits+si
         mov decdigits+di,al
         dec si
         inc di
         loop loo
              
        push di        
         mov ax,decimal
         mov si,0
         mov bx,16
         tohex: 
         mov dx,0
         div bx
         cmp dl,10
         je a1
         cmp dl,11
         je a2
         cmp dl,12
         je a3
         cmp dl,13
         je a4
         cmp dl,14
         je a5
         cmp dl,15
         je a6
         mov revhexdigits+si,dl
         jmp sk
         a1: mov revhexdigits+si,'A'
             jmp sk
          a2: mov revhexdigits+si,'B'
             jmp sk
          a3: mov revhexdigits+si,'C'
             jmp sk
          a4: mov revhexdigits+si,'D'
             jmp sk
          a5: mov revhexdigits+si,'E'
             jmp sk                 
           a6: mov revhexdigits+si,'F'
            
         sk:
         inc si
         cmp ax,0
         loopne tohex
         
         mov cx,si
         dec si
         mov di,si
         mov si,0        
         flip: mov al,revhexdigits+si
               mov hexdigits+di,al
               inc si
               dec di
               loop flip       
                
                
                
                
                
                
          pop di      
           mov bx,si     
         mov ah,2
         mov dl,00ah
         int 21h
         mov dl,00dh
         int 21h
        mov cx,9
        mov si,0
       demsg:mov dl,decmsg[si]
             int 21h
             inc si
             loop demsg   
        mov si,0
       
        mov cx,di
        printdec: mov dl,decdigits+si 
                  add dl,30h
                  int 21h
                  inc si
                  loop printdec
         mov dl,00ah
         int 21h
         mov dl,00dh
         int 21h        
       
       
       mov ah,2
        mov cx,8
        mov si,0
       bimsg:mov dl,binmsg[si]
             int 21h
             inc si
             loop bimsg
              
             pop si
             mov cx,12
             mov si,0
             check:
             cmp bindigits+si,1
             je sk2 
             inc si
             loop check
             cmp cx,0
             jne sk2
             mov dl,'0'
             int 21h
             jmp sk1
             
             sk2:
       binprint: mov dl,bindigits+si
                 add dl,30h
                 inc si
                 int 21h
                 loop binprint
       sk1:          
       mov ah,2
       mov dl,00ah
       int 21h
       mov dl,00dh
       int 21h           
       mov cx,13
       mov si,0
       hxmsg:mov dl,hexmsg+si
             int 21h
             inc si
             loop hxmsg
             
        
       mov si,bx
       mov cx,si
       mov si,0              
       hexprint: mov dl,hexdigits+si
                 cmp dl,39h
                 ja change
                  add dl,30h 
                  int 21h 
                  jmp k 
                  change: int 21h        
                 k: inc si
                  loop hexprint               
                 jmp last
l6: call ErrorPrinting
    mov ah,1
    int 21h
    mov al,3
    jmp j
   j: mov ax,3
    int 10h 
    jmp start
       ret       




ErrorPrinting proc  
mov ah,2
mov cx,36
mov si,0
l1: mov dl,msg[si]
    int 21h
    inc si
    loop l1 ; error is printed when more than 5 digits are entered, and if a number greater than 4 is entered and if any random character not between 0 and 4 is entered
ret
endp  

GetNum proc
mov ah,1
int 21h 
cmp al,'='
je l4
sub al,30h  
;cmp al,0
;je l3
cmp al,0
jb e
cmp al,4
ja e
mov cx,10
mov bx,0
mov dh,0
mov dl,al
l2: add bx,num
    loop l2
add bx,dx
mov num,bx
ret
l4: mov F,1 
ret 
;l3: mov F,2
;ret
e:;call ErrorPrinting 
jmp l6
ret 
endp


Intro proc
mov ah,2
mov di,0
mov cx,86
lp: mov dl,input[di]
    int 21h
    inc di                
    loop lp    
ret
endp  


 last:
 end