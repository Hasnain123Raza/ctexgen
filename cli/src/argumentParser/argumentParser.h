#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include "cli.h"

#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

void parseArguments(int argc, char *argv[], CLIConfigurations *configurations);

#endif