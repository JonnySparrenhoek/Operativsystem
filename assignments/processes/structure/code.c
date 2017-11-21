#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//const int read_only = 123456;

//char global[] = "this is a global string";
void foo();

int main() {

  int pid = getpid();
  /*foo:
    printf("process id: %d\n", pid);
    printf("global string: %p\n", &global);
    printf("the code: %p\n", &&foo);

    printf("read only: %p\n", &read_only);

    printf("\n\n /proc/%d/maps \n\n", pid);
    char command[50];
    sprintf(command, "cat /proc/%d/maps", pid);

    system(command);

    return 0;*/
    unsigned long p = 0x1;
    foo(&p);

    back:
      printf(" p: %p \n", &p);
      printf(" back: %p \n", &&back);
      printf("\n\n /proc/%d/maps \n\n", pid);
      char command[50];
      sprintf(command, "cat /proc/%d/maps", pid);
      system(command);

    /*printf(" p(0x%lx): %p \n",p,&p);

    printf("\n\n /proc/%d/maps \n\n", pid);
    char command[50];
    sprintf(command, "cat /proc/%d/maps", pid);
    system(command);*/

    return 0;
}

void zot(unsigned long *stop){
  unsigned long r = 0x3;

  unsigned long *i;
  for(i = &r; i <= stop; i++){
    printf(" %p 0x%lx\n", i, *i);
  }
}

void foo(unsigned long *stop){
  unsigned long q = 0x2;
  zot(stop);
}
