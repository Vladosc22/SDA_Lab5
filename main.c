
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


#define MEASURE_TIME(code_block)                          \
   clock_t start = clock();                          \
   code_block                                        \
   clock_t end = clock();                            \
   double time_spent = (double)(end - start) / CLOCKS_PER_SEC; \
   printf("Time taken: %.10f s\n", time_spent);      \

#define ARRAY_SIZE 100000

/*
   Selection Sort
*/

void selection_sort(int * arr)
{
   for (int i = 0; i < ARRAY_SIZE - 1; i++)
   {
       int min_index = i;

       for (int j = i + 1; j < ARRAY_SIZE; j++)
       {
           if (arr[j] < arr[min_index])
           {
               min_index = j;
           }
       }
      
       if (min_index != i)
       {
           int tmp = arr[min_index];
           arr[min_index] = arr[i];
           arr[i] = tmp;   
       }
   }
}

/*
   Insertion Sort
*/

void insertion_sort(int * arr)
{
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
       int j = i;

       while (arr[j] < arr[j - 1] && j > 0)
       {  
           int tmp = arr[j];
           arr[j] = arr[j - 1];
           arr[j - 1] = tmp;
           j--;
       }
   }
}

/*
   Bubble Sort
*/

void bubble_sort(int * arr)
{
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
       for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
       {
           if (arr[j] > arr[j + 1])
           {
               int tmp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = tmp;
           }
       }
   }
}

/*
   Merge Sort
*/

void merge_sort_helper(int * main_arr, int * tmp_arr, int main_len)
{
   if (main_len <= 1) return;

   // divide
   int mid_index = main_len / 2;

   // sort left
   merge_sort_helper(main_arr, tmp_arr, mid_index);

   // sort right
   merge_sort_helper(main_arr + mid_index, tmp_arr + mid_index, main_len - mid_index);

   //merge
   int left_iter = 0, right_iter = mid_index, main_iter = 0;

   while (left_iter < mid_index && right_iter < main_len)
   {
       if (main_arr[left_iter] <= main_arr[right_iter])
       {
           tmp_arr[main_iter++] = main_arr[left_iter++];
       }
       else
       {
           tmp_arr[main_iter++] = main_arr[right_iter++];
       }
   }
  
   while (left_iter < mid_index)
   {
       tmp_arr[main_iter++] = main_arr[left_iter++];
   }
  
   while (right_iter < main_len)
   {
       tmp_arr[main_iter++] = main_arr[right_iter++];
   }

   // coppy merged to original
   memcpy(main_arr, tmp_arr, sizeof(int) * main_len);
}

void merge_sort(int * arr)
{
   if (ARRAY_SIZE <= 1) return;

   int * tmp_arr = (int *)malloc(sizeof(int) * ARRAY_SIZE);

   merge_sort_helper(arr, tmp_arr, ARRAY_SIZE);

   free(tmp_arr);
}

/*
   Quick Sort:
*/

void swap(int * arr, int index_1, int index_2)
{
   int tmp = arr[index_1];
   arr[index_1] = arr[index_2];
   arr[index_2] = tmp;
}

int get_random_int(int min, int max) {
   return rand() % (max - min + 1) + min;
}

int get_pivot_index(int * arr, int lenght)
{
   return get_random_int(0, lenght - 1);
}

void quick_sort_helper(int * arr, int length)
{
   if (length <= 1) return;

   int pivot_index = get_pivot_index(arr, length);

   swap(arr, pivot_index, length - 1);
   pivot_index = length - 1;

   int left_index = 0;
   int right_index = length - 2;

   while (left_index <= right_index)
   {
       while (left_index <= right_index && arr[left_index] < arr[pivot_index])
       {
           left_index++;
       }
      
       while (left_index <= right_index && arr[right_index] > arr[pivot_index])
       {
           right_index--;
       }

       if (left_index <= right_index)
       {
           swap(arr, right_index, left_index);
           left_index++;
           right_index--;
       }
   }

   swap(arr, left_index, pivot_index);

   quick_sort_helper(arr, left_index);
   quick_sort_helper(arr + left_index + 1, length - left_index - 1);
}

void quick_sort(int * arr)
{
   quick_sort_helper(arr, ARRAY_SIZE);
}

/*
   Heap Sort - Build Max-Heap:
*/

void max_heapify(int * arr, int length, int parrent_index)
{
   int left_index = 2 * parrent_index + 1;
   int right_index = 2 * parrent_index + 2;

   int max_index = parrent_index;

   if (left_index < length && arr[left_index] > arr[max_index])
   max_index = left_index;

   if (right_index < length && arr[right_index] > arr[max_index])
   max_index = right_index;   
  
   if (max_index != parrent_index)
   {  
       swap(arr, max_index, parrent_index);
       max_heapify(arr, length, max_index);
   }
}

void build_max_heap(int * arr, int length)
{
   /*
       Este formula care ne de indexul la cel
       mai din dreapta nod care nu este frunza.

       Index = N / 2 - 1
   */
   for (int i = length / 2 - 1; i >= 0; i--)
       max_heapify(arr, length, i);
}

void heap_sort(int * arr)
{
   build_max_heap(arr, ARRAY_SIZE);

   /*
       Scoatem cate un nod din Max-Heap

       Swap last cu topul heapului
       facem max heapify pe tot
       heapul inafara de ultimul elem.
   */
   for (int tmp_legth = ARRAY_SIZE; tmp_legth > 0; tmp_legth--)
   {
       swap(arr, tmp_legth - 1, 0);
       max_heapify(arr, tmp_legth - 1, 0);
   }
}

/*
   Array Manipulations
*/

void populate_arr(int * arr)
{
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
       arr[i] = rand() % 1000;
   }
}

void print_arr(int * arr)
{
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
       printf("%d ", arr[i]);
   }
   printf("\n");
}

/*
   User Action
*/

void print_main_menu()
{
   printf("1. Initializare Tabloul\n");
   printf("2. Afisare Tabloul\n");
   printf("3. Sortare\n");
   printf("0. Eliberare Memorie & Iesire\n");
}

void print_sorting_menu()
{
   printf("1. Selection Sort\t");
   printf("4. Merge Sort\n");
   printf("2. Insertion Sort\t");
   printf("5. Quick Sort\n");
   printf("3. Bubble Sort  \t");
   printf("6. Heap Sort\n");
}

int get_menu_choice(void (*menu_printer)(), int choice_from, int choice_to)
{
   int user_choice;

   menu_printer();

   while (true)
   {
       printf("Introdu Optiunea:");
       scanf("%d", &user_choice);

       if (choice_from <= user_choice && user_choice <= choice_to)
       {
           return user_choice;
       }
      
       printf("Optiune Invalida\n");
   }
}

void perform_chosen_sort(int user_choice, int * arr)
{
   switch (user_choice)
   {
   case 1:
       selection_sort(arr);
       break;
   case 2:
       insertion_sort(arr);
       break;
   case 3:
       bubble_sort(arr);
       break;       
   case 4:
       merge_sort(arr);
       break;
   case 5:
       quick_sort(arr);
       break;                          
   case 6:
       heap_sort(arr);
       break;           
   }
}

void handle_sorting(int * arr)
{
   int user_choice = get_menu_choice(print_sorting_menu, 1, 6);

   // LARGE_INTEGER freq, start, end;
   // QueryPerformanceFrequency(&freq);
   // QueryPerformanceCounter(&start);

   MEASURE_TIME ({
       perform_chosen_sort(user_choice, arr);
   });

   // QueryPerformanceCounter(&end);
   // double time_taken = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

   // printf("---------------------------------------------\n");
   // printf("Sortarea a avut loc in %.10lf secunde\n", time_taken);
   // printf("---------------------------------------------\n");
}

/*
   Main
*/

int main()
{
   int * arr = (int *)calloc(ARRAY_SIZE, sizeof(int));

   while (true)
   {
       int user_choice = get_menu_choice(print_main_menu, 0, 3);

       switch (user_choice)
       {
       case 1:
           populate_arr(arr);
           break;
       case 2:
           print_arr(arr);
           break;
       case 3:
           handle_sorting(arr);
           break;
       case 0:
           free(arr);
           arr = NULL;
           return 0;
       }
   }
  
   return 0;
}
