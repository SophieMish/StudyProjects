import java.util.Arrays;
import java.util.Collections;

public class Stack extends Main {
    private int mSize;
    public int[] stackArray;
    private int top;
    private int[] index;

    public Stack(int s) {
        this.mSize = s;
        stackArray = new int[mSize];
        top = -1;
    }

    public void push(int item) {
        stackArray[++top] = item;
    }

    public int pop(){
        return stackArray[top--];
    }

    public void popSliced(int []an,int slice) {
        System.out.println("Срез равен "+ slice);
        int k=stackArray.length-slice;
        int j=0;
        if (slice == 0) {
            System.out.print("Случайное число членов для подпоследовательности = 0, ведите другой модуль или запустите программу еще раз");
        } else {
            System.out.print("Извлеченная подпоследовательность ");
            for (int i = stackArray.length; i > k; i--) {
                an[j++] = pop();
            }
        }
        printArray1D(an);
    }
    public int peek() {
        return stackArray[top];
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    public boolean isFull() {
        return (top == mSize - 1);
    }

    public void printStack() {
        System.out.println("Ваш стек c длиной "+ mSize);
        if (mSize <= 10) {
            for (int i = 0; i < mSize; i++) {
                System.out.print(stackArray[i] + " ");
            }
        } else {
            for (int i = 0; i < 10; i++) {
                System.out.print(stackArray[i] + " ");
            }
            System.out.println();
            if (mSize > 20) {
                System.out.println("...");
            }
            for (int i = mSize - 1; i >= mSize - 10; i--) {
                System.out.print(stackArray[i] + " ");
            }
        }
        System.out.println(" ");
    }
    public int indexesOfStackElements(int[] a, int value) {
        int point = 0;
        for (int i = 0; i < index.length; i++)
            if (value == a[i]) {
                point++;
                index[point] = i + 1;
            }
        return index[point];
    }

    public void sortStackAscending() {
        Arrays.sort(stackArray);
    }
    public void pushStackWihRandomNums(){
        for(int i=0;i<mSize;i++){
            push(arrayRandomSizeRestricted());
        }
    }
    public void sorStackDesending() {
        Collections.reverse(Arrays.asList(stackArray));
    }
}



