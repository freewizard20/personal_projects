# 2017 Operating Systems class

private school project repository removed. commit logs and woking code lost as of May 2018 :/ :cry::cry:

we did four projects with TIZEN artik 10, Linux 3.14 kernel here

1. gathering process informations using task_struct, and making a new system call for printing them
2. making a reader/writer lock based on device azimuth
3. developing a new run queue with weighted round robin algorithm
4. modifing the ext4 filesystem to accept modifications on specific geolocations

> *Credits to teammates Ben Horner and Sesang Jo of 2017 OS team 27, Seoul National University*

working video for proj 1 and 2

[project 1 video](https://youtu.be/QQ0pysqq_i4)
[project 2 video](https://youtu.be/rzx5NA-_A0Q)

# Adding a system call

## modifying existing files

arch/arm/kernel/calls.S
arch/arm/include/asm/unistd.h
arch/arm/include/uapi/asm/unistd.h
include/linux/syscalls.h
change Makefile of corresponding directory

add syscall

#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/sched.h>

asmlinkage int fwcall(int fw)


test file

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#define __NR_secmysys 380


int main(){


printf("hello from p2test\n");

int a;
int b;
int c;
int d;
int e;

a = syscall(380, 50);
printf("a");
b = syscall(381, 140, 30);
printf("b");
c = syscall(382, 190, 20);
printf("c");
d = syscall(383, 210, 40);
printf("d");
e = syscall(385, 312, 50);

printf("end");


}
```

direct_set_debug.sh --sdb-set

arm-linux-gnueabi-gcc -I<your kernel path>/include test.c -o test

# Using the Terminal


# Using Vim

## copy paste to Vim
### from browser(www) to vim
use `ctrl + C` from browser
use `Shift + Insert` to vim
or `i` then `Ctrl + Shift + v` to vim

### from vim to vim
use `v` to select
use 'y' to copy
use 'p' to paste

