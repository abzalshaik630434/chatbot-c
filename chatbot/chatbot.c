/*created by:ABZAL SHAIK
date:4/4/2025
project:Simple Chatbot*/
#include <stdio.h>
#include <string.h>

void chatbot_response(char input[], int *flag, char name[]) {
    // Convert input to lowercase for better matching
    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] += 32;
    }

    if (strstr(input, "hello") || strstr(input, "hi") || strstr(input, "hey")) {
        printf("Chatbot: Hello! How can I help you today?\n");
    }
    else if (strstr(input, "how are you")) {
        printf("Chatbot: I'm doing well, thanks for asking! What about you?\n");
    }
    else if (strstr(input, "your name")) {
        printf("Chatbot: I'm ChatBot, your virtual assistant!\n");
    }
    else if (strstr(input, "what can you do")) {
        printf("Chatbot: I can chat with you, remember your name, and more as I grow!\n");
    }
    else if (strstr(input, "thank you") || strstr(input, "thanks")) {
        printf("Chatbot: You're welcome! 😊\n");
    }
    else if (strstr(input, "bye") || strstr(input, "exit") || strstr(input, "quit")) {
        printf("Chatbot: Goodbye! Have a wonderful day!\n");
    }
    else if (strstr(input, "ask my name")) {
        printf("Chatbot: Of course! What is your name?\n");
        *flag = 1;
    }
    else if (strstr(input, "tell me a joke")) {
        printf("Chatbot: Why don’t scientists trust atoms? Because they make up everything! 😄\n");
    }
    else if (strstr(input, "what's up") || strstr(input, "sup")) {
        printf("Chatbot: Not much, just hanging around waiting to help you. What about you?\n");
    }
    else if (strstr(input, "do you love me")) {
        printf("Chatbot: I'm just a program, but I think you're pretty cool! ❤️\n");
    }
    else if (strstr(input, "i am bored")) {
        printf("Chatbot: Want to hear a fun fact or a joke? I can try to cheer you up!\n");
    }
    else if (strstr(input, "who made you") || strstr(input, "who created you")) {
        printf("Chatbot: I was created by a brilliant coder. Maybe someone like you? %s,😄\n",name);
    }
    else if (strstr(input, "help")) {
        printf("Chatbot: You can ask me anything like 'your name', 'how are you', 'tell me a joke', or 'ask my name'.\n");
    }
    else if (strstr(input,"tell my name") || strstr(input,"my name"))
    {
        printf("Chatbot:Oh! Hi %s\n",name);
    }
    else {
        printf("Chatbot: I'm still learning! Could you rephrase that?\n");
    }
    
}

int main() {
    char input[100];
    int flag = 0;//for checking name
    char name[100] = "";//storeing name

    printf("Chatbot: Hi! Type 'bye' to exit.\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // remove newline

        if (flag) {
            strncpy(name, input, sizeof(name));
            printf("Chatbot: Nice to meet you, %s!\n", name);
            flag = 0;
            continue;  // skip normal chatbot response for name input
        }

        if (strcmp(input, "bye") == 0) {
            chatbot_response(input, &flag, name);
            break;
        }

        chatbot_response(input, &flag, name);
    }

    return 0;
}
