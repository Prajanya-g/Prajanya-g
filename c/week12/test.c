/*
 #include <stdio.h>
 #include <stdlib.h>

 void array_copy2d(int** src, int** dest, int rows, int cols)
 {
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
             dest[i][j] = src[i][j];
         }
     }
 }

 int main(void)
 {
     int rows = 2, cols = 3;
     int row0[] = {10, 20, 30};
     int row1[] = {40, 50, 60};
     int* nums[2];
     nums[0] = row0;
     nums[1] = row1;
     
     int** nums_copy = malloc(sizeof(int*) * rows);
     if (nums_copy == NULL) {
         printf("Memory Allocation Error\n");
         return -1;
     }
     for (int i = 0; i < rows; i++) {
         nums_copy[i] = malloc(sizeof(int) * cols);
         if (nums_copy[i] == NULL) {
             printf("Memory Allocation Error\n");
             return -1;
         }
     }
     
     array_copy2d(nums, nums_copy, rows, cols);
     
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
             printf("nums_copy[%d][%d] = %d\n", i, j, nums_copy[i][j]);
         }
     }
     
     for (int i = 0; i < rows; i++) {
         free(nums_copy[i]);
     }
     free(nums_copy);
     
     return 0;
 }
 */
/*
 #include <stdio.h>
 #include <stdlib.h>

 int** array_copy2d(int** src, int rows, int cols)
 {
     int** dest = malloc(sizeof(int*) * rows);
     if (dest == NULL) {
         return NULL;
     }
     for (int i = 0; i < rows; i++) {
         dest[i] = malloc(sizeof(int) * cols);
         if (dest[i] == NULL) {
             return NULL;
         }
     }
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
             dest[i][j] = src[i][j];
         }
     }
     return dest;
 }

 int main(void)
 {
     int rows = 2, cols = 3;
     int row0[] = {1, 2, 3};
     int row1[] = {4, 5, 6};
     int* nums[2];
     nums[0] = row0;
     nums[1] = row1;
     
     int** nums_copy = array_copy2d(nums, rows, cols);
     if (nums_copy == NULL) {
         printf("Memory Allocation Error\n");
         return -1;
     }
     
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
             printf("nums_copy[%d][%d] = %d\n", i, j, nums_copy[i][j]);
         }
     }
     
     for (int i = 0; i < rows; i++) {
         free(nums_copy[i]);
     }
     free(nums_copy);
     
     return 0;
 }
 */
