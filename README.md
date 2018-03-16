# Memory Reorder In CPP

Consider the simple program that programmer would like to assign to variable a and then b.  
The compiler GCC will change memory order to assign variable b before a.  
This happens when gcc optimization -O3 enabled.
    
cpp code
    
    int a, b;
    int main(void) {
    a = b + 1;
    b = 0;
    }

Optimization Disabled: gcc -S -masm=intel gcc-instruction-reorder.cpp

    call	___main
    mov	eax, DWORD PTR _b
    add	eax, 1
    mov	DWORD PTR _a, eax
    mov	DWORD PTR _b, 0 // b after a
    mov	eax, 0
    leave

Optimization Enabled: gcc -S -masm=intel gcc-instruction-reorder.cpp **-O3**

    call	___main
    mov	eax, DWORD PTR _b
    mov	DWORD PTR _b, 0 b before a
    add	eax, 1
    mov	DWORD PTR _a, eax
    xor	eax, eax
    leave
