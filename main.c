#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_FILENAME "index.html"
#define TEMPLATE_FILENAME "template_main.html"
#define TETRIS_PARTIAL_FILENAME "tetris_partial.html"

#define TETRIS_GAME_PH "<!-- TETRIS_GAME_PLACEHOLDER -->"
#define TETRIS_NAV_LINK_PH "<!-- TETRIS_NAV_LINK_PLACEHOLDER -->"
#define TETRIS_SCRIPT_PH "<!-- TETRIS_SCRIPT_PLACEHOLDER -->"

#define TETRIS_NAV_LINK_HTML "<li><a class=\"nav-link\" href=\"#Game_tetris\">Game tetris</a></li>"
#define TETRIS_SCRIPT_HTML "<script src=\"tetris.js\"></script>"

// Function to read a whole file into a string
char* read_file_to_string(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("fseek to SEEK_END failed");
        fclose(file);
        return NULL;
    }

    long length = ftell(file);
    if (length == -1L) {
        perror("ftell failed");
        fclose(file);
        return NULL;
    }   

    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("fseek to SEEK_SET failed");
        fclose(file);
        return NULL;
    }

    char* buffer = malloc(length + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);
    return buffer;
}

// Function to replace a substring
char* str_replace(char* orig, const char* rep, const char* with) {
    
    char* result;
    char* ins;
    char* tmp;
    long len_rep;
    long len_with;
    long len_front;
    int count;

    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL;
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; (tmp = strstr(ins, rep)); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep;
    }
    strcpy(tmp, orig);
    return result;
}

void generateHTML() {
    // Read the main template
    char* template_content = read_file_to_string(TEMPLATE_FILENAME);
    if (!template_content) {
        return;
    }

    // Read the partial
    char* tetris_partial = read_file_to_string(TETRIS_PARTIAL_FILENAME);

    if (!tetris_partial) tetris_partial = strdup("");

    // Replace placeholders
    char* result1 = str_replace(template_content, TETRIS_GAME_PH, tetris_partial);
    char* result2 = str_replace(result1, TETRIS_NAV_LINK_PH, TETRIS_NAV_LINK_HTML);
    char* final_result = str_replace(result2, TETRIS_SCRIPT_PH, TETRIS_SCRIPT_HTML);

    // Write the final result to the output file
    FILE* outputFile = fopen(OUTPUT_FILENAME, "w");
    if (outputFile == NULL) {
        perror("Failed to create index.html");
    } else {
        fputs(final_result, outputFile);
        fclose(outputFile);
        printf("Successfully generated %s with Tetris!\n", OUTPUT_FILENAME);
    }

    // Free all allocated memory
    free(template_content);
    free(tetris_partial);
    free(result1);
    free(result2);
    free(final_result);
}

int main() {
    generateHTML();
    return 0;
}