#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
    size_t left, right;

    // left
    if (direction == 1)
    {
        left = 0;
        for ( right = 1; right < size; right++)
        {
            if (line[left] == line[right])
            {
                line[left] = line[left] * 2;
                line[right] = 0;
                right++;
                while (line[right] != 0 && right < size)
                {
                    right++;
                }
                left++;
                line[left] = line[right];
                line[right] = 0;
                right++;
                
            }
            
        }
        
    }

    return(1);
}