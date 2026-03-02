#include <stdio.h>
#include <openssl/sha.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
	#include <windows.h>
#endif

void str_puller();
void checker(char*);
void buffercleaner(void);
void clean(void);
void print_banner();
void hex_to_byte(char*, unsigned char*);

char string[256];
unsigned char hashofstring[32];

char input_hash[65];
unsigned char byte_hash[32];

FILE *readfile;

int main()
{	

	#ifdef _WIN32	
		SetConsoleOutput(CP_UTF8);
	#endif

    clean();

    while(1)
    {
        char filename[256];
        printf("\n[+] Enter the path of the dictionary : ");

        while((fgets(filename, 256, stdin)) == NULL)
        {
            clean();
            printf("\n[-] Please enter a valid path : ");
        }

        if(filename[strlen((filename)) - 1] != '\n')
            buffercleaner();

        filename[strcspn(filename, "\n")] = '\0';

        if(strcmp(filename, "exit") == 0)
        	exit(0);

        else if(strcmp(filename, "clear") == 0)
        	clean();

        else if(strcmp(filename, "help") == 0 || strcmp(filename, "-h") == 0 || strcmp(filename, "--help") == 0)
        	printf("\n\nclear : for clear the shell\nexit : for exit the program\nhelp : to show this help messege\n\n");

       readfile  = fopen(filename, "r");
       if(readfile)
           break;
    }

    while(1)
    {
        register int i = 0;
        printf("\n[+] Enter the hash value: ");

        while((fgets((char*)input_hash, 65, stdin)) == NULL)
        {
            clean();
            printf("[-] Enter a valid hash value : ");
        }

        if(input_hash[strlen(input_hash) - 1] != '\n')
            buffercleaner();

        for(i = 0 ; i < 64 ; i++)
        {
            if (!isxdigit(input_hash[i]))
                break;
        }

        if(i == 64)
            break;
    }

    input_hash[strcspn(input_hash, "\n")] = '\0';

    hex_to_byte(input_hash, byte_hash);

    str_puller();
    return 0;
}

void str_puller()
{   printf("\n\n");
    unsigned long counter = 0;
    while(fgets(string, 256, readfile))
    {
        string[strcspn(string, "\n")] = '\0';
        checker(string);

        counter++;
        if(counter % 10000 == 0)
        {
            printf("%lu possiblities checked \n", counter);
        }
    }
}

void checker(char *string)
{
    SHA256((unsigned char*)string, strlen(string), hashofstring);

    if((memcmp(hashofstring, byte_hash, 32)) == 0)
    {
        printf("[++++++] Password found : %s\n\n", string);
        fclose(readfile);
        exit(0);
    }
}

void hex_to_byte(char* input_hash, unsigned char* byte_hash)
{
    for(int i = 0 ; i < 32 ; i++)
    {
        unsigned char high = input_hash[i*2];
        unsigned char low = input_hash[i*2 + 1];

        high = (high <= '9') ? high - '0' : tolower(high) - 'a' + 10;
        low = (low <= '9') ? low - '0' : tolower(low) - 'a' + 10;

        byte_hash[i] = (high << 4) | low;
    }
}

void buffercleaner(void)
{
    int x;
    while((x = getchar()) != '\n' && x != EOF);
}

void clean(void)
{
    #ifdef _WIN32
        system("cls");

    #else
        system("clear");

    #endif

    print_banner();
}

void print_banner()
{
    printf("                    ███████╗██╗  ██╗ █████╗ ██████╗  \n");
    printf("                    ██╔════╝██║  ██║██╔══██╗██╔══██╗ \n");
    printf("                    ███████╗███████║███████║██████╔╝ \n");
    printf("                    ╚════██║██╔══██║██╔══██║██╔══██╗ \n");
    printf("                    ███████║██║  ██║██║  ██║██║  ██║ \n");
    printf("                    ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ \n");
    printf("\n");
    printf("   Very Simple, Efficient, CPU based SHA-256 Dictionary Cracker By Piyumila Perera\n");
    printf("   Educational Use Only\n");
    printf("   Version 1.0.0\n\n");
}