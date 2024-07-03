

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Token types
typedef enum {
    IDENTIFIER,
    NUMBER,
    RESERVED_WORD,
    SPECIAL_SYMBOL,
    COMMENT,
    ERROR
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char lexeme[100]; // Assuming lexemes have a maximum length of 100 characters
} Token;

// Function to check if a string is a reserved word
int isReservedWord(const char* word) {
    // Add more reserved words as needed
    const char* reservedWords[] = { "const", "var", "procedure", "call", "begin", "end", "if", "then", "else", "while", "do", "read", "write", "true", "false", "exit" };
    int numReservedWords = sizeof(reservedWords) / sizeof(reservedWords[0]);

    for (int i = 0; i < numReservedWords; i++) {
        if (strcmp(word, reservedWords[i]) == 0) {
            return 1; // True, it's a reserved word
        }
    }

    return 0; // False, it's not a reserved word
}

// Function to get the next token from the source code
Token getNextToken(FILE* file) {
    Token token;
    char c;

    // Skip white spaces and comments
    do {
        c = fgetc(file);

        // Check for comments
        if (c == '/') {
            char nextChar = fgetc(file);
            if (nextChar == '*') {
                // Skip comment until '*/'
                while ((c = fgetc(file)) != EOF) {
                    if (c == '*') {
                        char nextNextChar = fgetc(file);
                        if (nextNextChar == '/') {
                            break; // End of comment
                        }
                        ungetc(nextNextChar, file);
                    }
                }
            }
            else {
                ungetc(nextChar, file); // Not a comment, put the character back
                break;
            }
        }
    } while (isspace(c));

    // Check for identifiers or reserved words
    if (isalpha(c) || c == '_') {
        int i = 0;
        token.type = IDENTIFIER;
        token.lexeme[i++] = c;

        while ((c = fgetc(file)) != EOF && (isalnum(c) || c == '_')) {
            token.lexeme[i++] = c;
        }

        token.lexeme[i] = '\0';

        if (isReservedWord(token.lexeme)) {
            token.type = RESERVED_WORD;
        }

        ungetc(c, file); // Put the last character back
    }
    // Check for numbers
    else if (isdigit(c)) {
        int i = 0;
        token.type = NUMBER;
        token.lexeme[i++] = c;

        while ((c = fgetc(file)) != EOF && isdigit(c)) {
            token.lexeme[i++] = c;
        }

        token.lexeme[i] = '\0';
        ungetc(c, file); // Put the last character back
    }
    // Check for special symbols
    // Check for special symbols
    else {
        token.type = SPECIAL_SYMBOL;
        token.lexeme[0] = c;
        token.lexeme[1] = '\0';

        // Handle two-character special symbols
        if (c == ':' || c == '<' || c == '>') {
            char nextChar = fgetc(file);
            if ((c == ':' && nextChar == '=') || ((c == '<' || c == '>') && nextChar == '=')) {
                token.lexeme[1] = nextChar;
                token.lexeme[2] = '\0';
            }
            else {
                ungetc(nextChar, file); // Put the character back
            }
        }
    }


    return token;
}

int main() {
    FILE* sourceFile;
    if (fopen_s(&sourceFile, "test.pl", "r") != 0) {
        perror("Error opening source code file");
        return EXIT_FAILURE;
    }


    Token token;

    do {
        token = getNextToken(sourceFile);

        switch (token.type) {
        case IDENTIFIER:
            printf("Identifier: %s\n", token.lexeme);
            break;
        case NUMBER:
            printf("Number: %s\n", token.lexeme);
            break;
        case RESERVED_WORD:
            printf("Reserved Word: %s\n", token.lexeme);
            break;
        case SPECIAL_SYMBOL:
            printf("Special Symbol: %s\n", token.lexeme);
            break;
        case COMMENT:
            printf("Comment: %s\n", token.lexeme);
            break;
        case ERROR:
            printf("Error: %s\n", token.lexeme);
            break;
        default:
            printf("Unknown Token: %s\n", token.lexeme);
            break;
        }
    } while (token.type != EOF);


    fclose(sourceFile);

    return EXIT_SUCCESS;
} 
