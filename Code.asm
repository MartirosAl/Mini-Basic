include\masm32\include\masm32rt.inc

.386
	.data?

	D dd ?
	F dd ?
	M dd ?
	N dd ?
	P dd ?
	C1 dd ?
	S1 dd ?
	T1 dd ?
	C2 dd ?
	S2 dd ?
	T2 dd ?

	.data

	temp311 dd 0
	temp312 dd 0
	temp313 dd 0
	temp314 dd 0
	temp315 dd 0
	temp316 dd 0
	temp700 dd 0
	temp701 dd 0
	temp702 dd 0
	temp703 dd 0
	temp704 dd 0
	temp705 dd 0
	temp706 dd 0
	temp707 dd 0

	.code
	start:
	 call label_10
	 exit
	label_10 proc 
		mov eax, 120
		mov N, eax
		call label_20
		ret
	label_10 endp
	label_20 proc 
		mov eax, 240
		mov M, eax
		call label_30
		ret
	label_20 endp
	label_30 proc 
		mov eax, 1
		mov S1, eax
		call label_40
		ret
	label_30 endp
	label_40 proc 
		mov eax, 1
		mov S2, eax
		call label_50
		ret
	label_40 endp
	label_50 proc 
		call label_1050
		call label_60
		ret
	label_50 endp
	label_60 proc 
		call label_2050
		call label_70
		ret
	label_60 endp
	label_70 proc 
		mov eax, S1
		cmp eax, M
		JNE label_110
		call label_80
		ret
	label_70 endp
	label_80 proc 
		mov eax, S2
		cmp eax, N
		JNE label_110
		call label_90
		ret
	label_80 endp
	label_90 proc 
		mov eax, 1
		mov F, eax
		call label_100
		ret
	label_90 endp
	label_100 proc 
		call label_120
		call label_110
		ret
	label_100 endp
	label_110 proc 
		mov eax, 0
		mov F, eax
		call label_120
		ret
	label_110 endp
	label_120 proc 
		call label_5000
		call label_1000
		ret
	label_120 endp
	label_1000 proc 
		call label_1050
		ret
	label_1000 endp
	label_1050 proc 
		mov eax, 2
		mov C1, eax
		mov eax, N
		isub eax, 1
		mov temp311, eax
		mov eax, temp311
		mov temp700, eax
		mov eax, 1
		mov temp701, eax
		call label_256
		ret
	label_1050 endp
	label_256 proc 
		mov eax, C1
		cmp eax, temp700
		JE label_257
		JNS label_257
		call label_1060
		ret
	label_256 endp
	label_1060 proc 
		call label_3000
		call label_1070
		ret
	label_1060 endp
	label_1070 proc 
		mov eax, T1
		cmp eax, 1
		JE label_1090
		call label_1080
		ret
	label_1070 endp
	label_1080 proc 
		mov eax, C1
		iadd eax, temp701
		mov C1, eax
		call label_256
		call label_257
		ret
	label_1080 endp
	label_257 proc 
		call label_1090
		ret
	label_257 endp
	label_1090 proc 
		mov eax, S1
		iadd eax, C1
		mov temp312, eax
		mov eax, temp312
		mov S1, eax
		call label_1100
		ret
	label_1090 endp
	label_1100 proc 
		call label_1080
		call label_1110
		ret
	label_1100 endp
	label_1110 proc 
		ret
		call label_2000
		ret
	label_1110 endp
	label_2000 proc 
		call label_2050
		ret
	label_2000 endp
	label_2050 proc 
		mov eax, 2
		mov C2, eax
		mov eax, M
		isub eax, 1
		mov temp313, eax
		mov eax, temp313
		mov temp702, eax
		mov eax, 1
		mov temp703, eax
		call label_258
		ret
	label_2050 endp
	label_258 proc 
		mov eax, C2
		cmp eax, temp702
		JE label_259
		JNS label_259
		call label_2060
		ret
	label_258 endp
	label_2060 proc 
		call label_4000
		call label_2070
		ret
	label_2060 endp
	label_2070 proc 
		mov eax, T2
		cmp eax, 1
		JE label_2090
		call label_2080
		ret
	label_2070 endp
	label_2080 proc 
		mov eax, C2
		iadd eax, temp703
		mov C2, eax
		call label_258
		call label_259
		ret
	label_2080 endp
	label_259 proc 
		call label_2090
		ret
	label_259 endp
	label_2090 proc 
		mov eax, S2
		iadd eax, C2
		mov temp314, eax
		mov eax, temp314
		mov S2, eax
		call label_2100
		ret
	label_2090 endp
	label_2100 proc 
		call label_2080
		call label_2110
		ret
	label_2100 endp
	label_2110 proc 
		ret
		call label_3000
		ret
	label_2110 endp
	label_3000 proc 
		mov eax, 0
		mov D, eax
		call label_3010
		ret
	label_3000 endp
	label_3010 proc 
		mov eax, 0
		mov D, eax
		mov eax, N
		mov temp704, eax
		mov eax, 1
		mov temp705, eax
		call label_260
		ret
	label_3010 endp
	label_260 proc 
		mov eax, D
		cmp eax, temp704
		JE label_261
		JNS label_261
		call label_3020
		ret
	label_260 endp
	label_3020 proc 
		mov eax, D
		mov ebx, C1
		imul ebx
		mov temp315, eax
		mov eax, temp315
		mov P, eax
		call label_3030
		ret
	label_3020 endp
	label_3030 proc 
		mov eax, P
		cmp eax, N
		JE label_3050
		JNS label_3050
		call label_3040
		ret
	label_3030 endp
	label_3040 proc 
		mov eax, D
		iadd eax, temp705
		mov D, eax
		call label_260
		call label_261
		ret
	label_3040 endp
	label_261 proc 
		call label_3050
		ret
	label_261 endp
	label_3050 proc 
		mov eax, P
		cmp eax, N
		JE label_3080
		call label_3060
		ret
	label_3050 endp
	label_3060 proc 
		mov eax, 0
		mov T1, eax
		call label_3070
		ret
	label_3060 endp
	label_3070 proc 
		ret
		call label_3080
		ret
	label_3070 endp
	label_3080 proc 
		mov eax, 1
		mov T1, eax
		call label_3090
		ret
	label_3080 endp
	label_3090 proc 
		ret
		call label_4000
		ret
	label_3090 endp
	label_4000 proc 
		mov eax, 0
		mov D, eax
		call label_4010
		ret
	label_4000 endp
	label_4010 proc 
		mov eax, 0
		mov D, eax
		mov eax, N
		mov temp706, eax
		mov eax, 1
		mov temp707, eax
		call label_262
		ret
	label_4010 endp
	label_262 proc 
		mov eax, D
		cmp eax, temp706
		JE label_263
		JNS label_263
		call label_4020
		ret
	label_262 endp
	label_4020 proc 
		mov eax, D
		mov ebx, C2
		imul ebx
		mov temp316, eax
		mov eax, temp316
		mov P, eax
		call label_4030
		ret
	label_4020 endp
	label_4030 proc 
		mov eax, P
		cmp eax, M
		JE label_4050
		JNS label_4050
		call label_4040
		ret
	label_4030 endp
	label_4040 proc 
		mov eax, D
		iadd eax, temp707
		mov D, eax
		call label_262
		call label_263
		ret
	label_4040 endp
	label_263 proc 
		call label_4050
		ret
	label_263 endp
	label_4050 proc 
		mov eax, P
		cmp eax, M
		JE label_4080
		call label_4060
		ret
	label_4050 endp
	label_4060 proc 
		mov eax, 0
		mov T2, eax
		call label_4070
		ret
	label_4060 endp
	label_4070 proc 
		ret
		call label_4080
		ret
	label_4070 endp
	label_4080 proc 
		mov eax, 1
		mov T2, eax
		call label_4090
		ret
	label_4080 endp
	label_4090 proc 
		ret
		call label_5000
		ret
	label_4090 endp
	label_5000 proc 
	label_5000 endp
end start
