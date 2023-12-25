#include <stdio.h>
#include <string.h>

// A structure for the valorant agents
struct Agent {
    const char *name;
    const char *role;
    const char *questions[3];
};

// Code for yes/no questions
char askQuestion(const char *question) {
    char response;
    printf("%s (y/n): ", question);
    scanf(" %c", &response);
    return response;
}

// Code to guess the specific agent based on our response
const char *guessAgentForRole(struct Agent roleAgents[], int numAgents) {
    int i, j;

    for (i = 0; i < numAgents; i++) {
        int correctAnswers = 0;
        char response;

        for (j = 0; j < 3; j++) {
            response = askQuestion(roleAgents[i].questions[j]);

            // for case-insensitive
            response = tolower(response);

            if (response == 'y') {
                correctAnswers++;
            } else {
                // Move to the next agent's questions if the previous one was wrong
                break;
            }
        }

        // If 3 answers are correct, make the guess
        if (correctAnswers == 3) {
            return roleAgents[i].name;
        }
    }

    return "Unknown";
}

// Code  for guessing the agent's role
const char *guessRole(struct Agent controllers[], struct Agent initiators[], struct Agent duelists[], struct Agent sentinels[]) {
    const char *guessedRole = "Unknown";
    char response;

    printf("Is your agent a Controller? (y/n): ");
    scanf(" %c", &response);
    response = tolower(response);

    if (response == 'y') {
        guessedRole = "Controller";
    } else {
        printf("Is your agent a Duelist? (y/n): ");
        scanf(" %c", &response);
        response = tolower(response);

        if (response == 'y') {
            guessedRole = "Duelist";
        } else {
            printf("Is your agent an Initiator? (y/n): ");
            scanf(" %c", &response);
            response = tolower(response);

            if (response == 'y') {
                guessedRole = "Initiator";
            } else {
                printf("Is your agent a Sentinel? (y/n): ");
                scanf(" %c", &response);
                response = tolower(response);

                if (response == 'y') {
                    guessedRole = "Sentinel";
                }
            }
        }
    }

    return guessedRole;
}

int main() {
    // Separate arrays for characteristics of every agent in each role
    struct Agent controllers[] = {
        {"Brimstone", "Controller", {"Is the agent from America?", "Can you consider the agent as old?", "Is the agent associated with fire?"}},
        {"Viper", "Controller", {"Is the agent a female?", "Is the agent associated with poison?", "Does the agent have something to do with an animal?"}},
        {"Astra", "Controller", {"Does the agent have a wall skill?", "Does the agent like purple?", "Is the agent associated with outer space?"}},
        {"Harbor", "Controller", {"Is the agent associated with water?", "Does this agent have a bubble skill?", "Does the agent get its power from ancient technology?"}},
        {"Omen", "Controller", {"Can this agent teleport?", "Does the agent like cats?", "Can this agent blind?"}},
    };

    struct Agent duelists[] = {
        {"Jett", "Duelist", {"Is this agent from Korea?", "Can this agent fly?", "Does this agent have knives?"}},
        {"Pheonix", "Duelist", {"Is this agent from the U.K?", "Can this agent die twice in a round?", "Is the agent associated with fire?"}},
        {"Reyna", "Duelist", {"Is this agent from Mexico?", "Does this agent have a robot?", "Does this agent have an RPG?"}},
        {"Neon", "Duelist", {"Is this agent from the Philippines?", "Does the agent have speed skills?", "Is the agent associated with electricity"}},
        {"Yoru", "Duelist", {"Is this agent from Japan?", "Can this agent teleport?", "Can this agent become invisible in its ultimate?"}},
        {"Iso", "Duelist", {"Is this agent from China?", "Can this agent be invulnerable?", "Does this agent like to 1v1?"}},
    };

    struct Agent initiators[] = {
        {"Kayo", "Initiator", {"Is the agent a Human?", "Can the agent disrupt enemies' abilities?", "Can this agent be revived in its ultimate?"}},
        {"Breach", "Initiator", {"Is this agent from Sweden?", "Does the agent have seismic abilities?", "Can the agent knock up the enemies using its ultimate?"}},
        {"Sova", "Initiator", {"Is this agent from Russia?", "Does the agent use a bow?", "Does the agent like to hunt?"}},
        {"Skye", "Initiator", {"Is this agent from Australia?", "Can this agent make animals?", "Can this agent heal?"}},
        {"Fade", "Initiator", {"Is this agent from Turkey?", "Is the agent associated with nightmares?", "Can the agent disrupt enemies' hearing?"}},
        {"Gekko", "Initiator", {"Is this agent from America?", "Does the agent have pets?", "Can this agent's pet plant the bomb/spike?"}},
    };

    struct Agent sentinels[] = {
        {"Sage", "Sentinel", {"Is this agent from China?", "Does the agent have healing and support abilities?", "Does this agent have a wall?"}},
        {"Chyper", "Sentinel", {"Is this agent from Morocco?", "Does the agent trap abilities?", "Can this agent reveal the enemies' location with its ultimate?"}},
        {"Killjoy", "Sentinel", {"Is this agent from Germany?", "Does this agent make technology?", "Can this agent detain any enemy in its ultimate radius?"}},
        {"Chamber", "Sentinel", {"Is this agent from France?", "Is this agent rich?", "Does this agent have guns for its skills?"}},
        {"Deadlock", "Sentinel", {"Is this agent from Norway?", "Does the agent have a prosthetic arm?", "Does this agent use high-tech technology?"}},
    };

    printf("Welcome to Guess the Valorant Agent!\n");

    char playAgain;
    do {
        const char *guessedRole = guessRole(controllers, initiators, duelists, sentinels);
        const char *guessedAgent = "Unknown";

        if (strcmp(guessedRole, "Controller") == 0) {
            guessedAgent = guessAgentForRole(controllers, sizeof(controllers) / sizeof(controllers[0]));
        } else if (strcmp(guessedRole, "Initiator") == 0) {
            guessedAgent = guessAgentForRole(initiators, sizeof(initiators) / sizeof(initiators[0]));
        } else if (strcmp(guessedRole, "Duelist") == 0) {
            guessedAgent = guessAgentForRole(duelists, sizeof(duelists) / sizeof(duelists[0]));
        } else if (strcmp(guessedRole, "Sentinel") == 0) {
            guessedAgent = guessAgentForRole(sentinels, sizeof(sentinels) / sizeof(sentinels[0]));
        }

        // Code for the final guess
        printf("Is the agent %s?\n", guessedAgent);

        printf("(y/n): ");
        char response;
        scanf(" %c", &response);

        response = tolower(response);
        // Response to if the guess was correct or not
        if (response == 'y') {
            printf("Yay!\n");
        } else {
            printf("Aww!\n");
        }
        // Code if you want to continue playing
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    printf("Thanks for playing! Goodbye!\n");

    return 0;
}
