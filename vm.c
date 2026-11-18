#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum Opcode {
    OP_CONSTANT = 1,
    OP_ADD,
    OP_PRINT,
    OP_HALT,
};

typedef struct {
    uint8_t *program;
    size_t program_size;
    size_t ip;
    int stack[256];
    size_t stack_size;
} VM;

int main(void) {
    uint8_t program[] = {
        OP_CONSTANT, 2,
        OP_CONSTANT, 3,
        OP_ADD,
        OP_PRINT,
        OP_HALT
    };

    VM vm = {0};
    vm.program = program;
    vm.program_size = sizeof(program);

    while (vm.ip < vm.program_size){
        uint8_t opcode = vm.program[vm.ip++];

        switch (opcode){
            case OP_HALT: {
                return 0;
            }
            case OP_CONSTANT: {
                int value = vm.program[vm.ip++];
                vm.stack[vm.stack_size++] = value;
                break;
            }
            case OP_ADD: {
                int left = vm.stack[--vm.stack_size];
                int right = vm.stack[--vm.stack_size];
                int sum = right + left;
                vm.stack[vm.stack_size++] = sum;
                break;
            }
            case OP_PRINT: {
                int result = vm.stack[--vm.stack_size];
                printf("%d\n", result);
                break;
            }
        }
    }

    return 0;
}