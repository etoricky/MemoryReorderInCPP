int a, b;
int main(void) {
a = b + 1;
b = 0;
}

// gcc -v -> gcc version 6.3.0 MinGW

// gcc -S -masm=intel gcc-instruction-reorder.cpp
/*
	call	___main
	mov	eax, DWORD PTR _b
	add	eax, 1
	mov	DWORD PTR _a, eax
	mov	DWORD PTR _b, 0 // b after a
	mov	eax, 0
	leave
*/

// gcc -S -masm=intel gcc-instruction-reorder.cpp -O3
/*
	call	___main
	mov	eax, DWORD PTR _b
	mov	DWORD PTR _b, 0 // b before a
	add	eax, 1
	mov	DWORD PTR _a, eax
	xor	eax, eax
	leave
*/