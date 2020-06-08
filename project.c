#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1000

int ch;
char fn[64],e,c,name[20];
FILE *fp1,*fp2,*fp;

void Modify();
void NewFile();
void Copy();
void Delete();
void View();
void comparison();

int main()
{
	do {
		printf("\n-------------------------------------------------------------- CP Assign.-----------------------------------------------");
		printf("\n\n\tMENU:\n\t\n");
		printf("\n\t1.NEWFILE\t2.VIEW\t3.COPY\t\t4.DELETE\t5.COMPARISON\t6.EXIT\n");
		printf("\n\tEnter your choice: ");
		scanf("%d",&ch);
	switch(ch)
			{
			case 1:
			NewFile();
			break;
			case 2:
			View();
			break;
			case 3:
			Copy();
			break;
			case 4:
			Delete();
			break;
			case 5:
			comparison();
			break;
			case 6:
			exit(0);
			}
			}while(1);

return 0;
}

void NewFile()
{
	printf("\n\tEnter the name of the file to be created: ");
	scanf("%s", name);
	fp1=fopen(name,"w");
	printf("\n\tEnter the text and press '.' to save\n\n\t");

	while(1)
		{
			c=getchar();
			fputc(c,fp1);

		if(c == '.')
			{
				fclose(fp1);
				break;
			}

		}
}

void comparison()
{
	int line = 1, col = 0;
	  

	printf("\n\tEnter the first file: ");
		scanf("%s", name);
		fp1 = fopen(name,"r");
	printf("\n\tEnter the second file: ");
		scanf("%s", name);
		fp2 = fopen(fn,"r");

	

    if (fp1 == NULL || fp2 == NULL) 
    { 
       printf("\tError : Files not open\n"); 
       exit(0); 
    } 
	char ch1 = getc(fp1); 
    char ch2 = getc(fp2);

	while (ch1 != EOF && ch2 != EOF) 
    { 
        col++; 
  
        if (ch1 == '\n' && ch2 == '\n') 
        { 
            line++; 
            col = 0; 
        } 
  

        if (ch1 != ch2) 
        { 
            printf("Files not equal\n"); 
            printf("Line Number : %d \t""Position : %d \n", line, col); 
        } 
  
        ch1 = getc(fp1); 
        ch2 = getc(fp2); 
    } 
fclose(fp1); 
    fclose(fp2); 
}

void View()
{
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");

	if(fp1==NULL)
	{
		printf("\n\tFile not found!");
		fclose(fp1);
		printf("\n\n\tPress any key to continue\n");
	}
	while(!feof(fp1))
	{
		c=getc(fp1);
		printf("%c",c);
	}

}

void Copy()
{
	printf("\n\tEnter the new filename to copy:  ");
	scanf("%s",fn);
	printf("\n\tEnter the filename from which to copy: ");
	scanf("%s", name);
	fp1=fopen(name,"r");
	fp2=fopen(fn,"w");

	while(!feof(fp1))
	{
		c=getc(fp1);
		putc(c,fp2);
	}

printf("\n\tFile has been copied successfully");
fclose(fp2);
}

void Delete()
{
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");

	if(fp1==NULL)
	{
		printf("\n\tFile not found!");
		printf("\n\n\tPress any key to continue\n");
	}
	fclose(fp1);

	if(remove(fn)==0)
	{
		printf("\n\n\tFile has been deleted successfully!");
		printf("\n\n\tPress any key to continue\n");
	}
	else
		printf("\n\tError!\n"); 
}






