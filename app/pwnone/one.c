
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void setup() {
  setvbuf(stdin, NULL, _IONBF, NULL);
  setvbuf(stdout, NULL, _IONBF, NULL);
}

void win() {
  FILE *f = fopen("flag.txt", "r");
  char flag[50];
  
  if(f == NULL) {
    puts("Make sure there is a flag.txt file in this local directory or if you are running remotely then contact an admin!");
    exit(1);
  }

  fgets(flag, 50, f);
  printf("Well Played: %s\n", flag);
  exit(42);
}

void vuln() {
  char overflow[16];
  printf("I really want to win! Can you help me by calling this function: %p\n", win);
  printf("How many characters can you input?\n");
  gets(overflow);
}

int main() {
  setup(); 
  vuln();
  printf("FUN!");
  return 0;
}
