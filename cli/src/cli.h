#ifndef CLI_H
#define CLI_H

typedef struct {
    char *inputModelFilename;
    char *outputModelFilename;
    char *inputTextFilename;
    int printModel;
    int generateText;
    int textLengthMin;
    int textLengthMax;
} CLIConfigurations;

#endif