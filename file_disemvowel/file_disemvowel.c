#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char ch) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
     if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
       ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
       return true;
    else
        return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */

    int counter; // count the number of non-vowels that were copied into out_buf
    int j = 0;
    for(int i = 0; i < num_chars; i++)
    {
        if(!is_vowel(in_buf[i]))
        {
            out_buf[j] = in_buf[i];
            j++;
            counter++;
        }
    }
    return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */

    // create input and output buffers
    char in_buf[BUF_SIZE];
    char out_buf[BUF_SIZE];
    int num_chars, chars_copied;
    FILE* input = fopen(inputFile, "r"); // only read, the input file.
    num_chars = fread(in_buf, sizeof(char), sizeof(in_buf), input);
    fclose(input);
    chars_copied = copy_non_vowels(num_chars, in_buf, out_buf);
    FILE* output = fopen(outputFile, "w"); // only write to the output file.
    fwrite(out_buf, sizeof(char), chars_copied, output);
    fclose(output);
}

// Assume that we only have at maximum, 2 command line arguments given,
// a input file and an output file, we can use an if statement to set the
// input and output files.
int main(int argc, char *argv[]) {
    
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    if(argc == 2)
    {
        FILE *inputFile = argv[1];
        FILE *outputFile = stdout;
    }
    else
    {
        FILE *inputFile = argv[1];
        FILE *outputFile = argv[2];
    }

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}