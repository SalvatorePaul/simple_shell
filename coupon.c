#include "myshell.h"

/**
 * splitString - Splits a string into words based on a delimiter.
 *
 * @inputStr: The input string to be split.
 * @delimiter: The character used as a delimiter to split the string.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **splitString1(char *inputStr, char delimiter)
{
	int currentIndex, wordIndex, charIndex, charCount, numWords = 0;
	char **wordArray;

	if (inputStr == NULL || inputStr[0] == '\0') {
		return NULL; /* Check for empty or NULL input string */
	}

	/* Count the number of words based on the delimiter */
	for (currentIndex = 0; inputStr[currentIndex] != '\0'; currentIndex++) {
		if ((inputStr[currentIndex] != delimiter && inputStr[currentIndex + 1] == delimiter) ||
		    (inputStr[currentIndex] != delimiter && !inputStr[currentIndex + 1]) || inputStr[currentIndex + 1] == delimiter) {
			numWords++;
		}
	}

	if (numWords == 0) {
		return NULL; /* No words found */
	}

	/* Allocate memory for the array of words */
	wordArray = malloc((1 + numWords) * sizeof(char *));
	if (!wordArray) {
		return (NULL); /* Memory allocation failed */
	}

	/* Iterate through the input string and split it into words */
	for (currentIndex = 0, wordIndex = 0; wordIndex < numWords; wordIndex++) {
		while (inputStr[currentIndex] == delimiter && inputStr[currentIndex] != '\0') {
			currentIndex++;
		}
		charCount = 0;
		while (inputStr[currentIndex + charCount] != delimiter && inputStr[currentIndex + charCount] && inputStr[currentIndex + charCount] != delimiter) {
			charCount++;
		}

		/* Allocate memory for the current word */
		wordArray[wordIndex] = malloc((charCount + 1) * sizeof(char));
		if (!wordArray[wordIndex]) {
			/* Memory allocation failed, clean up previous allocations */
			for (charIndex = 0; charIndex < wordIndex; charIndex++) {
				free(wordArray[charIndex]);
			}
			free(wordArray);
			return NULL;
		}

		/* Copy the characters of the current word */
		for (charIndex = 0; charIndex < charCount; charIndex++) {
			wordArray[wordIndex][charIndex] = inputStr[currentIndex++];
		}
		wordArray[wordIndex][charIndex] = '\0'; /* Null-terminate the word */
	}
	wordArray[wordIndex] = NULL; /* Null-terminate the word array */

	return wordArray;
}

/**
 * splitString - Splits a string into words using the given delimiter string.
 *
 * @inputString: The input string to split.
 * @delimiterString: The delimiter string used for splitting.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **splitString(char *inputString, char *delimiterString)
{
    int numWords = 0;         /* Number of characters in a word */
    char **resultArray;  /* Array to store the resulting words */
    int index1;
    int index2;
    int index3;
    int index4;

if (inputString == NULL || inputString[0] == 0)
    return (NULL);  /* Check for NULL or empty input string */

if (!delimiterString)
    delimiterString = " ";  /* Set a default delimiter if not provided */

for (index1 = 0; inputString[index1] != '\0'; index1++)
{
    if (!check_delim(inputString[index1], delimiterString) && (check_delim(inputString[index1 + 1], delimiterString) ||
            !inputString[index1 + 1]))
    {
        numWords++;  /* Count the number of words */
    }
}

if (numWords == 0)
    return (NULL);  /* If no words found, return NULL */

resultArray = malloc((1 + numWords) * sizeof(char *));  /* Allocate memory for an array of strings */

if (!resultArray)
    return (NULL);  /* Check for memory allocation failure */

for (index1 = 0, index2 = 0; index2 < numWords; index2++)
{
    while (check_delim(inputString[index1], delimiterString))
    {
        index1++;  /* Skip leading delimiters */
    }
    index3 = 0;

    while (!check_delim(inputString[index1 + index3], delimiterString) && inputString[index1 + index3])
    {
        index3++;  /* Find the length of the word */
    }

    resultArray[index2] = malloc((index3 + 1) * sizeof(char));  /* Allocate memory for a word */

    if (!resultArray[index2])
    {
        /* Memory allocation failure, free previously allocated memory and return NULL */
        for (index3 = 0; index3 < index2; index3++)
        {
            free(resultArray[index3]);
        }
        free(resultArray);
        return (NULL);
    }

    for (index4 = 0; index4 < index3; index4++)
    {
        resultArray[index2][index4] = inputString[index1++];  /* Copy the word from the input string */
    }
    resultArray[index2][index4] = 0;  /* Null-terminate the copied word */
}
resultArray[index2] = NULL;  /* Null-terminate the result array */
return (resultArray);
}
