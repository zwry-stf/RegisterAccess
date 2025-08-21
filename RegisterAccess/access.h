#pragma once
typedef void* (__fastcall* FnGetRegister)   ();
typedef void  (__fastcall* FnPutRegister)   (void*);
typedef float (__fastcall* FnGetXMMRegister)();
typedef void  (__fastcall* FnPutXMMRegister)(float);

#define register_access_begin namespace register_access {
#define register_access_end }

#define import_read(f)      extern FnGetRegister read_##f;
#define import_write(f)     extern FnPutRegister write_##f;
#define __import(f)         import_read(f); import_write(f)
#define import_read_xmm(f)  extern FnGetXMMRegister read_##f;
#define import_write_xmm(f) extern FnPutXMMRegister write_##f;
#define __import_xmm(f)     import_read_xmm(f); import_write_xmm(f)

register_access_begin

__import(rax);
__import(rcx);
__import(rdx);
__import(rbx);
__import(rsp);
__import(rbp);
__import(rsi);

__import(r8);
__import(r9);
__import(r10);
__import(r11);
__import(r12);
__import(r13);
__import(r14);
__import(r15);

__import_xmm(xmm0);
__import_xmm(xmm1);
__import_xmm(xmm2);
__import_xmm(xmm3);
__import_xmm(xmm4);
__import_xmm(xmm5);
__import_xmm(xmm6);
__import_xmm(xmm7);

__import_xmm(xmm8);
__import_xmm(xmm9);
__import_xmm(xmm10);
__import_xmm(xmm11);
__import_xmm(xmm12);
__import_xmm(xmm13);
__import_xmm(xmm14);
__import_xmm(xmm15);

register_access_end

#undef import_read
#undef import_write
#undef __import
#undef import_read_xmm
#undef import_write_xmm
#undef __import_xmm