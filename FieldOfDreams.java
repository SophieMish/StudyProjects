import java.util.Scanner;
import java.util.Arrays;
//the program uses arguments,please enter it in Run->Edit configurations->Program arguments or cmd
//1- your word,2 - hint #1("how your text should look like"),3-hint #2, 4-hint #4
// the word "perceptron" is defaulted in program arguments + hints
public class FieldOfDreams {
    public static void main(String[] args) {
        String word=args[0];
        String hint1=args[1];
        String hint2=args[2];
        String hint3=args[3];
        char[] wordToArray=word.toCharArray();
        char[] emptyArray=new char[wordToArray.length];
        Arrays.fill(emptyArray, '_'); 
        System.out.println("There are "+wordToArray.length+" letters in the word");
        System.out.println("Hint #1 "+hint1);
        System.out.println("Hint #2 "+hint2);
        System.out.println("Hint #3 "+hint3);
        isArrayHaveSome_(wordToArray,emptyArray);
        DrawWin text=new DrawWin();
        text.paint();
    }
    public static void isArrayHaveSome_(char[]wordToArray,char[]emptyArray) {
        char scan;
        printArray(emptyArray);
        for (int i = 0; i < emptyArray.length; i++) {
            if (emptyArray[i] == '_') {
                scan = scanLetters();
                checkLetters(scan, wordToArray, emptyArray);
            }
        }
    }
    public static void printArray(char[]emptyArray) {
        String word = new String(emptyArray);
        System.out.println("You guessed the word " + word);
    }
    public static char scanLetters() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the letter of the word ");
        char a=scanner.next().charAt(0);
        char result=toLowerCase(a);
        return result;
    }
    public static void checkLetters(char letter,char[] wordToArray,char[]emptyArray){
        for(int i=0;i<emptyArray.length;i++){
            if(wordToArray[i]==letter)
                emptyArray[i]=letter;
        }
     isArrayHaveSome_(wordToArray,emptyArray);
    }
}
