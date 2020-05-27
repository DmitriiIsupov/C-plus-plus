#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

//void randomQuickSorting1(vector <int> &arr, int left, int right)
//{
//  int pivot; // ����������� �������
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
//  pivot = left;
//  left = l_hold;
//  right = r_hold;
//  if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
//    randomQuickSorting1(arr, left, pivot - 1);
//  if (right > pivot)
//    randomQuickSorting1(arr, pivot + 1, right);
//}

void randomQuickSorting1(vector <int> &arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        randomQuickSorting1(arr, first, right);
        randomQuickSorting1(arr, left, last);
    }
}
