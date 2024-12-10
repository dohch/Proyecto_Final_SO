;Definimos variables globales
global startB, kernelB
extern kernelMain, startConstructor, endConstructor, startDestructor, endDestructor

%define MAGIC_NUMBER 0
%define NUMBER_FLAGS 0
%define CHECK  -(MAGIC_NUMBER+NUMBER_FLAGS) 

startB:
        jmp start
align 8
        multiboot_header:
                dd MAGIC_NUMBER
                dd NUMBER_FLAGS
                dd CHECK
start:
        push rbx

stacticContructorLoop:
        mov rbx, startConstructor
        jmp .test
.body:
        call [rbx]
        add rbx, 8
.test:
        cmp rbx, endConstructor
        jb .body
        call KernelMain

staticDestructorLoop:
        mov rbx, startDestructor
        jmp .test
.body:
        call[rbx]
        add rbx, 8
.test:
        cmp rbx, endDestructor
        jb .body
        cli
        hlt
                
