#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char* argv[])
{
  int *ip = malloc(10 * sizeof *ip);
  if(!ip){ 
    //error handler
  }
  int *new_ip = realloc(ip, 100 * sizeof *new_ip);
  if(!new_ip){
    //handle errors
  }
  ip = new_ip; //(this grew our original to 100 elements)
  
  //we cannot do this because we would no longer have a reference to the mem.
  //being pointed at which would cause a memory leak 
}
