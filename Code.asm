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
	 call label_11
	 exit
	label_11 proc 
		mov eax, 7
		mov N, eax
		call label_21
	label_11 endp
	label_21 proc 
		mov eax, 5
		mov M, eax
		call label_31
	label_21 endp
	label_31 proc 
		mov eax, N
		cmp eax, M
		JS label_51
		call label_41
	label_31 endp
	label_41 proc 
		mov eax, temp293
		mov K, eax
		call label_101
	label_41 endp
	label_101 proc 
		call label_1
		call label_61
	label_101 endp
	label_61 proc 
		mov eax, F
		mov F1, eax
		call label_71
	label_61 endp
	label_71 proc 
		mov eax, N
		mov K, eax
		call label_81
	label_71 endp
	label_81 proc 
		call label_1
		call label_91
	label_81 endp
	label_91 proc 
		mov eax, F
		mov F2, eax
		call label_102
	label_91 endp
	label_102 proc 
		mov eax, M
		mov K, eax
		call label_103
	label_102 endp
	label_103 proc 
		call label_1
		call label_104
	label_103 endp
	label_104 proc 
		mov eax, F2
		mov ebx, temp295
		div ebx
		mov temp294, eax
		mov eax, temp294
		mov C, eax
		call label_105
	label_104 endp
	label_105 proc 
		call label_106
	label_105 endp
	label_106 proc 
		call label_107
		call label_51
	label_106 endp
	label_51 proc 
		mov eax, 0
		mov C, eax
		call label_108
	label_51 endp
	label_108 proc 
		call label_107
		call label_109
	label_108 endp
	label_109 proc 
		call label_1
	label_109 endp
	label_1 proc 
		mov eax, 1
		mov F, eax
		call label_110
	label_1 endp
	label_110 proc 
		mov eax, 1
		mov I, eax
		mov eax, K
		mov temp700, eax
		mov eax, 1
		mov temp701, eax
		mov eax, I
		cmp eax, temp700
		JE label_257
		JNS label_257
		call label_111
	label_110 endp
	label_111 proc 
		mov eax, temp296
		mov F, eax
		call label_112
	label_111 endp
	label_112 proc 
		mov eax, I
		add eax, temp701
		mov I, eax
		call label_256
		call label_113
	label_112 endp
	label_113 proc 
		call label_107
	label_113 endp
	label_107 proc 
	label_107 endp
end start
