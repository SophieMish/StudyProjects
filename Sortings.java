public class Sortings {
    public void bubbleSortAscending(int [][]arrayTest) {
        int temp = 0;
        for (int i = 0; i < arrayTest.length; i++) {
            for (int j = 0; j < arrayTest[i].length; j++) {
                for (int k = 0; k < arrayTest.length; k++) {
                    for (int n = 0; n < arrayTest[k].length; n++) {
                        if (arrayTest[k][n] > arrayTest[i][j]) {
                            temp = arrayTest[k][n];
                            arrayTest[k][n] = arrayTest[i][j];
                            arrayTest[i][j] = temp;
                        }
                    }
                }
            }
        }
    }
    public void bubbleSortDescending(int[][]arrayTest) {
        int temp = 0;
        for (int i = 0; i < arrayTest.length; i++) {
            for (int j = 0; j < arrayTest[i].length; j++) {
                for (int k = 0; k < arrayTest.length; k++) {
                    for (int n = 0; n < arrayTest[k].length; n++) {
                        if (arrayTest[k][n] < arrayTest[i][j]) {
                            temp = arrayTest[k][n];
                            arrayTest[k][n] = arrayTest[i][j];
                            arrayTest[i][j] = temp;
                        }
                    }
                }
            }
        }
    }
}
