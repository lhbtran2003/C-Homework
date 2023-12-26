#include<stdio.h>
typedef struct struct_old_name{
    char *name;
    char *gender;
    int age
}struct_new_name;
int main(){
    struct_new_name bakien = {"bakien", "nam", 45};

    printf("%s , %s, %d", bakien.name, bakien.gender, bakien.age);
}