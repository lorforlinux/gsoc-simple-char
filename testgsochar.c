/**
 * @file   	testgsochar.c
 * @author 	Deepak Khatri
 * @date   	6 June 2020
 * @version 0.1
 * @brief   Warmp up task for GSoC2020.
 * @see 	https://github.com/lorforlinux/gsoc-simple-char
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// Commands
#define OPEN	'o'
#define CLOSE	'c'
#define READ	'r'
#define WRITE	'w'
#define EXIT	'e'
#define ENTER   '\0'

// Message buffer
#define BUFFER_SIZE 1024

// Device method declarations
void getInput();
void openDevice();
void readDevice();
void writeDevice();

int main(){
	getInput();
    return 0;
}

// Device method definitions
void openDevice(){
	open("/dev/gsochar", O_RDWR | O_APPEND);
	getInput();
}

void readDevice(){
	printf("\nData read from the device:\n");
	system("cat /dev/gsochar");
	getInput();
}

void writeDevice(){
	printf("\nEnter data you want to write to the device:\n");
	char buffer[BUFFER_SIZE];
	char data[BUFFER_SIZE];
	if (fgets(data, BUFFER_SIZE, stdin) != NULL){
		char * strippedData;
		if ((strippedData=strchr(data, '\n')) != NULL){
    		*strippedData = '\0';
		}
		char cmd[BUFFER_SIZE + 40]= {0x0};
		sprintf(cmd,"echo \"%s\" >> /dev/gsochar", data);
		system(cmd);
	}
	getInput();	
}

void getInput(){
	char inputBuffer[BUFFER_SIZE];
	printf("\nPlease enter a command (o,r,w,e): ");
	if (fgets(inputBuffer, BUFFER_SIZE, stdin) != NULL){
		if (inputBuffer[0] == OPEN){
			openDevice();
		}
		else if (inputBuffer[0] == READ){
			readDevice();
		}
		else if (inputBuffer[0] == WRITE){
			writeDevice();
		}
		else if (inputBuffer[0] == EXIT){
		}
		else{
			printf("You have given incorrect input");
			getInput();
		}
	}
}