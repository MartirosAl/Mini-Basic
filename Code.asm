include \masm32\include\masm32rt.inc

.386
	.data?

		C  dd ?
		F  dd ?
		I  dd ?
		K  dd ?
		M  dd ?
		N  dd ?
		F1 dd ?
		F2 dd ?
		temp293 dd ?
		temp294 dd ?
		temp295 dd ?
		temp296 dd ?
		temp700 dd ?
		temp701 dd ?
		temp dd ?
	.code
start:

	label_11: 
		mov eax, 7.000000
		mov N, eax
		call label_21
	label_11 endp
	label_21: 
		mov eax, 5.000000
		mov M, eax
		call label_31
	label_21 endp
	label_31: 
		mov eax, N
		cmp eax, M
		JS label_Y0
		call label_41
	label_31 endp
	label_41: 
		mov eax, N
		sub M
		mov temp293, eax
		mov eax, temp293
		mov K, eax
		call label_101
	label_41 endp
	label_101: 
		call label_A
		call label_61
	label_101 endp
	label_61: 
		mov eax, F
		mov F1, eax
		call label_71
	label_61 endp
	label_71: 
		mov eax, N
		mov K, eax
		call label_81
	label_71 endp
	label_81: 
		call label_A
		call label_91
	label_81 endp
	label_91: 
		mov eax, F
		mov F2, eax
		call label_102
	label_91 endp
	label_102: 
		mov eax, M
		mov K, eax
		call label_103
	label_102 endp
	label_103: 
		call label_A
		call label_104
	label_103 endp
	label_104: 
		mov eax, F1
		mov ebx, F
		mul ebx
		mov temp295, eax
		mov eax, F2
		mov ebx, temp295
		div ebx
		mov temp294, eax
		mov eax, temp294
		mov C, eax
		call label_105
	label_104 endp
	label_105: 
		call label_106
	label_105 endp
	label_106: 
		call label_C3
		call label_51
	label_106 endp
	label_51: 
		mov eax, 0.000000
		mov C, eax
		call label_108
	label_51 endp
	label_108: 
		call label_C3
		call label_109
	label_108 endp
	label_109: 
		call label_1
	label_109 endp
	label_1: 
		mov eax, 1.000000
		mov F, eax
		call label_110
	label_1 endp
	label_110: 
		mov eax, 1.000000
		mov I, eax
		mov eax, temp700
		mov K, eax
		mov eax, temp701
		mov 1.000000, eax
		mov eax, I
		cmp eax, temp700
		JE label_W8
		JNS label_W8
		call label_111
	label_110 endp
	label_111: 
		mov eax, F
		mov ebx, I
		mul ebx
		mov temp296, eax
		mov eax, temp296
		mov F, eax
		call label_112
	label_111 endp
	label_112: 
		mov eax, I
		add eax, temp701
		mov I, eax
		call label_V8
		call label_113
	label_112 endp
	label_113: 
		call label_107
	label_113 endp
	label_107: 
end start
