#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <cmath>
using namespace std;

template <class T>

//void randomQuickSorting2(vector <T> &arr, int left, int right)
//{
//  T pivot; // ����������� �������
//  int l_hold = left; //����� �������
//  int r_hold = right; // ������ �������
//  pivot = arr[left];
//  while (left < right) // ���� ������� �� ���������
//  {
//    while ((arr[right] >= pivot) && (left < right))
//      right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
//    if (left != right) // ���� ������� �� ����������
//    {
//      arr[left] = arr[right]; // ���������� ������� [right] �� ����� ������������
//      left++; // �������� ����� ������� ������
//    }
//    while ((arr[left] <= pivot) && (left < right))
//      left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
//    if (left != right) // ���� ������� �� ����������
//    {
//      arr[right] = arr[left]; // ���������� ������� [left] �� ����� [right]
//      right--; // �������� ������ ������� ������
//    }
//  }
//  arr[left] = pivot; // ������ ����������� ������� �� �����
//  pivot.id = left;
//  left = l_hold;
//  right = r_hold;
//  if (left < pivot.id) // ���������� �������� ���������� ��� ����� � ������ ����� �������
//    randomQuickSorting2(arr, left, pivot.id - 1);
//  if (right > pivot.id)
//    randomQuickSorting2(arr, pivot.id + 1, right);
//}

void randomQuickSorting2(vector <T> &arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last;
        T middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                T tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        randomQuickSorting2(arr, first, right);
        randomQuickSorting2(arr, left, last);
    }
}

//int partition_index(vector<T> &a, int low, int high){
//    T pivot = a.at(high);
//    int i = (low - 1);
//    for (int j = low; j <= high - 1; j++){
//        if (a.at(j) <= pivot){
//            i++;
//            swap(a.at(i), a.at(j));
//        }
//    }
//    swap(a.at(i + 1), a.at(high));
//    return (i + 1);
//}
//template<class T>
//void randomQuickSorting2(vector<T> &a, int low, int high){
//    if (low < high){
//        int pi = partition_index(a, low, high);
//        randomQuickSorting2(a, low, pi - 1);
//        randomQuickSorting2(a, pi + 1, high);
//    }
//}
