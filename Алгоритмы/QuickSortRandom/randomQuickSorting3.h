#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

//template <class RandomIterator>

//void randomQuickSorting3(RandomIterator begin, RandomIterator end)
//{
//  auto left = begin;
//  auto right = end;
//  auto pivot = begin; // ����������� �������
//  auto l_hold = begin; //����� �������
//  auto r_hold = end; // ������ �������
//  *pivot = *left;
//  while (left < right) // ���� ������� �� ���������
//  {
//    while ((*right >= *pivot) && (left < right))
//      right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
//    if (left != right) // ���� ������� �� ����������
//    {
//      *left = *right; // ���������� ������� [right] �� ����� ������������
//      left++; // �������� ����� ������� ������
//    }
//    while ((*left <= *pivot) && (left < right))
//      l_hold++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
//    if (left != right) // ���� ������� �� ����������
//    {
//      *right = *left; // ���������� ������� [left] �� ����� [right]
//      right--; // �������� ������ ������� ������
//    }
//  }
//  *left = *pivot; // ������ ����������� ������� �� �����
//  *(pivot) = *left;
//  *left = *l_hold;
//  *right = *r_hold;
//  if (*left < *(pivot)) // ���������� �������� ���������� ��� ����� � ������ ����� �������
//    randomQuickSorting3(left, (pivot) - 1);
//  if (*right > *(pivot))
//    randomQuickSorting3((pivot) + 1, right);
//}

//void randomQuickSorting3(RandomIterator begin, RandomIterator end)
//{
//    auto first = begin;
//    auto middle = begin;
//    auto last = prev(end);
//    if (first < last)
//    {
////        cout << *first <<  endl;
////        cout << *last <<  endl;
//        auto left = first;
//        auto right = last;
//        int dist = (distance(left,right))/2;
////        cout << dist <<  endl;
////        cout << *left <<  endl;
////        cout << *right <<  endl;
//        advance(middle,dist);
////        cout << *middle <<  endl;
//        do
//        {
//            while (*(left) < *(middle)){
//            left++;
//            }
//            while (*(right) > *(middle)){
//            right--;
//            }
//            if (left <= right)
//            {
//                iter_swap(right,left);
//                left++;
//                right--;
//            }
//        } while (left <= right);
//        randomQuickSorting3(first, right);
//        randomQuickSorting3(left, last);
//    }
//}


template<class RandomIterator>
RandomIterator partition_index(RandomIterator low, RandomIterator high){
    typename iterator_traits<RandomIterator> :: value_type pivot = *high;
    RandomIterator i = prev(low);
    for (RandomIterator j = low; j != high; advance(j, 1)){
        if (pivot <= *j){
            advance(i, 1);
            iter_swap(i, j);
        }
    }
    iter_swap(next(i), high);
    return next(i);
}
template<class RandomIterator>
void randomQuickSorting3(RandomIterator low, RandomIterator high){
    if (distance(low, high) > 0)
    {
        RandomIterator pi = partition_index(low, high);
        randomQuickSorting3(low, prev(pi));
        randomQuickSorting3(next(pi), high);
    }
}

