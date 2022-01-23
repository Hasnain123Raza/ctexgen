#include "config.h"

#include "markov.h"
#include "parser.h"
#include "serializer.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello, world from %s!\n", PACKAGE_NAME);

    markovGreet();
    parserGreet();
    serializerGreet();

    return 0;
}