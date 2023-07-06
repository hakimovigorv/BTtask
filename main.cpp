#include <iostream>
#include <cmath>
#include <algorithm>

struct part
{
    double *start;
    int size;
    int idx;
};

void Merge(double* A, int p, int q, int r){
    int number_of_parts = 2;
    struct part parts[number_of_parts];
    int n = r - p;
    double A_copy[n];
    for (int i = 0; i<n; i++){
        A_copy[i] = A[p+i];
    }

    parts[0].start = A_copy;
    parts[0].size = q-p;
    parts[0].idx = 0;
    parts[1].start = A_copy + q - p;
    parts[1].size = r-q;
    parts[1].idx = 0;

    double min;
    int min_part_idx = 0;

    for (int i = 0; i<n; i++){
        min = INFINITY;
        for (int j = 0; j < number_of_parts; j++)
        {
            if (parts[j].idx >= parts[j].size)
                continue;
            if (min > *(parts[j].start + parts[j].idx))
            {
                min = *(parts[j].start + parts[j].idx);
                min_part_idx = j;
            }
        }
        A[p+i] = min;
        parts[min_part_idx].idx++;
    }
}


int main() {
    int n = 10;
    int p = 2;
    int r = 7;

    double A[n];

    for (int i = 0; i<n; i++){
        A[i] = n - i - 1;
    }

    std::cout << "initial array" << std::endl;
    for (int i = 0; i<n; i++){
        std::cout << A[i] << std::endl;
    }

    if (p < r){
        int q = (int)((p + r) / 2);
        std::sort(A + p, A + q);
        std::sort(A + q, A + r);

        std::cout << "array after sort" << std::endl;
        for (int i = 0; i<n; i++){
            std::cout << A[i] << std::endl;
        }
        Merge(A, p, q, r);
    }

    std::cout << "array after merge" << std::endl;
    for (int i = 0; i<n; i++){
        std::cout << A[i] << std::endl;
    }

    return 0;
}
