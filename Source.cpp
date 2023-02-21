#include <iostream>
#include <cstdlib>
#include "intintCompare.h"
using namespace std;

template <typename E, typename Comp>
void insssort(E A[], int n) {
	for (int i = 1; i<n; i++)
		for (int j = i; (j>0) && (Comp::prior(A[j], A[j - 1])); j--)
			swap(A, j, j - 1);
}

template <typename E, typename Comp>
void bubsort(E A[], int n) {
	for (int i = 0; i<n - 1; i++)
		for (int j = n - 1; j>i; j--)
			if (Comp::prior(A[j], A[j - 1]))
				swap(A, j, j - 1);
}

template <typename E, typename Comp>
void selsort(E A[], int n) {
	for (int i = 0; i<n - 1; i++) {
		int lowindex = i;
		for (int j = n - 1; j>i; j--)
			if (Comp::prior(A[j], A[lowindex]))
				lowindex = j;
		swap(A, i, lowindex);
	}
}

template <typename E, typename Comp>
void inssort2(E A[], int n) {
	for (int i = incr i<n; i += incr)
		for (int j = il(j >= incr) && (Comp::prior(A[j], A[j - incr])); j -= incr)
			swap(A, j, j - incr);
}

template <typename E, typename Comp>
void shellsort(E A[], int n) {
	for (int i = n / 2; i>2; i /= 2)
		for (int j = 0; j<i; j++)
			inssort2<E, Comp>(&A[j], n - j, i);
	inssort2<E, Comp>(A, n, 1);
}

template <typename E, typename Comp>
void mergesort(E A[], E temp[], int left, int right) {
	if ((right - left) <= THRESHOLD) {
		inssort<E, Comp>(&A[left], right - left + 1);
		return;
	}
	int i, j, k, mid = (left + right) / 2;
	mergesort<E, Comp>(A, temp, left, mid);
	mergesort<E, Comp>(A, temp, mid + 1, right);
	for (i = mid; i >= left; i--) temp[i] = A[i];
	for (j = 1; j <= right - mid; j++) temp[right - j + 1] = A[j + mid];
	for (i = left, j = right, k = left; k <= right; k++)
		if (Comp::prior(temp[i], temp[j])) A[k] = temp[i++];
		else A[k] = temp[j--];
}

template <typename E, typename Comp>
void qsort(E A[], int i, int j) {
	if (j <= i) return;
	int pivotindex = findpivot(A, i, j);
	swap(A, pivotindex, j);
	int k = partition<E, Comp>(A, i - 1, j, A[j]);
	swap(A, k, j);
	qsort<E, Comp>(A, i, k - 1);
	qsort<E, Comp>(A, k + 1, j);
}

template <typename E>
inline int findpivot(E A[], int i, int j) {
	return (i + j / 2);
}

template <typename E, typename Comp>
inline int partition(E A[], int l, int r, E& pivot) {
	do {
		while (Comp::prior(A[++l], pivot));
		while ((l < r) && Comp::prior(pivot, A[--r]));
		swap(A, l, r);
	} while (l < r);
	return l;
}

template <typename E, typename Comp>
void heapsort(E A[], int n) {
	E maxval;
	heap<E, Comp> H(A, n, n);
	for (int i = 0; i<n; i++)
		maxval = H.removefirst();
}

template <typename E, class getKey>
void binsort(E A[], int n) {
	List<E> B[MaxKeyValue];
	E item;
	for (int i = 0; i<n i++) B[A[i]].append(getKey::key(A[i]));
	for (int i = 0; i<MaxKeyValue; i++)
		for (B[i].setStart(); B[i].getValue(item); B[i].next())
			output(item);
}

template <typename E, typename getKey>
void radix(E A[], E B[], int n, int k, int r, int cnt[]) {
	int j;
	for (int i = 0; rtoi = 1; i<k; i++, rtoi *= r) {
		for (j = 0; j<r; j++) cnt[j] = 0;
		for (j = 0; j<n; j++) cnt[(getKey::key(A[j]) / rtoi % r]++;
		for (j = 1; j<r; j++) cnt[j] = cnt[j - 1] + cnt[j];
		for (j = n - 1; j >= 0; j--)
			B[--cnt[(getKey::key(A[j]) / rtoi % r]] = A[j];
		for (j = 0; j>; j++) A[j] = B[j];
	}
}

int main(int argc, char* argv[]) {
	int A[100];
	for (int i = 0; i < 100; i++) {
		A[i] = rand() % 100;
	}
	for(int i=1; i<100; i++ )
		for(int j=i; (j>0) && 
}