;Variables globales
;_start : ...completar
;_kmain : ...completar
global _start, _kmain
;Funciones externas
;kmain : 
;start_ctors : 
;end_ctors : 
;start_dtors :
;end_stors : 
extern kmain, start_ctors, end_ctors, start_dctors, end_dctors 
;Macros de valores
;Multiboot: Number for computer to know BOOT-MULTIBOOT
;Flags : Flags number - i don't know
;Checksum : To know the data integrity == 0
%define MULTIBOOT_HEADER_MAGIC 0x1BADB002
%define MULTIBOOT_HEADER_FLAGS 0x00000003
%define CHECKSUM - (MULTIBOOT_HEADER_MAGIC+MULTIBOOT_HEADER_FLAGS)

;Start changer the system
_start:
	jmp start
;Define 4 bytes length
align 4

	multiboot_header:
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd CHECKSUM

start:
	push ebx

static_ctor_loop:
	mov ebx, start_ctors
	jmp .test
.body:
	call [ebx]
	add ebx, 4
.test:
	cmp ebx, end_ctors
	jb .body

	call kmain

static_dtors_loop:
	mov ebx, start_dtors
	jmp .test
.body:
	call [ebx]
	add ebx,4
.test:
	cmp ebx, end_dtors
	jb .body

		cli
		hlt
