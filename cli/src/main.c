#include "config.h"

#include "argumentParser.h"

#include "markov.h"
#include "parser.h"
#include "serializer.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    CLIConfigurations configurations;
    parseArguments(argc, argv, &configurations);

    return 0;
}