#!/bin/bash

NAME=citizen

/usr/bin/g++ -DEVAL -static -O2 -o $NAME grader.c $NAME.cpp
