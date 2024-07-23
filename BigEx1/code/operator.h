#ifndef __OPRTATOR_H
#define __OPRTATOR_H

void menu();
void menu2();
int getSizeDB();
void getData(Member data[]);
void addMember(Member data[]);
int searchByUID(Member data[], const char *uid);
void findInfomation(Member data[]);

#endif