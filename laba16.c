#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 1000
int arr[NUM_ELEMENTS];
int n = 10;
int j = 0;
int mn = 1000000;
int c = 0;
int index;
void printElements() {
	printf("<  "); 
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}  
	printf(" >\n");
}
void keyboardInput() {
	printf("n =");
	scanf_s("%d", &n);
	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]); 

	}

}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}

}
int findMin() {
	int min = arr[0]; 
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i]; 

		}
	}
	return min;

} 
int more10() {
	int ch = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > 10) {
			ch++;
		}
	} 
	return ch; 
}
int even() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			return i;
		}
	
	} 
	
} 
void nom3() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) c = i;
	}
	for (int i = 0; i < n; i++) {
		if (i == c) arr[i] *= 2;
	}
}
int findindexmin() {
        int mn = 10000;
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mn) {
				mn = arr[i];
				c = i;
			}
		}
		return c;

	}
void deleteElements(int index){
	arr[index] = 0;
	for (int i = index; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
} 
void vstavka(int index, int value) {
	for (int i = n; i > index; --i) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[index] = value;
}
void main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	int item;
	do {
		printf("\n"); 
		printf("--------------------------------------------"); 
		printf("Содержимое массива: "); 
		printElements(); 
		printf("Выбирите нужную вам оперецаию:\n"); 
		printf("1:Вывести с клавиатуры массив\n"); 
		printf("2: х10 для всех нечетных элементов\n"); 
		printf("3:Найти минимальный элемент\n"); 
		printf("4: Сколько больше 10?\n");
		printf("5: Последний четный увеличить в 2 раза\n");
		printf("6:Сколько четных левее минимальногo \n ");
		printf("Лаба 17\n");
		printf("7:Удалить заданый элемент\n");
		printf("8: Вставить новый элемент в новое место\n");
		printf("9: Удалить минимальный элемент\n");
		printf("\n"); 
		printf("0: Выйти из программы\n"); 
		printf("Введеная операция:"); 
		scanf_s("%d", &item); 
		switch (item) {
		case 1:
			keyboardInput();
			break;
		case 2:
			oddsX10();
			break;
		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);

		}
		break;
		case 4:
			printf(" Ответ: %d", more10());
			break;
		case 5:
			nom3();
			printElements();
			break;
		case 6:
		{
			int mn = findindexmin();
			int c = 0;
			for (int i = mn; i < n; i++) {
				if (arr[i] % 2 == 0) c++;
			}
			printf("Левее минимального %d четных\n", c);
		}
		case 7:
		{
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElements(index);

		}
		break;
		case 8:
		{
			printf("Перед каким элементом нужно вставить новый? Индекс =");
			int index;
			scanf_s("%d", &index);
			printf("какое значение надо вставить =");
			int value;
			scanf_s("%d", &value);
			vstavka(index, value);

		}
		break;
		case 9:
		{
			int min = findindexmin();
			deleteElements(min);
		}
		break;
		case 10:
		{
			int indexMin = findindexmin(); 
			printf("Индекс минимального элемента = %d\n", indexMin); 
			vstavka(indexMin, 0);
		}
		break;
		
		
		} 


	
		} while (item != 0);
}
