  1         extern  printf          ; the C function, to be called
  2
  3                 section .data           ; Data section, initialized variables
  4 msg:            db "Hello, Holberton", 0 ; C string needs 0
  5 fmt:            db "%s", 10, 0          ; The printf format, "\n", '0'
  6
  7                 section .text           ; Code section.
  8
  9                 global main             ; the standard gcc entry point
 10 main:                                   ; the program label for the entry point
 11                 push    rbp             ; set up stack frame, must be alligned
 12
 13                 mov     rdi,fmt
 14                 mov     rsi,msg
 15                 mov     rax,0           ; or can be     xor     rax,rax
 16                 call    printf          ; Call C function
 17
 18                 pop     rbp             ; restore stack
 19
 20                 mov     rax,0           ; normal, no error, return value
 21                 ret                     ; return
