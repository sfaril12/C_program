#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_FILES 10
#define NAME_LENGTH 10

typedef struct {
    char dname[NAME_LENGTH];
    char fname[MAX_FILES][NAME_LENGTH];
    int fcnt;
} Directory;

int main() {
    int i, choice;
    char filename[NAME_LENGTH];
    Directory dir;

    dir.fcnt = 0;

    printf("\nEnter name of directory -- ");
    scanf("%9s", dir.dname);

    while(1) {
        printf("\n\n1. Create File\t2. Delete File\t3. Search File");
        printf("\n4. Display Files\t5. Exit\nEnter your choice -- ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nMasukkan nama file -- ");
                scanf("%9s", dir.fname[dir.fcnt]);
                dir.fcnt++;
                break;

            case 2:
                printf("\nMasukkan nama file-- ");
                scanf("%9s", filename);
                for(i = 0; i < dir.fcnt; i++) {
                    if(strcmp(filename, dir.fname[i]) == 0) {
                        printf("File %s terhapus", filename);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt-1]);
                        break;
                    }
                }
                if(i == dir.fcnt)
                    printf("File %s tidak ditemukan", filename);
                else
                    dir.fcnt--;
                break;

            case 3:
                printf("\nMasukkan nama file-- ");
                scanf("%9s", filename);
                for(i = 0; i < dir.fcnt; i++) {
                    if(strcmp(filename, dir.fname[i]) == 0) {
                        printf("File %s ditemukan ", filename);
                        break;
                    }
                }
                if(i == dir.fcnt)
                    printf("File %s tidak ditemukan", filename);
                break;

            case 4:
                if(dir.fcnt == 0)
                    printf("\nDirektori kosong");
                else {
                    printf("\nThe Files are -- ");
                    for(i = 0; i < dir.fcnt; i++)
                        printf("\t%s", dir.fname[i]);
                }
                break;

            default:
                exit(0);
        }
    }

    getch();
    return 0;
}
