#ifndef __RESIDENT_H
#define __RESIDENT_H

typedef struct Member
{
	char uid[20];		   // UID của RFID
	char roomNumber[10];   // Số Phòng
	char name[50];		   // Tên
	char licensePlate[20]; // Biển Số Xe
} Member;

#endif __RESIDENT_H