	global product
	global power
	
	section .text

product:
	xor  rax,rax           ;zero out the return register
	xor  r10,r10           ;zero out the counter i
loop1:	
	cmp  r10,rsi           ;does i==n?
	je  productDone       ;if input2 is =0,end
	add  rax,rdi           ;add input1 to rai
	inc  r10               ;input2+=1
	jmp  loop1             ;back to the begining of the loop
productDone:
	ret			;return to the caller
power:
	mov  r15,rsi		;move input2 to r15
	;sub  r15,1		;r15=r15-1	
	mov  r14,rdi		;move input1 to input2
	xor  rax,rax		;zero out the return register
	;xor  r10,r10		;zero out the counter i
	cmp   rsi,0
	jg    loop2
	je    powerDone
loop2:	
	;cmp  rsi,0		;does i==n?
	;je    powerDone	;if input2 is =0,end
	dec   rsi		;input2--
	call  power		;call the function
	;mov   rax,rdi		;save the value to rax
	mov   rsi,rax	
	call   product		;back to the begining of the pre function
	 ret
powerDone:
	mov rax,1		
	ret			;end it
