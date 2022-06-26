hmmf:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $32, %rsp
        movl    %edi, -20(%rbp)
        movl    $1, -4(%rbp)
                                ; 2) inside f function (when main initially calls it)
        cmpl    $1, -20(%rbp)
        jg      .L2
        movl    -4(%rbp), %eax
        jmp     .L3
.L2:
        movl    -20(%rbp), %eax
        subl    $1, %eax
        movl    %eax, %edi
        call    f
        imull   -20(%rbp), %eax
.L3:
        leave
        ret
.LC0:
        .string "f(5) = %d"
main:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
                                ; 1) before the call to f
        movl    $5, %edi
        call    f
        movl    %eax, -4(%rbp)
                                ; 3) after the call to f
        movl    -4(%rbp), %eax
        movl    %eax, %esi
        movl    $.LC0, %edi
        movl    $0, %eax
        call    printf
        movl    $0, %eax
        leave
        ret