#!/bin/bash
DIR_APP = "../list" 
gcc "$DIR_APP"/test.c "$DIR_APP"/src/table.c  "$DIR_APP"/src/utils.c -I"$DIR_APP"/include -o "$DIR_APP"/build/test
