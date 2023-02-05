#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE_BUFFER 4096

bool is_six_digits(char *user_input, int *integer);

int main(int argc, char *argv[])
{
    int integer = 0;
    bool pass = true;

    do
    {
        printf("\nEnter a 6 digit number:\n");
        // Get user input with restriction of 4096
        char *user_input = malloc(INPUT_SIZE_BUFFER);

        fgets(user_input, INPUT_SIZE_BUFFER, stdin);

        pass = is_six_digits(user_input, &integer);

    } while (!pass);

    printf("Your number is: %d", integer);

    return 0;
}

/*
int isspace (int __c); printf("Number cannot include a space");
int ispunct (int __c); printf("Number cannot include special characters");
int isalpha(int __c); printf("number cannot include letters")
*/
bool is_six_digits(char *user_input, int *integer)
{
    int counter = 0;
    char *input_buffer = malloc(INPUT_SIZE_BUFFER);
    int length = strlen(user_input);

    while (counter < length - 1)
    {

        char test_character = *(user_input + counter);

        if (isspace(test_character))
        {
            printf("A space was found and your number cannot include any spaces");
            return false;
        }

        if (ispunct(test_character))
        {
            printf("'%c' is a special character and your number cannot include any special characters", test_character);
            return false;
        }

        if (isalpha(test_character))
        {
            printf("'%c' is a letter and your number cannot include letters", test_character);
            return false;
        }

        if (!isdigit(test_character))
        {
            printf("Your number can only include digits");
            return false;
        }

        if (counter > 5)
        {
            printf("Your number cannot be more than 6 digits");
            return false;
        }

        counter++;
    }

    if (counter < 6)
    {
        printf("Your number cannot be less than 6 digits");
        return false;
    }

    // printf("counter is %d", counter);
    *integer = atoi(user_input);
    return true;
}

// Write to File
// int data[] = {
//     1000000000,
//     1000000001};

// FILE *file;

// file = fopen("file.bin", "wb");

// Point p1 = {
//     .x = 13,
//     .y = -5};
// Point p2;

// FILE *in;
// FILE *out;

// fopen("point.bin", "wb");
// if (out == NULL)
// {
//     return 1;
// }

// size_t elements_written = fwrite(&p1, sizeof(Point), 1, out);
// fclose(out);
// if (elements_written == 0)
// {
//     return 2;
// }

// return 0;

/*opening file for reading
FILE *fp;
char str[61];


fp = fopen("file.txt", "r");

if (fp == NULL)
{
    perror("Error opening file");
    return (-1);
}

if (fgets(str, 60, fp) != NULL)
{
    //writing content to stdout
    printf("%s", str);
}

fclose(fp);
fp = NULL;
return (0);
*/

/*Reading string data from a file*/

/*Reading char data from a file
FILE *fp;
int c;

fp = fopen("file.txt", "r");

if (fp == NULL)
{
    perror("Error in opening file");
    return (-1);
}

// read a single char
while ((c = fgetc(fp)) != EOF)
{
    printf("%c", c);
}

fclose(fp);
fp = NULL;

return (0);
*/

// rewind() positions the file that is specified by the file pointer argument at
// the beginning

// getc() "may be implamented as a macro"

// rename(const char *oldname, const char *newname);
// fclose() accepts a file pointer as an argument
// returns EOF (int) if an error occurs

// remove("file_name.txt") will delete the file that has the name
// "file_name.txt" from the current directory !careful with this!