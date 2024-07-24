#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "data.csv"

typedef struct Member
{
	char uid[20];		   // UID của RFID
	char roomNumber[10];   // Số Phòng
	char name[50];		   // Tên
	char licensePlate[20]; // Biển Số Xe
} Member;

void menu()
{
	printf("//---------MANAGEMENT INFOMATION RESIDENT APARTMENT-------------\\ \n");
	printf("//\t 1. Add Resident											\n");
	printf("//\t 2. Find Resident from UID/Licens plantes					\n");
	printf("//\t 3. Update Infomation Resident								\n");
	printf("//\t 4. Stop Program!											\n");
	printf("//\t 5. Test program!											\n");
	printf("//--------------------------------------------------------------\n");
}

void menu2()
{
	printf("//---------You want find with?-------------\\ \n");
	printf("//\t 1. Find Resident from UID \n");
	printf("//\t 2. Find Resident from Licens plantes \n");
	printf("//--------------------------------------------\n");
}

int getSizeDB()
{
	char c;
	int line = 1;
	FILE *file = fopen(FILENAME, "r");
	if (file == NULL)
		perror("Error open file");
	do
	{
		c = fgetc(file);
		if (c == '\n')
			line++;
	} while (c != EOF);
	fclose(file);
	return line;
}

void getData(Member data[])
{
	int i = 0;

	FILE *file = fopen(FILENAME, "r");
	if (file == NULL)
		perror("Error open file");

	while (fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", data[i].uid, data[i].roomNumber, data[i].name, data[i].licensePlate) != EOF)
	{
		printf("%s\t\t%s\t\t%s\t\t%s\n", data[i].uid, data[i].roomNumber, data[i].name, data[i].licensePlate);
		i++;
	}
	fclose(file);
}

void addMember(Member data[])
{
	char buffer[104];
	char uid[20]; // UID of RFID
	char roomNumber[10];
	char name[50];
	char licensePlate[20];

	int numOfResident = getSizeDB(); // because 1 line is title so num of resident = num of line - 1
	printf("NumofResident: %d \n", numOfResident - 1);
	printf("Enter UID: ");
	fflush(stdin);
	scanf("%s", uid);

	for (int i = 1; i < numOfResident; i++)
	{ // 0 is title so 1 is first uid
		if (strcmp(data[i].uid, uid) == 0)
		{
			printf("UID Already exist!!");
			exit(0);
		}
	}
	printf("Enter Room Number: ");	fflush(stdin);	gets(roomNumber);
	printf("Enter Name: ");	fflush(stdin);	gets(name);
	printf("Enter License Plate: ");	fflush(stdin);	gets(licensePlate);

	FILE *file = fopen(FILENAME, "a");
	if (file == NULL)
		perror("Error open file");
	sprintf(buffer, "\n%s,%s,%s,%s", uid, roomNumber, name, licensePlate);
	fputs(buffer, file);
	fclose(file);
}

int searchByLicensePlate(const Member data[], char* licensePlate){
	int numOfResident = getSizeDB(); // because 1 line is title so num of resident = num of line - 1

	for (int i = 1; i < numOfResident; i++)
	{
		if (strcmp(data[i].licensePlate, licensePlate) == 0)
			return i;
	}
	return -1;
}

int searchByUID(const Member data[], const char* uid)
{
	int numOfResident = getSizeDB(); // because 1 line is title so num of resident = num of line - 1

	for (int i = 1; i < numOfResident; i++)
	{
		if (strcmp(data[i].uid, uid) == 0)
			return i;
	}
	return -1;
}

Member searchMember(const Member data[], const char* searchValue, int (*SearchFunction) (const Member*, const char*)){
	int position;

	if ((position = SearchFunction(data, searchValue)) > 0){
		printf("Found Resident: \n");
		printf("%s\t\t%s\t\t%s\t\t%s\n", data[0].uid, data[0].roomNumber, data[0].name, data[0].licensePlate);
		printf("%s\t\t%s\t\t%s\t\t%s\n", data[position].uid, data[position].roomNumber, data[position].name, data[position].licensePlate);
		exit(0);
	}
	printf("Resident not found! \n");
}

void findInfomation(const Member data[])
{
	int pickOption2;
	char uidFind[20];
	char licensePlateFind[20];

continueFind:
	menu2();
	printf("Pick your option: ");
	scanf("%d", &pickOption2);
	switch (pickOption2)
	{
	case 1:
		printf("Enter UID want find: ");
		fflush(stdin);
		gets(uidFind);
		searchMember(data, uidFind, searchByUID);

	case 2:
		printf("Enter Licens Plantes want find: ");
		fflush(stdin);
		gets(licensePlateFind);
		searchMember(data, licensePlateFind, searchByLicensePlate);

	default:
		printf("Your option not vaild!!!");
		break;
	}
}

// void updateResident(Member data[], void (*methodFind)(Member, const char*)){

// }

int main()
{
	
	int pickOption;
	Member *data;
start:
	data = (Member *)malloc(getSizeDB() * sizeof(Member));
	getData(data);
	menu();
	printf("Your choice is: ");
	scanf("%d", &pickOption);
	switch (pickOption)
	{
	case 1:
		addMember(data);
		goto start;
	case 2:
		findInfomation(data);
		goto start;
	case 3:
		// updateResident(data, searchByUID);
		break;
	case 4:
		printf("Program Close!!! \n");
		break;
	case 5:
		getData(data);
		break;
	default:
		printf("Your option not vaild!!!");
		break;
	}
	// getch();
	return 0;
}