#pragma once

void displayArray(int arr[], int sizeArr);

void fillArray(int arr[], int sizeArr);

void bruteForceSort();

void quickSort(int arr[], int left, int right);

void merge(int array[], int const left, int const mid, int const right);

void mergeSort(int array[], int const begin, int const end);

void searchMinMax(int arr[], int sizeArr, bool isSort);

void averageMinMax(int arr[], int sizeArr, bool isSort);

void countLessValue(int arr[], int sizeArr, int value);

void countMoreValue(int arr[], int sizeArr, int value);

int linearSearch(int arr[], int sizeArr, int value);

int binarySearch(int arr[], int sizeArr, int value);

void swapElement(int arr[], int sizeArr, int first, int second);

void mainSecond();