#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    if (argc == 1)
        return 0;

    char* number = argv[1];
	int output = 0;

    _asm {
        push eax // pointer
        push ebx
        push ecx // do not use this
        push edx

        xor eax, eax
        xor ebx, ebx
        mov eax, number
        dec eax

        cyckle:
            inc eax
            mov cl, byte ptr [eax]
            cmp cl, 0
            je done
            cmp cl, 48
            jl notNumber
            cmp cl, 57
            jg notNumber

            sub cl, 48 // '0' - 48 . . .
            mov ebx, output
            imul ebx, 10
            jo overFill
            movsx edx, cl
            add ebx, edx
            jo overFill
            mov output, ebx

            jmp cyckle
        
        overFill:
            mov output, -2
            jmp done

        notNumber:
            mov output, -1
            jmp done

        done:
            pop eax
            pop ebx
            pop ecx
            pop edx

    }

    if (output == -2) {
        cout << "Overflow detected\n";
    }
    else {
        cout << output;
    }
    return 0;
}


