include \masm32\include\masm32rt.inc

.386
	.data?

		M  dd ?
		N  dd ?
		X  dd ?
		C1 dd ?
		T1 dd ?
		C2 dd ?
		T2 dd ?
		T3 dd ?
		temp307 dd ?
		temp308 dd ?
		temp309 dd ?
		temp310 dd ?
		temp311 dd ?
		temp312 dd ?
		temp313 dd ?
		temp314 dd ?
		temp315 dd ?
	.code
	start:
	 call label_11
	 exit
	label_11 proc 
		mov eax, 5
		mov N, eax
		call label_21
	label_11 endp
	label_21 proc 
		mov eax, 6
		mov M, eax
		call label_31
	label_21 endp
	label_31 proc 
		mov eax, 1
		mov X, eax
		call label_32
	label_31 endp
	label_32 proc 
		mov eax, 0
		mov C1, eax
		call label_33
	label_32 endp
	label_33 proc 
		mov eax, 0
		mov C2, eax
		call label_41
	label_33 endp
	label_41 proc 
		mov eax, X
		cmp eax, N
		JS label_81
		call label_51
	label_41 endp
	label_51 proc 
		mov eax, 1
		mov X, eax
		call label_61
	label_51 endp
	label_61 proc 
		mov eax, X
		cmp eax, M
		JS label_101
		call label_71
	label_61 endp
	label_71 proc 
		call label_1
		call label_81
	label_71 endp
	label_81 proc 
		mov eax, X
		mov T1, eax
		call label_82
	label_81 endp
	label_82 proc 
		mov eax, 0
		mov T2, eax
		call label_83
	label_82 endp
	label_83 proc 
		mov eax, 0
		mov T3, eax
		call label_91
	label_83 endp
	label_91 proc 
		mov eax, T1
		cmp eax, 0
		JE label_102
		call label_92
	label_91 endp
	label_92 proc 
		mov eax, T1
		mov ebx, 10
		div ebx
		mov temp307, eax
		mov eax, temp307
		mov T3, eax
		call label_93
	label_92 endp
	label_93 proc 
		mov eax, T3
		mov ebx, 10
		mul ebx
		mov temp308, eax
		mov eax, temp308
		mov T3, eax
		call label_94
	label_93 endp
	label_94 proc 
		mov eax, T1
		mov ebx, 10
		div ebx
		mov temp309, eax
		mov eax, temp309
		mov T1, eax
		call label_103
	label_94 endp
	label_103 proc 
		mov eax, T2
		add eax, T3
		mov temp310, eax
		mov eax, temp310
		mov T2, eax
		call label_104
	label_103 endp
	label_104 proc 
		call label_91
		call label_102
	label_104 endp
	label_102 proc 
		mov eax, T2
		cmp eax, N
		JNE label_105
		call label_106
	label_102 endp
	label_106 proc 
		mov eax, 1
		mov C1, eax
		call label_105
	label_106 endp
	label_105 proc 
		call label_41
		call label_101
	label_105 endp
	label_101 proc 
		mov eax, X
		mov T1, eax
		call label_107
	label_101 endp
	label_107 proc 
		mov eax, 0
		mov T2, eax
		call label_108
	label_107 endp
	label_108 proc 
		mov eax, 0
		mov T3, eax
		call label_109
	label_108 endp
	label_109 proc 
		mov eax, T1
		cmp eax, 0
		JE label_102
		call label_110
	label_109 endp
	label_110 proc 
		mov eax, T1
		mov ebx, 10
		div ebx
		mov temp311, eax
		mov eax, temp311
		mov T3, eax
		call label_111
	label_110 endp
	label_111 proc 
		mov eax, T3
		mov ebx, 10
		mul ebx
		mov temp312, eax
		mov eax, temp312
		mov T3, eax
		call label_112
	label_111 endp
	label_112 proc 
		mov eax, T1
		mov ebx, 10
		div ebx
		mov temp313, eax
		mov eax, temp313
		mov T1, eax
		call label_113
	label_112 endp
	label_113 proc 
		mov eax, T2
		add eax, T1
		mov temp314, eax
		mov eax, temp314
		sub eax, T3
		mov temp315, eax
		mov eax, temp315
		mov T2, eax
		call label_114
	label_113 endp
	label_114 proc 
		call label_91
		call label_115
	label_114 endp
	label_115 proc 
		mov eax, T2
		cmp eax, M
		JNE label_105
		call label_116
	label_115 endp
	label_116 proc 
		mov eax, 1
		mov C2, eax
		call label_117
	label_116 endp
	label_117 proc 
		call label_61
		call label_1
	label_117 endp
	label_1 proc 
	label_1 endp
end start
