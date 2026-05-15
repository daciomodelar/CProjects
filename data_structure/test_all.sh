#!/bin/bash

gcc list/test.c list/src/list.c list/src/l_utils.c -Ilist/include -o list/build/test &&

gcc queue/test.c queue/src/queue.c queue/src/q_utils.c -Iqueue/include -o queue/build/test && 

gcc stack/test.c stack/src/stack.c stack/src/s_utils.c -Istack/include -o stack/build/test &&

list/build/test
queue/build/test
stack/build/test

