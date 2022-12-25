//
// Created by FIX on 2022/5/6.
//

//冒泡排序
# include <stdio.h>
//int bubble(int a[],int n)
//	int i ,temp;
//	for (i=0;i<n-1;i++){      //只需要比较n-1次，只需要放对n-1个大数即可
//		if (a[i]>a[i+1]){           //大的放在后面
//			temp=a[i];
//			a[i]=a[i+1];
//			a[i+1]=temp;
//		}
//	}
//}
//
//int bubblesort(int a[],int n){
//	int i=0;
//	for (i=n;i>=1;i--){
//		bubble(a,i);
//	}
//}
//
//int main(){
//	int a[]={1,4,9,0,8};
//	bubblesort(a,5);
//	int i;
//	for (i=0;i<5;i++){
//		printf("%d\n",a[i]);
//	}
//	return 0;
//}


// 选择排序
//int findmaxpos(int a[],int n){
//	int max=a[0];
//	int i,pos;    //找出最大的那个数的下标
//	for (i=0;i<n;i++){
//		if (a[i]>max){
//			max=a[i];
//			pos=i;
//		}
//	}
//	return pos;
//}
//
//int selectionsort(int a[],int n){
//	while (n>1){
//		int pos =findmaxpos(a,n);
//		int temp=a[pos];           //通过交换把最大的数放到最后
//		a[pos]=a[n-1];
//		a[n-1]=temp;
//		n--;
//	}
//}
//int main(){
//	int a[]={1,4,9,0,8};
//	selectionsort(a,5);
//	int i;
//for(i=0;i<5;i++){
//	printf("%d\n",a[i]);
//}
//}

// 插入排序
//int insert(int a[], int n) {
//    int key = a[n];
//    int i = n;
//    while (a[i - 1] > key) {
//        a[i] = a[i - 1];
//        i--;
////		if(i==0) {
////			break;            //这个地方灯神是写了，但是如果数组里有0，就会有问题
////		}
//        a[i] = key;
//    }
//}
//
//int insertsort(int a[], int n) {
//    int i;
//    for (i = 1; i < n; i++) {
//        insert(a, i);
//    }
//}
//
//int main() {
//    int a[] = {1, 4, 9, 0, 8};
//    insertsort(a, 5);
//    int i;
//    for (i = 0; i < 5; i++) {
//        printf("%d\n", a[i]);
//
//    }
////    printf("%d", a[0]);
//}


//归并排序
//#include<stdio.h>
//
//#define N 10
//
//void merge(int a[], int l, int m, int r)//l为前半段开始位置m为前半段终止和后半段开始r为后半段开始位置
//
//{
//
//    int left_size = m - l;
//
//    int right_size = r - m + 1;
//
//    int a1[left_size];
//
//    int a2[right_size];
//
//
//    int i, j, k;
//
////前后两段有序序列分别放入两个数组
//
//    for (i = l; i < m; i++)
//
//        a1[i - l] = a[i];
//
//
//    for (i = m; i <= r; i++)
//
//        a2[i - m] = a[i];
//
////在两个数组中找最小的先放入原数组a中当一个数组遍历结束则停止
//
//    i = 0;
//    j = 0;
//    k = l;
//
//    while (i < left_size && j < right_size) {
//
//        if (a1[i] < a2[j])
//
//            a[k++] = a1[i++];
//
//        else
//
//            a[k++] = a2[j++];
//
//    }
//
////另一个数组还未遍历完此时该数组中全部放入a中
//
////下面两个循环只会执行一个
//
//    while (i < left_size)
//
//        a[k++] = a1[i++];
//
//    while (j < right_size)
//
//        a[k++] = a2[j++];
//
//
//}
//
//
//void mergesort(int a[], int low, int high) {
//
//    int m;
//
//    if (low < high) {
//
//        m = (low + high) / 2;
//
//        mergesort(a, low, m);//分治
//
//        mergesort(a, m + 1, high);
//
//        merge(a, low, m + 1, high);//注意这里是加一
//
//
//    }
//
//}
//
//
//int main() {
//
//    int a[] = {2, 9, 1, 8, 6, 7, 4, 3, 5, 10}, i;
//
//    mergesort(a, 0, N - 1);
//
//    for (i = 0; i < N; i++)
//
//        printf("%d", a[i]);
//
//
//}

//堆排序

#include <stdio.h>


void swop(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void heapify(int tree[], int n, int i) {
    if (i >= n) { return; }
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;
    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }
    if (max != i) {
        swop(tree, max, i);
        heapify(tree, n, max);
    }
}

void build_heap(int tree[], int n) {
    int last = n - 1;
    int parent = (last - 1) / 2;
    int i;
    for (i = parent; i >= 0; i--) {
        heapify(tree, n, i);
    }
}

void head_sort(int tree[], int n) {
    build_heap(tree, n);
    for (int i = n - 1; i >= 0; i--) {
        swop(tree, i, 0);
        heapify(tree, i, 0);
    }
}

int main() {
    int tree[] = {10, 4, 3, 5, 1, 2};
    int n = 6;
    int i;
    head_sort(tree, n);

    for (i = 0; i < n; i++) {
        printf("%d\n", tree[i]);
    }
    return 0;
}


