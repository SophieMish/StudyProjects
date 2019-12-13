import java.util.Arrays;
import java.util.Random;
import java.lang.Math;
public class Main {
    public static void main(String[] args) {
        //#1Минимум и максимум двумерного массива,их индексы
        final int lenIForArr = 4;
        final int lenJForArr = 3;
        int[][] arr = {{2, 4, 7}, {2, 9, 60}, {2, 5, 10}, {4, 3, 90}};
        boolean[][] indexesBoolean = new boolean[lenIForArr][lenJForArr];
        System.out.print("Ваш первый массив c кол-вом подмассивов " + lenIForArr + " ,кол-во элементов в них " + lenJForArr);
        System.out.println(" ");
        printArray(arr);
        System.out.println(" ");
        int min = findMin(arr, lenIForArr, lenJForArr);
        int max = findMax(arr, lenIForArr, lenJForArr);
        System.out.println("Минимум равен " + min);
        getIndexes(arr, indexesBoolean, min);
        System.out.println("Максимум равен " + max);
        getIndexes(arr, indexesBoolean, max);
        System.out.println(" ");
        //#2,3 Массив из консоли
        //1 число используется как кол-во подмассивов
        // 2 число используется как ко-во элементов в подмассивах
        final int ARRAY_SIZEi = Integer.parseInt(args[0]);
        final int ARRAY_SIZEj = Integer.parseInt(args[1]);
        int[][] arr1 = new int[ARRAY_SIZEi][ARRAY_SIZEj];
        randomizer(arr1);
        System.out.println("Ваш второй массив случайных чисел, кол-вом подмассивов " + ARRAY_SIZEi + ",кол-во элементов в них " + ARRAY_SIZEj);
        System.out.println(" ");
        printArray(arr1);
        System.out.println(" ");
        callSortAscending(arr1);
        System.out.println(" ");
        //3 значение- это способ сортировки AscendingSort DescendingSort AscendingDescendingSort
        //4 число модуль-ограничение
        final String wayOfSorting = args[2];
        System.out.println("Введите в консоль один из способов сортировки в консоль AscendingSort DescendingSort AscendingDescendingSort");
        System.out.println("Введите модуль в консоль");
        System.out.println(" ");
        System.out.print("Ваш третий массив с кол-вом подмассивов " + ARRAY_SIZEi + " ,кол-во элементов в них " + ARRAY_SIZEi);
        System.out.println(" ");
        int[][] consoleArr = new int[ARRAY_SIZEi][ARRAY_SIZEi];
        final int module1 = Integer.parseInt(args[3]);
        rnd(consoleArr, module1);
        wayOfSortingFunc(consoleArr, wayOfSorting);
        System.out.println(" ");
        //№4 Работа со стеком
        //5 число из консоли используется для рандомной выборки чисел для создания размера стека
        //6 число из консоли используется для ограничения кол-ва "случайных" стеков
        final int module2 = Integer.parseInt(args[4]);
        final int n = Integer.parseInt(args[5]);
        int size = rndForNum(module2);
        int slice = rndForNum(size);//вырезаемый кусок
        workWithStack1(module2, n);
        //№5 перестановки
        //Модуль 2 используется в перестановках как основа последовательности
        int[] arrOfPermutations = new int[module2];
        int[] changedArrOfPermutations = new int[arrOfPermutations.length];
        chages(arrOfPermutations, changedArrOfPermutations, module2);
        System.out.println(" ");
        System.out.println("Первый массив с перестановками ");
        printArray1D(arrOfPermutations);
        System.out.println(" ");
        System.out.println("Второй массив с перестановками ");
        printArray1D(changedArrOfPermutations);
        cycles(arrOfPermutations, changedArrOfPermutations, true);
    }

    public static int firstNotNull(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                return i;
            }
        }
        return 0;
    }

    public static boolean allNull(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }

    public static boolean anyNull(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                return true;
            }
        }
        return false;
    }

    public static void copingArray(int[][] a, int[][] copy, int size1, int size2) {
        for (int i = 0; i < size1 - 1; i++) {
            for (int j = 0; j < size2 - 1; j++) {
                copy[i][j] = a[i][j];
            }
        }
    }

    public static void coping2DArrayToArray(int[][] a, int[] copy, int size1, int size2) {
        int ctr = 0;
        for (int i = 0; i < size1 - 1; i++) {
            for (int j = 0; j < size2 - 1; j++) {
                copy[ctr++] = a[i][j];
            }
        }
    }

    public static void printArray(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + "  ");
            }
            System.out.println(" ");
        }
    }

    public static void printArray1D(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + "  ");
        }
        System.out.println(" ");
    }

    public static void rnd(int[][] arr, int module) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                arr[i][j] = (int) (Math.random() * (2 * module + 1) - module);
            }
        }
    }

    public static int rndForNum(int module) {
        return (int) (1 + Math.random() * module);
    }

    public static void randomizer(int[][] arr) {
        Random r = new Random();
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                arr[i][j] = r.nextInt();
            }
        }
    }

    public static void callSortAscending(int[][] arr) {
        Sortings sorter = new Sortings();
        long before = System.currentTimeMillis();
        sorter.bubbleSortAscending(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        System.out.println("Отсортированнный по убыванию массив ");
        printArray(arr);
        System.out.println("Время исполнения сортировки по возрастанию = " + time + " мс.");
        System.out.println(" ");

    }

    public static void callSortDescending(int[][] arr) {
        Sortings sorter = new Sortings();
        long before = System.currentTimeMillis();
        sorter.bubbleSortDescending(arr);
        long after = System.currentTimeMillis();
        long time = after - before;
        System.out.println("Отсортированнный по убыванию массив ");
        printArray(arr);
        System.out.println("Время исполнения сортировки по убыванию = " + time + " мс.");
        System.out.println(" ");
    }

    public static void getIndexes(int[][] a, boolean[][] index, int value) {
        for (int i = 0; i < index.length; i++) {
            for (int k = 0; k < index[0].length; k++) {
                index[i][k] = false;
            }
        }
        for (int i = 0; i < index.length; i++) {
            for (int k = 0; k < index[0].length; k++) {
                if (a[i][k] == value) {
                    index[i][k] = true;
                }
            }
        }
        System.out.println("Индексы элементов " + value + ": ");
        for (int i = 0; i < index.length; i++) {
            for (int k = 0; k < index[0].length; k++) {
                if (index[i][k]) {
                    System.out.println("[" + i + "]" + "[" + k + "]");
                }
            }
        }
        System.out.println();
    }

    public static int getIndexesForPermutations(int[] arr, int value) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return 0;
    }

    public static int findMax(int[][] arr, int len, int len2) {
        int max = arr[0][0];
        for (int i = 0; i < len; i++) {
            for (int k = 0; k < len2; k++) {
                if (max < arr[i][k]) {
                    max = arr[i][k];
                }
            }
        }
        return max;
    }

    public static int findMin(int[][] arr, int len, int len2) {
        int min = arr[0][0];
        for (int i = 0; i < len; i++) {
            for (int k = 0; k < len2; k++) {
                if (min > arr[i][k]) {
                    min = arr[i][k];
                }
            }
        }
        return min;
    }

    public static void wayOfSortingFunc(int[][] a, String wayOfSorting) {
        if (wayOfSorting.equals("AscendingSort")) {
            callSortAscending(a);
        }
        if (wayOfSorting.equals("DescendingSort")) {
            callSortDescending(a);
        } else {
            callSortAscending(a);
            callSortDescending(a);
        }
    }

    public static int arrayRandomSizeRestricted() {
        return 1 + (int) (Math.random() * (400 + 1));
    }

    public static void workWithStack1(int module, int n) {
        int size = rndForNum(module);
        int slice = rndForNum(size);
        Stack myStack = new Stack(size);
        myStack.pushStackWihRandomNums();
        System.out.println("Ваш стек ");
        printArray1D(myStack.stackArray);
        int[] an = new int[slice];
        myStack.popSliced(an, slice);
        if (n > 0) {
            workWithStack1(module, n - 1);
        } else {
            System.out.print("Стеков больше нет");
        }
    }

    public static void workWithStack2(int size, int slice, int module) {
        Stack myStack = new Stack(size);
        myStack.pushStackWihRandomNums();
        printArray1D(myStack.stackArray);
        //slice= rndForNum(size);
        int[] an = new int[slice];
        myStack.popSliced(an, slice);
        for (int i = 0; i < module; i++) {
            workWithStack2(size, slice, module);
        }
    }

    public static int cycles(int[] arr, int[] arrChanged, boolean pr) {
        if (pr) {
            int k = 0;
            int counter = 0;
            System.out.print("Цепочки: ");
            while (!(allNull(arr))) {
                int firstNum = arr[k];
                arr[k] = 0;
                while (arrChanged[k] != firstNum) {
                    System.out.print((k + 1) + " - ");
                    k = getIndexesForPermutations(arr, arrChanged[k]);
                    arr[k] = 0;
                }
                System.out.println((k + 1));
                k = firstNotNull(arr);
                counter++;
            }
            System.out.println("Колчество циклов= " + counter);
            return counter;
        } else {
            int k = 0;
            int counter = 0;
            while (!(allNull(arr))) {
                int firstNum = arr[k];
                arr[k] = 0;
                while (arrChanged[k] != firstNum) {
                    System.out.print((k + 1) + " - ");
                    k = getIndexesForPermutations(arr, arrChanged[k]);
                    arr[k] = 0;
                }
                k = firstNotNull(arr);
                counter++;
            }
            return counter;
        }
    }

    public static void chages(int[] arr1, int[] arrChange, int SIZE) {
        Random rnd=new Random();
        boolean check = true;
        int counter = 0;
        for (int i = 0; i < SIZE; i++) {
            arr1[i] = i + 1;
        } do {
            int i =rnd.nextInt(SIZE);
            if (arr1[i] != 0) {
                arrChange[counter++] = arr1[i];
                arr1[i] = 0;
            }
        }
        while (anyNull(arrChange));
        for (int i = 0; i < SIZE; i++) {
            arr1[i] = i + 1;
        }
    }
}



