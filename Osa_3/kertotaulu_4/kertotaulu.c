#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Helper function to calculate the number of digits in a number */
static int num_digits(uint num)
{
    int digits = 0;
    if (num == 0)
        return 1;
    while (num != 0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

char **luo_kertotaulu_mjt(uint a, uint b, uint c, uint d)
{
    uint i, j;
    uint rows = d - c + 2; /* Including header row */
    uint cols = b - a + 1; /* Number of columns */

    /* Allocate array for column widths */
    int *col_widths = malloc((cols + 1) * sizeof(int)); /* +1 for header column */
    if (col_widths == NULL)
    {
        return NULL;
    }

    /* Initialize column widths */
    for (j = 0; j <= cols; j++)
    {
        col_widths[j] = 0;
    }

    /* Calculate column widths */
    /* First column is header column (row labels), index 0 */
    col_widths[0] = num_digits(d); /* The widest row label */

    /* Compute widths for header row (column headers) */
    for (j = 0; j < cols; j++)
    {
        /* For header row, the maximum value is the column header itself */
        int width = num_digits(a + j);
        if (width > col_widths[j + 1])
        {
            col_widths[j + 1] = width; /* Width for each data column */
        }
    }

    /* Compute widths for data columns */
    for (j = 0; j < cols; j++)
    {
        uint max_value = d * (a + j); /* Maximum value in column j */
        int width = num_digits(max_value);
        if (width > col_widths[j + 1])
        {
            col_widths[j + 1] = width;
        }
    }

    /* Allocate array of strings (char pointers) */
    char **rows_array = malloc(rows * sizeof(char *));
    if (rows_array == NULL)
    {
        free(col_widths);
        return NULL;
    }

    /* Calculate total width of each row */
    int total_width = 0;
    for (j = 0; j <= cols; j++)
    {
        total_width += col_widths[j];
        if (j != cols)
            total_width += 1; /* Space between columns */
    }
    total_width += 1; /* Null terminator */

    /* Generate header row */
    /* Allocate memory for header row */
    rows_array[0] = malloc(total_width * sizeof(char));
    if (rows_array[0] == NULL)
    {
        free(col_widths);
        free(rows_array);
        return NULL;
    }

    /* Build header row */
    {
        char *ptr = rows_array[0];
        int pos = 0;

        /* First cell in header row is empty */
        for (j = 0; j < col_widths[0]; j++)
        {
            ptr[pos++] = ' ';
        }
        if (cols > 0)
            ptr[pos++] = ' '; /* Space between columns */

        for (j = 0; j < cols; j++)
        {
            /* Print column headers */
            int width = col_widths[j + 1];
            uint num = a + j;
            int len = sprintf(ptr + pos, "%*u", width, num);
            pos += len;
            if (j != cols - 1)
                ptr[pos++] = ' ';
        }
        ptr[pos] = '\0';
    }

    /* Generate data rows */
    for (i = 1; i < rows; i++)
    {
        /* Allocate memory for each row */
        rows_array[i] = malloc(total_width * sizeof(char));
        if (rows_array[i] == NULL)
        {
            free(col_widths);
            for (j = 0; j < i; j++)
                free(rows_array[j]);
            free(rows_array);
            return NULL;
        }

        /* Build data row */
        {
            char *ptr = rows_array[i];
            int pos = 0;
            uint row_label = c + i - 1;

            /* Print row label */
            int len = sprintf(ptr + pos, "%*u", col_widths[0], row_label);
            pos += len;
            if (cols > 0)
                ptr[pos++] = ' '; /* Space between columns */

            /* Print row data */
            for (j = 0; j < cols; j++)
            {
                int width = col_widths[j + 1];
                uint value = row_label * (a + j);
                len = sprintf(ptr + pos, "%*u", width, value);
                pos += len;
                if (j != cols - 1)
                    ptr[pos++] = ' ';
            }
            ptr[pos] = '\0';
        }
    }

    /* Clean up */
    free(col_widths);

    return rows_array;
}

