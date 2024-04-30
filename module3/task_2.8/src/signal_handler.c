#include "main.h"

void signal_handler(int signal) {
  switch (signal) {
    case SIGUSR1:
      printf("Process %d: SIGUSR1 signal received for blocking\n", getpid());
      file_locked = 1;
      break;
    case SIGUSR2:
      printf("Process %d: SIGUSR2 unlock signal received\n", getpid());
      file_locked = 0;
      break;
  }
}