#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void user_access_rights(mode_t buf);
void right_access_modif();
int convert_bits(char *access_rights);
void print_binary(int num);

#endif