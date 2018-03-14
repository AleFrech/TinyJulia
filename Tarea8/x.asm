extern printf
global main
section .data
         format: db "%d" , 10, 0

section .text
main:
         push ebp
         mov ebp,esp

         sub esp,4
         mov DWORD [ebp-4], 10
         sub esp,4
         mov DWORD [ebp-8], 20

         push DWORD [ebp-4]
         push format
         call printf
         add esp, 8
         
         push DWORD [ebp-8]
         push format
         call printf

         add esp, 8
         leave
         ret
