#include "config.h"
#include "argumentParser.h"

const char *argp_program_bug_address = PACKAGE_BUGREPORT;
const char *argp_program_version = PACKAGE_VERSION;

static int parse_opt(int key, char *arg, struct argp_state *state);

void parseArguments(int argc, char *argv[], CLIConfigurations *configurations)
{
    struct argp_option options[] = {
        { "input", 'i', "FILENAME", 0, "Filename of input model. Defaults to " DEFAULT_INPUT_MODEL_NAME },
        { "output", 'o', "FILENAME", 0, "Filename of output model. Defaults to " DEFAULT_OUTPUT_MODEL_NAME },
        { "text", 't', "FILENAME", 0, "Filename of input text. Defaults to " DEFAULT_INPUT_TEXT_FILE },
        { "print", 'p', 0, OPTION_ARG_OPTIONAL, "Prints the input model." },
        { "generate", 'g', 0, OPTION_ARG_OPTIONAL, "Generates text using input model." },
        { "upper", 'u', "NUMBER", 0, "Upper limit of generated text's length. Defaults to " DEFAULT_TEXT_LENGTH_MAX },
        { "lower", 'l', "NUMBER", 0, "Lower limit of generated text's length. Defaults to " DEFAULT_TEXT_LENGTH_MIN },
        { 0 }
    };

    struct argp argp = { options, parse_opt, 0, 0 };

    configurations->inputModelFilename = DEFAULT_INPUT_MODEL_NAME;
    configurations->outputModelFilename = DEFAULT_OUTPUT_MODEL_NAME;
    configurations->inputTextFilename = DEFAULT_INPUT_TEXT_FILE;
    configurations->printModel = 0;
    configurations->generateText = 0;
    configurations->textLengthMax = atoi(DEFAULT_TEXT_LENGTH_MAX);
    configurations->textLengthMin = atoi(DEFAULT_TEXT_LENGTH_MIN);

    if (argp_parse(&argp, argc, argv, 0, 0, configurations) == -1)
        exit(EXIT_FAILURE);
}

static int parse_opt(int key, char *arg, struct argp_state *state)
{
    CLIConfigurations *configurations = state->input;

    switch (key)
    {
        case 'i':
            configurations->inputModelFilename = arg;
            break;
        case 'o':
            configurations->outputModelFilename = arg;
            break;
        case 't':
            configurations->inputTextFilename = arg;
            break;
        case 'p':
            configurations->printModel = 1;
            break;
        case 'g':
            configurations->generateText = 1;
            break;
        case 'u':
            configurations->textLengthMax = atoi(arg);
            if (configurations->textLengthMax <= 0)
                argp_error(state, "Upper limit of generated text's length must be greater than zero.");
            if (configurations->textLengthMax < configurations->textLengthMin)
                configurations->textLengthMax = configurations->textLengthMin;
            break;
        case 'l':
            configurations->textLengthMin = atoi(arg);
            if (configurations->textLengthMin <= 0)
                argp_error(state, "Lower limit of generated text's length must be greater than zero.");
            if (configurations->textLengthMin > configurations->textLengthMax)
                configurations->textLengthMin = configurations->textLengthMax;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}