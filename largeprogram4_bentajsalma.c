
// Salma Bentaj
// Steinberg
// COP3200
//Large Program 4


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 30

typedef struct{
    char firstName[MAXSIZE];
    char lastName[MAXSIZE];
    int age;
    char gender[MAXSIZE];
    char powers[MAXSIZE];
} anime;


void menu (void);
anime * insert (anime animeList[MAXSIZE], int size, int *characters);
void removeAnime (anime animeList[MAXSIZE], int size);
void search (anime animeList[MAXSIZE]);
void display(anime animeList[MAXSIZE], int size, int *characters);

int main(void)
{
  char option;
  int characters = 6;
  int size = characters;
  anime animeList[MAXSIZE];
  
  
  printf("Welcome to the Anime Character Catalog!\n");

    do {
        menu();

        printf("Enter Option: ");
        scanf(" %c", &option);

        if (toupper(option) == 'A')
        {
            printf("Insert was selected...\n");
            insert(animeList, size, &characters);
        }
        
        if (toupper(option) == 'D')
        {
            printf("Display was selected...\n");
            display(animeList, size, &characters);
        }

        if (toupper(option) == 'R')
        {
            printf("Remove was selected...\n");
            removeAnime (animeList, size);
        }

        if (toupper(option) == 'S')
        {
            printf("Search was selected...");
            search (animeList);
        }
      
    
    }while (toupper(option) != 'E');
    
    
    if (toupper(option) == 'E')
    {
        printf("Thank you. Good Bye.");
    }
    
    
  return 0;
}

void menu (void)
{
  printf("What would you like to do?\n");
  printf("A: Add a New Anime Character\n");
  printf("R: Remove an Anime Character\n");
  printf("D: Display All Anime Characters\n");
  printf("S: Search Up an Anime Character\n");
  printf("E: Exit\n");

}




anime * insert (anime animeList[MAXSIZE], int size, int *characters)
{

    printf("How many characters would you like to add to the catalog?\n");
    scanf("%d", characters);

    printf("Please enter the first name of the anime character: ");

    scanf("%s", animeList[size].firstName);
    printf("%s", animeList[size].firstName);

    printf("Please enter the last name of the anime character: ");
    scanf("%s", animeList[size].lastName);
    printf("%s", animeList[size].lastName);
      
      
    printf("Please enter the age of the anime character: ");
    scanf("%d", &animeList[size].age);
    printf("%d", animeList[size].age);

    printf("Please enter the gender of the character: ");
    scanf("%s", animeList[size].gender);
    printf("%s", animeList[size].gender);

    printf("Do they have powers? (Yes/No): ");
    scanf("%s", animeList[size].powers);
    printf("%s", animeList[size].powers);
      
    printf("Adding new anime character to catalog\n");
    
  
    size++;
    
    
    return animeList;
}




void display (anime animeList[MAXSIZE], int size, int *characters)
{
    strcpy(animeList[0].firstName, "Yuji");
    strcpy(animeList[0].lastName, "Itadori");
    animeList[0].age = 15;
    strcpy(animeList[0].gender, "Male");
    strcpy(animeList[0].powers, "Yes");
    
    strcpy(animeList[1].firstName, "Gojo");
    strcpy(animeList[1].lastName, "Satori");
    animeList[1].age = 28;
    strcpy(animeList[1].gender, "Male");
    strcpy(animeList[1].powers, "Yes");
    
    strcpy(animeList[2].firstName, "Kaname");
    strcpy(animeList[2].lastName, "Kuran");
    animeList[2].age = 10000;
    strcpy(animeList[2].gender, "Male");
    strcpy(animeList[2].powers, "Yes");
    
    strcpy(animeList[3].firstName, "Akira");
    strcpy(animeList[3].lastName, "Fudo");
    animeList[3].age = 16;
    strcpy(animeList[3].gender, "Male");
    strcpy(animeList[3].powers, "Yes");
    
    strcpy(animeList[4].firstName, "Taiga");
    strcpy(animeList[4].lastName, "Aisaka");
    animeList[4].age = 18;
    strcpy(animeList[4].gender, "Female");
    strcpy(animeList[4].powers, "No");
    
    strcpy(animeList[5].firstName, "Megumi");
    strcpy(animeList[5].lastName, "Fushigoro");
    animeList[5].age = 15;
    strcpy(animeList[5].gender, "Male");
    strcpy(animeList[5].powers, "Yes");

    
    for(int x = 0; x < *characters; x++)
    {
        printf("Character %d\n", x);
        printf("First Name: %s\n", (x + animeList)->firstName);
        printf("Last Name: %s\n", (x + animeList)->lastName);
        printf("Age: %d\n", (x + animeList)->age);
        printf("Gender: %s\n", (x + animeList)->gender);
        printf("Powers: %s\n", (x + animeList)->powers);

        characters++;
    }
}

void removeAnime (anime animeList[MAXSIZE], int size)
{
  int index;
    printf("What index would you like to remove?\n");
    printf("Index: ");
    scanf("%d", &index);
    if (index < 0 || index >= size)
    {
        printf("That is not a character in the catalog\n");
    }
    
    for (int i = index; i < size; i++)
    {
      if (i >= 0 && i <=5)
      {
        // make a loop to clear out the hardcopied struct arrays hbut setting them to null and then swapping and shifting over the elements
        //animeList[i].firstName = NULL;
      }
        strcpy(animeList[i].firstName, animeList[i + 1].firstName);
        strcpy(animeList[i].lastName, animeList[i + 1].lastName);
        animeList[i].age = animeList[i + 1].age;
        strcpy(animeList[i].gender, animeList[i + 1].gender);
        strcpy(animeList[i].powers, animeList[i + 1].powers);

    }
}


void search (anime animeList[MAXSIZE])
{
  char input [MAXSIZE];

  printf("Please enter the character you would like to search\n");
  printf("First Name: ");
  scanf("%s", input);

for (int i = 0; i < MAXSIZE; i++)
{
  if (strcmp(animeList[i].firstName, input) == 0)
{
        printf("Character %d\n", i);
        printf("First Name: %s\n", (i + animeList)->firstName);
        printf("Last Name: %s\n", (i + animeList)->lastName);
        printf("Age: %d\n", (i + animeList)->age);
        printf("Gender: %s\n", (i + animeList)->gender);
        printf("Powers: %s\n", (i + animeList)->powers);
}
else
{
  printf("That character is not in the catalog, please try again\n");
  printf("First Name: ");
  scanf(" %s", input);
}

}


}
