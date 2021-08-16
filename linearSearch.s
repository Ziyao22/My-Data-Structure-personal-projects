


	global linearSearch

	section .text


linearSearch:
	xor  r10,r10			;zero out the counter i
loop1:	
	cmp  rsi,r10			;compare the size with i
	je   Done			;if they are equal,end it
	mov  r11,[rdi+r10*4]		;This is not needed
	cmp  edx,[rdi+r10*4]		;compare target with array[i]
	je	Done1			;if they are equal,return it
	add  r10,1			;i++
	jmp  loop1			;back to the begining of the loop	
Done:
	mov  rax,-1			;if not find, return -1
	ret				;finish it
Done1:
	mov  rax,r10	
	ret
