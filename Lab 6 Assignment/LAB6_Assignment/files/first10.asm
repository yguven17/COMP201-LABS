first10():
        pushq   %rbp
        movq    %rsp, %rbp
        movl    $0, -4(%rbp)
        movl    $0, -8(%rbp)
.L3:
        cmpl    $9, -8(%rbp)
        jg      .L2
        movl    -8(%rbp), %eax
        addl    %eax, -4(%rbp)
        addl    $2, -8(%rbp)
        jmp     .L3
.L2:
        movl    -4(%rbp), %eax
        popq    %rbp
        ret