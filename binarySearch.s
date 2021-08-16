	global binarySearch
	section .text
			; Parameter 1 is a pointer to the int array 
			; Parameter 2 is the left index in the array 
			; Parameter 3 is the right index in the array
			;Parameter 4 is the garget in the array


				;1=rdi 2=rsi 3=rdx 4=rcx
binarySearch:	
	cmp  rsi,rdx			;compare left and right
	jg   Done                      ;if left>=right,end it
	mov  r10,rsi			;store left to r10 register
	add  r10,rdx			;left+right
	shr  r10,1		     	;midvalue			
	cmp  ecx,[r10*4+rdi]			;compare target with array[mid]
	jg   if1			;if target>array[mid]		
	jl   if2			;if target<array[mid]
	jmp  Done2			;else return mid value
Done2:
	;sub r10,1			;index from 0 not 1
	mov rax,r10			;save mid value
	ret				;return it
if1:
	mov rsi,r10			;low=mid
	add rsi,1			;low=mid+1
	jmp binarySearch		;back to the while loop
if2:	
	mov rdx,r10			;high=mid
	sub rdx,1			;high=mid-1
	jmp binarySearch		;back to the while loop
Done:
	mov rax,-1		;Did not find the value,return -1
	ret					;finish it
