include \masm32\include\masm32rt.inc

.386
	.data?

		I  dd ?
		M  dd ?
		N  dd ?
		P  dd ?
		R  dd ?
		T  dd ?
		X  dd ?
		I1 dd ?
		P1 dd ?
		temp310 dd ?
		temp311 dd ?
		temp312 dd ?
		temp313 dd ?
		temp314 dd ?
		temp315 dd ?
		temp316 dd ?
		temp317 dd ?
		temp318 dd ?
		temp700 dd ?
		temp701 dd ?
		temp dd ?
	.code
	start:
	 call label_11
	 exit
	label_11: 
		mov eax, 0.000000
		mov X, eax
		call label_31
	label_11 endp
	label_31: 
		mov eax, 7.000000
		mov N, eax
		call label_51
	label_31 endp
	label_51: 
		mov eax, 31.000000
		mov M, eax
		call label_56
	label_51 endp
	label_56: 
		mov eax, 0.000000
		mov R, eax
		call label_61
	label_56 endp
	label_61: 
		mov eax, N
		mov X, eax
		call label_71
	label_61 endp
	label_71: 
		call label_1
		call label_81
	label_71 endp
	label_81: 
		mov eax, R
		cmp eax, 1.000000
		JE label_91
		call label_82
	label_81 endp
	label_82: 
		call label_101
		call label_91
	label_82 endp
	label_91: 
		mov eax, M
		mov X, eax
		call label_102
	label_91 endp
	label_102: 
		call label_1
		call label_21
	label_102 endp
	label_21: 
		call label_101
		call label_1
	label_21 endp
	label_1: 
		mov eax, X
		add eax, 1.000000
		mov temp310, eax
		mov eax, temp310
		mov T, eax
		call label_103
	label_1 endp
	label_103: 
		mov eax, 0.000000
		mov P, eax
		call label_104
	label_103 endp
	label_104: 
		mov eax, 1.000000
		mov P1, eax
		call label_105
	label_104 endp
	label_105: 
		mov eax, P1
		cmp eax, T
		JE label_106
		JNS label_106
		call label_41
	label_105 endp
	label_41: 
		mov eax, P1
		mov ebx, 2.000000
		mul ebx
		mov temp311, eax
		mov eax, temp311
		mov P1, eax
		call label_107
	label_41 endp
	label_107: 
		mov eax, P
		add eax, 1.000000
		mov temp312, eax
		mov eax, temp312
		mov P, eax
		call label_108
	label_107 endp
	label_108: 
		call label_105
		call label_106
	label_108 endp
	label_106: 
		mov eax, P1
		cmp eax, T
		JE label_74
		call label_72
	label_106 endp
	label_72: 
		mov eax, 0.000000
		mov R, eax
		call label_73
	label_72 endp
	label_73: 
		call label_74
	label_73 endp
	label_74: 
		call label_109
		call label_75
	label_74 endp
	label_75: 
		mov eax, I1
		cmp eax, 1.000000
		JE label_78
		call label_76
	label_75 endp
	label_76: 
		mov eax, 0.000000
		mov R, eax
		call label_77
	label_76 endp
	label_77: 
		call label_78
	label_77 endp
	label_78: 
		mov eax, 1.000000
		mov R, eax
		call label_79
	label_78 endp
	label_79: 
		call label_109
	label_79 endp
	label_109: 
		mov eax, 1.000000
		mov I1, eax
		call label_2
	label_109 endp
	label_2: 
		mov eax, P
		cmp eax, 1.000000
		JE label_8
		JS label_8
		call label_3
	label_2 endp
	label_3: 
		mov eax, P
		mov ebx, 2.000000
		div ebx
		mov temp313, eax
		mov eax, temp313
		mov ebx, 2.000000
		mul ebx
		mov temp314, eax
		mov eax, temp314
		cmp eax, P
		JE label_8
		call label_4
	label_3 endp
	label_4: 
		mov eax, 3.000000
		mov I, eax
		mov eax, P
		mov ebx, 2.000000
		div ebx
		mov temp315, eax
		mov eax, temp315
		add eax, 1.000000
		mov temp316, eax
		mov eax, temp700
		mov temp316, eax
		mov eax, temp701
		mov 1.000000, eax
		mov eax, I
		cmp eax, temp700
		JE label_257
		JNS label_257
		call label_5
	label_4 endp
	label_5: 
		mov eax, P
		mov ebx, I
		div ebx
		mov temp317, eax
		mov eax, temp317
		mov ebx, I
		mul ebx
		mov temp318, eax
		mov eax, temp318
		cmp eax, P
		JE label_8
		call label_6
	label_5 endp
	label_6: 
		mov eax, I
		add eax, temp701
		mov I, eax
		call label_256
		call label_7
	label_6 endp
	label_7: 
		call label_8
	label_7 endp
	label_8: 
		mov eax, 0.000000
		mov I1, eax
		call label_9
	label_8 endp
	label_9: 
		call label_101
	label_9 endp
	label_101: 
	label_101 endp
end start
