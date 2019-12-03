import java.util.Arrays;
import java.util.Random;
import java.lang.Math;

public class progamaxmin2 {
    public static void main(String[] args) {
        final int ARRAY_SIZE1 = Integer.parseInt(args[0]);
        final int module= Integer.parseInt(args[2]);
        final String wayOfSorting = args[1];
        //Ввод с кансоли кол-во эл-в для сравнения массивов
        int length1=arrayRandomSizeRestricted();
        int length2=arrayRandomSizeRestricted();
        int[] a = new int[length1];
        int[] a2 = new int[length2];
        //Ввод с консоли ко-во элементов для манипуляций с массивом
        int[] consoleArr = new int[ARRAY_SIZE1];
        randomizer(a);
        randomizer(a2);
        System.out.println("Ваш массив 1 с количеством элементов " + length1);
        printArray(a);
        System.out.println(" ");
        System.out.println("Ваш массив 2 с количеством элементов " + length2);
        printArray(a2);
        System.out.println(" ");
        //ex1 Сортировка и сравнение первых двух массивовс написанной фунц-ей
        boolean compare1 = compareArraysTakingOrder(a, a2);
        System.out.println("Ваши массивы равны по элементам " + compare1);
        boolean compare2 = compareArraysWithoutOrder(a, a2);
        System.out.println("Ваши массивы равны по элементам и их местам " + compare2);
        System.out.println(" ");
        //ex1**Со стандартной библиотекой
        System.out.println("Сравнение массива 1 и массива 2 в стандартной библиотеке");
        compareArraysWithStandartBiblio(a, a2);
        System.out.println(" ");
        maxArrayLength(a, a2);
        ////ex2 Максимальный массив из двух

        System.out.println(" ");
        //ex3 "Консольный массив 1"
        System.out.println("Введите кол-во эл-ов в консоль");
        randomizer(consoleArr);
        System.out.println(" ");
        System.out.println("Ваш массив 3 с количествои эл-в  " + ARRAY_SIZE1);
        printArray(consoleArr);
        System.out.println(" ");
        callBubbleSort2Descending(consoleArr);
        System.out.println(" ");
        //ex4"Консольный массив c методом сортировки
        System.out.println("Введите в консоль один из способов сортировки в консоль UpBubbleSort DownBubbleSort UpSelectionSort DownSelectionSort UpDownBubble UpDownSelection");
        System.out.println("Введите модуль в консоль");
        System.out.println(" ");
        rnd(consoleArr,module);
        wayOfSortingFunc(consoleArr, wayOfSorting);
        //ex5 Сравнение быстродействия сортировок
        long[] timeComparing = new long[5];
        int[] largeArr = new int[10000];
        randomizer(largeArr);
        compareSorts(timeComparing,largeArr);
        System.out.println(" ");
        //ex6 упражнения по матанализу и экономике
        int n=Integer.parseInt(args[3]);
        int x=Integer.parseInt(args[4]);
        System.out.println("Введите в консоль 4 и 5 параметр для факторизации, вычисления сочетаний и размещений");
        System.out.println(n+"!= "+fact(n));
        combinations(n,x);
        permutations(n,x);
        double i=(double)x;
        sin(n,x);
        sumOfSequence(n);
    }
    public static long callBubbleSort1Ascending(int[] arr) {
        long before = System.currentTimeMillis();
        bubbleSort1(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        boolean b = check1(arr);
        printCheck(b);
        System.out.println("Отсортированнный по возрастанию массив ");
        printArray(arr);
        System.out.println("Время исполнения Bubble Sort по возрастанию = " + time + " мс.");
        System.out.println(" ");
        return time;
    }
    public static long callBubbleSort2Descending(int[] arr) {
        long before = System.currentTimeMillis();
        reverse(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        boolean b = check2(arr);
        printCheck(b);
        System.out.println("Отсортированнный по убыванию массив ");
        printArray(arr);
        System.out.println("Время исполнения Bubble Sort по убыванию = " + time + " мс.");
        System.out.println(" ");
        return time;
    }
    public static long callSelectionSortDescending(int[] arr) {
        long before = System.currentTimeMillis();
        reverse(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        boolean b = check1(arr);
        printCheck(b);
        System.out.println("Отсортированнный по убыванию массив ");
        printArray(arr);
        System.out.println("Время исполнения Selection Sort по убыванию = " + time + " мс.");
        System.out.println(" ");
        return time;
    }
    public static long callSelectionSortAscending(int[] arr) {
        long before = System.currentTimeMillis();
        selectionSort(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        boolean b = check2(arr);
        printCheck(b);
        System.out.println("Отсортированнный по возрастанию массив ");
        printArray(arr);
        System.out.println("Время исполнения Selection Sort по возрастанию = " + time + " мс.");
        System.out.println(" ");
        return time;
    }
    public static long callBiblioSort(int[] arr) {
        long before = System.currentTimeMillis();
        Arrays.sort(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        System.out.println("Время исполнения Quick Sort = " + time + " мс.");
        System.out.println(" ");
        return time;
    }
    public static void randomizer(int[] arr) {
        Random r = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = r.nextInt();
        }
    }
    public static void rnd (int []arr,int module){
        for(int i=0;i<arr.length;i++) {
            arr[i] = (int)(Math.random() * (2*module + 1)-module);
        }
    }
    public static int arrayRandomSizeRestricted(){
        return 1 + (int) (Math.random() * (400+ 1));
    }
    public static void printArray(int[] arr) {
        if (arr.length <= 10) {
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + " ");
            }
        } else {
            for (int i = 0; i < 10; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            if (arr.length > 20) {
                System.out.println("...");
            }
            for (int i = arr.length - 1; i >= arr.length - 10; i--) {
                System.out.print(arr[i] + " ");
            }
        }
        System.out.println(" ");
    }
    public static void compareArraysWithStandartBiblio(int[]a1,int[]a2) {
        boolean areEqual = Arrays.equals(a1, a2);
        if (areEqual) {
            System.out.println("Массивы равны");
        } else {
            System.out.println("Массивы не равны");
        }
    }
    public static void maxArrayLength(int []a1,int[]a2) {
        maxArraySumElements(a1,a2);
        if (a1.length > a2.length) {
            System.out.println("По количеству элементов максимальный массив 1");
            printArray(a1);
        }
        if (a1.length < a2.length) {
            System.out.println("По количеству элементов максимальный массив 2 ");
            printArray(a2);
        }
    }
    public static void maxArraySumElements(int []a1,int[]a2) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < a1.length; i++) {
            sum1 = sum1 + a1[i];
        }
        for (int i = 0; i < a2.length; i++) {
            sum2 = sum2 + a2[i];
        }
        if (a1.length == a2.length) {
            if (sum1 > sum2) {
                System.out.println("По значению элементов максимальный массив 1");
                printArray(a1);
            } else {
                System.out.println("По значению элементов максимальный массив 2");
                printArray(a2);
            }
        } else {
            maxArraySumElementsWithoutLen(sum1, sum2,a1,a2);
        }
    }
    public static void maxArraySumElementsWithoutLen(int sum1,int sum2,int[]a1,int[]a2){
        if (sum1 > sum2) {
            System.out.println("По значению элементов максимальный массив 1");
            printArray(a1);
        } else {
            System.out.println("По значению элементов максимальный массив 2");
            printArray(a2);
        }
    }
    public static void bubbleSort1(int[] a) {
        boolean isSorted = false;
        while (!isSorted) {
            isSorted = true;
            for (int i = 0; i < a.length - 1; i++) {
                if (a[i] > a[i + 1]) {
                    isSorted = false;
                    int changer = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = changer;
                }
            }
        }
    }
    public static void reverse(int[] a) {
       int tmp;
       for(int i=0;i<a.length;i++){
           tmp=a[a.length-i-1];
           a[a.length-i-1]=a[i];
           a[i]=tmp;
                }
    }
    public static boolean check1(int[] a) {
        boolean check = true;
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] < a[i + i]) {
                return check;
            }
        }
        return !check;
    }
    public static boolean check2(int[] a) {
        boolean check = true;
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + i]) {
                return check;
            }
        }
        return !check;
    }
    public static void printCheck(boolean a) {
        if (a = true) {
            System.out.println("Массив отсортирован");
        } else {
            System.out.println("Массив не отсортирован");
        }
    }
    public static void selectionSortAscending(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int min = a[i];
            int minIndex = i;
            for (int j = i + 1; j < a.length; j++) {
                if (a[j] > min) {
                    min = a[j];
                    minIndex = j;
                }
            }
            int changer = a[i];
            a[i] = min;
            a[minIndex] = changer;
        }
    }
    public static boolean compareArraysTakingOrder(int[]a,int[]a2){
        if(a.length!=a2.length){
            return false;
        } else {
            for(int i=0;i<a.length;i++) {
                if (a[i] != a2[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    public static boolean compareArraysWithoutOrder(int[]a,int[]a2) {
        if (a.length != a2.length) {
            return false;
        }
        bubbleSort1(a);
        bubbleSort1(a2);
        for (int i = 0; i < a.length; i++) {
            if (a[i] != a2[i]) {
                return false;
            }
        }
        return true;
    }
    public static void wayOfSortingFunc(int[]a,String wayOfSorting){
        if(wayOfSorting.equals("BubbleSortAscending")){
            callBubbleSort1Ascending(a);
        }
        if(wayOfSorting.equals("BubbleSortDescending")){
            callBubbleSort2Descending(a);
        }
        if(wayOfSorting.equals("SelectionSortAscending")){
            callSelectionSortAscending(a);
        }
        if(wayOfSorting.equals("SelectionSortDescending")){
            callSelectionSortDescending(a);
        }
        if(wayOfSorting.equals("BubbleAscendingDescending")){
            callBubbleSort1Ascending(a);
            callBubbleSort2Descending(a);
        }
        if(wayOfSorting.equals("SelectionAscendingDescending")){
            callSelectionSortAscending(a);
            callSelectionSortDescending(a);
        }
    }
    public static void compareSorts(long[] timeComparing,int[] arr){
        timeComparing[0]=callBubbleSort1Ascending(arr);
        timeComparing[1]=callBubbleSort2Descending(arr);
        timeComparing[2]=callSelectionSortAscending(arr);
        timeComparing[3]=callSelectionSortDescending(arr);
        timeComparing[4]=callBiblioSort(arr);
        long [] copy=new long[timeComparing.length];
        for (int i = 0; i < timeComparing.length; i++) {
            copy[i] = timeComparing[i];
        }
        Arrays.sort(timeComparing);
        String[]sortTypesOfNames={"Bubble Sort Ascending","Bubble Sort Descending","Selection Sort Ascending","Selection Sort Descending","Quick Sort"};
        int fastest=0;
        int slowest=0;
        int second=0;
        int third=0;
        int fourth=0;
        for (int i = 0; i < 5; i++) {
            if (timeComparing[0] == copy[i]) {
                fastest = i;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (timeComparing[1] == copy[i]) {
                second = i;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (timeComparing[2] == copy[i]) {
                third = i;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (timeComparing[3] == copy[i]) {
                fourth = i;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (timeComparing[4] == copy[i]) {
                slowest = i;
                break;
            }
        }
        System.out.println("Самая быстрая сортировка это " + sortTypesOfNames[fastest]);
        System.out.println("Вторая по быстроте сортировка  это  " + sortTypesOfNames[second]);
        System.out.println("Третья по быстроте сортировка это " + sortTypesOfNames[third]);
        System.out.println("Четвертая по быстроте сортировка это " + sortTypesOfNames[fourth]);
        System.out.println("Самая медленная сортировка " + sortTypesOfNames[slowest]);
    }
    public static void copingArray(int[] a, int[] copy) {
        for (int i = 0; i < a.length; i++)
            copy[i] = a[i];
    }
    public static int fact(int n){
        int result=1;
        for (int i = 1; i <=n; i ++){
            result= result*i;
        }
        return result;
    }
    public static void combinations(int n, int k){
    if(k>n){
        System.out.println("Ошибка, введите k<=n");
    }
    int result = 0;
    do{
        result+= (fact(n)/(fact(k)*fact(n-k)));
        k++;
    }while(n!=k);
    System.out.println("Кол-во сочетаний равно "+result);
    }
    public static void permutations(int n,int k) {
        if (k > n) {
            System.out.println("Ошибка, введите k<=n");
        }
        int result = 0;
        do {
            result += (fact(n) / (fact(n - k)));
            k++;
        } while (n != k);
        System.out.println("Кол-во размещений равно " + result);
    }
    public static void sin(int n,int x) {
        int powOf2 = 1;
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            powOf2 *= 2;
            sum += Math.sin(i * x) / powOf2;
        }
        System.out.println("Сумма ряда (sin ix)/2^i " + sum);
    }
    public static void sumOfSequence(int n){
        int sum=0;
        for(int i = 1; i <= n; i++ ){
            sum=sum+((i^n)/6);
        }
        System.out.println("Сумма выражения (i^n)/6 "+sum);
    }
}
