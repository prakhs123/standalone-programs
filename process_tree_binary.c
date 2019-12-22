//
//  File.c
//  process tree
//
//  Created by Prakhar Jain on 11/08/13.
//  Copyright (c) 2013 Prakhar Jain. All rights reserved.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

static pid_t fork_ok(void)
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "Fork failure in pid %d\n", (int)getpid());
        exit(1);
    }
    else {
        printf("%d %d\n", (int)getpid(), (int)getppid());
    }
    return pid;
}

static void tree_p(int level)
{
    if (level == 0)
        return;
    if (fork_ok() == 0 || fork_ok() == 0) {
        tree_p(level-1);
    }
    else {
        printf("I am %d, my parent is %d\n", (int)getpid(), (int)getppid());
        while (wait(0) > 0);
        printf("Exit %d\n", (int)getpid());
    }
}

int main(void)
{
    int depth, w;
    printf("Enter the number of levels in the binary process tree\n");
    scanf("%d", &depth);
    printf("Start %d\n", (int)getpid());
    fflush(0);
    tree_p(depth);
    scanf("%d", &w);
    return 0;
}