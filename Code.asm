include \masm32\include\masm32rt.inc

.386
	.data?

		A  dd ?
		D  dd ?
		I  dd ?
		J  dd ?
		L  dd ?
		M  dd ?
		N  dd ?
		P  dd ?
		S  dd ?
		T  dd ?
		X  dd ?
		R1 dd ?
		T1 dd ?
		R2 dd ?
		temp304 dd ?
		temp305 dd ?
		temp306 dd ?
		temp307 dd ?
		temp308 dd ?
		temp309 dd ?
		temp310 dd ?
		temp311 dd ?
		temp312 dd ?
		temp313 dd ?
		temp700 dd ?
		temp701 dd ?
		temp702 dd ?
		temp703 dd ?
	.code
	start:
	 call label_11
	 exit
	label_11 proc 
		mov eax, 100
		mov N, eax
		call label_21
		 ret
	label_11 endp
	label_21 proc 
		mov eax, 370
		mov M, eax
		call label_31
		 ret
	label_21 endp
	label_31 proc 
		mov eax, N
		mov X, eax
		call label_41
		 ret
	label_31 endp
	label_41 proc 
		call label_1
		call label_51
		 ret
	label_41 endp
	label_51 proc 
		mov eax, A
		mov R1, eax
		call label_61
		 ret
	label_51 endp
	label_61 proc 
		mov eax, M
		mov X, eax
		call label_71
		 ret
	label_61 endp
	label_71 proc 
		call label_1
		call label_81
		 ret
	label_71 endp
	label_81 proc 
		mov eax, A
		mov R2, eax
		call label_91
		 ret
	label_81 endp
	label_91 proc 
		call label_100
		call label_1
		 ret
	label_91 endp
	label_1 proc 
		call label_101
		 ret
	label_1 endp
	label_101 proc 
		mov eax, 0
		mov L, eax
		call label_102
		 ret
	label_101 endp
	label_102 proc 
		mov eax, 1
		mov P, eax
		call label_103
		 ret
	label_102 endp
	label_103 proc 
		mov eax, P
		cmp eax, X
		JNS label_Z2
		call label_105
		 ret
	label_103 endp
	label_105 proc 
		mov eax, L
		add eax, 1
		mov temp304, eax
		mov eax, temp304
		mov L, eax
		call label_106
		 ret
	label_105 endp
	label_106 proc 
		mov eax, P
		mov ebx, 10
		imul ebx
		mov temp305, eax
		mov eax, temp305
		mov P, eax
		call label_107
		 ret
	label_106 endp
	label_107 proc 
		call label_103
		call label_104
		 ret
	label_107 endp
	label_104 proc 
		mov eax, 0
		mov S, eax
		call label_108
		 ret
	label_104 endp
	label_108 proc 
		mov eax, X
		mov T, eax
		call label_109
		 ret
	label_108 endp
	label_109 proc 
		mov eax, P
		mov ebx, 10
		idiv ebx
		mov temp306, eax
		mov eax, temp306
		mov P, eax
		call label_110
		 ret
	label_109 endp
	label_110 proc 
		mov eax, 1
		mov I, eax
		mov eax, L
		mov temp700, eax
		mov eax, 1
		mov temp701, eax
		mov eax, I
		cmp eax, temp700
		JE label_257
		JNS label_257
		call label_111
		 ret
	label_110 endp
	label_111 proc 
		mov eax, 0
		mov J, eax
		mov eax, 9
		mov temp702, eax
		mov eax, 1
		mov temp703, eax
		mov eax, J
		cmp eax, temp702
		JE label_259
		JNS label_259
		call label_112
		 ret
	label_111 endp
	label_112 proc 
		mov eax, J
		mov ebx, P
		imul ebx
		mov temp307, eax
		mov eax, temp307
		mov T1, eax
		call label_113
		 ret
	label_112 endp
	label_113 proc 
		mov eax, T1
		cmp eax, T
		JNS label_J3
		call label_115
		 ret
	label_113 endp
	label_115 proc 
		mov eax, J
		add eax, temp703
		mov J, eax
		call label_258
		call label_114
		 ret
	label_115 endp
	label_114 proc 
		mov eax, J
		sub eax, 1
		mov temp308, eax
		mov eax, temp308
		mov D, eax
		call label_116
		 ret
	label_114 endp
	label_116 proc 
		mov eax, D
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mul eax
		mov temp310, eax
		mov eax, S
		add eax, temp310
		mov temp309, eax
		mov eax, temp309
		mov S, eax
		call label_117
		 ret
	label_116 endp
	label_117 proc 
		mov eax, D
		mov ebx, P
		imul ebx
		mov temp312, eax
		mov eax, T
		sub eax, temp312
		mov temp311, eax
		mov eax, temp311
		mov T, eax
		call label_118
		 ret
	label_117 endp
	label_118 proc 
		mov eax, P
		mov ebx, 10
		idiv ebx
		mov temp313, eax
		mov eax, temp313
		mov P, eax
		call label_119
		 ret
	label_118 endp
	label_119 proc 
		mov eax, I
		add eax, temp701
		mov I, eax
		call label_256
		call label_120
		 ret
	label_119 endp
	label_120 proc 
		mov eax, S
		cmp eax, X
		JE label_121
		call label_122
		 ret
	label_120 endp
	label_122 proc 
		mov eax, 0
		mov A, eax
		call label_123
		 ret
	label_122 endp
	label_123 proc 
		call label_124
		call label_121
		 ret
	label_123 endp
	label_121 proc 
		mov eax, 1
		mov A, eax
		call label_124
		 ret
	label_121 endp
	label_124 proc 
		ret
		call label_100
		 ret
	label_124 endp
	label_100 proc 
	label_100 endp
end start
