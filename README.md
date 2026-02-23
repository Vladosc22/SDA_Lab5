🔢 Sorting Algorithms Benchmark (Menu-Driven) in C
📖 Project Overview

This project is a C console application that demonstrates and benchmarks multiple classic sorting algorithms on a large array of integers.
The user can initialize the array with random values, print it, choose a sorting algorithm from a menu, and measure execution time using clock().

It is designed for learning algorithm behavior, complexity, and practical runtime differences.

✅ Features

✅ Menu-driven CLI (initialize / print / sort / exit)
✅ Random array generation (populate_arr)
✅ Sorting algorithm selection menu
✅ Benchmarking macro (MEASURE_TIME) to measure execution time
✅ Implements 6 sorting algorithms:

Selection Sort

Insertion Sort

Bubble Sort

Merge Sort

Quick Sort (random pivot)

Heap Sort (max-heap)

🧠 Algorithms Implemented
1️⃣ Selection Sort

Repeatedly selects the smallest element and swaps it into position

Time: O(n²)

Space: O(1)

2️⃣ Insertion Sort

Builds sorted portion incrementally by inserting elements into the correct position

Time: O(n²) (best case O(n) when nearly sorted)

Space: O(1)

3️⃣ Bubble Sort

Repeatedly swaps adjacent out-of-order elements

Time: O(n²)

Space: O(1)

4️⃣ Merge Sort

Divide-and-conquer; splits array and merges sorted halves

Time: O(n log n)

Space: O(n) (temporary buffer)

5️⃣ Quick Sort (Random Pivot)

Partition-based divide-and-conquer using a random pivot

Average: O(n log n)

Worst-case: O(n²)

Space: recursion stack (≈ O(log n) average)

6️⃣ Heap Sort (Max-Heap)

Builds a max-heap and extracts the max repeatedly

Time: O(n log n)

Space: O(1)

⚙️ Array Size

The program uses a fixed size:

#define ARRAY_SIZE 100000
🏗️ Project Structure
.
├── main.c
└── README.md

Problema: 
1.1 Să se elaboreze un program ce va aloca dinamic un tablou unidimensional de numere întregi și va implementa următoarele funcții, funcțiile vor fi organizate sub forma unui meniu:
1.	Inițializarea tabloului cu numere aleatorii;
2.	Afișarea tabloului;
3.	Eliberarea memoriei tabloului;
4.	Sortarea tabloului utilizând una din metode ( selection sort, insertion sort, bubble sort), se va afișa în cât timp a fost executată sortarea;
5.	sortarea tabloului utilizând una din metode ( merge sort, quick sort, heap sort ), se va afișa în cît timp a fost executată sortarea.

1.2 Să se realizeze o analiză empirică a timpului necesar pentru a sorta un tablou aleator de lungimea N unde N va avea valori [100, 1000, 10000, 100000], rezultatele obținute se vor plasa în tabelul de mai jos:
N	100	1000	10000	100000	
Metoda de sortare 1 ( ex. selection sort)					
Metoda de sortare 2 ( ex. heap sort)					
 

2.1 Să se elaboreze un program ce va aloca dinamic un tablou unidimensional de numere întregi și va implementa următoarele funcții, funcțiile vor fi organizate sub forma unui meniu:
1.	Inițializarea tabloului cu numere aleatorii;
2.	Afișarea tabloului;
3.	Eliberarea memoriei tabloului;
4.	Căutarea unui număr din tablou utilizând metoda de căutare linear search, se va afișa în cît timp se execută căutarea.
5.	Căutarea unui număr din tablou utilizând metoda de căutare binary search, se va afișa în cît timp se execută căutarea. 

2.2 Să se realizeze o analiză empirică a timpului necesar pentru a efectua 10000 de căutări într-un tablou aleator de lungimea N unde N va avea valori [100, 1000, 10000, 100000], rezultatele obținute se vor plasa în tabelul de mai jos:
N	100	1000	10000	100000
Linear search				
Binary search 				

3.1 Să se realizeze un algoritm de calcul a unui element din șirul lui Fibonaci pe baza poziției acestuia N, de exemplu:
- fib(0) == 0;
- fib(1) == 1;
- fib(5) == 3;
- fib(100) == 354224848179261915075;
- fib(500) == 139423224561697880139724382870407283950070256587697307264108962948325571622863290691557658876222521294125;
Poziția unui element N, va fi în diapazonul [50;1000000] , asta înseamnă că algoritmul trebuie să poată calcula minim fib(50) și maxim fib(1000000).
3.2 Să se realizeze o analiză empirică a timpului necesar pentru a calcula numărul lui fibonaci de pe poziția N, unde N va avea valori [50, 100, 1000, 10000, 100000, 1000000], rezultatele obținute se vor plasa în tabelul de mai jos:
N	50	100	1000	10000	100000	1000000
Fibonacci						

Barem de notare:
Problema	1.1, 1.2	1.1, 1.2, 2.1	1.1, 1.2, 2.1, 2.2	1.1, 1.2, 2.1, 2.2, 3.1,
3.2	Toate exercițiile și algoritm pentru fibonacci până la 1000	Toate exercițiile și algoritm pentru fibonacci de la 1000000

[Chiochiu Vladislav TI-244 Lab 5 SDA.docx](https://github.com/user-attachments/files/25449359/Chiochiu.Vladislav.TI-244.Lab.5.SDA.docx)


