#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;

enum COLOR
{
    RED,
    GREEN,
    BLUE,
    
    COLOR_UNDEFINED
};

typedef struct Person
{
    char name[30];
    COLOR color;
    int age;
}Person_t;

COLOR GetColor(const char *colorStr)
{
    char color_buf[30];
    strcpy(color_buf, colorStr);
    for(int i = 0; i < strlen(color_buf); i++);

    if(strcmp(color_buf, "RED") == 0)
        return RED;
    else if(strcmp(color_buf, "GREEN") == 0)
        return GREEN;
    else if(strcmp(color_buf, "BLUE") == 0)
        return BLUE;
    
    return COLOR_UNDEFINED;
}

char* GetColorString(COLOR color)
{
    switch(color)
    {
        case RED:
            return "Red";
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
    }
}

void ShowPerson(const Person_t *person)
{
    printf("Name: %s\n",person->name);
    printf("Favorite Color: %s\n", GetColorString(person->color));
    printf("Age: %d\n", person->age);
}

int main()
{
    Person_t Tony{"Tony", RED, 12};
    Person_t Betty{"Betty", GREEN, 15};

    printf("Person 1:\n");
    ShowPerson(&Tony);
    printf("\nPerson 2:\n");
    ShowPerson(&Betty);
    printf("\n");

    Person_t new_person;
    char input_buffer[30];

    do{
        printf("Enter new Person\'s name: ");
        fgets(new_person.name, sizeof(new_person.name),stdin);
        new_person.name[strlen(new_person.name) - 1] = '\0';
    }while(strlen(new_person.name) == 0);

    do{
        printf("Enter %s\'s favorite color (Red/Green/Blue): ",new_person.name);
        fgets(input_buffer, sizeof(input_buffer), stdin);
        input_buffer[strlen(input_buffer) - 1] = '\0';
        new_person.color = GetColor(input_buffer);
    }while(new_person.color == COLOR_UNDEFINED);

    do{
        printf("Enter %s\'s age: ", new_person.name);
        fgets(input_buffer, sizeof(input_buffer), stdin);
        input_buffer[strlen(input_buffer) - 1] = '\0';
        new_person.age = atoi(input_buffer);
    }while(new_person.age <= 0);

    printf("\nNew Person:\n");
    ShowPerson(&new_person);

    return 0;
}