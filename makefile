# COSC1254 Programming Using c++ 2016
# Assignment 1
# Name: Wolf Zimmermamnn
# Student ID: s3495671
# Course Code: COSC1254
# Program Code: BP094


all:
	g++ -g -std=c++14 -Wall -pedantic src/*.cpp src/*.h -o mazer



clean:
	rm -f *.o *.svg *.b *.bin *.g
