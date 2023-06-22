#include <linux/kvm.h>
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    printf("%d", (int)sizeof(struct kvm_xsave));
    return 0;
}
    