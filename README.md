# MemoryReorderInCPP

Consider the simple program that programmer would like to assign to variable a and then b.  
The compiler GCC will change memory order to assign variable b before a.
This happens when gcc optimization -O3 enabled.
    
    int a, b;
    int main(void) {
    a = b + 1;
    b = 0;
    }
