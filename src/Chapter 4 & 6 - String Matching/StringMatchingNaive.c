#include "stdio.h"
#include "string.h"
#include "stdbool.h"

/*
 * "Naive" Algorithm of String Matching to find the number of occurrences of a pattern in a text.
 *
 * Given a text of size N and pattern of size M, the algorithm iterates the entire string once
 * and compares all characters  with the first character of the pattern, if this happens to be true, then it compares
 * all subsequent M characters of the string with the characters of the pattern, if any of those comparisons fails,
 * the appropriate variable is set to false. At the end of the second iteration, if said variable still holds true,
 * then the pattern is found and the number of occurrences is increase by one.
 *
 * In the worst case, the algorithm performs N*M comparisons between characters, therefore the complexity is O(N*M)
 * If N >> M, O ≈ O(N)
 *
 * The function takes as input a text and a pattern, and returns the number of occurrences of pattern in text.
 */
int string_matching(char *text, char* pattern)
{
    unsigned int text_len = strlen(text);
    unsigned int pattern_len = strlen(pattern);
    int counter = 0;
    for(int i = 0; i < text_len; i++) {
        int j = 0;
        bool found = false;
        if(text[i] == pattern[j]) {
            found = true;
            for(; j < pattern_len; j++) {
                if(text[i + j] != pattern[j]) {
                    found = false;
                }
            }
            if(found) counter++;
        }
    }
    return counter;
}

int main()
{
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor metus sem, "
                 "faucibus tincidunt tellus scelerisque sed. "
                 "Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.";
    char *pattern = "us";
    printf("NO. OF OCCURRENCES: %d.\n", string_matching(text, pattern));

    return 0;
}
