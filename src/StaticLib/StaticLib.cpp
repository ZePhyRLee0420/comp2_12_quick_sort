#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
    if (begin == NULL || end == NULL)
        return false;

    if (end < begin)
        return false;

    if (end - begin <= 1)
        return true;

    item* left = begin;
    item* right = (item*)end - 1;

    item pivot = begin[(end - begin) / 2];

    while (left <= right)
    {
        while (left->key < pivot.key)
            left++;

        while (right->key > pivot.key)
            right--;

        if (left <= right)
        {
            item tmp = *left;
            *left = *right;
            *right = tmp;

            left++;
            right--;
        }
    }

    if (begin < right + 1)
        quick_sort(begin, right + 1);
    if (left < end)
        quick_sort(left, end);

    return true;
}
