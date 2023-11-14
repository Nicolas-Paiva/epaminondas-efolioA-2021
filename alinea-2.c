#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Checks whether a string meets all the criteria to be valid
int checkString(char string[]);

int addStrings(char validStrings[50][51], char allStrings[50][51]);

int main(void)
{
  char allStrings[50][51] = {"AIDQGDUGBK", "QZLXIIUKYE", "XDNNTNNRNY", "XDNNTNNRNY", "XDNNTNNRNY", "XDNNTNNRNY", "XDNNTNNRNY", "XDNNTNNRNY", "XDNNTNNRNY", ""};
  char validStrings[50][51];

  int isValid = 0;
  int validStringsIndex = 0;
  int validWords = 0;

  addStrings(validStrings, allStrings);

  for (int i = 0; i < 7; i++)
  {
    printf("%s\n", validStrings[i]);
  }
  
  return 0;
}

int checkString(char string[])
{
  // Checks whether the string has more than 10 characters:
  int stringLength = strlen(string);
  if (stringLength > 10 || stringLength < 10)
  {
    return 0;
  }

  // Checks whether there is a non uppercase character in the string
  for (int i = 0; i < stringLength; i++)
  {
    if (isupper(string[i]) == 0)
    {
      return 0;
    }
  }
  return 1;
}

int addStrings(char validStrings[50][51], char allStrings[][51])
{
  int isValid = 0;
  int index = 0;
  int counter = 0;
  for (int i = 0; allStrings[i][0] != '\0'; i++)
  {
    isValid = checkString(allStrings[i]);
    if (isValid == 1)
    { // If the string is valid we copy it into the "validStrings" array
      int j;
      for (j = 0; allStrings[i][j] != '\0'; j++)
      {
        validStrings[index][j] = allStrings[i][j];
      }
      validStrings[index][j] = '\0';
      index++;
      counter++;
    }
  }
  return counter;
}
