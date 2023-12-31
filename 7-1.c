// 1. Design, Develop and Implement Tower of Hanoi problem with n disks using recursion
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod,char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Moved disk from rod %c to %c\n", from_rod, to_rod, aux_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int N = 3;

    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}