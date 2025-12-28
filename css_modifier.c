#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "css_modifier.h"

#define CSS_FILENAME "styles.css"
#define BG_COLOR_VAR "--bg" // CSS variable for background color
#define DECLARATION_SIZE 100 // Static size for declaration line symbol count "e.g. --bg: red;"

// Function to read a whole file into a string
char* read_file_to_string(const char* filename) {
    FILE* file = fopen(filename, "rb");
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
char* str_replace(const char* orig, const char* rep, const char* with) {
    char* result;
    const char* ins;
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

    if (with == NULL)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; (tmp = strstr(ins, rep)); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    const char* p = orig;
    while (count--) {
        ins = strstr(p, rep);
        len_front = ins - p;
        tmp = strncpy(tmp, p, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        p += len_front + len_rep;
    }
    strcpy(tmp, p);
    return result;
}


void modify_css_background(const char* new_color) {
    char* css_content = read_file_to_string(CSS_FILENAME);
    if (!css_content) {
        return;
    }

    char old_line[DECLARATION_SIZE];
    char new_line[DECLARATION_SIZE];

    char* line_start = strstr(css_content, BG_COLOR_VAR);

    if (line_start) {
        // Find the end of the line
        char* line_end = strchr(line_start, ';');
        if (line_end) {
            // Extract the full original line
            long line_length = line_end - line_start + 1;
            strncpy(old_line, line_start, line_length);
            old_line[line_length] = '\0';

            // Create the new line
            sprintf(new_line, "%s: %s;", BG_COLOR_VAR, new_color);

            // Replace the line
            char* final_css = str_replace(css_content, old_line, new_line);

            FILE* cssFile = fopen(CSS_FILENAME, "wb");
            if (cssFile == NULL) {
                perror("Failed to open styles.css for writing");
            } else {
                fputs(final_css, cssFile);
                fclose(cssFile);
                printf("Successfully modified background color in %s\n", CSS_FILENAME);
            }
            free(final_css);
        }
    } else {
        printf("Could not find the '%s' variable in %s\n", BG_COLOR_VAR, CSS_FILENAME);
    }

    free(css_content);
}

void modify_css_text_color(const char* new_color) {
    char* css_content = read_file_to_string(CSS_FILENAME);
    if (!css_content) {
        return;
    }

    char old_line[DECLARATION_SIZE];
    char new_line[DECLARATION_SIZE];

    char* line_start = strstr(css_content, "--text"); // Target --text variable

    if (line_start) {
        // Find the end of the line
        char* line_end = strchr(line_start, ';');
        if (line_end) {
            // Extract the full original line
            long line_length = line_end - line_start + 1;
            strncpy(old_line, line_start, line_length);
            old_line[line_length] = '\0';

            // Create the new line
            sprintf(new_line, "--text: %s;", new_color); // Use --text as the variable

            // Replace the line
            char* final_css = str_replace(css_content, old_line, new_line);

            FILE* cssFile = fopen(CSS_FILENAME, "wb");
            if (cssFile == NULL) {
                perror("Failed to open styles.css for writing");
            } else {
                fputs(final_css, cssFile);
                fclose(cssFile);
                printf("Successfully modified text color in %s\n", CSS_FILENAME);
            }
            free(final_css);
        }
    } else {
        printf("Could not find the '--text' variable in %s\n", CSS_FILENAME);
    }
    free(css_content);
}

void modify_css_card_color(const char* new_color) {
    char* css_content = read_file_to_string(CSS_FILENAME);
    if (!css_content) {
        return;
    }

    char old_line[DECLARATION_SIZE];
    char new_line[DECLARATION_SIZE];

    char* line_start = strstr(css_content, "--card");

    if (line_start) {
        char* line_end = strchr(line_start, ';');
        if (line_end) {
            long line_length = line_end - line_start + 1;
            strncpy(old_line, line_start, line_length);
            old_line[line_length] = '\0';
            sprintf(new_line, "--card: %s;", new_color);
            char* final_css = str_replace(css_content, old_line, new_line);
            FILE* cssFile = fopen(CSS_FILENAME, "wb");
            if (cssFile == NULL) {
                perror("Failed to open styles.css for writing");
            } else {
                fputs(final_css, cssFile);
                fclose(cssFile);
                printf("Successfully modified card color in %s\n", CSS_FILENAME);
            }
            free(final_css);
        }
    } else {
        printf("Could not find the '--card' variable in %s\n", CSS_FILENAME);
    }
    free(css_content);
}

void modify_css_muted_color(const char* new_color) {
    char* css_content = read_file_to_string(CSS_FILENAME);
    if (!css_content) {
        return;
    }

    char old_line[DECLARATION_SIZE];
    char new_line[DECLARATION_SIZE];

    char* line_start = strstr(css_content, "--muted");

    if (line_start) {
        char* line_end = strchr(line_start, ';');
        if (line_end) {
            long line_length = line_end - line_start + 1;
            strncpy(old_line, line_start, line_length);
            old_line[line_length] = '\0';
            sprintf(new_line, "--muted: %s;", new_color);
            char* final_css = str_replace(css_content, old_line, new_line);
            FILE* cssFile = fopen(CSS_FILENAME, "wb");
            if (cssFile == NULL) {
                perror("Failed to open styles.css for writing");
            } else {
                fputs(final_css, cssFile);
                fclose(cssFile);
                printf("Successfully modified muted color in %s\n", CSS_FILENAME);
            }
            free(final_css);
        }
    } else {
        printf("Could not find the '--muted' variable in %s\n", CSS_FILENAME);
    }
    free(css_content);
}

void modify_css_code_bg_color(const char* new_color) {
    char* css_content = read_file_to_string(CSS_FILENAME);
    if (!css_content) {
        return;
    }

    char old_line[DECLARATION_SIZE];
    char new_line[DECLARATION_SIZE];

    char* line_start = strstr(css_content, "--code-bg");

    if (line_start) {
        char* line_end = strchr(line_start, ';');
        if (line_end) {
            long line_length = line_end - line_start + 1;
            strncpy(old_line, line_start, line_length);
            old_line[line_length] = '\0';
            sprintf(new_line, "--code-bg: %s;", new_color);
            char* final_css = str_replace(css_content, old_line, new_line);
            FILE* cssFile = fopen(CSS_FILENAME, "wb");
            if (cssFile == NULL) {
                perror("Failed to open styles.css for writing");
            } else {
                fputs(final_css, cssFile);
                fclose(cssFile);
                printf("Successfully modified code background color in %s\n", CSS_FILENAME);
            }
            free(final_css);
        }
    } else {
        printf("Could not find the '--code-bg' variable in %s\n", CSS_FILENAME);
    }
    free(css_content);
}

void modify_css_code_text_color(const char* new_color) {
    char* css_content = read_file_to_string(CSS_FILENAME);
    if (!css_content) {
        return;
    }

    char old_line[DECLARATION_SIZE];
    char new_line[DECLARATION_SIZE];

    char* line_start = strstr(css_content, "--code-text");

    if (line_start) {
        char* line_end = strchr(line_start, ';');
        if (line_end) {
            long line_length = line_end - line_start + 1;
            strncpy(old_line, line_start, line_length);
            old_line[line_length] = '\0';
            sprintf(new_line, "--code-text: %s;", new_color);
            char* final_css = str_replace(css_content, old_line, new_line);
            FILE* cssFile = fopen(CSS_FILENAME, "wb");
            if (cssFile == NULL) {
                perror("Failed to open styles.css for writing");
            } else {
                fputs(final_css, cssFile);
                fclose(cssFile);
                printf("Successfully modified code text color in %s\n", CSS_FILENAME);
            }
            free(final_css);
        }
    } else {
        printf("Could not find the '--code-text' variable in %s\n", CSS_FILENAME);
    }
    free(css_content);
}