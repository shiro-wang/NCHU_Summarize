INCLUDE Irvine32.inc
.data
key BYTE "ABXmv#7"
text BYTE 50 DUP(0)		;��J�w�İ�
byteCount DWORD ?
start BYTE "please key in the plain text: ",0
after BYTE "Cipher text: ",0
decrypt BYTE "Decrypted: ",0


.code
main PROC
	
	mov edx,OFFSET start	;�N�r�겾��edx�Ȧs����
	call WriteString		;��ܦbedx�Ȧs�������r��
	mov edx,OFFSET text		;�w�İϪ��첾
	mov ecx,(SIZEOF text)-1		;���w�ҿ�J�r�����̤j�ƶq
	call ReadString			;��J�r��
	mov byteCount,eax		;�s�����J���r���ƶq
	XOR eax,eax
	
	mov edx,0				;�����w�g�B�z�X�Ӧr��
	mov esi,OFFSET text
	mov ebx,OFFSET key
	mov ecx,LENGTHOF key	;���X��key�N���y���X��
	L1:
		mov al,[esi]
		mov ah,[ebx]
		XOR al,ah			;�쥻al,key:ah,��XOR
		mov [esi],al		;�⵲�G�s�^
		inc esi
		inc ebx
		inc edx
		cmp edx,byteCount	;��������h���X
		je next
		loop L1
	mov ecx,LENGTHOF key	;key�����o�٨S����,���]ecx
	mov ebx,OFFSET key		;���]ebx�^key����
	jmp L1					;�^�h�~��

	next:
		mov edx,OFFSET after
		call WriteString
		mov edx,OFFSET text
		call WriteString
	
	call Crlf

	mov esi,OFFSET text
	mov ebx,OFFSET key
	mov edx,0
	XOR eax,eax
	mov ecx,LENGTHOF key
	L2:
		mov al,[esi]
		mov ah,[ebx]
		XOR al,ah
		mov [esi],al
		inc esi
		inc ebx
		inc edx
		cmp edx,byteCount
		je next2
		loop L2
	mov ecx,LENGTHOF key
	mov ebx,OFFSET key
	jmp L2

	next2:
		mov edx,OFFSET decrypt
		call WriteString
		mov edx,OFFSET text
		call WriteString

exit
main ENDP

END main